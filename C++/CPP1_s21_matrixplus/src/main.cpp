//
// Created by DimasX on 06.02.2023.
//
#include <memory>
#include "s21_matrix.h"


int main() {
//  S21Matrix A = S21Matrix(4,4);
//  std::unique_ptr<S21Matrix>  p2(new S21Matrix(4,4));
//  p2->S21_Fill();
////  p2->S21_Print();
//  A.S21_Fill();
//  A.SubMatrix(*p2);
//  A.S21_Print();
//  std::cout << "RES = " << A.EqMatrix(*p2) << std::endl;
//  A.S21_Print();
  S21Matrix A = S21Matrix(4,4);
  A.S21_Fill();
  S21Matrix B(A);
  B.S21_Print();

  S21Matrix C(std::move(A));
  C.S21_Print();
  A.S21_Print();
  return 0;
}
