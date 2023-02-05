#include <check.h>
#include <stdio.h>

#include "../s21_decimal.h"
#include "test_s21_decimal.h"

START_TEST(is_less_1) {
  int numb_1 = -345432520;
  int numb_2 = -345432521;
  int result = 0;
  s21_decimal number_1 = {0};
  s21_decimal number_2 = {0};
  s21_from_int_to_decimal(numb_1, &number_1);
  s21_from_int_to_decimal(numb_2, &number_2);
  ck_assert_int_eq(s21_is_less(number_1, number_2), result);
  ck_assert_int_eq(s21_is_less_or_equal(number_1, number_2), result);
}
END_TEST

START_TEST(is_less_2) {
  int numb_1 = 345432520;
  int numb_2 = 345432525;
  int result = 1;
  s21_decimal number_1 = {0};
  s21_decimal number_2 = {0};
  s21_from_int_to_decimal(numb_1, &number_1);
  s21_from_int_to_decimal(numb_2, &number_2);
  ck_assert_int_eq(s21_is_less(number_1, number_2), result);
  ck_assert_int_eq(s21_is_less_or_equal(number_1, number_2), result);
}
END_TEST

START_TEST(is_less_3) {
  int numb_1 = 345432520;
  unsigned long long numb_2 = 345432520;
  int result = 0;
  s21_decimal number_1 = {0};
  s21_decimal number_2 = {0};
  s21_from_int_to_decimal(numb_1, &number_1);
  s21_from_int_to_decimal(numb_2, &number_2);
  ck_assert_int_eq(s21_is_less(number_1, number_2), result);
  ck_assert_int_eq(s21_is_less_or_equal(number_1, number_2), 1);
}
END_TEST

START_TEST(is_equal_1) {
  int numb_1 = 2147483647;
  int numb_2 = 2147483647;
  int result = 1;
  s21_decimal number_1 = {0};
  s21_decimal number_2 = {0};
  s21_from_int_to_decimal(numb_1, &number_1);
  s21_from_int_to_decimal(numb_2, &number_2);
  ck_assert_int_eq(s21_is_equal(number_1, number_2), result);
}
END_TEST

START_TEST(is_equal_2) {
  unsigned long long numb_1 = 18446744073709551615Ull;
  unsigned long long numb_2 = 18446744073709551615Ull;
  int result = 1;
  s21_decimal number_1 = {0};
  s21_decimal number_2 = {0};
  s21_from_int_to_decimal(numb_1, &number_1);
  s21_from_int_to_decimal(numb_2, &number_2);
  ck_assert_int_eq(s21_is_equal(number_1, number_2), result);
}
END_TEST

START_TEST(is_equal_3) {
  unsigned long long numb_1 = 0;
  unsigned long long numb_2 = 0;
  int result = 1;
  s21_decimal number_1 = {0};
  s21_decimal number_2 = {0};
  s21_from_int_to_decimal(numb_1, &number_1);
  s21_from_int_to_decimal(numb_2, &number_2);
  ck_assert_int_eq(s21_is_equal(number_1, number_2), result);
}
END_TEST

Suite *test_g(void) {
  Suite *s;
  TCase *tc_bin;

  s = suite_create("Gulianbo");
  tc_bin = tcase_create("Bin");
  tcase_add_test(tc_bin, is_equal_1);
  tcase_add_test(tc_bin, is_equal_2);
  tcase_add_test(tc_bin, is_equal_3);
  tcase_add_test(tc_bin, is_less_1);
  tcase_add_test(tc_bin, is_less_2);
  tcase_add_test(tc_bin, is_less_3);
  suite_add_tcase(s, tc_bin);

  return s;
}
