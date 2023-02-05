#ifndef C2_S21_STRINGPLUS_0_SRC_TEST_TEST_H_
#define C2_S21_STRINGPLUS_0_SRC_TEST_TEST_H_
#include "../s21_math.h"
#include <check.h>
#include <math.h>
#define SIX 1000000
#define s21_DBL_MAX 1.7976931348623158e+308
#define s21_e 2.71828182845904523536
#define s21_E 2.71828182845
#define S21_P_4 0.78539816339
#define S21_P_3 1.0471975512
#define S21_2P_3 2.09439510239
#define s21_3P_4 2.35619449019
#define s21_5P_6 2.61799387799
#define s21_7P_6 3.66519142919
#define s21_5P_4 3.92699081699
#define s21_4P_3 4.18879020479
#define s21_5P_3 5.23598775598
#define s21_7P_4 5.49778714378
#define s21_11P_6 5.75958653158
#define S21_P 3.14159265358979
#define S21_P_6 S21_P / 6
#define S21_2P  2 * S21_P
Suite *s21_math_lukeshir(void);
Suite* s21_math_nyar(void);
Suite* s21_gulianbo_suite(void);
#endif //C2_S21_STRINGPLUS_0_SRC_TEST_TEST_H_
