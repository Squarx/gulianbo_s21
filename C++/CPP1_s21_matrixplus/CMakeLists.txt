cmake_minimum_required(VERSION 3.23)
project(CPP1_s21_matrixplus)

set(CMAKE_CXX_STANDARD 14)

include_directories(code-samples)

add_executable(CPP1_s21_matrixplus
       src/s21_matrix.cpp src/s21_matrix.h src/main.cpp)
