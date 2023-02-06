//
// Created by DimasX on 06.02.2023.
//
#include <iostream>
#include <cmath>
#include <cstring>

#ifndef CPP1_S21_MATRIXPLUS_SRC_S21_MATRIX_H_
#define CPP1_S21_MATRIXPLUS_SRC_S21_MATRIX_H_
enum {
  FAILURE,
  SUCCESS
};
class S21Matrix {
 private:
  // attributes
  int _rows, _cols;                                           // rows and columns attributes
  double **_p = nullptr;                                                // pointer to the memory where the matrix will be allocated

 public:
  S21Matrix();                                                // default constructor
  S21Matrix(int rows, int cols);                              // parameterized constructor
  S21Matrix(const S21Matrix& other);                            // copy cnstructor
  S21Matrix(S21Matrix&& other) noexcept;                       // move cnstructor
  ~S21Matrix();                                               // destructor
  void set(int i, int j, int val) {
    _p[i][j] = val;
  }

  // some operators overloads
  S21Matrix& operator=(const S21Matrix& o);                   // assignment operator overload
  int& operator()(int row, int col);                          // index operator overload
  int& operator()(int row, int col) const;
  S21Matrix& operator+=(const S21Matrix& o);
  S21Matrix operator+(const S21Matrix& o);
  S21Matrix& operator-=(const S21Matrix& o);
  S21Matrix operator-(const S21Matrix& o);

  // some public methods
  bool EqMatrix(const S21Matrix& other);
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& other);
  S21Matrix CalcComplements();
  S21Matrix Transpose();
  double Determinant();
  S21Matrix InverseMatrix();
  S21Matrix Minor(int row_skip, int col_skip);
  void delete_matrix(S21Matrix* A);
  void create_matrix(S21Matrix* A, int rows, int cols);
  void S21_Print();
  void S21_Fill();
};
#endif //CPP1_S21_MATRIXPLUS_SRC_S21_MATRIX_H_
