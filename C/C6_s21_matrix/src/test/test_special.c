//
// Created by Gulian Boris on 1/13/23.
//
#include "test.h"
/**
 * @example 0 - incorrect  nan
 * @example 2 - with inf
 * @example 4 == 5 float
 *
 */
// static double matrix_2_2[10][2][2] = {
//     {{1, 2}, {3, 0 / 0.}},  // incorr
//
//     {{1, 2}, {3, 4}},
//
//     {{s21_INF, 2}, {3, 4}},
//
//     {{s21_INF, 2}, {3, 4}},
//
//     {{-1.3219847132, 2.12372938432 * 1e23}, {99.99999999 * 1e-100, -0.}},
//
//     {{-1.3219847132, 2.12372938434 * 1e23}, {99.99999999 * 1e-100, -0.}},
//
// };
//
// static double matrix_3_2[10][3][2] = {
//     {{1, 2}, {3, 4}, {5, 6}},
//
//     {{1, 4}, {2, 5}, {3, 6}},
//
//     {{s21_INF, 2}, {3, 4}, {0.123124, 234.123}},
//
//     {{s21_INF, 2}, {3, 4}, {0, 0 / 0.}},
//
//     {{-1.3219847132, 2.12372938432 * 1e23},
//      {99.99999999 * 1e-100, -0.},
//      {-s21_INF, s21_INT_MIN}},
//
//     {{-1.3219847132, 2.12372938434 * 1e23},
//      {99.99999999 * 1e-100, -0.},
//      {s21_INF, -s21_INF}},
//
// };
//
// static double matrix_2_3[10][2][3] = {
//     {{1, 2, 3}, {4, 5, 6}},
//
//     {{1, -1, 1}, {2, 3, 4}},
//
//     {{s21_INF, 2, 3}, {4, 0.123124, 234.123}},
//
//     {{s21_INF, 2, 3}, {4, 0, 0 / 0.}},
//
//     {{-1.3219847132, 2.12372938432 * 1e23, 99.99999999 * 1e-100},
//      {-0., -s21_INF, s21_INT_MIN}},
//
//     {{-1.3219847132, 2.12372938434 * 1e23, 99.99999999 * 1e-100},
//      {-0., s21_INF, -s21_INF}},
//
// };
//
static double matrix_3_3[11][3][3] = {
    {{1, 2, 3}, {0, 4, 5}, {0, 0, 6}},

    {{1, 0, 0}, {2, 0, 0 / 0.}, {3, 4, 1}},

    {{1, 2, 3}, {-0.0, 4, 2}, {2, 3, 4}},

    {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},

    {{-1, -2, -3}, {-4, -5, -6}, {-7, -8, -9}},

    {{1, 2, 3}, {0, 4, 2}, {5, 2, 1}},

    {{2, 5, 7}, {6, 3, 4}, {5, -2, -3}},

    {{2, 5, 7}, {s21_INF, 3, 4}, {5, -2, -3}},

    {{2, 4, 6}, {0, 8, 10}, {0, 0, 12}},

    {{s21_INF, 5, 7}, {s21_INF, 3, 4}, {5, -2, -3}},

    {{0, 0, 0}, {0, 8, 10}, {0, 0, 12}},
};
//
static double matrix_4_4[6][4][4] = {
    {{1.123, 2.999, 3.23, 4.76},
     {0.256, 4.987, 5.148, -0.123},
     {-200.01, 852.1324, 676.2, -100.20001},
     {2134.123, 92384.123, 0, 2111}},  // det = 507641914.691281

};
START_TEST(INV_create) {
  matrix_t A;
  int error = 0;

  error = s21_create_matrix(1, 1, NULL);
  ck_assert_int_eq(error, 1);

  error = s21_create_matrix(0, 0, &A);
  ck_assert_int_eq(error, 1);

  error = s21_create_matrix(0, 1, &A);
  ck_assert_int_eq(error, 1);

  error = s21_create_matrix(-1, 1, &A);
  ck_assert_int_eq(error, 1);

  error = s21_create_matrix(-1, 1, &A);
  ck_assert_int_eq(error, 1);

  error = s21_create_matrix(-1, -1, &A);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(INV_eq) {
  matrix_t A;
  matrix_t B;
  //  matrix_t Res;
  int res = 0;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  copy__(0, 3, 3, matrix_3_3, A.matrix);
  copy__(0, 3, 3, matrix_3_3, B.matrix);
  res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, SUCCESS);

  copy__(7, 3, 3, matrix_3_3, A.matrix);
  copy__(7, 3, 3, matrix_3_3, B.matrix);
  res = s21_eq_matrix(&A, &B);     // matrix have inf
  ck_assert_int_eq(res, SUCCESS);  // should it be FAIL ?
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST
START_TEST(INV_mult_num) {
  matrix_t A;
  matrix_t B;
  matrix_t Res;
  int error = 0;
  double num = 2;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &Res);
  copy__(0, 3, 3, matrix_3_3, A.matrix);
  copy__(8, 3, 3, matrix_3_3, Res.matrix);
  error = s21_mult_number(&A, num, &B);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(s21_eq_matrix(&B, &Res), 1);
  s21_remove_matrix(&B);
  num = 0 / 0.;
  error = s21_mult_number(&A, num, &B);  // num = NAN
  ck_assert_int_eq(error, 2);
  s21_remove_matrix(&B);
  num = 2;
  error = s21_mult_number(&A, num, NULL);  // NUll => error 1 2 ??
  ck_assert_int_eq(error, 2);
  error = s21_mult_number(NULL, num, &B);
  ck_assert_int_eq(error, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&Res);
}
END_TEST

START_TEST(INV_mult_matrix) {
  matrix_t A;
  matrix_t B;
  matrix_t Res;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  copy__(0, 3, 3, matrix_3_3, A.matrix);
  copy__(1, 3, 3, matrix_3_3, A.matrix);
  int error = s21_mult_matrix(&A, &B, NULL);
  ck_assert_int_eq(error, 2);
  error = s21_mult_matrix(&A, NULL, &Res);
  ck_assert_int_eq(error, 2);
  s21_remove_matrix(&B);
  s21_create_matrix(2, 3, &B);
  error = s21_mult_matrix(&A, NULL, &Res);
  ck_assert_int_eq(error, 2);
  s21_remove_matrix(&B);
  s21_create_matrix(4, 3, &B);
  error = s21_mult_matrix(&A, NULL, &Res);
  ck_assert_int_eq(error, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  copy__(9, 3, 3, matrix_3_3, A.matrix);  // A[i][j] *  B[k][m] == Nan
  copy__(10, 3, 3, matrix_3_3, B.matrix);
  error = s21_mult_matrix(&A, &B, &Res);
  ck_assert_int_eq(error, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&Res);
}
START_TEST(INV_t_inv_trnsps) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(3, 3, &A);
  int error = s21_transpose(NULL, &B);
  ck_assert_int_eq(error, CALC_ERR);
  error = s21_transpose(&A, NULL);
  ck_assert_int_eq(error, CALC_ERR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(INV_t_inv_clc_cmpnts) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(3, 3, &A);
  copy__(0, 3, 3, matrix_3_3, A.matrix);
  int error = s21_calc_complements(&A, NULL);
  ck_assert_int_eq(error, CALC_ERR);
  error = s21_calc_complements(NULL, &B);
  ck_assert_int_eq(error, CALC_ERR);
  s21_remove_matrix(&A);
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 0;
  error = s21_inverse_matrix(&A, &B);
  ck_assert_int_eq(error, CALC_ERR);
  A.matrix[0][0] = 5;
  error = s21_inverse_matrix(&A, &B);
  ck_assert_int_eq(error, OK);
  ck_assert_double_eq(B.matrix[0][0], 0.2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST
START_TEST(INV_t_inv_det) {
  double res;
  matrix_t A;
  int error;
  s21_create_matrix(3, 3, &A);
  copy__(0, 3, 3, matrix_3_3, A.matrix);
  error = s21_determinant(&A, NULL);
  ck_assert_int_eq(error, CALC_ERR);
  error = s21_determinant(NULL, &res);
  ck_assert_int_eq(error, CALC_ERR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(INV_t_inv_mx) {
  matrix_t A;
  matrix_t Res;
  int error;
  s21_create_matrix(3, 3, &A);
  copy__(0, 3, 3, matrix_3_3, A.matrix);
  error = s21_inverse_matrix(&A, NULL);
  ck_assert_int_eq(error, CALC_ERR);
  error = s21_inverse_matrix(NULL, &Res);
  ck_assert_int_eq(error, CALC_ERR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(INV_t_inv_sum) {
  matrix_t A;
  matrix_t B;
  matrix_t Res;
  int error;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(4, 4, &B);
  copy__(0, 3, 3, matrix_3_3, A.matrix);
  copy__(0, 4, 4, matrix_4_4, B.matrix);
  error = s21_sum_matrix(&A, &B, &Res);
  ck_assert_int_eq(error, CALC_ERR);
  error = s21_sum_matrix(NULL, &B, &Res);
  ck_assert_int_eq(error, CALC_ERR);
  error = s21_sum_matrix(&A, NULL, &Res);
  ck_assert_int_eq(error, CALC_ERR);
  error = s21_sum_matrix(&A, &B, NULL);
  ck_assert_int_eq(error, CALC_ERR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(INV_t_inv_sub) {
  matrix_t A;
  matrix_t B;
  matrix_t Res;
  int error;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(4, 4, &B);
  copy__(0, 3, 3, matrix_3_3, A.matrix);
  copy__(0, 4, 4, matrix_4_4, B.matrix);
  error = s21_sub_matrix(&A, &B, &Res);
  ck_assert_int_eq(error, CALC_ERR);
  error = s21_sub_matrix(NULL, &B, &Res);
  ck_assert_int_eq(error, CALC_ERR);
  error = s21_sub_matrix(&A, NULL, &Res);
  ck_assert_int_eq(error, CALC_ERR);
  error = s21_sub_matrix(&A, &B, NULL);
  ck_assert_int_eq(error, CALC_ERR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_determinant_test_1x1) {
  matrix_t matrix;
  double value = 142;
  s21_create_matrix(1, 1, &matrix);
  matrix.matrix[0][0] = 142;
  double res;
  s21_determinant(&matrix, &res);
  ck_assert_double_eq_tol(res, value, 1e-7);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(s21_determinant_test_2x2) {
  matrix_t matrix;
  double value = 10759902.756;

  s21_create_matrix(2, 2, &matrix);
  matrix.matrix[0][0] = 14234;
  matrix.matrix[0][1] = -2234;
  matrix.matrix[1][0] = 3324;
  matrix.matrix[1][1] = 234.234;

  double res;
  s21_determinant(&matrix, &res);
  ck_assert_double_eq_tol(res, value, 1e-7);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(s21_determinant_test_3x3) {
  matrix_t matrix;
  double value = -14351145.1125;
  double res;

  s21_create_matrix(3, 3, &matrix);
  matrix.matrix[0][0] = 1234.25;
  matrix.matrix[0][1] = -234.4;
  matrix.matrix[0][2] = 624;
  matrix.matrix[1][0] = 43;
  matrix.matrix[1][1] = 45;
  matrix.matrix[1][2] = 1;
  matrix.matrix[2][0] = 0;
  matrix.matrix[2][1] = -560;
  matrix.matrix[2][2] = -0.25;

  s21_determinant(&matrix, &res);
  ck_assert_double_eq_tol(res, value, 1e-7);
  s21_remove_matrix(&matrix);
}
END_TEST

//
START_TEST(s21_determinant_test_4x4) {
  matrix_t matrix;
  double value = 1563370.85615;
  double res;

  s21_create_matrix(4, 4, &matrix);
  matrix.matrix[0][0] = 1234.25;
  matrix.matrix[0][1] = -234.4;
  matrix.matrix[0][2] = 624;
  matrix.matrix[0][3] = 624;

  matrix.matrix[1][0] = 43;
  matrix.matrix[1][1] = 45;
  matrix.matrix[1][2] = 1;
  matrix.matrix[1][3] = 1;

  matrix.matrix[2][0] = 0;
  matrix.matrix[2][1] = -2;
  matrix.matrix[2][2] = -0.25;
  matrix.matrix[2][3] = -0.45;

  matrix.matrix[3][0] = 30;
  matrix.matrix[3][1] = 2.303;
  matrix.matrix[3][2] = 23;
  matrix.matrix[3][3] = 2;

  s21_determinant(&matrix, &res);
  ck_assert_double_eq_tol(res, value, 1e-7);
  s21_remove_matrix(&matrix);
}
END_TEST
//

START_TEST(s21_determinant_test_5x5) {
  matrix_t matrix;
  double value = -82677054.89092243;
  double res;

  s21_create_matrix(5, 5, &matrix);
  matrix.matrix[0][0] = 1234.25;
  matrix.matrix[0][1] = -234.4;
  matrix.matrix[0][2] = 624;
  matrix.matrix[0][3] = 624;
  matrix.matrix[0][4] = 23;

  matrix.matrix[1][0] = 43;
  matrix.matrix[1][1] = 45;
  matrix.matrix[1][2] = 1;
  matrix.matrix[1][3] = 1;
  matrix.matrix[1][4] = 14.3;

  matrix.matrix[2][0] = 0;
  matrix.matrix[2][1] = -2;
  matrix.matrix[2][2] = -0.25;
  matrix.matrix[2][3] = -0.45;
  matrix.matrix[2][4] = 3.15;

  matrix.matrix[3][0] = 30;
  matrix.matrix[3][1] = 2.303;
  matrix.matrix[3][2] = 23;
  matrix.matrix[3][3] = 2;
  matrix.matrix[3][4] = 25.5;

  matrix.matrix[4][0] = 14.04;
  matrix.matrix[4][1] = 42.07;
  matrix.matrix[4][2] = -9.3;
  matrix.matrix[4][3] = -25;
  matrix.matrix[4][4] = -2.5;

  s21_determinant(&matrix, &res);
  ck_assert_double_eq_tol(res, value, 1e-7);
  s21_remove_matrix(&matrix);
}
END_TEST

//
START_TEST(s21_determinant_test_6x6) {
  matrix_t matrix;
  double value = 53342143.1860735;
  double res;

  s21_create_matrix(6, 6, &matrix);
  matrix.matrix[0][0] = 1;
  matrix.matrix[0][1] = 2;
  matrix.matrix[0][2] = 0.1;
  matrix.matrix[0][3] = 0.55;
  matrix.matrix[0][4] = 0.66;
  matrix.matrix[0][5] = 0.4;

  matrix.matrix[1][0] = 34;
  matrix.matrix[1][1] = 35;
  matrix.matrix[1][2] = 89;
  matrix.matrix[1][3] = 5;
  matrix.matrix[1][4] = 78;
  matrix.matrix[1][5] = 13;

  matrix.matrix[2][0] = 12;
  matrix.matrix[2][1] = 35;
  matrix.matrix[2][2] = 0.48;
  matrix.matrix[2][3] = 0.56;
  matrix.matrix[2][4] = 0.12;
  matrix.matrix[2][5] = 42;

  matrix.matrix[3][0] = 32;
  matrix.matrix[3][1] = 13;
  matrix.matrix[3][2] = 12;
  matrix.matrix[3][3] = 12;
  matrix.matrix[3][4] = 11;
  matrix.matrix[3][5] = 0.112;

  matrix.matrix[4][0] = 2.01;
  matrix.matrix[4][1] = 2.9;
  matrix.matrix[4][2] = 5;
  matrix.matrix[4][3] = 45;
  matrix.matrix[4][4] = 62.5;
  matrix.matrix[4][5] = 52.2;

  matrix.matrix[5][0] = 5.4;
  matrix.matrix[5][1] = 56.5;
  matrix.matrix[5][2] = 0.1;
  matrix.matrix[5][3] = 3.5;
  matrix.matrix[5][4] = 7;
  matrix.matrix[5][5] = 8;

  s21_determinant(&matrix, &res);
  ck_assert_double_eq_tol(res, value, 1e-7);
  s21_remove_matrix(&matrix);
}

Suite *s21_matrix_inv(void) {
  Suite *Gulianbo = suite_create("s21_inv_test");

  TCase *t_inv_create = tcase_create("test_INV_s21_create_matrix");
  suite_add_tcase(Gulianbo, t_inv_create);
  tcase_add_test(t_inv_create, INV_create);

  TCase *t_inv_cmp = tcase_create("test_INV_s21_cmp");
  suite_add_tcase(Gulianbo, t_inv_cmp);
  tcase_add_test(t_inv_cmp, INV_eq);

  TCase *t_inv_mul_num = tcase_create("test_INV_s21_mul_num");
  suite_add_tcase(Gulianbo, t_inv_mul_num);
  tcase_add_test(t_inv_mul_num, INV_mult_num);

  TCase *t_inv_mul_matrix = tcase_create("test_INV_s21_mul_matrix");
  suite_add_tcase(Gulianbo, t_inv_mul_matrix);
  tcase_add_test(t_inv_mul_matrix, INV_mult_matrix);

  TCase *t_inv_trnsps = tcase_create("test_INV_s21_trnsps");
  suite_add_tcase(Gulianbo, t_inv_trnsps);
  tcase_add_test(t_inv_trnsps, INV_t_inv_trnsps);

  TCase *t_inv_clc_cmpnts = tcase_create("t_inv_clc_cmpnts");
  suite_add_tcase(Gulianbo, t_inv_clc_cmpnts);
  tcase_add_test(t_inv_clc_cmpnts, INV_t_inv_clc_cmpnts);

  TCase *t_inv_det = tcase_create("t_inv_det");
  suite_add_tcase(Gulianbo, t_inv_det);
  tcase_add_test(t_inv_det, INV_t_inv_det);

  TCase *t_inv_mx = tcase_create("t_inv_mx");
  suite_add_tcase(Gulianbo, t_inv_mx);
  tcase_add_test(t_inv_mx, INV_t_inv_mx);

  TCase *t_inv_sub = tcase_create("t_inv_sub");
  suite_add_tcase(Gulianbo, t_inv_sub);
  tcase_add_test(t_inv_sub, INV_t_inv_sub);

  TCase *t_inv_sum = tcase_create("t_inv_sum");
  suite_add_tcase(Gulianbo, t_inv_sum);
  tcase_add_test(t_inv_sum, INV_t_inv_sum);

  TCase *t_det_cond = tcase_create("t_det_con_jump");
  suite_add_tcase(Gulianbo, t_det_cond);
  tcase_add_test(t_det_cond, s21_determinant_test_1x1);
  tcase_add_test(t_det_cond, s21_determinant_test_2x2);
  tcase_add_test(t_det_cond, s21_determinant_test_3x3);
  tcase_add_test(t_det_cond, s21_determinant_test_4x4);
  tcase_add_test(t_det_cond, s21_determinant_test_5x5);
  tcase_add_test(t_det_cond, s21_determinant_test_6x6);

  return Gulianbo;
}