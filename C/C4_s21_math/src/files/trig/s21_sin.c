#include "../../s21_math.h"
long double s21_sin(double x) {
  double flag = s21_invalide_res(x);
  long double sin = 0;
  if (flag == s21_INF || flag == s21_NEG_INF || flag == s21_NEG_ZERO) {
    if (flag == 0) {
      sin = positive(x) ? 0. : -0.;
    } else {
      sin = 0 / 0.;
    }
  } else {
    long double tmp = x;
    format_rad(&tmp);
    long double error = 1e-18;
    sin = tmp;
    long double next = tmp;
    int n = 0;
    do {
      next = -1 * next * (tmp * tmp) / (((2 * n + 2) * (2 * n + 3)));
      sin += next;
      n++;
    } while (next > error || next < -error);
  }
  return sin;
}