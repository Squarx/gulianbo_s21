//
// Created by DimasX on 06.02.2023.
//
#include <memory>

#include "s21_matrix_oop.h"

int main() {
  double data[1] = {2};
  S21Matrix matrix1(data, 1, 1);
  S21Matrix tt = matrix1.InverseMatrix();
  tt.print();
  return 0;
}