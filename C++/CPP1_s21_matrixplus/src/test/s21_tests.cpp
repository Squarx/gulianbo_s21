
#include <gtest/gtest.h>

#include <vector>

#include "../s21_matrix_oop.h"

TEST(MatrtixTest, CreateMatrix) {
    S21Matrix mat = S21Matrix(2, 2);
    S21Matrix* point = new S21Matrix(4, 4);
    point->FillRandMatrix();
    delete point;
    EXPECT_EQ(mat.GetCols(), 2);
    EXPECT_THROW(S21Matrix n(-1, 2), std::exception);
    EXPECT_THROW(S21Matrix n( 1, 0), std::exception);
    EXPECT_THROW(S21Matrix n(nullptr, 1, 0), std::exception);
}


TEST(MatrtixTest, MoveMatrix) {
    double data[4] = {2, 1, 2, 4};
    S21Matrix matrix1(data, 2, 2);
    S21Matrix matrix2 =  std::move(matrix1);
    S21Matrix matrix3(data, 2, 2);
    EXPECT_EQ(matrix2 == matrix3, true);
    EXPECT_EQ(matrix1.GetRows() == 0, true);
    EXPECT_EQ(matrix1.GetCols() == 0, true);

}
TEST(MatrtixTest, GetRowsColsMatrix) {
    S21Matrix mat = S21Matrix(2, 2);
    int rows = mat.GetRows();
    EXPECT_EQ(rows, 2);
    EXPECT_EQ(mat.GetCols(), 2);
    EXPECT_THROW(mat.SetRows(0), std::exception);
}

TEST(MatrtixTest, SetRowsColsMatrix) {
    S21Matrix mat = S21Matrix(2, 2);
    mat.SetCols(5);
    mat.SetRows(6);
    int rows = mat.GetRows();
    EXPECT_EQ(rows, 6);
    EXPECT_EQ(mat.GetCols(), 5);
    EXPECT_THROW(mat.SetCols(0), std::exception);
}
TEST(MatrtixTestFunction, EqMatrix) {
    double data[4] = {2, 1, 2, 4};
    double dataNew[4] = {2, 0, 2, 4};
    S21Matrix matrix1 = S21Matrix(data, 2, 2);
    S21Matrix matrix2 = S21Matrix(data, 2, 2);
    S21Matrix matrix3 = S21Matrix(dataNew, 2, 2);
    EXPECT_EQ(matrix1.EqMatrix(matrix2), true);
    EXPECT_EQ(matrix1.EqMatrix(matrix3), false);
}

TEST(MatrtixTestFunction, SumMatrixFunction) {
    double data[4] = {2, 1, 2, 4};
    double dataout[4] = {4, 2, 4, 8};
    S21Matrix matrix1 = S21Matrix(data, 2, 2);
    S21Matrix matrix2 = S21Matrix(data, 2, 2);
    S21Matrix matrix3 = S21Matrix(dataout, 2, 2);
    matrix1.SumMatrix(matrix2);
    EXPECT_EQ(matrix1.EqMatrix(matrix3), true);
    matrix1.SetCols(7);
    EXPECT_THROW(matrix1 + matrix3, std::exception);
}

TEST(MatrtixTestFunction, SubMatrixFunction) {
    double data[4] = {2, 1, 2, 4};
    double dataout[4] = {0, 0, 0, 0};
    S21Matrix matrix1 = S21Matrix(data, 2, 2);
    S21Matrix matrix2 = S21Matrix(data, 2, 2);
    S21Matrix matrix3 = S21Matrix(dataout, 2, 2);
    matrix1.SubMatrix(matrix2);
    EXPECT_EQ(matrix1.EqMatrix(matrix3), true);
    matrix1.SetCols(7);
    EXPECT_THROW(matrix1 - matrix3, std::exception);
}

TEST(MatrtixTestFunction, MulNumberFunction) {
    double data[4] = {2, 1, 2, 4};
    double dataout[4] = {8, 4, 8, 16};
    S21Matrix matrix1 = S21Matrix(data, 2, 2);
    S21Matrix matrix3 = S21Matrix(dataout, 2, 2);
    matrix1.MulNumber(4);
    EXPECT_EQ(matrix1.EqMatrix(matrix3), true);
}
TEST(MatrtixTestFunction, MulMatrixFunction) {
    double data[4] = {2, 1, 2, 4};
    double dataout[4] = {6, 6, 12, 18};
    S21Matrix matrix1 = S21Matrix(data, 2, 2);
    S21Matrix matrix2 = S21Matrix(data, 2, 2);
    S21Matrix matrix3 = S21Matrix(dataout, 2, 2);
    matrix1.MulMatrix(matrix2);
    EXPECT_EQ(matrix1.EqMatrix(matrix3), true);
}

TEST(MatrtixTestFunction, MulMatrixFunctionWithExeption) {
    double data[4] = {2, 1, 2, 4};
    double dataout[6] = {2, 1, 2, 4, 0, 0};
    S21Matrix matrix1 = S21Matrix(data, 2, 2);
    S21Matrix matrix3 = S21Matrix(dataout, 3, 2);
    matrix1.SetRows(3);
    EXPECT_EQ(matrix1.EqMatrix(matrix3), true);
    EXPECT_THROW(matrix1 * matrix3, std::exception);
}

TEST(MatrtixTestFunction, TrancFunction) {
    double data[4] = {2, 1, 2, 4};
    double dataout[4] = {2, 2, 1, 4};
    S21Matrix matrix1 = S21Matrix(data, 2, 2);
    S21Matrix matrix2(matrix1);
    matrix2 = matrix1.Transpose();
    S21Matrix matrix3 = S21Matrix(dataout, 2, 2);
    EXPECT_EQ(matrix2.EqMatrix(matrix3), true);
}
TEST(MatrtixTestFunction, CalcComplemencFunction) {
    double data[4] = {2, 1, 2, 4};
    double dataout[4] = {4, -2, -1, 2};
    S21Matrix matrix1 = S21Matrix(data, 2, 2);
    S21Matrix matrix2;
    matrix2 = matrix1.CalcComplements();
    S21Matrix matrix3 = S21Matrix(dataout, 2, 2);
    EXPECT_EQ(matrix2.EqMatrix(matrix3), true);
    matrix2.SetRows(4);
    EXPECT_THROW(matrix2.CalcComplements(), std::exception);
    S21Matrix matrixNULL = std::move(matrix2);
    EXPECT_THROW(matrix2.CalcComplements(), std::exception);
    S21Matrix matrix4(1, 1);
    matrix4.setValue(0,0, 2);
    S21Matrix matrix5 = matrix4.CalcComplements();
    EXPECT_EQ(matrix5(0,0) == 2, true);
}


TEST(MatrtixTestFunction, DeterminantFunction) {
    double data[4] = {2, 1, 2, 4};
    S21Matrix matrix1 = S21Matrix(data, 2, 2);
    double det = matrix1.Determinant();
    EXPECT_EQ(det, 6);
    matrix1.SetRows(4);
    EXPECT_THROW(matrix1.Determinant(), std::exception);
    double data1[9] = {1, 2, 33, 2, 543, 23, 123, 123, 124};
    S21Matrix matrix2 = S21Matrix(data1, 3, 3);
    EXPECT_EQ(matrix2.Determinant() == -2126254, true);

}

TEST(MatrtixTestFunction, InverseMatrixFunction) {
    double data[4] = {2, 1, 2, 4};
    double dataout[4] = {2 / 3., -1 / 6., -1 / 3., 1 / 3.};
    double data1[9] = {1, 2, 3, 4 ,5, 6, 7, 8, 9};
    S21Matrix matrix1 = S21Matrix(data, 2, 2);
    S21Matrix matrix2(matrix1);
    matrix2 = matrix1.InverseMatrix();
    S21Matrix matrix3 = S21Matrix(dataout, 2, 2);
    EXPECT_EQ(matrix2.EqMatrix(matrix3), true);
    matrix3.SetRows(8);
    EXPECT_THROW(matrix3.InverseMatrix(), std::exception);
    S21Matrix ZeroDet(data1, 3, 3);
    EXPECT_THROW(ZeroDet.InverseMatrix(), std::exception);
    double data2[1] = {2};
    S21Matrix matrix4(data2, 1, 1);
    S21Matrix tt = matrix4.InverseMatrix();
    EXPECT_EQ(tt(0, 0) == 0.5, true);
}

TEST(MatrtixTestOperator, EqualToOperator) {
    double data[4] = {2, 1, 2, 4};
    double dataout[4] = {4, 2, 4, 8};
    S21Matrix matrix1 = S21Matrix(data, 2, 2);
    S21Matrix matrix2 = S21Matrix(data, 2, 2);
    S21Matrix matrix3 = S21Matrix(dataout, 2, 2);
    matrix1 = matrix2 + matrix1;
    EXPECT_EQ((matrix1 == matrix3), true);
    EXPECT_EQ((matrix1 == matrix2), false);
}

TEST(MatrtixTestOperator, SumMatrixOperator) {
    double data[4] = {2, 1, 2, 4};
    double dataout[4] = {4, 2, 4, 8};
    S21Matrix matrix1 = S21Matrix(data, 2, 2);
    S21Matrix matrix2 = S21Matrix(data, 2, 2);
    S21Matrix matrix3 = S21Matrix(dataout, 2, 2);
    matrix1 = matrix2 + matrix1;
    EXPECT_EQ(matrix1.EqMatrix(matrix3), true);
}

TEST(MatrtixTestOperator, SumMatrixAssignmentOperator) {
    double data[4] = {2, 1, 2, 4};
    double dataout[4] = {4, 2, 4, 8};
    S21Matrix matrix1 = S21Matrix(data, 2, 2);
    S21Matrix matrix2 = S21Matrix(data, 2, 2);
    S21Matrix matrix3 = S21Matrix(dataout, 2, 2);
    matrix1 += matrix2;
    EXPECT_EQ(matrix1.EqMatrix(matrix3), true);
}

TEST(MatrtixTestOperator, SubMatrixOperator) {
    double data[4] = {2, 1, 2, 4};
    double dataout[4] = {0, 0, 0, 0};
    S21Matrix matrix1 = S21Matrix(data, 2, 2);
    S21Matrix matrix2 = S21Matrix(data, 2, 2);
    S21Matrix matrix3 = S21Matrix(dataout, 2, 2);
    matrix1 = matrix2 - matrix1;
    EXPECT_EQ(matrix1.EqMatrix(matrix3), true);
}

TEST(MatrtixTestOperator, SubMatrixAssignmentOperator) {
    double data[4] = {2, 1, 2, 4};
    double dataout[4] = {0, 0, 0, 0};
    S21Matrix matrix1 = S21Matrix(data, 2, 2);
    S21Matrix matrix2 = S21Matrix(data, 2, 2);
    S21Matrix matrix3 = S21Matrix(dataout, 2, 2);
    matrix1 -= matrix2;
    EXPECT_EQ(matrix1.EqMatrix(matrix3), true);
}

TEST(MatrtixTestOperator, MulMatrixOperator) {
    double data[4] = {2, 1, 2, 4};
    double dataout[4] = {6, 6, 12, 18};
    S21Matrix matrix1 = S21Matrix(data, 2, 2);
    S21Matrix matrix2 = S21Matrix(data, 2, 2);
    S21Matrix matrix3 = S21Matrix(dataout, 2, 2);
    matrix1 = matrix2 * matrix1;
    EXPECT_EQ(matrix1.EqMatrix(matrix3), true);
}

TEST(MatrtixTestOperator, MulMatrixAssignmentOperator) {
    double data[4] = {2, 1, 2, 4};
    double dataout[4] = {6, 6, 12, 18};
    S21Matrix matrix1 = S21Matrix(data, 2, 2);
    S21Matrix matrix2 = S21Matrix(data, 2, 2);
    S21Matrix matrix3 = S21Matrix(dataout, 2, 2);
    matrix1 *= matrix2;
    EXPECT_EQ(matrix1.EqMatrix(matrix3), true);
}

TEST(MatrtixTestOperator, MulNumberOperator) {
    double data[4] = {2, 1, 2, 4};
    double dataout[4] = {4, 2, 4, 8};
    S21Matrix matrix1 = S21Matrix(data, 2, 2);
    S21Matrix matrix2 = S21Matrix(dataout, 2, 2);
    matrix1 = matrix1 * 2;
    EXPECT_EQ(matrix2.EqMatrix(matrix1), true);
}
TEST(MatrtixTestOperator, MulNumberFriendOperator) {
    double data[4] = {2, 1, 2, 4};
    double dataout[4] = {4, 2, 4, 8};
    S21Matrix matrix1 = S21Matrix(data, 2, 2);
    S21Matrix matrix2 = S21Matrix(dataout, 2, 2);
    matrix1 =  matrix1 * 2.0;
    EXPECT_EQ(matrix2.EqMatrix(matrix1), true);
}

TEST(MatrtixTestOperator, MulNumberAssignmentOperator) {
    double data[4] = {2, 1, 2, 4};
    double dataout[4] = {4, 2, 4, 8};
    S21Matrix matrix1 = S21Matrix(data, 2, 2);
    S21Matrix matrix2 = S21Matrix(dataout, 2, 2);
    matrix1 *= 2;
    EXPECT_EQ(matrix2.EqMatrix(matrix1), true);
}
TEST(MatrtixTestOperator, OpertorGetElement) {
    double data[4] = {2, 1, 2, 4};
    S21Matrix matrix1 = S21Matrix(data, 2, 2);
    EXPECT_EQ( matrix1(0, 0) == data[0], true);
    EXPECT_THROW(matrix1(-1, 2), std::exception);
    EXPECT_THROW(matrix1(3, 2), std::exception);

}


TEST(MatrtixTestOperator, FunctionCopydata) {
    double data[4] = {2, 1, 2, 4};
    S21Matrix matrix1 = S21Matrix(data, 2, 2);
    S21Matrix matrix2(2, 2);
    matrix2.copy_data(&matrix2, matrix1);
    EXPECT_EQ( matrix1 == matrix2, true);
}
TEST(MatrtixTestOperator, FunctionFillint) {
    double data[4] = {0, 1, 2, 3};
    S21Matrix matrix1 = S21Matrix(data, 2, 2);
    S21Matrix matrix2(2, 2);
    matrix2.fill_int();
    EXPECT_EQ( matrix1 == matrix2, true);
}

TEST(MatrtixTestOperator, Functionprint) {
    double data[4] = {0, 1, 2, 3};
    S21Matrix matrix1 = S21Matrix(data, 2, 2);
    matrix1.print();
    S21Matrix deleter = std::move(matrix1);
    EXPECT_THROW(matrix1.print(), std::exception);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}