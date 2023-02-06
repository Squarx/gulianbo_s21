//
// Created by DimasX on 06.02.2023.
//

#include "s21_matrix.h"

S21Matrix::S21Matrix() : S21Matrix(3, 3) {
}
S21Matrix::S21Matrix(int rows, int cols) {
  _rows = rows;
  _cols = cols;
  // that is how memory allocation works in C++
  _p = new double *[_rows];
  for (int i = 0; i < _rows; ++i) {
    _p[i] = new double[_cols];
  }
}
S21Matrix::~S21Matrix() {
  if (_p) {
    for (int i = 0; i < _rows; i++) {
      delete[] _p[i];
    }
    delete[] _p;
  }
}
S21Matrix::S21Matrix(S21Matrix&& other) noexcept{
  if (_p  && (_rows == other._rows &&  _cols == other._cols)) {
    for(int i = 0; i < _rows; i++) {
      memcpy(_p[i], other._p[i], sizeof(double) * _cols);
    }
  } else {
    if (_p && (_rows != 0 || _cols != 0)) {
      for (int i = 0; i < _rows; i++)
        delete[] _p[i];
      delete[] _p;
    }
    _p = new double *[other._rows];
    for (int i = 0; i < other._rows; ++i) {
      _p[i] = new double[other._cols];
    }
    for(int i = 0; i < other._rows; i++) {
      memcpy(_p[i], other._p[i], sizeof(double) * other._cols);
    }
  }
  _rows = other._rows;
  _cols = other._cols;
  for (int i = 0; i < other._rows; i++)
    delete[] other._p[i];
  delete[] other._p;
  other._p = nullptr;
  other._rows = 0;
  other._cols = 0;
}

void S21Matrix::S21_Print() {
  try {
    if (_rows == 0 || _cols == 0) {
      throw std::range_error("It seems to be a NULL matrix");
    }
    for (int i = 0; i < _rows; i++) {
      for (int j = 0; j < _cols; ++j) {
        std::cout << _p[i][j] << " ";
      }
      std::cout << std::endl;
    }
  }
  catch (std::range_error &e) {
    std::cout << e.what() << std::endl;
  }
}
void S21Matrix::S21_Fill() {
  for (int i = 0, x = 0; i < _rows; i++)
    for (int j = 0; j < _cols; ++j, ++x)
      _p[i][j] = x * x;
}

bool S21Matrix::EqMatrix(const S21Matrix& other) {
  bool res = SUCCESS;
  if (_cols != other._cols || _rows != other._rows) res = FAILURE;
  for (int i = 0; res && i < _rows; i++)
    for (int j = 0; res && j < _cols; j++)
      if ((fabs(_p[i][j] - other._p[i][j])) >= 1e-7)
        res = FAILURE;
  return res;
}
void S21Matrix::SumMatrix(const S21Matrix& other) {
  try {
    if (_rows != other._rows || _cols != other._cols) {
      throw std::out_of_range(
          "Incorrect input, matrices should have the same size");
    }
    for (auto i = 0; i < _rows; i++)
      for (auto j = 0; j < _cols; j++)
        _p[i][j] += other._p[i][j];
  }
  catch (std::out_of_range& e) {
    std::cout << e.what() << std::endl;
  }
}
void S21Matrix::SubMatrix(const S21Matrix& other) {
  try {
    if (_rows != other._rows || _cols != other._cols) {
      throw std::out_of_range(
          "Incorrect input, matrices should have the same size");
    }
    for (auto i = 0; i < _rows; i++)
      for (auto j = 0; j < _cols; j++)
        _p[i][j] -= other._p[i][j];
  }
  catch (std::out_of_range& e) {
    std::cout << e.what() << std::endl;
  }
}

S21Matrix::S21Matrix(const S21Matrix& other) {
  _rows = other._rows;
  _cols = other._cols;
  _p = new double *[_rows];
  for (int i = 0; i < _rows; ++i) {
    _p[i] = new double[_cols];
  }
  for (auto i = 0; i < _rows; i++)
    for (auto j = 0; j < _cols; j++)
      _p[i][j] = other._p[i][j];
}
void S21Matrix::MulNumber(const double num) {
  for (auto i = 0; i < _rows; i++)
    for (auto j = 0; j < _cols; j++)
      _p[i][j] *= num;
}


void S21Matrix::MulMatrix(const S21Matrix& other) {
  try {
    if (_cols != other._rows) {
      throw std::out_of_range(
          "Incorrect input, matrices should have size A(m*n) && B(n*d)");
    }
    S21Matrix C = S21Matrix(_rows, other._cols);
    for (int i = 0; i < _rows; i++) {
      for (int j = 0; j < other._cols; ++j) {
        double res = 0;
        for (int r = 0; r < other._rows; r++) {
          res += _p[i][r] * other._p[r][j];
        }
        C._p[i][j] = res;
      }
    }
    this->delete_matrix(this);
    this->create_matrix(this, C._rows, C._cols);
    for (int i = 0; i < _rows; i++)
      for (int j = 0; j < _cols; ++j) {
        _p[i][j] = C._p[i][j];
      }
  }
  catch(std::out_of_range& e)  {
      std::cout << e.what() << std::endl;
  }
}
void S21Matrix::delete_matrix(S21Matrix* A) {
  for (int i = 0; i < A->_rows; i++)
    delete[] A->_p[i];
  delete[] A->_p;
  A->_p = nullptr;
  A->_rows = 0;
  A->_cols = 0;
}
void S21Matrix::create_matrix(S21Matrix* A, int rows, int cols) {
  A->_p = new double *[rows];
  for (int i = 0; i < rows; ++i) {
    A->_p[i] = new double[cols];
  }
  A->_rows = rows;
  A->_cols = cols;
}
// число столбцов первой матрицы не равно числу строк второй матрицы
/*
 * int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = OK;
  error = s21_matrix_valid_PRO(2, A, B);
  if (!error && (A->columns != B->rows)) error = CALC_ERR;
  if (!error) error = s21_create_matrix(A->rows, B->columns, result);
  for (int i = 0; !error && i < result->rows; i++) {
    for (int j = 0; !error && j < result->columns; ++j) {
      result->matrix[i][j] = sum_mult(i, j, A, B);
      if (result->matrix[i][j] != result->matrix[i][j]) error = CALC_ERR;
    }
  }
  return error;
}

double sum_mult(int i, int j, matrix_t *A, matrix_t *B) {
  double res = 0;
  for (int r = 0; r < B->rows; r++) {
    res += A->matrix[i][r] * B->matrix[r][j];
  }
  return res;
}

 */
