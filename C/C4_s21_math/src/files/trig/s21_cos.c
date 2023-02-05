#include "../../s21_math.h"

long double s21_cos(double x) {
  double flag = s21_invalide_res(x);
  long double cos = 1;
  if (flag == s21_INF || flag == s21_NEG_INF) {
    cos = 0. / 0.;
  } else {
    long double tmp = x;
    format_rad(&tmp);
    long double error = 1e-18;
    long double next = 1;
    int n = 1;
    do {
      next = -1 * next * (tmp * tmp) / (2 * n * (2 * n - 1));
      cos += next;
      n++;
    } while (next > error || next < -error);
  }
  return cos;
}