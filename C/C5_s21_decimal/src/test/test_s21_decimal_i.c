#include <check.h>
#include <stdio.h>

#include "../s21_decimal.h"
#include "test_s21_decimal.h"

START_TEST(test_sign_function) {
  s21_decimal number_1 = {{15, 0, 0, 0}};
  ck_assert_int_eq(getSign(number_1), 0);
  setSign_To_Neg(&number_1);
  ck_assert_int_eq(getSign(number_1), 1);
  setSign_To_Pos(&number_1);
  ck_assert_int_eq(getSign(number_1), 0);
  setSign_To_Neg(&number_1);
  ck_assert_int_eq(getSign(number_1), getBit(number_1.bits[3], 31));
  setSign_To_Pos(&number_1);
  ck_assert_int_eq(getSign(number_1), getBit(number_1.bits[3], 31));
}
END_TEST

START_TEST(test_getBit_function) {
  s21_decimal number_1 = {{21, 0, 0, 0}};

  ck_assert_int_eq(getBit(number_1.bits[3], 31), 0);
  ck_assert_int_eq(getBit(number_1.bits[0], 31), 0);
  ck_assert_int_eq(getBit(number_1.bits[0], 0), 1);
  ck_assert_int_eq(getBit(number_1.bits[0], 1), 0);
  ck_assert_int_eq(getBit(number_1.bits[0], 4), 1);
}
END_TEST

START_TEST(test_setBit_function) {
  s21_decimal number_1 = {{21, 0, 0, 0}};

  ck_assert_int_eq(getBit(number_1.bits[3], 31), 0);
  setBit_To_Zero(&number_1, 3, 31);
  ck_assert_int_eq(getBit(number_1.bits[3], 31), 0);
  setBit_To_One(&number_1, 3, 31);
  ck_assert_int_eq(getBit(number_1.bits[3], 31), 1);
}
END_TEST

START_TEST(test_resetBit_function) {
  s21_decimal number_1 = {{21, 0, 0, 0}};

  ck_assert_int_eq(number_1.bits[0], 21);
  resetDigit(&number_1, 0);
  ck_assert_int_eq(number_1.bits[0], 0);
}
END_TEST

START_TEST(test_get_set_init_Exponent_function) {
  s21_decimal number_1 = {0};

  ck_assert_int_eq(getExponent(number_1), 0);
  setExponent(&number_1, 32);
  ck_assert_int_eq(getExponent(number_1), 32);
  initExponent(&number_1);
  ck_assert_int_eq(getExponent(number_1), 0);
  setExponent(&number_1, 17);
  ck_assert_int_eq(getExponent(number_1), 17);
  initExponent(&number_1);
  ck_assert_int_eq(getExponent(number_1), 0);
  setExponent(&number_1, 21);
  ck_assert_int_eq(getExponent(number_1), 21);
  initExponent(&number_1);
  ck_assert_int_eq(getExponent(number_1), 0);
}
END_TEST

START_TEST(NULL_DECIMAL) {
  int test_int = 0;
  s21_decimal *decimal = NULL;
  int status = s21_from_int_to_decimal(test_int, decimal);

  ck_assert_int_eq(status, ERROR_CONV);
}
END_TEST

START_TEST(ZERO_INT) {
  int test_int = 0;
  s21_decimal number = {0};
  int status = s21_from_int_to_decimal(test_int, &number);

  ck_assert_int_eq(status, ALLRIGHT_CONV);
  ck_assert_int_eq(test_int, number.bits[0]);
  ck_assert_int_eq(0, number.bits[1]);
  ck_assert_int_eq(0, number.bits[2]);
  ck_assert_int_eq(0, getSign(number));
  ck_assert_int_eq(0, getExponent(number));
}
END_TEST

START_TEST(MAX_INT) {
  int test_int = INT32_MAX;
  s21_decimal number = {0};
  int status = s21_from_int_to_decimal(test_int, &number);

  ck_assert_int_eq(status, ALLRIGHT_CONV);
  ck_assert_int_eq(test_int, number.bits[0]);
  ck_assert_int_eq(0, number.bits[1]);
  ck_assert_int_eq(0, number.bits[2]);
  ck_assert_int_eq(0, getSign(number));
  ck_assert_int_eq(0, getExponent(number));
}
END_TEST

START_TEST(MIN_INT) {
  int test_int = INT32_MIN + 1;
  s21_decimal number = {0};
  int status = s21_from_int_to_decimal(-test_int, &number);

  ck_assert_int_eq(status, ALLRIGHT_CONV);
  ck_assert_int_eq(-test_int, number.bits[0]);
  ck_assert_int_eq(0, number.bits[1]);
  ck_assert_int_eq(0, number.bits[2]);
  ck_assert_int_eq(0, getSign(number));
  ck_assert_int_eq(0, getExponent(number));
}
END_TEST

START_TEST(NEG_INT) {
  int test_int = -204841;
  s21_decimal number = {0};
  int status = s21_from_int_to_decimal(test_int, &number);

  ck_assert_int_eq(status, ALLRIGHT_CONV);
  ck_assert_int_eq(-test_int, number.bits[0]);
  ck_assert_int_eq(0, number.bits[1]);
  ck_assert_int_eq(0, number.bits[2]);
  ck_assert_int_eq(1, getSign(number));
  ck_assert_int_eq(0, getExponent(number));
}
END_TEST

START_TEST(POS_INT) {
  int test_int = 2100842;
  s21_decimal number = {0};
  int status = s21_from_int_to_decimal(test_int, &number);

  ck_assert_int_eq(status, ALLRIGHT_CONV);
  ck_assert_int_eq(test_int, number.bits[0]);
  ck_assert_int_eq(0, number.bits[1]);
  ck_assert_int_eq(0, number.bits[2]);
  ck_assert_int_eq(0, getSign(number));
  ck_assert_int_eq(0, getExponent(number));
}
END_TEST

START_TEST(RANDOM_INT) {
  int get;
  time_t t;
  srand((unsigned)time(&t));

  int test_int = getRandom(0, INT32_MAX);

  if (rand() % 2) test_int = -test_int;

  s21_decimal number = {0};
  int status = s21_from_int_to_decimal(test_int, &number);

  ck_assert_int_eq(status, ALLRIGHT_CONV);
  get = test_int < 0 ? -test_int : test_int;
  ck_assert_int_eq(get, number.bits[0]);
  ck_assert_int_eq(0, number.bits[1]);
  ck_assert_int_eq(0, number.bits[2]);
  if (test_int < 0)
    ck_assert_int_eq(1, getSign(number));
  else
    ck_assert_int_eq(0, getSign(number));
  ck_assert_int_eq(0, getExponent(number));
}
END_TEST

START_TEST(TEST_FLOAT_TO_DECIMAL) {
  float value = 5.9;
  s21_decimal number = {0};
  s21_from_float_to_decimal(value, &number);
  ck_assert_int_eq(value, number.bits[0] / (int)pow(10, getExponent(number)));
  ck_assert_int_eq(0, number.bits[1]);
  ck_assert_int_eq(0, number.bits[2]);
  ck_assert_int_eq(1, getExponent(number));
  ck_assert_int_eq(0, getSign(number));

  value = -21.9999;
  resetDigit(&number, 0);
  s21_from_float_to_decimal(value, &number);
  ck_assert_int_eq(-value, number.bits[0] / pow(10, getExponent(number)));
  ck_assert_int_eq(0, number.bits[1]);
  ck_assert_int_eq(0, number.bits[2]);
  ck_assert_int_eq(4, getExponent(number));
  ck_assert_int_eq(1, getSign(number));

  value = -21.99998;
  resetDigit(&number, 0);
  s21_from_float_to_decimal(value, &number);
  ck_assert_int_eq(-value, number.bits[0] / pow(10, getExponent(number)));
  ck_assert_int_eq(0, number.bits[1]);
  ck_assert_int_eq(0, number.bits[2]);
  ck_assert_int_eq(5, getExponent(number));
  ck_assert_int_eq(1, getSign(number));
}
END_TEST

START_TEST(TEST_FLOAT_TO_DECIMAL_EXTRA_1) {
  float value = -74.6584;
  s21_decimal number = {0};
  s21_from_float_to_decimal(value, &number);
  ck_assert_int_eq(-value, number.bits[0] / pow(10, getExponent(number)));
  ck_assert_int_eq(0, number.bits[1]);
  ck_assert_int_eq(0, number.bits[2]);
  ck_assert_int_eq(4, getExponent(number));
  ck_assert_int_eq(1, getSign(number));
}
END_TEST

// $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

START_TEST(TEST_DECIMAL_TO_INT_NULL) {
  s21_decimal decimal = {{0, 0, 0, 0}};
  int status = s21_from_decimal_to_int(decimal, NULL);

  ck_assert_int_eq(status, ERROR_CONV);
}
END_TEST

START_TEST(TEST_DECIMAL_TO_INT_ZERO) {
  int test_int = 0;
  s21_decimal number = {{0, 0, 0, 0}};
  int status = s21_from_decimal_to_int(number, &test_int);

  ck_assert_int_eq(status, ALLRIGHT_CONV);
  ck_assert_int_eq(test_int, number.bits[0]);
  ck_assert_int_eq(0, getSignfromNumber(test_int));
}
END_TEST

START_TEST(TEST_DECIMAL_TO_INT_MAX) {
  int test_int = 0;
  s21_decimal number = {{0, 0, 0, 0}};
  s21_from_int_to_decimal(INT32_MAX, &number);
  ck_assert_int_eq(0, getSign(number));

  int status = s21_from_decimal_to_int(number, &test_int);

  ck_assert_int_eq(status, ALLRIGHT_CONV);
  ck_assert_int_eq(test_int, number.bits[0]);
  ck_assert_int_eq(0, getSignfromNumber(test_int));
}
END_TEST

START_TEST(TEST_DECIMAL_TO_INT_MIN) {
  int test_int = 0;
  s21_decimal number = {{0, 0, 0, 0}};
  s21_from_int_to_decimal(INT32_MIN + 1, &number);
  ck_assert_int_eq(1, getSign(number));

  int status = s21_from_decimal_to_int(number, &test_int);

  ck_assert_int_eq(status, ALLRIGHT_CONV);
  ck_assert_int_eq(-test_int, number.bits[0]);
  ck_assert_int_eq(1, getSignfromNumber(test_int));
}
END_TEST

START_TEST(TEST_DECIMAL_TO_INT_NEG) {
  int test_int = 0;
  s21_decimal number = {{0, 0, 0, 0}};
  s21_from_int_to_decimal(-12341, &number);
  ck_assert_int_eq(1, getSign(number));

  int status = s21_from_decimal_to_int(number, &test_int);

  ck_assert_int_eq(status, ALLRIGHT_CONV);
  ck_assert_int_eq(-test_int, number.bits[0]);
  ck_assert_int_eq(1, getSignfromNumber(test_int));
}
END_TEST

START_TEST(TEST_DECIMAL_TO_INT_POS) {
  int test_int = 0;
  s21_decimal number = {{0, 0, 0, 0}};
  s21_from_int_to_decimal(87651, &number);
  ck_assert_int_eq(0, getSign(number));

  int status = s21_from_decimal_to_int(number, &test_int);

  ck_assert_int_eq(status, ALLRIGHT_CONV);
  ck_assert_int_eq(test_int, number.bits[0]);
  ck_assert_int_eq(0, getSignfromNumber(test_int));
}
END_TEST

START_TEST(TEST_DECIMAL_TO_INT_FLOAT_POS) {
  int test_int = 0;
  s21_decimal number = {{0, 0, 0, 0}};
  s21_from_float_to_decimal(83.374, &number);
  ck_assert_int_eq(3, getExponent(number));
  ck_assert_int_eq(0, getSign(number));

  int status = s21_from_decimal_to_int(number, &test_int);

  ck_assert_int_eq(status, ALLRIGHT_CONV);
  ck_assert_int_eq(83.374, test_int);
  ck_assert_int_eq(0, getSignfromNumber(test_int));
}
END_TEST

START_TEST(TEST_DECIMAL_TO_INT_FLOAT_NEG) {
  int test_int = 0;
  s21_decimal number = {{0, 0, 0, 0}};
  s21_from_float_to_decimal(-74.6588864, &number);
  ck_assert_int_eq(5, getExponent(number));
  ck_assert_int_eq(1, getSign(number));

  int status = s21_from_decimal_to_int(number, &test_int);

  ck_assert_int_eq(status, ALLRIGHT_CONV);
  ck_assert_float_eq(-74, test_int);
  ck_assert_int_eq(1, getSignfromNumber(test_int));
}
END_TEST

START_TEST(TEST_DECIMAL_TO_INT_FLOAT_POS_EXTRA) {
  int test_int = 0;
  s21_decimal number = {{0, 1, 1, 0}};

  int status = s21_from_decimal_to_int(number, &test_int);

  ck_assert_int_eq(status, ERROR_CONV);
}
END_TEST

// $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

START_TEST(TEST_DECIMAL_TO_FLOAT_NULL) {
  s21_decimal decimal = {{0, 0, 0, 0}};
  int status = s21_from_decimal_to_float(decimal, NULL);

  ck_assert_int_eq(status, ERROR_CONV);
}
END_TEST

START_TEST(TEST_DECIMAL_TO_FLOAT_ZERO) {
  float test_float = 0;
  s21_decimal number = {{0, 0, 0, 0}};
  s21_from_float_to_decimal(0, &number);
  ck_assert_int_eq(0, getExponent(number));
  ck_assert_int_eq(0, getSign(number));

  int status = s21_from_decimal_to_float(number, &test_float);

  ck_assert_int_eq(status, ALLRIGHT_CONV);
  ck_assert_float_eq(test_float,
                     ((float)number.bits[0] * pow(10, getExponent(number))));
  ck_assert_int_eq(0, getSignfromNumber(test_float));
}
END_TEST

START_TEST(TEST_DECIMAL_TO_FLOAT_POS_EXTRA) {
  float test_float = 0;
  s21_decimal number = {{0, 0, 0, 0}};
  s21_from_float_to_decimal(83374, &number);
  setExponent(&number, 3);
  ck_assert_int_eq(3, getExponent(number));
  ck_assert_int_eq(0, getSign(number));

  int status = s21_from_decimal_to_float(number, &test_float);

  ck_assert_int_eq(status, ALLRIGHT_CONV);
  ck_assert_float_eq(test_float, 83374 / pow(10, getExponent(number)));
  ck_assert_int_eq(0, getSignfromNumber(test_float));
}
END_TEST

START_TEST(TEST_DECIMAL_TO_FLOAT_POS_EXTRA_1) {
  float test_float = 0;
  s21_decimal number = {{0, 0, 0, 0}};
  s21_from_float_to_decimal(201.47, &number);
  setExponent(&number, 2);
  ck_assert_int_eq(2, getExponent(number));
  ck_assert_int_eq(0, getSign(number));

  int status = s21_from_decimal_to_float(number, &test_float);

  ck_assert_int_eq(status, ALLRIGHT_CONV);
  ck_assert_float_eq(test_float, 201.47);
  ck_assert_int_eq(0, getSignfromNumber(test_float));
}
END_TEST

START_TEST(TEST_DECIMAL_TO_FLOAT_POS_EXTRA_2) {
  float test_float = 0;
  s21_decimal number = {{0, 0, 0, 0}};
  s21_from_float_to_decimal(8338.4, &number);
  setExponent(&number, 1);
  ck_assert_int_eq(1, getExponent(number));
  ck_assert_int_eq(0, getSign(number));

  int status = s21_from_decimal_to_float(number, &test_float);

  ck_assert_int_eq(status, ALLRIGHT_CONV);
  ck_assert_float_eq(test_float, 8338.4);
  ck_assert_int_eq(0, getSignfromNumber(test_float));
}
END_TEST

START_TEST(TEST_DECIMAL_TO_FLOAT_NEG_EXTRA) {
  float test_float = 0;
  s21_decimal number = {{0, 0, 0, 0}};
  s21_from_float_to_decimal(-74.658, &number);
  setExponent(&number, 3);
  ck_assert_int_eq(3, getExponent(number));
  ck_assert_int_eq(1, getSign(number));

  int status = s21_from_decimal_to_float(number, &test_float);

  ck_assert_int_eq(status, ALLRIGHT_CONV);
  ck_assert_float_eq(test_float, -74.658);
  ck_assert_int_eq(1, getSignfromNumber(test_float));
}
END_TEST

// $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

START_TEST(TEST_FLOOR) {
  s21_decimal test_value_1 = {{0, 0, 0, 0}};
  s21_decimal result_dec = {{0, 0, 0, 0}};
  int result;

  s21_from_int_to_decimal(673988, &test_value_1);
  setExponent(&test_value_1, 5);
  s21_floor(test_value_1, &result_dec);
  s21_from_decimal_to_int(result_dec, &result);
  ck_assert_int_eq(result, 6);

  s21_from_int_to_decimal(-2744406, &test_value_1);
  setExponent(&test_value_1, 4);
  s21_floor(test_value_1, &result_dec);
  s21_from_decimal_to_int(result_dec, &result);
  ck_assert_int_eq(result, -275);
}
END_TEST

// $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

START_TEST(TEST_ROUND) {
  s21_decimal test_value_1 = {{0, 0, 0, 0}};
  s21_decimal result_dec = {{0, 0, 0, 0}};
  int result;

  zeroDefDecimal(&test_value_1);
  zeroDefDecimal(&result_dec);
  s21_from_int_to_decimal(673988, &test_value_1);
  setExponent(&test_value_1, 5);
  s21_round(test_value_1, &result_dec);
  s21_from_decimal_to_int(result_dec, &result);
  ck_assert_int_eq(result, 7);

  zeroDefDecimal(&test_value_1);
  zeroDefDecimal(&result_dec);
  s21_from_int_to_decimal(19993, &test_value_1);
  setExponent(&test_value_1, 4);
  s21_floor(test_value_1, &result_dec);
  s21_from_decimal_to_int(result_dec, &result);
  ck_assert_int_eq(result, 1);

  zeroDefDecimal(&test_value_1);
  zeroDefDecimal(&result_dec);
  s21_from_int_to_decimal(-19993, &test_value_1);
  setExponent(&test_value_1, 4);
  s21_floor(test_value_1, &result_dec);
  s21_from_decimal_to_int(result_dec, &result);
  ck_assert_int_eq(result, -2);

  zeroDefDecimal(&test_value_1);
  zeroDefDecimal(&result_dec);
  s21_from_int_to_decimal(-19993, &test_value_1);
  s21_floor(test_value_1, &result_dec);
  s21_from_decimal_to_int(result_dec, &result);
  ck_assert_int_eq(result, -19993);
}
END_TEST

// $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

START_TEST(TEST_NEGATE) {
  int result_int;
  s21_decimal value = {{0, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};

  s21_from_int_to_decimal(INT32_MAX, &value);
  ck_assert_int_eq(INT32_MAX, value.bits[0]);
  ck_assert_int_eq(0, value.bits[1]);
  ck_assert_int_eq(0, value.bits[2]);
  ck_assert_int_eq(0, getSign(value));

  zeroDefDecimal(&value);

  s21_from_int_to_decimal(INT32_MAX, &value);
  s21_negate(value, &result);
  ck_assert_int_eq(INT32_MAX, result.bits[0]);
  ck_assert_int_eq(0, result.bits[1]);
  ck_assert_int_eq(0, result.bits[2]);
  ck_assert_int_eq(1, getSign(result));

  zeroDefDecimal(&value);
  zeroDefDecimal(&result);

  s21_from_int_to_decimal(711996, &value);
  s21_negate(value, &result);
  s21_from_decimal_to_int(result, &result_int);
  ck_assert_int_eq(result_int, -711996);

  zeroDefDecimal(&value);
  zeroDefDecimal(&result);

  s21_from_int_to_decimal(-279, &value);
  s21_negate(value, &result);
  s21_from_decimal_to_int(result, &result_int);
  ck_assert_int_eq(result_int, 279);
}
END_TEST

// $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

START_TEST(TEST_TRUNCATE) {
  s21_decimal test_value_1 = {{0, 0, 0, 0}};
  s21_decimal result_dec = {{0, 0, 0, 0}};
  int result;

  s21_from_int_to_decimal(673988, &test_value_1);
  setExponent(&test_value_1, 4);
  s21_truncate(test_value_1, &result_dec);
  s21_from_decimal_to_int(result_dec, &result);
  ck_assert_int_eq(result, 67);

  zeroDefDecimal(&test_value_1);
  zeroDefDecimal(&result_dec);

  s21_from_int_to_decimal(-2744406, &test_value_1);
  setExponent(&test_value_1, 4);
  s21_truncate(test_value_1, &result_dec);
  s21_from_decimal_to_int(result_dec, &result);
  ck_assert_int_eq(result, -274);

  zeroDefDecimal(&test_value_1);
  zeroDefDecimal(&result_dec);

  s21_from_int_to_decimal(-2744406, &test_value_1);
  setExponent(&test_value_1, 4);
  s21_truncate(test_value_1, &result_dec);
  s21_from_decimal_to_int(result_dec, &result);
  ck_assert_int_eq(result, -274);

  zeroDefDecimal(&test_value_1);
  zeroDefDecimal(&result_dec);
  s21_from_int_to_decimal(-2744406, &test_value_1);
  s21_truncate(test_value_1, &result_dec);
  s21_from_decimal_to_int(result_dec, &result);
  ck_assert_int_eq(result, -2744406);
}
END_TEST

// $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

START_TEST(TEST_DIV) {
  s21_decimal src1, src2;
  zeroDefDecimal(&src1);
  zeroDefDecimal(&src2);
  float a = 9403.0e2;
  int b = 202;
  float res_our_dec = 0.0;
  s21_from_float_to_decimal(a, &src1);
  s21_from_int_to_decimal(b, &src2);
  float res_origin = 4654.950495049504950495049505;
  s21_decimal res_od;
  s21_div(src1, src2, &res_od);
  s21_from_decimal_to_float(res_od, &res_our_dec);
  ck_assert_float_eq(res_our_dec, res_origin);

  s21_decimal test_value_1 = {{0, 0, 0, 0}};
  s21_decimal test_value_2 = {{0, 0, 0, 0}};
  s21_decimal result_dec = {{0, 0, 0, 0}};
  int result_int;

  s21_from_int_to_decimal(100000, &test_value_1);
  s21_from_int_to_decimal(1000, &test_value_2);
  s21_div(test_value_1, test_value_2, &result_dec);
  s21_from_decimal_to_int(result_dec, &result_int);
  ck_assert_int_eq(result_int, (100000 / 1000));

  s21_from_int_to_decimal(100000, &test_value_1);
  s21_from_int_to_decimal(1000, &test_value_2);
  setExponent(&test_value_2, 2);
  s21_div(test_value_1, test_value_2, &result_dec);
  s21_from_decimal_to_int(result_dec, &result_int);
  ck_assert_int_eq(result_int, (100000 / 10));

  zeroDefDecimal(&test_value_1);
  zeroDefDecimal(&test_value_2);
  s21_from_int_to_decimal(-456800, &test_value_1);
  s21_from_int_to_decimal(456800, &test_value_2);
  s21_div(test_value_1, test_value_2, &result_dec);
  s21_from_decimal_to_int(result_dec, &result_int);
  ck_assert_int_eq(result_int, -1);

  s21_from_int_to_decimal(8900, &test_value_1);
  setInf(&test_value_2);
  int status = s21_div(test_value_1, test_value_2, &result_dec);
  ck_assert_int_eq(status, 3);
}
END_TEST

// $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

START_TEST(TEST_IS_EQUAL) {
  s21_decimal dst1, dst2;

  s21_from_float_to_decimal(1.2345, &dst1);
  s21_from_float_to_decimal(1.2, &dst2);
  ck_assert_int_eq(s21_is_equal(dst1, dst2), FALSE);  // 1.2345 = 1.2

  s21_from_float_to_decimal(1.2, &dst1);
  s21_from_float_to_decimal(1.2, &dst2);
  ck_assert_int_eq(s21_is_equal(dst1, dst2), TRUE);  // 1.2 = 1.2

  s21_from_float_to_decimal(-234.17, &dst1);
  s21_from_float_to_decimal(234.17, &dst2);
  ck_assert_int_eq(s21_is_equal(dst1, dst2), FALSE);

  s21_from_float_to_decimal(234.17, &dst1);
  s21_from_float_to_decimal(234.17, &dst2);
  ck_assert_int_eq(s21_is_equal(dst1, dst2), TRUE);

  setInf(&dst1);
  setInf(&dst2);
  ck_assert_int_eq(s21_is_less_or_equal(dst2, dst1),
                   TRUE);  // +INFINITY = +INFINITY

  s21_from_int_to_decimal(0, &dst1);  // -0 == 0
  s21_from_int_to_decimal(0, &dst2);
  setSign_To_Neg(&dst1);
  ck_assert_int_eq(s21_is_equal(dst1, dst2), TRUE);

  s21_decimal test_value_1 = {{0, 0, 0, 0}};
  s21_decimal test_value_2 = {{0, 0, 0, 0}};
  s21_from_int_to_decimal(0, &test_value_1);
  s21_from_int_to_decimal(0, &test_value_2);
  ck_assert_int_eq(s21_is_equal(test_value_1, test_value_2), TRUE);

  s21_from_int_to_decimal(711996, &test_value_1);
  s21_from_int_to_decimal(701995, &test_value_2);
  ck_assert_int_eq(s21_is_equal(test_value_1, test_value_2), FALSE);

  s21_from_int_to_decimal(19993, &test_value_1);
  s21_from_int_to_decimal(-6739, &test_value_2);
  ck_assert_int_eq(s21_is_equal(test_value_1, test_value_2), FALSE);

  s21_from_int_to_decimal(-9993, &test_value_1);
  s21_from_int_to_decimal(-9993, &test_value_2);
  ck_assert_int_eq(s21_is_equal(test_value_1, test_value_2), TRUE);

  s21_from_int_to_decimal(11881, &test_value_1);
  s21_from_int_to_decimal(11881, &test_value_2);
  ck_assert_int_eq(s21_is_greater_or_equal(test_value_1, test_value_2), TRUE);
}
END_TEST

// $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

START_TEST(TEST_IS_GREATER) {
  s21_decimal dst1, dst2;

  s21_from_float_to_decimal(1.2345, &dst1);
  s21_from_float_to_decimal(1.2, &dst2);
  ck_assert_int_eq(s21_is_greater(dst1, dst2), TRUE);   // 1.2345 > 1.2
  ck_assert_int_eq(s21_is_greater(dst2, dst1), FALSE);  // 1.2 > 1.2345

  setSign_To_Neg(&dst1);
  setSign_To_Neg(&dst2);
  ck_assert_int_eq(s21_is_greater(dst1, dst2), FALSE);  // -1.2345 > -1.2
  ck_assert_int_eq(s21_is_greater(dst2, dst1), TRUE);   // -1.2 > 1.2345

  setSign_To_Pos(&dst1);
  ck_assert_int_eq(s21_is_greater(dst1, dst2), TRUE);   //  1.2345 > -1.2
  ck_assert_int_eq(s21_is_greater(dst2, dst1), FALSE);  //  -1.2 > 1.2345

  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  ck_assert_int_eq(s21_is_greater(dst1, dst2), FALSE);  // 0 > 0

  setInf(&dst1);
  ck_assert_int_eq(s21_is_greater(dst1, dst2), TRUE);   // +INFINITY > 0
  ck_assert_int_eq(s21_is_greater(dst2, dst1), FALSE);  // 0 > +INFINITY

  setSign_To_Neg(&dst1);
  ck_assert_int_eq(s21_is_greater(dst1, dst2), FALSE);  // -INFINITY > 0
  ck_assert_int_eq(s21_is_greater(dst2, dst1), TRUE);   // 0 > -INFINITY

  s21_decimal test_value_1 = {{0, 0, 0, 0}};
  s21_decimal test_value_2 = {{0, 0, 0, 0}};
  s21_from_int_to_decimal(111, &test_value_1);
  s21_from_int_to_decimal(111, &test_value_2);
  ck_assert_int_eq(s21_is_greater(test_value_1, test_value_2), 0);

  s21_from_int_to_decimal(19993, &test_value_1);
  s21_from_int_to_decimal(-6739, &test_value_2);
  ck_assert_int_eq(s21_is_greater(test_value_1, test_value_2), 1);

  s21_from_int_to_decimal(-19993, &test_value_1);
  s21_from_int_to_decimal(6739, &test_value_2);
  ck_assert_int_eq(s21_is_greater(test_value_1, test_value_2), 0);

  setSign_To_Pos(&test_value_1);
  setSign_To_Pos(&test_value_2);
  s21_from_int_to_decimal(6739, &test_value_1);
  s21_from_int_to_decimal(19993, &test_value_2);
  ck_assert_int_eq(s21_is_greater(test_value_1, test_value_2), 0);

  setSign_To_Pos(&test_value_1);
  setSign_To_Pos(&test_value_2);
  s21_from_int_to_decimal(711996, &test_value_1);
  s21_from_int_to_decimal(711995, &test_value_2);
  ck_assert_int_eq(s21_is_greater(test_value_1, test_value_2), 1);
}
END_TEST

// $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

START_TEST(TEST_IS_LESS) {
  s21_decimal dst1, dst2;

  s21_from_float_to_decimal(1.2345, &dst1);
  s21_from_float_to_decimal(1.2, &dst2);
  ck_assert_int_eq(s21_is_less(dst1, dst2), FALSE);  // 1.2345 < 1.2
  ck_assert_int_eq(s21_is_less(dst2, dst1), TRUE);   // 1.2 < 1.2345

  setSign_To_Neg(&dst1);
  setSign_To_Neg(&dst2);
  ck_assert_int_eq(s21_is_less(dst1, dst2), TRUE);   // -1.2345 < -1.2
  ck_assert_int_eq(s21_is_less(dst2, dst1), FALSE);  // -1.2 < -1.2345

  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  ck_assert_int_eq(s21_is_less(dst1, dst2), FALSE);  // 0 < 0

  setInf(&dst1);
  ck_assert_int_eq(s21_is_less(dst1, dst2), FALSE);  // +INFINITY < 0
  ck_assert_int_eq(s21_is_less(dst2, dst1), TRUE);   // 0 < +INFINITY

  setSign_To_Neg(&dst1);
  ck_assert_int_eq(s21_is_less(dst1, dst2), TRUE);   // -INFINITY < 0
  ck_assert_int_eq(s21_is_less(dst2, dst1), FALSE);  // 0 < -INFINITY

  s21_decimal test_value_1 = {{0, 0, 0, 0}};
  s21_decimal test_value_2 = {{0, 0, 0, 0}};
  s21_from_int_to_decimal(10, &test_value_1);
  s21_from_int_to_decimal(15, &test_value_2);
  ck_assert_int_eq(s21_is_less(test_value_1, test_value_2), 1);

  s21_from_int_to_decimal(6739, &test_value_1);
  s21_from_int_to_decimal(19993, &test_value_2);
  ck_assert_int_eq(s21_is_less(test_value_1, test_value_2), 1);

  s21_from_int_to_decimal(19993, &test_value_1);
  s21_from_int_to_decimal(6739, &test_value_2);
  ck_assert_int_eq(s21_is_less(test_value_1, test_value_2), 0);

  s21_from_int_to_decimal(-19993, &test_value_1);
  s21_from_int_to_decimal(6739, &test_value_2);
  ck_assert_int_eq(s21_is_less(test_value_1, test_value_2), 1);

  setSign_To_Pos(&test_value_1);
  setSign_To_Pos(&test_value_2);
  s21_from_int_to_decimal(19993, &test_value_1);
  s21_from_int_to_decimal(-6739, &test_value_2);
  ck_assert_int_eq(s21_is_less(test_value_1, test_value_2), 0);
}
END_TEST

// $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

START_TEST(TEST_IS_LESS_OR_EQUAL) {
  s21_decimal dst1, dst2;

  s21_from_float_to_decimal(1.2345, &dst1);
  s21_from_float_to_decimal(1.2, &dst2);
  ck_assert_int_eq(s21_is_less_or_equal(dst1, dst2), FALSE);  // 1.2345 <= 1.2
  ck_assert_int_eq(s21_is_less_or_equal(dst2, dst1), TRUE);   // 1.2 <= 1.2345

  setSign_To_Neg(&dst1);
  setSign_To_Neg(&dst2);
  ck_assert_int_eq(s21_is_less_or_equal(dst1, dst2),
                   TRUE);  // -1.2345 <= -1.2
  ck_assert_int_eq(s21_is_less_or_equal(dst2, dst1),
                   FALSE);  // -1.2 <= 1.2345

  setSign_To_Pos(&dst1);
  ck_assert_int_eq(s21_is_less_or_equal(dst1, dst2),
                   FALSE);  //  1.2345 <= -1.2 // fail
  ck_assert_int_eq(s21_is_less_or_equal(dst2, dst1),
                   TRUE);  //  -1.2 <= 1.2345

  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  ck_assert_int_eq(s21_is_less_or_equal(dst1, dst2), TRUE);  // 0 <= 0

  setInf(&dst1);
  ck_assert_int_eq(s21_is_less_or_equal(dst1, dst2),
                   FALSE);                                   // +INFINITY <= 0
  ck_assert_int_eq(s21_is_less_or_equal(dst2, dst1), TRUE);  // 0 <= +INFINITY

  setInf(&dst2);
  ck_assert_int_eq(s21_is_less_or_equal(dst2, dst1),
                   TRUE);  // +INFINITY <= +INFINITY

  setSign_To_Neg(&dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  ck_assert_int_eq(s21_is_less_or_equal(dst1, dst2), TRUE);  // -INFINITY <= 0
  ck_assert_int_eq(s21_is_less_or_equal(dst2, dst1),
                   FALSE);  // 0 <= -INFINITY

  s21_from_float_to_decimal(1726.73, &dst1);
  s21_from_float_to_decimal(1726.73, &dst2);
  ck_assert_int_eq(s21_is_less_or_equal(dst1, dst2),
                   TRUE);  // 1726.73 <= 1726.73

  s21_decimal test_value_1 = {{0, 0, 0, 0}};
  s21_decimal test_value_2 = {{0, 0, 0, 0}};
  s21_from_int_to_decimal(111, &test_value_1);
  s21_from_int_to_decimal(111, &test_value_2);
  ck_assert_int_eq(s21_is_less_or_equal(test_value_1, test_value_2), 1);

  s21_from_int_to_decimal(711995, &test_value_1);
  s21_from_int_to_decimal(711996, &test_value_2);
  ck_assert_int_eq(s21_is_less_or_equal(test_value_1, test_value_2), 1);

  s21_from_int_to_decimal(-19993, &test_value_1);
  s21_from_int_to_decimal(6739, &test_value_2);
  ck_assert_int_eq(s21_is_less_or_equal(test_value_1, test_value_2), 1);

  setSign_To_Pos(&test_value_1);
  setSign_To_Pos(&test_value_2);
  s21_from_int_to_decimal(19993, &test_value_1);
  s21_from_int_to_decimal(-6739, &test_value_2);
  ck_assert_int_eq(s21_is_less_or_equal(test_value_1, test_value_2), 0);

  s21_from_int_to_decimal(-9993, &test_value_1);
  s21_from_int_to_decimal(-9993, &test_value_2);
  ck_assert_int_eq(s21_is_less_or_equal(test_value_1, test_value_2), 1);
}
END_TEST

// $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

START_TEST(TEST_IS_GREATER_OR_EQUAL) {
  s21_decimal dst1, dst2;

  s21_from_float_to_decimal(1.2345, &dst1);
  s21_from_float_to_decimal(1.2, &dst2);
  ck_assert_int_eq(s21_is_greater_or_equal(dst1, dst2),
                   TRUE);  // 1.2345 >= 1.2
  ck_assert_int_eq(s21_is_greater_or_equal(dst2, dst1),
                   FALSE);  // 1.2 >= 1.2345

  setSign_To_Neg(&dst1);
  setSign_To_Neg(&dst2);
  ck_assert_int_eq(s21_is_greater_or_equal(dst1, dst2),
                   FALSE);  // -1.2345 >= -1.2
  ck_assert_int_eq(s21_is_greater_or_equal(dst2, dst1),
                   TRUE);  // -1.2 >= 1.2345

  setSign_To_Pos(&dst1);
  ck_assert_int_eq(s21_is_greater_or_equal(dst1, dst2),
                   TRUE);  //  1.2345 >= -1.2 // fail
  ck_assert_int_eq(s21_is_greater_or_equal(dst2, dst1),
                   FALSE);  //  -1.2 >= 1.2345

  s21_from_float_to_decimal(0.0, &dst1);
  s21_from_float_to_decimal(0.0, &dst2);
  ck_assert_int_eq(s21_is_greater_or_equal(dst1, dst2), TRUE);  // 0 >= 0

  setInf(&dst1);
  ck_assert_int_eq(s21_is_greater_or_equal(dst1, dst2),
                   TRUE);  // +INFINITY >= 0
  ck_assert_int_eq(s21_is_greater_or_equal(dst2, dst1),
                   FALSE);  // 0 >= +INFINITY

  setSign_To_Neg(&dst1);
  ck_assert_int_eq(s21_is_greater_or_equal(dst1, dst2),
                   FALSE);  // -INFINITY >= 0
  ck_assert_int_eq(s21_is_greater_or_equal(dst2, dst1),
                   TRUE);  // 0 >= -INFINITY

  s21_decimal test_value_1 = {{0, 0, 0, 0}};
  s21_decimal test_value_2 = {{0, 0, 0, 0}};
  s21_from_int_to_decimal(11881, &test_value_1);
  s21_from_int_to_decimal(11881, &test_value_2);
  ck_assert_int_eq(s21_is_greater_or_equal(test_value_1, test_value_2), 1);

  s21_from_int_to_decimal(711996, &test_value_1);
  s21_from_int_to_decimal(701995, &test_value_2);
  ck_assert_int_eq(s21_is_greater_or_equal(test_value_1, test_value_2), 1);

  s21_from_int_to_decimal(0, &test_value_1);
  s21_from_int_to_decimal(0, &test_value_2);
  ck_assert_int_eq(s21_is_greater_or_equal(test_value_1, test_value_2), 1);

  s21_from_int_to_decimal(19993, &test_value_1);
  s21_from_int_to_decimal(-6739, &test_value_2);
  ck_assert_int_eq(s21_is_greater_or_equal(test_value_1, test_value_2), 1);

  setSign_To_Pos(&test_value_1);
  setSign_To_Pos(&test_value_2);
  s21_from_int_to_decimal(-19993, &test_value_1);
  s21_from_int_to_decimal(239, &test_value_2);
  ck_assert_int_eq(s21_is_greater_or_equal(test_value_1, test_value_2), 0);
}
END_TEST

// $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

START_TEST(TEST_IS_NOT_EQUAL) {
  s21_decimal dst1, dst2;

  s21_from_float_to_decimal(1.2345, &dst1);
  s21_from_float_to_decimal(1.2, &dst2);
  ck_assert_int_eq(s21_is_not_equal(dst1, dst2), TRUE);  // 1.2345 = 1.2

  s21_from_float_to_decimal(1.2, &dst1);
  s21_from_float_to_decimal(1.2, &dst2);
  ck_assert_int_eq(s21_is_not_equal(dst1, dst2), FALSE);  // 1.2 = 1.2

  setInf(&dst1);
  setInf(&dst2);
  ck_assert_int_eq(s21_is_not_equal(dst1, dst2), FALSE);

  s21_from_float_to_decimal(234.17, &dst1);
  s21_from_float_to_decimal(234.17, &dst2);
  ck_assert_int_eq(s21_is_not_equal(dst1, dst2), FALSE);

  s21_decimal test_value_1 = {{0, 0, 0, 0}};
  s21_decimal test_value_2 = {{0, 0, 0, 0}};
  s21_from_int_to_decimal(-9993, &test_value_1);
  s21_from_int_to_decimal(-9993, &test_value_2);
  ck_assert_int_eq(s21_is_not_equal(test_value_1, test_value_2), 0);

  s21_from_int_to_decimal(19993, &test_value_1);
  s21_from_int_to_decimal(-6739, &test_value_2);
  ck_assert_int_eq(s21_is_not_equal(test_value_1, test_value_2), 1);

  s21_from_int_to_decimal(711996, &test_value_1);
  s21_from_int_to_decimal(701995, &test_value_2);
  ck_assert_int_eq(s21_is_not_equal(test_value_1, test_value_2), 1);

  s21_from_int_to_decimal(11881, &test_value_1);
  s21_from_int_to_decimal(11881, &test_value_2);
  ck_assert_int_eq(s21_is_not_equal(test_value_1, test_value_2), 0);

  s21_from_int_to_decimal(6739, &test_value_1);
  s21_from_int_to_decimal(19993, &test_value_2);
  ck_assert_int_eq(s21_is_not_equal(test_value_1, test_value_2), 1);
}
END_TEST

// $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

START_TEST(TEST_FROM_INT_TO_DECIMAL) {
  s21_decimal X;
  int Y;
  s21_from_int_to_decimal(100, &X);
  s21_from_decimal_to_int(X, &Y);
  ck_assert_int_eq(100, Y);

  s21_from_int_to_decimal(6.5, &X);
  s21_from_decimal_to_int(X, &Y);
  ck_assert_int_eq(6, Y);

  s21_from_int_to_decimal(0.123, &X);
  s21_from_decimal_to_int(X, &Y);
  ck_assert_int_eq(0, Y);

  s21_from_int_to_decimal(123456789, &X);
  s21_from_decimal_to_int(X, &Y);
  ck_assert_int_eq(123456789, Y);

  s21_from_int_to_decimal(-94, &X);
  s21_from_decimal_to_int(X, &Y);
  ck_assert_int_eq(-94, Y);

  s21_from_int_to_decimal(-4.31, &X);
  s21_from_decimal_to_int(X, &Y);
  ck_assert_int_eq(-4, Y);

  s21_from_int_to_decimal(-0.13, &X);
  s21_from_decimal_to_int(X, &Y);
  ck_assert_int_eq(0, Y);
}
END_TEST

// $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

START_TEST(TEST_FROM_FLOAT_TO_DECIMAL) {
  s21_decimal X;
  float Y;
  s21_from_float_to_decimal(10.53, &X);
  s21_from_decimal_to_float(X, &Y);
  ck_assert_float_eq(10.53, Y);

  s21_from_float_to_decimal(-4.48, &X);
  s21_from_decimal_to_float(X, &Y);
  ck_assert_float_eq(-4.48, Y);

  s21_from_float_to_decimal(0.123, &X);
  s21_from_decimal_to_float(X, &Y);
  ck_assert_float_eq(0.123, Y);

  s21_from_float_to_decimal(100, &X);
  s21_from_decimal_to_float(X, &Y);
  ck_assert_float_eq(100, Y);

  s21_from_float_to_decimal(-49, &X);
  s21_from_decimal_to_float(X, &Y);
  ck_assert_float_eq(-49, Y);

  s21_from_float_to_decimal(2e-3, &X);
  s21_from_decimal_to_float(X, &Y);
  ck_assert_float_eq(2e-3, Y);

  s21_from_float_to_decimal(2e5, &X);
  s21_from_decimal_to_float(X, &Y);
  ck_assert_float_eq(2e5, Y);
}
END_TEST

// $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

START_TEST(TEST_MOD) {
  s21_decimal test_value_1 = {{0, 0, 0, 0}};
  s21_decimal test_value_2 = {{0, 0, 0, 0}};
  s21_decimal result_dec = {{0, 0, 0, 0}};
  int result_int = 0;
  float result_float = 0;

  initDecimalThree(&test_value_1, &test_value_2, &result_dec);
  initIntResult(&result_int);
  s21_from_int_to_decimal(100000, &test_value_1);
  s21_from_int_to_decimal(1000, &test_value_2);
  s21_mod(test_value_1, test_value_2, &result_dec);
  s21_from_decimal_to_int(result_dec, &result_int);
  ck_assert_int_eq(result_int, (100000 % 1000));

  initDecimalThree(&test_value_1, &test_value_2, &result_dec);
  initIntResult(&result_int);
  s21_from_int_to_decimal(1, &test_value_1);
  s21_from_int_to_decimal(3, &test_value_2);
  s21_mod(test_value_1, test_value_2, &result_dec);
  s21_from_decimal_to_int(result_dec, &result_int);
  ck_assert_int_eq(result_int, (1 % 3));

  initDecimalThree(&test_value_1, &test_value_2, &result_dec);
  initIntResult(&result_int);
  s21_from_int_to_decimal(6, &test_value_1);
  s21_from_int_to_decimal(3, &test_value_2);
  s21_mod(test_value_1, test_value_2, &result_dec);
  s21_from_decimal_to_int(result_dec, &result_int);
  int result = 6 % 3;
  ck_assert_int_eq(result_int, result);

  initDecimalThree(&test_value_1, &test_value_2, &result_dec);
  initIntResult(&result_int);
  s21_from_int_to_decimal(100, &test_value_1);
  s21_from_int_to_decimal(100, &test_value_2);
  setExponent(&test_value_1, 1);
  setExponent(&test_value_2, 2);
  s21_mod(test_value_1, test_value_2, &result_dec);
  s21_from_decimal_to_int(result_dec, &result_int);
  ck_assert_int_eq(result_int, 0);

  initDecimalThree(&test_value_1, &test_value_2, &result_dec);
  initIntResult(&result_int);
  s21_from_int_to_decimal(100, &test_value_1);
  s21_from_int_to_decimal(100, &test_value_2);
  setExponent(&test_value_1, 2);
  setExponent(&test_value_2, 1);
  s21_mod(test_value_1, test_value_2, &result_dec);
  s21_from_decimal_to_int(result_dec, &result_int);
  ck_assert_int_eq(result_int, (1 % 10));

  initDecimalThree(&test_value_1, &test_value_2, &result_dec);
  initIntResult(&result_int);
  s21_from_int_to_decimal(12, &test_value_1);
  s21_from_int_to_decimal(-12, &test_value_2);
  s21_mod(test_value_1, test_value_2, &result_dec);
  s21_from_decimal_to_int(result_dec, &result_int);
  ck_assert_int_eq(result_int, 0);

  initDecimalThree(&test_value_1, &test_value_2, &result_dec);
  initIntResult(&result_int);
  s21_from_float_to_decimal(10.1111, &test_value_1);
  s21_from_float_to_decimal(2, &test_value_2);
  s21_mod(test_value_1, test_value_2, &result_dec);
  s21_from_decimal_to_float(result_dec, &result_float);
  ck_assert_float_eq(result_float, 0.1111);
}
END_TEST

// $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

Suite *test_i(void) {
  Suite *s;
  TCase *tc_bin;

  s = suite_create("Isabeler");
  tc_bin = tcase_create("Bin");

  tcase_add_test(tc_bin, test_sign_function);
  tcase_add_test(tc_bin, test_getBit_function);
  tcase_add_test(tc_bin, test_setBit_function);
  tcase_add_test(tc_bin, test_resetBit_function);
  tcase_add_test(tc_bin, test_get_set_init_Exponent_function);

  // s21_from_int_to_decimal_function
  tcase_add_test(tc_bin, NULL_DECIMAL);
  tcase_add_test(tc_bin, ZERO_INT);
  tcase_add_test(tc_bin, MAX_INT);
  tcase_add_test(tc_bin, MIN_INT);
  tcase_add_test(tc_bin, NEG_INT);
  tcase_add_test(tc_bin, POS_INT);
  tcase_add_test(tc_bin, RANDOM_INT);
  // tcase_add_loop_test(tc_bin, RANDOM_INT, 0, 1000);
  tcase_add_test(tc_bin, TEST_FROM_INT_TO_DECIMAL);
  tcase_add_test(tc_bin, TEST_DECIMAL_TO_INT_FLOAT_POS_EXTRA);

  // s21_from_float_to_decimal_function
  tcase_add_test(tc_bin, TEST_FLOAT_TO_DECIMAL);
  tcase_add_test(tc_bin, TEST_FLOAT_TO_DECIMAL_EXTRA_1);
  tcase_add_test(tc_bin, TEST_FROM_FLOAT_TO_DECIMAL);

  // s21_from_decimal_to_int_function
  tcase_add_test(tc_bin, TEST_DECIMAL_TO_INT_NULL);
  tcase_add_test(tc_bin, TEST_DECIMAL_TO_INT_ZERO);
  tcase_add_test(tc_bin, TEST_DECIMAL_TO_INT_MAX);
  tcase_add_test(tc_bin, TEST_DECIMAL_TO_INT_MIN);
  tcase_add_test(tc_bin, TEST_DECIMAL_TO_INT_NEG);
  tcase_add_test(tc_bin, TEST_DECIMAL_TO_INT_POS);
  tcase_add_test(tc_bin, TEST_DECIMAL_TO_INT_FLOAT_POS);
  tcase_add_test(tc_bin, TEST_DECIMAL_TO_INT_FLOAT_NEG);

  // s21_from_decimal_to_float_function
  tcase_add_test(tc_bin, TEST_DECIMAL_TO_FLOAT_NULL);
  tcase_add_test(tc_bin, TEST_DECIMAL_TO_FLOAT_ZERO);
  tcase_add_test(tc_bin, TEST_DECIMAL_TO_FLOAT_POS_EXTRA);
  tcase_add_test(tc_bin, TEST_DECIMAL_TO_FLOAT_POS_EXTRA_1);
  tcase_add_test(tc_bin, TEST_DECIMAL_TO_FLOAT_POS_EXTRA_2);
  tcase_add_test(tc_bin, TEST_DECIMAL_TO_FLOAT_NEG_EXTRA);

  // s21_floor
  tcase_add_test(tc_bin, TEST_FLOOR);

  // s21_round
  tcase_add_test(tc_bin, TEST_ROUND);

  // s21_negate
  tcase_add_test(tc_bin, TEST_NEGATE);

  // s21_negate
  tcase_add_test(tc_bin, TEST_TRUNCATE);

  // s21_div
  tcase_add_test(tc_bin, TEST_DIV);

  // s21_is_equal
  tcase_add_test(tc_bin, TEST_IS_EQUAL);

  // s21_is_not_equal
  tcase_add_test(tc_bin, TEST_IS_NOT_EQUAL);

  // s21_is_greater
  tcase_add_test(tc_bin, TEST_IS_GREATER);

  // s21_is_greater_or_equal
  tcase_add_test(tc_bin, TEST_IS_GREATER_OR_EQUAL);

  // s21_is_less
  tcase_add_test(tc_bin, TEST_IS_LESS);

  // s21_is_less_or_equal
  tcase_add_test(tc_bin, TEST_IS_LESS_OR_EQUAL);

  // s21_mod
  tcase_add_test(tc_bin, TEST_MOD);

  suite_add_tcase(s, tc_bin);

  return s;
}
