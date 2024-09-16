#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#include <SDL.h>
#include <SDL_ttf.h>

#define WIDTH 10
#define HEIGHT 22
#define VISIBLE_HEIGHT 20
#define GRID_SIZE 30

#define ARRAY_COUNT(x) (sizeof(x) / sizeof((x)[0]))
#define ZERO_STRUCT(obj) memset(&(obj), 0, sizeof(obj))

static const int FRAMES_PER_DROP[] = {
    48,
    43,
    38,
    33,
    28,
    23,
    18,
    13,
    8,
    6,
    5,
    5,
    5,
    4,
    4,
    4,
    3,
    3,
    3,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    1
};

static const double TARGET_SECONDS_PER_FRAME = 1.f / 60.f;


struct Color {
    int r, g, b, a;
};

static const struct Color BASE_COLORS[] = {
    { 0x28, 0x28, 0x28, 0xFF },
    { 0x2D, 0x99, 0x99, 0xFF },
    { 0x99, 0x99, 0x2D, 0xFF },
    { 0x99, 0x2D, 0x99, 0xFF },
    { 0x2D, 0x99, 0x51, 0xFF },
    { 0x99, 0x2D, 0x2D, 0xFF },
    { 0x2D, 0x63, 0x99, 0xFF },
    { 0x99, 0x63, 0x2D, 0xFF }
};

static const struct Color LIGHT_COLORS[] = {
    { 0x28, 0x28, 0x28, 0xFF },
    { 0x44, 0xE5, 0xE5, 0xFF },
    { 0xE5, 0xE5, 0x44, 0xFF },
    { 0xE5, 0x44, 0xE5, 0xFF },
    { 0x44, 0xE5, 0x7A, 0xFF },
    { 0xE5, 0x44, 0x44, 0xFF },
    { 0x44, 0x95, 0xE5, 0xFF },
    { 0xE5, 0x95, 0x44, 0xFF }
};

static const struct Color DARK_COLORS[] = {
    { 0x28, 0x28, 0x28, 0xFF },
    { 0x1E, 0x66, 0x66, 0xFF },
    { 0x66, 0x66, 0x1E, 0xFF },
    { 0x66, 0x1E, 0x66, 0xFF },
    { 0x1E, 0x66, 0x36, 0xFF },
    { 0x66, 0x1E, 0x1E, 0xFF },
    { 0x1E, 0x42, 0x66, 0xFF },
    { 0x66, 0x42, 0x1E, 0xFF }
};


struct Tetrino {
    int *data;
    int side;
};

static const int TETRINO_1[] = {
    0, 0, 0, 0,
    1, 1, 1, 1,
    0, 0, 0, 0,
    0, 0, 0, 0
};

static const int TETRINO_2[] = {
    2, 2,
    2, 2
};

static const int TETRINO_3[] = {
    0, 0, 0,
    3, 3, 3,
    0, 3, 0
};

static const int TETRINO_4[] = {
    0, 4, 4,
    4, 4, 0,
    0, 0, 0
};

static const int TETRINO_5[] = {
    5, 5, 0,
    0, 5, 5,
    0, 0, 0
};

static const int TETRINO_6[] = {
    6, 0, 0,
    6, 6, 6,
    0, 0, 0
};

static const int TETRINO_7[] = {
    0, 0, 7,
    7, 7, 7,
    0, 0, 0
};


static const struct Tetrino TETRINOS[] = {
    { TETRINO_1, 4 },
    { TETRINO_2, 2 },
    { TETRINO_3, 3 },
    { TETRINO_4, 3 },
    { TETRINO_5, 3 },
    { TETRINO_6, 3 },
    { TETRINO_7, 3 }
};

enum Game_Phase {
    GAME_PHASE_START,
    GAME_PHASE_PLAY,
    GAME_PHASE_LINE,
    GAME_PHASE_GAMEOVER
};

struct Piece_State {
    int tetrino_index, offset_row, offset_col, rotation;
};

struct Game_State {
    int board[WIDTH * HEIGHT], lines[HEIGHT], pending_line_count;
    struct Piece_State piece;
    enum Game_Phase phase;
    int start_level, level, line_count, points;
    double next_drop_time, highlight_end_time, time;
};

struct Input_State {
    int left, right, up, down, a;
    int dleft, dright, dup, ddown, da;
};

enum Text_Align {
    TEXT_ALIGN_LEFT,
    TEXT_ALIGN_CENTER,
    TEXT_ALIGN_RIGHT
};

static int matrix_get(const int *values, int width, int row, int col) {
    return values[row * width + col];
}

static void matrix_set(int *values, int width, int row, int col, int value) {
    values[row * width + col] = value;
}

static int tetrino_get(const struct Tetrino *tetrino, int row, int col, int rotation) {
    int side = tetrino->side;
    switch (rotation) {
        case 0:
            return tetrino->data[row * side + col];
        case 1:
            return tetrino->data[(side - col - 1) * side + row];
        case 2:
            return tetrino->data[(side - row - 1) * side + (side - col - 1)];
        case 3:
            return tetrino->data[col * side + (side - row - 1)];
    }
    return 0;
}

static int check_row_filled(const int *values, int width, int row) {
    for (int col = 0; col < width; ++col) {
        if (!matrix_get(values, width, row, col)) return 0;
    }
    return 1;
}

static int check_row_empty(const int *values, int width, int row) {
    for (int col = 0; col < width; ++col) {
        if (matrix_get(values, width, row, col)) return 0;
    }
    return 1;
}

static int find_lines(const int *values, int width, int height, int *lines_out) {
    int count = 0;
    for (int row = 0; row < height; ++row) {
        int filled = check_row_filled(values, width, row);
        lines_out[row] = filled;
        count += filled;
    }
    return count;
}

static void clear_lines(int *values, int width, int height, const int *lines) {
    int src_row = height - 1;
    for (int dst_row = height - 1; dst_row >= 0; --dst_row) {
        while (src_row >= 0 && lines[src_row]) --src_row;\
        if (src_row < 0) memset(values + dst_row * width, 0, width);
        else {
            if (src_row != dst_row) memcpy(values + dst_row * width, values + src_row * width, width);
            --src_row;
        }
    }
}

static bool check_piece_valid(const struct Piece_State *piece, const int *board, int width, int height) {
    const struct Tetrino *tetrino = TETRINOS + piece->tetrino_index;
    assert(tetrino);
    for (int row = 0; row < tetrino->side; ++row) {
        for (int col = 0; col < tetrino->side; ++col) {
            int value = tetrino_get(tetrino, row, col, piece->rotation);
            if (value > 0) {
                int board_row = piece->offset_row + row;
                int board_col = piece->offset_col + col;
                if (board_row < 0 || board_row >= height || board_col < 0 || board_col >= width) return false;
                else if (matrix_get(board, width, board_row, board_col)) return false;
            }
        }
    }
    return true;
}

static void merge_piece(struct Game_State *game) {
    const struct Tetrino *tetrino = TETRINOS + game->piece.tetrino_index;
    for (int row = 0; row < tetrino->side; ++row) {
        for (int col = 0; col < tetrino->side; ++col) {
            int value = tetrino_get(tetrino, row, col, game->piece.rotation);
            if (value) {
                int board_row = game->piece.offset_row + row;
                int board_col = game->piece.offset_col + col;
                matrix_set(game->board, WIDTH, board_row, board_col, value);
            }
        }
    }
}

static int random_int(int min, int max) {
    return min + rand() % (max - min);
}

static double get_time_to_next_drop(int level) {
    if (level > 29) level = 29;
    return FRAMES_PER_DROP[level] * TARGET_SECONDS_PER_FRAME;
}


static void spawn_piece(struct Game_State *game) {
    ZERO_STRUCT(game->piece);
    game->piece.tetrino_index = (int)random_int(0, ARRAY_COUNT(TETRINOS));
    game->piece.offset_col = WIDTH / 2;
    game->next_drop_time = game->time + get_time_to_next_drop(game->level);
}


static bool soft_drop(struct Game_State *game) {
    ++game->piece.offset_row;
    if (!check_piece_valid(&game->piece, game->board, WIDTH, HEIGHT)) {
        --game->piece.offset_row;
        merge_piece(game);
        spawn_piece(game);
        return false;
    }

    game->next_drop_time = game->time + get_time_to_next_drop(game->level);
    return true;
}

static int compute_points(int level, int line_count) {
    switch (line_count)
    {
    case 1:
        return 40 * (level + 1);
    case 2:
        return 100 * (level + 1);
    case 3:
        return 300 * (level + 1);
    case 4:
        return 1200 * (level + 1);
    }
    return 0;
}

static int
min(int x, int y)
{
    return x < y ? x : y;
}
static int
max(int x, int y)
{
    return x > y ? x : y;
}

static int
get_lines_for_next_level(int start_level, int level)
{
    int first_level_up_limit = min(
        (start_level * 10 + 10),
        max(100, (start_level * 10 - 50)));
    if (level == start_level)
    {
        return first_level_up_limit;
    }
    int diff = level - start_level;
    return first_level_up_limit + diff * 10;
}

static void
update_game_start(struct Game_State *game, const struct Input_State *input)
{
    if (input->dup > 0)
    {
        ++game->start_level;
    }

    if (input->ddown > 0 && game->start_level > 0)
    {
        --game->start_level;
    }

    if (input->da > 0)
    {
        memset(game->board, 0, WIDTH * HEIGHT);
        game->level = game->start_level;
        game->line_count = 0;
        game->points = 0;
        spawn_piece(game);
        game->phase = GAME_PHASE_PLAY;
    }
}

static void
update_game_gameover(struct Game_State *game, const struct Input_State *input)
{
    if (input->da > 0)
    {
        game->phase = GAME_PHASE_START;
    }
}

static void
update_game_line(struct Game_State *game)
{
    if (game->time >= game->highlight_end_time)
    {
        clear_lines(game->board, WIDTH, HEIGHT, game->lines);
        game->line_count += game->pending_line_count;
        game->points += compute_points(game->level, game->pending_line_count);

        int lines_for_next_level = get_lines_for_next_level(game->start_level,
                                                            game->level);
        if (game->line_count >= lines_for_next_level)
        {
            ++game->level;
        }

        game->phase = GAME_PHASE_PLAY;
    }
}

static void
update_game_play(struct Game_State *game,
                 const struct Input_State *input)
{
    struct Piece_State piece = game->piece;
    if (input->dleft > 0)
    {
        --piece.offset_col;
    }
    if (input->dright> 0)
    {
        ++piece.offset_col;
    }
    if (input->dup > 0)
    {
        piece.rotation = (piece.rotation + 1) % 4;
    }

    if (check_piece_valid(&piece, game->board, WIDTH, HEIGHT))
    {
        game->piece = piece;
    }

    if (input->ddown > 0)
    {
        soft_drop(game);
    }

    if (input->da > 0)
    {
        while(soft_drop(game));
    }

    while (game->time >= game->next_drop_time)
    {
        soft_drop(game);
    }

    game->pending_line_count = find_lines(game->board, WIDTH, HEIGHT, game->lines);
    if (game->pending_line_count > 0)
    {
        game->phase = GAME_PHASE_LINE;
        game->highlight_end_time = game->time + 0.5f;
    }

    int game_over_row = 0;
    if (!check_row_empty(game->board, WIDTH, game_over_row))
    {
        game->phase = GAME_PHASE_GAMEOVER;
    }
}

static void
update_game(struct Game_State *game,
            const struct Input_State *input)
{
    switch(game->phase)
    {
    case GAME_PHASE_START:
        update_game_start(game, input);
        break;
    case GAME_PHASE_PLAY:
        update_game_play(game, input);
        break;
    case GAME_PHASE_LINE:
        update_game_line(game);
        break;
    case GAME_PHASE_GAMEOVER:
        update_game_gameover(game, input);
        break;
    }
}

static void
fill_rect(SDL_Renderer *renderer,
          int x, int y, int width, int height, struct Color color)
{
    SDL_Rect rect = {0};
    rect.x = x;
    rect.y = y;
    rect.w = width;
    rect.h = height;
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &rect);
}


static void
draw_rect(SDL_Renderer *renderer,
          int x, int y, int width, int height, struct Color color)
{
    SDL_Rect rect = {0};
    rect.x = x;
    rect.y = y;
    rect.w = width;
    rect.h = height;
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawRect(renderer, &rect);
}

static void
draw_string(SDL_Renderer *renderer,
            TTF_Font *font,
            const char *text,
            int x, int y,
            enum Text_Align alignment,
            struct Color color)
{
    SDL_Color sdl_color = { color.r, color.g, color.b, color.a };
    SDL_Surface *surface = TTF_RenderText_Solid(font, text, sdl_color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_Rect rect;
    rect.y = y;
    rect.w = surface->w;
    rect.h = surface->h;
    switch (alignment)
    {
    case TEXT_ALIGN_LEFT:
        rect.x = x;
        break;
    case TEXT_ALIGN_CENTER:
        rect.x = x - surface->w / 2;
        break;
    case TEXT_ALIGN_RIGHT:
        rect.x = x - surface->w;
        break;
    }

    SDL_RenderCopy(renderer, texture, 0, &rect);
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}

static void
draw_cell(SDL_Renderer *renderer,
          int row, int col, int value,
          int offset_x, int offset_y,
          bool outline)
{
    struct Color base_color = BASE_COLORS[value];
    struct Color light_color = LIGHT_COLORS[value];
    struct Color dark_color = DARK_COLORS[value];


    int edge = GRID_SIZE / 8;

    int x = col * GRID_SIZE + offset_x;
    int y = row * GRID_SIZE + offset_y;

    if (outline)
    {
        draw_rect(renderer, x, y, GRID_SIZE, GRID_SIZE, base_color);
        return;
    }

    fill_rect(renderer, x, y, GRID_SIZE, GRID_SIZE, dark_color);
    fill_rect(renderer, x + edge, y,
              GRID_SIZE - edge, GRID_SIZE - edge, light_color);
    fill_rect(renderer, x + edge, y + edge,
              GRID_SIZE - edge * 2, GRID_SIZE - edge * 2, base_color);
}

static void
draw_piece(SDL_Renderer *renderer,
           const struct Piece_State *piece,
           int offset_x, int offset_y,
           bool outline)
{
    const struct Tetrino *tetrino = TETRINOS + piece->tetrino_index;
    for (int row = 0;
         row < tetrino->side;
         ++row)
    {
        for (int col = 0;
             col < tetrino->side;
             ++col)
        {
            int value = tetrino_get(tetrino, row, col, piece->rotation);
            if (value)
            {
                draw_cell(renderer,
                          row + piece->offset_row,
                          col + piece->offset_col,
                          value,
                          offset_x, offset_y,
                          outline);
            }
        }
    }
}

static void
draw_board(SDL_Renderer *renderer,
           const int *board, int width, int height,
           int offset_x, int offset_y)
{
    fill_rect(renderer, offset_x, offset_y,
              width * GRID_SIZE, height * GRID_SIZE,
              BASE_COLORS[0]);
    for (int row = 0;
         row < height;
         ++row)
    {
        for (int col = 0;
             col < width;
             ++col)
        {
            int value = matrix_get(board, width, row, col);
            if (value)
            {
                draw_cell(renderer, row, col, value, offset_x, offset_y, false);
            }
        }
    }
}

static void
render_game(const struct Game_State *game,
            SDL_Renderer *renderer,
            TTF_Font *font)
{

    char buffer[4096];

    struct Color highlight_color = { 0xFF, 0xFF, 0xFF, 0xFF };

    int margin_y = 60;

    draw_board(renderer, game->board, WIDTH, HEIGHT, 0, margin_y);

    if (game->phase == GAME_PHASE_PLAY)
    {
        draw_piece(renderer, &game->piece, 0, margin_y, false);

        struct Piece_State piece = game->piece;
        while (check_piece_valid(&piece, game->board, WIDTH, HEIGHT))
        {
            piece.offset_row++;
        }
        --piece.offset_row;

        draw_piece(renderer, &piece, 0, margin_y, true);

    }

    if (game->phase == GAME_PHASE_LINE)
    {
        for (int row = 0;
             row < HEIGHT;
             ++row)
        {
            if (game->lines[row])
            {
                int x = 0;
                int y = row * GRID_SIZE + margin_y;

                fill_rect(renderer, x, y,
                          WIDTH * GRID_SIZE, GRID_SIZE, highlight_color);
            }
        }
    }
    else if (game->phase == GAME_PHASE_GAMEOVER)
    {
        int x = WIDTH * GRID_SIZE / 2;
        int y = (HEIGHT * GRID_SIZE + margin_y) / 2;
        draw_string(renderer, font, "GAME OVER",
                    x, y, TEXT_ALIGN_CENTER, highlight_color);
    }
    else if (game->phase == GAME_PHASE_START)
    {
        int x = WIDTH * GRID_SIZE / 2;
        int y = (HEIGHT * GRID_SIZE + margin_y) / 2;
        draw_string(renderer, font, "PRESS START",
                    x, y, TEXT_ALIGN_CENTER, highlight_color);

        snprintf(buffer, sizeof(buffer), "STARTING LEVEL: %d", game->start_level);
        draw_string(renderer, font, buffer,
                    x, y + 30, TEXT_ALIGN_CENTER, highlight_color);
    }

    struct Color black_color = { 0x00, 0x00, 0x00, 0x00 };

    fill_rect(renderer,
              0, margin_y,
              WIDTH * GRID_SIZE, (HEIGHT - VISIBLE_HEIGHT) * GRID_SIZE,
              black_color);


    snprintf(buffer, sizeof(buffer), "LEVEL: %d", game->level);
    draw_string(renderer, font, buffer, 5, 5, TEXT_ALIGN_LEFT, highlight_color);

    snprintf(buffer, sizeof(buffer), "LINES: %d", game->line_count);
    draw_string(renderer, font, buffer, 5, 35, TEXT_ALIGN_LEFT, highlight_color);

    snprintf(buffer, sizeof(buffer), "POINTS: %d", game->points);
    draw_string(renderer, font, buffer, 5, 65, TEXT_ALIGN_LEFT, highlight_color);
}

int main(int argc, char* argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        return 1;
    }

    if (TTF_Init() < 0)
    {
        return 2;
    }

    SDL_Window *window = SDL_CreateWindow(
        "Tetris",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        300,
        720,
        SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(
        window,
        -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    const char *font_name = "novem___.ttf";
    TTF_Font *font = TTF_OpenFont(font_name, 24);

    struct Game_State game;
    struct Input_State input;

    ZERO_STRUCT(game);
    ZERO_STRUCT(input);

    spawn_piece(&game);

    game.piece.tetrino_index = 2;

    bool quit = false;
    while (!quit)
    {
        game.time = SDL_GetTicks() / 1000.0f;

        SDL_Event e;
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }
        }

        int key_count;
        const int *key_states = SDL_GetKeyboardState(&key_count);

        if (key_states[SDL_SCANCODE_ESCAPE])
        {
            quit = true;
        }

        struct Input_State prev_input = input;

        input.left = key_states[SDL_SCANCODE_LEFT];
        input.right = key_states[SDL_SCANCODE_RIGHT];
        input.up = key_states[SDL_SCANCODE_UP];
        input.down = key_states[SDL_SCANCODE_DOWN];
        input.a = key_states[SDL_SCANCODE_SPACE];

        input.dleft = (int)input.left - (int)prev_input.left;
        input.dright = (int)input.right - (int)prev_input.right;
        input.dup = (int)input.up - (int)prev_input.up;
        input.ddown = (int)input.down - (int)prev_input.down;
        input.da = (int)input.a - (int)prev_input.a;

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);

        update_game(&game, &input);
        render_game(&game, renderer, font);

        SDL_RenderPresent(renderer);
    }

    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    return 0;
}
