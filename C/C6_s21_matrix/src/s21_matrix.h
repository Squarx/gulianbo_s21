//
// Created by DimasX on 29.12.2022.
//

#ifndef C6_S21_MATRIX_0_SRC_S21_MATRIX_H_
#define C6_S21_MATRIX_0_SRC_S21_MATRIX_H_
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
//#define calloc(x,y) NULL
typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

#define s21_INF (1 / 0.)
typedef enum numbers {
  s21_INT_MAX = 2147483647,
  s21_INT_MIN = -2147483648,
  SUCCESS = 1,
  FAILURE = 0,
  COL = 0,
  ROW = 1
} NUM;

static const int inv_size[7][2] = {{-1, -1}, {-1, 0}, {0, -1}, {0, 0},
                                   {0, 1},   {1, 0},  {1, 1}};
typedef enum errors {
  OK = 0,
  INVALID = 1,
  CALC_ERR = 2,
  Matrix_NULL = 2,
} Err;

int s21_create_matrix(int rows, int columns, matrix_t *result);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
void s21_remove_matrix(matrix_t *A);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);
//
void test_create_remove(void);
void print_err(int error);
int s21_matrix_valid(matrix_t *A, matrix_t *B);
int s21_size_equal(matrix_t *A, matrix_t *B);
void copy__(int n, int a, int b, double src[n][a][b], double **dst);
void test_compare(void);
void printer__(matrix_t *A);
int s21_matrix_valid_PRO(int n, ...);
int s21_matrix_valid_mini(matrix_t *curr);
matrix_t *s21_create_struct(void);
int s21_size_equal_PRO(int n, matrix_t *A, ...);
int s21_eq_size_MUL(matrix_t *A, matrix_t *B, matrix_t *result);
double sum_mult(int i, int j, matrix_t *A, matrix_t *B);
int s21_val_size_transpose(matrix_t *A, matrix_t *result);
int s21_val_size_calc(matrix_t *A, matrix_t *result);
matrix_t *Minor(int row_skip, int col_skip, matrix_t *A);
double det(matrix_t *A);
#endif  // C6_S21_MATRIX_0_SRC_S21_MATRIX_H_
