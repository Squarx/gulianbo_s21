#include "../../s21_math.h"
long double s21_sqrt(double x) {
  long double res = 0;
  if (x >= 0) {
    res = s21_pow(x, 0.5);
  } else {
    res = 0 / -0.;
  }
  return res;
}