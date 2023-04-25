
#include <stdio.h>

typedef struct matrix_t {
        int rows;
        int columnes;

        float **data_;
} matrix_t;

void matrixAllocateEmpty(matrix_t *rt, int rows, int columnes);
void matrixCopyFrom(matrix_t *to, matrix_t *from);
void matrixDeallocate(matrix_t *matrix);
void matrixSetIdtt(matrix_t *matrix);

void matrixMult(matrix_t *rt, matrix_t *lhs, matrix_t *rhs);
void matrixTranspose(matrix_t matrix);
void matrixGetDeterminant(matrix_t *matrix);
