//
// Created by DimasX on 06.02.2023.
//

#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() { *this = S21Matrix(3, 3); }
S21Matrix::S21Matrix(int rows, int cols) {
  if (rows < 1 || cols < 1) {
    throw std::out_of_range(
        "Incorrect input, matrices should have the positive size");
  }
  _rows = rows;
  _cols = cols;
  // that is how memory allocation works in C++
  _matrix = new double *[_rows];
  for (int i = 0; i < _rows; ++i) {
    _matrix[i] = new double[_cols];
  }
}
S21Matrix::~S21Matrix() {
  if (_matrix) {
    for (int i = 0; i < _rows; i++) {
      delete[] _matrix[i];
    }
    delete[] _matrix;
  }
}
S21Matrix::S21Matrix(
    const S21Matrix &other) {
  _rows = other._rows;
  _cols = other._cols;
  _matrix = new double *[_rows];
  for (int i = 0; i < _rows; ++i) {
    _matrix[i] = new double[_cols];
  }
    copy_data(this, other);
}
S21Matrix::S21Matrix(S21Matrix &&other) noexcept {
  if (this->_matrix != nullptr) delete_matrix(this);
  create_matrix(this, other._rows, other._cols);
  for (auto i = 0; i < other._rows; i++) {
    std::memmove(this->_matrix[i], other._matrix[i],
                 other._cols * sizeof(double));
  }
  delete_matrix(&other);
}

bool S21Matrix::EqMatrix(const S21Matrix &other) {
  bool res = true;
  if (_cols != other._cols || _rows != other._rows) res = false;
  for (int i = 0; res && i < _rows; i++)
    for (int j = 0; res && j < _cols; j++)
      if ((fabs(_matrix[i][j] - other._matrix[i][j])) >= 1e-7)
        res = false;
  return res;
}
void S21Matrix::SumMatrix(const S21Matrix &other) {

  if (_rows != other._rows || _cols != other._cols) {
    throw std::out_of_range(
        "Incorrect input, matrices should have the same size");
  }
  for (auto i = 0; i < _rows; i++)
    for (auto j = 0; j < _cols; j++)
      _matrix[i][j] += other._matrix[i][j];
}

void S21Matrix::SubMatrix(const S21Matrix &other) {
  if (_rows != other._rows || _cols != other._cols) {
    throw std::out_of_range(
        "Incorrect input, matrices should have the same size");
  }
  for (auto i = 0; i < _rows; i++)
    for (auto j = 0; j < _cols; j++)
      _matrix[i][j] -= other._matrix[i][j];
}

void S21Matrix::MulNumber(const double num) {
  for (auto i = 0; i < _rows; i++)
    for (auto j = 0; j < _cols; j++)
      _matrix[i][j] *= num;
}

void S21Matrix::MulMatrix(const S21Matrix &other) {

  if (_cols != other._rows) {
    throw std::out_of_range(
        "Incorrect input, matrices should have size A(m*n) && B(n*d)");
  }
  S21Matrix Result = S21Matrix(_rows, other._cols);
  for (int i = 0; i < _rows; i++) {
    for (int j = 0; j < other._cols; ++j) {
      double res = 0;
      for (int r = 0; r < other._rows; r++) {
        res += _matrix[i][r] * other._matrix[r][j];
      }
      Result._matrix[i][j] = res;
    }
  }
  this->delete_matrix(this);
  this->create_matrix(this, Result._rows, Result._cols);
  copy_data(this, Result);
}
S21Matrix S21Matrix::Transpose() {
  S21Matrix Transposed = S21Matrix(_cols, _rows);
  for (int i = 0; i < _rows; i++)
    for (int j = 0; j < _cols; ++j) {
      Transposed._matrix[j][i] = _matrix[i][j];
    }
  return Transposed;
}
void S21Matrix::delete_matrix(S21Matrix *A) {
  for (int i = 0; i < A->_rows; i++)
    delete[] A->_matrix[i];
  delete[] A->_matrix;
  A->_matrix = nullptr;
  A->_rows = 0;
  A->_cols = 0;
}
void S21Matrix::create_matrix(S21Matrix *A, int rows, int cols) {
  A->_matrix = new double *[rows];
  for (int i = 0; i < rows; ++i) {
    A->_matrix[i] = new double[cols];
  }
  A->_rows = rows;
  A->_cols = cols;
}

S21Matrix S21Matrix::CalcComplements() {
  S21Matrix COMP = S21Matrix(_rows, _cols);
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
      COMP._matrix[i][j] = sign * res;
      sign = -sign;
    }
  }
  return COMP;
}
S21Matrix S21Matrix::Minor(int row_skip, int col_skip) {
  S21Matrix minor = S21Matrix(_rows - 1, _cols - 1);
  for (int i = 0, minor_row = 0; i < _rows; i++) {
    if (i != row_skip) {
      for (int j = 0, minor_col = 0; j < _cols; j++)
        if (j != col_skip) minor._matrix[minor_row][minor_col++] = _matrix[i][j];
      minor_row++;
    }
  }
  return minor;
}

double S21Matrix::Determinant() {
  double res = 0;
  if (_rows != _cols)
    throw (std::out_of_range("NOT SQUARE"));
  if (_rows == 1) res = _matrix[0][0];
  if (_rows == 2)
    res = _matrix[0][0] * _matrix[1][1] - _matrix[1][0] * _matrix[0][1];
  if (_rows > 2) {
    int sign = 1;
    for (int i = 0; i < _cols; i++) {
      S21Matrix minor = Minor(0, i);
      double minor_res = 0;
      minor_res = minor.Determinant();
      res += sign * _matrix[0][i] * minor_res;
      sign = -sign;
    }
  }
  return res;
}
S21Matrix S21Matrix::InverseMatrix() {
  if (_rows != _cols)
    throw (std::out_of_range("NOT SQUARE"));
  S21Matrix Inverse = S21Matrix(_rows, _cols);
  double det = this->Determinant();
  if (det == 0)
    throw (std::out_of_range("Determinant = 0"));
  if (_rows == 1) {
    Inverse._matrix[0][0] = _matrix[0][0] * 1 / _matrix[0][0] / _matrix[0][0];
  } else {
    S21Matrix Tmp = this->CalcComplements();
    S21Matrix Tmp_T = Tmp.Transpose();
    Tmp_T.MulNumber(1 / det);
    for (int i = 0; i < Tmp_T._rows; i++)
      for (int j = 0; j < Tmp_T._cols; ++j) {
        Inverse._matrix[i][j] = Tmp_T._matrix[i][j];
      }
  }

//  catch (std::out_of_range &e) {
//    std::cout << e.what() << std::endl;
//  }
  return Inverse;
}
S21Matrix &S21Matrix::operator=(const S21Matrix &other) {
  if (&other != this) {
    if (_matrix) delete_matrix(this);
    create_matrix(this, other._rows, other._cols);
    copy_data(this, other);
  }
  return *this;
}


/**
 *
 * @param dest
 * @param src
 */
void S21Matrix::copy_data(S21Matrix *dest, const S21Matrix &src) {
  for (int i = 0; i < src._rows; ++i)
    for (int j = 0; j < src._cols; ++j)
      dest->_matrix[i][j] = src._matrix[i][j];
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
bool S21Matrix::operator==(const S21Matrix &other) {
  return this->EqMatrix(other);
}

S21Matrix &S21Matrix::operator+=(const S21Matrix &other) {
  this->SumMatrix(other);
  return *this;
}
S21Matrix &S21Matrix::operator-=(const S21Matrix &other) {
  this->SubMatrix(other);
  return *this;
}

S21Matrix &S21Matrix::operator*=(const S21Matrix &other) {
  this->MulMatrix(other);
  return *this;
}
S21Matrix &S21Matrix::operator*=(double num) {
  this->MulNumber(num);
  return *this;
}

double S21Matrix::operator()(int row, int col) {
  if (row >= _rows || col >= _cols || !_matrix) {
    throw std::out_of_range("Incorrect input, index is out of range");
  }
  return _matrix[row][col];
}
void S21Matrix::SetRows(int row) {
  if (row <= 0)
    throw std::out_of_range("Rows must be > 0");
  S21Matrix temp = std::move(*this);
  create_matrix(this, row, temp._cols);
  this->set_zero();
  for (auto i = 0; i < this->_rows && i < temp._rows; ++i) {
    for (auto j = 0; j < this->_cols; ++j) {
      this->_matrix[i][j] = temp._matrix[i][j];
    }
  }
}
void S21Matrix::set_zero() {
  for (int i = 0; i < _rows; ++i)
    for (int j = 0; j < _cols; ++j)
      _matrix[i][j] = 0;
}
void S21Matrix::SetCols(int col) {
  if (col <= 0)
    throw std::out_of_range("Rows must be > 0");
  S21Matrix temp = std::move(*this);
  create_matrix(this, temp._rows, col);
  this->set_zero();
  for (auto i = 0; i < this->_rows; ++i) {
    for (auto j = 0; j < this->_cols && j < temp._cols; ++j) {
      this->_matrix[i][j] = temp._matrix[i][j];
    }
  }
}

void S21Matrix::FillRandMatrix() {
  double min = -100.0, max = 100.0;
  srand(time(nullptr));
  for (int i = 0; i < this->_rows; i++) {
    for (int j = 0; j < this->_cols; j++) {
      this->_matrix[i][j] = (double) (rand()) / RAND_MAX * (max - min) + min;
    }
  }
}

void S21Matrix::CopyData(const S21Matrix &other) {
  for (auto i = 0; i < other._rows; i++) {
    std::memcpy(this->_matrix[i], other._matrix[i],
                other._cols * sizeof(double));
  }
}
void S21Matrix::print() {
  try {
    if (_rows == 0 || _cols == 0) {
      throw std::range_error("It seems to be a NULL matrix");
    }
    for (int i = 0; i < _rows; i++) {
      for (int j = 0; j < _cols; ++j) {
        std::cout << _matrix[i][j] << " ";
      }
      std::cout << std::endl;
    }
  }
  catch (std::range_error &e) {
    std::cout << e.what() << std::endl;
  }
}
void S21Matrix::fill_int() {
  for (int i = 0, x = 0; i < _rows; i++)
    for (int j = 0; j < _cols; ++j, ++x)
      _matrix[i][j] = x;
}