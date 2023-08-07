#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <queue>
#include <vector>

#include "../s21_containers.h"

class QueueTest {
 public:
  s21::Queue<int> s21_queue_null;
  std::queue<int> std_queue_null;

  s21::Queue<int> s21_queue_swap1{1, 1, 1};
  std::queue<int> std_queue_swap1;

  s21::Queue<int> s21_queue_swap2{2, 2, 2, 2};
  std::queue<int> std_queue_swap2;
};

TEST(queue, null_constructor) {
  QueueTest data;
  EXPECT_EQ(data.s21_queue_null.size(), data.std_queue_null.size());
  EXPECT_EQ(data.s21_queue_null.empty(), data.std_queue_null.empty());
}

TEST(queue, copy_constructor) {
  QueueTest data;
  data.s21_queue_null.push(3);
  data.s21_queue_null.push(4);

  data.std_queue_null.push(3);
  data.std_queue_null.push(4);

  s21::Queue<int> a(data.s21_queue_null);
  std::queue<int> b(data.std_queue_null);

  EXPECT_EQ(a.size(), b.size());
  EXPECT_EQ(a.empty(), b.empty());

  while (!a.empty()) {
    EXPECT_EQ(a.front(), b.front());
    a.pop();
    b.pop();
  }

  while (!data.s21_queue_null.empty()) {
    EXPECT_EQ(data.s21_queue_null.front(), data.std_queue_null.front());
    data.s21_queue_null.pop();
    data.std_queue_null.pop();
  }
}

TEST(queue, move_constructor) {
  QueueTest data;
  data.s21_queue_null.push(3);
  data.s21_queue_null.push(4);

  data.std_queue_null.push(3);
  data.std_queue_null.push(4);

  s21::Queue<int> a(std::move(data.s21_queue_null));
  std::queue<int> b(std::move(data.std_queue_null));

  EXPECT_EQ(a.size(), b.size());
  EXPECT_EQ(a.empty(), b.empty());

  while (!a.empty()) {
    EXPECT_EQ(a.front(), b.front());
    a.pop();
    b.pop();
  }

  while (!data.s21_queue_null.empty()) {
    EXPECT_EQ(data.s21_queue_null.front(), data.std_queue_null.front());
    data.s21_queue_null.pop();
    data.std_queue_null.pop();
  }
}

TEST(queue, copy_operator) {
  QueueTest data;
  data.s21_queue_null.push(3);
  data.s21_queue_null.push(4);

  data.std_queue_null.push(3);
  data.std_queue_null.push(4);

  s21::Queue<int> a;
  a = data.s21_queue_null;
  std::queue<int> b;
  b = data.std_queue_null;

  EXPECT_EQ(a.size(), b.size());
  EXPECT_EQ(a.empty(), b.empty());

  while (!a.empty()) {
    EXPECT_EQ(a.front(), b.front());
    a.pop();
    b.pop();
  }

  while (!data.s21_queue_null.empty()) {
    EXPECT_EQ(data.s21_queue_null.front(), data.std_queue_null.front());
    data.s21_queue_null.pop();
    data.std_queue_null.pop();
  }
}

TEST(queue, move_operator) {
  QueueTest data;
  data.s21_queue_null.push(3);
  data.s21_queue_null.push(4);

  data.std_queue_null.push(3);
  data.std_queue_null.push(4);

  s21::Queue<int> a;
  a = std::move(data.s21_queue_null);
  std::queue<int> b;
  b = std::move(data.std_queue_null);

  EXPECT_EQ(a.size(), b.size());
  EXPECT_EQ(a.empty(), b.empty());

  while (!a.empty()) {
    EXPECT_EQ(a.front(), b.front());
    a.pop();
    b.pop();
  }

  while (!data.s21_queue_null.empty()) {
    EXPECT_EQ(data.s21_queue_null.front(), data.std_queue_null.front());
    data.s21_queue_null.pop();
    data.std_queue_null.pop();
  }
}

TEST(queue, swap) {
  QueueTest data;

  data.std_queue_swap1.push(1);
  data.std_queue_swap1.push(1);
  data.std_queue_swap1.push(1);

  data.std_queue_swap2.push(2);
  data.std_queue_swap2.push(2);
  data.std_queue_swap2.push(2);
  data.std_queue_swap2.push(2);

  data.std_queue_swap1.swap(data.std_queue_swap2);
  data.s21_queue_swap1.swap(data.s21_queue_swap2);

  EXPECT_EQ(data.std_queue_swap1.front(), data.s21_queue_swap1.front());
  EXPECT_EQ(data.std_queue_swap1.back(), data.s21_queue_swap1.back());

  EXPECT_EQ(data.std_queue_swap2.front(), data.s21_queue_swap2.front());
  EXPECT_EQ(data.std_queue_swap2.back(), data.s21_queue_swap2.back());

  while (!data.s21_queue_swap2.empty()) {
    EXPECT_EQ(data.s21_queue_swap2.front(), data.std_queue_swap2.front());
    EXPECT_EQ(data.s21_queue_swap2.front(), 1);
    EXPECT_EQ(data.s21_queue_swap2.back(), 1);
    data.s21_queue_swap2.pop();
    data.std_queue_swap2.pop();
  }

  while (!data.s21_queue_swap1.empty()) {
    EXPECT_EQ(data.s21_queue_swap1.front(), data.std_queue_swap1.front());
    EXPECT_EQ(data.s21_queue_swap1.front(), 2);
    EXPECT_EQ(data.s21_queue_swap1.back(), 2);

    data.s21_queue_swap1.pop();
    data.std_queue_swap1.pop();
  }
}

TEST(queue, emplace) {
  QueueTest data;
  data.std_queue_swap1.push(1);
  data.std_queue_swap1.push(1);
  data.std_queue_swap1.push(1);

  data.std_queue_swap1.emplace(6);
  data.s21_queue_swap1.emplace_back(6);

  data.std_queue_swap1.emplace(7);
  data.s21_queue_swap1.emplace_back(7);

  while (!data.s21_queue_swap1.empty()) {
    EXPECT_EQ(data.s21_queue_swap1.front(), data.std_queue_swap1.front());
    data.s21_queue_swap1.pop();
    data.std_queue_swap1.pop();
  }
}