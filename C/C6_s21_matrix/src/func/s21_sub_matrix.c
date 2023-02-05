#include "../s21_matrix.h"
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = OK;
  error = s21_matrix_valid_PRO(2, A, B);
  if (!error && result == NULL) error = CALC_ERR;
  if (!error) error = s21_size_equal_PRO(2, A, B);
  if (!error) error = s21_create_matrix(A->rows, A->columns, result);
  if (!error) {
    for (int i = 0; !error && i < A->rows; ++i)
      for (int j = 0; !error && j < A->columns; ++j) {
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
        if (result->matrix[i][j] != result->matrix[i][j]) error = CALC_ERR;
      }
  }
  return error;
}