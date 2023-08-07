#include <gtest/gtest.h>

#include <list>

#include "../s21_containers.h"

class ListTest {
 public:
  s21::List<int> s21_list_null;
  std::list<int> std_list_null;

  s21::List<int> s21_list_sort{12, 1, 5,   4,  3,  10, 22, 4, 8,
                               13, 0, 100, 28, 34, 3,  5,  6};
  std::list<int> std_list_sort{12, 1, 5,   4,  3,  10, 22, 4, 8,
                               13, 0, 100, 28, 34, 3,  5,  6};

  s21::List<int> s21_list_merge{-12, -1,  -5,   -4,  -3,  -10, -22, -4,
                                -8,  -13, -100, -28, -34, -3,  -5,  -6};
  std::list<int> std_list_merge{-12, -1,  -5,   -4,  -3,  -10, -22, -4,
                                -8,  -13, -100, -28, -34, -3,  -5,  -6};

  s21::List<int> s21_list_reverse{1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::list<int> std_list_reverse{1, 2, 3, 4, 5, 6, 7, 8, 9};

  s21::List<int> s21_list_unic{0, 1, 2, 3, 4, 2, 5, 6, 4, 4, 6, 6, 7, 7};
  std::list<int> std_list_unic{0, 1, 2, 3, 4, 2, 5, 6, 4, 4, 6, 6, 7, 7};

  s21::List<int> s21_list_swap1{1, 1, 1, 1, 1, 1};
  std::list<int> std_list_swap1{1, 1, 1, 1, 1, 1};

  s21::List<int> s21_list_swap2{2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
  std::list<int> std_list_swap2{2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
};

TEST(List, null_constructor) {
  ListTest data;
  EXPECT_EQ(data.s21_list_null.size(), data.std_list_null.size());
  EXPECT_EQ(data.s21_list_null.empty(), data.std_list_null.empty());

  EXPECT_EQ(data.s21_list_null.max_size(), data.std_list_null.max_size());
}

TEST(List, init_list_constructor) {
  ListTest data;
  EXPECT_EQ(data.s21_list_sort.size(), data.std_list_sort.size());
  EXPECT_EQ(data.s21_list_sort.empty(), data.std_list_sort.empty());
}

TEST(List, numb_constructor) {
  s21::List<int> a(5);
  std::list<int> b(5);
  EXPECT_EQ(a.size(), b.size());
  EXPECT_EQ(a.empty(), b.empty());
}

TEST(List, copy_constructor) {
  ListTest data;
  s21::List<int> a(data.s21_list_reverse);
  std::list<int> b(data.std_list_reverse);
  EXPECT_EQ(a.size(), b.size());
  EXPECT_EQ(a.empty(), b.empty());
}

TEST(List, move_constructor) {
  ListTest data;
  s21::List<int> a(data.s21_list_reverse);
  std::list<int> b(data.std_list_reverse);
  s21::List<int> a2(std::move(a));
  std::list<int> b2(std::move(b));

  EXPECT_EQ(a2.size(), b2.size());
  EXPECT_EQ(a2.empty(), b2.empty());

  EXPECT_EQ(a.size(), b.size());
  EXPECT_EQ(a.empty(), b.empty());
  EXPECT_EQ(a.empty(), 1);
}

TEST(List, copy_operator) {
  ListTest data;
  s21::List<int> a(data.s21_list_swap1);
  std::list<int> b(data.std_list_swap1);

  a = data.s21_list_reverse;
  b = data.std_list_reverse;

  EXPECT_EQ(a.size(), b.size());
  EXPECT_EQ(a.empty(), b.empty());
}

TEST(List, move_operator) {
  ListTest data;
  s21::List<int> a(data.s21_list_reverse);
  std::list<int> b(data.std_list_reverse);
  s21::List<int> a2;
  std::list<int> b2;

  a2 = std::move(a);
  b2 = std::move(b);

  EXPECT_EQ(a2.size(), b2.size());
  EXPECT_EQ(a2.empty(), b2.empty());

  EXPECT_EQ(a.size(), b.size());
  EXPECT_EQ(a.empty(), b.empty());
  EXPECT_EQ(a.empty(), 1);
}

TEST(List, iterators) {
  ListTest data;
  std::list<int>::iterator s_iter = data.std_list_reverse.begin();
  s21::List<int>::iterator l_iter = data.s21_list_reverse.begin();

  std::list<int>::iterator s_end = data.std_list_reverse.end();
  //  s21::List<int>::iterator l_end = data.s21_list_reverse.end();

  EXPECT_EQ(data.std_list_reverse.front(), data.s21_list_reverse.front());
  EXPECT_EQ(data.std_list_reverse.back(), data.s21_list_reverse.back());

  while (s_iter != s_end) {
    EXPECT_EQ(*s_iter, *l_iter);
    ++s_iter;
    ++l_iter;
  }

  const s21::List<int> c(data.s21_list_reverse);
  const std::list<int> d(data.std_list_reverse);

  std::list<int>::const_iterator s_iter_c = d.cbegin();
  s21::List<int>::const_iterator l_iter_c = c.cbegin();
  std::list<int>::const_iterator s_end_c = d.cend();

  while (s_iter_c != s_end_c) {
    EXPECT_EQ(*s_iter_c, *l_iter_c);
    ++s_iter_c;
    ++l_iter_c;
  }
}

TEST(List, push) {
  ListTest data;
  data.s21_list_swap1.push_back(5);
  data.s21_list_swap1.push_back(6);
  data.s21_list_swap1.push_back(7);

  data.std_list_swap1.push_back(5);
  data.std_list_swap1.push_back(6);
  data.std_list_swap1.push_back(7);

  std::list<int>::iterator s_iter = data.std_list_swap1.begin();
  s21::List<int>::iterator l_iter = data.s21_list_swap1.begin();

  std::list<int>::iterator s_end = data.std_list_swap1.end();
  //  s21::List<int>::iterator l_end = data.s21_list_reverse.end();

  EXPECT_EQ(data.std_list_swap1.front(), data.s21_list_swap1.front());
  EXPECT_EQ(data.std_list_swap1.back(), data.s21_list_swap1.back());

  while (s_iter != s_end) {
    EXPECT_EQ(*s_iter, *l_iter);
    ++s_iter;
    ++l_iter;
  }

  data.s21_list_swap1.push_front(5);
  data.s21_list_swap1.push_front(6);
  data.s21_list_swap1.push_front(7);

  data.std_list_swap1.push_front(5);
  data.std_list_swap1.push_front(6);
  data.std_list_swap1.push_front(7);

  s_iter = data.std_list_swap1.begin();
  l_iter = data.s21_list_swap1.begin();

  s_end = data.std_list_swap1.end();

  EXPECT_EQ(data.std_list_swap1.front(), data.s21_list_swap1.front());
  EXPECT_EQ(data.std_list_swap1.back(), data.s21_list_swap1.back());

  while (s_iter != s_end) {
    EXPECT_EQ(*s_iter, *l_iter);
    ++s_iter;
    ++l_iter;
  }

  data.s21_list_null.push_front(5);
  data.std_list_null.push_front(5);

  s_iter = data.std_list_null.begin();
  l_iter = data.s21_list_null.begin();

  s_end = data.std_list_null.end();

  while (s_iter != s_end) {
    EXPECT_EQ(*s_iter, *l_iter);
    ++s_iter;
    ++l_iter;
  }

  s21::List<int> s21;
  std::list<int> std;

  s21.push_back(5);
  std.push_back(5);

  s_iter = std.begin();
  l_iter = s21.begin();

  s_end = std.end();

  while (s_iter != s_end) {
    EXPECT_EQ(*s_iter, *l_iter);
    ++s_iter;
    ++l_iter;
  }
}

TEST(List, pop) {
  ListTest data;
  data.s21_list_reverse.pop_back();
  data.s21_list_reverse.pop_back();

  data.std_list_reverse.pop_back();
  data.std_list_reverse.pop_back();

  std::list<int>::iterator s_iter = data.std_list_reverse.begin();
  s21::List<int>::iterator l_iter = data.s21_list_reverse.begin();

  std::list<int>::iterator s_end = data.std_list_reverse.end();

  EXPECT_EQ(data.std_list_reverse.front(), data.s21_list_reverse.front());
  EXPECT_EQ(data.std_list_reverse.back(), data.s21_list_reverse.back());

  while (s_iter != s_end) {
    //    std::cout << *s_iter << " == " << *l_iter << "?\n";
    EXPECT_EQ(*s_iter, *l_iter);
    ++s_iter;
    ++l_iter;
  }

  data.s21_list_reverse.pop_front();
  data.s21_list_reverse.pop_front();

  data.std_list_reverse.pop_front();
  data.std_list_reverse.pop_front();

  s_iter = data.std_list_reverse.begin();
  l_iter = data.s21_list_reverse.begin();

  s_end = data.std_list_reverse.end();

  EXPECT_EQ(data.std_list_reverse.front(), data.s21_list_reverse.front());
  EXPECT_EQ(data.std_list_reverse.back(), data.s21_list_reverse.back());

  while (s_iter != s_end) {
    //    std::cout << *s_iter << " == " << *l_iter << "?\n";
    EXPECT_EQ(*s_iter, *l_iter);
    ++s_iter;
    ++l_iter;
  }
}

TEST(List, pop_all) {
  std::list<int> std{1, 2, 3};
  s21::List<int> s21{1, 2, 3};

  std.pop_back();
  std.pop_back();
  std.pop_back();

  s21.pop_back();
  s21.pop_back();
  s21.pop_back();
  s21.pop_back();

  std::list<int>::iterator s_iter = std.begin();
  s21::List<int>::iterator l_iter = s21.begin();

  std::list<int>::iterator s_end = std.end();

  EXPECT_EQ(std.front(), s21.front());
  EXPECT_EQ(std.back(), s21.back());

  while (s_iter != s_end) {
    //    std::cout << *s_iter << " == " << *l_iter << "?\n";
    EXPECT_EQ(*s_iter, *l_iter);
    ++s_iter;
    ++l_iter;
  }

  std::list<int> std2{1, 2, 3};
  s21::List<int> s212{1, 2, 3};

  std2.pop_front();
  std2.pop_front();
  std2.pop_front();

  s212.pop_front();
  s212.pop_front();
  s212.pop_front();
  s212.pop_front();

  s_iter = std2.begin();
  l_iter = s212.begin();

  s_end = std2.end();

  EXPECT_EQ(std2.front(), s212.front());
  EXPECT_EQ(std2.back(), s212.back());

  while (s_iter != s_end) {
    //    std::cout << *s_iter << " == " << *l_iter << "?\n";
    EXPECT_EQ(*s_iter, *l_iter);
    ++s_iter;
    ++l_iter;
  }
}

TEST(List, swap) {
  ListTest data;

  data.std_list_swap1.swap(data.std_list_swap2);
  data.s21_list_swap1.swap(data.s21_list_swap2);

  std::list<int>::iterator s_iter = data.std_list_swap1.begin();
  s21::List<int>::iterator l_iter = data.s21_list_swap1.begin();

  std::list<int>::iterator s_end = data.std_list_swap1.end();

  EXPECT_EQ(data.std_list_swap1.front(), data.s21_list_swap1.front());
  EXPECT_EQ(data.std_list_swap1.back(), data.s21_list_swap1.back());

  while (s_iter != s_end) {
    //    std::cout << *s_iter << " == " << *l_iter << "?\n";
    EXPECT_EQ(*s_iter, *l_iter);
    EXPECT_EQ(2, *l_iter);
    ++s_iter;
    ++l_iter;
  }

  s_iter = data.std_list_swap2.begin();
  l_iter = data.s21_list_swap2.begin();

  s_end = data.std_list_swap2.end();

  EXPECT_EQ(data.std_list_swap2.front(), data.s21_list_swap2.front());
  EXPECT_EQ(data.std_list_swap2.back(), data.s21_list_swap2.back());

  while (s_iter != s_end) {
    //    std::cout << *s_iter << " == " << *l_iter << "?\n";
    EXPECT_EQ(*s_iter, *l_iter);
    EXPECT_EQ(1, *l_iter);
    ++s_iter;
    ++l_iter;
  }
}

TEST(List, reverse) {
  ListTest data;

  data.std_list_reverse.reverse();
  data.s21_list_reverse.reverse();

  std::list<int>::iterator s_iter = data.std_list_reverse.begin();
  s21::List<int>::iterator l_iter = data.s21_list_reverse.begin();

  std::list<int>::iterator s_end = data.std_list_reverse.end();

  EXPECT_EQ(data.std_list_reverse.front(), data.s21_list_reverse.front());
  EXPECT_EQ(data.std_list_reverse.back(), data.s21_list_reverse.back());

  while (s_iter != s_end) {
    //    std::cout << *s_iter << " == " << *l_iter << "?\n";
    EXPECT_EQ(*s_iter, *l_iter);

    ++s_iter;
    ++l_iter;
  }
  data.std_list_reverse.reverse();
  data.s21_list_reverse.reverse();

  s_iter = data.std_list_reverse.begin();
  l_iter = data.s21_list_reverse.begin();

  s_end = data.std_list_reverse.end();

  EXPECT_EQ(data.std_list_reverse.front(), data.s21_list_reverse.front());
  EXPECT_EQ(data.std_list_reverse.back(), data.s21_list_reverse.back());

  while (s_iter != s_end) {
    //    std::cout << *s_iter << " == " << *l_iter << "?\n";
    EXPECT_EQ(*s_iter, *l_iter);
    ++s_iter;
    ++l_iter;
  }
}

TEST(List, unic) {
  ListTest data;

  data.s21_list_unic.unique();
  data.std_list_unic.unique();

  std::list<int>::iterator s_iter = data.std_list_unic.begin();
  s21::List<int>::iterator l_iter = data.s21_list_unic.begin();

  std::list<int>::iterator s_end = data.std_list_unic.end();

  EXPECT_EQ(data.std_list_unic.front(), data.s21_list_unic.front());
  EXPECT_EQ(data.std_list_unic.back(), data.s21_list_unic.back());

  while (s_iter != s_end) {
    //    std::cout << *s_iter << " == " << *l_iter << "?\n";
    EXPECT_EQ(*s_iter, *l_iter);

    ++s_iter;
    ++l_iter;
  }
}

TEST(List, merge) {
  ListTest data;

  data.s21_list_merge.merge(data.s21_list_sort);
  data.std_list_merge.merge(data.std_list_sort);
  data.std_list_merge.sort();

  std::list<int>::iterator s_iter = data.std_list_merge.begin();
  s21::List<int>::iterator l_iter = data.s21_list_merge.begin();

  std::list<int>::iterator s_end = data.std_list_merge.end();

  EXPECT_EQ(data.std_list_merge.front(), data.s21_list_merge.front());
  EXPECT_EQ(data.std_list_merge.back(), data.s21_list_merge.back());

  while (s_iter != s_end) {
    //    std::cout << *s_iter << " == " << *l_iter << "?\n";
    EXPECT_EQ(*s_iter, *l_iter);

    ++s_iter;
    ++l_iter;
  }
}

TEST(List, emplace) {
  ListTest data;

  data.s21_list_swap1.emplace_back(6);
  data.std_list_swap1.emplace_back(6);

  data.s21_list_swap1.emplace_front(6);
  data.std_list_swap1.emplace_front(6);

  std::list<int>::iterator s_iter = data.std_list_swap1.begin();
  s21::List<int>::iterator l_iter = data.s21_list_swap1.begin();

  std::list<int>::iterator s_end = data.std_list_swap1.end();

  EXPECT_EQ(data.std_list_swap1.front(), data.s21_list_swap1.front());
  EXPECT_EQ(data.std_list_swap1.back(), data.s21_list_swap1.back());

  while (s_iter != s_end) {
    //    std::cout << *s_iter << " == " << *l_iter << "?\n";
    EXPECT_EQ(*s_iter, *l_iter);
    ++s_iter;
    ++l_iter;
  }

  std::list<int>::const_iterator s_iter2 = data.std_list_swap2.cbegin();
  s21::List<int>::const_iterator l_iter2(data.s21_list_swap2.begin() + 2);
  s_iter2++;
  s_iter2++;

  data.s21_list_swap2.emplace(l_iter2, 6);
  data.std_list_swap2.emplace(s_iter2, 6);
  s_iter2++;
  ++l_iter2;
  data.s21_list_swap2.emplace(l_iter2, 4);
  data.std_list_swap2.emplace(s_iter2, 4);
}

TEST(List, sort) {
  std::list<int> std{100, 3};
  s21::List<int> s21{100, 3};

  std.sort();
  s21.sort();

  std::list<int>::iterator s_iter = std.begin();
  s21::List<int>::iterator l_iter = s21.begin();

  //  std::list<int>::iterator s_end = std.end();
  s21::List<int>::iterator l_end = s21.end();

  EXPECT_EQ(std.front(), s21.front());
  EXPECT_EQ(std.back(), s21.back());

  while (l_iter != l_end) {
    //    std::cout << *s_iter << " == " << *l_iter << "?\n";
    EXPECT_EQ(*s_iter, *l_iter);
    ++s_iter;
    ++l_iter;
  }
}