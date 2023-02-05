#include "../s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int error = OK;
  error = s21_matrix_valid_PRO(1, A);
  // A.clo == a.row
  if (!error && result == NULL) error = CALC_ERR;
  if (!error) error = s21_create_matrix(A->rows, A->columns, result);
  if (!error && A->rows == 1)
    error = CALC_ERR;
  else {
    for (int i = 0; !error && i < result->rows; i++) {
      int sign = i % 2 == 0 ? 1 : -1;
      for (int j = 0; !error && j < result->columns; j++) {
        matrix_t *MINOR = Minor(i, j, A);
        if (MINOR == NULL) {
          error = INVALID;
        } else {
          double res = 0;
          error = s21_determinant(MINOR, &res);
          if (res != res) error = CALC_ERR;
          if (!error) {
            result->matrix[i][j] = sign * res;
            sign = -sign;
          }
          s21_remove_matrix(MINOR);
          free(MINOR);
        }
      }
    }
  }
  return error;
}
/**
 *
 * @param row_skip - текущая итерация по ряду
 * @param col_skip -  текущая итерация по столбцу
 * @param A - исходная матрица
 * @return - ДИНАМИЕЧСКАЯ структура mtrix_t (НАДО ЧИСТИТЬ)
 * @return  - в структуре матрица размером [n-1][n-1] (A[n][n]) полученная
 * вычеркиванием пересечения строки столбца
 */
matrix_t *Minor(int row_skip, int col_skip, matrix_t *A) {
  matrix_t *minor = s21_create_struct();
  if (minor != NULL) {
    int error = OK;
    error = s21_create_matrix(A->rows - 1, A->columns - 1, minor);
    if (!error) {
      for (int i = 0, minor_row = 0; i < A->rows; i++) {
        if (i != row_skip) {
          for (int j = 0, minor_col = 0; j < A->columns; j++)
            if (j != col_skip)
              minor->matrix[minor_row][minor_col++] = A->matrix[i][j];
          minor_row++;
        }
      }
    }
  }
  return minor;
}
