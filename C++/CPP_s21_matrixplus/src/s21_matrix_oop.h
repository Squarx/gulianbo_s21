//
// Created by DimasX on 06.02.2023.
//
#ifndef CPP1_S21MATRIX_PLUS_SRC_S21MATRIX_H_
#define CPP1_S21MATRIX_PLUS_SRC_S21MATRIX_H_

#include <cmath>
#include <cstring>
#include <iostream>

class S21Matrix {
 public:
  S21Matrix();  // Конструктор по умолчанию
  S21Matrix(int rows, int cols);
  S21Matrix(const double *data, int rows, int cols);
  S21Matrix(const S21Matrix &other);  // Конструктор копирования
  S21Matrix(S21Matrix &&other) noexcept;  // Конструктор перемещения
  ~S21Matrix();

  void SetValue(int row, int col, double val);
  int GetRows() const;
  int GetCols() const;
  void SetRows(int row);
  void SetCols(int col);

  S21Matrix &operator=(const S21Matrix &other);  // Оператор присваивания
  S21Matrix &operator=(S21Matrix &&other) noexcept;  // Оператор перемещения!
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
  double operator()(int row, int col) const;

  bool EqMatrix(const S21Matrix &other);
  void SumMatrix(const S21Matrix &other);
  void SubMatrix(const S21Matrix &other);
  void MulNumber(double num);
  void MulMatrix(const S21Matrix &other);
  S21Matrix CalcComplements();
  S21Matrix Transpose();
  double Determinant();
  S21Matrix InverseMatrix();

  void Print();
  void FillInt();
  void FillRandMatrix();
  void ClearMatrix();

 private:
  int rows_, cols_;
  double **matrix_ = nullptr;
  void DeleteMatrix(S21Matrix *A);
  void CreateMatrix(S21Matrix *A, int rows, int cols);
  static void CopyData(S21Matrix *dest, const S21Matrix &src);
  S21Matrix Minor(int row_skip, int col_skip);
};

#endif  // CPP1_S21MATRIX_PLUS_SRC_S21MATRIX_H_
