#include "../s21_matrix.h"
int s21_transpose(matrix_t *A, matrix_t *result) {
  int error = OK;
  error = s21_matrix_valid_PRO(1, A);
  if (!error && result == NULL)
    error = CALC_ERR;  // вообще след строка вернет ошибку INVALID (1) так и чо
                       // возвращать
  if (!error) error = s21_create_matrix(A->columns, A->rows, result);
  if (!error) {
    for (int i = 0; i < A->rows; i++)
      for (int j = 0; j < A->columns; j++)
        result->matrix[j][i] = A->matrix[i][j];
  }
  return error;
}