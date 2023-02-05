#include "test.h"
START_TEST(test_01_s21_exp_s21_NAN) {
#line 13
    long double orig = exp(s21_NAN), our = s21_exp(s21_NAN);
    int res = 0;
    if (isnan(orig) && isnan(our)) {
      res = 1;
    }
    ck_assert_int_eq(1, res);
}
END_TEST

START_TEST(test_02_s21_exp_s21_INF) {
#line 21
  long double orig = exp(s21_INF), our = s21_exp(s21_INF);
  int res = 0;
  if (isinf(orig) && isinf(our)) {
    res = 1;
  }
  ck_assert_int_eq(1, res);
}
END_TEST

START_TEST(test_03_s21_exp_NEG_s21_INF) {
#line 28
  long double orig = exp(-s21_INF), our = s21_exp(-s21_INF);
  int res = 0;
  if (fabsl(orig - our) <= 1e-6) {
    res = 1;
  }
  ck_assert_int_eq(1, res);
}
END_TEST

START_TEST(test_04_s21_exp_ZERO) {
#line 36
  char orig[10] = {0}, our[10] = {0};
  sprintf(orig, "%.6f", exp(0));
  sprintf(our, "%.6Lf", s21_exp(0));
  ck_assert_str_eq(orig, our);
}
END_TEST

START_TEST(test_05_s21_exp_ONE) {
#line 42
  char orig[10] = {0}, our[10] = {0};
  sprintf(orig, "%.6f", exp(1));
  sprintf(our, "%.6Lf", s21_exp(1));
  ck_assert_str_eq(orig, our);
}
END_TEST

START_TEST(test_06_s21_exp_TWO) {
#line 48
  char orig[10] = {0}, our[10] = {0};
  sprintf(orig, "%.6f", exp(2));
  sprintf(our, "%.6Lf", s21_exp(2));
  ck_assert_str_eq(orig, our);
}
END_TEST

START_TEST(test_07_s21_exp_FRACTION) {
#line 54
  char orig[10] = {0}, our[10] = {0};
  sprintf(orig, "%.6f", exp(1.5));
  sprintf(our, "%.6Lf", s21_exp(1.5));
  ck_assert_str_eq(orig, our);
}
END_TEST

START_TEST(test_08_s21_exp_NEG_FRACTION) {
#line 60
  char orig[10] = {0}, our[10] = {0};
  sprintf(orig, "%.6f", exp(-1.5));
  sprintf(our, "%.6Lf", s21_exp(-1.5));
  ck_assert_str_eq(orig, our);
}
END_TEST

START_TEST(test_10_s21_exp_MAIN_TIMEOUT) {
#line 66
  char orig[20] = {0}, our[20] = {0};
  sprintf(orig, "%.6f", exp(0.000000000001));
  sprintf(our, "%.6Lf", s21_exp(0.000000000001));
  ck_assert_str_eq(orig, our);
}
END_TEST

START_TEST(test_12_s21_exp) {
#line 72
  char orig[512] = {0}, our[512] = {0};
  sprintf(orig, "%.6f", exp(-1004.0000001));
  sprintf(our, "%.6Lf", s21_exp(-1004.0000001));
  ck_assert_str_eq(orig, our);
}
END_TEST
START_TEST(test_01_s21_fabs_s21_NAN) {
#line 80
  char orig[10] = {0}, our[10] = {0};
  sprintf(orig, "%.6f", fabs(s21_NAN));
  sprintf(our, "%.6Lf", s21_fabs(s21_NAN));
  ck_assert_str_eq(orig, our);
}
END_TEST

START_TEST(test_02_s21_fabs_s21_NEGZERO) {
#line 86
  char orig[10] = {0}, our[10] = {0};
  sprintf(orig, "%.6f", fabs(s21_NEG_ZERO));
  sprintf(our, "%.6Lf", s21_fabs(s21_NEG_ZERO));
  ck_assert_str_eq(orig, our);
}
END_TEST

START_TEST(test_03_s21_fabs_ZERO) {
#line 92
  char orig[10] = {0}, our[10] = {0};
  sprintf(orig, "%.6f", fabs(0.0));
  sprintf(our, "%.6Lf", s21_fabs(0.0));
  ck_assert_str_eq(orig, our);
}
END_TEST

START_TEST(test_04_s21_fabs_ONE) {
#line 98
  char orig[10] = {0}, our[10] = {0};
  sprintf(orig, "%.6f", fabs(1.0));
  sprintf(our, "%.6Lf", s21_fabs(1.0));
  ck_assert_str_eq(orig, our);
}
END_TEST

START_TEST(test_05_s21_fabs_TWO) {
#line 104
  char orig[10] = {0}, our[10] = {0};
  sprintf(orig, "%.6f", fabs(2.0));
  sprintf(our, "%.6Lf", s21_fabs(2.0));
  ck_assert_str_eq(orig, our);
}
END_TEST

START_TEST(test_06_s21_fabs_FRACTION) {
#line 110
  char orig[10] = {0}, our[10] = {0};
  sprintf(orig, "%.6f", fabs(1.5));
  sprintf(our, "%.6Lf", s21_fabs(1.5));
  ck_assert_str_eq(orig, our);
}
END_TEST

START_TEST(test_07_s21_fabs_NEG_FRACTION) {
#line 116
  char orig[10] = {0}, our[10] = {0};
  sprintf(orig, "%.6f", fabs(-1.5));
  sprintf(our, "%.6Lf", s21_fabs(-1.5));
  ck_assert_str_eq(orig, our);
}
END_TEST
START_TEST(test_01_s21_fmod_s21_NAN_x) {
#line 123
  char orig[10] = {0}, our[10] = {0};
  sprintf(orig, "%.6f", fmod(s21_NAN, 0.5));
  sprintf(our, "%.6Lf", s21_fmod(s21_NAN, 0.5));
  ck_assert_str_eq(orig, our);
}
END_TEST

START_TEST(test_02_s21_fmod_s21_NAN_y) {
#line 128
  char orig[10] = {0}, our[10] = {0};
  sprintf(orig, "%.6f", fmod(0.5, s21_NAN));
  sprintf(our, "%.6Lf", s21_fmod(0.5, s21_NAN));
  ck_assert_str_eq(orig, our);
}
END_TEST

START_TEST(test_03_s21_fmod_s21_NEGZERO) {
#line 133
  char orig[10] = {0}, our[10] = {0};
  sprintf(orig, "%.6f", fmod(s21_NEG_ZERO, 1.5));
  sprintf(our, "%.6Lf", s21_fmod(s21_NEG_ZERO, 1.5));
  ck_assert_str_eq(orig, our);
}
END_TEST

START_TEST(test_04_s21_fmod_s21_INF) {
#line 138
  char orig[10] = {0}, our[10] = {0};
  sprintf(orig, "%.6f", fmod(s21_INF, -1.5));
  sprintf(our, "%.6Lf", s21_fmod(s21_INF, -1.5));
  ck_assert_str_eq(orig, our);
}
END_TEST

START_TEST(test_05_s21_fmod_ZERO) {
#line 143
  char orig[10] = {0}, our[10] = {0};
  sprintf(orig, "%.6f", fmod(0.0, 2.0));
  sprintf(our, "%.6Lf", s21_fmod(0.0, 2.0));
  ck_assert_str_eq(orig, our);
}
END_TEST

START_TEST(test_06_s21_fmod_ONE) {
#line 148
  char orig[10] = {0}, our[10] = {0};
  sprintf(orig, "%.6f", fmod(1.0, 0.5));
  sprintf(our, "%.6Lf", s21_fmod(1.0, 0.5));
  ck_assert_str_eq(orig, our);
}
END_TEST

START_TEST(test_07_s21_fmod_TWO) {
#line 153
  char orig[10] = {0}, our[10] = {0};
  sprintf(orig, "%.6f", fmod(2.0, 1.5));
  sprintf(our, "%.6Lf", s21_fmod(2.0, 1.5));
  ck_assert_str_eq(orig, our);
}
END_TEST

START_TEST(test_08_s21_fmod_FRACTION) {
#line 158
  char orig[10] = {0}, our[10] = {0};
  sprintf(orig, "%.6f", fmod(1.5, 3.5));
  sprintf(our, "%.6Lf", s21_fmod(1.5, 3.5));
  ck_assert_str_eq(orig, our);
}
END_TEST

START_TEST(test_02_s21_log_s21_NEGZERO) {
#line 176
  char orig[9] = {0}, our[9] = {0};
  sprintf(orig, "%.6f", log(s21_NEG_ZERO));
  sprintf(our, "%.6Lf", s21_log(s21_NEG_ZERO));
  ck_assert_str_eq(orig, our);
}
END_TEST

START_TEST(test_04_s21_log_ONE) {
#line 188
  char orig[10] = {0}, our[10] = {0};
  sprintf(orig, "%.6f", log(1.0));
  sprintf(our, "%.6Lf", s21_log(1.0));
  ck_assert_str_eq(orig, our);
}
END_TEST

START_TEST(test_05_s21_log_TWO) {
#line 194
  char orig[10] = {0}, our[10] = {0};
  sprintf(orig, "%.6f", log(2.0));
  sprintf(our, "%.6Lf", s21_log(2.0));
  ck_assert_str_eq(orig, our);
}
END_TEST

START_TEST(test_06_s21_log_FRACTION) {
#line 200
  char orig[10] = {0}, our[10] = {0};
  sprintf(orig, "%.6f", log(1.5));
  sprintf(our, "%.6Lf", s21_log(1.5));
  ck_assert_str_eq(orig, our);
}
END_TEST

START_TEST(test_07_s21_log_NEG_FRACTION) {
#line 206
  char orig[10] = {0}, our[10] = {0};
  sprintf(orig, "%.6f", log(-1.5));
  sprintf(our, "%.6Lf", s21_log(-1.5));
  ck_assert_str_eq(orig, our);
}
END_TEST

START_TEST(test_08_s21_log_s21_e) {
#line 212
  char orig[10] = {0}, our[10] = {0};
  sprintf(orig, "%.6f", log(s21_e + 1));
  sprintf(our, "%.6Lf", s21_log(s21_e + 1));
  ck_assert_str_eq(orig, our);
}
END_TEST

START_TEST(test_09_s21_log_s21_e_TIMEOUT) {
#line 218
  char orig[10] = {0}, our[10] = {0};
  sprintf(orig, "%.6f", log(9102475.801065));
  sprintf(our, "%.6Lf", s21_log(9102475.801065));
  ck_assert_str_eq(orig, our);
}
END_TEST

START_TEST(test_10_s21_log_s21_e_TIMEOUT) {
#line 224
  char orig[10] = {0}, our[10] = {0};
  sprintf(orig, "%.6f", log(-892796.577370));
  sprintf(our, "%.6Lf", s21_log(-892796.577370));
  ck_assert_str_eq(orig, our);
}
END_TEST
START_TEST(test_01_s21_pow_BASE_ONE) {
#line 231
  char orig[10] = {0}, our[10] = {0};
  sprintf(orig, "%.6f", pow(1, 5));
  sprintf(our, "%.6Lf", s21_pow(1, 5));
  ck_assert_str_eq(orig, our);
}
END_TEST

START_TEST(test_02_s21_pow_s21_INF) {
#line 237
  char orig[10] = {0}, our[10] = {0};
  sprintf(orig, "%.6f", pow(s21_INF, 5));
  sprintf(our, "%.6Lf", s21_pow(s21_INF, 5));
  ck_assert_str_eq(orig, our);
}
END_TEST

START_TEST(test_03_s21_pow_NEG_BASE_FRACTIONED_EXP) {
#line 243
  char orig[10] = {0}, our[10] = {0};
  sprintf(orig, "%.6f", pow(-3, 5.5));
  sprintf(our, "%.6Lf", s21_pow(-3, 5.5));
  ck_assert_str_eq(orig, our);
}
END_TEST

START_TEST(test_04_s21_pow_s21_NAN) {
#line 249
  char orig[10] = {0}, our[10] = {0};
  sprintf(orig, "%.6f", pow(s21_NAN, 5));
  sprintf(our, "%.6Lf", s21_pow(s21_NAN, 5));
  ck_assert_str_eq(orig, our);
}
END_TEST

START_TEST(test_05_s21_pow_BASE_ZERO) {
#line 255
  char orig[10] = {0}, our[10] = {0};
  sprintf(orig, "%.6f", pow(0, 5));
  sprintf(our, "%.6Lf", s21_pow(0, 5));
  ck_assert_str_eq(orig, our);
}
END_TEST

START_TEST(test_06_s21_pow_BASE_NEGZERO_EXP_ODD) {
#line 261
  char orig[10] = {0}, our[10] = {0};
  sprintf(orig, "%.6f", pow(s21_NEG_ZERO, 3));
  sprintf(our, "%.6Lf", s21_pow(s21_NEG_ZERO, 3));
  ck_assert_str_eq(orig, our);
}
END_TEST

START_TEST(test_07_s21_pow_BASE_NEGINF_EXP_POZ_ODD) {
#line 267
  char orig[10] = {0}, our[10] = {0};
  sprintf(orig, "%.6f", pow(-s21_INF, 3));
  sprintf(our, "%.6Lf", s21_pow(-s21_INF, 3));
  ck_assert_str_eq(orig, our);
}
END_TEST

START_TEST(test_08_s21_pow_MAIN_01) {
#line 273
  char orig[20] = {0}, our[20] = {0};
  sprintf(orig, "%.6f", pow(5, 3));
  sprintf(our, "%.6Lf", s21_pow(5, 3));
  ck_assert_str_eq(orig, our);
}
END_TEST

START_TEST(test_09_s21_pow_MAIN_02) {
#line 279
  char orig[20] = {0}, our[20] = {0};
  sprintf(orig, "%.6f", pow(-3, 5));
  sprintf(our, "%.6Lf", s21_pow(-3, 5));
  ck_assert_str_eq(orig, our);
}
END_TEST

START_TEST(test_11_s21_pow_MAIN_TIMEOUT) {
#line 291
  char orig[20] = {0}, our[20] = {0};
  sprintf(orig, "%.6f", pow(-132549216.566863, -132549216.566863));
  sprintf(our, "%.6Lf", s21_pow(-132549216.566863, -132549216.566863));
  ck_assert_str_eq(orig, our);
}
END_TEST
START_TEST(test_01_s21_abs) {
#line 298
  char orig[20] = {0}, our[20] = {0};
  int x = -156746274;
  sprintf(orig, "%d", abs(x));
  sprintf(our, "%d", s21_abs(x));
  ck_assert_str_eq(orig, our);
}
END_TEST

START_TEST(test_02_s21_abs) {
#line 304
  char orig[20] = {0}, our[20] = {0};
  int x = 156746274;
  sprintf(orig, "%d", abs(x));
  sprintf(our, "%d", s21_abs(x));
  ck_assert_str_eq(orig, our);
}
END_TEST

START_TEST(test_03_s21_abs) {
#line 310
  char orig[20] = {0}, our[20] = {0};
  int x = -2147483647;
  sprintf(orig, "%d", abs(x));
  sprintf(our, "%d", s21_abs(x));
  ck_assert_str_eq(orig, our);
}
END_TEST
START_TEST(test_01_s21_ceil) {
#line 318
  char orig[30] = {0}, our[30] = {0};
  double x = 142.315;
  sprintf(orig, "%.15f", ceil(x));
  sprintf(our, "%.15Lf", s21_ceil(x));
  ck_assert_str_eq(orig, our);
}
END_TEST

START_TEST(test_02_s21_ceil) {
#line 324
  char orig[30] = {0}, our[30] = {0};
  double x = 32243;
  sprintf(orig, "%.15f", ceil(x));
  sprintf(our, "%.15Lf", s21_ceil(x));
  ck_assert_str_eq(orig, our);
}
END_TEST

START_TEST(test_03_s21_ceil) {
#line 330
  char orig[30] = {0}, our[30] = {0};
  double x = -21474.24356;
  sprintf(orig, "%.15f", ceil(x));
  sprintf(our, "%.15Lf", s21_ceil(x));
  ck_assert_str_eq(orig, our);
}
END_TEST
START_TEST(test_01_s21_sqrt) {
#line 339
  char orig[100] = {0}, our[100] = {0};
  double x = 144.0;
  sprintf(orig, "%.6f", sqrt(x));
  sprintf(our, "%.6Lf", s21_sqrt(x));
  ck_assert_str_eq(orig, our);
  ck_assert_double_eq_tol(sqrt(144.0), s21_sqrt(144.0), 0.0000001);
}
END_TEST

START_TEST(test_02_s21_sqrt) {
#line 346
  char orig[1000] = {0}, our[1000] = {0};
  double x = 3243;
  sprintf(orig, "%.6f", sqrt(x));
  sprintf(our, "%.6Lf", s21_sqrt(x));
  ck_assert_str_eq(orig, our);
}
END_TEST

START_TEST(test_03_s21_sqrt) {
#line 352
  char orig[100] = {0}, our[100] = {0};
  double x = -21474.24356;
  sprintf(orig, "%.6f", sqrt(x));
  sprintf(our, "%.6Lf", s21_sqrt(x));
  ck_assert_str_eq(orig, our);
}
END_TEST

START_TEST(test_01_s21_floor) {
#line 365
  char orig[30] = {0}, our[30] = {0};
  double x = 142.315;
  sprintf(orig, "%.6f", floor(x));
  sprintf(our, "%.6Lf", s21_floor(x));
  ck_assert_str_eq(orig, our);
}
END_TEST

START_TEST(test_02_s21_floor) {
#line 371
  char orig[30] = {0}, our[30] = {0};
  double x = 32243;
  sprintf(orig, "%.6f", floor(x));
  sprintf(our, "%.6Lf", s21_floor(x));
  ck_assert_str_eq(orig, our);
}
END_TEST

START_TEST(test_03_s21_floor) {
#line 377
  char orig[30] = {0}, our[30] = {0};
  double x = -21474.24356;
  sprintf(orig, "%.6f", floor(x));
  sprintf(our, "%.6Lf", s21_floor(x));
  ck_assert_str_eq(orig, our);
}
END_TEST

START_TEST(test_04_s21_floor_s21_NAN) {
#line 383
  char orig[100] = {0}, our[100] = {0};
  sprintf(orig, "%.6f", floor(s21_NAN));
  sprintf(our, "%.6Lf", s21_floor(s21_NAN));
  ck_assert_str_eq(orig, our);
}
END_TEST

START_TEST(test_05_s21_floor_ZERO) {
#line 388
  char orig[100] = {0}, our[100] = {0};
  sprintf(orig, "%.6f", floor(0));
  sprintf(our, "%.6Lf", s21_floor(0));
  ck_assert_str_eq(orig, our);
}
END_TEST

START_TEST(test_06_s21_floor_s21_INF) {
#line 393
  char orig[100] = {0}, our[100] = {0};
  sprintf(orig, "%.6f", floor(s21_INF));
  sprintf(our, "%.6Lf", s21_floor(s21_INF));
  ck_assert_str_eq(orig, our);
}
END_TEST
START_TEST(test_01_s21_tan) {
#line 400
  char orig[100] = {0}, our[100] = {0};
  double x = 142.315;
  sprintf(orig, "%.9f", tan(x));
  sprintf(our, "%.9Lf", s21_tan(x));
  ck_assert_str_eq(orig, our);
}
END_TEST

START_TEST(test_02_s21_tan) {
#line 406
  char orig[1000] = {0}, our[1000] = {0};
  double x = 3243;
  sprintf(orig, "%.9f", tan(x));
  sprintf(our, "%.9Lf", s21_tan(x));
  ck_assert_str_eq(orig, our);
}
END_TEST

START_TEST(test_03_s21_tan) {
#line 412
  char orig[100] = {0}, our[100] = {0};
  double x = -21474.24356;
  sprintf(orig, "%.6f", tan(x));
  sprintf(our, "%.6Lf", s21_tan(x));
  ck_assert_str_eq(orig, our);
}
END_TEST

START_TEST(test_10_s21_tan_TIMEOUT) {
#line 418
  char orig[100] = {0}, our[100] = {0};
  double x = 0.0000000001;
  sprintf(orig, "%.6f", tan(x));
  sprintf(our, "%.6Lf", s21_tan(x));
  ck_assert_str_eq(orig, our);
}
END_TEST

START_TEST(test_11_s21_tan_TIMEOUT) {
#line 424
  char orig[100] = {0}, our[100] = {0};
  double x = 430824.234405370;
  sprintf(orig, "%.7f", tan(x));
  sprintf(our, "%.7Lf", s21_tan(x));
  ck_assert_str_eq(orig, our);
}
END_TEST
START_TEST(test_01_s21_sin) {
#line 432
  char orig[100] = {0}, our[100] = {0};
  double x = 142.315;
  sprintf(orig, "%.9f", sin(x));
  sprintf(our, "%.9Lf", s21_sin(x));
  ck_assert_str_eq(orig, our);
}
END_TEST

START_TEST(test_02_s21_sin) {
#line 438
  char orig[1000] = {0}, our[1000] = {0};
  double x = 3243;
  sprintf(orig, "%.9f", sin(x));
  sprintf(our, "%.9Lf", s21_sin(x));
  ck_assert_str_eq(orig, our);
}
END_TEST

START_TEST(test_03_s21_sin) {
#line 444
  char orig[100] = {0}, our[100] = {0};
  double x = -21474.24356;
  sprintf(orig, "%.9f", sin(x));
  sprintf(our, "%.9Lf", s21_sin(x));
  ck_assert_str_eq(orig, our);
}
END_TEST

START_TEST(test_04_s21_sin_s21_NAN) {
#line 450
  char orig[100] = {0}, our[100] = {0};
  sprintf(orig, "%.6f", sin(s21_NAN));
  sprintf(our, "%.6Lf", s21_sin(s21_NAN));
  ck_assert_str_eq(orig, our);
}
END_TEST

START_TEST(test_10_s21_sin_TIMEOUT) {
#line 455
  char orig[100] = {0}, our[100] = {0};
  double x = 430824.234405370;
  sprintf(orig, "%.7f", sin(x));
  sprintf(our, "%.7Lf", s21_sin(x));
  ck_assert_str_eq(orig, our);
}
END_TEST
START_TEST(test_01_s21_cos) {
#line 464
  char orig[100] = {0}, our[100] = {0};
  double x = 142.315;
  sprintf(orig, "%.9f", cos(x));
  sprintf(our, "%.9Lf", s21_cos(x));
  ck_assert_str_eq(orig, our);
}
END_TEST

START_TEST(test_02_s21_cos) {
#line 470
  char orig[1000] = {0}, our[1000] = {0};
  double x = 3243;
  sprintf(orig, "%.9f", cos(x));
  sprintf(our, "%.9Lf", s21_cos(x));
  ck_assert_str_eq(orig, our);
}
END_TEST

START_TEST(test_03_s21_cos) {
#line 476
  char orig[100] = {0}, our[100] = {0};
  double x = -21474.24356;
  sprintf(orig, "%.6f", cos(x));
  sprintf(our, "%.6Lf", s21_cos(x));
  ck_assert_str_eq(orig, our);
}
END_TEST

START_TEST(test_04_s21_cos_s21_NAN) {
#line 482
  char orig[100] = {0}, our[100] = {0};
  sprintf(orig, "%.6f", cos(s21_NAN));
  sprintf(our, "%.6Lf", s21_cos(s21_NAN));
  ck_assert_str_eq(orig, our);
}
END_TEST

START_TEST(test_05_s21_cos_ZERO) {
#line 487
  char orig[100] = {0}, our[100] = {0};
  sprintf(orig, "%.6f", cos(1));
  sprintf(our, "%.6Lf", s21_cos(1));
  ck_assert_str_eq(orig, our);
}
END_TEST

START_TEST(test_06_s21_cos_s21_PI) {
#line 492
  char orig[100] = {0}, our[100] = {0};
  sprintf(orig, "%.6f", cos(-PI / 2));
  sprintf(our, "%.6Lf", s21_cos(-PI / 2));
  ck_assert_str_eq(orig, our);
}
END_TEST

START_TEST(test_10_s21_cos_TIMEOUT) {
#line 497
  char orig[100] = {0}, our[100] = {0};
  double x = 0.0000000001;
  sprintf(orig, "%.9f", cos(x));
  sprintf(our, "%.9Lf", s21_cos(x));
  ck_assert_str_eq(orig, our);
}
END_TEST
START_TEST(test_01_s21_atan) {
#line 505
  char orig[30] = {0}, our[30] = {0};
  double x = 142.315;
  sprintf(orig, "%.6f", atan(x));
  sprintf(our, "%.6Lf", s21_atan(x));
  ck_assert_str_eq(orig, our);
}
END_TEST

START_TEST(test_02_s21_atan) {
#line 511
  char orig[30] = {0}, our[30] = {0};
  double x = 32243;
  sprintf(orig, "%.6f", atan(x));
  sprintf(our, "%.6Lf", s21_atan(x));
  ck_assert_str_eq(orig, our);
}
END_TEST

START_TEST(test_03_s21_atan) {
#line 517
  char orig[30] = {0}, our[30] = {0};
  double x = -21474.24356;
  sprintf(orig, "%.6f", atan(x));
  sprintf(our, "%.6Lf", s21_atan(x));
  ck_assert_str_eq(orig, our);
}
END_TEST

START_TEST(test_04_s21_atan) {
#line 523
  char orig[30] = {0}, our[30] = {0};
  double x = -1;
  sprintf(orig, "%.6f", atan(x));
  sprintf(our, "%.6Lf", s21_atan(x));
  ck_assert_str_eq(orig, our);
}
END_TEST

START_TEST(test_05_s21_atan) {
#line 529
  char orig[30] = {0}, our[30] = {0};
  double x = 1;
  sprintf(orig, "%.6f", atan(x));
  sprintf(our, "%.6Lf", s21_atan(x));
  ck_assert_str_eq(orig, our);
}
END_TEST
START_TEST(test_01_s21_asin) {
#line 537
  char orig[30] = {0}, our[30] = {0};
  double x = 142.315;
  sprintf(orig, "%.15f", asin(x));
  sprintf(our, "%.15Lf", s21_asin(x));
  ck_assert_str_eq(orig, our);
}
END_TEST

START_TEST(test_02_s21_asin) {
#line 544
  char orig[30] = {0}, our[30] = {0};
  double x = 32243;
  sprintf(orig, "%.15f", asin(x));
  sprintf(our, "%.15Lf", s21_asin(x));
  ck_assert_str_eq(orig, our);
}
END_TEST

START_TEST(test_03_s21_asin) {
#line 551
  char orig[30] = {0}, our[30] = {0};
  double x = -21474.24356;
  sprintf(orig, "%.15f", asin(x));
  sprintf(our, "%.15Lf", s21_asin(x));
  ck_assert_str_eq(orig, our);
}
END_TEST

START_TEST(test_04_s21_asin) {
#line 558
  char orig[30] = {0}, our[30] = {0};
  double x = 0.426;
  sprintf(orig, "%.15f", asin(x));
  sprintf(our, "%.15Lf", s21_asin(x));
  ck_assert_str_eq(orig, our);
}
END_TEST

START_TEST(test_05_s21_asin) {
#line 565
  char orig[30] = {0}, our[30] = {0};
  double x = -1;
  sprintf(orig, "%.15f", asin(x));
  sprintf(our, "%.15Lf", s21_asin(x));
  ck_assert_str_eq(orig, our);
}
END_TEST

START_TEST(test_06_s21_asin) {
#line 572
  char orig[30] = {0}, our[30] = {0};
  double x = 1;
  sprintf(orig, "%.15f", asin(x));
  sprintf(our, "%.15Lf", s21_asin(x));
  ck_assert_str_eq(orig, our);
}
END_TEST
START_TEST(test_01_s21_acos) {
#line 580
  char orig[30] = {0}, our[30] = {0};
  double x = 142.315;
  sprintf(orig, "%.9f", acos(x));
  sprintf(our, "%.9Lf", s21_acos(x));
  ck_assert_str_eq(orig, our);
}
END_TEST

START_TEST(test_02_s21_acos) {
#line 586
  char orig[30] = {0}, our[30] = {0};
  double x = 32243;
  sprintf(orig, "%.9f", acos(x));
  sprintf(our, "%.9Lf", s21_acos(x));
  ck_assert_str_eq(orig, our);
}
END_TEST

START_TEST(test_03_s21_acos) {
#line 592
  char orig[30] = {0}, our[30] = {0};
  double x = -21474.24356;
  sprintf(orig, "%.9f", acos(x));
  sprintf(our, "%.9Lf", s21_acos(x));
  ck_assert_str_eq(orig, our);
}
END_TEST

START_TEST(test_04_s21_acos) {
#line 598
  char orig[30] = {0}, our[30] = {0};
  double x = 0.426;
  sprintf(orig, "%.9f", acos(x));
  sprintf(our, "%.9Lf", s21_acos(x));
  ck_assert_str_eq(orig, our);
}
END_TEST

START_TEST(test_05_s21_acos) {
#line 604
  char orig[30] = {0}, our[30] = {0};
  double x = -1;
  sprintf(orig, "%.9f", acos(x));
  sprintf(our, "%.9Lf", s21_acos(x));
  ck_assert_str_eq(orig, our);
}
END_TEST

START_TEST(test_06_s21_acos) {
#line 610
  char orig[30] = {0}, our[30] = {0};
  double x = 1;
  sprintf(orig, "%.9f", acos(x));
  sprintf(our, "%.9Lf", s21_acos(x));
  ck_assert_str_eq(orig, our);
}
END_TEST


Suite* s21_math_nyar(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("s21_math_exp");
  TCase *tc1_2 = tcase_create("s21_math_fabs");
  TCase *tc1_3 = tcase_create("s21_math_fmod");
  TCase *tc1_4 = tcase_create("s21_math_log");
  TCase *tc1_5 = tcase_create("s21_math_pow");
  TCase *tc1_6 = tcase_create("s21_math_abs");
  TCase *tc1_7 = tcase_create("s21_math_ceil");
  TCase *tc1_8 = tcase_create("s21_math_sqrt");
  TCase *tc1_9 = tcase_create("s21_math_floor");
  TCase *tc1_10 = tcase_create("s21_math_tan");
  TCase *tc1_11 = tcase_create("s21_math_sin");
  TCase *tc1_12 = tcase_create("s21_math_cos");
  TCase *tc1_13 = tcase_create("s21_math_atan");
  TCase *tc1_14 = tcase_create("s21_math_asin");
  TCase *tc1_15 = tcase_create("s21_math_acos");
  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, test_01_s21_exp_s21_NAN);
  tcase_add_test(tc1_1, test_02_s21_exp_s21_INF);
  tcase_add_test(tc1_1, test_03_s21_exp_NEG_s21_INF);
  tcase_add_test(tc1_1, test_04_s21_exp_ZERO);
  tcase_add_test(tc1_1, test_05_s21_exp_ONE);
  tcase_add_test(tc1_1, test_06_s21_exp_TWO);
  tcase_add_test(tc1_1, test_07_s21_exp_FRACTION);
  tcase_add_test(tc1_1, test_08_s21_exp_NEG_FRACTION);
  tcase_add_test(tc1_1, test_10_s21_exp_MAIN_TIMEOUT);
  tcase_add_test(tc1_1, test_12_s21_exp);
  suite_add_tcase(s1, tc1_2);
  tcase_add_test(tc1_2, test_01_s21_fabs_s21_NAN);
  tcase_add_test(tc1_2, test_02_s21_fabs_s21_NEGZERO);
  tcase_add_test(tc1_2, test_03_s21_fabs_ZERO);
  tcase_add_test(tc1_2, test_04_s21_fabs_ONE);
  tcase_add_test(tc1_2, test_05_s21_fabs_TWO);
  tcase_add_test(tc1_2, test_06_s21_fabs_FRACTION);
  tcase_add_test(tc1_2, test_07_s21_fabs_NEG_FRACTION);
  suite_add_tcase(s1, tc1_3);
  tcase_add_test(tc1_3, test_01_s21_fmod_s21_NAN_x);
  tcase_add_test(tc1_3, test_02_s21_fmod_s21_NAN_y);
  tcase_add_test(tc1_3, test_03_s21_fmod_s21_NEGZERO);
  tcase_add_test(tc1_3, test_04_s21_fmod_s21_INF);
  tcase_add_test(tc1_3, test_05_s21_fmod_ZERO);
  tcase_add_test(tc1_3, test_06_s21_fmod_ONE);
  tcase_add_test(tc1_3, test_07_s21_fmod_TWO);
  tcase_add_test(tc1_3, test_08_s21_fmod_FRACTION);
  suite_add_tcase(s1, tc1_4);
  tcase_add_test(tc1_4, test_02_s21_log_s21_NEGZERO);
  tcase_add_test(tc1_4, test_04_s21_log_ONE);
  tcase_add_test(tc1_4, test_05_s21_log_TWO);
  tcase_add_test(tc1_4, test_06_s21_log_FRACTION);
  tcase_add_test(tc1_4, test_07_s21_log_NEG_FRACTION);
  tcase_add_test(tc1_4, test_08_s21_log_s21_e);
  tcase_add_test(tc1_4, test_09_s21_log_s21_e_TIMEOUT);
  tcase_add_test(tc1_4, test_10_s21_log_s21_e_TIMEOUT);
  suite_add_tcase(s1, tc1_5);
  tcase_add_test(tc1_5, test_01_s21_pow_BASE_ONE);
  tcase_add_test(tc1_5, test_02_s21_pow_s21_INF);
  tcase_add_test(tc1_5, test_03_s21_pow_NEG_BASE_FRACTIONED_EXP);
  tcase_add_test(tc1_5, test_04_s21_pow_s21_NAN);
  tcase_add_test(tc1_5, test_05_s21_pow_BASE_ZERO);
  tcase_add_test(tc1_5, test_06_s21_pow_BASE_NEGZERO_EXP_ODD);
  tcase_add_test(tc1_5, test_07_s21_pow_BASE_NEGINF_EXP_POZ_ODD);
  tcase_add_test(tc1_5, test_08_s21_pow_MAIN_01);
  tcase_add_test(tc1_5, test_09_s21_pow_MAIN_02);
  tcase_add_test(tc1_5, test_11_s21_pow_MAIN_TIMEOUT);
  suite_add_tcase(s1, tc1_6);
  tcase_add_test(tc1_6, test_01_s21_abs);
  tcase_add_test(tc1_6, test_02_s21_abs);
  tcase_add_test(tc1_6, test_03_s21_abs);
  suite_add_tcase(s1, tc1_7);
  tcase_add_test(tc1_7, test_01_s21_ceil);
  tcase_add_test(tc1_7, test_02_s21_ceil);
  tcase_add_test(tc1_7, test_03_s21_ceil);
  suite_add_tcase(s1, tc1_8);
  tcase_add_test(tc1_8, test_01_s21_sqrt);
  tcase_add_test(tc1_8, test_02_s21_sqrt);
  tcase_add_test(tc1_8, test_03_s21_sqrt);
  suite_add_tcase(s1, tc1_9);
  tcase_add_test(tc1_9, test_01_s21_floor);
  tcase_add_test(tc1_9, test_02_s21_floor);
  tcase_add_test(tc1_9, test_03_s21_floor);
  tcase_add_test(tc1_9, test_04_s21_floor_s21_NAN);
  tcase_add_test(tc1_9, test_05_s21_floor_ZERO);
  tcase_add_test(tc1_9, test_06_s21_floor_s21_INF);
  suite_add_tcase(s1, tc1_10);
  tcase_add_test(tc1_10, test_01_s21_tan);
  tcase_add_test(tc1_10, test_02_s21_tan);
  tcase_add_test(tc1_10, test_03_s21_tan);
  tcase_add_test(tc1_10, test_10_s21_tan_TIMEOUT);
  tcase_add_test(tc1_10, test_11_s21_tan_TIMEOUT);
  suite_add_tcase(s1, tc1_11);
  tcase_add_test(tc1_11, test_01_s21_sin);
  tcase_add_test(tc1_11, test_02_s21_sin);
  tcase_add_test(tc1_11, test_03_s21_sin);
  tcase_add_test(tc1_11, test_04_s21_sin_s21_NAN);
  tcase_add_test(tc1_11, test_10_s21_sin_TIMEOUT);
  suite_add_tcase(s1, tc1_12);
  tcase_add_test(tc1_12, test_01_s21_cos);
  tcase_add_test(tc1_12, test_02_s21_cos);
  tcase_add_test(tc1_12, test_03_s21_cos);
  tcase_add_test(tc1_12, test_04_s21_cos_s21_NAN);
  tcase_add_test(tc1_12, test_05_s21_cos_ZERO);
  tcase_add_test(tc1_12, test_06_s21_cos_s21_PI);
  tcase_add_test(tc1_12, test_10_s21_cos_TIMEOUT);
  suite_add_tcase(s1, tc1_13);
  tcase_add_test(tc1_13, test_01_s21_atan);
  tcase_add_test(tc1_13, test_02_s21_atan);
  tcase_add_test(tc1_13, test_03_s21_atan);
  tcase_add_test(tc1_13, test_04_s21_atan);
  tcase_add_test(tc1_13, test_05_s21_atan);
  suite_add_tcase(s1, tc1_14);
  tcase_add_test(tc1_14, test_01_s21_asin);
  tcase_add_test(tc1_14, test_02_s21_asin);
  tcase_add_test(tc1_14, test_03_s21_asin);
  tcase_add_test(tc1_14, test_04_s21_asin);
  tcase_add_test(tc1_14, test_05_s21_asin);
  tcase_add_test(tc1_14, test_06_s21_asin);
  suite_add_tcase(s1, tc1_15);
  tcase_add_test(tc1_15, test_01_s21_acos);
  tcase_add_test(tc1_15, test_02_s21_acos);
  tcase_add_test(tc1_15, test_03_s21_acos);
  tcase_add_test(tc1_15, test_04_s21_acos);
  tcase_add_test(tc1_15, test_05_s21_acos);
  tcase_add_test(tc1_15, test_06_s21_acos);
  return  s1;
}