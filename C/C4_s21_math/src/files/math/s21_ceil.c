#include "../../s21_math.h"
long double s21_ceil(double x) {
  long double res = s21_invalide_res(x);
  if (res == 1) {
    if (x > 0) {
      res = (long double)(x == (int)x) ? (long long)x : ((long long)x + 1);
    } else {
      if (x < 0 && -1 < x)
        res = -0.;
      else
        res = ((long long)x);
    }
  }
  return res;
}