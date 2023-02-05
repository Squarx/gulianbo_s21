#include "../../s21_math.h"

long double s21_floor(double x) {
  long double res = 0;
  res = s21_invalide_res(x);
  if (res == 1) {
    if (x >= 0) {
      res = (long)x;
    } else {
      if (x == (double)((long)x)) {
        res = (long)x;
      } else {
        res = (long)x - 1;
      }
    }
  }
  return res;
}