/*
 * dynamic_array.c
 * Simple dynamic array (vector-like) example in C.
 * Compile: gcc -std=c11 -Wall -Wextra -o dynamic_array dynamic_array.c
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    size_t size;
    size_t capacity;
} IntVec;

IntVec *vec_create(size_t initial) {
    IntVec *v = malloc(sizeof(*v));
    if (!v) return NULL;
    v->data = malloc(initial * sizeof(int));
    if (!v->data) { free(v); return NULL; }
    v->size = 0;
    v->capacity = initial;
    return v;
}

void vec_destroy(IntVec *v) {
    if (!v) return;
    free(v->data);
    free(v);
}

int vec_push(IntVec *v, int value) {
    if (v->size == v->capacity) {
        size_t newcap = v->capacity ? v->capacity * 2 : 4;
        int *tmp = realloc(v->data, newcap * sizeof(int));
        if (!tmp) return 0;
        v->data = tmp;
        v->capacity = newcap;
    }
    v->data[v->size++] = value;
    return 1;
}

int main(void) {
    IntVec *v = vec_create(4);
    if (!v) { perror("vec_create"); return EXIT_FAILURE; }

    for (int i = 1; i <= 16; ++i) {
        if (!vec_push(v, i * i)) { perror("vec_push"); vec_destroy(v); return EXIT_FAILURE; }
    }

    printf("Dynamic array contents (size=%zu):\n", v->size);
    for (size_t i = 0; i < v->size; ++i) printf("%zu: %d\n", i, v->data[i]);

    vec_destroy(v);
    return EXIT_SUCCESS;
}
