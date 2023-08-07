#include <gtest/gtest.h>

#include <stack>
#include <vector>

#include "../s21_containers.h"

class stackTest {
 public:
  s21::Stack<int> s21_stack_null;
  std::stack<int> std_stack_null;

  s21::Stack<int> s21_stack_swap1{1, 1, 1};
  std::stack<int> std_stack_swap1;

  s21::Stack<int> s21_stack_swap2{2, 2, 2, 2};
  std::stack<int> std_stack_swap2;
};

TEST(stack, null_constructor) {
  stackTest data;
  EXPECT_EQ(data.s21_stack_null.size(), data.std_stack_null.size());
  EXPECT_EQ(data.s21_stack_null.empty(), data.std_stack_null.empty());
}

TEST(stack, copy_constructor) {
  stackTest data;
  data.s21_stack_null.push(3);
  data.s21_stack_null.push(4);

  data.std_stack_null.push(3);
  data.std_stack_null.push(4);

  s21::Stack<int> a(data.s21_stack_null);
  std::stack<int> b(data.std_stack_null);

  EXPECT_EQ(a.size(), b.size());
  EXPECT_EQ(a.empty(), b.empty());

  while (!a.empty()) {
    EXPECT_EQ(a.top(), b.top());
    a.pop();
    b.pop();
  }

  while (!data.s21_stack_null.empty()) {
    EXPECT_EQ(data.s21_stack_null.top(), data.std_stack_null.top());
    data.s21_stack_null.pop();
    data.std_stack_null.pop();
  }
}

TEST(stack, move_constructor) {
  stackTest data;
  data.s21_stack_null.push(3);
  data.s21_stack_null.push(4);

  data.std_stack_null.push(3);
  data.std_stack_null.push(4);

  s21::Stack<int> a(std::move(data.s21_stack_null));
  std::stack<int> b(std::move(data.std_stack_null));

  EXPECT_EQ(a.size(), b.size());
  EXPECT_EQ(a.empty(), b.empty());

  while (!a.empty()) {
    EXPECT_EQ(a.top(), b.top());
    a.pop();
    b.pop();
  }

  while (!data.s21_stack_null.empty()) {
    EXPECT_EQ(data.s21_stack_null.top(), data.std_stack_null.top());
    data.s21_stack_null.pop();
    data.std_stack_null.pop();
  }
}

TEST(stack, copy_operator) {
  stackTest data;
  data.s21_stack_null.push(3);
  data.s21_stack_null.push(4);

  data.std_stack_null.push(3);
  data.std_stack_null.push(4);

  s21::Stack<int> a;
  a = data.s21_stack_null;
  std::stack<int> b;
  b = data.std_stack_null;

  EXPECT_EQ(a.size(), b.size());
  EXPECT_EQ(a.empty(), b.empty());

  while (!a.empty()) {
    EXPECT_EQ(a.top(), b.top());
    a.pop();
    b.pop();
  }

  while (!data.s21_stack_null.empty()) {
    EXPECT_EQ(data.s21_stack_null.top(), data.std_stack_null.top());
    data.s21_stack_null.pop();
    data.std_stack_null.pop();
  }
}

TEST(stack, move_operator) {
  stackTest data;
  data.s21_stack_null.push(3);
  data.s21_stack_null.push(4);

  data.std_stack_null.push(3);
  data.std_stack_null.push(4);

  s21::Stack<int> a;
  a = std::move(data.s21_stack_null);
  std::stack<int> b;
  b = std::move(data.std_stack_null);

  EXPECT_EQ(a.size(), b.size());
  EXPECT_EQ(a.empty(), b.empty());

  while (!a.empty()) {
    EXPECT_EQ(a.top(), b.top());
    a.pop();
    b.pop();
  }

  while (!data.s21_stack_null.empty()) {
    EXPECT_EQ(data.s21_stack_null.top(), data.std_stack_null.top());
    data.s21_stack_null.pop();
    data.std_stack_null.pop();
  }
}

TEST(stack, swap) {
  stackTest data;

  data.std_stack_swap1.push(1);
  data.std_stack_swap1.push(1);
  data.std_stack_swap1.push(1);

  data.std_stack_swap2.push(2);
  data.std_stack_swap2.push(2);
  data.std_stack_swap2.push(2);
  data.std_stack_swap2.push(2);

  data.std_stack_swap1.swap(data.std_stack_swap2);
  data.s21_stack_swap1.swap(data.s21_stack_swap2);

  EXPECT_EQ(data.std_stack_swap1.top(), data.s21_stack_swap1.top());

  EXPECT_EQ(data.std_stack_swap2.top(), data.s21_stack_swap2.top());

  while (!data.s21_stack_swap2.empty()) {
    EXPECT_EQ(data.s21_stack_swap2.top(), data.std_stack_swap2.top());
    EXPECT_EQ(data.s21_stack_swap2.top(), 1);
    data.s21_stack_swap2.pop();
    data.std_stack_swap2.pop();
  }

  while (!data.s21_stack_swap1.empty()) {
    EXPECT_EQ(data.s21_stack_swap1.top(), data.std_stack_swap1.top());
    EXPECT_EQ(data.s21_stack_swap1.top(), 2);

    data.s21_stack_swap1.pop();
    data.std_stack_swap1.pop();
  }
}

TEST(stack, emplace) {
  stackTest data;
  data.std_stack_swap1.push(1);
  data.std_stack_swap1.push(1);
  data.std_stack_swap1.push(1);

  data.std_stack_swap1.emplace(6);
  data.s21_stack_swap1.emplace_front(6);

  data.std_stack_swap1.emplace(7);
  data.s21_stack_swap1.emplace_front(7);

  while (!data.s21_stack_swap1.empty()) {
    EXPECT_EQ(data.s21_stack_swap1.top(), data.std_stack_swap1.top());
    data.s21_stack_swap1.pop();
    data.std_stack_swap1.pop();
  }
}