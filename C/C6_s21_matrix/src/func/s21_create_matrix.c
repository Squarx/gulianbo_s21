#include "../s21_matrix.h"
int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int error = 0;
  if (result == NULL) error = INVALID;
  if (!error) {
    if (rows <= 0 || columns <= 0) error = INVALID;
    result->matrix = NULL;
  }
  if (!error) {
    result->rows = rows;
    result->columns = columns;
    result->matrix = calloc(rows, sizeof(double *));
    if (result->matrix == NULL) error = INVALID;
    for (int i = 0; !error && i < rows; i++) {
      result->matrix[i] = calloc(columns, sizeof(double));
      if (result->matrix[i] == NULL) {
        for (int j = 0; j < i; j++) free(result->matrix[j]);
        free(result->matrix);
        error = INVALID;
      }
    }
  }
  return error;
}