//
// Created by DimasX on 26.12.2022.
//
#include "../../s21_math.h"
void format_rad(long double* x) {
  if (*x > 2 * PI) {
    for (; *x > 2 * PI;) {
      *x -= 2 * PI;
    }
  }
  if (*x < -2 * PI) {
    for (; *x < -2 * PI;) {
      *x += 2 * PI;
    }
  }
}

int positive(long double num) {
  double b = (double)num;
  int c = (((*((long long*)&b)) & ((long long)1 << 63)) == 0);
  return c;
}
/**
 * @brief возвращает 1 если все ок или:| inf -inf nan +0 -0|
 * @param x
 * @return
 */
double s21_invalide_res(double x) {
  double res = 1;
  if (x == 0) res = positive((long double)x) ? 0. : -0.;
  if (x != x) res = 0 / .0;
  if (x == s21_INF) res = s21_INF;
  if (x == s21_NEG_INF) res = s21_NEG_INF;
  return res;
}