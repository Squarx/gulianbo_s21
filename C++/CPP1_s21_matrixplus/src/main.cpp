//
// Created by DimasX on 06.02.2023.
//
#include <memory>
#include "s21_matrix_oop.h"

int main() {
//  std::unique_ptr<S21Matrix>  p2(new S21Matrix(4,4));
  S21Matrix A(3,3);
  A.FillRandMatrix();
  A.print();
  A.SetRows(2);
  std::cout << "" << std::endl;
  A.print();
  return 0;
}


//S21Matrix A(3,3);
//A.FillRandMatrix();
//S21Matrix t = std::move(A);
//t.print();
//A.print();