//
// Created by DimasX on 06.02.2023.
//
#include <chrono>
#include <memory>

#include "s21_matrix_oop.h"

int main() {
  S21_Project::S21Matrix matrix1(1000, 1000);
  S21_Project::S21Matrix matrix3(1000, 1000);
  matrix1.FillRandMatrix();
  matrix3.FillRandMatrix();
  auto start = std::chrono::high_resolution_clock::now();
  S21_Project::S21Matrix matrix2 = std::move(matrix1);
  S21_Project::S21Matrix matrix4(std::move(matrix3));
  auto end = std::chrono::high_resolution_clock::now();
  auto duration_ms =
      std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  std::cout << "Time elapsed: " << duration_ms.count() << " ms" << std::endl;
  return 0;
}