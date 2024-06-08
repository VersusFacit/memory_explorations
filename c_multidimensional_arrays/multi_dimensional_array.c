#include "stdlib.h"
#include "stdio.h"

#include "multi_dimensional_array.h"


/**
 * Allocate memory for each row (pointer to pointer to contiguous memory cells on heap)
 * Allocate memory for each col (pointer to data on heap)
 * In event of failure, abort and clean up previously allocated row cells
 */
_2DIntArray* create2DIntArray(size_t rows, size_t cols) {

    _2DIntArray* array = (_2DIntArray*)malloc(sizeof(_2DIntArray));
    if (array == NULL) {
        perror("Initial memory allocation failed");
        exit(1);
    }

    array->cols = cols;
    array->rows = rows;
    array->data = (int**)calloc(rows, sizeof(int*));
    if (array->data == NULL) {
        perror("Data memory allocation failed");
        exit(1);
    }

    for (size_t i = 0; i < rows; ++i) {
        array->data[i] = (int*)calloc(cols, sizeof(int));
        if (array->data[i] == NULL) {
            perror("Row memory allocation failed");
            for (size_t j = 0; j < i; ++j) {
                free(array->data[j]);
            }
            free(array->data);
            free(array);
            exit(1);
        }
    }

    return array;
}

void free2DIntArray(_2DIntArray* array) {
    for (size_t i = 0; i < array->rows; ++i) {
        free(array->data[i]);
    }
    free(array->data);
    free(array);
}

void print2DIntArray(_2DIntArray* array) {
    printf("[\n");
    for (size_t i = 0; i < array->rows; ++i) {
        printf("\t");
        for (size_t j = 0; j < array->cols; ++j) {
            printf("%d", array->data[i][j]);
            if (j + 1 < array->cols) {
                printf(", ");
            }
        }
        printf("\n");
    }
    printf("]\n");
}

/*****************
 * Generic Array *
 *****************/

_2DArray* create2DArray(size_t rows, size_t cols, size_t size) {
    _2DArray* array = (_2DArray*)calloc(1, sizeof(_2DArray));
    if (array == NULL) {
        perror("Allocation of array failed.");
        exit(1);
    }
    array->cols = cols;
    array->rows = rows;
    array->size = size;
    array->data = (void**)calloc(rows, size);
    if (array->data == NULL) {
        perror("Allocation of array data failed.");
        exit(1);
    }

    for (size_t i = 0; i < rows; ++i) {
        array->data[i] = (void*)calloc(cols, sizeof(void *));
        if (array->data[i] == NULL) {
            perror("Allocation of row data failed.");
            for (size_t j = 0; j < i; ++j) {
                free(array->data[i]);
            }
            free(array->data);
            free(array);
        }
    }

    return array;
}
void print2D(_2DArray* a) {
    printf("[\n");
    for (size_t i = 0; i < a->rows; ++i) {
        printf("\t");
        for (size_t j = 0; j < a->cols; ++j) {
            printf("%d", a->data[i*sizeof(a->size)][j*sizeof(a->size)]);
            if (j + 1 < a->cols) {
                printf(", ");
            }
        }
        printf("\n");
    }
    printf("]\n");
}

void free2DArray(_2DArray*);
