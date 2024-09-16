#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const int INITIAL_SIZE = 1;

typedef struct dynamic_array {
    unsigned int size;
    unsigned int capacity;
    long long* array;
} dynamic_array;

void arrayInit(dynamic_array** arr_ptr) {
    dynamic_array *container;
    container = (dynamic_array*) malloc(sizeof(dynamic_array));

    container->size = 0;
    container->capacity = INITIAL_SIZE;
    container->array = (long long *)malloc(INITIAL_SIZE * sizeof(long long));

    *arr_ptr = container;
}

void insertItem(dynamic_array* container, long long item) {
    if (container->size == container->capacity) {
        long long *temp = container->array;
        container->capacity *= 2;
        container->array = realloc(container->array, container->capacity * sizeof(long long));
        if(container->array == NULL) {
            printf("Out of Memory\n");
            container->array = temp;
            return;
        }
    }
    container->array[container->size] = item;
    container->size++;
}

long long getItem(dynamic_array* container, int index) {
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

    int n = 0;
    long long mx = 0, num;

    while(scanf("%lld", &num) != EOF) {
        insertItem(arr, num);
        n++;
        if(num > mx) mx = num;
    }

    long long outof = 1;
    while(mx > outof) outof *= 10;
    // printf("%lld %lld\n", mx, outof);

    for(int i = 0; i < n; i++) {
        long long num = getItem(arr, i);
        printf("%.2lf%% ", 1.0 * num / outof * 100.0);
    }
    printf("\n");

    freeArray(arr);

    return 0;
}
