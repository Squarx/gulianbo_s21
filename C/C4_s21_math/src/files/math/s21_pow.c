#include "../../s21_math.h"

long double s21_pow(double base, double exp) {
  long double res = 0;
  double flag_base = s21_invalide_res(base);
  double flag_exp = s21_invalide_res(exp);
  if (flag_base != 1) {
    if (base == 0 && exp == 0) res = 1;
    if (flag_base == 0 && exp != 0) res = flag_base;
    if (flag_base != flag_base) res = 0 / 0.;
    if (flag_base == s21_INF) res = s21_INF;
    if (flag_base == -s21_INF) res = -s21_INF;
  }
  if (flag_exp != 1) {
    if (flag_exp != flag_exp) res = s21_NAN;
    if (flag_exp == -s21_INF || flag_exp == s21_INF) {
      if (base == 0) {
        res = flag_exp == s21_INF ? 0 : s21_INF;
      } else {
        if (flag_exp == s21_INF && base == base) res = s21_INF;
        if (flag_exp == -s21_INF && base == base) res = 0;
        if (base != base) res = 0. / 0.;
      }
    }
    if (flag_exp == 0) res = 1;
  }
  if (flag_base == 1 && flag_exp == 1) {
    int sign = 1;
    if (base < 0 && ((double)exp != (int)exp)) {
      res = s21_NAN;
    } else {
      if (base < 0) {
        if ((int)exp % 2) sign = -1;
        base = -base;
      }
      long double cust_pow = (exp * s21_log(base));
      res = (long double)sign * s21_exp((double)cust_pow);
    }
  }
  return res;
}
