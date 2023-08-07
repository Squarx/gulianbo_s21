//
// Created by Gulian Boris on 5/17/23.
//

#ifndef CPP2_S21_CONTAINERS_1_SRC_TEST_MAP_TEST_H_
#define CPP2_S21_CONTAINERS_1_SRC_TEST_MAP_TEST_H_
#include <map>

#include "../s21_containers.h"
class TestMapInt {
 public:
  s21::Map<int, int> s21_map_empty;
  s21::Map<int, int> s21_map_four{{1, 1},   {2, 2},   {3, 3},   {4, 4},
                                  {1, 100}, {2, 200}, {3, 300}, {3, 400}};
  s21::Map<int, int> s21_map_swap{{1, 95}, {2, 95}, {3, 95}};

  std::map<int, int> std_map_empty;
  std::map<int, int> std_map_four{{1, 1},   {2, 2},   {3, 3},   {4, 4},
                                  {1, 100}, {2, 200}, {3, 300}, {3, 400}};
  std::map<int, int> std_map_swap{{1, 95}, {2, 95}, {3, 95}};
};

TEST(Map, construcor_default) {
  TestMapInt tester;
  EXPECT_EQ(tester.s21_map_empty.size(), tester.std_map_empty.size());
  EXPECT_EQ(tester.s21_map_empty.empty(), tester.std_map_empty.empty());
}

TEST(Map, construcot_initializer) {
  TestMapInt tester;
  EXPECT_EQ(tester.s21_map_four.size(), tester.std_map_four.size());
  EXPECT_EQ(tester.std_map_four.empty(), tester.std_map_four.empty());
}
TEST(Map, constructor_copy_empty) {
  TestMapInt tester;
  s21::Map<int, int> s21_map_copy(tester.s21_map_empty);
  std::map<int, int> std_map_copy(tester.std_map_empty);
  EXPECT_EQ(s21_map_copy.size(), std_map_copy.size());
  EXPECT_EQ(std_map_copy.empty(), std_map_copy.empty());
}

TEST(Map, constructor_copy_not_empty) {
  TestMapInt tester;
  s21::Map<int, int> s21_map_copy(tester.s21_map_four);
  std::map<int, int> std_map_copy(tester.std_map_four);
  EXPECT_EQ(s21_map_copy.size(), std_map_copy.size());
  EXPECT_EQ(std_map_copy.empty(), std_map_copy.empty());
}

TEST(Map, constructor_move_empty) {
  TestMapInt tester;
  s21::Map<int, int> s21_map_move = std::move(tester.s21_map_empty);
  std::map<int, int> std_map_move = std::move(tester.std_map_empty);
  EXPECT_EQ(s21_map_move.size(), std_map_move.size());
  EXPECT_EQ(s21_map_move.empty(), std_map_move.empty());
}

TEST(Map, constructor_move_not_empty) {
  TestMapInt tester;
  s21::Map<int, int> s21_map_move = std::move(tester.s21_map_four);
  std::map<int, int> std_map_move = std::move(tester.std_map_four);
  EXPECT_EQ(s21_map_move.size(), std_map_move.size());
  EXPECT_EQ(s21_map_move.empty(), std_map_move.empty());
}

TEST(Map, operator_copy_empty) {
  TestMapInt tester;
  s21::Map<int, int> s21_map_copy;
  std::map<int, int> std_map_copy;
  s21_map_copy = tester.s21_map_four;
  std_map_copy = tester.std_map_four;
  EXPECT_EQ(s21_map_copy.size(), std_map_copy.size());
  EXPECT_EQ(s21_map_copy.empty(), std_map_copy.empty());
}

TEST(Map, operator_copy_not_empty) {
  TestMapInt tester;
  s21::Map<int, int> s21_map_copy{{1, 1}, {2, 2}};
  std::map<int, int> std_map_copy{{1, 1}, {2, 2}};
  s21_map_copy = tester.s21_map_four;
  std_map_copy = tester.std_map_four;
  EXPECT_EQ(s21_map_copy.size(), std_map_copy.size());
  EXPECT_EQ(s21_map_copy.empty(), std_map_copy.empty());
}

TEST(Map, operator_move_empty) {
  TestMapInt tester;
  s21::Map<int, int> s21_map_move;
  std::map<int, int> std_map_move;
  s21_map_move = std::move(tester.s21_map_four);
  std_map_move = std::move(tester.std_map_four);
  EXPECT_EQ(s21_map_move.size(), std_map_move.size());
  EXPECT_EQ(s21_map_move.empty(), std_map_move.empty());
}

TEST(Map, operator_move_not_empty) {
  TestMapInt tester;
  s21::Map<int, int> s21_map_move{{1, 1}, {2, 2}};
  std::map<int, int> std_map_move{{1, 1}, {2, 2}};
  s21_map_move = std::move(tester.s21_map_empty);
  std_map_move = std::move(tester.std_map_empty);
  EXPECT_EQ(s21_map_move.size(), std_map_move.size());
  EXPECT_EQ(s21_map_move.empty(), std_map_move.empty());
}

TEST(Map, function_empty_empty) {
  TestMapInt tester;
  EXPECT_EQ(tester.s21_map_empty.size(), tester.std_map_empty.size());
  EXPECT_EQ(tester.s21_map_empty.empty(), tester.std_map_empty.empty());
}

TEST(Map, function_empty_not_empty) {
  TestMapInt tester;
  EXPECT_EQ(tester.s21_map_four.size(), tester.std_map_four.size());
  EXPECT_EQ(tester.s21_map_four.empty(), tester.std_map_four.empty());
}

TEST(Map, function_size_empty) {
  TestMapInt tester;
  EXPECT_EQ(tester.s21_map_empty.size(), tester.std_map_empty.size());
  EXPECT_EQ(tester.s21_map_empty.empty(), tester.std_map_empty.empty());
}

TEST(Map, function_size_not_empty) {
  TestMapInt tester;
  EXPECT_EQ(tester.s21_map_four.size(), tester.std_map_four.size());
  EXPECT_EQ(tester.std_map_four.empty(), tester.std_map_four.empty());
}

TEST(Map, function_max_size_empty) {
  TestMapInt tester;
  EXPECT_EQ(tester.s21_map_empty.size(), tester.std_map_empty.size());
  EXPECT_EQ(tester.s21_map_empty.empty(), tester.std_map_empty.empty());
  EXPECT_EQ(tester.s21_map_empty.max_size(), tester.std_map_empty.max_size());
}

TEST(Map, function_swap_empty) {
  s21::Map<int, int> m1({{213, 123}, {123, 232324}, {124, 324124}});
  s21::Map<int, int> m2;
  m1.swap(m2);
  std::map<int, int> m3({{213, 123}, {123, 232324}, {124, 324124}});
  std::map<int, int> m4;
  m3.swap(m4);
  ASSERT_EQ(m1.size(), m3.size());
  ASSERT_EQ(m2.size(), m4.size());
}

TEST(Map, function_swap_not_empty) {
  TestMapInt tester;
  s21::Map<int, int> s21_map_swap{{213, 123}, {123, 232324}, {124, 324124}};
  std::map<int, int> std_map_swap{{213, 123}, {123, 232324}, {124, 324124}};
  s21_map_swap.swap(tester.s21_map_four);
  std_map_swap.swap(tester.std_map_four);
  EXPECT_EQ(s21_map_swap.size(), std_map_swap.size());
  EXPECT_EQ(s21_map_swap.empty(), std_map_swap.empty());
}
TEST(Map, WithDuplicatesCase) {
  s21::Map<int, int> m1({{1, 8},
                         {4, 2},
                         {2, 3},
                         {1, 8},
                         {4, 2},
                         {2, 3},
                         {1, 8},
                         {4, 2},
                         {2, 3},
                         {1, 8},
                         {4, 2},
                         {2, 3}});
  s21::Map<int, int> m2({{1, 3}, {2, 2}, {123, 123123}});
  m1.merge(m2);

  std::map<int, int> m3({{1, 8},
                         {4, 2},
                         {2, 3},
                         {1, 8},
                         {4, 2},
                         {2, 3},
                         {1, 8},
                         {4, 2},
                         {2, 3},
                         {1, 8},
                         {4, 2},
                         {2, 3}});
  std::map<int, int> m4({{1, 3}, {2, 2}, {123, 123123}});
  m3.merge(m4);

  ASSERT_EQ(m1.size(), m3.size());
  ASSERT_EQ(m2.size(), m4.size());
}

TEST(Map, WithoutDuplicatesCase) {
  s21::Map<int, int> m1({{1, 8},
                         {4, 2},
                         {2, 3},
                         {1, 8},
                         {4, 2},
                         {2, 3},
                         {1, 8},
                         {4, 2},
                         {2, 3},
                         {1, 8},
                         {4, 2},
                         {2, 3}});
  s21::Map<int, int> m2({{99, 99}, {228, 228}});
  m1.merge(m2);

  std::map<int, int> m3({{1, 8},
                         {4, 2},
                         {2, 3},
                         {1, 8},
                         {4, 2},
                         {2, 3},
                         {1, 8},
                         {4, 2},
                         {2, 3},
                         {1, 8},
                         {4, 2},
                         {2, 3}});
  std::map<int, int> m4({{99, 99}, {228, 228}});
  m3.merge(m4);

  ASSERT_EQ(m1.size(), m3.size());
  ASSERT_EQ(m2.size(), m4.size());
}

TEST(Map, function_clear_empty) {
  TestMapInt tester;
  tester.s21_map_empty.clear();
  tester.std_map_empty.clear();
  EXPECT_EQ(tester.s21_map_empty.size(), tester.std_map_empty.size());
  EXPECT_EQ(tester.s21_map_empty.empty(), tester.std_map_empty.empty());
}
TEST(Map, function_clear_not_empty) {
  TestMapInt tester;
  tester.s21_map_four.clear();
  tester.std_map_four.clear();
  EXPECT_EQ(tester.s21_map_four.size(), tester.std_map_four.size());
  EXPECT_EQ(tester.s21_map_four.empty(), tester.std_map_four.empty());
}

TEST(Map, function_begin_empty) {
  TestMapInt tester;
  using s21_it = s21::Map<int, int>::iterator;
  using std_it = std::map<int, int>::iterator;

  s21_it iter_1 = tester.s21_map_empty.begin();
  std_it iter_2 = tester.std_map_empty.begin();

  EXPECT_EQ(iter_1 == tester.s21_map_empty.end(),
            iter_2 == tester.std_map_empty.end());
}
TEST(Map, function_begin_not_empty) {
  TestMapInt tester;
  using s21_it = s21::Map<int, int>::iterator;
  using std_it = std::map<int, int>::iterator;
  s21_it iter_1 = tester.s21_map_four.begin();
  std_it iter_2 = tester.std_map_four.begin();
  EXPECT_EQ(iter_1 != tester.s21_map_four.end(),
            iter_2 != tester.std_map_four.end());
  EXPECT_EQ((*iter_1).second, (*iter_2).second);
}

TEST(Map, const_begin_empty) {
  TestMapInt tester;
  s21::Map<int, int>::const_iterator iter_1 = tester.s21_map_empty.begin();
  std::map<int, int>::const_iterator iter_2 = tester.std_map_empty.begin();
  EXPECT_EQ(tester.s21_map_empty.size(), tester.std_map_empty.size());
  EXPECT_EQ(tester.s21_map_empty.empty(), tester.std_map_empty.empty());
  EXPECT_EQ(iter_1 == tester.s21_map_empty.end(),
            iter_2 == tester.std_map_empty.end());
}
TEST(Map, const_begin_not_empty) {
  TestMapInt tester;
  s21::Map<int, int>::const_iterator iter_1 = tester.s21_map_four.begin();
  std::map<int, int>::const_iterator iter_2 = tester.std_map_four.begin();
  EXPECT_EQ(tester.s21_map_four.size(), tester.std_map_four.size());
  EXPECT_EQ(tester.s21_map_four.empty(), tester.std_map_four.empty());
  EXPECT_EQ(iter_1 != tester.s21_map_four.end(),
            iter_2 != tester.std_map_four.end());
  EXPECT_EQ((*iter_1).second, (*iter_2).second);
}
TEST(Map, operator_plus) {
  TestMapInt tester;
  s21::Map<int, int>::iterator iter_1 = tester.s21_map_four.begin();
  std::map<int, int>::iterator iter_2 = tester.std_map_four.begin();
  EXPECT_EQ((*iter_1).second, (*iter_2).second);
  ++iter_1;
  ++iter_2;
  EXPECT_EQ((*iter_1).second, (*iter_2).second);
  ++iter_1;
  ++iter_2;
  EXPECT_EQ((*iter_1).second, (*iter_2).second);
}
TEST(Map, operator_minus) {
  TestMapInt tester;
  s21::Map<int, int>::iterator iter_1 = tester.s21_map_four.begin();
  std::map<int, int>::iterator iter_2 = tester.std_map_four.begin();
  ++iter_1;
  ++iter_2;
  EXPECT_EQ((*iter_1).second, (*iter_2).second);
  --iter_1;
  --iter_2;
  EXPECT_EQ((*iter_1).second, (*iter_2).second);
}

TEST(Map, operator_assignment) {
  TestMapInt tester;
  s21::Map<int, int>::iterator iter_1 = tester.s21_map_four.begin();
  s21::Map<int, int>::iterator iter_3 = iter_1;
  std::map<int, int>::iterator iter_2 = tester.std_map_four.begin();
  std::map<int, int>::iterator iter_4 = iter_2;
  EXPECT_EQ(tester.s21_map_four.size(), tester.std_map_four.size());
  EXPECT_EQ(tester.s21_map_four.empty(), tester.std_map_four.empty());
  EXPECT_EQ((*iter_1).second, (*iter_3).second);
  EXPECT_EQ((*iter_2).second, (*iter_4).second);
}
TEST(Map, operator_equal) {
  TestMapInt tester;
  s21::Map<int, int>::iterator iter_1 = tester.s21_map_four.begin();
  s21::Map<int, int>::iterator iter_3 = tester.s21_map_four.begin();
  std::map<int, int>::iterator iter_2 = tester.std_map_empty.begin();
  std::map<int, int>::iterator iter_4 = tester.std_map_empty.begin();
  EXPECT_EQ(tester.s21_map_four.size(), tester.std_map_four.size());
  EXPECT_EQ(tester.s21_map_four.empty(), tester.std_map_four.empty());
  EXPECT_EQ(tester.s21_map_empty.size(), tester.std_map_empty.size());
  EXPECT_EQ(tester.s21_map_empty.empty(), tester.std_map_empty.empty());
  EXPECT_EQ(iter_1 == iter_3, iter_2 == iter_4);
}
TEST(Map, operatort_not_equal) {
  TestMapInt tester;
  s21::Map<int, int>::iterator iter_1 = tester.s21_map_four.begin();
  std::map<int, int>::iterator iter_2 = tester.std_map_four.begin();
  EXPECT_EQ(iter_1 != tester.s21_map_four.end(),
            iter_2 != tester.std_map_empty.end());
}
TEST(Map, const_operator_plus) {
  TestMapInt tester;
  s21::Map<int, int>::const_iterator iter_1 = tester.s21_map_four.begin();
  std::map<int, int>::const_iterator iter_2 = tester.std_map_four.begin();
  EXPECT_EQ((*iter_1).second, (*iter_2).second);
  ++iter_1;
  ++iter_2;
  EXPECT_EQ((*iter_1).second, (*iter_2).second);
  ++iter_1;
  ++iter_2;
  EXPECT_EQ((*iter_1).second, (*iter_2).second);
}
TEST(Map, const_operator_minus) {
  TestMapInt tester;
  s21::Map<int, int>::const_iterator iter_1 = tester.s21_map_four.begin();
  std::map<int, int>::const_iterator iter_2 = tester.std_map_four.begin();
  ++iter_1;
  ++iter_2;
  EXPECT_EQ((*iter_1).second, (*iter_2).second);
  --iter_1;
  --iter_2;
  EXPECT_EQ((*iter_1).second, (*iter_2).second);
}

TEST(Map, const_operator_assignment) {
  TestMapInt tester;
  s21::Map<int, int>::const_iterator iter_1 = tester.s21_map_four.begin();
  s21::Map<int, int>::const_iterator iter_3 = iter_1;
  std::map<int, int>::const_iterator iter_2 = tester.std_map_four.begin();
  std::map<int, int>::const_iterator iter_4 = iter_2;
  EXPECT_EQ(tester.s21_map_four.size(), tester.std_map_four.size());
  EXPECT_EQ(tester.s21_map_four.empty(), tester.std_map_four.empty());
  EXPECT_EQ((*iter_1).second, (*iter_3).second);
  EXPECT_EQ((*iter_2).second, (*iter_4).second);
}
TEST(Map, const_operator_equal) {
  TestMapInt tester;
  s21::Map<int, int>::const_iterator iter_1 = tester.s21_map_four.begin();
  s21::Map<int, int>::const_iterator iter_3 = tester.s21_map_four.begin();
  std::map<int, int>::const_iterator iter_2 = tester.std_map_empty.begin();
  std::map<int, int>::const_iterator iter_4 = tester.std_map_empty.begin();
  EXPECT_EQ(tester.s21_map_four.size(), tester.std_map_four.size());
  EXPECT_EQ(tester.s21_map_four.empty(), tester.std_map_four.empty());
  EXPECT_EQ(tester.s21_map_empty.size(), tester.std_map_empty.size());
  EXPECT_EQ(tester.s21_map_empty.empty(), tester.std_map_empty.empty());
  EXPECT_EQ(iter_1 == iter_3, iter_2 == iter_4);
}
TEST(Map, const_operatort_not_equal) {
  TestMapInt tester;
  s21::Map<int, int>::const_iterator iter_1 = tester.s21_map_four.begin();
  std::map<int, int>::iterator iter_2 = tester.std_map_four.begin();
  EXPECT_EQ(iter_1 != tester.s21_map_four.end(),
            iter_2 != tester.std_map_empty.end());
}

TEST(Map, const_operator_square_brackets) {
  TestMapInt tester;
  //  std::map<int, int> std_map_swap{{1, 95}, {2, 95}, {3, 95}};
  EXPECT_EQ(tester.s21_map_swap[1], tester.std_map_swap[1]);
  EXPECT_EQ(tester.s21_map_swap[2], tester.std_map_swap[2]);
  EXPECT_EQ(tester.s21_map_swap[3], tester.std_map_swap[3]);
  tester.s21_map_swap[4] = 69;
  tester.std_map_swap[4] = 69;
  EXPECT_EQ(tester.s21_map_swap[4], tester.std_map_swap[4]);
  EXPECT_EQ(tester.s21_map_swap.size(), tester.std_map_swap.size());
  tester.s21_map_swap[4] = 699;
  tester.std_map_swap[4] = 699;
  EXPECT_EQ(tester.s21_map_swap[4], tester.std_map_swap[4]);
  EXPECT_EQ(tester.s21_map_swap.size(), tester.std_map_swap.size());
}
TEST(Map, function_insert_without_duplicate) {
  TestMapInt tester;
  std::pair<s21::Map<int, int>::iterator, bool> iter_1 =
      tester.s21_map_four.insert({5, 2});
  std::pair<std::map<int, int>::iterator, bool> iter_2 =
      tester.std_map_four.insert({5, 2});
  EXPECT_EQ((*(iter_1.first)).second, (*(iter_2.first)).second);
  EXPECT_TRUE(iter_1.second == iter_2.second);
}

TEST(Map, function_insert_with_duplicate) {
  TestMapInt tester;
  std::pair<s21::Map<int, int>::iterator, bool> iter_1 =
      tester.s21_map_four.insert({1, 2});
  std::pair<std::map<int, int>::iterator, bool> iter_2 =
      tester.std_map_four.insert({1, 2});
  EXPECT_TRUE(iter_1.second == iter_2.second);
}

TEST(Map, function_insert_key_value_without_duplicate) {
  TestMapInt tester;
  std::pair<s21::Map<int, int>::iterator, bool> iter_1 =
      tester.s21_map_four.insert(7, 7);
  std::pair<std::map<int, int>::iterator, bool> iter_2 =
      tester.std_map_four.insert({7, 7});
  EXPECT_EQ(tester.s21_map_four.size(), tester.std_map_four.size());
  EXPECT_EQ(tester.s21_map_four.empty(), tester.std_map_four.empty());
  EXPECT_EQ((*(iter_1.first)).second, (*(iter_2.first)).second);
  EXPECT_TRUE(iter_1.second == iter_2.second);
}

TEST(Map, function_insert_key_value_with_duplicate) {
  TestMapInt tester;
  std::pair<s21::Map<int, int>::iterator, bool> iter_1 =
      tester.s21_map_four.insert(1, 7);
  std::pair<std::map<int, int>::iterator, bool> iter_2 =
      tester.std_map_four.insert({1, 7});
  EXPECT_EQ(tester.s21_map_four.size(), tester.std_map_four.size());
  EXPECT_EQ(tester.s21_map_four.empty(), tester.std_map_four.empty());
  EXPECT_TRUE(iter_1.second == iter_2.second);
}
TEST(Map, function_insert_or_assign_value) {
  s21::Map<int, int> m1({{1, 3}, {4, 2}});
  std::map<int, int> m2({{1, 3}, {4, 2}});
  std::pair<s21::Map<int, int>::iterator, bool> it1 = m1.insert_or_assign(5, 2);
  std::pair<std::map<int, int>::iterator, bool> it2 = m2.insert_or_assign(5, 2);
  ASSERT_TRUE(it1.second == it2.second);
}

TEST(Map, function_insert_or_assign) {
  s21::Map<int, int> m1({{1, 3}, {4, 2}});
  std::map<int, int> m2({{1, 3}, {4, 2}});
  std::pair<s21::Map<int, int>::iterator, bool> it1 = m1.insert_or_assign(1, 2);
  std::pair<std::map<int, int>::iterator, bool> it2 = m2.insert_or_assign(1, 2);
  ASSERT_EQ((*(it1.first)).second, (*(it2.first)).second);
  ASSERT_TRUE(it1.second == it2.second);
}
TEST(Map, function_insert_s) {
  s21::Map<int, int> m1({{1, 3}, {4, 2}});
  std::pair<s21::Map<int, int>::iterator, bool> it1 = m1.insert(5, 2);
  ASSERT_EQ((*(it1.first)).second, 2);
  ASSERT_TRUE(it1.second);
}

TEST(Map, function_at) {
  s21::Map<int, int> m1({{1, 3}, {4, 2}});
  std::map<int, int> m2({{1, 3}, {4, 2}});
  ASSERT_EQ(m1.at(1), m2.at(1));
  EXPECT_THROW(m1.at(100), std::exception);
  EXPECT_THROW(m2.at(100), std::exception);
}
TEST(Map, function_erase) {
  s21::Map<int, int> m1({{1, 3}, {4, 2}});
  std::map<int, int> m2({{1, 3}, {4, 2}});
  m1.erase(m1.begin());
  m2.erase(m2.begin());
  ASSERT_EQ(m1[1], m2[1]);
}
TEST(Map, function_Emplace) {
  s21::Map<int, int> s1({{1, 3}, {4, 2}});
  auto it1 = s1.emplace(std::pair<int, int>(5, 5), std::pair<int, int>(51, 53));
  ASSERT_EQ((*it1[0].first).second, 5);
  ASSERT_EQ((*it1[1].first).second, 53);
}
TEST(Map, function_contains) {
  s21::Map<int, int> s1({{1, 3}, {4, 2}});
  ASSERT_TRUE(s1.contains(1));
  ASSERT_TRUE(s1.contains(4));
  ASSERT_FALSE(s1.contains(3));
}
#endif  // CPP2_S21_CONTAINERS_1_SRC_TEST_MAP_TEST_H_
