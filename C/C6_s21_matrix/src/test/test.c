#include "test.h"

START_TEST(test_s21_create_matrix) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t C = {0};
  int resultA = s21_create_matrix(5, 5, &A);
  ck_assert_int_eq(resultA, OK);
  resultA = s21_create_matrix(-4, 4, &B);
  ck_assert_int_eq(resultA, INVALID);
  resultA = s21_create_matrix(-4, 0, &C);
  ck_assert_int_eq(resultA, INVALID);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(test_s21_eq_matrix) {
  matrix_t A = {0}, B = {0};
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);
  int ret = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(ret, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

  ret = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(ret, FAILURE);

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(5, 5, &B);
  ret = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(ret, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);
  A.matrix[2][2] = -7;
  ret = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(ret, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);
  A.matrix[2][2] = -7;
  B.matrix[2][2] = -7;
  ret = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(ret, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST
//
START_TEST(test_s21_sum_matrix) {
  matrix_t A = {0}, B = {0}, res = {0}, res_org = {0};
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);
  //  s21_create_matrix(5, 5, &res);
  int ret = s21_sum_matrix(&A, &B, &res);
  ck_assert_int_eq(ret, OK);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
  // матрица b == 6 A == 5
  s21_create_matrix(6, 6, &B);
  ret = s21_sum_matrix(&A, &B, &res);
  ck_assert_int_eq(ret, CALC_ERR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  // матрица A == NULL
  s21_create_matrix(6, 6, &B);
  ret = s21_sum_matrix(&A, &B, &res);
  ck_assert_int_eq(ret, INVALID);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  //
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);
  s21_create_matrix(5, 5, &res_org);
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      A.matrix[i][j] = i + j;
      res_org.matrix[i][j] = i + j;
    }
  }
  ret = s21_sum_matrix(&A, &B, &res);
  ck_assert_int_eq(ret, OK);
  ret = s21_eq_matrix(&res, &res_org);
  ck_assert_int_eq(ret, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
  s21_remove_matrix(&res_org);
}
END_TEST
//
START_TEST(test_s21_sub_matrix) {
  matrix_t A = {0}, B = {0}, res = {0}, res_org = {0};
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);
  int ret = s21_sub_matrix(&A, &B, &res);
  ck_assert_int_eq(ret, OK);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
  // b 6 || a 5
  s21_create_matrix(6, 6, &B);
  ret = s21_sub_matrix(&A, &B, &res);
  ck_assert_int_eq(ret, CALC_ERR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  // A NULL
  s21_create_matrix(6, 6, &B);
  ret = s21_sub_matrix(&A, &B, &res);
  ck_assert_int_eq(ret, INVALID);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  // OK
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);
  s21_create_matrix(5, 5, &res_org);
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      A.matrix[i][j] = i - j;
      res_org.matrix[i][j] = i - j;
    }
  }
  ret = s21_sub_matrix(&A, &B, &res);
  ck_assert_int_eq(ret, OK);
  ret = s21_eq_matrix(&res, &res_org);
  ck_assert_int_eq(ret, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
  s21_remove_matrix(&res_org);
}
// END_TEST
//
START_TEST(test_s21_mult_number) {
  matrix_t A = {0}, res = {0}, res_org = {0};
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &res_org);
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      A.matrix[i][j] = 1;
      res_org.matrix[i][j] = 1 * 5;
    }
  }
  int ret = s21_mult_number(&A, 5, &res);
  ck_assert_int_eq(ret, OK);
  ret = s21_eq_matrix(&res, &res_org);
  ck_assert_int_eq(ret, SUCCESS);
  s21_remove_matrix(&A);
  ret = s21_mult_number(&A, 5, &res);
  ck_assert_int_eq(ret, INVALID);
  s21_remove_matrix(&res);
  s21_remove_matrix(&res_org);
}
END_TEST
//
START_TEST(test_s21_mult_matrix) {
  matrix_t A = {0}, B = {0}, res = {0}, res_org = {0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  s21_create_matrix(2, 2, &res_org);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      A.matrix[i][j] = i + j + 1;
      B.matrix[i][j] = i + j + 1;
    }
  }
  res_org.matrix[0][0] = 5;
  res_org.matrix[0][1] = 8;
  res_org.matrix[1][0] = 8;
  res_org.matrix[1][1] = 13;
  int ret = s21_mult_matrix(&A, &B, &res);
  ck_assert_int_eq(ret, OK);
  ret = s21_eq_matrix(&res, &res_org);
  ck_assert_int_eq(ret, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
  s21_remove_matrix(&res_org);

  s21_create_matrix(3, 2, &A);
  s21_create_matrix(2, 2, &B);
  s21_create_matrix(3, 2, &res_org);
  ret = s21_mult_matrix(&A, &B, &res);
  ck_assert_int_eq(ret, OK);
  ret = s21_eq_matrix(&res, &res_org);
  ck_assert_int_eq(ret, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
  s21_remove_matrix(&res_org);

  s21_create_matrix(2, 7, &A);
  s21_create_matrix(2, 2, &B);
  ret = s21_mult_matrix(&A, &B, &res);
  ck_assert_int_eq(ret, CALC_ERR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

  ret = s21_mult_matrix(&A, &B, &res);
  ck_assert_int_eq(ret, INVALID);
  s21_remove_matrix(&res);
}
END_TEST
//
START_TEST(test_s21_transpose) {
  matrix_t A = {0}, res_my = {0}, res_org = {0};

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &res_org);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  res_org.matrix[0][0] = 1;
  res_org.matrix[0][1] = 3;
  res_org.matrix[1][0] = 2;
  res_org.matrix[1][1] = 4;
  int ret = s21_transpose(&A, &res_my);
  ck_assert_int_eq(ret, OK);
  ret = s21_eq_matrix(&res_my, &res_org);
  ck_assert_int_eq(ret, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res_my);
  s21_remove_matrix(&res_org);

  double matrix[3][2] = {{1, 2}, {3, 4}, {5, 6}};
  double res[2][3] = {{1, 3, 5}, {2, 4, 6}};
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(2, 3, &res_org);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 2; j++) {
      A.matrix[i][j] = matrix[i][j];
    }
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      res_org.matrix[i][j] = res[i][j];
    }
  }
  ret = s21_transpose(&A, &res_my);
  ck_assert_int_eq(ret, OK);
  ret = s21_eq_matrix(&res_my, &res_org);
  ck_assert_int_eq(ret, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res_my);
  s21_remove_matrix(&res_org);
  ret = s21_transpose(&A, &res_my);
  ck_assert_int_eq(ret, INVALID);
}
END_TEST
//
START_TEST(test_s21_calc_complements) {
  double m[3][3] = {{1, 2, 3}, {0, 4, 2}, {5, 2, 1}};
  double r[3][3] = {{0, 10, -20}, {4, -14, 8}, {-8, -2, 4}};
  matrix_t matrix = {0}, res_org = {0}, res_my = {0};
  s21_create_matrix(3, 3, &matrix);
  s21_create_matrix(3, 3, &res_org);
  for (int i = 0; i < matrix.rows; i++) {
    for (int j = 0; j < matrix.columns; j++) {
      matrix.matrix[i][j] = m[i][j];
    }
  }
  for (int i = 0; i < matrix.rows; i++) {
    for (int j = 0; j < matrix.columns; j++) {
      res_org.matrix[i][j] = r[i][j];
    }
  }
  int ret = s21_calc_complements(&matrix, &res_my);
  ck_assert_int_eq(ret, OK);
  ret = s21_eq_matrix(&res_org, &res_my);
  ck_assert_int_eq(ret, SUCCESS);
  s21_remove_matrix(&matrix);
  s21_remove_matrix(&res_my);
  s21_remove_matrix(&res_org);

  s21_create_matrix(2, 3, &matrix);
  ret = s21_calc_complements(&matrix, &res_my);
  ck_assert_int_eq(ret, CALC_ERR);
  s21_remove_matrix(&matrix);
  s21_remove_matrix(&res_my);
  ret = s21_calc_complements(&matrix, &res_my);
  ck_assert_int_eq(ret, INVALID);
  s21_remove_matrix(&res_my);
}
END_TEST
//
START_TEST(test_s21_determinant) {
  matrix_t matrix = {0};
  s21_create_matrix(3, 3, &matrix);
  int count = 1;
  for (int i = 0; i < matrix.rows; i++) {
    for (int j = 0; j < matrix.columns; j++) {
      matrix.matrix[i][j] = count++;
    }
  }
  matrix.matrix[2][2] = 10;
  double res = 0;
  int ret = s21_determinant(&matrix, &res);
  ck_assert_uint_eq(res, -3);
  ck_assert_int_eq(ret, OK);
  s21_remove_matrix(&matrix);

  s21_create_matrix(2, 3, &matrix);
  ret = s21_determinant(&matrix, &res);
  ck_assert_int_eq(ret, CALC_ERR);
  s21_remove_matrix(&matrix);

  ret = s21_determinant(&matrix, &res);
  ck_assert_int_eq(ret, INVALID);
}
END_TEST
//
START_TEST(test_s21_inverse_matrix) {
  double m[3][3] = {{2, 5, 7}, {6, 3, 4}, {5, -2, -3}};
  double r[3][3] = {{1, -1, 1}, {-38, 41, -34}, {27, -29, 24}};
  matrix_t matrix = {0}, res_org = {0}, res_my = {0};
  s21_create_matrix(3, 3, &matrix);
  s21_create_matrix(3, 3, &res_org);
  for (int i = 0; i < matrix.rows; i++) {
    for (int j = 0; j < matrix.columns; j++) {
      matrix.matrix[i][j] = m[i][j];
    }
  }
  for (int i = 0; i < matrix.rows; i++) {
    for (int j = 0; j < matrix.columns; j++) {
      res_org.matrix[i][j] = r[i][j];
    }
  }
  int ret = s21_inverse_matrix(&matrix, &res_my);
  ck_assert_int_eq(ret, OK);
  ret = s21_eq_matrix(&res_org, &res_my);
  s21_remove_matrix(&res_my);
  //  s21_remove_matrix(&res_org);
  //  s21_remove_matrix(&matrix);
  ck_assert_int_eq(ret, SUCCESS);

  double m2[3][3] = {{2, 5, 7}, {0, 0, 0}, {5, -2, -3}};
  for (int i = 0; i < matrix.rows; i++) {
    for (int j = 0; j < matrix.columns; j++) {
      matrix.matrix[i][j] = m2[i][j];
    }
  }
  ret = s21_inverse_matrix(&matrix, &res_my);
  ck_assert_int_eq(ret, CALC_ERR);
  s21_remove_matrix(&matrix);
  s21_remove_matrix(&res_my);
  s21_remove_matrix(&res_org);
}
END_TEST

Suite *s21_matrix_test(void) {
  Suite *s = suite_create("s21_matrix_test");

  TCase *tc_s21_create_matrix = tcase_create("test_s21_create_matrix");
  suite_add_tcase(s, tc_s21_create_matrix);
  tcase_add_test(tc_s21_create_matrix, test_s21_create_matrix);

  TCase *tc_s21_eq_matrix = tcase_create("test_s21_eq_matrix");
  suite_add_tcase(s, tc_s21_eq_matrix);
  tcase_add_test(tc_s21_eq_matrix, test_s21_eq_matrix);
  //
  TCase *tc_s21_sum_matrix = tcase_create("test_s21_sum_matrix");
  suite_add_tcase(s, tc_s21_sum_matrix);
  tcase_add_test(tc_s21_sum_matrix, test_s21_sum_matrix);
  //
  TCase *tc_s21_sub_matrix = tcase_create("test_s21_sub_matrix");
  suite_add_tcase(s, tc_s21_sub_matrix);
  tcase_add_test(tc_s21_sub_matrix, test_s21_sub_matrix);
  //
  TCase *tc_s21_mult_number = tcase_create("test_s21_mult_number");
  suite_add_tcase(s, tc_s21_mult_number);
  tcase_add_test(tc_s21_mult_number, test_s21_mult_number);
  //
  TCase *tc_s21_mult_matrix = tcase_create("test_s21_mult_matrix");
  suite_add_tcase(s, tc_s21_mult_matrix);
  tcase_add_test(tc_s21_mult_matrix, test_s21_mult_matrix);
  //
  TCase *tc_s21_transpose = tcase_create("test_s21_transpose");
  suite_add_tcase(s, tc_s21_transpose);
  tcase_add_test(tc_s21_transpose, test_s21_transpose);
  //
  TCase *tc_s21_calc_complements = tcase_create("test_s21_calc_complements");
  suite_add_tcase(s, tc_s21_calc_complements);
  tcase_add_test(tc_s21_calc_complements, test_s21_calc_complements);
  //
  TCase *tc_s21_determinant = tcase_create("test_s21_determinant");
  suite_add_tcase(s, tc_s21_determinant);
  tcase_add_test(tc_s21_determinant, test_s21_determinant);
  //
  TCase *tc_s21_inverse_matrix = tcase_create("test_s21_inverse_matrix");
  suite_add_tcase(s, tc_s21_inverse_matrix);
  tcase_add_test(tc_s21_inverse_matrix, test_s21_inverse_matrix);

  return s;
}

int main(void) {
  int number_failed = 0;
  Suite *s = s21_matrix_test();
  Suite *g = s21_matrix_inv();
  SRunner *sr = srunner_create(s);
  SRunner *gr = srunner_create(g);
  srunner_run_all(sr, CK_NORMAL);
  srunner_run_all(gr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  srunner_free(gr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}