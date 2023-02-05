#include "s21_decimal.h"

int getSignfromNumber(int number) { return number < 0 ? 1 : 0; }

void setInf(s21_decimal *number) {
  zeroDefDecimal(number);
  setExponent(number, 28);
}

int isInf(s21_decimal number) {
  int status = NO_INF;

  if (!number.bits[0] && !number.bits[1] && !number.bits[2]) {
    if (getExponent(number) == 28) {
      if (getSign(number)) {
        status = MINUS_INF;
      } else {
        status = PLUS_INF;
      }
    }
  }
  return status;
}

void zeroDefDecimal(s21_decimal *value) {
  for (int i = 0; i < 4; i++) value->bits[i] = 0U;
}

int getSign(s21_decimal number) { return IS_SET(number.bits[3], 31) != 0; }

int getBit(int number, int index) { return IS_SET(number, index) != 0; }

void setSign_To_Pos(s21_decimal *number) { ZERO_BIT(number->bits[3], 31); }

void setSign_To_Neg(s21_decimal *number) { ADD_BIT(number->bits[3], 31); }

void conditional_set_bit(s21_decimal *number, int digit, int index, int bit) {
  if (bit == 0) {
    ZERO_BIT(number->bits[digit], index);
  } else if (bit == 1) {
    ADD_BIT(number->bits[digit], index);
  }
}

void setBit_To_Zero(s21_decimal *number, int digit, int index) {
  ZERO_BIT(number->bits[digit], index);
}

void setBit_To_One(s21_decimal *number, int digit, int index) {
  ADD_BIT(number->bits[digit], index);
}

void resetDigit(s21_decimal *number, int digit) {
  INIT_ZERO(number->bits[digit]);
}

int getExponent(s21_decimal number) {
  int res = 0;
  for (int i = START_EXPONENT, j = 0; i <= END_EXPONENT; i++, j++) {
    if (IS_SET(number.bits[3], i) != 0) {
      res += ((int)pow(2, j));
    }
  }
  return res;
}

void setExponent(s21_decimal *number, int exponent) {
  initExponent(number);
  for (int i = START_EXPONENT; i <= END_EXPONENT && exponent != 0; i++) {
    if (exponent % 2) {
      setBit_To_One(number, 3, i);
    }
    exponent /= 2;
  }
}

void initExponent(s21_decimal *number) {
  for (int i = START_EXPONENT; i <= END_EXPONENT; i++) {
    setBit_To_Zero(number, 3, i);
  }
}

int getRandom(int start, int end) {
  int result = rand() % (end - start) + start;
  return result;
}

int isBitDecimal(const int array[], int index) {
  int digit = index / 32;
  int position = index % 32;
  return IS_SET(array[digit], position) != 0;
}

void setBitDecimalOne(int array[], int index) {
  int digit = index / 32;
  int position = index % 32;
  ADD_BIT(array[digit], position);
}

void setBitDecimalZero(int array[], int index) {
  int digit = index / 32;
  int position = index % 32;
  ZERO_BIT(array[digit], position);
}

void cpyBitsDecimal(int array_1[], int array_2[], int size) {
  for (int i = 0; i < size; i++) {
    if (isBitDecimal(array_2, i)) {
      setBitDecimalOne(array_1, i);
    } else {
      setBitDecimalZero(array_1, i);
    }
  }
}

int countBits(int array[], int size) {
  int count = size - 1;
  for (; count >= 0 && !isBitDecimal(array, count); count--) {
  }
  count++;
  return count;
}

int compareBits(int array_1[], int array_2[], int size_1, int size_2) {
  int count1 = countBits(array_1, size_1);
  int count2 = countBits(array_2, size_2);

  int status = -1;

  if (count1 > count2)
    status = 1;
  else if (count1 < count2)
    status = 2;
  else {
    for (int i = count1 - 1; i >= 0; i--) {
      if (isBitDecimal(array_1, i) != isBitDecimal(array_2, i)) {
        status = isBitDecimal(array_1, i) ? 1 : 2;
        break;
      }
    }
    status = (status == -1) ? 0 : status;
  }
  return status;
}

void truncDigit(int array[], int exponent, int round) {
  int exponentBits[DIGITS] = {0};
  setBitDecimalOne(exponentBits, 0);
  for (int i = 0; i < exponent; i++) multiplyByTen(exponentBits);

  int tmp_res[DIGITS] = {0};
  int reminder[DIGITS] = {0};
  arrayDiv(array, BY * DIGITS, exponentBits, BY * DIGITS, tmp_res, BY * DIGITS,
           reminder, BY * DIGITS);

  if (round) {
    int one[1] = {0};
    setBitDecimalOne(one, 1);
    int tmp_rem[1] = {0};
    int half[DIGITS] = {0};
    arrayDiv(exponentBits, BY * DIGITS, one, BY, half, BY * DIGITS, tmp_rem,
             BY);

    if (compareBits(reminder, half, BY * DIGITS, BY * DIGITS) != 2) {
      int tmp[DIGITS] = {0};
      cpyBitsDecimal(tmp, tmp_res, BY * DIGITS);
      setBitDecimalZero(one, 1);
      setBitDecimalOne(one, 0);
      sumArrays(tmp, BY * DIGITS, one, BY, tmp_res, BY * DIGITS);
    }
  }
  cpyBitsDecimal(array, tmp_res, BY * DIGITS);
}

void arrayDiv(int div_1[], int div_1_len, int div_2[], int div_2_len, int res[],
              int res_len, int reminder[], int reminder_len) {
  zeroElems(res, res_len / BY);
  zeroElems(reminder, reminder_len / BY);

  int tmp[DIGITS] = {0};
  int start_div = countBits(div_1, div_1_len);
  int status = false;

  for (int i = start_div - 1; i >= 0; i--) {
    rightShift(reminder, reminder_len, 1);
    if (isBitDecimal(div_1, i)) {
      setBitDecimalOne(reminder, 0);
    }
    if (compareBits(reminder, div_2, reminder_len, div_2_len) != 2) {
      status = true;
      rightShift(res, res_len, 1);
      setBitDecimalOne(res, 0);
      zeroElems(tmp, DIGITS);
      cpyBitsDecimal(tmp, reminder, reminder_len);
      subArray(tmp, BY * DIGITS, div_2, div_2_len, reminder, reminder_len);
    } else {
      if (status) rightShift(res, res_len, 1);
    }
  }
}

void subArray(int array_1[], int size_1, int array_2[], int size_2, int res[],
              int res_len) {
  zeroElems(res, res_len / BY);

  int count1 = countBits(array_1, size_1);
  int count2 = countBits(array_2, size_2);

  if (!count2) cpyBitsDecimal(res, array_1, res_len);

  for (int i = 0; i < count1; i++) {
    if (isBitDecimal(array_1, i)) {
      if (!isBitDecimal(array_2, i)) setBitDecimalOne(res, i);
    } else {
      if (i < count2 && isBitDecimal(array_2, i)) {
        for (int j = i + 1; j < count1; j++) {
          if (isBitDecimal(array_1, j)) {
            if (j == (count1 - 1)) count1--;
            setBitDecimalZero(array_1, j);
            break;
          } else {
            setBitDecimalOne(array_1, j);
          }
        }
        setBitDecimalOne(res, i);
      } else {
        if (isBitDecimal(array_1, i)) setBitDecimalOne(res, i);
      }
    }
  }
}

void multiplyByTen(int array[]) {
  int ten[1] = {10};
  int res[DIGITS];
  multiplyArrays(array, ten, BY, res, BY * DIGITS);
  cpyBitsDecimal(array, res, BY * DIGITS);
}

void multiplyArrays(int array_1[], int array_2[], int size_1, int res[],
                    int size_2) {
  zeroElems(res, size_2 / BY);
  int cpy[DIGITS];
  cpyBitsDecimal(cpy, array_1, BY * DIGITS);
  int tmp[DIGITS] = {0};
  for (int i = 0; i < countBits(array_2, size_1); i++) {
    if (isBitDecimal(array_2, i)) {
      sumArrays(res, BY * DIGITS, cpy, BY * DIGITS, tmp, BY * DIGITS);
      cpyBitsDecimal(res, tmp, size_2);
    }
    rightShift(cpy, BY * DIGITS, 1);
  }
  cpyBitsDecimal(res, tmp, size_2);
}

void sumArrays(int array_1[], int size_1, int array_2[], int size_2,
               int result[], int size) {
  zeroElems(result, size / BY);
  int reminder = 0;
  for (int i = 0; i < size; i++) {
    int x = (i >= size_1) ? 0 : isBitDecimal(array_1, i);
    int y = (i >= size_2) ? 0 : isBitDecimal(array_2, i);
    reminder += (x + y);
    if (reminder % 2) {
      setBitDecimalOne(result, i);
    }
    reminder = (reminder > 1) ? 1 : 0;
  }
}

void rightShift(int arrays[], int size, int many) {
  for (int i = 0; i < many; i++) {
    int array = isBitDecimal(arrays, 0);
    setBitDecimalZero(arrays, 0);
    for (int j = 0; j < size - 1; j++) {
      if (array) {
        array = isBitDecimal(arrays, j + 1);
        setBitDecimalOne(arrays, j + 1);
      } else {
        array = isBitDecimal(arrays, j + 1);
        setBitDecimalZero(arrays, j + 1);
      }
    }
  }
}

void zeroElems(int array[], int size) {
  for (int i = 0; i < size; i++) {
    array[i] = 0;
  }
}

void initDecResult(s21_decimal *result) { zeroDefDecimal(result); }

void initFloatResult(float *result) { *result = 0.0; }

void initIntResult(int *result) { *result = 0; }

void initDecimalThree(s21_decimal *number_1, s21_decimal *number_2,
                      s21_decimal *number_3) {
  zeroDefDecimal(number_1);
  zeroDefDecimal(number_2);
  zeroDefDecimal(number_3);
}

void print_decimal(s21_decimal value) {
  for (int i = 3; i >= 0; --i) {
    for (int j = 31; j >= 0; --j) {
      printf("%u", IS_SET(value.bits[i], j) != 0);
    }
    if (i != 0) printf(" | ");
  }
  printf("\n");
}
