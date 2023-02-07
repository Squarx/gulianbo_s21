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
S21Matrix::S21Matrix(S21Matrix &&other) noexcept {
  if (_p && (_rows == other._rows && _cols == other._cols)) {
    for (int i = 0; i < _rows; i++) {
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
    for (int i = 0; i < other._rows; i++) {
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
      _p[i][j] = x;
}

bool S21Matrix::EqMatrix(const S21Matrix &other) {
  bool res = SUCCESS;
  if (_cols != other._cols || _rows != other._rows) res = FAILURE;
  for (int i = 0; res && i < _rows; i++)
    for (int j = 0; res && j < _cols; j++)
      if ((fabs(_p[i][j] - other._p[i][j])) >= 1e-7)
        res = FAILURE;
  return res;
}
void S21Matrix::SumMatrix(const S21Matrix &other) {
  try {
    if (_rows != other._rows || _cols != other._cols) {
      throw std::out_of_range(
          "Incorrect input, matrices should have the same size");
    }
    for (auto i = 0; i < _rows; i++)
      for (auto j = 0; j < _cols; j++)
        _p[i][j] += other._p[i][j];
  }
  catch (std::out_of_range &e) {
    std::cout << e.what() << std::endl;
  }
}
void S21Matrix::SubMatrix(const S21Matrix &other) {
  try {
    if (_rows != other._rows || _cols != other._cols) {
      throw std::out_of_range(
          "Incorrect input, matrices should have the same size");
    }
    for (auto i = 0; i < _rows; i++)
      for (auto j = 0; j < _cols; j++)
        _p[i][j] -= other._p[i][j];
  }
  catch (std::out_of_range &e) {
    std::cout << e.what() << std::endl;
  }
}

S21Matrix::S21Matrix(const S21Matrix &other) {
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

void S21Matrix::MulMatrix(const S21Matrix &other) {
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
  catch (std::out_of_range &e) {
    std::cout << e.what() << std::endl;
  }
}
S21Matrix S21Matrix::Transpose() {
  S21Matrix Transposed = S21Matrix(_cols, _rows);
  for (int i = 0; i < _rows; i++)
    for (int j = 0; j < _cols; ++j) {
      Transposed._p[j][i] = _p[i][j];
    }
  return Transposed;
}
void S21Matrix::delete_matrix(S21Matrix *A) {
  for (int i = 0; i < A->_rows; i++)
    delete[] A->_p[i];
  delete[] A->_p;
  A->_p = nullptr;
  A->_rows = 0;
  A->_cols = 0;
}
void S21Matrix::create_matrix(S21Matrix *A, int rows, int cols) {
  A->_p = new double *[rows];
  for (int i = 0; i < rows; ++i) {
    A->_p[i] = new double[cols];
  }
  A->_rows = rows;
  A->_cols = cols;
}
// TODO
S21Matrix S21Matrix::CalcComplements() {
  S21Matrix COMP = S21Matrix(_rows, _cols);;
  try {
    if (_rows != _cols)
      throw std::out_of_range("Invalid size of matrix(NOT SQUARE)");
    if (_rows == 1 || _cols == 1)
      throw std::out_of_range("Invalid size of matrix(CANT FIND MINOR)");
    for (int i = 0; i < COMP._rows; i++) {
      int sign = i % 2 == 0 ? 1 : -1;
      for (int j = 0; j < COMP._cols; j++) {
        S21Matrix MINOR = Minor(i, j);
        double res = 0;
        res = MINOR.Determinant();
        COMP._p[i][j] = sign * res;
        sign = -sign;
      }
    }
  }
  catch (std::out_of_range &e) {
    std::cout << e.what() << std::endl;
  }
  return COMP;
}
S21Matrix S21Matrix::Minor(int row_skip, int col_skip) {
  S21Matrix minor = S21Matrix(_rows - 1, _cols - 1);
  for (int i = 0, minor_row = 0; i < _rows; i++) {
    if (i != row_skip) {
      for (int j = 0, minor_col = 0; j < _cols; j++)
        if (j != col_skip) minor._p[minor_row][minor_col++] = _p[i][j];
      minor_row++;
    }
  }
  return minor;
}

double S21Matrix::Determinant() {
  double res = 0;
  try {
    if (_rows != _cols)
      throw (std::out_of_range("NOT SQUARE"));
    if (_rows == 1) res = _p[0][0];
    if (_rows == 2)
      res = _p[0][0] * _p[1][1] - _p[1][0] * _p[0][1];
    if (_rows > 2) {
      int sign = 1;
      for (int i = 0; i < _cols; i++) {
        S21Matrix minor = Minor(0, i);
        double minor_res = 0;
        minor_res = minor.Determinant();
        res += sign * _p[0][i] * minor_res;
        sign = -sign;
      }
    }
  }
  catch (std::out_of_range &e) {
    std::cout << e.what() << std::endl;
  }

  return res;
}
S21Matrix S21Matrix::InverseMatrix() {
  S21Matrix Inverse = S21Matrix(_rows, _cols);
  try {
    double det = this->Determinant();
    if (det == 0)
      throw (std::out_of_range("Determinant = 0"));
    if (_rows != _cols)
      throw (std::out_of_range("NOT SQUARE"));
    if (_rows == 1) {
      Inverse._p[0][0] = _p[0][0] * 1 / _p[0][0] / _p[0][0];
    } else {
      S21Matrix Tmp = this->CalcComplements();
      S21Matrix Tmp_T = Tmp.Transpose();
      Tmp_T.MulNumber(1 / det);
      for (int i = 0; i < Tmp_T._rows; i++)
        for (int j = 0; j < Tmp_T._cols; ++j) {
          Inverse._p[i][j] = Tmp_T._p[i][j];
        }
    }
  }
  catch (std::out_of_range &e) {
    std::cout << e.what() << std::endl;
  }
  return Inverse;
}
S21Matrix &S21Matrix::operator=(const S21Matrix &other) {
  if (&other != this) {
    if (_p) delete_matrix(this);
    create_matrix(this, other._rows, other._cols);
    copy_data(this, other);
  }
  return *this;
}

void S21Matrix::copy_data(S21Matrix *dest, const S21Matrix &src) {
  for (int i = 0; i < src._rows; ++i)
    for (int j = 0; j < src._cols; ++j)
      dest->_p[i][j] = src._p[i][j];
}

S21Matrix S21Matrix::operator+(const S21Matrix &other) {
  S21Matrix res(*this);
  res.SumMatrix(other);
  return res;
}

S21Matrix S21Matrix::operator-(const S21Matrix &other) {
  S21Matrix res(*this);
  res.SubMatrix(other);
  return res;
}
S21Matrix S21Matrix::operator*(double num) {
  S21Matrix res(*this);
  res.MulNumber(num);
  return res;
}
S21Matrix S21Matrix::operator*(const S21Matrix &other) {
  S21Matrix res(*this);
  res.MulMatrix(other);
  return res;
}
bool S21Matrix::operator == (const S21Matrix &other) {
  return this->EqMatrix(other);
}

S21Matrix& S21Matrix::operator += (const S21Matrix &other) {
   this->SumMatrix(other);
  return *this;
}
S21Matrix& S21Matrix::operator -= (const S21Matrix &other) {
  this->SubMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator *= (const S21Matrix &other) {
  this->MulMatrix(other);
  return *this;
}
S21Matrix& S21Matrix::operator *= (double num) {
  this->MulNumber(num);
  return *this;
}

double S21Matrix::operator()(int row, int col) {
  try {
    if (row >= _rows || col >= _cols || !_p) {
      throw std::out_of_range("Incorrect input, index is out of range");
    }
  }
  catch (std::out_of_range & e) {
    std::cout << e.what() << std::endl;
    return 0.0;
  }
  return _p[row][col];
}
void S21Matrix::Set_row(int row) {
  try {
    if (row <= 0)
      throw std::out_of_range("Rows must be > 0");
    if (row >= _rows) {
      S21Matrix tmp(row, _cols);
      tmp.set_zero();
      tmp.copy_data(&tmp, *this);
      delete_matrix(this);
      this->create_matrix(this, tmp._rows, tmp._cols);
      copy_data(this, tmp);
    } else {
      for (int i = _rows - 1; i >= row; i--)
        delete[] _p[i];
      _rows = row;
    }
  }
  catch  (std::out_of_range & e){
    std::cout << e.what() << std::endl;
  }
}
void S21Matrix::set_zero() {
  for (int i = 0; i < _rows; ++i)
    for (int j = 0; j < _cols; ++j)
      _p[i][j] = 0;
}
void S21Matrix::Set_col(int col) {
  try {
    if (col <= 0)
      throw std::out_of_range("Rows must be > 0");
    if (col >= _cols) {
      S21Matrix tmp(_rows, col);
      tmp.set_zero();
      tmp.copy_data(&tmp, *this);
      delete_matrix(this);
      this->create_matrix(this, tmp._rows, tmp._cols);
      copy_data(this, tmp);
    } else {
//      for (int i = 0; i < _rows; i++) {
//        printf("%f\n", (_p[i][col - 1]));
////        delete[] &(_p[i][col - 1]);
//      }
      _cols = col;
    }
  }
  catch  (std::out_of_range & e){
    std::cout << e.what() << std::endl;
  }
}
