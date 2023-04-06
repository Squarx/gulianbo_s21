//
// Created by DimasX on 06.02.2023.
//
#include <cmath>
#include <cstring>
#include <iostream>

#ifndef CPP1_S21_MATRIXPLUS_SRC_S21_MATRIX_H_
#define CPP1_S21_MATRIXPLUS_SRC_S21_MATRIX_H_
enum { FAILURE, SUCCESS };

class S21Matrix {
 private:
  // attributes
  int _rows, _cols;  // rows and columns attributes
  double **_matrix =
      nullptr;  // pointer to the memory where the matrix will be allocated

 public:
  S21Matrix();                    // default constructor
  S21Matrix(int rows, int cols);  // parameterized constructor
  S21Matrix(const double *data, int rows, int cols);

  S21Matrix(const S21Matrix &other);  // copy costructor

  S21Matrix(S21Matrix &&other) noexcept;  // move costructor
  ~S21Matrix();                           // destructor
  void setValue(int row, int col, double val);

  int GetRows() const;

  int GetCols() const;

  void SetRows(int row);

  void SetCols(int col);

  // some operators overloads
  S21Matrix &operator=(const S21Matrix &other);  // assignment operator overload
  S21Matrix operator+(const S21Matrix &other);

  S21Matrix operator-(const S21Matrix &other);

  S21Matrix operator*(double num);

  S21Matrix operator*(const S21Matrix &other);

  bool operator==(const S21Matrix &other);

  double operator()(int row, int col);  // index operator overload
  //  int& operator()(int row, int col) const;
  S21Matrix &operator+=(const S21Matrix &other);

  S21Matrix &operator-=(const S21Matrix &other);

  S21Matrix &operator*=(const S21Matrix &other);

  S21Matrix &operator*=(double num);

  // some public methods
  bool EqMatrix(const S21Matrix &other);

  void SumMatrix(const S21Matrix &other);

  void SubMatrix(const S21Matrix &other);

  void MulNumber(const double num);

  void MulMatrix(const S21Matrix &other);

  S21Matrix CalcComplements();

  S21Matrix Transpose();

  double Determinant();

  S21Matrix InverseMatrix();

  S21Matrix Minor(int row_skip, int col_skip);

  void delete_matrix(S21Matrix *A);

  void create_matrix(S21Matrix *A, int rows, int cols);

  void print();

  void fill_int();

  void copy_data(S21Matrix *dest, const S21Matrix &src);

  void set_zero();

  void FillRandMatrix();
};

#endif  // CPP1_S21_MATRIXPLUS_SRC_S21_MATRIX_H_
