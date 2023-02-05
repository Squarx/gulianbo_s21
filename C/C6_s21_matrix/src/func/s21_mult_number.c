#include "../s21_matrix.h"
/**
 *
 * @param A
 * @param number
 * @param result
 * @return !! +-0 * +-inf => nan => 2
 */
int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int error = OK;
  if (number != number) error = CALC_ERR;
  if (!error && result == NULL) error = CALC_ERR;
  if (!error) error = s21_matrix_valid_PRO(1, A);
  if (!error) error = s21_create_matrix(A->rows, A->columns, result);
  if (!error) {
    for (int i = 0; !error && i < A->rows; ++i)
      for (int j = 0; !error && j < A->columns; ++j) {
        result->matrix[i][j] = A->matrix[i][j] * number;
        if (result->matrix[i][j] != result->matrix[i][j]) error = CALC_ERR;
      }
  }
  return error;
}