#include "../../s21_math.h"

long double s21_asin(double x) {
  long double error = 1e-18;
  int fail = 0;
  long double asin = x;
  long double next = x;
  int n = 0;
  if (x > 0.9 && x < 1) {
    if (1 - x < 1e-10) x = 1;
  }
  if (x < -0.9 && x > -1) {
    if (x + 1 < 1e-10) x = -1;
  }
  if (x >= 1 || x <= -1) {
    fail = 1;
    if (x == 1 || x == -1) {
      if (x == 1)
        asin = PI / 2;
      else
        asin = -PI / 2;
    } else {
      asin = 0 / 0.;
    }
  }
  if (!fail) {
    do {
      next = next * ((2 * n + 1.) * (2 * n + 1.) * (2 * n + 2.) * x * x) /
             (4. * (n + 1.) * (n + 1.) * (2. * n + 3.));
      asin += next;
      n++;
    } while (next > error || next < -error);
  }
  return asin;
}