//
// Created by DimasX on 06.02.2023.
//
#include <memory>
#include "s21_matrix.h"


int main() {
  S21Matrix A = S21Matrix();
  A.S21_Fill();
//  A.S21_Print();
  S21Matrix B = S21Matrix(3, 1);
  B.S21_Fill();
//  B.S21_Print();
  A.MulMatrix(B);
  A.S21_Print();
//  std::unique_ptr<S21Matrix>  p2(new S21Matrix(4,4));
  return 0;
}
