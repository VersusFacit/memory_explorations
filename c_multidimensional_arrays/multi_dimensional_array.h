#ifndef MULTI_DIMENSIONAL_ARRAY_H_
#define MULTI_DIMENSIONAL_ARRAY_H_

#include "stdlib.h"

typedef struct {
    int** data;
    size_t rows;
    size_t cols;
} _2DIntArray;

_2DIntArray* create2DIntArray(size_t, size_t);
void print2DIntArray(_2DIntArray*);
void free2DIntArray(_2DIntArray*);


typedef struct {
    size_t rows;
    size_t cols;
    size_t size;
    void** data;
} _2DArray;

_2DArray* create2DArray(size_t, size_t, size_t);
void print2D(_2DArray*);
void free2DArray(_2DArray*);

#endif // MULTI_DIMENSIONAL_ARRAY_H_
