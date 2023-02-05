#include "../s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int res = SUCCESS;
  if (A == NULL || B == NULL || A->matrix == NULL || B->matrix == NULL ||
      A->rows != B->rows || A->columns != B->columns)
    res = FAILURE;
  if (res == SUCCESS) {
    for (int i = 0; res && i < A->rows; i++)
      for (int j = 0; res && j < A->columns; j++)
        if (A->matrix[i] == NULL || B->matrix[i] == NULL ||
            (fabs(A->matrix[i][j] - B->matrix[i][j])) >= 1e-7)
          res = FAILURE;
  }
  return res;
}
