//
// Created by DimasX on 06.02.2023.
//
#include <memory>
#include "s21_matrix.h"


int main() {
//  std::unique_ptr<S21Matrix>  p2(new S21Matrix(4,4));
  S21Matrix A = S21Matrix();
   A.S21_Fill();
  A.S21_Print();
  A.set(0, 1, 2);
//  A._p[0][1] = 2;
   S21Matrix CALC = A.InverseMatrix();
   CALC.S21_Print();
   CALC.MulMatrix(A);
   CALC.S21_Print();
//   std::cout << "DET = " << A.Determinant() << std::endl;

  return 0;
}
