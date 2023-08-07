//
// Created by Gulian Boris on 5/17/23.
//

#ifndef CPP2_S21_CONTAINERS_1_SRC_TEST_MULTISET_TEST_H_
#define CPP2_S21_CONTAINERS_1_SRC_TEST_MULTISET_TEST_H_

#include "../s21_containersplus.h"
#include "set_test.h"
class TestPersonMultiset {
 public:
  Person a = Person(1, 15000, "a");
  Person b = Person(2, 14000, "b");
  Person c = Person(3, 13000, "c");
  Person d = Person(4, 12000, "d");
  Person e = Person(5, 11000, "e");
  Person f = Person(6, 10000, "f");
  Person g = Person(7, 9000, "g");
  Person i = Person(8, 8000, "i");
  Person k = Person(9, 7000, "k");
  Person l = Person(10, 6000, "l");
  Person m = Person(11, 5000, "m");
  Person n = Person(12, 4000, "n");
  Person o = Person(13, 4000, "o");
  Person p = Person(14, 2000, "p");
  Person r = Person(15, 1000, "r");
  s21::Multiset<Person, PersonCmpSalary, std::allocator<Person>> s21_set_empty;
  s21::Multiset<Person, PersonCmpSalary, std::allocator<Person>> s21_set_ten{
      a, b, c, d, e, f, g, i, k, a, m};
  s21::Multiset<Person, PersonCmpSalary, std::allocator<Person>> s21_set_copy;
  s21::Multiset<Person, PersonCmpSalary, std::allocator<Person>> s21_move;
  s21::Multiset<Person, PersonCmpSalary, std::allocator<Person>> s21_set_swap{
      m, n, o, p, r};
  s21::Multiset<Person, PersonCmpSalary, std::allocator<Person>> s21_set_merge{
      a, b, c, o, p, r};
  s21::Multiset<Person, PersonCmpSalary, std::allocator<Person>> s21_set_delete{
      b, c, d, g, i, k, a, p, b};

  std::multiset<Person, PersonCmpSalary, std::allocator<Person>> std_set_empty;
  std::multiset<Person, PersonCmpSalary, std::allocator<Person>> std_set_ten{
      a, b, c, d, e, f, g, i, k, a, m};
  std::multiset<Person, PersonCmpSalary, std::allocator<Person>> std_set_copy;
  std::multiset<Person, PersonCmpSalary, std::allocator<Person>> std_move;
  std::multiset<Person, PersonCmpSalary, std::allocator<Person>> std_set_swap{
      m, n, o, p, r};
  std::multiset<Person, PersonCmpSalary, std::allocator<Person>> std_set_merge{
      a, b, c, o, p, r};
  std::multiset<Person, PersonCmpSalary, std::allocator<Person>> std_set_delete{
      b, c, d, g, i, k, a, p, b};
};
TEST(Multiset, constructor_default) {
  TestPersonMultiset tester;
  EXPECT_EQ(tester.s21_set_empty.size(), tester.std_set_empty.size());
  EXPECT_EQ(tester.s21_set_empty.empty(), tester.std_set_empty.empty());
}

TEST(Multiset, initializer_list) {
  TestPersonMultiset tester;
  EXPECT_EQ(tester.s21_set_ten.size(), tester.s21_set_ten.size());
  EXPECT_EQ(tester.std_set_ten.empty(), tester.std_set_ten.empty());
  EXPECT_EQ(tester.s21_set_ten.size(), tester.std_set_ten.size());
  EXPECT_EQ(tester.s21_set_ten.find(tester.a) != tester.s21_set_ten.end(),
            tester.std_set_ten.find(tester.b) != tester.std_set_ten.end());
  EXPECT_EQ(tester.s21_set_ten.find(tester.c) != tester.s21_set_ten.end(),
            tester.std_set_ten.find(tester.d) != tester.std_set_ten.end());
  EXPECT_EQ(tester.s21_set_ten.find(tester.e) != tester.s21_set_ten.end(),
            tester.std_set_ten.find(tester.f) != tester.std_set_ten.end());
  EXPECT_EQ(tester.s21_set_ten.find(tester.g) != tester.s21_set_ten.end(),
            tester.std_set_ten.find(tester.i) != tester.std_set_ten.end());
}

TEST(Multiset, constructor_copy) {
  TestPersonMultiset tester;
  s21::Multiset<Person, PersonCmpSalary, std::allocator<Person>> s21_empty(
      tester.s21_set_ten);
  std::multiset<Person, PersonCmpSalary, std::allocator<Person>> std_empty(
      tester.std_set_ten);
  EXPECT_EQ(s21_empty.size(), tester.s21_set_ten.size());
  EXPECT_EQ(s21_empty.empty(), std_empty.empty());
}

TEST(Multiset, operator_move) {
  //  s21_set_ten{a, b, c, d, e, f, g, i, k, a, m};
  TestPersonMultiset tester;
  tester.s21_move = std::move(tester.s21_set_ten);
  tester.std_move = std::move(tester.std_set_ten);
  EXPECT_EQ(tester.s21_move.find(tester.a) != tester.s21_move.end(),
            tester.std_move.find(tester.a) != tester.std_move.end());
  EXPECT_EQ(tester.s21_move.find(tester.b) != tester.s21_move.end(),
            tester.std_move.find(tester.b) != tester.std_move.end());
  EXPECT_EQ(tester.s21_move.find(tester.c) != tester.s21_move.end(),
            tester.std_move.find(tester.c) != tester.std_move.end());
  EXPECT_EQ(tester.s21_move.find(tester.d) != tester.s21_move.end(),
            tester.std_move.find(tester.d) != tester.std_move.end());
  EXPECT_EQ(tester.s21_move.size(), tester.std_move.size());
  EXPECT_EQ(tester.s21_move.empty(), tester.std_move.empty());
}

TEST(Multiset, operator_copy) {
  TestPersonMultiset tester;
  tester.s21_set_copy = tester.s21_set_ten;
  tester.std_set_copy = tester.std_set_ten;
  EXPECT_EQ(tester.s21_move.find(tester.a) != tester.s21_move.end(),
            tester.std_move.find(tester.a) != tester.std_move.end());
  EXPECT_EQ(tester.s21_move.find(tester.b) != tester.s21_move.end(),
            tester.std_move.find(tester.b) != tester.std_move.end());
  EXPECT_EQ(tester.s21_move.find(tester.c) != tester.s21_move.end(),
            tester.std_move.find(tester.c) != tester.std_move.end());
  EXPECT_EQ(tester.s21_move.find(tester.r) == tester.s21_move.end(),
            tester.std_move.find(tester.r) == tester.std_move.end());
  EXPECT_EQ(tester.s21_move.size(), tester.std_move.size());
  EXPECT_EQ(tester.s21_move.empty(), tester.std_move.empty());
  EXPECT_EQ(tester.s21_set_copy.size(), tester.std_set_copy.size());
  EXPECT_EQ(tester.s21_set_copy.empty(), tester.std_set_copy.empty());
}

TEST(Multiset, function_not_empty) {
  TestPersonMultiset tester_p;
  EXPECT_EQ(tester_p.s21_set_ten.size(), tester_p.std_set_ten.size());
  EXPECT_EQ(tester_p.s21_set_ten.empty(), tester_p.std_set_ten.empty());
  EXPECT_EQ(tester_p.s21_set_empty.size(), tester_p.std_set_empty.size());
  EXPECT_EQ(tester_p.s21_set_empty.empty(), tester_p.std_set_empty.empty());
  EXPECT_EQ(tester_p.s21_set_empty.size(), tester_p.std_set_empty.size());
}
TEST(Multiset, function_max_size) {
  TestSetInt tester_i;
  EXPECT_EQ(tester_i.s21_set_empty.max_size(),
            tester_i.std_set_empty.max_size());
  EXPECT_EQ(tester_i.s21_set_ten.max_size(), tester_i.std_set_ten.max_size());
  s21::Multiset<float> s21_float_empty;
  std::multiset<float> std_float_empty;
  EXPECT_EQ(s21_float_empty.max_size(), std_float_empty.max_size());
}

TEST(Multiset, function_swap_not_empty) {
  //  s21_set_ten{a, b, c, d, e, f, g, i, k, a, m};
  TestPersonMultiset tester;
  tester.s21_set_swap.swap(tester.s21_set_ten);
  tester.std_set_swap.swap(tester.std_set_ten);
  EXPECT_EQ(tester.s21_set_swap.find(tester.a) != tester.s21_set_swap.end(),
            tester.std_set_swap.find(tester.a) != tester.std_set_swap.end());
  EXPECT_EQ(tester.s21_set_swap.find(tester.b) != tester.s21_set_swap.end(),
            tester.std_set_swap.find(tester.b) != tester.std_set_swap.end());
  EXPECT_EQ(tester.s21_set_swap.find(tester.c) != tester.s21_set_swap.end(),
            tester.std_set_swap.find(tester.c) != tester.std_set_swap.end());
  EXPECT_EQ(tester.s21_set_swap.find(tester.r) == tester.s21_set_swap.end(),
            tester.std_set_swap.find(tester.r) == tester.std_set_swap.end());
  EXPECT_EQ(tester.s21_set_swap.size(), tester.std_set_swap.size());
  EXPECT_EQ(tester.s21_set_ten.size(), tester.std_set_ten.size());
}

TEST(Multiset, function_swap_empty) {
  TestPersonMultiset tester;
  tester.s21_set_swap.swap(tester.s21_set_copy);
  tester.std_set_swap.swap(tester.std_set_copy);
  EXPECT_EQ(tester.s21_set_swap.find(tester.a) == tester.s21_set_swap.end(),
            tester.std_set_swap.find(tester.a) == tester.std_set_swap.end());
  EXPECT_EQ(tester.s21_set_swap.size(), tester.std_set_swap.size());
  EXPECT_EQ(tester.s21_set_ten.size(), tester.std_set_ten.size());
}

TEST(Multiset, function_merge) {
  //  s21_set_ten{a, b, c, d, e, f, g, i, k, a, m};
  // s21_set_merge{a, b, c, o, p, r};
  TestPersonMultiset tester;
  tester.s21_set_merge.merge(tester.s21_set_ten);
  tester.std_set_merge.merge(tester.std_set_ten);
  EXPECT_EQ(tester.s21_set_merge.find(tester.a) != tester.s21_set_merge.end(),
            tester.std_set_merge.find(tester.a) != tester.std_set_merge.end());
  EXPECT_EQ(tester.s21_set_merge.find(tester.m) != tester.s21_set_merge.end(),
            tester.std_set_merge.find(tester.m) != tester.std_set_merge.end());
  EXPECT_EQ(tester.s21_set_merge.find(tester.e) != tester.s21_set_merge.end(),
            tester.std_set_merge.find(tester.e) != tester.std_set_merge.end());
  EXPECT_EQ(tester.s21_set_merge.size(), tester.std_set_merge.size());
  EXPECT_EQ(tester.s21_set_ten.size(), tester.std_set_ten.size());
  EXPECT_EQ(tester.std_set_merge.empty(), tester.std_set_merge.empty());
  EXPECT_EQ(tester.s21_set_ten.empty(), tester.std_set_ten.empty());
}

TEST(Multiset, function_clear_not_empty) {
  TestPersonMultiset tester;
  tester.s21_set_ten.clear();
  tester.std_set_ten.clear();
  EXPECT_EQ(tester.s21_set_ten.size(), tester.std_set_ten.size());
  EXPECT_EQ(tester.s21_set_ten.empty(), tester.std_set_ten.empty());
}

TEST(Multiset, function_clear_empty) {
  TestPersonMultiset tester;
  tester.s21_set_empty.clear();
  tester.std_set_empty.clear();
  EXPECT_EQ(tester.s21_set_empty.size(), tester.std_set_empty.size());
  EXPECT_EQ(tester.std_set_empty.empty(), tester.std_set_empty.empty());
}

TEST(Multiset, function_begin_not_empty) {
  TestPersonMultiset tester;
  s21::Multiset<Person, PersonCmpSalary, std::allocator<Person>>::iterator i =
      tester.s21_set_ten.begin();
  std::multiset<Person, PersonCmpSalary, std::allocator<Person>>::iterator j =
      tester.std_set_ten.begin();
  EXPECT_EQ((*i).getAge(), (*j).getAge());
}

TEST(Multiset, function_begin_empty) {
  TestPersonMultiset tester;
  s21::Multiset<Person, PersonCmpSalary, std::allocator<Person>>::iterator i =
      tester.s21_set_empty.begin();
  std::multiset<Person, PersonCmpSalary, std::allocator<Person>>::iterator j =
      tester.std_set_empty.begin();
  EXPECT_EQ((*i).getAge(), (*j).getAge());
  EXPECT_EQ((*i).getSal(), (*j).getSal());
}

TEST(Multiset, function_const_begin_not_empty) {
  TestPersonMultiset tester;
  s21::Multiset<Person, PersonCmpSalary, std::allocator<Person>>::const_iterator
      i = tester.s21_set_ten.begin();
  std::multiset<Person, PersonCmpSalary, std::allocator<Person>>::const_iterator
      j = tester.std_set_ten.begin();
  EXPECT_EQ((*i).getAge(), (*j).getAge());
  EXPECT_EQ((*i).getSal(), (*j).getSal());
}

TEST(Multiset, function_const_begin_empty) {
  TestPersonMultiset tester;
  s21::Multiset<Person, PersonCmpSalary, std::allocator<Person>>::const_iterator
      i = tester.s21_set_empty.begin();
  std::multiset<Person, PersonCmpSalary, std::allocator<Person>>::const_iterator
      j = tester.std_set_empty.begin();
  EXPECT_EQ((*i).getSal(), (*j).getSal());
  EXPECT_EQ((*i).getAge(), (*j).getAge());
}

TEST(Multiset, function_end_not_empty) {
  TestPersonMultiset tester;
  s21::Multiset<Person, PersonCmpSalary, std::allocator<Person>>::const_iterator
      i = tester.s21_set_ten.end();
  std::multiset<Person, PersonCmpSalary, std::allocator<Person>>::const_iterator
      j = tester.std_set_ten.end();
  --i;
  --j;
  EXPECT_EQ((*i).getSal(), (*j).getSal());
  EXPECT_EQ((*i).getAge(), (*j).getAge());
}

TEST(Multiset, function_end_empty) {
  TestPersonMultiset tester;
  s21::Multiset<Person, PersonCmpSalary, std::allocator<Person>>::const_iterator
      i = tester.s21_set_empty.end();
  std::multiset<Person, PersonCmpSalary, std::allocator<Person>>::const_iterator
      j = tester.std_set_empty.end();
  EXPECT_EQ((*i).getSal(), (*j).getSal());
  EXPECT_EQ((*i).getAge(), (*j).getAge());
}

TEST(Multiset, function_const_end_not_empty) {
  TestPersonMultiset tester;
  s21::Multiset<Person, PersonCmpSalary, std::allocator<Person>>::const_iterator
      i = tester.s21_set_ten.end();
  std::multiset<Person, PersonCmpSalary, std::allocator<Person>>::const_iterator
      j = tester.std_set_ten.end();
  --i;
  --j;
  EXPECT_EQ((*i).getSal(), (*j).getSal());
  EXPECT_EQ((*i).getAge(), (*j).getAge());
}

TEST(Multiset, function_const_end_empty) {
  TestPersonMultiset tester;
  s21::Multiset<Person, PersonCmpSalary, std::allocator<Person>>::const_iterator
      i = tester.s21_set_empty.end();
  std::multiset<Person, PersonCmpSalary, std::allocator<Person>>::const_iterator
      j = tester.std_set_empty.end();
  EXPECT_EQ((*i).getSal(), (*j).getSal());
  EXPECT_EQ((*i).getAge(), (*j).getAge());
}

TEST(Multiset, operator_plus) {
  TestPersonMultiset tester;
  s21::Multiset<Person, PersonCmpSalary, std::allocator<Person>>::iterator i =
      tester.s21_set_ten.begin();
  std::multiset<Person, PersonCmpSalary, std::allocator<Person>>::iterator j =
      tester.std_set_ten.begin();
  while (i != tester.s21_set_ten.end() && j != tester.std_set_ten.end()) {
    EXPECT_EQ((*i).getSal(), (*j).getSal());
    EXPECT_EQ((*i).getAge(), (*j).getAge());
    ++i;
    ++j;
  }
  EXPECT_EQ(tester.s21_set_ten.size(), tester.std_set_ten.size());
  EXPECT_EQ(tester.std_set_ten.empty(), tester.std_set_ten.empty());
}

TEST(Multiset, operator_plus_int) {
  TestPersonMultiset tester;
  s21::Multiset<Person, PersonCmpSalary, std::allocator<Person>>::iterator i =
      tester.s21_set_ten.begin();
  std::multiset<Person, PersonCmpSalary, std::allocator<Person>>::iterator j =
      tester.std_set_ten.begin();
  while (i != tester.s21_set_ten.end() && j != tester.std_set_ten.end()) {
    EXPECT_EQ((*i).getSal(), (*j).getSal());
    EXPECT_EQ((*i).getAge(), (*j).getAge());
    i++;
    j++;
  }
  EXPECT_EQ(tester.s21_set_ten.size(), tester.std_set_ten.size());
  EXPECT_EQ(tester.std_set_ten.empty(), tester.std_set_ten.empty());
}

TEST(Multiset, operation_assignment) {
  TestPersonMultiset tester;
  s21::Multiset<Person, PersonCmpSalary, std::allocator<Person>>::iterator
      iter_1 = tester.s21_set_ten.begin();
  s21::Multiset<Person, PersonCmpSalary, std::allocator<Person>>::iterator
      iter_3 = iter_1;
  std::multiset<Person, PersonCmpSalary, std::allocator<Person>>::iterator
      iter_2 = tester.std_set_ten.begin();
  std::multiset<Person, PersonCmpSalary, std::allocator<Person>>::iterator
      iter_4 = iter_2;
  EXPECT_EQ((*iter_1).getSal(), (*iter_3).getSal());
  EXPECT_EQ((*iter_1).getAge(), (*iter_3).getAge());
  EXPECT_EQ((*iter_2).getSal(), (*iter_4).getSal());
  EXPECT_EQ((*iter_2).getAge(), (*iter_4).getAge());
}

TEST(Multiset, operation_equal) {
  TestPersonMultiset tester;
  s21::Multiset<Person, PersonCmpSalary, std::allocator<Person>>::iterator it1 =
      tester.s21_set_ten.begin();
  s21::Multiset<Person, PersonCmpSalary, std::allocator<Person>>::iterator it3 =
      tester.s21_set_ten.begin();
  std::multiset<Person, PersonCmpSalary, std::allocator<Person>>::iterator it2 =
      tester.std_set_ten.begin();
  std::multiset<Person, PersonCmpSalary, std::allocator<Person>>::iterator it4 =
      tester.std_set_ten.begin();
  ASSERT_EQ(it1 == it3, it2 == it4);
}

TEST(Multiset, operation_not_equal) {
  TestPersonMultiset tester;
  s21::Multiset<Person, PersonCmpSalary, std::allocator<Person>>::iterator
      iter_1 = tester.s21_set_ten.begin();
  std::multiset<Person, PersonCmpSalary, std::allocator<Person>>::iterator
      iter_2 = tester.std_set_ten.begin();
  ASSERT_EQ(iter_1 != tester.s21_set_ten.end(),
            iter_2 != tester.std_set_ten.end());
}

TEST(Multiset, function_insert) {
  TestPersonMultiset tester;
  using s21_it =
      s21::Multiset<Person, PersonCmpSalary, std::allocator<Person>>::iterator;
  using std_it =
      std::multiset<Person, PersonCmpSalary, std::allocator<Person>>::iterator;
  s21_it iter_1 = tester.s21_set_ten.insert(tester.a);
  std_it iter_2 = tester.std_set_ten.insert(tester.a);
  EXPECT_EQ((*iter_1).getAge(), (*iter_2).getAge());
  EXPECT_EQ((*iter_1).getSal(), (*iter_2).getSal());
}

TEST(Multiset, function_find_have) {
  TestPersonMultiset tester;
  using s21_it =
      s21::Multiset<Person, PersonCmpSalary, std::allocator<Person>>::iterator;
  using std_it =
      std::multiset<Person, PersonCmpSalary, std::allocator<Person>>::iterator;
  s21_it i = tester.s21_set_ten.find(tester.a);
  std_it j = tester.std_set_ten.find(tester.a);
  EXPECT_EQ(i != tester.s21_set_ten.end(), j != tester.std_set_ten.end());
}

TEST(Multiset, function_find_dont_have) {
  TestPersonMultiset tester;
  using s21_it =
      s21::Multiset<Person, PersonCmpSalary, std::allocator<Person>>::iterator;
  using std_it =
      std::multiset<Person, PersonCmpSalary, std::allocator<Person>>::iterator;
  s21_it i = tester.s21_set_ten.find(tester.r);
  std_it j = tester.std_set_ten.find(tester.r);
  EXPECT_EQ(i != tester.s21_set_ten.end(), j != tester.std_set_ten.end());
}

TEST(Multiset, function_erase) {
  TestPersonMultiset tester;
  using s21_it =
      s21::Multiset<Person, PersonCmpSalary, std::allocator<Person>>::iterator;
  using std_it =
      std::multiset<Person, PersonCmpSalary, std::allocator<Person>>::iterator;
  tester.s21_set_ten.erase(tester.s21_set_ten.begin());
  tester.std_set_ten.erase(tester.std_set_ten.begin());
  s21_it iter_1 = tester.s21_set_ten.find(tester.a);
  std_it iter_2 = tester.std_set_ten.find(tester.a);
  ASSERT_EQ(iter_1 == tester.s21_set_ten.end(),
            iter_2 == tester.std_set_ten.end());
  TestSetInt tester_i;
  s21::Multiset<int>::iterator iter_3 = tester_i.s21_set_delete.find(75);
  std::multiset<int>::iterator iter_4 = tester_i.std_set_delete.find(75);
  tester_i.s21_set_delete.erase(iter_3);
  tester_i.std_set_delete.erase(iter_4);
  iter_3 = tester_i.s21_set_delete.find(75);
  iter_4 = tester_i.std_set_delete.find(75);
  ASSERT_EQ(iter_3 == tester_i.s21_set_delete.end(),
            iter_4 == tester_i.std_set_delete.end());
}

TEST(Multiset, functions_erase_alot) {
  TestPersonMultiset tester;
  using s21_it =
      s21::Multiset<Person, PersonCmpSalary, std::allocator<Person>>::iterator;
  using std_it =
      std::multiset<Person, PersonCmpSalary, std::allocator<Person>>::iterator;
  //  s21::Multiset<Person, PersonCmpSalary, std::allocator<Person>>
  //  s21_set_ten{a, b, c, d, e, f, g, i, k, a, m};
  s21_it it1 = tester.s21_set_ten.find(tester.a);
  std_it it2 = tester.std_set_ten.find(tester.a);
  tester.s21_set_ten.erase(it1);
  tester.std_set_ten.erase(it2);
  it1 = tester.s21_set_ten.find(tester.b);
  it2 = tester.std_set_ten.find(tester.b);
  tester.s21_set_ten.erase(it1);
  tester.std_set_ten.erase(it2);
  it1 = tester.s21_set_ten.find(tester.c);
  it2 = tester.std_set_ten.find(tester.c);
  tester.s21_set_ten.erase(it1);
  tester.std_set_ten.erase(it2);
  it1 = tester.s21_set_ten.find(tester.d);
  it2 = tester.std_set_ten.find(tester.d);
  tester.s21_set_ten.erase(it1);
  tester.std_set_ten.erase(it2);
  it1 = tester.s21_set_ten.find(tester.e);
  it2 = tester.std_set_ten.find(tester.e);
  tester.s21_set_ten.erase(it1);
  tester.std_set_ten.erase(it2);
  it1 = tester.s21_set_ten.find(tester.f);
  it2 = tester.std_set_ten.find(tester.f);
  tester.s21_set_ten.erase(it1);
  tester.std_set_ten.erase(it2);
  it1 = tester.s21_set_ten.find(tester.g);
  it2 = tester.std_set_ten.find(tester.g);
  tester.s21_set_ten.erase(it1);
  tester.std_set_ten.erase(it2);
  it1 = tester.s21_set_ten.find(tester.i);
  it2 = tester.std_set_ten.find(tester.i);
  tester.s21_set_ten.erase(it1);
  tester.std_set_ten.erase(it2);
  it1 = tester.s21_set_ten.find(tester.k);
  it2 = tester.std_set_ten.find(tester.k);
  tester.s21_set_ten.erase(it1);
  tester.std_set_ten.erase(it2);
  it1 = tester.s21_set_ten.find(tester.m);
  it2 = tester.std_set_ten.find(tester.m);
  tester.s21_set_ten.erase(it1);
  tester.std_set_ten.erase(it2);
  it1 = tester.s21_set_ten.find(tester.a);
  it2 = tester.std_set_ten.find(tester.a);
  tester.s21_set_ten.erase(it1);
  tester.std_set_ten.erase(it2);
  ASSERT_EQ(tester.s21_set_ten.size(), tester.std_set_ten.size());
}

TEST(Multiset, function_emplace) {
  TestPersonMultiset tester;
  // s21_set_merge{a, b, c, o, p, r};
  auto it1 =
      tester.s21_set_merge.emplace(tester.d, tester.d, tester.e, tester.f);
  EXPECT_EQ((*it1[0].first).getAge(), tester.d.getAge());
  EXPECT_EQ(it1[1].second, true);
  EXPECT_EQ((*it1[2].first).getAge(), tester.e.getAge());
  EXPECT_EQ((*it1[3].first).getAge(), tester.f.getAge());
}

TEST(Multiset, function_count) {
  TestPersonMultiset tester;
  ASSERT_EQ(tester.s21_set_ten.count(tester.a),
            tester.std_set_ten.count(tester.a));
  ASSERT_EQ(tester.s21_set_ten.count(tester.g),
            tester.std_set_ten.count(tester.g));
  ASSERT_EQ(tester.s21_set_ten.count(tester.r),
            tester.std_set_ten.count(tester.r));
}

TEST(Multiset, function_contains) {
  TestPersonMultiset tester;
  ASSERT_TRUE(tester.s21_set_ten.contains(tester.a));
  ASSERT_TRUE(tester.s21_set_ten.contains(tester.b));
  ASSERT_FALSE(tester.s21_set_ten.contains(tester.r));
}

//
// s21_set_empty;
// s21_set_ten{a, b, c, d, e, f, g, i, k, a, m};
// s21_set_copy;
// s21_move;
// s21_set_swap{m, n, o, p, r};
// s21_set_merge{a, b, c, o, p, r};
// s21_set_delete{b, c, d, g, i, k, a, p, b};

TEST(Multiset, function_lower_bound) {
  TestPersonMultiset tester;
  s21::Multiset<int> s1({1, 3, 7, 9, 5, 4, 2, 2, 5, 66, 345, 34, 345, 12, -1});
  std::multiset<int> s2({1, 3, 7, 9, 5, 4, 2, 2, 5, 66, 345, 34, 345, 12, -1});
  s21::Multiset<int>::iterator it1 = s1.lower_bound(2);
  std::multiset<int>::iterator it2 = s2.lower_bound(2);
  ASSERT_EQ(*it1, *it2);
  ++it1;
  ++it2;
  ASSERT_EQ(*it1, *it2);
  ++it1;
  ++it2;
  ASSERT_EQ(*it1, *it2);
  --it1;
  --it2;
  --it1;
  --it2;
  --it1;
  --it2;
  ASSERT_EQ(*it1, *it2);
}
TEST(Multiset, function_upper_bound) {
  s21::Multiset<int> s1({1, 3, 4, 2, 2, 2, 1, 1, 2, 2, 2, 2, 123,
                         1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1});
  std::multiset<int> s2({1, 3, 4, 2, 2, 2, 1, 1, 2, 2, 2, 2, 123,
                         1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1});
  s21::Multiset<int>::iterator it1 = s1.upper_bound(2);
  std::multiset<int>::iterator it2 = s2.upper_bound(2);
  ASSERT_EQ(*it1, *it2);
  ++it1;
  ++it2;
  ASSERT_EQ(*it1, *it2);
  --it1;
  --it2;
  --it1;
  --it2;
  ASSERT_EQ(*it1, *it2);
}

TEST(Multiset, function_equal_range) {
  s21::Multiset<int> s1({1, 3, 4, 2, 2, 2, 1, 1, 2, 2, 2, 2, 123,
                         1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1});
  std::multiset<int> s2({1, 3, 4, 2, 2, 2, 1, 1, 2, 2, 2, 2, 123,
                         1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1});
  auto it1 = s1.equal_range(2);
  auto i = it1.first;
  auto it2 = s2.equal_range(2);
  auto j = it2.first;
  while (i != it1.second && j != it2.second) {
    EXPECT_EQ(*i, *j);
    i++;
    j++;
  }
  it1 = s1.equal_range(1);
  i = it1.first;
  it2 = s2.equal_range(1);
  j = it2.first;
  while (i != it1.second && j != it2.second) {
    EXPECT_EQ(*i, *j);
    i++;
    j++;
  }
  it1 = s1.equal_range(213);
  it2 = s2.equal_range(213);
  EXPECT_EQ(it1.second == s1.end(), it2.second == s2.end());
  EXPECT_EQ(it1.first == s1.end(), it2.first == s2.end());
  EXPECT_EQ(s1.count(1), s2.count(1));
  EXPECT_EQ(s1.count(2), s2.count(2));
  EXPECT_EQ(s1.count(213), s2.count(213));
  i = s1.end();
  j = s2.end();
  --i;
  --j;
  while (i != s1.begin() && j != s2.begin()) {
    EXPECT_EQ(*i, *j);
    --i;
    --j;
  }
}
#endif  // CPP2_S21_CONTAINERS_1_SRC_TEST_MULTISET_TEST_H_
