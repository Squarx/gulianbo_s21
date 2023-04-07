#include "s21_matrix.h"

#include <math.h>

void s21_move_matrix(matrix_t *A, double step, int xyz) {
  if (!(A->rows <= 0 || A->columns <= 0 || A->matrix == NULL)) {
    for (int i = 1; i < A->rows; i++) A->matrix[i][xyz] += step;
  }
}

void s21_x_rotation_matrix(matrix_t *A, double a) {
  if (!(A->rows <= 0 || A->columns <= 0 || A->matrix == NULL)) {
    for (int i = 1; i < A->rows; i++) {
      double y = A->matrix[i][1];
      double z = A->matrix[i][2];
      A->matrix[i][1] = cos(a) * y - sin(a) * z;
      A->matrix[i][2] = sin(a) * y + cos(a) * z;
    }
  }
}

void s21_y_rotation_matrix(matrix_t *A, double a) {
  if (!(A->rows <= 0 || A->columns <= 0 || A->matrix == NULL)) {
    for (int i = 1; i < A->rows; i++) {
      double x = A->matrix[i][0];
      double z = A->matrix[i][2];
      A->matrix[i][0] = cos(a) * x + sin(a) * z;
      A->matrix[i][2] = -sin(a) * x + cos(a) * z;
    }
  }
}

void s21_z_rotation_matrix(matrix_t *A, double a) {
  if (!(A->rows <= 0 || A->columns <= 0 || A->matrix == NULL)) {
    for (int i = 1; i < A->rows; i++) {
      double x = A->matrix[i][0];
      double y = A->matrix[i][1];
      A->matrix[i][0] = cos(a) * x - sin(a) * y;
      A->matrix[i][1] = sin(a) * x + cos(a) * y;
    }
  }
}

void s21_scaling_matrix(matrix_t *A, double scale) {
  if (!(A->rows <= 0 || A->columns <= 0 || A->matrix == NULL || scale == 0)) {
    for (int i = 0; i < A->rows; i++)
      for (int j = 0; j < A->columns; j++) A->matrix[i][j] *= scale;
  }
}

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int error_code = 0;
  if (rows <= 0 || columns <= 0 || result == NULL) {
    error_code = 1;
  } else {
    result->rows = rows;
    result->columns = columns;
    result->matrix = calloc(rows, sizeof(double));
    for (int i = 0; i < rows && result->matrix != NULL; i++) {
      result->matrix[i] = calloc(columns, sizeof(double));
    }
    if (result->matrix == NULL) {
      error_code = 1;
    }
  }
  return error_code;
}

void s21_remove_matrix(matrix_t *A) {
  if (A != NULL && A->matrix != NULL) {
    for (int i = 0; i < A->rows && A->matrix[i]; i++) {
      free(A->matrix[i]);
    }
    free(A->matrix);
    *A = (matrix_t){0};
  }
}
