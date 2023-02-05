#include "../../s21_math.h"
long double s21_log(double x) {
  long double res = 0;
  int optimisation = 0;
  if (x < 0 || x == 1) {
    if (x == 1.)
      res = 0;
    else
      res = 0 / 0.;
  } else {
    double flag = s21_invalide_res(x);
    if (flag != 1) {
      if (x == 0) {
        res = s21_NEG_INF;
      } else {
        res = x == s21_INF ? s21_INF : s21_NAN;
      }
    } else {
      if (x > EXP) {
        while (x > EXP) {
          x = x / EXP;
          optimisation++;
        }
      }
      if (x < EXP) {
        while (x < EXP) {
          x = x * EXP;
          optimisation--;
        }
      }
      long double num = (x - 1) / (x + 1);
      res += num;
      long double error = 1e-18;
      long double next = num;
      int n = 0;
      if (x != 0) {
        do {
          next = next * num * num * (2 * n + 1) / (2 * n + 3);
          res += next;
          n++;
        } while (res != 0 && next != 0 && (next > error || next < -error));
      }
      res = 2 * res + optimisation;
    }
  }
  return res;
}