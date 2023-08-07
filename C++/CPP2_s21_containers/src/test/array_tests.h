#include <gtest/gtest.h>

#include "../s21_containersplus.h"
class ArrayTest {
 public:
  s21::Array<int, 5> s21_array_null{};
  std::array<int, 5> std_array_null{};

  s21::Array<int, 5> s21_array_swap1{1, 1, 1, 1, 1};
  std::array<int, 5> std_array_swap1{1, 1, 1, 1, 1};

  s21::Array<int, 5> s21_array_swap2{2, 2, 2, 2, 2};
  std::array<int, 5> std_array_swap2{2, 2, 2, 2, 2};

  s21::Array<int, 5> s21_array_data{1, 2, 3, 4, 5};
  std::array<int, 5> std_array_data{1, 2, 3, 4, 5};
};

TEST(array, null_constructor) {
  ArrayTest data;
  EXPECT_EQ(data.s21_array_null.size(), data.std_array_null.size());
  EXPECT_EQ(data.s21_array_null.empty(), data.std_array_null.empty());
  EXPECT_EQ(data.s21_array_null.max_size(), data.std_array_null.max_size());
}

TEST(array, copy_constructor) {
  ArrayTest data;

  s21::Array<int, 5> a(data.s21_array_data);
  std::array<int, 5> b(data.std_array_data);

  EXPECT_EQ(a.size(), b.size());
  EXPECT_EQ(a.empty(), b.empty());
  std::array<int, 5>::iterator s_iter = a.begin();
  s21::Array<int, 5>::iterator l_iter = b.begin();

  std::array<int, 5>::iterator s_end = a.end();

  while (s_iter != s_end) {
    std::cout << *s_iter << " == " << *l_iter << "?\n";
    EXPECT_EQ(*s_iter, *l_iter);
    ++s_iter;
    ++l_iter;
  }
}

TEST(array, move_constructor) {
  ArrayTest data;

  s21::Array<int, 5> a(std::move(data.s21_array_data));
  std::array<int, 5> b(std::move(data.std_array_data));

  EXPECT_EQ(a.size(), b.size());
  EXPECT_EQ(a.empty(), b.empty());

  std::array<int, 5>::iterator s_iter = a.begin();
  s21::Array<int, 5>::iterator l_iter = b.begin();

  std::array<int, 5>::iterator s_end = a.end();

  while (s_iter != s_end) {
    //    std::cout << *s_iter << " == " << *l_iter << "?\n";
    EXPECT_EQ(*s_iter, *l_iter);
    ++s_iter;
    ++l_iter;
  }

  s_iter = a.begin();
  l_iter = b.begin();

  s_end = a.end();

  while (s_iter != s_end) {
    //    std::cout << *s_iter << " == " << *l_iter << "?\n";
    EXPECT_EQ(*s_iter, *l_iter);
    ++s_iter;
    ++l_iter;
  }
}

TEST(array, copy_operator) {
  ArrayTest data;

  s21::Array<int, 5> a;
  a = data.s21_array_null;
  std::array<int, 5> b;
  b = data.std_array_null;

  EXPECT_EQ(a.size(), b.size());
  EXPECT_EQ(a.empty(), b.empty());

  std::array<int, 5>::iterator s_iter = a.begin();
  s21::Array<int, 5>::iterator l_iter = b.begin();

  std::array<int, 5>::iterator s_end = a.end();

  while (s_iter != s_end) {
    //    std::cout << *s_iter << " == " << *l_iter << "?\n";
    EXPECT_EQ(*s_iter, *l_iter);
    ++s_iter;
    ++l_iter;
  }

  a = data.s21_array_data;
  b = data.std_array_data;

  s_iter = a.begin();
  l_iter = b.begin();

  s_end = a.end();

  while (s_iter != s_end) {
    //    std::cout << *s_iter << " == " << *l_iter << "?\n";
    EXPECT_EQ(*s_iter, *l_iter);
    ++s_iter;
    ++l_iter;
  }
}

TEST(array, move_operator) {
  ArrayTest data;

  s21::Array<int, 5> b;
  b = std::move(data.s21_array_null);
  std::array<int, 5> a;
  a = std::move(data.std_array_null);

  EXPECT_EQ(a.size(), b.size());
  EXPECT_EQ(a.empty(), b.empty());

  std::array<int, 5>::iterator s_iter = a.begin();
  s21::Array<int, 5>::iterator l_iter = b.begin();

  std::array<int, 5>::iterator s_end = a.end();

  while (s_iter != s_end) {
    //    std::cout << *s_iter << " == " << *l_iter << "?\n";
    EXPECT_EQ(*s_iter, *l_iter);
    ++s_iter;
    ++l_iter;
  }

  s_iter = data.std_array_null.begin();
  l_iter = data.s21_array_null.begin();

  std::array<int, 5>::iterator l_end = data.s21_array_null.end();

  while (l_iter != l_end) {
    //    std::cout << *s_iter << " == " << *l_iter << "?\n";
    EXPECT_EQ(*s_iter, *l_iter);
    ++s_iter;
    ++l_iter;
  }

  b = std::move(data.s21_array_data);
  a = std::move(data.std_array_data);

  s_iter = a.begin();
  l_iter = b.begin();

  s_end = a.end();

  while (s_iter != s_end) {
    //    std::cout << *s_iter << " == " << *l_iter << "?\n";
    EXPECT_EQ(*s_iter, *l_iter);
    ++s_iter;
    ++l_iter;
  }

  s_iter = data.std_array_data.begin();
  l_iter = data.s21_array_data.begin();

  l_end = data.s21_array_data.end();

  while (l_iter != l_end) {
    //    std::cout << *s_iter << " == " << *l_iter << "?\n";
    EXPECT_EQ(*s_iter, *l_iter);
    ++s_iter;
    ++l_iter;
  }
}

TEST(array, swap) {
  ArrayTest data;

  data.std_array_swap1.swap(data.std_array_swap2);
  data.s21_array_swap1.swap(data.s21_array_swap2);

  std::array<int, 5>::iterator s_iter = data.std_array_swap1.begin();
  s21::Array<int, 5>::iterator l_iter = data.s21_array_swap1.begin();

  std::array<int, 5>::iterator s_end = data.std_array_swap1.end();

  while (s_iter != s_end) {
    //    std::cout << *s_iter << " == " << *l_iter << "?\n";
    EXPECT_EQ(*s_iter, *l_iter);
    ++s_iter;
    ++l_iter;
  }

  s_iter = data.std_array_swap2.begin();
  l_iter = data.s21_array_swap2.begin();

  s_end = data.std_array_swap2.end();

  while (s_iter != s_end) {
    //    std::cout << *s_iter << " == " << *l_iter << "?\n";
    EXPECT_EQ(*s_iter, *l_iter);
    ++s_iter;
    ++l_iter;
  }
}

TEST(array, data_fill) {
  ArrayTest data;

  data.s21_array_null.fill(3);

  std::array<int, 5>::iterator s_iter = data.std_array_swap1.data();
  s21::Array<int, 5>::iterator l_iter = data.s21_array_swap1.data();

  std::array<int, 5>::iterator s_end = data.std_array_swap1.end();

  while (s_iter != s_end) {
    //    std::cout << *s_iter << " == " << *l_iter << "?\n";
    EXPECT_EQ(*s_iter, *l_iter);
    ++s_iter;
    ++l_iter;
  }
}

TEST(array, at) {
  ArrayTest data;

  data.std_array_swap1.at(3);
  data.s21_array_swap1.at(3);

  EXPECT_EQ(data.std_array_swap1.at(3), data.s21_array_swap1.at(3));
  EXPECT_EQ(data.std_array_swap1[3], data.s21_array_swap1[3]);
  EXPECT_ANY_THROW(data.std_array_swap1.at(7));
  EXPECT_ANY_THROW(data.s21_array_swap1.at(7));
}