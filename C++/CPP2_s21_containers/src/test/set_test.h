//
// Created by Gulian Boris on 5/16/23.
//

#ifndef CPP2_S21_CONTAINERS_1_SRC_TEST_SET_TEST_H_
#define CPP2_S21_CONTAINERS_1_SRC_TEST_SET_TEST_H_
#include <iostream>
#include <set>

#include "../s21_containers.h"
class TestSetInt {
 public:
  s21::Set<int> s21_set_empty;
  s21::Set<int> s21_set_ten{1, 2, 56, 76, 123, 56, 78, 56, 21, 100};
  s21::Set<int> s21_set_copy;
  s21::Set<int> s21_move;
  s21::Set<int> s21_set_swap{95, 94, 93, 92};
  s21::Set<int> s21_set_merge{1, 2, 3, 4, 5};
  s21::Set<int> s21_set_delete{50, 10, 75, 5, 12, 15};

  std::set<int> std_set_empty;
  std::set<int> std_set_ten{1, 2, 56, 76, 123, 56, 78, 56, 21, 100};
  std::set<int> std_set_copy;
  std::set<int> std_move;
  std::set<int> std_set_swap{95, 94, 93, 92};
  std::set<int> std_set_merge{1, 2, 3, 4, 5};
  std::set<int> std_set_delete{50, 10, 75, 5, 12, 15};
};

class Person {
 private:
  int age_;
  int salary_;
  std::string name_;

 public:
  Person() : age_(0), salary_(0), name_("") {}
  Person(int age, int salary, std::string name)
      : age_(age), salary_(salary), name_(name) {}
  ~Person() = default;
  int getAge() const { return age_; }
  int getSal() const { return salary_; }
  std::string getName() { return name_; }
  bool operator==(const Person& o) const {
    return (age_ == o.age_) && (salary_ == o.salary_) && (name_ == o.name_);
  }
  bool operator!=(const Person& o) const { return !operator==(o); }
  friend std::ostream& operator<<(std::ostream& os, const Person& p) {
    os << "Name: " << p.name_ << " Salary: " << p.salary_ << " Age: " << p.age_;
    return os;
  }
};

class PersonCmpAge {
 public:
  bool operator()(const Person& lhs, const Person& rhs) const {
    return lhs.getAge() < rhs.getAge();
  }
};

class PersonCmpSalary {
 public:
  bool operator()(const Person& lhs, const Person& rhs) const {
    return lhs.getSal() < rhs.getSal();
  }
};

class TestPerson {
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
  s21::Set<Person, PersonCmpSalary, std::allocator<Person>> s21_set_empty;
  s21::Set<Person, PersonCmpSalary, std::allocator<Person>> s21_set_ten{
      a, b, c, d, e, f, g, i, k, a, m};
  s21::Set<Person, PersonCmpSalary, std::allocator<Person>> s21_set_copy;
  s21::Set<Person, PersonCmpSalary, std::allocator<Person>> s21_move;
  s21::Set<Person, PersonCmpSalary, std::allocator<Person>> s21_set_swap{
      m, n, o, p, r};
  s21::Set<Person, PersonCmpSalary, std::allocator<Person>> s21_set_merge{
      a, b, c, o, p, r};
  s21::Set<Person, PersonCmpSalary, std::allocator<Person>> s21_set_delete{
      b, c, d, g, i, k, a, p, b};

  std::set<Person, PersonCmpSalary, std::allocator<Person>> std_set_empty;
  std::set<Person, PersonCmpSalary, std::allocator<Person>> std_set_ten{
      a, b, c, d, e, f, g, i, k, a, m};
  std::set<Person, PersonCmpSalary, std::allocator<Person>> std_set_copy;
  std::set<Person, PersonCmpSalary, std::allocator<Person>> std_move;
  std::set<Person, PersonCmpSalary, std::allocator<Person>> std_set_swap{
      m, n, o, p, r};
  std::set<Person, PersonCmpSalary, std::allocator<Person>> std_set_merge{
      a, b, c, o, p, r};
  std::set<Person, PersonCmpSalary, std::allocator<Person>> std_set_delete{
      b, c, d, g, i, k, a, p, b};
};

TEST(Set, constructor_default) {
  TestPerson tester;
  EXPECT_EQ(tester.s21_set_empty.size(), tester.std_set_empty.size());
  EXPECT_EQ(tester.s21_set_empty.empty(), tester.std_set_empty.empty());
}

TEST(Set, initializer_list) {
  TestPerson tester;
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

TEST(Set, constructor_copy) {
  TestPerson tester;
  s21::Set<Person, PersonCmpSalary, std::allocator<Person>> s21_empty(
      tester.s21_set_ten);
  std::set<Person, PersonCmpSalary, std::allocator<Person>> std_empty(
      tester.std_set_ten);
  EXPECT_EQ(s21_empty.size(), tester.s21_set_ten.size());
  EXPECT_EQ(s21_empty.empty(), std_empty.empty());
}

TEST(Set, operator_move) {
  //  s21_set_ten{a, b, c, d, e, f, g, i, k, a, m};
  TestPerson tester;
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

TEST(Set, operator_copy) {
  TestPerson tester;
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

TEST(Set, function_not_empty) {
  TestPerson tester_p;
  EXPECT_EQ(tester_p.s21_set_ten.size(), tester_p.std_set_ten.size());
  EXPECT_EQ(tester_p.s21_set_ten.empty(), tester_p.std_set_ten.empty());
  EXPECT_EQ(tester_p.s21_set_empty.size(), tester_p.std_set_empty.size());
  EXPECT_EQ(tester_p.s21_set_empty.empty(), tester_p.std_set_empty.empty());
  EXPECT_EQ(tester_p.s21_set_empty.size(), tester_p.std_set_empty.size());
}
TEST(Set, function_max_size) {
  TestSetInt tester_i;
  EXPECT_EQ(tester_i.s21_set_empty.max_size(),
            tester_i.std_set_empty.max_size());
  EXPECT_EQ(tester_i.s21_set_ten.max_size(), tester_i.std_set_ten.max_size());
  s21::Set<float> s21_float_empty;
  std::set<float> std_float_empty;
  EXPECT_EQ(s21_float_empty.max_size(), std_float_empty.max_size());
}

TEST(Set, function_swap_not_empty) {
  //  s21_set_ten{a, b, c, d, e, f, g, i, k, a, m};
  TestPerson tester;
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

TEST(Set, function_swap_empty) {
  TestPerson tester;
  tester.s21_set_swap.swap(tester.s21_set_copy);
  tester.std_set_swap.swap(tester.std_set_copy);
  EXPECT_EQ(tester.s21_set_swap.find(tester.a) == tester.s21_set_swap.end(),
            tester.std_set_swap.find(tester.a) == tester.std_set_swap.end());
  EXPECT_EQ(tester.s21_set_swap.size(), tester.std_set_swap.size());
  EXPECT_EQ(tester.s21_set_ten.size(), tester.std_set_ten.size());
}

TEST(Set, function_merge) {
  //  s21_set_ten{a, b, c, d, e, f, g, i, k, a, m};
  // s21_set_merge{a, b, c, o, p, r};
  TestPerson tester;
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

TEST(Set, function_clear_not_empty) {
  TestPerson tester;
  tester.s21_set_ten.clear();
  tester.std_set_ten.clear();
  EXPECT_EQ(tester.s21_set_ten.size(), tester.std_set_ten.size());
  EXPECT_EQ(tester.s21_set_ten.empty(), tester.std_set_ten.empty());
}

TEST(Set, function_clear_empty) {
  TestPerson tester;
  tester.s21_set_empty.clear();
  tester.std_set_empty.clear();
  EXPECT_EQ(tester.s21_set_empty.size(), tester.std_set_empty.size());
  EXPECT_EQ(tester.std_set_empty.empty(), tester.std_set_empty.empty());
}

TEST(Set, function_begin_not_empty) {
  TestPerson tester;
  s21::Set<Person, PersonCmpSalary, std::allocator<Person>>::iterator i =
      tester.s21_set_ten.begin();
  std::set<Person, PersonCmpSalary, std::allocator<Person>>::iterator j =
      tester.std_set_ten.begin();
  EXPECT_EQ((*i).getAge(), (*j).getAge());
}

TEST(Set, function_begin_empty) {
  TestPerson tester;
  s21::Set<Person, PersonCmpSalary, std::allocator<Person>>::iterator i =
      tester.s21_set_empty.begin();
  std::set<Person, PersonCmpSalary, std::allocator<Person>>::iterator j =
      tester.std_set_empty.begin();
  EXPECT_EQ((*i).getAge(), (*j).getAge());
  EXPECT_EQ((*i).getSal(), (*j).getSal());
}

TEST(Set, function_const_begin_not_empty) {
  TestPerson tester;
  s21::Set<Person, PersonCmpSalary, std::allocator<Person>>::const_iterator i =
      tester.s21_set_ten.begin();
  std::set<Person, PersonCmpSalary, std::allocator<Person>>::const_iterator j =
      tester.std_set_ten.begin();
  EXPECT_EQ((*i).getAge(), (*j).getAge());
  EXPECT_EQ((*i).getSal(), (*j).getSal());
}

TEST(Set, function_const_begin_empty) {
  TestPerson tester;
  s21::Set<Person, PersonCmpSalary, std::allocator<Person>>::const_iterator i =
      tester.s21_set_empty.begin();
  std::set<Person, PersonCmpSalary, std::allocator<Person>>::const_iterator j =
      tester.std_set_empty.begin();
  EXPECT_EQ((*i).getSal(), (*j).getSal());
  EXPECT_EQ((*i).getAge(), (*j).getAge());
}

TEST(Set, function_end_not_empty) {
  TestPerson tester;
  s21::Set<Person, PersonCmpSalary, std::allocator<Person>>::const_iterator i =
      tester.s21_set_ten.end();
  std::set<Person, PersonCmpSalary, std::allocator<Person>>::const_iterator j =
      tester.std_set_ten.end();
  --i;
  --j;
  EXPECT_EQ((*i).getSal(), (*j).getSal());
  EXPECT_EQ((*i).getAge(), (*j).getAge());
}

TEST(Set, function_end_empty) {
  TestPerson tester;
  s21::Set<Person, PersonCmpSalary, std::allocator<Person>>::const_iterator i =
      tester.s21_set_empty.end();
  std::set<Person, PersonCmpSalary, std::allocator<Person>>::const_iterator j =
      tester.std_set_empty.end();
  EXPECT_EQ((*i).getSal(), (*j).getSal());
  EXPECT_EQ((*i).getAge(), (*j).getAge());
}

TEST(Set, function_const_end_not_empty) {
  TestPerson tester;
  s21::Set<Person, PersonCmpSalary, std::allocator<Person>>::const_iterator i =
      tester.s21_set_ten.end();
  std::set<Person, PersonCmpSalary, std::allocator<Person>>::const_iterator j =
      tester.std_set_ten.end();
  --i;
  --j;
  EXPECT_EQ((*i).getSal(), (*j).getSal());
  EXPECT_EQ((*i).getAge(), (*j).getAge());
}

TEST(Set, function_const_end_empty) {
  TestPerson tester;
  s21::Set<Person, PersonCmpSalary, std::allocator<Person>>::const_iterator i =
      tester.s21_set_empty.end();
  std::set<Person, PersonCmpSalary, std::allocator<Person>>::const_iterator j =
      tester.std_set_empty.end();
  EXPECT_EQ((*i).getSal(), (*j).getSal());
  EXPECT_EQ((*i).getAge(), (*j).getAge());
}

TEST(Set, operator_plus) {
  TestPerson tester;
  s21::Set<Person, PersonCmpSalary, std::allocator<Person>>::iterator i =
      tester.s21_set_ten.begin();
  std::set<Person, PersonCmpSalary, std::allocator<Person>>::iterator j =
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

TEST(Set, operator_plus_int) {
  TestPerson tester;
  s21::Set<Person, PersonCmpSalary, std::allocator<Person>>::iterator i =
      tester.s21_set_ten.begin();
  std::set<Person, PersonCmpSalary, std::allocator<Person>>::iterator j =
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

TEST(Set, operation_assignment) {
  TestPerson tester;
  s21::Set<Person, PersonCmpSalary, std::allocator<Person>>::iterator iter_1 =
      tester.s21_set_ten.begin();
  s21::Set<Person, PersonCmpSalary, std::allocator<Person>>::iterator iter_3 =
      iter_1;
  std::set<Person, PersonCmpSalary, std::allocator<Person>>::iterator iter_2 =
      tester.std_set_ten.begin();
  std::set<Person, PersonCmpSalary, std::allocator<Person>>::iterator iter_4 =
      iter_2;
  EXPECT_EQ((*iter_1).getSal(), (*iter_3).getSal());
  EXPECT_EQ((*iter_1).getAge(), (*iter_3).getAge());
  EXPECT_EQ((*iter_2).getSal(), (*iter_4).getSal());
  EXPECT_EQ((*iter_2).getAge(), (*iter_4).getAge());
}

TEST(Set, operation_equal) {
  TestPerson tester;
  s21::Set<Person, PersonCmpSalary, std::allocator<Person>>::iterator it1 =
      tester.s21_set_ten.begin();
  s21::Set<Person, PersonCmpSalary, std::allocator<Person>>::iterator it3 =
      tester.s21_set_ten.begin();
  std::set<Person, PersonCmpSalary, std::allocator<Person>>::iterator it2 =
      tester.std_set_ten.begin();
  std::set<Person, PersonCmpSalary, std::allocator<Person>>::iterator it4 =
      tester.std_set_ten.begin();
  ASSERT_EQ(it1 == it3, it2 == it4);
}

TEST(Set, operation_not_equal) {
  TestPerson tester;
  s21::Set<Person, PersonCmpSalary, std::allocator<Person>>::iterator iter_1 =
      tester.s21_set_ten.begin();
  std::set<Person, PersonCmpSalary, std::allocator<Person>>::iterator iter_2 =
      tester.std_set_ten.begin();
  ASSERT_EQ(iter_1 != tester.s21_set_ten.end(),
            iter_2 != tester.std_set_ten.end());
}

TEST(Set, function_insert) {
  TestPerson tester;
  using s21_it =
      s21::Set<Person, PersonCmpSalary, std::allocator<Person>>::iterator;
  using std_it =
      std::set<Person, PersonCmpSalary, std::allocator<Person>>::iterator;
  std::pair<s21_it, bool> iter_1 = tester.s21_set_ten.insert(tester.a);
  std::pair<std_it, bool> iter_2 = tester.std_set_ten.insert(tester.a);
  EXPECT_EQ((iter_1.second), (iter_2.second));
  EXPECT_EQ((*(iter_1.first)).getAge(), (*(iter_2.first)).getAge());

  std::pair<s21_it, bool> iter_3 = tester.s21_set_ten.insert(tester.r);
  std::pair<std_it, bool> iter_4 = tester.std_set_ten.insert(tester.r);
  EXPECT_EQ((iter_3.second), (iter_4.second));
  EXPECT_EQ((*(iter_3.first)).getAge(), (*(iter_4.first)).getAge());
}

TEST(Set, function_find_have) {
  TestPerson tester;
  using s21_it =
      s21::Set<Person, PersonCmpSalary, std::allocator<Person>>::iterator;
  using std_it =
      std::set<Person, PersonCmpSalary, std::allocator<Person>>::iterator;
  s21_it i = tester.s21_set_ten.find(tester.a);
  std_it j = tester.std_set_ten.find(tester.a);
  EXPECT_EQ(i != tester.s21_set_ten.end(), j != tester.std_set_ten.end());
}

TEST(Set, function_find_dont_have) {
  TestPerson tester;
  using s21_it =
      s21::Set<Person, PersonCmpSalary, std::allocator<Person>>::iterator;
  using std_it =
      std::set<Person, PersonCmpSalary, std::allocator<Person>>::iterator;
  s21_it i = tester.s21_set_ten.find(tester.r);
  std_it j = tester.std_set_ten.find(tester.r);
  EXPECT_EQ(i != tester.s21_set_ten.end(), j != tester.std_set_ten.end());
}

TEST(Set, function_erase) {
  TestPerson tester;
  using s21_it =
      s21::Set<Person, PersonCmpSalary, std::allocator<Person>>::iterator;
  using std_it =
      std::set<Person, PersonCmpSalary, std::allocator<Person>>::iterator;
  tester.s21_set_ten.erase(tester.s21_set_ten.begin());
  tester.std_set_ten.erase(tester.std_set_ten.begin());
  s21_it iter_1 = tester.s21_set_ten.find(tester.a);
  std_it iter_2 = tester.std_set_ten.find(tester.a);
  ASSERT_EQ(iter_1 == tester.s21_set_ten.end(),
            iter_2 == tester.std_set_ten.end());
  TestSetInt tester_i;
  s21::Set<int>::iterator iter_3 = tester_i.s21_set_delete.find(75);
  std::set<int>::iterator iter_4 = tester_i.std_set_delete.find(75);
  tester_i.s21_set_delete.erase(iter_3);
  tester_i.std_set_delete.erase(iter_4);
  iter_3 = tester_i.s21_set_delete.find(75);
  iter_4 = tester_i.std_set_delete.find(75);
  ASSERT_EQ(iter_3 == tester_i.s21_set_delete.end(),
            iter_4 == tester_i.std_set_delete.end());
}

TEST(Set, functions_erase_alot) {
  TestPerson tester;
  using s21_it =
      s21::Set<Person, PersonCmpSalary, std::allocator<Person>>::iterator;
  using std_it =
      std::set<Person, PersonCmpSalary, std::allocator<Person>>::iterator;
  //  s21::Set<Person, PersonCmpSalary, std::allocator<Person>> s21_set_ten{a,
  //  b, c, d, e, f, g, i, k, a, m};
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
  // it2 = tester.std_set_ten.find(tester.a);
  tester.s21_set_ten.erase(it1);
  // tester.std_set_ten.erase(it2); ?????????????? бесконченый цикл в стандарте
  ASSERT_EQ(tester.s21_set_ten.size(), tester.std_set_ten.size());
}

TEST(Set, function_erase_int) {
  TestSetInt tester;
  tester.s21_set_ten.erase(tester.s21_set_ten.begin());
  tester.std_set_ten.erase(tester.std_set_ten.begin());
  s21::Set<int>::iterator iter_1 = tester.s21_set_ten.find(1);
  std::set<int>::iterator iter_2 = tester.std_set_ten.find(1);
  ASSERT_EQ(iter_1 == tester.s21_set_ten.end(),
            iter_2 == tester.std_set_ten.end());

  s21::Set<int>::iterator iter_3 = tester.s21_set_delete.find(75);
  std::set<int>::iterator iter_4 = tester.std_set_delete.find(75);
  tester.s21_set_delete.erase(iter_3);
  tester.std_set_delete.erase(iter_4);
  iter_3 = tester.s21_set_delete.find(75);
  iter_4 = tester.std_set_delete.find(75);
  ASSERT_EQ(iter_3 == tester.s21_set_delete.end(),
            iter_4 == tester.std_set_delete.end());
}

TEST(Set, function_emplace) {
  TestPerson tester;
  // s21_set_merge{a, b, c, o, p, r};
  auto it1 =
      tester.s21_set_merge.emplace(tester.d, tester.d, tester.e, tester.f);

  EXPECT_EQ((*it1[0].first).getAge(), tester.d.getAge());
  EXPECT_EQ(it1[1].second, false);
  EXPECT_EQ((*it1[2].first).getAge(), tester.e.getAge());
  EXPECT_EQ((*it1[3].first).getAge(), tester.f.getAge());
}
#endif  // CPP2_S21_CONTAINERS_1_SRC_TEST_SET_TEST_H_
