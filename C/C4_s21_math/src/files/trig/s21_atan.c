#include "../../s21_math.h"

long double s21_atan(double x) {
  long double error = 1e-15;
  long double atan = 0;
  long double next = 0;
  double flag = s21_invalide_res(x);
  if (flag != 1) {
    if (flag == 0) {
      atan = positive(flag) ? 0. : -0.0;
    } else if (flag == s21_INF) {
      atan = PI / 2;
    } else if (flag == s21_NEG_INF) {
      atan = -PI / 2;
    } else {
      atan = 0 / 0.0;
    }
  } else {
    long n = 0;
    if (x < 0 && x > -1 && (x + 1 < 1e-12)) x = -1;
    if (x > 0 && x < 1 && (1 - x < 1e-12)) x = 1;
    if (s21_fabs(x) < 1) {
      atan = x;
      next = x;
      n = 0;
      do {
        next = -1 * next * x * x * (2 * n + 1) / (2 * n + 3);
        atan += next;
        n++;
      } while (next > error || next < -error);
    } else {
      error = 1e-8;
      if (x < 0)
        atan = -PI / 2;
      else
        atan = PI / 2;
      next = -1 / x;
      atan += next;
      n = 0;
      do {
        next = -1 * next * (2 * n + 1) / (x * x * (long double)(2 * n + 3));
        atan += next;
        n++;
      } while (next > error || next < -error);
    }
  }
  return atan;
}