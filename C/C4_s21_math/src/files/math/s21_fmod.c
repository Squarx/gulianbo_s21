#include "../../s21_math.h"

long double s21_fmod(double x, double y) {
  long double res = 0;
  double flag_base = s21_invalide_res(x);
  double flag_y = s21_invalide_res(y);
  if (flag_base != 1) {
    if (flag_base == 0) {
      res = positive(flag_base) ? 0 : -0.;
    } else {
      res = 0 / 0.;
    }
  }
  if (flag_y != 1) {
    if (flag_y == s21_INF || flag_y == s21_NEG_INF) {
      if (flag_base == 1 || flag_base == 0)
        res = x;
      else
        res = 0 / 0.;
    } else
      res = 0 / 0.;
  }
  if (flag_base == 1 && flag_y == 1) {
    long long main_part = 0;
    main_part = (long long)(x / y);
    res = (x - y * (long double)main_part);
  }
  return res;
}