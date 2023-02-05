#include "s21_decimal.h"

int s21_is_greater(s21_decimal number_1, s21_decimal number_2) {
  int result = FALSE;
  int sign = getSign(number_1);
  int exp = s21_max(number_1.bits[3], number_2.bits[3]);
  if (exp != 2) exp_rewrite(&number_1, &number_2, exp);
  if (sign == getSign(number_2)) {
    for (int i = 2, max_res = 3; i >= 0 && max_res != 0; i--) {
      max_res = s21_max(number_1.bits[i], number_2.bits[i]);
      if (max_res == 1) {
        i = 0;
        result = TRUE;
      }
    }
    if (sign != 0 && !s21_is_equal(number_1, number_2)) {
      result = !result;
    }
    int status_1 = isInf(number_1);
    int status_2 = isInf(number_2);
    if (status_1 + status_2 != 2) {
      result = status_1 > status_2 ? TRUE : FALSE;
    }
  } else {
    if (sign == 0) {
      result = TRUE;
    }
  }
  return result;
}

void exp_rewrite(s21_decimal *number_1, s21_decimal *number_2, int exp) {
  s21_decimal *f_value = NULL;
  long double tmp = 0;
  int sub = abs(getExponent(*number_1) - getExponent(*number_2));
  double pow_add = pow(10, sub);
  f_value = exp == 1 ? number_2 : number_1;
  for (int i = 0; i < 3; i++) {
    tmp = ((long double)(unsigned int)f_value->bits[i] * pow_add);
    if (tmp <= 4294967295) {
      f_value->bits[i] *= (int)pow_add;
    } else {
      int status = mul_overflow(f_value, tmp, i);
      if (status == MORE_OR_INF) {
        if (getSign(*f_value)) {
          setInf(f_value);
          setSign_To_Neg(f_value);
        } else {
          setInf(f_value);
        }
      }
    }
  }
}

int s21_is_equal(s21_decimal number_1,
                 s21_decimal number_2) {  // for numbers and +0/-0
  int result = FALSE;
  if (number_1.bits[0] == number_2.bits[0] &&
      number_1.bits[1] == number_2.bits[1] &&
      number_1.bits[2] == number_2.bits[2]) {
    if (number_1.bits[3] == number_2.bits[3] ||
        (number_1.bits[0] + number_1.bits[1] + number_1.bits[2] == 0 &&
         (isInf(number_1) + isInf(number_2) == 2))) {
      result = TRUE;
    }
  }
  return result;
}

int s21_is_greater_or_equal(s21_decimal number_1, s21_decimal number_2) {
  int result = 0;
  if (s21_is_greater(number_1, number_2) || s21_is_equal(number_1, number_2)) {
    result = 1;
  }
  return result;
}

int s21_is_less(s21_decimal number_1, s21_decimal number_2) {
  int result = 0;
  if (!s21_is_equal(number_1, number_2)) {
    result = !s21_is_greater(number_1, number_2);
  }
  return result;
}

int s21_is_less_or_equal(s21_decimal number_1, s21_decimal number_2) {
  int result = 0;
  if (s21_is_less(number_1, number_2) || s21_is_equal(number_1, number_2)) {
    result = 1;
  }
  return result;
}

int s21_is_not_equal(s21_decimal number_1, s21_decimal number_2) {
  return (!s21_is_equal(number_1, number_2));
}

int s21_max(unsigned int numb_1, unsigned int numb_2) {  // max is numb_1?
  int result = 0;
  if (numb_1 == numb_2) {
    result = 2;
  } else if (numb_1 > numb_2) {
    result = 1;
  }
  return result;  // 1 - true, 0 - false, 2 - its equal
}