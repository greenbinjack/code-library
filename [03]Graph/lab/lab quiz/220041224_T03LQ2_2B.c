// author : greenbinjack

#include <stdio.h>
#include <math.h>

const int Height = 500;
const int Width = 1192;
const int k = 8;

int min(int a, int b) { return (a < b) ? a : b; }

int main() {
    FILE* source = fopen("100dollars.tif", "rb");
    FILE* destination = fopen("negative_100dollars.tif", "wb");

    char grid[Height][Width], c;
    for(int i = 0; i < 8; i++) {
        c = fgetc(source);
        fputc(c, destination);
    }
    for(int i = 0; i < Height; i++){
        for(int j = 0; j < Width; j++){
            grid[i][j] = fgetc(source);
        }
    }

    int query, x, y, m, n;
    scanf("%d", &query);
    while(query--) {
        scanf("%d%d%d%d", &x, &y, &m, &n);
        for(int i = x; i < min(x + m, Height); i++) {
            for(int j = y; j < min(y + n, Width); j++) {
                grid[i][j] = pow(2, k) - 1 - grid[i][j];
            }
        }
    }

    for(int i = 0; i < Height; i++){
        for(int j = 0; j < Width; j++){
            fputc(grid[i][j], destination);
        }
    }
    while(1){
        c = fgetc(source);
        if(c == EOF) break;
        fputc(c, destination);
    }
    fclose(source);
    fclose(destination);

    return 0;
}
