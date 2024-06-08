#include <stdlib.h>
#include "multi_dimensional_array.h"

int main(void) {

    _2DIntArray* a = create2DIntArray(7, 9);
    for (size_t i = 0; i < a->rows; ++i) {
        for (size_t j = 0; j < a->cols; ++j) {
            a->data[i][j] = i+j;
        }
    }
    print2DIntArray(a);
    free2DIntArray(a);





    return EXIT_SUCCESS;
}
