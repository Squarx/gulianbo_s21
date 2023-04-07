#include <check.h>
#include <unistd.h>

#include "s21_3DViewer.h"
#include "s21_matrix.h"

static double res_v[27] = {0,    0,    0,    -0.5, -0.5, -0.5, -0.5, -0.5, 0.5,
                           -0.5, 0.5,  -0.5, -0.5, 0.5,  0.5,  0.5,  -0.5, -0.5,
                           0.5,  -0.5, 0.5,  0.5,  0.5,  -0.5, 0.5,  0.5,  0.5};
static int res_f[72] = {1, 7, 7, 5, 5, 1, 1, 3, 3, 7, 7, 1, 1, 4, 4, 3, 3, 1,
                        1, 2, 2, 4, 4, 1, 3, 8, 8, 7, 7, 3, 3, 4, 4, 8, 8, 3,
                        5, 7, 7, 8, 8, 5, 5, 8, 8, 6, 6, 5, 1, 5, 5, 6, 6, 1,
                        1, 6, 6, 2, 2, 1, 4, 6, 6, 8, 8, 4, 4, 2, 2, 6, 6, 4};

int eq(V_F count);

int eq(V_F count) {
  V_F res = {0};
  int error = 0;

  res.resultV = res_v;
  res.resultF = res_f;

  for (int i = 0; i < (count.v + 1) * 3 && error == 0; i++) {
    if (res.resultV[i] != count.resultV[i]) {
      error = 1;
      printf("i: %d, res: %f, count: %f", i, res.resultV[i], count.resultV[i]);
    }
  }

  for (int i = 0; i < count.f * 6 && error == 0; i++) {
    if (res.resultF[i] != count.resultF[i]) {
      error = 1;
      printf("i: %d, res: %d, count: %d", i, res.resultF[i], count.resultF[i]);
    }
  }
  return error;
}

START_TEST(test_s21_empty) {
  char PathName[100];
  getcwd(PathName, 100);
  strcat(PathName, "/Objects/cube_empty.obj");
  V_F count = {0};
  char *path = PathName;
  s21_3DViewer(path, &count);

  ck_assert_int_eq(count.error, 1);

  clean_all(&count);
}

END_TEST

START_TEST(test_s21_figure) {
  V_F count = {0};
  char PathName[100];
  getcwd(PathName, 100);
  strcat(PathName, "/Objects/cube.obj");
  char *path = PathName;
  s21_3DViewer(path, &count);
  int res = eq(count);

  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(count.error, 0);

  clean_all(&count);
}

END_TEST

START_TEST(test_s21_no_file) {
  V_F count = {0};
  char *path = "/Users/aqualadt/C8_3DViewer_v1.0-0/src/aboba.obj";
  s21_3DViewer(path, &count);
  ck_assert_int_eq(count.error, 1);
}

START_TEST(test_s21_move) {
  //    V_F count = {0};
  matrix_t A;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 1;
  A.matrix[1][0] = 1;
  A.matrix[1][1] = 1;
  s21_move_matrix(&A, 2, 0);
  ck_assert_float_eq(A.matrix[1][0], 3);
  s21_remove_matrix(&A);
}

START_TEST(test_s21_scale) {
  //    V_F count = {0};
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 2;

  A.matrix[1][0] = 2;
  A.matrix[1][1] = 2;
  A.matrix[1][2] = 2;

  A.matrix[2][0] = 2;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 2;
  s21_scaling_matrix(&A, 1.41);
  ck_assert_float_eq(A.matrix[1][0], 2.82);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_rotate_X) {
  //    V_F count = {0};
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 2;

  A.matrix[1][0] = 2;
  A.matrix[1][1] = 2;
  A.matrix[1][2] = 2;

  A.matrix[2][0] = 2;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 2;
  s21_x_rotation_matrix(&A, 1.41);
  ck_assert_float_eq(A.matrix[1][0], 2);
  //    printf("|%f||%f|\n", A.matrix[1][1], A.matrix[1][2]);
  ck_assert_double_eq_tol(A.matrix[1][1], -1.653992, 1e-6);
  ck_assert_double_eq_tol(A.matrix[1][2], 2.294409, 1e-6);
  s21_remove_matrix(&A);
}

START_TEST(test_s21_rotate_Y) {
  //    V_F count = {0};
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 2;

  A.matrix[1][0] = 2;
  A.matrix[1][1] = 2;
  A.matrix[1][2] = 2;

  A.matrix[2][0] = 2;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 2;
  s21_y_rotation_matrix(&A, 1.41);
  ck_assert_float_eq(A.matrix[1][1], 2);
  //    printf("|%f||%f|\n", A.matrix[1][0], A.matrix[1][2]);
  ck_assert_double_eq_tol(A.matrix[1][2], -1.653992, 1e-6);
  ck_assert_double_eq_tol(A.matrix[1][0], 2.294409, 1e-6);
  s21_remove_matrix(&A);
}

START_TEST(test_s21_rotate_Z) {
  //    V_F count = {0};
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 2;

  A.matrix[1][0] = 2;
  A.matrix[1][1] = 2;
  A.matrix[1][2] = 2;

  A.matrix[2][0] = 2;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 2;
  s21_z_rotation_matrix(&A, 1.41);
  ck_assert_float_eq(A.matrix[1][2], 2);
  ck_assert_double_eq_tol(A.matrix[1][0], -1.653992, 1e-6);
  ck_assert_double_eq_tol(A.matrix[1][1], 2.294409, 1e-6);
  s21_remove_matrix(&A);
}

Suite *s21_viewer_test(void) {
  Suite *s = suite_create("s21_viewer_test");

  TCase *tc_s21_empty = tcase_create("test_s21_empty");
  suite_add_tcase(s, tc_s21_empty);
  tcase_add_test(tc_s21_empty, test_s21_empty);

  TCase *tc_s21_figure = tcase_create("test_s21_figure");
  suite_add_tcase(s, tc_s21_figure);
  tcase_add_test(tc_s21_figure, test_s21_figure);

  TCase *tc_s21_no_file = tcase_create("test_s21_no_file");
  suite_add_tcase(s, tc_s21_no_file);
  tcase_add_test(tc_s21_no_file, test_s21_no_file);

  TCase *tc_s21_afine = tcase_create("test_s21_afine");
  suite_add_tcase(s, tc_s21_afine);
  tcase_add_test(tc_s21_afine, test_s21_move);
  tcase_add_test(tc_s21_afine, test_s21_scale);
  tcase_add_test(tc_s21_afine, test_s21_rotate_X);
  tcase_add_test(tc_s21_afine, test_s21_rotate_Y);
  tcase_add_test(tc_s21_afine, test_s21_rotate_Z);
  return s;
}

int main() {
  int number_failed = 0;
  Suite *s = s21_viewer_test();
  SRunner *sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

// int main() {
//   V_F count = {0};
//   char *path = "/Users/aqualadt/C8_3DViewer_v1.0-0/src/cube.obj";
//   s21_3DViewer(path, &count);
//   clean_all(&count);
// }
