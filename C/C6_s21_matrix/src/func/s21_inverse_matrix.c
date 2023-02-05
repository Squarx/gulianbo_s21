#include "../s21_matrix.h"
int s21_inverse_matrix(matrix_t* A, matrix_t* result) {
  int error = OK;
  double res = 0;
  error = s21_matrix_valid_PRO(1, A);
  if (!error) {
    error = s21_determinant(A, &res);
    if (!error && res == 0) error = CALC_ERR;
  }
  if (!error) {
    if (A->rows == 1) {
      error = s21_mult_number(A, 1 / A->matrix[0][0] / A->matrix[0][0], result);
    } else {
      matrix_t Tmp = {0};
      matrix_t Tmp_T = {0};
      error = s21_calc_complements(A, &Tmp);
      if (!error) error = s21_transpose(&Tmp, &Tmp_T);
      if (!error) error = s21_mult_number(&Tmp_T, 1 / res, result);
      s21_remove_matrix(&Tmp);
      s21_remove_matrix(&Tmp_T);
    }
  }
  return error;
}