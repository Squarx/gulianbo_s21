#include "../s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int error = OK;
  error = s21_matrix_valid_PRO(1, A);
  if (!error && (A->columns != A->rows)) error = CALC_ERR;
  if (!error && result == NULL) error = CALC_ERR;
  if (!error) {
    if (A->rows == 1) *result = A->matrix[0][0];
    if (A->rows == 2)
      *result =
          A->matrix[0][0] * A->matrix[1][1] - A->matrix[1][0] * A->matrix[0][1];
    if (A->rows > 2) {
      *result = 0;
      int sign = 1;
      for (int i = 0; !error && i < A->columns; i++) {
        matrix_t *minor = Minor(0, i, A);
        if (minor == NULL)
          error = INVALID;
        else {
          double minor_res = 0;
          error = s21_determinant(minor, &minor_res);
          if (!error) {
            *result += sign * A->matrix[0][i] * minor_res;
            sign = -sign;
          }
          s21_remove_matrix(minor);
          free(minor);
        }
      }
    }
  }
  return error;
}