//
// Created by DimasX on 06.02.2023.
//
#include <memory>
#include "s21_matrix.h"

int main() {
//  std::unique_ptr<S21Matrix>  p2(new S21Matrix(4,4));
  S21Matrix A(3,3);
  A.S21_Fill();
  A.Set_col(5);
  A.S21_Print();

//  B = B * 2;
//  A = A - B;
  std::cout << A(2,1) << std::endl;
//   std::cout << "DET = " << A.Determinant() << std::endl;

  return 0;
}
