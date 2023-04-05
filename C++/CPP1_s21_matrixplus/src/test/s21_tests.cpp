
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
}

TEST(MatrtixTest, VectorMatrixMemoryTest) {
    std::vector<S21Matrix> matrixVector;
    matrixVector.push_back(S21Matrix(2, 2));
    matrixVector.push_back(S21Matrix(5, 5));
    matrixVector.push_back(S21Matrix(5, 7));
    matrixVector.pop_back();
}

//TEST(MatrtixTest, MoveMatrix) {
//    double data[4] = {2, 1, 2, 4};
//    S21Matrix matrix1(data, 2, 2);
//    S21Matrix matrix2;
//    S21Matrix matrix3(data, 2, 2);
//    matrix2 = std::move(matrix1);
//    EXPECT_EQ(matrix2 == matrix3, true);
//}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}