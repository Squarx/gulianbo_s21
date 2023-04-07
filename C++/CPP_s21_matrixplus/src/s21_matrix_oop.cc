//
// Created by DimasX on 06.02.2023.
//

#include "s21_matrix_oop.h"

S21_Project::S21Matrix::S21Matrix() : S21Matrix(3, 3) {}

S21_Project::S21Matrix::S21Matrix(int rows, int cols) {
  if (rows < 1 || cols < 1) {
    throw std::out_of_range(
        "Incorrect input, matrices should have the positive size");
  } else {
    rows_ = rows;
    cols_ = cols;
    matrix_ = new double *[rows_]();
    for (int i = 0; i < rows_; ++i) {
      matrix_[i] = new double[cols_]();
    }
  }
}

S21_Project::S21Matrix::S21Matrix(const double *data, int rows, int cols)
    : S21Matrix(rows, cols) {
  if (!data || !matrix_) {
    throw std::out_of_range("Incorrect input, data is empty");
  }
  for (auto i = 0; i < rows; ++i) {
    for (auto j = 0; j < cols; ++j) {
      matrix_[i][j] = data[i * cols + j];
    }
  }
}

S21_Project::S21Matrix::~S21Matrix() {
  if (matrix_) {
    for (int i = 0; i < rows_; i++) {
      delete[] matrix_[i];
    }
    delete[] matrix_;
  }
}

S21_Project::S21Matrix::S21Matrix(const S21Matrix &other) {
  if (matrix_) DeleteMatrix(this);
  CreateMatrix(this, other.rows_, other.cols_);
  CopyData(this, other);
}

S21_Project::S21Matrix::S21Matrix(S21Matrix &&other) noexcept {
  if (matrix_ != nullptr) DeleteMatrix(this);
  matrix_ = other.matrix_;
  rows_ = other.rows_;
  cols_ = other.cols_;
  other.matrix_ = nullptr;
  other.cols_ = 0;
  other.rows_ = 0;
}

bool S21_Project::S21Matrix::EqMatrix(const S21Matrix &other) {
  bool res = true;
  if (cols_ != other.cols_ || rows_ != other.rows_) res = false;
  for (int i = 0; res && i < rows_; i++)
    for (int j = 0; res && j < cols_; j++)
      if ((fabs(matrix_[i][j] - other(i, j))) >= 1e-7) res = false;
  return res;
}

void S21_Project::S21Matrix::SumMatrix(const S21Matrix &other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::out_of_range(
        "Incorrect input, matrices should have the same size");
  }
  for (auto i = 0; i < rows_; i++)
    for (auto j = 0; j < cols_; j++) matrix_[i][j] += other(i, j);
}

void S21_Project::S21Matrix::SubMatrix(const S21Matrix &other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::out_of_range(
        "Incorrect input, matrices should have the same size");
  }
  for (auto i = 0; i < rows_; i++)
    for (auto j = 0; j < cols_; j++) matrix_[i][j] -= other(i, j);
}

void S21_Project::S21Matrix::MulNumber(double num) {
  for (auto i = 0; i < rows_; i++)
    for (auto j = 0; j < cols_; j++) matrix_[i][j] *= num;
}

void S21_Project::S21Matrix::MulMatrix(const S21Matrix &other) {
  if (cols_ != other.rows_) {
    throw std::out_of_range(
        "Incorrect input, matrices should have size A(m*n) && B(n*d)");
  }
  S21Matrix Result = S21Matrix(rows_, other.cols_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < other.cols_; ++j) {
      double res = 0;
      for (int r = 0; r < other.rows_; r++) {
        res += matrix_[i][r] * other(r, j);
      }
      Result.matrix_[i][j] = res;
    }
  }
  *this = Result;
  DeleteMatrix(&Result);
}

S21_Project::S21Matrix S21_Project::S21Matrix::Transpose() {
  S21Matrix Transposed = S21Matrix(cols_, rows_);
  for (int i = 0; i < rows_; i++)
    for (int j = 0; j < cols_; ++j) {
      Transposed.matrix_[j][i] = matrix_[i][j];
    }
  return Transposed;
}

void S21_Project::S21Matrix::DeleteMatrix(S21Matrix *A) {
  for (int i = 0; i < A->rows_; i++) delete[] A->matrix_[i];
  delete[] A->matrix_;
  A->matrix_ = nullptr;
  A->rows_ = 0;
  A->cols_ = 0;
}

void S21_Project::S21Matrix::CreateMatrix(S21Matrix *A, int rows, int cols) {
  A->matrix_ = new double *[rows]();
  for (int i = 0; i < rows; ++i) {
    A->matrix_[i] = new double[cols]();
  }
  A->rows_ = rows;
  A->cols_ = cols;
}

S21_Project::S21Matrix S21_Project::S21Matrix::CalcComplements() {
  if (rows_ != cols_) {
    throw std::out_of_range("Invalid size of matrix(NOT SQUARE)");
  }
  if (!matrix_) {
    throw std::out_of_range("Empty matrix");
  }
  S21Matrix COMP = S21Matrix(rows_, cols_);
  if (rows_ == 1) {
    COMP.matrix_[0][0] = matrix_[0][0];
  } else {
    for (int i = 0; i < COMP.rows_; i++) {
      int sign = i % 2 == 0 ? 1 : -1;
      for (int j = 0; j < COMP.cols_; j++) {
        S21Matrix minor = Minor(i, j);
        double res = 0;
        res = minor.Determinant();
        COMP.matrix_[i][j] = sign * res;
        sign = -sign;
      }
    }
  }
  return COMP;
}

S21_Project::S21Matrix S21_Project::S21Matrix::Minor(int row_skip,
                                                     int col_skip) {
  S21Matrix minor = S21Matrix(rows_ - 1, cols_ - 1);
  for (int i = 0, minor_row = 0; i < rows_; i++) {
    if (i != row_skip) {
      for (int j = 0, minor_col = 0; j < cols_; j++)
        if (j != col_skip)
          minor.matrix_[minor_row][minor_col++] = matrix_[i][j];
      minor_row++;
    }
  }
  return minor;
}

double S21_Project::S21Matrix::Determinant() {
  double res = 0;
  if (rows_ != cols_) throw(std::out_of_range("NOT SQUARE"));
  if (rows_ == 1) res = matrix_[0][0];
  if (rows_ == 2)
    res = matrix_[0][0] * matrix_[1][1] - matrix_[1][0] * matrix_[0][1];
  if (rows_ > 2) {
    int sign = 1;
    for (int i = 0; i < cols_; i++) {
      S21Matrix minor = Minor(0, i);
      double minor_res = 0;
      minor_res = minor.Determinant();
      res += sign * matrix_[0][i] * minor_res;
      sign = -sign;
    }
  }
  return res;
}

S21_Project::S21Matrix S21_Project::S21Matrix::InverseMatrix() {
  if (rows_ != cols_) throw(std::out_of_range("NOT SQUARE"));
  S21Matrix Inverse = S21Matrix(rows_, cols_);
  double det = Determinant();
  if (fabs(det) <= 1e-7) throw(std::out_of_range("Determinant = 0"));
  if (rows_ == 1) {
    Inverse.matrix_[0][0] = matrix_[0][0] * 1 / matrix_[0][0] / matrix_[0][0];
  } else {
    S21Matrix Tmp = CalcComplements();
    S21Matrix Tmp_T = Tmp.Transpose();
    Tmp_T.MulNumber(1 / det);
    for (int i = 0; i < Tmp_T.rows_; i++)
      for (int j = 0; j < Tmp_T.cols_; ++j) {
        Inverse.matrix_[i][j] = Tmp_T.matrix_[i][j];
      }
  }
  return Inverse;
}
S21_Project::S21Matrix &S21_Project::S21Matrix::operator=(
    S21Matrix &&other) noexcept {
  if (&other != this) {
    if (matrix_ != nullptr) DeleteMatrix(this);
    matrix_ = other.matrix_;
    rows_ = other.rows_;
    cols_ = other.cols_;
    other.matrix_ = nullptr;
    other.cols_ = 0;
    other.rows_ = 0;
  }
  return *this;
}
S21_Project::S21Matrix &S21_Project::S21Matrix::operator=(
    const S21Matrix &other) {
  if (&other != this) {
    if (matrix_) DeleteMatrix(this);
    CreateMatrix(this, other.rows_, other.cols_);
    CopyData(this, other);
  }
  return *this;
}

void S21_Project::S21Matrix::CopyData(S21Matrix *dest, const S21Matrix &src) {
  for (int i = 0; i < src.rows_; ++i)
    for (int j = 0; j < src.cols_; ++j) dest->matrix_[i][j] = src.matrix_[i][j];
}

S21_Project::S21Matrix S21_Project::S21Matrix::operator+(
    const S21Matrix &other) {
  S21Matrix res(*this);
  res.SumMatrix(other);
  return res;
}

S21_Project::S21Matrix S21_Project::S21Matrix::operator-(
    const S21Matrix &other) {
  S21Matrix res(*this);
  res.SubMatrix(other);
  return res;
}

S21_Project::S21Matrix S21_Project::S21Matrix::operator*(double num) {
  S21Matrix res(*this);
  res.MulNumber(num);
  return res;
}

S21_Project::S21Matrix S21_Project::S21Matrix::operator*(
    const S21Matrix &other) {
  S21Matrix res(*this);
  res.MulMatrix(other);
  return res;
}

bool S21_Project::S21Matrix::operator==(const S21Matrix &other) {
  return EqMatrix(other);
}

S21_Project::S21Matrix &S21_Project::S21Matrix::operator+=(
    const S21Matrix &other) {
  SumMatrix(other);
  return *this;
}

S21_Project::S21Matrix &S21_Project::S21Matrix::operator-=(
    const S21Matrix &other) {
  SubMatrix(other);
  return *this;
}

S21_Project::S21Matrix &S21_Project::S21Matrix::operator*=(
    const S21Matrix &other) {
  MulMatrix(other);
  return *this;
}

S21_Project::S21Matrix &S21_Project::S21Matrix::operator*=(double num) {
  MulNumber(num);
  return *this;
}

double &S21_Project::S21Matrix::operator()(int row, int col) {
  if (row >= rows_ || col >= cols_ || !matrix_ || row < 0 || col < 0) {
    throw std::out_of_range("Incorrect input, index is out of range");
  }
  return matrix_[row][col];
}

double S21_Project::S21Matrix::operator()(int row, int col) const {
  if (row >= rows_ || col >= cols_ || !matrix_ || row < 0 || col < 0) {
    throw std::out_of_range("Incorrect input, index is out of range");
  }
  return matrix_[row][col];
}

void S21_Project::S21Matrix::SetRows(int row) {
  if (row <= 0) throw std::out_of_range("Rows must be > 0");
  S21Matrix temp = std::move(*this);
  CreateMatrix(this, row, temp.cols_);
  for (auto i = 0; i < rows_ && i < temp.rows_; ++i) {
    for (auto j = 0; j < cols_; ++j) {
      matrix_[i][j] = temp.matrix_[i][j];
    }
  }
}

void S21_Project::S21Matrix::ClearMatrix() {
  for (int i = 0; i < rows_; ++i)
    for (int j = 0; j < cols_; ++j) matrix_[i][j] = 0;
}

void S21_Project::S21Matrix::SetCols(int col) {
  if (col <= 0) throw std::out_of_range("Rows must be > 0");
  S21Matrix temp = std::move(*this);
  CreateMatrix(this, temp.rows_, col);
  for (auto i = 0; i < rows_; ++i) {
    for (auto j = 0; j < cols_ && j < temp.cols_; ++j) {
      matrix_[i][j] = temp.matrix_[i][j];
    }
  }
}

void S21_Project::S21Matrix::FillRandMatrix() {
  double min = -100.0, max = 100.0;
  srand(time(nullptr));
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++)
      matrix_[i][j] =
          static_cast<double>(rand()) / RAND_MAX * (max - min) + min;
  }
}

void S21_Project::S21Matrix::Print() {
  if (rows_ == 0 || cols_ == 0) {
    throw std::range_error("It seems to be a NULL matrix");
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; ++j) {
      std::cout << matrix_[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

void S21_Project::S21Matrix::FillInt() {
  for (int i = 0, x = 0; i < rows_; i++)
    for (int j = 0; j < cols_; ++j, ++x) matrix_[i][j] = x;
}

void S21_Project::S21Matrix::SetValue(int row, int col, double val) {
  if (row >= rows_ || col >= cols_ || !matrix_ || row < 0 || col < 0) {
    throw std::out_of_range("Incorrect input, index is out of range");
  }
  matrix_[row][col] = val;
}

int S21_Project::S21Matrix::GetRows() const { return rows_; }

int S21_Project::S21Matrix::GetCols() const { return cols_; }