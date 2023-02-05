#include "test.h"



START_TEST(sin_test) {  // done
  ck_assert_ldouble_nan(s21_sin(s21_INF));
  ck_assert_ldouble_nan(s21_sin(s21_NEG_INF));
  ck_assert_ldouble_nan(s21_sin(s21_NAN));
  ck_assert_ldouble_nan(s21_sin(s21_NEG_INF));
  ck_assert_ldouble_eq_tol(s21_sin(0.5), sin(0.5), 1e-15);
  ck_assert_ldouble_eq_tol(s21_sin(-0.5), sin(-0.5), 1e-15);
  ck_assert_ldouble_eq_tol(s21_sin(-1), sin(-1), 1e-15);
  ck_assert_ldouble_eq_tol(s21_sin(1), sin(1), 1e-15);
  ck_assert_ldouble_eq_tol(s21_sin(1.1), sin(1.1), 1e-15);
  ck_assert_ldouble_eq_tol(s21_sin(-2.1), sin(-2.1), 1e-15);
  ck_assert_ldouble_eq_tol(s21_sin(0), sin(0), 1e-15);
  ck_assert_ldouble_eq_tol(s21_sin(-0), sin(-0), 1e-15);
  ck_assert_ldouble_eq_tol(round(s21_sin(5.1234567) * SIX) / SIX,
                           round(sin(5.1234567) * SIX) / SIX, 1e-15);
  ck_assert_ldouble_eq_tol(round(s21_sin(0.00000004564897) * SIX) / SIX,
                           round(sin(0.00000004564897) * SIX) / SIX, 1e-15);
}
END_TEST

START_TEST(cos_test) {  // done
  ck_assert_ldouble_nan(s21_cos(s21_INF));
  ck_assert_ldouble_nan(s21_cos(s21_NEG_INF));
  ck_assert_ldouble_nan(s21_cos(s21_NAN));
  ck_assert_ldouble_nan(s21_cos(s21_NAN));
  ck_assert_ldouble_eq_tol(s21_cos(0.5), cos(0.5), 1e-15);
  ck_assert_ldouble_eq_tol(s21_cos(-0.5), cos(-0.5), 1e-15);
  ck_assert_ldouble_eq_tol(s21_cos(-1), cos(-1), 1e-15);
  ck_assert_ldouble_eq_tol(s21_cos(1), cos(1), 1e-15);
  ck_assert_ldouble_eq_tol(s21_cos(1.1), cos(1.1), 1e-15);
  ck_assert_ldouble_eq_tol(s21_cos(-2.1), cos(-2.1), 1e-15);
  ck_assert_ldouble_eq_tol(s21_cos(0), cos(0), 1e-15);
  ck_assert_ldouble_eq_tol(s21_cos(-0), cos(-0), 1e-15);
  ck_assert_ldouble_eq_tol(round(s21_cos(5.123456789123) * SIX) / SIX,
                           round(cos(5.123456789123) * SIX) / SIX, 1e-15);
  ck_assert_ldouble_eq_tol(round(s21_cos(0.00000004564897) * SIX) / SIX,
                           round(cos(0.00000004564897) * SIX) / SIX, 1e-15);
}
END_TEST

START_TEST(tan_test) {  // done
  ck_assert_ldouble_nan(s21_cos(s21_INF));
  ck_assert_ldouble_nan(s21_cos(s21_NEG_INF));
  ck_assert_ldouble_nan(s21_cos(s21_NAN));
  ck_assert_ldouble_nan(s21_cos(s21_NAN));
  ck_assert_ldouble_eq_tol(s21_tan(0.5), tan(0.5), 1e-15);
  ck_assert_ldouble_eq_tol(s21_tan(-0.5), tan(-0.5), 1e-15);
  ck_assert_ldouble_eq_tol(s21_tan(-1), tan(-1), 1e-15);
  ck_assert_ldouble_eq_tol(s21_tan(1), tan(1), 1e-15);
  ck_assert_ldouble_eq_tol(s21_tan(1.1), tan(1.1), 1e-15);
  ck_assert_ldouble_eq_tol(s21_tan(-2.1), tan(-2.1), 1e-8);
  ck_assert_ldouble_eq_tol(s21_tan(0), tan(0), 1e-15);
  ck_assert_ldouble_eq_tol(s21_tan(-0), tan(-0), 1e-15);
  ck_assert_ldouble_eq_tol(round(s21_tan(5.123456789123) * SIX) / SIX,
                           round(tan(5.123456789123) * SIX) / SIX, 1e-15);
  ck_assert_ldouble_eq_tol(round(s21_tan(0.00000004564897) * SIX) / SIX,
                           round(tan(0.00000004564897) * SIX) / SIX, 1e-15);
}
END_TEST

START_TEST(asin_test) {  // done
  ck_assert_ldouble_nan(s21_asin(s21_INF));
  ck_assert_ldouble_nan(s21_asin(s21_NEG_INF));
  ck_assert_ldouble_nan(s21_asin(s21_NAN));
  ck_assert_ldouble_nan(s21_asin(s21_NAN));
  ck_assert_ldouble_eq_tol(s21_asin(0.5), asin(0.5), 1e-8);
  ck_assert_ldouble_eq_tol(s21_asin(-0.5), asin(-0.5), 1e-8);
  ck_assert_ldouble_eq_tol(s21_asin(-1), asin(-1), 1e-15);
  ck_assert_ldouble_eq_tol(s21_asin(1), asin(1), 1e-15);
  ck_assert_ldouble_nan(s21_asin(1.1));
  ck_assert_ldouble_eq_tol(s21_asin(0), asin(0), 1e-15);
  ck_assert_ldouble_eq_tol(s21_asin(-0), asin(-0), 1e-15);
  ck_assert_ldouble_eq_tol(s21_asin(0.00000004564897), asin(0.00000004564897),
                           1e-15);
}
END_TEST

START_TEST(acos_test) {  // done
  ck_assert_ldouble_nan(s21_acos(s21_INF));
  ck_assert_ldouble_nan(s21_acos(s21_NEG_INF));
  ck_assert_ldouble_nan(s21_acos(s21_NAN));
  ck_assert_ldouble_nan(s21_acos(s21_NAN));
  ck_assert_ldouble_eq_tol(s21_acos(0.5), acos(0.5), 1e-8);
  ck_assert_ldouble_eq_tol(s21_acos(-0.5), acos(-0.5), 1e-8);
  ck_assert_ldouble_eq_tol(round(s21_acos(-1) * SIX) / SIX,
                           round(acos(-1) * SIX) / SIX, 1e-15);
  ck_assert_ldouble_eq_tol(s21_acos(1), acos(1), 1e-15);
  ck_assert_ldouble_nan(s21_acos(1.1));
  ck_assert_ldouble_eq_tol(round(s21_acos(0) * SIX) / SIX,
                           round(acos(0) * SIX) / SIX, 1e-15);
  ck_assert_ldouble_eq_tol(round(s21_acos(-0) * SIX) / SIX,
                           round(acos(-0) * SIX) / SIX, 1e-15);
  ck_assert_ldouble_eq_tol(s21_acos(0.00000004564897), acos(0.00000004564897),
                           1e-15);
}
END_TEST

START_TEST(atan_test) {  // done
  ck_assert_ldouble_nan(s21_atan(s21_NAN));
  ck_assert_ldouble_nan(s21_atan(s21_NAN));
  ck_assert_ldouble_eq_tol(s21_atan(s21_NEG_INF), atan(s21_NEG_INF), 1e-8);
  ck_assert_ldouble_eq_tol(s21_atan(s21_INF), atan(s21_INF), 1e-8);
  ck_assert_ldouble_eq_tol(s21_atan(0.5), atan(0.5), 1e-8);
  ck_assert_ldouble_eq_tol(s21_atan(-0.5), atan(-0.5), 1e-8);
  ck_assert_ldouble_eq_tol(s21_atan(-1), atan(-1), 1e-8);
  ck_assert_ldouble_eq_tol(s21_atan(1), atan(1), 1e-8);
  ck_assert_ldouble_eq_tol(s21_atan(1.1), atan(1.1), 1e-8);
  ck_assert_ldouble_eq_tol(s21_atan(-2.1), atan(-2.1), 1e-8);
  ck_assert_ldouble_eq_tol(s21_atan(0), atan(0), 1e-15);
  ck_assert_ldouble_eq_tol(s21_atan(-0), atan(-0), 1e-15);
  ck_assert_ldouble_eq_tol(round(s21_atan(5.123456789123) * SIX) / SIX,
                           round(atan(5.123456789123) * SIX) / SIX, 1e-15);
  ck_assert_ldouble_eq_tol(round(s21_atan(0.00000004564897) * SIX) / SIX,
                           round(atan(0.00000004564897) * SIX) / SIX, 1e-15);
  ck_assert_ldouble_eq_tol(round(s21_atan(170000000000000.1) * SIX) / SIX,
                           round(atan(170000000000000.1) * SIX) / SIX, 1e-15);
}
END_TEST

START_TEST(exp_test) {  // done
  ck_assert_ldouble_infinite(s21_exp(s21_INF));
  ck_assert_ldouble_eq_tol(s21_exp(s21_NEG_INF), exp(s21_NEG_INF), 1e-8);
  ck_assert_ldouble_nan(s21_exp(s21_NAN));
  ck_assert_ldouble_nan(s21_exp(s21_NAN));
  ck_assert_ldouble_eq_tol(round(s21_exp(0.5) * SIX) / SIX,
                           round(exp(0.5) * SIX) / SIX, 1e-15);
  ck_assert_ldouble_eq_tol(round(s21_exp(-0.5) * SIX) / SIX,
                           round(exp(-0.5) * SIX) / SIX, 1e-15);
  ck_assert_ldouble_eq_tol(round(s21_exp(-1) * SIX) / SIX,
                           round(exp(-1) * SIX) / SIX, 1e-15);
  ck_assert_ldouble_eq_tol(round(s21_exp(1) * SIX) / SIX,
                           round(exp(1) * SIX) / SIX, 1e-15);
  ck_assert_ldouble_eq_tol(round(s21_exp(1.1) * SIX) / SIX,
                           round(exp(1.1) * SIX) / SIX, 1e-15);
  ck_assert_ldouble_eq_tol(round(s21_exp(-2.1) * SIX) / SIX,
                           round(exp(-2.1) * SIX) / SIX, 1e-15);
  ck_assert_ldouble_eq_tol(s21_exp(0), exp(0), 1e-15);
  ck_assert_ldouble_eq_tol(s21_exp(-0), exp(-0), 1e-15);
  ck_assert_ldouble_eq_tol(s21_exp(5.123456789123), exp(5.123456789123), 1e-8);
  ck_assert_ldouble_eq_tol(s21_exp(0.00000004564897), exp(0.00000004564897),
                           1e-15);
  ck_assert_ldouble_eq_tol(s21_exp(20.1), exp(20.1), 1e-8);
  ck_assert_ldouble_eq_tol(s21_exp(-20.1), exp(-20.1), 1e-8);
}
END_TEST

START_TEST(log_test) {  // done
  ck_assert_ldouble_infinite(s21_log(s21_INF));
  ck_assert_ldouble_nan(s21_log(s21_NEG_INF));
  ck_assert_ldouble_nan(s21_log(s21_NAN));
  ck_assert_ldouble_nan(s21_log(s21_NAN));
  ck_assert_ldouble_eq_tol(round(s21_log(0.5) * SIX) / SIX,
                           round(log(0.5) * SIX) / SIX, 1e-15);
  ck_assert_ldouble_nan(s21_log(-0.5));
  ck_assert_ldouble_eq_tol(s21_log(1), log(1), 1e-15);
  ck_assert_ldouble_eq_tol(round(s21_log(1.1) * SIX) / SIX,
                           round(log(1.1) * SIX) / SIX, 1e-15);
  ck_assert_ldouble_infinite(s21_log(0));
  ck_assert_ldouble_infinite(s21_log(-0));
  ck_assert_ldouble_eq_tol(round(s21_log(5.123456789123) * SIX) / SIX,
                           round(log(5.123456789123) * SIX) / SIX, 1e-15);
  ck_assert_ldouble_eq_tol(round(s21_log(0.00000004564897) * SIX) / SIX,
                           round(log(0.00000004564897) * SIX) / SIX, 1e-15);
  ck_assert_ldouble_eq_tol(round(s21_log(170000000000000.1) * SIX) / SIX,
                           round(log(170000000000000.1) * SIX) / SIX, 1e-8);
}
END_TEST

START_TEST(sqrt_test) {  // done
  ck_assert_ldouble_nan(s21_sqrt(s21_NEG_INF));
  ck_assert_ldouble_infinite(s21_sqrt(s21_INF));
  ck_assert_ldouble_nan(s21_sqrt(s21_NAN));
  ck_assert_ldouble_nan(s21_sqrt(s21_NAN));
  ck_assert_ldouble_eq_tol(round(s21_sqrt(0.5) * SIX) / SIX,
                           round(sqrt(0.5) * SIX) / SIX, 1e-15);
  ck_assert_ldouble_nan(s21_sqrt(-0.5));
  ck_assert_ldouble_eq_tol(s21_sqrt(1), sqrt(1), 1e-15);
  ck_assert_ldouble_eq_tol(round(s21_sqrt(1.1) * SIX) / SIX,
                           round(sqrt(1.1) * SIX) / SIX, 1e-15);
  ck_assert_ldouble_eq_tol(s21_sqrt(0), sqrt(0), 1e-15);
  ck_assert_ldouble_eq_tol(s21_sqrt(-0), sqrt(-0), 1e-15);
  ck_assert_ldouble_eq_tol(round(s21_sqrt(5.123456789123) * SIX) / SIX,
                           round(sqrt(5.123456789123) * SIX) / SIX, 1e-15);
  ck_assert_ldouble_eq_tol(round(s21_sqrt(0.00000004564897) * SIX) / SIX,
                           round(sqrt(0.00000004564897) * SIX) / SIX, 1e-15);
}
END_TEST

START_TEST(pow_test) {  // done
  ck_assert_ldouble_eq(s21_pow(s21_INF, s21_INF),
                       pow(s21_INF, s21_INF));
  ck_assert_ldouble_eq_tol(s21_pow(s21_INF, s21_NEG_INF),
                           pow(s21_INF, s21_NEG_INF), 1e-8);
  ck_assert_ldouble_nan(s21_pow(s21_INF, s21_NAN));
  ck_assert_ldouble_nan(s21_pow(s21_INF, s21_NAN));

  ck_assert_ldouble_eq(s21_pow(s21_NEG_INF, s21_INF),
                       pow(s21_NEG_INF, s21_INF));
  ck_assert_ldouble_eq_tol(s21_pow(s21_NEG_INF, s21_NEG_INF),
                           pow(s21_NEG_INF, s21_NEG_INF), 1e-8);
  ck_assert_ldouble_nan(s21_pow(s21_NEG_INF, s21_NAN));
  ck_assert_ldouble_nan(s21_pow(s21_NEG_INF, s21_NAN));

  ck_assert_ldouble_nan(s21_pow(s21_NAN, s21_INF));
  ck_assert_ldouble_nan(s21_pow(s21_NAN, s21_NEG_INF));
  ck_assert_ldouble_nan(s21_pow(s21_NAN, s21_NAN));
  ck_assert_ldouble_nan(s21_pow(s21_NAN, s21_NAN));

  ck_assert_ldouble_nan(s21_pow(s21_NAN, s21_INF));
  ck_assert_ldouble_nan(s21_pow(s21_NAN, s21_NEG_INF));
  ck_assert_ldouble_nan(s21_pow(s21_NAN, s21_NAN));
  ck_assert_ldouble_nan(s21_pow(s21_NAN, s21_NAN));

  ck_assert_ldouble_infinite(s21_pow(s21_INF, 2.4));
  ck_assert_ldouble_infinite(s21_pow(s21_NEG_INF, 2.4));
  ck_assert_ldouble_nan(s21_pow(s21_NAN, 2.4));
  ck_assert_ldouble_nan(s21_pow(s21_NAN, 2.4));

  ck_assert_ldouble_infinite(s21_pow(2.4, s21_INF));
  ck_assert_ldouble_eq_tol(s21_pow(2.4, s21_NEG_INF), pow(2.4, s21_NEG_INF),
                           1e-8);
  ck_assert_ldouble_nan(s21_pow(2.4, s21_NAN));
  ck_assert_ldouble_nan(s21_pow(2.4, s21_NAN));

  ck_assert_ldouble_eq_tol(s21_pow(0, 2.4), pow(0, 2.4), 1e-8);
  ck_assert_ldouble_eq_tol(s21_pow(-0, 2.4), pow(-0, 2.4), 1e-8);
  ck_assert_ldouble_eq_tol(s21_pow(2.4, 0), pow(2.4, 0), 1e-8);
  ck_assert_ldouble_eq_tol(s21_pow(2.4, -0), pow(2.4, -0), 1e-8);
  ck_assert_ldouble_eq_tol(round(s21_pow(2.4, 0.5) * SIX) / SIX,
                           round(pow(2.4, 0.5) * SIX) / SIX, 1e-8);
  ck_assert_ldouble_eq_tol(round(s21_pow(2.4, -0.5) * SIX) / SIX,
                           round(pow(2.4, -0.5) * SIX) / SIX, 1e-8);
  ck_assert_ldouble_nan(s21_pow(-2.4, 0.5));
  ck_assert_ldouble_nan(s21_pow(-2.4, -0.5));
  ck_assert_ldouble_nan(s21_pow(-2.4, 2.1));
  ck_assert_ldouble_nan(s21_pow(-2.4, -2.1));
  ck_assert_ldouble_eq_tol(s21_pow(-2.4, 2), pow(-2.4, 2), 1e-8);
  ck_assert_ldouble_eq_tol(s21_pow(2.4, 2), pow(2.4, 2), 1e-8);
  ck_assert_ldouble_eq_tol(s21_pow(-2.4, -1), pow(-2.4, -1), 1e-8);
  ck_assert_ldouble_nan(s21_pow(-2.4, -1.2));
  ck_assert_ldouble_nan(s21_pow(-2.4, -0.4));
  ck_assert_ldouble_eq_tol(s21_pow(2.4, 1), pow(2.4, 1), 1e-8);
  ck_assert_ldouble_eq_tol(s21_pow(2.4, 3), pow(2.4, 3), 1e-8);
  ck_assert_ldouble_eq_tol(s21_pow(2.4, -3), pow(2.4, -3), 1e-8);
  ck_assert_ldouble_eq_tol(s21_pow(66.4, 1.7), pow(66.4, 1.7), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(66.4, -1.5), pow(66.4, -1.5), 1e-8);
  ck_assert_ldouble_eq_tol(s21_pow(3.3, 13.2), pow(3.3, 13.2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(3.3, -24.2), pow(3.3, -24.2), 1e-8);
  ck_assert_ldouble_nan(s21_pow(-3.3, -24.2));
  ck_assert_ldouble_eq_tol(s21_pow(0.0000000005543, 24.2),
                           pow(0.0000000005543, 24.2), 1e-8);
  ck_assert_ldouble_eq_tol(s21_pow(0.0000000005543, 0.00000003),
                           pow(0.0000000005543, 0.00000003), 1e-8);
}
END_TEST

START_TEST(fmod_test) {  // done
  ck_assert_ldouble_nan(s21_fmod(s21_INF, s21_INF));
  ck_assert_ldouble_nan(s21_fmod(s21_INF, s21_NEG_INF));
  ck_assert_ldouble_nan(s21_fmod(s21_INF, s21_NAN));
  ck_assert_ldouble_nan(s21_fmod(s21_INF, s21_NAN));

  ck_assert_ldouble_nan(s21_fmod(s21_NEG_INF, s21_INF));
  ck_assert_ldouble_nan(s21_fmod(s21_NEG_INF, s21_NEG_INF));
  ck_assert_ldouble_nan(s21_fmod(s21_NEG_INF, s21_NAN));
  ck_assert_ldouble_nan(s21_fmod(s21_NEG_INF, s21_NAN));

  ck_assert_ldouble_nan(s21_fmod(s21_NAN, s21_INF));
  ck_assert_ldouble_nan(s21_fmod(s21_NAN, s21_NEG_INF));
  ck_assert_ldouble_nan(s21_fmod(s21_NAN, s21_NAN));
  ck_assert_ldouble_nan(s21_fmod(s21_NAN, s21_NAN));

  ck_assert_ldouble_nan(s21_fmod(s21_NAN, s21_INF));
  ck_assert_ldouble_nan(s21_fmod(s21_NAN, s21_NEG_INF));
  ck_assert_ldouble_nan(s21_fmod(s21_NAN, s21_NAN));
  ck_assert_ldouble_nan(s21_fmod(s21_NAN, s21_NAN));

  ck_assert_ldouble_nan(s21_fmod(s21_INF, 2.4));
  ck_assert_ldouble_nan(s21_fmod(s21_NEG_INF, 2.4));
  ck_assert_ldouble_nan(s21_fmod(s21_NAN, 2.4));
  ck_assert_ldouble_nan(s21_fmod(s21_NAN, 2.4));

  ck_assert_ldouble_eq_tol(s21_fmod(2.4, s21_INF), fmod(2.4, s21_INF),
                           1e-8);
  ck_assert_ldouble_eq_tol(s21_fmod(2.4, s21_NEG_INF), fmod(2.4, s21_NEG_INF),
                           1e-8);
  ck_assert_ldouble_nan(s21_fmod(2.4, s21_NAN));
  ck_assert_ldouble_nan(s21_fmod(2.4, s21_NAN));

  ck_assert_ldouble_eq_tol(s21_fmod(0, 2.4), fmod(0, 2.4), 1e-8);
  ck_assert_ldouble_eq_tol(s21_fmod(-0, 2.4), fmod(-0, 2.4), 1e-8);
  ck_assert_ldouble_nan(s21_fmod(2.4, 0));
  ck_assert_ldouble_nan(s21_fmod(2.4, -0));
  ck_assert_ldouble_eq_tol(s21_fmod(2.4, 0.5), fmod(2.4, 0.5), 1e-8);
  ck_assert_ldouble_eq_tol(s21_fmod(2.4, -0.5), fmod(2.4, -0.5), 1e-8);
  ck_assert_ldouble_eq_tol(s21_fmod(-2.4, 0.5), fmod(-2.4, 0.5), 1e-8);
  ck_assert_ldouble_eq_tol(s21_fmod(-2.4, -0.5), fmod(-2.4, -0.5), 1e-8);
  ck_assert_ldouble_eq_tol(s21_fmod(666666.4, 1.5), fmod(666666.4, 1.5), 1e-8);
  ck_assert_ldouble_eq_tol(s21_fmod(666666.4, -1.5), fmod(666666.4, -1.5),
                           1e-8);
  ck_assert_ldouble_eq_tol(s21_fmod(3.3, 24.2), fmod(3.3, 24.2), 1e-8);
  ck_assert_ldouble_eq_tol(s21_fmod(3.3, -24.2), fmod(3.3, -24.2), 1e-8);
  ck_assert_ldouble_eq_tol(s21_fmod(-3.3, -24.2), fmod(-3.3, -24.2), 1e-8);
  ck_assert_ldouble_eq_tol(s21_fmod(0.0000000005543, 24.2),
                           fmod(0.0000000005543, 24.2), 1e-8);
  ck_assert_ldouble_eq_tol(s21_fmod(0.0000000005543, 0.000003),
                           fmod(0.0000000005543, 0.000003), 1e-8);
}
END_TEST

START_TEST(ceil_test) {  // done
  ck_assert_ldouble_eq(s21_ceil(s21_INF), ceil(s21_INF));
  ck_assert_ldouble_eq(s21_ceil(s21_NEG_INF), ceil(s21_NEG_INF));
  ck_assert_ldouble_nan(s21_ceil(s21_NAN));
  ck_assert_ldouble_nan(s21_ceil(s21_NAN));
  ck_assert_ldouble_eq(s21_ceil(-876554310.23455), ceil(-876554310.23455));
  ck_assert_ldouble_eq(s21_ceil(876554310.23455), ceil(876554310.23455));
  ck_assert_ldouble_eq(s21_ceil(-0.45), ceil(-0.45));
  ck_assert_ldouble_eq(s21_ceil(0.45), ceil(0.45));
  ck_assert_ldouble_eq(s21_ceil(-0.00000000000000045),
                       ceil(-0.00000000000000045));
}
END_TEST

START_TEST(floor_test) {  // done
  ck_assert_ldouble_infinite(s21_floor(s21_INF));
  ck_assert_ldouble_infinite(s21_floor(s21_NEG_INF));
  ck_assert_ldouble_nan(s21_floor(s21_NAN));
  ck_assert_ldouble_eq(s21_floor(s21_INF), floor(s21_INF));
  ck_assert_ldouble_eq(s21_floor(s21_NEG_INF), floor(s21_NEG_INF));
  ck_assert_ldouble_eq(s21_floor(0), floor(0));
  ck_assert_ldouble_eq(s21_floor(-0), floor(-0));
  ck_assert_ldouble_eq(s21_floor(-876554310.23455), floor(-876554310.23455));
  ck_assert_ldouble_eq(s21_floor(876554310.23455), floor(876554310.23455));
  ck_assert_ldouble_eq(s21_floor(-0.45), floor(-0.45));
  ck_assert_ldouble_eq(s21_floor(0.45), floor(0.45));
  ck_assert_ldouble_eq(s21_floor(-0.0000000000000000000045),
                       floor(-0.0000000000000000000045));
}
END_TEST

START_TEST(abs_test) {  // done
  int inf_max = 1.0 / 0.0;
  int inf_min = -1.0 / 0.0;
  int nan_max = 0.0 / 0.0;
  int nan_min = -0.0 / 0.0;
  ck_assert_int_eq(s21_abs(inf_max), abs(inf_max));
  ck_assert_int_eq(s21_abs(inf_min), abs(inf_min));
  ck_assert_int_eq(s21_abs(nan_max), abs(nan_max));
  ck_assert_int_eq(s21_abs(nan_min), abs(nan_min));
  ck_assert_int_eq(s21_abs(-10), abs(-10));
  ck_assert_int_eq(s21_abs(-0), abs(-0));
}
END_TEST

START_TEST(fabs_test) {  // done
  ck_assert_ldouble_infinite(s21_fabs(s21_NEG_INF));
  ck_assert_ldouble_infinite(s21_fabs(s21_INF));
  ck_assert_ldouble_nan(s21_fabs(s21_NAN));
  ck_assert_ldouble_nan(s21_fabs(s21_NAN));
  ck_assert_ldouble_eq_tol(s21_fabs(0.5), fabs(0.5), 1e-15);
  ck_assert_ldouble_eq_tol(s21_fabs(-0.5), fabs(-0.5), 1e-15);
  ck_assert_ldouble_eq_tol(s21_fabs(-1.0), fabs(-1.0), 1e-15);
  ck_assert_ldouble_eq_tol(s21_fabs(1.0), fabs(1.0), 1e-15);
  ck_assert_ldouble_eq_tol(s21_fabs(1.1), fabs(1.1), 1e-15);
  ck_assert_ldouble_eq_tol(s21_fabs(-2.1), fabs(-2.1), 1e-15);
  ck_assert_ldouble_eq_tol(s21_fabs(0.0), fabs(0.0), 1e-15);
  ck_assert_ldouble_eq_tol(s21_fabs(-0.0), fabs(-0.0), 1e-15);
  ck_assert_ldouble_eq_tol(s21_fabs(5.123456789123), fabs(5.123456789123),
                           1e-15);
  ck_assert_ldouble_eq_tol(s21_fabs(0.00000004564897), fabs(0.00000004564897),
                           1e-15);
  ck_assert_ldouble_eq_tol(s21_fabs(170000000000000.1), fabs(170000000000000.1),
                           1e-15);
  ck_assert_ldouble_eq_tol(s21_fabs(-5.123456789123), fabs(-5.123456789123),
                           1e-15);
  ck_assert_ldouble_eq_tol(s21_fabs(-0.00000004564897), fabs(-0.00000004564897),
                           1e-15);
  ck_assert_ldouble_eq_tol(s21_fabs(-170000000000000.1),
                           fabs(-170000000000000.1), 1e-15);
}
END_TEST

Suite *s21_math_lukeshir(void) {
  Suite *suite;
  TCase *tcase;
  suite = suite_create("UNITS");  //создает набор кейсов с заданным именем
  tcase = tcase_create("TESTS");
  suite_add_tcase(suite, tcase);
  tcase_add_test(tcase, sin_test);
  tcase_add_test(tcase, cos_test);
  tcase_add_test(tcase, tan_test);
  tcase_add_test(tcase, asin_test);
  tcase_add_test(tcase, acos_test);
  tcase_add_test(tcase, atan_test);
  tcase_add_test(tcase, exp_test);
  tcase_add_test(tcase, log_test);
  tcase_add_test(tcase, sqrt_test);
  tcase_add_test(tcase, pow_test);
  tcase_add_test(tcase, fmod_test);
  tcase_add_test(tcase, ceil_test);
  tcase_add_test(tcase, floor_test);
  tcase_add_test(tcase, abs_test);
  tcase_add_test(tcase, fabs_test);
  suite_add_tcase(suite, tcase);
  return suite;
}