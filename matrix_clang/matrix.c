
#include <malloc.h>
#include <stdlib.h>

#include "matrix.h"

void matrixAllocateEmpty(matrix_t *rt, int rows, int columnes) {
    rt = (matrix_t *)malloc(sizeof(matrix_t));

    rt->rows = rows;
    rt->columnes = columnes;

    rt->data_ = (float **)malloc(sizeof(float *) * rows);
    for (int i = 0; i < rows; i++) {
        rt->data_[i] = (float *)malloc(sizeof(float) * columnes);
    }
}

void matrixCopyFrom(matrix_t *to, matrix_t *from) {
}

void matrixDeallocate(matrix_t *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        free(matrix->data_[i]);
    }
    free(matrix->data_);
}

void matrixSetIdtt(matrix_t *matrix) {
    if (matrix->rows == matrix->columnes) {
        return;
    }

    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->columnes; j++) {
            if (i == j) {
                matrix->data_[i][j] = 1.0f;
            }
        }
    }
}
