//
// Created by DimasX on 06.02.2023.
//
#include <cmath>
#include <cstring>
#include <iostream>

#ifndef CPP1_S21_MATRIXPLUS_SRC_S21_MATRIX_H_
#define CPP1_S21_MATRIXPLUS_SRC_S21_MATRIX_H_

class S21Matrix {
 public:
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const double *data, int rows, int cols);
  S21Matrix(const S21Matrix &other);
  S21Matrix(S21Matrix &&other) noexcept;
  ~S21Matrix();

  void setValue(int row, int col, double val);
  int GetRows() const;
  int GetCols() const;
  void SetRows(int row);
  void SetCols(int col);

  S21Matrix &operator=(const S21Matrix &other);
  S21Matrix operator+(const S21Matrix &other);
  S21Matrix operator-(const S21Matrix &other);
  S21Matrix operator*(double num);
  S21Matrix operator*(const S21Matrix &other);
  S21Matrix &operator+=(const S21Matrix &other);
  S21Matrix &operator-=(const S21Matrix &other);
  S21Matrix &operator*=(const S21Matrix &other);
  S21Matrix &operator*=(double num);
  bool operator==(const S21Matrix &other);
  double &operator()(int row, int col);

  bool EqMatrix(const S21Matrix &other);
  void SumMatrix(const S21Matrix &other);
  void SubMatrix(const S21Matrix &other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix &other);
  S21Matrix CalcComplements();
  S21Matrix Transpose();
  double Determinant();
  S21Matrix InverseMatrix();

  void Print();
  void FillInt();
  void FillRandMatrix();

 private:
  int _rows, _cols;
  double **_matrix = nullptr;
  void DeleteMatrix(S21Matrix *A);
  void CreateMatrix(S21Matrix *A, int rows, int cols);
  void CopyData(S21Matrix *dest, const S21Matrix &src);
  void SetZero();
  S21Matrix Minor(int row_skip, int col_skip);
};

#endif  // CPP1_S21_MATRIXPLUS_SRC_S21_MATRIX_H_
