#include "s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  zeroDefDecimal(result);
  int sign_1 = !getSign(value_1);
  int sign_2 = !getSign(value_2);
  int status = -1;

  if (sign_1) {
    if (!sign_2) {
      s21_decimal tmp_1;
      setSign_To_Pos(&tmp_1);
      cpyBitsDecimal(tmp_1.bits, value_2.bits, ALL - 1);
      status = s21_sub(value_1, tmp_1, result);
    }
  } else {
    if (sign_2) {
      s21_decimal tmp_1;
      setSign_To_Pos(&tmp_1);
      cpyBitsDecimal(tmp_1.bits, value_1.bits, ALL - 1);
      status = s21_sub(value_2, tmp_1, result);
    } else {
      setSign_To_Neg(result);
    }
  }

  if (status == -1) {
    int exponent_1 = getExponent(value_1);
    int exponent_2 = getExponent(value_2);
    int val1[DIGITS] = {0};
    int val2[DIGITS] = {0};
    int add_res[DIGITS] = {0};
    cpyBitsDecimal(val1, value_1.bits, CORE);
    cpyBitsDecimal(val2, value_2.bits, CORE);

    while (exponent_1 != exponent_2) {
      if (exponent_1 > exponent_2) {
        multiplyByTen(val2);
        exponent_2++;
      } else {
        multiplyByTen(val1);
        exponent_1++;
      }
    }

    sumArrays(val1, BY * DIGITS, val2, BY * DIGITS, add_res, BY * DIGITS);

    if (countBits(add_res, BY * DIGITS) > CORE) {
      int count = 0;
      int tmp[DIGITS] = {0};
      cpyBitsDecimal(tmp, add_res, BY * DIGITS);
      while (countBits(tmp, BY * DIGITS) > CORE) {
        truncDigit(tmp, 1, 1);
        count++;
      }
      if (count <= exponent_1) {
        if (count) {
          truncDigit(add_res, count, 1);
          exponent_1 -= count;
        }
      } else {
        status = 1 + getSign(*result);
        setExponent(result, 28);
      }
    }

    if (status == -1) {
      status = OK;
      setExponent(result, exponent_1);
      cpyBitsDecimal(result->bits, add_res, CORE);
    }
  }

  return status;
}

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  zeroDefDecimal(result);
  int sign_1 = !getSign(value_1);
  int sign_2 = !getSign(value_2);
  int status = -1;

  if (sign_1) {
    if (!sign_2) {
      setSign_To_Pos(&value_2);
      status = s21_add(value_1, value_2, result);
    }
  } else {
    if (!sign_2) {
      s21_decimal tmp_1;
      setSign_To_Pos(&tmp_1);
      cpyBitsDecimal(tmp_1.bits, value_1.bits, ALL - 1);
      setSign_To_Pos(&tmp_1);

      s21_decimal tmp_2;
      setSign_To_Pos(&tmp_2);
      cpyBitsDecimal(tmp_2.bits, value_2.bits, ALL - 1);
      setSign_To_Pos(&tmp_2);

      status = s21_sub(tmp_2, tmp_1, result);
    } else {
      s21_decimal tmp_val;
      setSign_To_Pos(&tmp_val);
      cpyBitsDecimal(tmp_val.bits, value_2.bits, ALL - 1);
      setSign_To_Neg(&tmp_val);
      status = s21_add(value_1, tmp_val, result);
    }
  }

  if (status == -1) {
    if (sign_1) {
      setSign_To_Pos(result);
    }
    int exponent_1 = getExponent(value_1);
    int exponent_2 = getExponent(value_2);
    int val_1[DIGITS] = {0};
    int val_2[DIGITS] = {0};
    int sub_res[DIGITS] = {0};
    cpyBitsDecimal(val_1, value_1.bits, CORE);
    cpyBitsDecimal(val_2, value_2.bits, CORE);

    while (exponent_1 != exponent_2) {
      if (exponent_1 > exponent_2) {
        multiplyByTen(val_2);
        exponent_2++;
      } else {
        multiplyByTen(val_1);
        exponent_1++;
      }
    }

    int comp = compareBits(val_1, val_2, BY * DIGITS, BY * DIGITS);
    if (comp == 1) {
      subArray(val_1, BY * DIGITS, val_2, BY * DIGITS, sub_res, BY * DIGITS);
    } else if (comp == 2) {
      subArray(val_2, BY * DIGITS, val_1, BY * DIGITS, sub_res, BY * DIGITS);
      if (sign_1) {
        setSign_To_Neg(result);
      } else {
        setSign_To_Pos(result);
      }
    } else {
      setSign_To_Pos(result);
    }

    int count = 0;
    int tmp_res[DIGITS] = {0};
    cpyBitsDecimal(tmp_res, sub_res, BY * DIGITS);
    while (countBits(tmp_res, BY * DIGITS) > CORE) {
      truncDigit(tmp_res, 1, 1);
      count++;
    }
    if (count <= exponent_1) {
      if (count) {
        truncDigit(sub_res, count, 1);
        exponent_1 -= count;
      }
    } else {
      status = 1 + getSign(*result);
      setExponent(result, 28);
    }

    if (status == -1) {
      status = OK;
      setExponent(result, exponent_1);
      cpyBitsDecimal(result->bits, sub_res, CORE);
    }
  }

  return status;
}

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  zeroDefDecimal(result);

  int status = -1;

  if (!isInf(value_2)) {
    status = OK;
  } else if (!countBits(value_2.bits, CORE)) {
    status = DIV_TO_NULL;
  }

  if (status == -1) {
    int sign = (getSign(value_1) != getSign(value_2));
    int exponent = getExponent(value_1) - getExponent(value_2);

    int resultArray[7] = {0};

    int valOne[7] = {0};
    cpyBitsDecimal(valOne, value_1.bits, CORE);

    int valTwo[3] = {0};
    cpyBitsDecimal(valTwo, value_2.bits, CORE);

    while (exponent < 0) {
      multiplyByTen(valOne);
      exponent++;
    }

    int rem[7] = {0};

    arrayDiv(valOne, DIGITS * BY, valTwo, CORE, resultArray, DIGITS * BY, rem,
             DIGITS * BY);

    while (countBits(rem, DIGITS * BY) > 0 && exponent < 28) {
      multiplyByTen(valOne);
      arrayDiv(valOne, DIGITS * BY, valTwo, CORE, resultArray, DIGITS * BY, rem,
               DIGITS * BY);
      exponent++;
    }

    int count = 0;
    int tmp[7] = {0};
    cpyBitsDecimal(tmp, resultArray, DIGITS * BY);
    while (countBits(tmp, DIGITS * BY) > CORE) {
      truncDigit(tmp, 1, 1);
      count++;
    }

    if (count <= exponent) {
      if (count) {
        truncDigit(resultArray, count, 1);
        exponent -= count;
      }
    } else {
      status = 1 + getSign(*result);
      setExponent(result, 28);
    }

    if (status == -1) {
      status = OK;
      cpyBitsDecimal(result->bits, resultArray, CORE);
      setExponent(result, exponent);
      if (sign) {
        setSign_To_Neg(result);
      }
    }
  }
  return status;
}

int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  zeroDefDecimal(result);

  int status = -1;
  int sign = !getSign(value_1);

  int val_1[DIGITS] = {0};
  cpyBitsDecimal(val_1, value_1.bits, CORE);
  int val_2[DIGITS] = {0};
  cpyBitsDecimal(val_2, value_2.bits, CORE);

  int exponent_1 = getExponent(value_1);
  int exponent_2 = getExponent(value_2);

  while (exponent_1 != exponent_2) {
    if (exponent_1 > exponent_2) {
      multiplyByTen(val_2);
      exponent_2++;
    } else {
      multiplyByTen(val_1);
      exponent_1++;
    }
  }

  int res[DIGITS] = {0};
  int rem[DIGITS] = {0};
  arrayDiv(val_1, BY * DIGITS, val_2, BY * DIGITS, res, BY * DIGITS, rem,
           BY * DIGITS);

  int tmp[DIGITS] = {0};
  if (!sign) {
    cpyBitsDecimal(tmp, res, BY * DIGITS);

    int one[1] = {0};
    setBitDecimalOne(one, 0);

    sumArrays(tmp, BY * DIGITS, one, BY, res, BY * DIGITS);
  }

  cpyBitsDecimal(tmp, res, BY * DIGITS);
  multiplyArrays(val_2, tmp, BY * DIGITS, res, BY * DIGITS);
  cpyBitsDecimal(tmp, res, BY * DIGITS);

  if (sign) {
    subArray(val_1, BY * DIGITS, tmp, BY * DIGITS, res, BY * DIGITS);
  } else {
    subArray(tmp, BY * DIGITS, val_1, BY * DIGITS, res, BY * DIGITS);
  }

  int count = 0;
  int resArray[DIGITS] = {0};
  cpyBitsDecimal(resArray, res, BY * DIGITS);
  while (countBits(resArray, BY * DIGITS) > CORE) {
    truncDigit(resArray, 1, 1);
    count++;
  }

  if (count <= exponent_1) {
    if (count) {
      truncDigit(res, count, 1);
      exponent_1 -= count;
    }
  } else {
    status = MORE_OR_INF;
    setExponent(result, MAX_EXPONENT);
  }

  if (status == -1) {
    status = OK;
    cpyBitsDecimal(result->bits, res, CORE);
    setExponent(result, exponent_1);
  }

  return status;
}
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  zeroDefDecimal(result);
  int status = OK;

  int exponent = getExponent(value_1) + getExponent(value_2);

  int sign = getSign(value_1) != getSign(value_2);

  int res[DIGITS] = {0};
  int val[DIGITS] = {0};
  cpyBitsDecimal(val, value_1.bits, CORE);

  multiplyArrays(val, value_2.bits, CORE, res, BY * DIGITS);

  if (countBits(res, DIGITS) > CORE) {
    int count = 0;
    int tmp_res[DIGITS] = {0};
    cpyBitsDecimal(tmp_res, res, BY * DIGITS);
    while (countBits(tmp_res, BY * DIGITS) > CORE) {
      truncDigit(tmp_res, 1, 1);
      count++;
    }
    if (count <= exponent) {
      if (count) {
        truncDigit(res, count, 1);
        exponent -= count;
      }
    } else {
      status = 1 + getSign(*result);
      setExponent(result, 28);
    }
  }

  if (status == OK) {
    cpyBitsDecimal(result->bits, res, CORE);
    setExponent(result, exponent);
    if (sign) {
      setSign_To_Neg(result);
    }
  }

  return status;
}

void mod_div_for_mul(unsigned int *tmp_mod, long double *tmp_div_res,
                     long double tmp) {
  unsigned int tmp_div = 0;
  tmp_div = (unsigned int)(tmp / 4294967295);
  *tmp_mod = (unsigned int)(tmp - (tmp_div * 4294967295));
  *tmp_div_res = (long double)tmp_div;
}

int mul_overflow(s21_decimal *result, long double tmp, int flag) {
  unsigned int tmp_0_mod = 0, tmp_1_mod = 0;
  long double tmp_0 = 0, tmp_1 = 0;
  int status = 0;
  if (tmp > 4294967295) {
    if (flag == 0) {
      mod_div_for_mul(&tmp_0_mod, &tmp_0,
                      tmp);  // tmp_0 = (long int)(tmp / 4294967295);
      result->bits[0] =
          (int)tmp_0_mod;  // tmp_0_mod = tmp - (tmp_0 * 4294967295);
    } else {
      tmp_0 = tmp;
    }
    if (tmp_0 > 4294967295) {
      if (flag <= 1) {
        mod_div_for_mul(&tmp_0_mod, &tmp_1,
                        tmp_0);  // tmp_1 = tmp_0 / 4294967295;
        result->bits[1] =
            (int)tmp_1_mod;  // tmp_1_mod = tmp_0 - (tmp_1 * 4294967295);
      } else {
        tmp_1 = tmp;
      }
      if (tmp_1 > 4294967295) {
        status = MORE_OR_INF;
      } else {
        result->bits[2] = (int)tmp_1;
      }
    } else {
      result->bits[1] = (int)tmp_0;
    }
  } else {
    result->bits[flag] = (int)tmp;
  }
  return status;
}