#include "s21_test_calc.h"

START_TEST(test_CALC) {
  double answer = 0.0;
  int error = 0;
  char *str_1 = "2 + 2 + 2 + 2 + 2 + 2 + 2 + 2 + 2 + 2";
  answer = s21_smart_calc(str_1, 0, 0, &error);
  printf("|%f|\n", answer);
  ck_assert_int_eq(20, answer);
  answer = 0.0;

  char *str_1_extra =
      "15/(7-(1+1))*3-(2+(1+1))*15/(7-(200+1))*3-(2+(1+1))*(15/(7-(1+1))*3-(2+(1+1))+15/(7-(1+1))*3-(2+(1+1)))";
  answer = s21_smart_calc(str_1_extra, 0, 0, &error);
  ck_assert_double_eq_tol(-30.072164948453608, answer, 1e-6);
  answer = 0.0;

  char *str_2 = "2 - 2 - 2 - 2 - 2 - 2 - 2 - 2 - 2 - 2";
  answer = s21_smart_calc(str_2, 0, 0, &error);
  ck_assert_int_eq(-16, answer);
  answer = 0.0;

  char *str_3 = "2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2";
  answer = s21_smart_calc(str_3, 0, 0, &error);
  ck_assert_int_eq(1024, answer);
  answer = 0.0;

  char *str_4 = "2 / 2 / 2 / 2 / 2 / 2 / 2 / 2 / 2 / 2";
  answer = s21_smart_calc(str_4, 0, 0, &error);
  ck_assert_double_eq_tol(0.00390625, answer, 1e-6);
  answer = 0.0;

  char *str_5 = "sin(0.7) + sin(0.7) + sin(0.7) + sin(0.7) + sin(0.7)";
  answer = s21_smart_calc(str_5, 0, 0, &error);
  ck_assert_ldouble_eq_tol(3.22108844, answer, 1e-7);
  answer = 0.0;

  char *str_6 = "cos(0.7) + cos(0.7) + cos(0.7) + cos(0.7) + cos(0.7)";
  answer = s21_smart_calc(str_6, 0, 0, &error);
  ck_assert_ldouble_eq_tol(3.82421094, answer, 1e-7);
  answer = 0.0;

  char *str_7 = "tan(0.7) + tan(0.7) + tan(0.7) + tan(0.7) + tan(0.7)";
  answer = s21_smart_calc(str_7, 0, 0, &error);
  ck_assert_ldouble_eq_tol(4.2114419, answer, 1e-7);
  answer = 0.0;

//  char *str_8 = "ctg(0.7) + ctg(0.7) + ctg(0.7) + ctg(0.7) + ctg(0.7)";
//  answer = s21_smart_calc(str_8, 0, 0, &error);
//  ck_assert_ldouble_eq_tol(5.93620915, answer, 1e-7);
//  answer = 0.0;

  char *str_9 = "acos(0.7) + acos(0.7) + acos(0.7) + acos(0.7) + acos(0.7)";
  answer = s21_smart_calc(str_9, 0, 0, &error);
  ck_assert_ldouble_eq_tol(3.976994151, answer, 1e-7);
  answer = 0.0;

  char *str_10 = "asin(0.7) + asin(0.7) + asin(0.7) + asin(0.7) + asin(0.7)";
  answer = s21_smart_calc(str_10, 0, 0, &error);
  ck_assert_ldouble_eq_tol(3.876987483, answer, 1e-7);
  answer = 0.0;

  char *str_11 = "atan(0.7) + atan(0.7) + atan(0.7) + atan(0.7) + atan(0.7)";
  answer = s21_smart_calc(str_11, 0, 0, &error);
  ck_assert_ldouble_eq_tol(3.053629822, answer, 1e-7);
  answer = 0.0;

  char *str_12 = "(7 mod 7) + (7 mod 6) + (7 mod 6) + (7 mod 5) + (7 mod 4)";
  answer = s21_smart_calc(str_12, 0, 0, &error);
  ck_assert_int_eq(7, answer);
  answer = 0.0;

  char *str_12_2 = "0 mod 0";
  answer = s21_smart_calc(str_12_2, 0, 0, &error);
  ck_assert_double_nan(answer);
  answer = 0.0;

  char *str_13 =
      "log(7 mod 7 + 1) + log(7 mod 6) + log(7 mod 6) + log(7 mod 5) + log(7 mod 4)";
  answer = s21_smart_calc(str_13, 0, 0, &error);
  ck_assert_ldouble_eq_tol(0.7781512503836436, answer, 1e-7);
  answer = 0.0;

  char *str_14 = "sqrt(4) + sqrt(7) + sqrt(0.99) + sqrt(81) + sqrt(100)";
  answer = s21_smart_calc(str_14, 0, 0, &error);
  ck_assert_ldouble_eq_tol(24.6407387, answer, 1e-7);
  answer = 0.0;

  char *str_15 = "7 ^ 2 + 7 ^ 5 + 7 ^ 4 + 7 ^ 3 + 7 ^ 7";
  answer = s21_smart_calc(str_15, 0, 0, &error);
  ck_assert_int_eq(843143, answer);
  answer = 0.0;

  char *str_16 = "ln(7) + ln(7) + ln(7) + ln(7) + ln(7)";
  answer = s21_smart_calc(str_16, 0, 0, &error);
  ck_assert_ldouble_eq_tol(9.729550745, answer, 1e-7);
  answer = 0.0;

  char *str_17 = "-7";
  answer = s21_smart_calc(str_17, 0, 0, &error);
  ck_assert_int_eq(-7, answer);
  answer = 0.0;

  char *str_18 = "2^2^3";
  answer = s21_smart_calc(str_18, 0, 0, &error);
  ck_assert_int_eq(256, answer);
  answer = 0.0;

  char *str_19 = "cos(200^2)^2";
  answer = s21_smart_calc(str_19, 0, 0, &error);
  ck_assert_ldouble_eq_tol(0.10406267813194549, answer, 1e-7);
  answer = 0.0;

  char *str_20 = "(2 + 3)(2 + 3)";
  answer = s21_smart_calc(str_20, 0, 0, &error);
  ck_assert_int_eq(25, answer);
  answer = 0.0;

  char *str_21 = "(2 + 3)   (2 + 3)";
  answer = s21_smart_calc(str_21, 0, 0, &error);
  ck_assert_int_eq(25, answer);
  answer = 0.0;

  char *str_22 = "1 + 2 * 3 * 4(2 + 3)";
  answer = s21_smart_calc(str_22, 0, 0, &error);
  ck_assert_int_eq(121, answer);
  answer = 0.0;

  char *str_23 = "cos 10";
  answer = s21_smart_calc(str_23, 0, 0, &error);
  ck_assert_ldouble_eq_tol(-2 + 1.160928471, answer, 1e-7);
  answer = 0.0;
}
END_TEST

START_TEST(test_2) {
  int mode = 1;
  double answer = 0.0;
  int value = 2;
  int error = 0;
  char *str_1 = "x + x + x + x + x + x + x + x + x + x";
  answer = s21_smart_calc(str_1, mode, value, &error);
  ck_assert_int_eq(0, error);
  ck_assert_int_eq(20, answer);
  answer = 0.0;
  error = 0;

  char *str_2 = "x - x - x - x - x - x - x - x - x - x";
  answer = s21_smart_calc(str_2, mode, value, &error);
  ck_assert_int_eq(0, error);
  ck_assert_int_eq(-16, answer);
  answer = 0.0;
  error = 0;

  char *str_3 = "x * x * x * x * x * x * x * x * x * x";
  answer = s21_smart_calc(str_3, mode, value, &error);
  ck_assert_int_eq(0, error);
  ck_assert_int_eq(1024, answer);
  answer = 0.0;
  error = 0;

  char *str_4 = "x / x / x / x / x / x / x / x / x / x";
  answer = s21_smart_calc(str_4, mode, value, &error);
  ck_assert_int_eq(0, error);
  ck_assert_int_eq(0, answer);
  answer = 0.0;
  error = 0;

  value = 7;
  char *str_5 = "sin(x) + sin(x) + sin(x) + sin(x) + sin(x)";
  answer = s21_smart_calc(str_5, mode, value, &error);
  ck_assert_int_eq(0, error);
  ck_assert_ldouble_eq_tol(3.28493299, answer, 1e-7);
//
//  answer = 0.0;
  char *str_6 = "cos(x) + cos(x) + cos(x) + cos(x) + cos(x)";
  answer = s21_smart_calc(str_6, mode, value, &error);
  ck_assert_int_eq(0, error);
  ck_assert_ldouble_eq_tol(3.76951127, answer, 1e-7);
//
  answer = 0.0;
  char *str_7 = "tan(x) + tan(x) + tan(x) + tan(x) + tan(x)";
  answer = s21_smart_calc(str_7, mode, value, &error);
  ck_assert_int_eq(0, error);
  ck_assert_ldouble_eq_tol(4.35724, answer, 1e-7);
//

//
  answer = 0.0;
  value = 7;
  char *str_12 = "(x mod x) + (x mod 6) + (x mod 6) + (x mod 5) + (x mod 4)";
  answer = s21_smart_calc(str_12, mode, value, &error);
  ck_assert_int_eq(0, error);
  ck_assert_int_eq(7, answer);
//
  answer = 0.0;
  char *str_13 = "log(x mod x + 1) + log(x mod 6) + log(x mod 6) + log(x mod 5) + log(x mod 4)";
  answer = s21_smart_calc(str_13, mode, value, &error);
  ck_assert_int_eq(0, error);
  ck_assert_ldouble_eq_tol(0.7781512503836436, answer, 1e-7);
//
  answer = 0.0;
  char *str_14 = "sqrt(4) + sqrt(x) + sqrt(0.99) + sqrt(81) + sqrt(100)";
  answer = s21_smart_calc(str_14, mode, value, &error);
  ck_assert_int_eq(0, error);
  ck_assert_ldouble_eq_tol(24.6407387, answer, 1e-7);
//
  answer = 0.0;
  char *str_15 = "x ^ 2 + x ^ 5 + x ^ 4 + x ^ 3 + x ^ x";
  answer = s21_smart_calc(str_15, mode, value, &error);
  ck_assert_int_eq(0, error);
  ck_assert_int_eq(843143, answer);
//
  answer = 0.0;
  char *str_16 = "x ^ 2 + x ^ 5 + x ^ 4 + x ^ 3 + x ^ x";
  answer = s21_smart_calc(str_16, mode, value, &error);
  ck_assert_int_eq(0, error);
  ck_assert_int_eq(843143, answer);
}
END_TEST

//
START_TEST(invalid_input) {
  int mode = 0;
  double answer = 0.0;
  int value = 2;
  int error = 0;
  char *str_1 = "x + x + x + x + x + x + x + x + x + x";
  answer = s21_smart_calc(str_1, mode, value, &error);
  ck_assert_int_ne(error, 0);
  ck_assert_double_nan(answer);
  answer = 0.0;
  error = 0;


  char *str_2 = "1+";
  answer = s21_smart_calc(str_2, mode, value, &error);
  ck_assert_int_ne(error, 0);
  ck_assert_double_nan(answer);
  answer = 0.0;
  error = 0;

  char *str_3 = "sin(^)";
  answer = s21_smart_calc(str_3, mode, value, &error);
  ck_assert_int_ne(error, 0);
  ck_assert_double_nan(answer);
  answer = 0.0;
  error = 0;

  char *str_4 = "sin(1-)";
  answer = s21_smart_calc(str_4, mode, value, &error);
  ck_assert_int_ne(error, 0);
  ck_assert_double_nan(answer);
  answer = 0.0;
  error = 0;


  char *str_5 = "sin(0)-";
  answer = s21_smart_calc(str_5, mode, value, &error);
  ck_assert_int_ne(error, 0);
  ck_assert_double_nan(answer);
  answer = 0.0;
  error = 0;


  char *str_6 = "sin(1+0()))";
  answer = s21_smart_calc(str_6, mode, value, &error);
  ck_assert_int_ne(error, 0);
  ck_assert_double_nan(answer);
  answer = 0.0;
  error = 0;


  char *str_7 = "12 mod ";
  answer = s21_smart_calc(str_7, mode, value, &error);
  ck_assert_int_ne(error, 0);
  ck_assert_double_nan(answer);
  answer = 0.0;
  error = 0;

  char *str_8 = "1-----1-";
  answer = s21_smart_calc(str_8, mode, value, &error);
  ck_assert_int_ne(error, 0);
  ck_assert_double_nan(answer);
  answer = 0.0;
  error = 0;


  char *str_9 = "1-^2";
  answer = s21_smart_calc(str_9, mode, value, &error);
  ck_assert_int_ne(error, 0);
  ck_assert_double_nan(answer);
  answer = 0.0;
  error = 0;

  char *str_10 = "1.1.1 + 2";
  answer = s21_smart_calc(str_10, mode, value, &error);
  ck_assert_int_ne(error, 0);
  ck_assert_double_nan(answer);
  answer = 0.0;
  error = 0;

  char *str_11 = ".1 + 2";
  answer = s21_smart_calc(str_11, mode, value, &error);
  ck_assert_int_ne(error, 0);
  ck_assert_double_nan(answer);
  answer = 0.0;
  error = 0;

  mode = 1;
  char *str_12 = "x+";
  answer = s21_smart_calc(str_12, mode, value, &error);
  ck_assert_int_ne(error, 0);
  ck_assert_double_nan(answer);
  answer = 0.0;
  error = 0;


  char *str_13 = "x+";
  answer = s21_smart_calc(str_13, mode, value, &error);
  ck_assert_int_ne(error, 0);
  ck_assert_double_nan(answer);
  answer = 0.0;
  error = 0;

  char *str_14 = "sin(x^((2/3)*(2 * 3(cos(sin(sqrt(1/)))))))";
  answer = s21_smart_calc(str_14, mode, value, &error);
  ck_assert_int_ne(error, 0);
  ck_assert_double_nan(answer);
  answer = 0.0;
  error = 0;

  char *str_15 = "sin(x-)";
  answer = s21_smart_calc(str_15, mode, value, &error);
  ck_assert_int_ne(error, 0);
  ck_assert_double_nan(answer);
  answer = 0.0;
  error = 0;


  char *str_16 = "sin(x)-";
  answer = s21_smart_calc(str_16, mode, value, &error);
  ck_assert_int_ne(error, 0);
  ck_assert_double_nan(answer);
  answer = 0.0;
  error = 0;


  char *str_17 = "sin(x+x()))";
  answer = s21_smart_calc(str_17, mode, value, &error);
  ck_assert_int_ne(error, 0);
  ck_assert_double_nan(answer);
  answer = 0.0;
  error = 0;


  char *str_18 = "x mod ";
  answer = s21_smart_calc(str_18, mode, value, &error);
  ck_assert_int_ne(error, 0);
  ck_assert_double_nan(answer);
  answer = 0.0;
  error = 0;

  char *str_19 = "1-----x-";
  answer = s21_smart_calc(str_19, mode, value, &error);
  ck_assert_int_ne(error, 0);
  ck_assert_double_nan(answer);
  answer = 0.0;
  error = 0;


  char *str_20 = "x-^x";
  answer = s21_smart_calc(str_20, mode, value, &error);
  ck_assert_int_ne(error, 0);
  ck_assert_double_nan(answer);
  answer = 0.0;
  error = 0;

  char *str_21 = "1.1.1 + x";
  answer = s21_smart_calc(str_21, mode, value, &error);
  ck_assert_int_ne(error, 0);
  ck_assert_double_nan(answer);
  answer = 0.0;
  error = 0;

  char *str_22 = "x. + 2";
  answer = s21_smart_calc(str_22, mode, value, &error);
  ck_assert_int_ne(error, 0);
  ck_assert_double_nan(answer);
  answer = 0.0;
  error = 0;

}
END_TEST


START_TEST(smart_multiplyer) {
//  int mode = 0;
  double answer = 0.0;
//  int value = 2;
  int error = 0;
  char *str_1 = "cos(10)sin(10)";
  answer = s21_smart_calc(str_1, 0, 0, &error);
  ck_assert_ldouble_eq_tol(0.4564726253638138, answer, 1e-7);
  answer = 0.0;


  char *str_2 = "cos(-10)sin(10)";
  answer = s21_smart_calc(str_2, 0, 0, &error);
  ck_assert_ldouble_eq_tol(0.4564726253638138, answer, 1e-7);
  answer = 0.0;

  char *str_3 = "cos(10)sin(10)";
  answer = s21_smart_calc(str_3, 0, 0, &error);
  ck_assert_ldouble_eq_tol(0.4564726253638138, answer, 1e-7);
  answer = 0.0;

  char *str_4 = "cos(-10)sin(-10)";
  answer = s21_smart_calc(str_4, 0, 0, &error);
  ck_assert_ldouble_eq_tol(-0.4564726253638138, answer, 1e-7);
  answer = 0.0;

  char *str_5 = "2sin(-10)";
  answer = s21_smart_calc(str_5, 0, 0, &error);
  ck_assert_ldouble_eq_tol(1.0880422217787395, answer, 1e-7);
  answer = 0.0;

  char *str_6 = "2sin(-10)*4cos(sqrt(log(ln(200000))))";
  answer = s21_smart_calc(str_6, 0, 0, &error);
  ck_assert_ldouble_eq_tol(2.194181048, answer, 1e-7);
  answer = 0.0;

  char *str_7 = "(-10)4";
  answer = s21_smart_calc(str_7, 0, 0, &error);
  ck_assert_int_ne(error, 0);
  answer = 0.0;
  int value = 5;
  int mode = 1;
  char *str_8 = "10log(100)cos(20)sin(30)xXx";
  answer = s21_smart_calc(str_8, mode, value, &error);
  ck_assert_ldouble_eq_tol(-1007.994956, answer, 1e-6);
  answer = 0.0;


  char *str_9 = "(-10)(4)";
  answer = s21_smart_calc(str_9, 0, 0, &error);
  ck_assert_ldouble_eq_tol(-40, answer, 1e-6);
  answer = 0.0;

  char *str_10 = "1/3sinX+6^2^3";
  answer = s21_smart_calc(str_10, mode, value, &error);
  ck_assert_ldouble_eq_tol(1679615.652388, answer, 1e-6);
  answer = 0.0;
}
END_TEST
Suite *Calc(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("Gulianbo ");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_CALC);
  tcase_add_test(tc_core, test_2);
  tcase_add_test(tc_core, invalid_input);
  tcase_add_test(tc_core, smart_multiplyer);

  suite_add_tcase(s, tc_core);

  return s;
}