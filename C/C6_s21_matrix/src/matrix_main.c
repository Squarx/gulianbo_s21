
#include "s21_matrix.h"
double matrix_3_2[10][3][2] = {
    {{1, 2}, {3, 4}, {5, 6}},

    {{1, 4}, {2, 5}, {3, 6}},

    {{s21_INF, 2}, {3, 4}, {0.123124, 234.123}},

    {{s21_INF, 2}, {3, 4}, {0, 0 / 0.}},

    {{-1.3219847132, 2.12372938432 * 1e23},
     {99.99999999 * 1e-100, -0.},
     {-s21_INF, s21_INT_MIN}},

    {{-1.3219847132, 2.12372938434 * 1e23},
     {99.99999999 * 1e-100, -0.},
     {s21_INF, -s21_INF}},

};
double matrix_2_3[10][2][3] = {
    {{1, 2, 3}, {4, 5, 6}},

    {{1, -1, 1}, {2, 3, 4}},

    {{s21_INF, 2, 3}, {4, 0.123124, 234.123}},

    {{s21_INF, 2, 3}, {4, 0, 0 / 0.}},

    {{-1.3219847132, 2.12372938432 * 1e23, 99.99999999 * 1e-100},
     {-0., -s21_INF, s21_INT_MIN}},

    {{-1.3219847132, 2.12372938434 * 1e23, 99.99999999 * 1e-100},
     {-0., s21_INF, -s21_INF}},

};
double matrix_2_2[10][2][2] = {
    {{1, 2}, {3, 4}},

    {{-1, -2}, {-3, -4}},

    {{s21_INF, 2}, {3, 4}},

    {{s21_INF, 2}, {3, 4}},

    {{-1.3219847132, 2.12372938432 * 1e23}, {99.99999999 * 1e-100, -0.}},

    {{-1.3219847132, 2.12372938434 * 1e23}, {99.99999999 * 1e-100, -0.}},

};

double matrix_3_3[8][3][3] = {
    {{1, 2, 3}, {0, 4, 5}, {0, 0, 6}},

    {{1, 0, 0}, {2, 0, 0 / 0.}, {3, 4, 1}},

    {{1, 2, 3}, {-0.0, 4, 2}, {2, 3, 4}},

    {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},

    {{-1, -2, -3}, {-4, -5, -6}, {-7, -8, -9}},

    {{1, 2, 3}, {0, 4, 2}, {5, 2, 1}},

    {{2, 5, 7}, {6, 3, 4}, {5, -2, -3}},

    {{37, 38, 23}, {26, 32, 28}, {-10, -4, 8}},
};

double matrix_4_4[6][4][4] = {
    {{1.123, 2.999, 3.23, 4.76},
     {0.256, 4.987, 5.148, -0.123},
     {-200.01, 852.1324, 676.2, -100.20001},
     {2134.123, 92384.123, 0, 2111}},  // det = 507641914.691281

};
void printer__(matrix_t *A) {
  for (int i = 0; i < A->rows; ++i) {
    for (int j = 0; j < A->columns; ++j) {
      printf("%.8f ", A->matrix[i][j]);
    }
    printf("\n");
  }
}

int my_sum(int a, matrix_t *Arg, ...) {
  printf("%d\n", a);
  int result = 0;
  va_list factor;
  matrix_t *cur = Arg;    //указатель va_list
  va_start(factor, Arg);  // устанавливаем указатель
  for (int i = 0; i < a; i++) {
    result += cur->columns;
    cur = va_arg(factor, matrix_t *);
    // получаем значение текущего параметра типа int
  }
  va_end(factor);  // завершаем обработку параметров
  return result;
}

void print_err(int error) { printf("Here ERROR = |%d|\n", error); }

void printer_2(double arr[7][2][2], int n) {
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) printf("|%f| ", arr[n][i][j]);
    printf("\n");
  }
}

void test_create_remove(void) {
  int error = 0;
  for (int i = 0; i < 7; i++) {
    matrix_t *first = malloc(1 * sizeof(matrix_t));
    printf("VAL = ARR[%d][%d]\n", inv_size[i][ROW], inv_size[i][COL]);
    error = s21_create_matrix(inv_size[i][ROW], inv_size[i][COL], first);
    print_err(error);
    s21_remove_matrix(first);
  }
}
void test_compare(void) {
  //  double matrix_2_2[10][2][2] = {
  //      {{1, 2}, {3, 4.1234568}},
  //      {{1, 2}, {3, 4.1234567}},
  //      {{s21_INF, 2}, {3, 4}},
  //      {{s21_INF, 2}, {3, 4}},
  //      {{-1.3219847132, 2.12372938432 * 1e23}, {99.99999999 * 1e-100, -0.}},
  //      {{-1.3219847132, 2.12372938434 * 1e23}, {99.99999999 * 1e-100, -0.}},
  //
  //  };
  matrix_t *A = malloc(1 * sizeof(matrix_t));
  matrix_t *B = malloc(1 * sizeof(matrix_t));
  s21_create_matrix(2, 2, A);
  s21_create_matrix(2, 2, B);
  copy__(0, 2, 2, matrix_2_2, A->matrix);
  printer__(A);

  copy__(1, 2, 2, matrix_2_2, B->matrix);
  printer__(B);
  int res = s21_eq_matrix(A, B);
  res == SUCCESS ? printf("success\n") : printf("FAIL\n");
  s21_remove_matrix(A);
  s21_remove_matrix(B);
  free(A);
  free(B);
}

void test_inverse(void) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t R = {0};
  s21_create_matrix(4, 4, &A);
  copy__(0, 4, 4, matrix_4_4, A.matrix);
  double determinant = 0;
  s21_determinant(&A, &determinant);
  printf("Det = %f\n", determinant);
  int error = s21_inverse_matrix(&A, &B);
  print_err(error);
  printer__(&A);
  printer__(&B);
  error = s21_mult_matrix(&A, &B, &R);
  print_err(error);
  printer__(&R);
  if (R.matrix[0][0] == 1 && R.matrix[1][1] == 1 && R.matrix[2][2] == 1 &&
      R.matrix[3][3] == 1)
    printf("Success\n");
  else
    printf("Fail\n");
  //  printf("%.20f\n", R.matrix[0][0]);
  //  printf("%.20f\n", R.matrix[1][1]);
  //  printf("%.20f\n", R.matrix[2][2]);
  //  printf("%.20f\n", R.matrix[3][3]);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
}
int main(void) {
  matrix_t A, B;
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 123;
  double res;
  int error = s21_calc_complements(&A, &B);
  if (!error) {
    printer__(&B);
    printf("res = %f\n", A.matrix[0][0] * B.matrix[0][0]);
  } else {
    printf("erorr = %d\n", error);
  }
  //  s21_create_matrix(1, 1, &A);
  //  //  s21_create_matrix(2, 1, &B);
  //  A.matrix[0][0] = 5;
  //  //  A.matrix[0][1] = 2;
  //  //  A.matrix[1][0] = 3;
  //  //  A.matrix[1][1] = 4;
  //  printer__(&A);
  //  double result = 0;
  //  s21_determinant(&A, &result);
  //  printf("result%f\n", result);
  //
  //  int error = s21_inverse_matrix(&A, &B);
  //  print_err(error);
  //  printer__(&B);
  //  s21_mult_matrix(&A, &B, &res);
  //  printer__(&res);
  return 0;
}
