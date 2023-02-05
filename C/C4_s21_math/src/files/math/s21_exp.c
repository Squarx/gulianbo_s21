#include "../../s21_math.h"
long double s21_exp(double x) {
  long double res = 0;
  if (x == s21_INF || x == -s21_INF || x == s21_NAN) {
    if (x == s21_INF) res = s21_INF;
    if (x == -s21_INF) res = 0;
    if (x == s21_NAN) res = s21_NAN;
  } else {
    if (x < 0) {
      res = 1 / s21_exp(-x);
    } else {
      long double err = 1e-18;
      res = 1 + x;
      long double next = (long double)x;
      unsigned long n = 1;
      do {
        next = next * x / (n + 1);
        res += next;
        n++;
      } while ((next > err || next < -err) && next < (double)1 / 0. &&
               res < (double)1 / 0.);
    }
  }
  return res;
}