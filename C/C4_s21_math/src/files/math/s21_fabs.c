#include "../../s21_math.h"
long double s21_fabs(double x) {
  long double res = s21_invalide_res(x);
  if (res != 1) {
    if (x == s21_NEG_INF) res = s21_INF;
    if (x == s21_NEG_ZERO) res = 0.0;
  } else {
    res = (x > 0) ? x : -x;
  }
  return res;
}