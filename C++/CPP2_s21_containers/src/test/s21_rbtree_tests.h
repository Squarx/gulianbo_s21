//
// Created by Gulian Boris on 5/19/23.
//

#ifndef CPP2_S21_CONTAINERS_1_SRC_TEST_S21_RBTREE_TESTS_H_
#define CPP2_S21_CONTAINERS_1_SRC_TEST_S21_RBTREE_TESTS_H_
#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "../s21_tree.h"
class TestTreeInt {
 public:
  s21::Tree<int> s21_empty;
  s21::Tree<int> s21_ten{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  s21::Tree<int> s21_move_empty;
  s21::Tree<int> s21_move_ten{11, 22, 33, 44, 55, 66, 77, 88, 99, 1010};
};

TEST(Tree, construcors) {
  TestTreeInt tester;
  EXPECT_EQ(tester.s21_empty.Size(), 0);
  EXPECT_EQ(tester.s21_ten.Size(), 10);
}
TEST(Tree, constructor_copy_empty) {
  TestTreeInt tester;
  s21::Tree<int> s21_tree_copy(tester.s21_empty);
  EXPECT_EQ(s21_tree_copy.Size(), tester.s21_empty.Size());
}
TEST(Tree, constructor_copy_not_empty) {
  TestTreeInt tester;
  s21::Tree<int> s21_tree_copy(tester.s21_ten);
  EXPECT_EQ(s21_tree_copy.Size(), tester.s21_ten.Size());
}

TEST(Tree, constructor_move_empty) {
  TestTreeInt tester;
  s21::Tree<int> s21_tree_copy(std::move(tester.s21_empty));
  EXPECT_EQ(s21_tree_copy.Size(), tester.s21_empty.Size());
}

TEST(Tree, constructor_move_not_empty) {
  TestTreeInt tester;
  s21::Tree<int> s21_tree_copy(std::move(tester.s21_ten));
  EXPECT_EQ(s21_tree_copy.Size(), tester.s21_move_ten.Size());
  EXPECT_EQ(tester.s21_ten.Size(), 0);
}

TEST(Tree, operator_copy_empty) {
  TestTreeInt tester;
  tester.s21_move_empty = tester.s21_empty;
  EXPECT_EQ(tester.s21_move_empty.Size(), tester.s21_empty.Size());
}

TEST(Tree, operator_copy_not_empty) {
  TestTreeInt tester;
  tester.s21_move_empty = tester.s21_ten;
  EXPECT_EQ(tester.s21_move_empty.Size(), tester.s21_ten.Size());
}

TEST(Tree, operator_move_empty) {
  TestTreeInt tester;
  tester.s21_move_empty = std::move(tester.s21_empty);
  EXPECT_EQ(tester.s21_move_empty.Size(), tester.s21_empty.Size());
}

TEST(Tree, operator_move_not_empty) {
  TestTreeInt tester;
  tester.s21_move_empty = std::move(tester.s21_ten);
  EXPECT_EQ(tester.s21_move_empty.Size(), tester.s21_move_ten.Size());
  EXPECT_EQ(tester.s21_ten.Size(), 0);
}
#endif  // CPP2_S21_CONTAINERS_1_SRC_TEST_S21_RBTREE_TESTS_H_
