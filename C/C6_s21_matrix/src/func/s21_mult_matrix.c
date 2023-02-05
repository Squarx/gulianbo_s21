#include "../s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = OK;
  error = s21_matrix_valid_PRO(2, A, B);
  if (!error && (A->columns != B->rows)) error = CALC_ERR;
  if (!error) error = s21_create_matrix(A->rows, B->columns, result);
  for (int i = 0; !error && i < result->rows; i++) {
    for (int j = 0; !error && j < result->columns; ++j) {
      result->matrix[i][j] = sum_mult(i, j, A, B);
      if (result->matrix[i][j] != result->matrix[i][j]) error = CALC_ERR;
    }
  }
  return error;
}

double sum_mult(int i, int j, matrix_t *A, matrix_t *B) {
  double res = 0;
  for (int r = 0; r < B->rows; r++) {
    res += A->matrix[i][r] * B->matrix[r][j];
  }
  return res;
}