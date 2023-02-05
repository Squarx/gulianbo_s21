//
// Created by DimasX on 29.12.2022.
//

#include "../s21_matrix.h"
//
matrix_t *s21_create_struct(void) {
  matrix_t *res = NULL;
  res = calloc(1, sizeof(matrix_t));
  return res;
}
/**
 *
 * @param n сколько всего матриц сравнивать
 * @param A
 * @param ...
 * @return
 */
int s21_size_equal_PRO(int n, matrix_t *A, ...) {
  int error = OK;
  va_list curr_matrix;
  va_start(curr_matrix, A);
  int rows = 0;
  int col = 0;
  rows = A->rows;
  col = A->columns;
  for (int i = 0; i < n - 1 && !error; i++) {
    matrix_t *curr = NULL;
    curr = va_arg(curr_matrix, matrix_t *);
    if (rows != curr->rows || col != curr->columns) error = CALC_ERR;
  }
  va_end(curr_matrix);
  return error;
}

/**
 * @brief ПРОВЕРКА НА (БЕЗ РАЗМЕРА)
 * @example A == NULL => INVALID
 * @example A->MATRIX == NULL => INVALID
 * @example A->MATRIX-> (ROW || COL) <= 0 => INVALID
 * @example A->MATRIX[i][j] == || Nan => CALC_ERR
 * @param n количество входных переменных
 * @param A
 * @return OK (0) || INVALID (1) CALC_ERR (2)
 */
int s21_matrix_valid_PRO(int n, ...) {
  int error = OK;
  va_list curr_matrix;
  va_start(curr_matrix, n);
  for (int i = 0; i < n && !error; i++) {
    matrix_t *curr = NULL;
    curr = va_arg(curr_matrix, matrix_t *);
    if (curr == NULL) error = Matrix_NULL;
    if (!error)
      if (curr->matrix == NULL) error = INVALID;
    if (!error)
      if (curr->rows <= 0 || curr->columns <= 0) error = INVALID;
    if (!error) {
      for (int j = 0; !error && j < curr->rows; j++)
        for (int z = 0; !error && z < curr->columns; z++) {
          if (curr->matrix[j][z] != curr->matrix[j][z]) error = CALC_ERR;
        }
    }
  }
  va_end(curr_matrix);
  return error;
}

/**
 *
 * @param n какой по счету двумерные массив копировать
 * @param a размер стат src
 * @param b размер стат src
 * @param src  стат src
 * @param dst
 */
void copy__(int n, int a, int b, double src[n][a][b], double **dst) {
  for (int i = 0; i < a; ++i)
    for (int j = 0; j < b; ++j) dst[i][j] = src[n][i][j];
}
