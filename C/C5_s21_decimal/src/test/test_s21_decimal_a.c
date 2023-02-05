#include <check.h>
#include <stdio.h>

#include "../s21_decimal.h"
#include "test_s21_decimal.h"

START_TEST(is_equal_1) {
  int numb_1 = 345432521;
  int numb_2 = 345432521;
  int result = 1;
  s21_decimal number_1 = {0};
  s21_decimal number_2 = {0};
  s21_from_int_to_decimal(numb_1, &number_1);
  s21_from_int_to_decimal(numb_2, &number_2);
  ck_assert_int_eq(s21_is_equal(number_1, number_2), result);
}
END_TEST

START_TEST(is_equal_2) {
  int numb_1 = 345432500;
  int numb_2 = 345432521;
  int result = 0;
  s21_decimal number_1 = {0};
  s21_decimal number_2 = {0};
  s21_from_int_to_decimal(numb_1, &number_1);
  s21_from_int_to_decimal(numb_2, &number_2);
  ck_assert_int_eq(s21_is_equal(number_1, number_2), result);
}
END_TEST

START_TEST(is_equal_3) {
  int numb_1 = -345432521;
  int numb_2 = 345432521;
  int result = 0;
  s21_decimal number_1 = {0};
  s21_decimal number_2 = {0};
  s21_from_int_to_decimal(numb_1, &number_1);
  s21_from_int_to_decimal(numb_2, &number_2);
  ck_assert_int_eq(s21_is_equal(number_1, number_2), result);
}
END_TEST

START_TEST(is_equal_4) {
  int numb_1 = 345432521;
  int numb_2 = -345432521;
  int result = 0;
  s21_decimal number_1 = {0};
  s21_decimal number_2 = {0};
  s21_from_int_to_decimal(numb_1, &number_1);
  s21_from_int_to_decimal(numb_2, &number_2);
  ck_assert_int_eq(s21_is_equal(number_1, number_2), result);
}
END_TEST

START_TEST(is_equal_5) {
  int numb_1 = -345432521;
  int numb_2 = -345432521;
  int result = 1;
  s21_decimal number_1 = {0};
  s21_decimal number_2 = {0};
  s21_from_int_to_decimal(numb_1, &number_1);
  s21_from_int_to_decimal(numb_2, &number_2);
  ck_assert_int_eq(s21_is_equal(number_1, number_2), result);
}
END_TEST

START_TEST(is_equal_6) {
  int numb_1 = +0;
  int numb_2 = -0;
  int result = 0;
  s21_decimal number_1 = {0};
  s21_decimal number_2 = {0};
  s21_from_int_to_decimal(numb_1, &number_1);
  s21_from_int_to_decimal(numb_2, &number_2);
  ck_assert_int_eq(s21_is_greater(number_1, number_2), result);
}
END_TEST

START_TEST(is_greater_1) {
  int numb_1 = -345432521;
  int numb_2 = -345432521;
  int result = 0;
  s21_decimal number_1 = {0};
  s21_decimal number_2 = {0};
  s21_from_int_to_decimal(numb_1, &number_1);
  s21_from_int_to_decimal(numb_2, &number_2);
  ck_assert_int_eq(s21_is_greater(number_1, number_2), result);
}
END_TEST

START_TEST(is_greater_2) {
  int numb_1 = 345432550;
  int numb_2 = 345432521;
  int result = 1;
  s21_decimal number_1 = {0};
  s21_decimal number_2 = {0};
  s21_from_int_to_decimal(numb_1, &number_1);
  s21_from_int_to_decimal(numb_2, &number_2);
  ck_assert_int_eq(s21_is_greater(number_1, number_2), result);
}
END_TEST

START_TEST(is_greater_3) {
  int numb_1 = -345432521;
  int numb_2 = 345432521;
  int result = 0;
  s21_decimal number_1 = {0};
  s21_decimal number_2 = {0};
  s21_from_int_to_decimal(numb_1, &number_1);
  s21_from_int_to_decimal(numb_2, &number_2);
  ck_assert_int_eq(s21_is_greater(number_1, number_2), result);
}
END_TEST

START_TEST(is_greater_4) {
  int numb_1 = 345432521;
  int numb_2 = -345432521;
  int result = 1;
  s21_decimal number_1 = {0};
  s21_decimal number_2 = {0};
  s21_from_int_to_decimal(numb_1, &number_1);
  s21_from_int_to_decimal(numb_2, &number_2);
  ck_assert_int_eq(s21_is_greater(number_1, number_2), result);
}
END_TEST

START_TEST(is_greater_5) {
  int numb_1 = 345432520;
  int numb_2 = 345432521;
  int result = 0;
  s21_decimal number_1 = {0};
  s21_decimal number_2 = {0};
  s21_from_int_to_decimal(numb_1, &number_1);
  s21_from_int_to_decimal(numb_2, &number_2);
  ck_assert_int_eq(s21_is_greater(number_1, number_2), result);
}
END_TEST

START_TEST(is_greater_7) {
  int numb_1 = -345432520;
  int numb_2 = -345432521;
  int result = 1;
  s21_decimal number_1 = {0};
  s21_decimal number_2 = {0};
  s21_from_int_to_decimal(numb_1, &number_1);
  s21_from_int_to_decimal(numb_2, &number_2);
  ck_assert_int_eq(s21_is_greater(number_1, number_2), result);
}
END_TEST

START_TEST(is_greater_8) {
  int result = 1;
  s21_decimal number_1 = {{2, 0, 0, 0}};
  setExponent(&number_1, 27);
  s21_decimal number_2 = {{3, 0, 0, 0}};
  setExponent(&number_2, 28);
  ck_assert_int_eq(s21_is_greater(number_1, number_2), result);
}
END_TEST

START_TEST(is_greater_9) {
  int result = 0;
  s21_decimal number_1 = {{2, 0, 0, 0}};
  setExponent(&number_1, 27);
  setSign_To_Neg(&number_1);
  s21_decimal number_2 = {{3, 0, 0, 0}};
  setExponent(&number_2, 28);
  ck_assert_int_eq(s21_is_greater(number_1, number_2), result);
}
END_TEST

START_TEST(is_greater_10) {
  int result = 1;
  s21_decimal number_1 = {{3294967295, 4294967295, 4294967290, 0}};
  setExponent(&number_1, 17);
  s21_decimal number_2 = {{4294967295, 4294967295, 4294967295, 0}};
  setExponent(&number_2, 28);
  ck_assert_int_eq(s21_is_greater(number_1, number_2), result);
}
END_TEST

START_TEST(is_greater_11) {
  int result = 0;
  s21_decimal number_1 = {{3294967295, 4294967295, 4294967290, 0}};
  setExponent(&number_1, 17);
  setSign_To_Neg(&number_1);
  s21_decimal number_2 = {{4294967295, 4294967295, 4294967295, 0}};
  setExponent(&number_2, 28);
  setSign_To_Neg(&number_2);
  ck_assert_int_eq(s21_is_greater(number_1, number_2), result);
}
END_TEST

START_TEST(is_greater_12) {
  int result = 0;
  s21_decimal number_1 = {{3294967295, 0, 0, 0}};
  setExponent(&number_1, 5);
  setSign_To_Neg(&number_1);
  s21_decimal number_2 = {{32949672, 0, 0, 0}};
  setExponent(&number_2, 3);
  setSign_To_Neg(&number_2);
  ck_assert_int_eq(s21_is_greater(number_1, number_2), result);
}
END_TEST

START_TEST(sub_1) {
  int numb1 = 2147483645;  // 1399999999
  int numb2 = -2147483645;
  s21_decimal number_1 = {0};
  s21_decimal number_2 = {0};
  s21_decimal number_3 = {0};
  s21_decimal number_4 = {0};
  s21_decimal number_5 = {0};
  s21_decimal number_6 = {0};
  s21_decimal result_3 = {{4294967290, 0, 0, 0}};
  s21_decimal result_4 = {{2147483640, 1, 0, 0}};
  s21_decimal result_5 = {{4294967290, 0, 0, 0}};
  s21_decimal result_6 = {{2147483645, 0, 0, 0}};

  s21_from_int_to_decimal(numb1, &number_1);
  s21_from_int_to_decimal(numb2, &number_2);

  s21_sub(number_1, number_2, &number_3);
  s21_sub(number_3, number_2, &number_4);
  s21_sub(number_4, number_1, &number_5);
  s21_sub(number_5, number_1, &number_6);
  ck_assert_int_eq(number_3.bits[0], result_3.bits[0]);
  ck_assert_int_eq(number_3.bits[1], result_3.bits[1]);
  // ck_assert_int_eq(number_4.bits[0], result_4.bits[0]);
  ck_assert_int_eq(number_4.bits[1], result_4.bits[1]);
  ck_assert_int_eq(number_5.bits[0], result_5.bits[0]);
  ck_assert_int_eq(number_5.bits[1], result_5.bits[1]);
  ck_assert_int_eq(number_6.bits[0], result_6.bits[0]);
  ck_assert_int_eq(number_6.bits[1], result_6.bits[1]);
}
END_TEST

START_TEST(sub_2) {
  int numb1 = -2147483645;  // 1399999999
  int numb2 = 2147483645;
  s21_decimal number_1 = {0};
  s21_decimal number_2 = {0};
  s21_decimal number_3 = {0};
  s21_decimal number_4 = {0};
  s21_decimal number_5 = {0};
  s21_decimal number_6 = {0};
  s21_decimal number_7 = {0};
  s21_decimal number_0 = {{1147483645, 0, 0, 0}};
  s21_decimal result_3 = {{4294967290, 0, 0, 2147483648}};
  s21_decimal result_4 = {{2147483645, 0, 0, 2147483648}};
  s21_decimal result_5 = {{0, 0, 0, 2147483648}};
  s21_decimal result_6 = {{2147483645, 0, 0, 0}};
  s21_decimal result_7 = {{1000000000, 0, 0, 2147483648}};

  s21_from_int_to_decimal(numb1, &number_1);
  s21_from_int_to_decimal(numb2, &number_2);

  s21_sub(number_1, number_2, &number_3);
  s21_sub(number_3, number_1, &number_4);
  s21_sub(number_4, number_1, &number_5);
  s21_sub(number_5, number_1, &number_6);
  s21_sub(number_0, number_6, &number_7);
  ck_assert_int_eq(number_3.bits[0], result_3.bits[0]);
  ck_assert_int_eq(number_3.bits[1], result_3.bits[1]);
  ck_assert_int_eq(number_4.bits[0], result_4.bits[0]);
  ck_assert_int_eq(number_4.bits[1], result_4.bits[1]);
  ck_assert_int_eq(number_5.bits[0], result_5.bits[0]);
  ck_assert_int_eq(number_5.bits[1], result_5.bits[1]);
  ck_assert_int_eq(number_6.bits[0], result_6.bits[0]);
  ck_assert_int_eq(number_6.bits[1], result_6.bits[1]);
  ck_assert_int_eq(number_7.bits[0], result_7.bits[0]);
  ck_assert_int_eq(number_7.bits[1], result_7.bits[1]);
}
END_TEST

START_TEST(sub_3) {
  s21_decimal number_3 = {0};
  s21_decimal number_1 = {{4294967295, 4294967295, 4294967295, 0}};
  s21_decimal number_2 = {{2000, 0, 0, 2147483648}};
  int a = s21_sub(number_1, number_2, &number_3);
  s21_decimal number_6 = {0};
  s21_decimal number_4 = {{4294967295, 4294967295, 4294967295, 2147483648}};
  s21_decimal number_5 = {{2000, 0, 0, 0}};
  int b = s21_sub(number_4, number_5, &number_6);

  ck_assert_int_eq(a, 1);
  ck_assert_int_eq(b, 2);
}
END_TEST

START_TEST(sub_4) {
  float numb1 = 2361.44444;
  float numb2 = 21.33333;
  float a = 0;
  s21_decimal number_3 = {0};
  s21_decimal number_1 = {0};
  s21_decimal number_2 = {0};
  s21_from_float_to_decimal(numb1, &number_1);
  s21_from_float_to_decimal(numb2, &number_2);
  s21_sub(number_1, number_2, &number_3);
  s21_decimal result_3 = {{234011107, 0, 0, 8650752}};
  s21_from_decimal_to_float(number_3, &a);

  ck_assert_int_eq(number_3.bits[0], result_3.bits[0]);
  ck_assert_int_eq(number_3.bits[1], result_3.bits[1]);
  ck_assert_int_eq(number_3.bits[2], result_3.bits[2]);
  // ck_assert_int_eq(number_3.bits[3], result_3.bits[3]);
  ck_assert_float_eq(a, 2340.111084);
}
END_TEST

START_TEST(add_1) {
  int numb1 = 2147483645;  // 1399999999
  int numb2 = -2147483645;
  s21_decimal number_1 = {0};
  s21_decimal number_2 = {0};
  s21_decimal number_3 = {0};
  s21_decimal number_4 = {0};
  s21_decimal number_5 = {0};
  s21_decimal number_6 = {0};
  s21_decimal result_3 = {{0, 0, 0, 0}};
  s21_decimal result_4 = {{2147483645, 0, 0, 0}};
  s21_decimal result_5 = {{4294967290, 0, 0, 0}};
  s21_decimal result_6 = {{2147483640, 1, 0, 0}};

  s21_from_int_to_decimal(numb1, &number_1);
  s21_from_int_to_decimal(numb2, &number_2);

  s21_add(number_1, number_2, &number_3);
  s21_add(number_3, number_1, &number_4);
  s21_add(number_4, number_1, &number_5);
  s21_add(number_5, number_1, &number_6);
  ck_assert_int_eq(number_3.bits[0], result_3.bits[0]);
  ck_assert_int_eq(number_3.bits[1], result_3.bits[1]);
  ck_assert_int_eq(number_4.bits[0], result_4.bits[0]);
  ck_assert_int_eq(number_4.bits[1], result_4.bits[1]);
  ck_assert_int_eq(number_5.bits[0], result_5.bits[0]);
  ck_assert_int_eq(number_5.bits[1], result_5.bits[1]);
  // ck_assert_int_eq(number_6.bits[0], result_6.bits[0]);
  ck_assert_int_eq(number_6.bits[1], result_6.bits[1]);
}
END_TEST

START_TEST(add_3) {
  s21_decimal number_3 = {0};
  s21_decimal number_1 = {{4294967295, 4294967295, 4294967295, 0}};
  s21_decimal number_2 = {{2000, 0, 0, 0}};
  int a = s21_add(number_1, number_2, &number_3);
  s21_decimal number_6 = {0};
  s21_decimal number_4 = {{4294967295, 4294967295, 4294967295, 2147483648}};
  s21_decimal number_5 = {{2000, 0, 0, 2147483648}};
  int b = s21_add(number_4, number_5, &number_6);

  ck_assert_int_eq(a, 1);
  ck_assert_int_eq(b, 2);
}
END_TEST

START_TEST(add_4) {
  float numb1 = 2361.44444;
  float numb2 = 21.33333;
  float a = 0;
  float b = 2382.7778;
  s21_decimal number_3 = {0};
  s21_decimal number_1 = {0};
  s21_decimal number_2 = {0};
  s21_from_float_to_decimal(numb1, &number_1);
  s21_from_float_to_decimal(numb2, &number_2);
  s21_add(number_1, number_2, &number_3);
  s21_decimal result_3 = {{238277773, 0, 0, 8650752}};
  s21_from_decimal_to_float(number_3, &a);

  ck_assert_int_eq(number_3.bits[0], result_3.bits[0]);
  ck_assert_int_eq(number_3.bits[1], result_3.bits[1]);
  ck_assert_int_eq(number_3.bits[2], result_3.bits[2]);
  // ck_assert_int_eq(number_3.bits[3], result_3.bits[3]);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(is_less_1) {
  int numb_1 = -345432521;
  int numb_2 = -345432521;
  int result = 0;
  s21_decimal number_1 = {0};
  s21_decimal number_2 = {0};
  s21_from_int_to_decimal(numb_1, &number_1);
  s21_from_int_to_decimal(numb_2, &number_2);
  ck_assert_int_eq(s21_is_less(number_1, number_2), result);
  ck_assert_int_eq(s21_is_less_or_equal(number_1, number_2), !result);
}
END_TEST

START_TEST(is_less_2) {
  int numb_1 = 345432550;
  int numb_2 = 345432521;
  int result = 0;
  s21_decimal number_1 = {0};
  s21_decimal number_2 = {0};
  s21_from_int_to_decimal(numb_1, &number_1);
  s21_from_int_to_decimal(numb_2, &number_2);
  ck_assert_int_eq(s21_is_less(number_1, number_2), result);
  ck_assert_int_eq(s21_is_less_or_equal(number_1, number_2), result);
}
END_TEST

START_TEST(is_less_3) {
  int numb_1 = -345432521;
  int numb_2 = 345432521;
  int result = 1;
  s21_decimal number_1 = {0};
  s21_decimal number_2 = {0};
  s21_from_int_to_decimal(numb_1, &number_1);
  s21_from_int_to_decimal(numb_2, &number_2);
  ck_assert_int_eq(s21_is_less(number_1, number_2), result);
  ck_assert_int_eq(s21_is_less_or_equal(number_1, number_2), result);
}
END_TEST

START_TEST(is_less_4) {
  int numb_1 = 345432521;
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

START_TEST(is_less_5) {
  int numb_1 = 345432521;
  int numb_2 = 345432521;
  int result = 0;
  s21_decimal number_1 = {0};
  s21_decimal number_2 = {0};
  s21_from_int_to_decimal(numb_1, &number_1);
  s21_from_int_to_decimal(numb_2, &number_2);
  ck_assert_int_eq(s21_is_less(number_1, number_2), result);
  ck_assert_int_eq(s21_is_less_or_equal(number_1, number_2), !result);
}
END_TEST

START_TEST(is_less_7) {
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

START_TEST(is_less_8) {
  int result = 0;
  s21_decimal number_1 = {{2, 0, 0, 0}};
  setExponent(&number_1, 27);
  s21_decimal number_2 = {{3, 0, 0, 0}};
  setExponent(&number_2, 28);
  ck_assert_int_eq(s21_is_less(number_1, number_2), result);
  ck_assert_int_eq(s21_is_less_or_equal(number_1, number_2), result);
}
END_TEST

START_TEST(is_less_9) {
  int result = 1;
  s21_decimal number_1 = {{2, 0, 0, 0}};
  setExponent(&number_1, 27);
  setSign_To_Neg(&number_1);
  s21_decimal number_2 = {{3, 0, 0, 0}};
  setExponent(&number_2, 28);
  ck_assert_int_eq(s21_is_less(number_1, number_2), result);
  ck_assert_int_eq(s21_is_less_or_equal(number_1, number_2), 1);
}
END_TEST

START_TEST(is_less_10) {
  int result = 0;
  s21_decimal number_1 = {{3294967295, 4294967295, 4294967290, 0}};
  setExponent(&number_1, 17);
  s21_decimal number_2 = {{4294967295, 4294967295, 4294967295, 0}};
  setExponent(&number_2, 28);
  ck_assert_int_eq(s21_is_less(number_1, number_2), result);
  ck_assert_int_eq(s21_is_less_or_equal(number_1, number_2), result);
}
END_TEST

START_TEST(is_less_11) {
  int result = 1;
  s21_decimal number_1 = {{3294967295, 4294967295, 4294967290, 0}};
  setExponent(&number_1, 17);
  setSign_To_Neg(&number_1);
  s21_decimal number_2 = {{4294967295, 4294967295, 4294967295, 0}};
  setExponent(&number_2, 28);
  setSign_To_Neg(&number_2);
  ck_assert_int_eq(s21_is_less(number_1, number_2), result);
  ck_assert_int_eq(s21_is_less_or_equal(number_1, number_2), result);
}
END_TEST

START_TEST(is_less_12) {
  int result = 1;
  s21_decimal number_1 = {{3294967295, 0, 0, 0}};
  setExponent(&number_1, 5);
  setSign_To_Neg(&number_1);
  s21_decimal number_2 = {{32949672, 0, 0, 0}};
  setExponent(&number_2, 3);
  setSign_To_Neg(&number_2);
  ck_assert_int_eq(s21_is_less(number_1, number_2), result);
  ck_assert_int_eq(s21_is_less_or_equal(number_1, number_2), result);
}
END_TEST

START_TEST(is_less_13) {
  int result = 0;
  s21_decimal number_1 = {{32949672, 0, 0, 0}};
  setExponent(&number_1, 3);
  setSign_To_Neg(&number_1);
  s21_decimal number_2 = {{32949672, 0, 0, 0}};
  setExponent(&number_2, 3);
  setSign_To_Neg(&number_2);
  ck_assert_int_eq(s21_is_less(number_1, number_2), result);
  ck_assert_int_eq(s21_is_less_or_equal(number_1, number_2), 1);
}
END_TEST

START_TEST(is_div_1) {
  s21_decimal number_1 = {{4294967295, 4294967295, 4294967295, 0}};
  setExponent(&number_1, 20);
  s21_decimal number_2 = {{2, 0, 0, 0}};
  s21_decimal number_3 = {0};
  s21_decimal result = {0};

  s21_div(number_1, number_2, &number_3);
  ck_assert_int_eq(number_3.bits[0], result.bits[0]);
  ck_assert_int_eq(number_3.bits[1], result.bits[1]);
  // ck_assert_int_eq(number_3.bits[2], result.bits[2]);
  // ck_assert_int_eq(number_3.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_add_isabeler) {
  s21_decimal src1, src2;
  int a_int = -1234;
  float b_float = 1.234;
  float a_float;
  int b_int;
  float res_our_dec;
  s21_from_int_to_decimal(a_int, &src1);
  s21_from_float_to_decimal(b_float, &src2);
  float res_origin = -1232.766;
  s21_decimal res_od;
  s21_add(src1, src2, &res_od);
  s21_from_decimal_to_float(res_od, &res_our_dec);
  ck_assert_float_eq(res_our_dec, res_origin);

  a_int = -1234;
  b_float = -1.234;
  s21_from_int_to_decimal(a_int, &src1);
  s21_from_float_to_decimal(b_float, &src2);
  res_origin = -1235.234;
  s21_add(src1, src2, &res_od);
  s21_from_decimal_to_float(res_od, &res_our_dec);
  ck_assert_float_eq(res_our_dec, res_origin);

  a_float = -1234;
  b_float = -221.234;
  s21_from_float_to_decimal(a_float, &src1);
  s21_from_float_to_decimal(b_float, &src2);
  res_origin = -1455.234;
  s21_add(src1, src2, &res_od);
  s21_from_decimal_to_float(res_od, &res_our_dec);
  ck_assert_float_eq(res_our_dec, res_origin);

  a_float = -9403;
  b_float = 0.00234;
  s21_from_float_to_decimal(a_float, &src1);
  s21_from_float_to_decimal(b_float, &src2);
  res_origin = -9402.99766;
  s21_add(src1, src2, &res_od);
  s21_from_decimal_to_float(res_od, &res_our_dec);
  ck_assert_float_eq(res_our_dec, res_origin);

  a_int = -1234;
  b_float = -221.234;
  s21_from_float_to_decimal(a_int, &src1);
  s21_from_float_to_decimal(b_float, &src2);
  res_origin = -1455.234;
  s21_add(src1, src2, &res_od);
  s21_from_decimal_to_float(res_od, &res_our_dec);
  ck_assert_float_eq(res_our_dec, res_origin);

  a_int = -9403;
  b_int = 234;
  int res_our_dec_int = 0;
  s21_from_int_to_decimal(a_int, &src1);
  s21_from_int_to_decimal(b_int, &src2);
  int res_origin_int = -9169;
  s21_add(src1, src2, &res_od);
  s21_from_decimal_to_int(res_od, &res_our_dec_int);
  ck_assert_int_eq(res_our_dec_int, res_origin_int);

  a_float = -940.3;
  b_float = 0.000234;
  s21_from_float_to_decimal(a_float, &src1);
  s21_from_float_to_decimal(b_float, &src2);
  res_origin = -940.299766;
  s21_add(src1, src2, &res_od);
  s21_from_decimal_to_float(res_od, &res_our_dec);
  ck_assert_float_eq(res_our_dec, res_origin);

  a_float = -0.9403;
  b_float = 0.000234;
  s21_from_float_to_decimal(a_float, &src1);
  s21_from_float_to_decimal(b_float, &src2);
  res_origin = -0.940066;
  s21_add(src1, src2, &res_od);
  s21_from_decimal_to_float(res_od, &res_our_dec);
  ck_assert_float_eq(res_our_dec, res_origin);

  a_float = -0.9403;
  b_float = 2.0234;
  res_origin = 1.0831;
  s21_from_float_to_decimal(a_float, &src1);
  s21_from_float_to_decimal(b_float, &src2);
  s21_add(src1, src2, &res_od);
  s21_from_decimal_to_float(res_od, &res_our_dec);
  ck_assert_float_eq(res_our_dec, res_origin);

  a_float = -0.94e03;
  b_float = -112.0e2;
  s21_from_float_to_decimal(a_float, &src1);
  s21_from_float_to_decimal(b_float, &src2);
  res_origin = -12140;
  s21_add(src1, src2, &res_od);
  s21_from_decimal_to_float(res_od, &res_our_dec);
  ck_assert_float_eq(res_our_dec, res_origin);

  a_int = 9403;
  b_int = 202;
  res_origin_int = 9605;
  s21_from_int_to_decimal(a_int, &src1);
  s21_from_int_to_decimal(b_int, &src2);
  s21_add(src1, src2, &res_od);
  s21_from_decimal_to_int(res_od, &res_our_dec_int);
  ck_assert_int_eq(res_our_dec_int, res_origin_int);

  src1.bits[3] = 0x300000;
  src1.bits[2] = 0;
  src1.bits[1] = 0xF;
  src1.bits[0] = 0x67E4FEEF;
  src2.bits[3] = 0x300000;
  src2.bits[2] = 0;
  src2.bits[1] = 0xFF;
  src2.bits[0] = 0x67E4FFFF;
  s21_decimal result_origin;
  result_origin.bits[3] = 0x300000;
  result_origin.bits[2] = 0;
  result_origin.bits[1] = 0x10E;
  result_origin.bits[0] = 0xCFC9FEEE;
  s21_add(src1, src2, &res_od);
  ck_assert_int_eq(result_origin.bits[3], res_od.bits[3]);
  ck_assert_int_eq(result_origin.bits[2], res_od.bits[2]);
  ck_assert_int_eq(result_origin.bits[1], res_od.bits[1]);
  ck_assert_int_eq(result_origin.bits[0], res_od.bits[0]);

  s21_decimal test_value_1 = {{0, 0, 0, 0}};
  s21_decimal test_value_2 = {{0, 0, 0, 0}};
  s21_decimal result_dec = {{0, 0, 0, 0}};
  int result_int;
  float result_float;

  s21_from_float_to_decimal(1899.999, &test_value_1);
  s21_from_float_to_decimal(100.021, &test_value_2);
  s21_add(test_value_1, test_value_2, &result_dec);
  s21_from_decimal_to_float(result_dec, &result_float);
  ck_assert_float_eq(result_float, 1899.999 + 100.021);

  s21_from_int_to_decimal(-467, &test_value_1);
  s21_from_int_to_decimal(3668, &test_value_2);
  s21_add(test_value_1, test_value_2, &result_dec);
  s21_from_decimal_to_int(result_dec, &result_int);
  ck_assert_int_eq(result_int, -467 + 3668);

  s21_from_int_to_decimal(467, &test_value_1);
  s21_from_int_to_decimal(-3668, &test_value_2);
  s21_add(test_value_1, test_value_2, &result_dec);
  s21_from_decimal_to_int(result_dec, &result_int);
  ck_assert_int_eq(result_int, 467 + (-3668));

  s21_from_int_to_decimal(-199421, &test_value_1);
  s21_from_int_to_decimal(4433, &test_value_2);
  s21_add(test_value_1, test_value_2, &result_dec);
  s21_from_decimal_to_int(result_dec, &result_int);
  ck_assert_int_eq(result_int, -199421 + 4433);

  s21_from_int_to_decimal(199421, &test_value_1);
  s21_from_int_to_decimal(-4433, &test_value_2);
  s21_add(test_value_1, test_value_2, &result_dec);
  s21_from_decimal_to_int(result_dec, &result_int);
  ck_assert_int_eq(result_int, 199421 + (-4433));

  s21_from_int_to_decimal(1899999, &test_value_1);
  s21_from_int_to_decimal(100001, &test_value_2);
  s21_add(test_value_1, test_value_2, &result_dec);
  s21_from_decimal_to_int(result_dec, &result_int);
  ck_assert_int_eq(result_int, 2000000);

  s21_from_int_to_decimal(-199421, &test_value_1);
  s21_from_int_to_decimal((-4433), &test_value_2);
  s21_add(test_value_1, test_value_2, &result_dec);
  s21_from_decimal_to_int(result_dec, &result_int);
  ck_assert_int_eq(result_int, (-199421) + (-4433));

  s21_from_int_to_decimal(467, &test_value_1);
  s21_from_int_to_decimal(3668, &test_value_2);
  s21_add(test_value_1, test_value_2, &result_dec);
  s21_from_decimal_to_int(result_dec, &result_int);
  ck_assert_int_eq(result_int, 467 + 3668);

  s21_from_int_to_decimal(-467, &test_value_1);
  s21_from_int_to_decimal(-3668, &test_value_2);
  s21_add(test_value_1, test_value_2, &result_dec);
  s21_from_decimal_to_int(result_dec, &result_int);
  ck_assert_int_eq(result_int, (-467) + (-3668));

  s21_decimal a_dec, b_dec, res_dec;
  int ret, res_int;
  float res_fl;

  for (int i = 0; i < 1000; i++) {
    s21_from_int_to_decimal(i, &a_dec);
    s21_from_int_to_decimal(1000 - i, &b_dec);
    ret = s21_add(a_dec, b_dec, &res_dec);
    s21_from_decimal_to_int(res_dec, &res_int);
    ck_assert_int_eq(ret, 0);
    ck_assert_int_eq(res_int, 1000);
  }

  zeroDefDecimal(&a_dec);
  for (int i = 0; i < 96; i++) {
    setBitDecimalOne(a_dec.bits, i);
  }
  ret = s21_add(a_dec, b_dec, &res_dec);
  ck_assert_int_eq(ret, 1);

  setSign_To_Neg(&a_dec);
  setSign_To_Neg(&b_dec);
  ret = s21_add(a_dec, b_dec, &res_dec);
  ck_assert_int_eq(ret, 2);

  s21_from_float_to_decimal(1.5787, &a_dec);
  s21_from_float_to_decimal(451.577, &b_dec);
  ret = s21_add(a_dec, b_dec, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_fl);
  ck_assert_float_eq(res_fl, 1.5787 + 451.577);

  zeroDefDecimal(&a_dec);
  for (int i = 0; i < 96; i++) {
    setBitDecimalOne(a_dec.bits, i);
  }
  s21_from_float_to_decimal(0.8, &b_dec);
  ret = s21_add(a_dec, b_dec, &res_dec);
  ck_assert_int_eq(28, getExponent(res_dec));
  ck_assert_int_eq(ret, 1);

  zeroDefDecimal(&a_dec);
  for (int i = 0; i < 96; i++) {
    setBitDecimalOne(a_dec.bits, i);
  }
  s21_from_float_to_decimal(0.3, &b_dec);
  ret = s21_add(a_dec, b_dec, &res_dec);
  ck_assert_int_eq(ret, 0);
  ck_assert_int_eq(getExponent(a_dec), getExponent(res_dec));
}
END_TEST

START_TEST(test_sub_isabeler) {
  s21_decimal src1, src2;
  int a_int = 9403;
  int b_int = 202;
  int res_our_dec_int;
  s21_from_int_to_decimal(a_int, &src1);
  s21_from_int_to_decimal(b_int, &src2);
  int res_origin_int = 9201;
  s21_decimal res_od;
  s21_sub(src1, src2, &res_od);
  s21_from_decimal_to_int(res_od, &res_our_dec_int);
  ck_assert_int_eq(res_our_dec_int, res_origin_int);

  a_int = 9403;
  float b_float = 202.098;
  float res_our_dec_float = 0.0;
  s21_from_int_to_decimal(a_int, &src1);
  s21_from_float_to_decimal(b_float, &src2);
  float res_origin_float = 9200.902;
  s21_sub(src1, src2, &res_od);
  s21_from_decimal_to_float(res_od, &res_our_dec_float);
  ck_assert_float_eq(res_our_dec_float, res_origin_float);

  float a_float = -9403;
  b_float = 202.098;
  s21_from_float_to_decimal(a_float, &src1);
  s21_from_float_to_decimal(b_float, &src2);
  res_origin_float = a_float - b_float;
  s21_sub(src1, src2, &res_od);
  s21_from_decimal_to_float(res_od, &res_our_dec_float);
  ck_assert_float_eq(res_our_dec_float, res_origin_float);

  a_float = -94;
  b_float = -202;
  s21_from_float_to_decimal(a_float, &src1);
  s21_from_float_to_decimal(b_float, &src2);
  res_origin_float = a_float - b_float;
  s21_sub(src1, src2, &res_od);
  s21_from_decimal_to_float(res_od, &res_our_dec_float);
  ck_assert_float_eq(res_our_dec_float, res_origin_float);

  src1.bits[3] = 0x30000;
  src1.bits[2] = 0;
  src1.bits[1] = 0xFFFF;
  src1.bits[0] = 0xFF837E4F;
  src2.bits[3] = 0x80070000;
  src2.bits[2] = 0;
  src2.bits[1] = 0xFFF;
  src2.bits[0] = 0xFF837E4F;
  s21_decimal result_origin, result_our;
  result_origin.bits[3] = 0x70000;
  result_origin.bits[2] = 0;
  result_origin.bits[1] = 0x27100FEC;
  result_origin.bits[0] = 0xFFF96C3F;
  s21_sub(src1, src2, &result_our);
  ck_assert_int_eq(result_origin.bits[2], result_our.bits[2]);
  ck_assert_int_eq(result_origin.bits[1], result_our.bits[1]);
  ck_assert_int_eq(result_origin.bits[0], result_our.bits[0]);

  s21_decimal test_value_1 = {{0, 0, 0, 0}};
  s21_decimal test_value_2 = {{0, 0, 0, 0}};
  s21_decimal result_dec = {{0, 0, 0, 0}};
  int result_int;
  s21_from_int_to_decimal(1899999, &test_value_1);
  s21_from_int_to_decimal(100001, &test_value_2);
  s21_sub(test_value_1, test_value_2, &result_dec);
  s21_from_decimal_to_int(result_dec, &result_int);
  ck_assert_int_eq(result_int, 1899999 - 100001);

  s21_from_int_to_decimal(1899999, &test_value_1);
  s21_from_int_to_decimal(-100001, &test_value_2);
  s21_sub(test_value_1, test_value_2, &result_dec);
  s21_from_decimal_to_int(result_dec, &result_int);
  ck_assert_int_eq(result_int, 1899999 - (-100001));

  s21_from_int_to_decimal(-1899999, &test_value_1);
  s21_from_int_to_decimal(100001, &test_value_2);
  s21_sub(test_value_1, test_value_2, &result_dec);
  s21_from_decimal_to_int(result_dec, &result_int);
  ck_assert_int_eq(result_int, (-1899999) - 100001);

  s21_from_int_to_decimal(-1899999, &test_value_1);
  s21_from_int_to_decimal(-100001, &test_value_2);
  s21_sub(test_value_1, test_value_2, &result_dec);
  s21_from_decimal_to_int(result_dec, &result_int);
  ck_assert_int_eq(result_int, (-1899999) - (-100001));

  s21_from_int_to_decimal(1994214, &test_value_1);
  s21_from_int_to_decimal(77443333, &test_value_2);
  s21_sub(test_value_1, test_value_2, &result_dec);
  s21_from_decimal_to_int(result_dec, &result_int);
  ck_assert_int_eq(result_int, 1994214 - 77443333);

  s21_from_int_to_decimal(1994214, &test_value_1);
  s21_from_int_to_decimal(-77443333, &test_value_2);
  s21_sub(test_value_1, test_value_2, &result_dec);
  s21_from_decimal_to_int(result_dec, &result_int);
  ck_assert_int_eq(result_int, 1994214 - (-77443333));

  s21_from_int_to_decimal(-1994214, &test_value_1);
  s21_from_int_to_decimal(77443333, &test_value_2);
  s21_sub(test_value_1, test_value_2, &result_dec);
  s21_from_decimal_to_int(result_dec, &result_int);
  ck_assert_int_eq(result_int, -1994214 - 77443333);

  s21_from_int_to_decimal(-1994214, &test_value_1);
  s21_from_int_to_decimal(-77443333, &test_value_2);
  s21_sub(test_value_1, test_value_2, &result_dec);
  s21_from_decimal_to_int(result_dec, &result_int);
  ck_assert_int_eq(result_int, (-1994214) - (-77443333));

  s21_from_int_to_decimal(19999445, &test_value_1);
  s21_from_int_to_decimal(6, &test_value_2);
  s21_sub(test_value_1, test_value_2, &result_dec);
  s21_from_decimal_to_int(result_dec, &result_int);
  ck_assert_int_eq(result_int, 19999445 - 6);

  float result_float;
  s21_from_float_to_decimal(1899.999, &test_value_1);
  s21_from_float_to_decimal(100.021, &test_value_2);
  s21_sub(test_value_1, test_value_2, &result_dec);
  s21_from_decimal_to_float(result_dec, &result_float);
  ck_assert_float_eq(result_float, 1899.999 - 100.021);
}
END_TEST

START_TEST(test_mul_isabeler) {
  s21_decimal src1, src2;
  float a_float = 9403.0e2;
  int b_int = 202;
  float res_our_dec_float;
  s21_from_float_to_decimal(a_float, &src1);
  s21_from_int_to_decimal(b_int, &src2);
  float res_origin_float = 189940600;
  s21_decimal res_od;
  s21_mul(src1, src2, &res_od);
  s21_from_decimal_to_float(res_od, &res_our_dec_float);
  ck_assert_float_eq(res_our_dec_float, res_origin_float);

  a_float = 9403.0e2;
  float b_float = 9403.0e2;
  s21_from_float_to_decimal(a_float, &src1);
  s21_from_float_to_decimal(b_float, &src2);
  res_origin_float = 884164090000;
  s21_mul(src1, src2, &res_od);
  s21_from_decimal_to_float(res_od, &res_our_dec_float);
  ck_assert_float_eq(res_our_dec_float, res_origin_float);

  int a_int = 9403;
  b_int = 202;
  int res_our_dec_int;
  s21_from_int_to_decimal(a_int, &src1);
  s21_from_int_to_decimal(b_int, &src2);
  int res_origin_int = 1899406;
  s21_mul(src1, src2, &res_od);
  s21_from_decimal_to_int(res_od, &res_our_dec_int);
  ck_assert_int_eq(res_our_dec_int, res_origin_int);

  s21_decimal test_value_1 = {{0, 0, 0, 0}};
  s21_decimal test_value_2 = {{0, 0, 0, 0}};
  s21_decimal result_dec = {{0, 0, 0, 0}};

  int result_int;
  s21_from_int_to_decimal(18999, &test_value_1);
  s21_from_int_to_decimal(1001, &test_value_2);
  s21_mul(test_value_1, test_value_2, &result_dec);
  s21_from_decimal_to_int(result_dec, &result_int);
  ck_assert_int_eq(result_int, (18999 * 1001));

  s21_from_int_to_decimal(18999, &test_value_1);
  s21_from_int_to_decimal(-1001, &test_value_2);
  s21_mul(test_value_1, test_value_2, &result_dec);
  s21_from_decimal_to_int(result_dec, &result_int);
  ck_assert_int_eq(result_int, (18999 * (-1001)));

  s21_from_int_to_decimal(-18999, &test_value_1);
  s21_from_int_to_decimal(1001, &test_value_2);
  s21_mul(test_value_1, test_value_2, &result_dec);
  s21_from_decimal_to_int(result_dec, &result_int);
  ck_assert_int_eq(result_int, (-18999 * 1001));

  s21_from_int_to_decimal(-18999, &test_value_1);
  s21_from_int_to_decimal(-1001, &test_value_2);
  s21_mul(test_value_1, test_value_2, &result_dec);
  s21_from_decimal_to_int(result_dec, &result_int);
  ck_assert_int_eq(result_int, ((-18999) * (-1001)));

  s21_from_int_to_decimal(191, &test_value_1);
  s21_from_int_to_decimal(57443, &test_value_2);
  s21_mul(test_value_1, test_value_2, &result_dec);
  s21_from_decimal_to_int(result_dec, &result_int);
  ck_assert_int_eq(result_int, 191 * 57443);

  s21_from_int_to_decimal(191, &test_value_1);
  s21_from_int_to_decimal(-57443, &test_value_2);
  s21_mul(test_value_1, test_value_2, &result_dec);
  s21_from_decimal_to_int(result_dec, &result_int);
  ck_assert_int_eq(result_int, 191 * (-57443));

  s21_from_int_to_decimal(-191, &test_value_1);
  s21_from_int_to_decimal(57443, &test_value_2);
  s21_mul(test_value_1, test_value_2, &result_dec);
  s21_from_decimal_to_int(result_dec, &result_int);
  ck_assert_int_eq(result_int, -191 * 57443);

  s21_from_int_to_decimal(-191, &test_value_1);
  s21_from_int_to_decimal(-57443, &test_value_2);
  s21_mul(test_value_1, test_value_2, &result_dec);
  s21_from_decimal_to_int(result_dec, &result_int);
  ck_assert_int_eq(result_int, ((-191) * (-57443)));

  float result_float;
  s21_from_float_to_decimal(1899.999, &test_value_1);
  s21_from_float_to_decimal(100.001, &test_value_2);
  s21_mul(test_value_1, test_value_2, &result_dec);
  s21_from_decimal_to_float(result_dec, &result_float);
  ck_assert_int_eq(result_float, 1899.999 * 100.001);
}
END_TEST

Suite *test_a(void) {
  Suite *s;
  TCase *tc_bin;

  s = suite_create("Aqualadt");
  tc_bin = tcase_create("Bin");

  tcase_add_test(tc_bin, is_equal_1);
  tcase_add_test(tc_bin, is_equal_2);
  tcase_add_test(tc_bin, is_equal_3);
  tcase_add_test(tc_bin, is_equal_4);
  tcase_add_test(tc_bin, is_equal_5);
  tcase_add_test(tc_bin, is_equal_6);

  tcase_add_test(tc_bin, is_greater_1);
  tcase_add_test(tc_bin, is_greater_2);
  tcase_add_test(tc_bin, is_greater_3);
  tcase_add_test(tc_bin, is_greater_4);
  tcase_add_test(tc_bin, is_greater_5);
  //  tcase_add_test(tc_bin, is_greater_6);
  tcase_add_test(tc_bin, is_greater_7);
  tcase_add_test(tc_bin, is_greater_8);
  tcase_add_test(tc_bin, is_greater_9);
  tcase_add_test(tc_bin, is_greater_10);
  tcase_add_test(tc_bin, is_greater_11);
  tcase_add_test(tc_bin, is_greater_12);

  tcase_add_test(tc_bin, is_less_1);
  tcase_add_test(tc_bin, is_less_2);
  tcase_add_test(tc_bin, is_less_3);
  tcase_add_test(tc_bin, is_less_4);
  tcase_add_test(tc_bin, is_less_5);
  tcase_add_test(tc_bin, is_less_7);
  tcase_add_test(tc_bin, is_less_8);
  tcase_add_test(tc_bin, is_less_9);
  tcase_add_test(tc_bin, is_less_10);
  tcase_add_test(tc_bin, is_less_11);
  tcase_add_test(tc_bin, is_less_12);
  tcase_add_test(tc_bin, is_less_13);

  tcase_add_test(tc_bin, sub_1);
  tcase_add_test(tc_bin, sub_2);
  tcase_add_test(tc_bin, sub_3);
  tcase_add_test(tc_bin, sub_4);

  tcase_add_test(tc_bin, test_add_isabeler);

  tcase_add_test(tc_bin, test_sub_isabeler);

  tcase_add_test(tc_bin, test_mul_isabeler);

  tcase_add_test(tc_bin, add_1);
  tcase_add_test(tc_bin, add_3);
  tcase_add_test(tc_bin, add_4);

  tcase_add_test(tc_bin, is_div_1);

  suite_add_tcase(s, tc_bin);

  return s;
}
