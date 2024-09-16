#include <stdio.h>
#include <stdlib.h>

const int INITIAL_SIZE = 1;

typedef struct dynamic_array {
    unsigned int size;
    unsigned int capacity;
    int* array;
} dynamic_array;

void arrayInit(dynamic_array** arr_ptr) {
    dynamic_array *container;
    container = (dynamic_array*) malloc(sizeof(dynamic_array));

    container->size = 0;
    container->capacity = INITIAL_SIZE;
    container->array = (int *)malloc(INITIAL_SIZE * sizeof(int));

    *arr_ptr = container;
}

void insertItem(dynamic_array* container, int item) {
    if (container->size == container->capacity) {
        int *temp = container->array;
        container->capacity *= 2;
        container->array = realloc(container->array, container->capacity * sizeof(int));
        if(container->array == NULL) {
            printf("Out of Memory\n");
            container->array = temp;
            return;
        }
    }
    container->array[container->size] = item;
    container->size++;
}

int getItem(dynamic_array* container, int index) {
    if(index >= container->size) {
        printf("Index Out of Bounds\n");
        return -1;
    }
    return container->array[index];
}

void freeArray(dynamic_array* container) {
    free(container->array);
    free(container);
}

int main() {
    dynamic_array* arr;
    arrayInit(&arr);

    int sum, x, n = 0;
    scanf("%d", &sum);

    while(1) {
        scanf("%d", &x);
        if(x == -1) break;
        insertItem(arr, x);
        n++;
    }

    int l = 0, r = 0, temp = 0;
    while(r < n) {
        temp += getItem(arr, r);
        if(temp == sum) {
            printf("%d %d\n", l, r);
            goto end;
        }
        while(temp > sum) temp -= getItem(arr, l), l++;
        r++;
    }
    printf("-1\n");

    end:
    freeArray(arr);

    return 0;
}


