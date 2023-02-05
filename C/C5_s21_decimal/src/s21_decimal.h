#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
  int bits[4];
} s21_decimal;

typedef enum { ALLRIGHT_CONV, ERROR_CONV } status_conv_oper;

typedef enum { FALSE, TRUE } status_comp_oper;

typedef enum { ALLRIGHT_OTHER, ERROR_OTHER } status_other_oper;

typedef enum { POSITIVE_SIGN, NEGATIVE_SIGN } sign_of_decimal;

typedef enum {
  START_EXPONENT = 16,
  END_EXPONENT = 23,
  MAX_EXPONENT = 28
} exponent_values;

typedef enum { OK, MORE_OR_INF, LESS_OR_INF, DIV_TO_NULL } status_math_oper;

typedef enum { MINUS_INF, NO_INF, PLUS_INF } inf;

typedef enum { OK_CALC, ERROR_CALC } status_calc_oper;

typedef enum { DIGITS = 7, BY = 32, CORE = 96, ALL = 128 } info_digits;

// core --->
#define IS_SET(X, INDEX) (X & (1U << INDEX))
#define ADD_BIT(X, INDEX) (X |= (1U << INDEX))
#define ZERO_BIT(X, INDEX) (X &= ~(1U << INDEX))
#define INIT_ZERO(X) (X = 0U)
#define INVERT_BIT(X, INDEX) (X ^= (1U << INDEX))

#define MAX_DECIMAL 79228162514264337593543950335.0F
#define MIN_DECIMAL -79228162514264337593543950335.0F

// sign operations
int getSignfromNumber(int number);
int getSign(s21_decimal number);
void setSign_To_Pos(s21_decimal *number);
void setSign_To_Neg(s21_decimal *number);

// binary operations
void setInf(s21_decimal *number);
int getBit(int number, int index);
int getExponent(s21_decimal number);
void setExponent(s21_decimal *number, int exponent);
void initExponent(s21_decimal *number);
void resetDigit(s21_decimal *number, int digit);
void setBit_To_Zero(s21_decimal *number, int digit, int index);
void setBit_To_One(s21_decimal *number, int digit, int index);
void invert_bit(s21_decimal *number, int digit, int index);
void conditional_set_bit(s21_decimal *number, int digit, int index, int bit);

// for entire decimal number
int isBitDecimal(const int array[], int index);
void setBitDecimalOne(int array[], int index);
void setBitDecimalZero(int array[], int index);
void cpyBitsDecimal(int array_1[], int array_2[], int size);
void zeroElems(int array[], int size);
void zeroDefDecimal(s21_decimal *value);
int isInf(s21_decimal number);

// additional functions
int countBits(int array[], int size);
int compareBits(int array_1[], int array_2[], int size_1, int size_2);
void truncDigit(int array[], int exponent, int round);
void multiplyByTen(int array[]);
void multiplyArrays(int array_1[], int array_2[], int size_1, int res[],
                    int size_2);
void sumArrays(int array_1[], int size_1, int array_2[], int size_2,
               int result[], int size);
void subArray(int array_1[], int size_1, int array_2[], int size_2, int res[],
              int res_len);
void arrayDiv(int div_1[], int div_1_len, int div_2[], int div_2_len, int res[],
              int res_len, int reminder[], int reminder_len);
void rightShift(int arrays[], int size, int many);

// other operations
int getRandom(int start, int end);
void initDecResult(s21_decimal *result);
void initFloatResult(float *result);
void initIntResult(int *result);
void initDecimalThree(s21_decimal *number_1, s21_decimal *number_2,
                      s21_decimal *number_3);
void print_decimal(s21_decimal value);
// comp_oper --->
int s21_is_less(s21_decimal number_1, s21_decimal number_2);
int s21_is_less_or_equal(s21_decimal number_1, s21_decimal number_2);
int s21_is_greater(s21_decimal number_1, s21_decimal number_2);
int s21_is_greater_or_equal(s21_decimal number_1, s21_decimal number_2);
int s21_is_equal(s21_decimal number_1, s21_decimal number_2);
int s21_is_not_equal(s21_decimal number_1, s21_decimal number_2);
int s21_max(unsigned int numb_1, unsigned int numb_2);
void exp_rewrite(s21_decimal *number_1, s21_decimal *number_2, int exp);
void overflow(s21_decimal *number, double pow, int i);

// conv_oper --->
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);
int getExpFloat(float src, int *exponent);

// math_oper --->
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

int if_overflow(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
void null_check(s21_decimal *value_1);
void if_take_rank(s21_decimal value_1, s21_decimal value_2,
                  s21_decimal *result);
void pow_value(s21_decimal *value, int pow);
void exp_check(s21_decimal *value_1, s21_decimal *value_2, s21_decimal *result);
void mod_div_for_mul(unsigned int *tmp_mod, long double *tmp_div_res,
                     long double tmp);
int mul_overflow(s21_decimal *result, long double tmp, int flag);

// other_oper --->
int s21_floor(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);

#endif
