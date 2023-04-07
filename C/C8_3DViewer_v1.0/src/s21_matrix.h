#ifndef C6_S21_MATRIX_0_SRC_S21_MATRIX_H_
#define C6_S21_MATRIX_0_SRC_S21_MATRIX_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

#define SUCCESS 1
#define FAILURE 0

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
void s21_move_matrix(matrix_t *A, double step, int xyz);
void s21_x_rotation_matrix(matrix_t *A, double a);
void s21_y_rotation_matrix(matrix_t *A, double a);
void s21_z_rotation_matrix(matrix_t *A, double a);
void s21_scaling_matrix(matrix_t *A, double scale);

#endif  // C6_S21_MATRIX_0_SRC_S21_MATRIX_H_
