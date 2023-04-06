//
// Created by DimasX on 06.02.2023.
//
#include <memory>

#include "s21_matrix_oop.h"

int main() {
  S21Matrix matrix1(2, 2);
  printf("%f\n", matrix1(0, 0));
  matrix1(0, 0) = 5;
  printf("%f\n", matrix1(0, 0));
  return 0;
}