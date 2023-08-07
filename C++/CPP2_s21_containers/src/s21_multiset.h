#ifndef CPP2_S21_CONTAINERS_1_SRC_S21_MULTISET_H_
#define CPP2_S21_CONTAINERS_1_SRC_S21_MULTISET_H_

#include <cstdlib>
#include <iostream>

#include "s21_set.h"

namespace s21 {

template <class Key, class Compare = std::less<Key>,
          class Allocator = std::allocator<Key>,
          class Container = s21::Set<Key, Compare, Allocator, false>>

class Multiset {
 public:
  using key_type = Key;
  using value_type = Key;
  using reference = Key&;
  using const_reference = const Key&;
  using iterator = typename s21::Set<Key, Compare, Allocator, true>::iterator;
  using const_iterator =
      typename s21::Set<Key, Compare, Allocator, true>::const_iterator;
  using size_type = size_t;

  Multiset() : set_() {}
  Multiset(std::initializer_list<value_type> const& items) : set_(items) {}
  Multiset(const Multiset& s) : set_(s.set_) {}
  Multiset(Multiset&& s) : set_(std::move(s.set_)) {}

  Multiset& operator=(const Multiset& s) noexcept {
    if (&s == this) return *this;
    set_ = s.set_;
    return *this;
  }

  ~Multiset() = default;
  Multiset& operator=(Multiset&& s) noexcept {
    set_ = std::move(s.set_);
    return *this;
  };

  iterator begin() { return set_.begin(); }
  iterator end() { return set_.end(); }
  bool empty() { return set_.empty(); }
  size_type size() { return set_.size(); }
  size_type max_size() { return set_.max_size(); }

  void clear() { set_.clear(); }
  iterator insert(const value_type& value) {
    return (set_.insert(value).first);
  }
  void erase(iterator pos) { set_.erase(pos); }
  void swap(Multiset& other) { set_.swap(other.set_); }
  void merge(Multiset& other) { set_.merge(other.set_); }

  iterator find(const Key& key) { return set_.find(key); }
  bool contains(const Key& key) { return set_.contains(key); }

  size_type count(const Key& key) {
    auto find = set_.find(key);
    auto cnt = 0;
    if (!find.IsDefLeaf()) {
      for (auto i = lower_bound(key); i++ != upper_bound(key); cnt++)
        ;
    }
    return cnt;
  }

  std::pair<iterator, iterator> equal_range(const Key& key) {
    return std::make_pair(lower_bound(key), upper_bound(key));
  }

  iterator lower_bound(const Key& key) {
    auto find = set_.find(key);
    if (!find.IsDefLeaf()) {
      for (find = begin(); find != end() && *find != key; ++find)
        ;
    }
    return find;
  }

  iterator upper_bound(const Key& key) {
    auto find = set_.find(key);
    if (!find.IsDefLeaf())
      for (; (find != end()) && (*find == key); ++find)
        ;
    return find;
  }

  template <typename... Args>
  vector<std::pair<iterator, bool>> emplace(Args&&... args) {
    return set_.emplace(std::forward<Args>(args)...);
  }

 private:
  Container set_;
};

}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_1_SRC_S21_MULTISET_H_
