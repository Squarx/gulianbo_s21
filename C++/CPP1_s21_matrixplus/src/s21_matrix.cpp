//
// Created by DimasX on 06.02.2023.
//

#include "s21_matrix.h"

S21Matrix::S21Matrix() : S21Matrix(3, 3) {
}
S21Matrix::~S21Matrix() {
  if (_p) {
    for (int i = 0; i < _rows; i++) {
      delete[] _p[i];
    }
    delete[] _p;
  }
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
      _p[i][j] = x;
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

S21Matrix::S21Matrix(S21Matrix&& other) {
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