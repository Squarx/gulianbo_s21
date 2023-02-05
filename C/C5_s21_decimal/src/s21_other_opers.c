#include "s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
  zeroDefDecimal(result);
  int status = OK;

  int exponent = getExponent(value);
  if (exponent) {
    int tmp_1[7] = {0};
    cpyBitsDecimal(tmp_1, value.bits, CORE);
    truncDigit(tmp_1, exponent, 0);
    if (getSign(value)) {
      setSign_To_Neg(result);
      int tmp_2[1] = {0};
      setBitDecimalOne(tmp_2, 0);
      int tmp_3[DIGITS] = {0};
      sumArrays(tmp_1, DIGITS * BY, tmp_2, BY, tmp_3, DIGITS * BY);
      cpyBitsDecimal(tmp_1, tmp_3, DIGITS * BY);
    }
    cpyBitsDecimal(result->bits, tmp_1, CORE);
  } else {
    cpyBitsDecimal(result->bits, value.bits, ALL);
  }
  return status;
}

int s21_negate(s21_decimal value, s21_decimal *result) {
  cpyBitsDecimal(result->bits, value.bits, ALL);
  if (getSign(value))
    setSign_To_Pos(result);
  else
    setSign_To_Neg(result);
  return 0;
}

int s21_round(s21_decimal value, s21_decimal *result) {
  zeroDefDecimal(result);
  int status = OK;

  int exponent = getExponent(value);
  if (exponent) {
    int tmp[DIGITS] = {0};
    cpyBitsDecimal(tmp, value.bits, CORE);
    truncDigit(tmp, exponent, 1);
    if (getSign(value)) {
      setSign_To_Neg(result);
    }
    cpyBitsDecimal(result->bits, tmp, CORE);
  } else {
    cpyBitsDecimal(result->bits, value.bits, ALL);
  }
  return status;
}

int s21_truncate(s21_decimal value, s21_decimal *result) {
  zeroDefDecimal(result);
  int status = ALLRIGHT_OTHER;

  if (result != NULL) {
    int exponent = getExponent(value);
    if (exponent) {
      int tmp[DIGITS] = {0};
      cpyBitsDecimal(tmp, value.bits, CORE);
      truncDigit(tmp, exponent, 0);
      if (getSign(value)) setSign_To_Neg(result);
      cpyBitsDecimal(result->bits, tmp, CORE);
    } else {
      cpyBitsDecimal(result->bits, value.bits, ALL);
    }
  } else {
    status = ERROR_OTHER;
  }
  return status;
}
