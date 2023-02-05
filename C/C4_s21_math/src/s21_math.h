//
// Created by DimasX on 25.12.2022.
//
#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#ifndef C4_S21_MATH_0_SRC_S21_MATH_H_
#define C4_S21_MATH_0_SRC_S21_MATH_H_
#define PI 3.14159265358979323846264338327950288
#define EXP 2.71828182845904523536
// for test
#define s21_ZERO (0.0)
#define s21_NEG_ZERO (-0.0)
#define s21_NAN (0 / 0.)
#define s21_INF (1 / 0.)
#define s21_NEG_INF (1 / -0.)
long double s21_power_int(long double x, int pow);
unsigned long long s21_factorial(int x);
void format_rad(long double* x);
int s21_nand(double x);
int positive(long double num);
int s21_inf_test(double x);
int s21_abs(int x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);
unsigned long long s21_factorial_skip1(int x);
double s21_invalide_res(double x);
#endif  // C4_S21_MATH_0_SRC_S21_MATH_H_
