#include "../s21_matrix.h"

void s21_remove_matrix(matrix_t *A) {
  if (A != NULL && A->matrix != NULL) {
    if (A->columns > 0 && A->rows > 0) {
      for (int i = 0; i < A->rows; i++) {
        free(A->matrix[i]);
        A->matrix[i] = NULL;
      }
      A->rows = 0;
      A->columns = 0;
      free(A->matrix);
      A->matrix = NULL;
    }
  }
}