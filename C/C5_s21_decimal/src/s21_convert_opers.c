#include "s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int status = ALLRIGHT_CONV;

  if (dst != NULL) {
    initDecResult(dst);
    if (src < 0) {
      setSign_To_Neg(dst);
      src = -src;
    }
    dst->bits[0] = src;
  } else {
    status = ERROR_CONV;
  }
  return status;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int status = ALLRIGHT_CONV;
  int exponent = 0;
  int res = getExpFloat(src, &exponent);  // long double

  if (dst != NULL) {
    initDecResult(dst);
    if (!isnormal(src) || src > MAX_DECIMAL || src < MIN_DECIMAL) {
      status = ERROR_CONV;
    } else {
      s21_from_int_to_decimal(res, dst);
      setExponent(dst, exponent);
    }
  } else {
    status = ERROR_CONV;
  }

  return status;
}

int getExpFloat(float src, int *exponent) {
  float src1 = src;
  *exponent = 0;
  while (src1 != (int)src1 && *exponent <= 5) {
    src1 *= 10;
    (*exponent)++;
  }
  return src1;
}

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int status = ALLRIGHT_CONV;

  if (dst != NULL) {
    initFloatResult(dst);
    double number = 0.0;
    int sign = getSign(src);
    int exponent = getExponent(src);

    for (int i = 0; i < CORE; i++) {
      number += isBitDecimal(src.bits, i) * pow(2, i);
    }

    number /= pow(10, exponent);
    if (sign) number = -number;

    *dst = (float)number;
  } else {
    status = ERROR_CONV;
  }
  return status;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int status = ALLRIGHT_CONV;
  if (dst != NULL && !((src.bits[1] || src.bits[2]) && src.bits[0]) &&
      !(src.bits[1] && src.bits[2])) {
    initIntResult(dst);
    int exponent = getExponent(src);
    int sign = getSign(src);
    int number = src.bits[0];

    if (exponent) number /= pow(10, exponent);
    if (sign) number = -number;

    *dst = number;
  } else {
    status = ERROR_CONV;
  }

  return status;
}
