//
// Created by DimasX on 25.12.2022.
//
#include "../s21_math.h"

int main() {
  for (double i = -1; i <= -0.9998;) {
    char orig[100] = {0}, our[100] = {0};
    sprintf(orig, "%.10f", asin(-i));
    sprintf(our, "%.10Lf", s21_asin(-i));
    printf("orig = %s\nmy =   %s\n*********\n", orig, our);
    i += 0.0001;
  }
  return 0;
}