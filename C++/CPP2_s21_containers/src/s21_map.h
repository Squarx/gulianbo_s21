#ifndef CPP2_S21_CONTAINERS_1_SRC_S21_MAP_H_
#define CPP2_S21_CONTAINERS_1_SRC_S21_MAP_H_
#include <cstdlib>
#include <iostream>
#include <limits>

#include "s21_set.h"
#include "s21_vector.h"
template <class value_type, class Compare>
class MapComp {
 public:
  MapComp() : comp_(Compare()) {}
  bool operator()(const value_type &lhs, const value_type &rhs) const {
    return comp_(lhs.first, rhs.first);
  }

 private:
  Compare comp_;
};

namespace s21 {
template <class Key, class T, class Compare = std::less<Key>,
          class Allocator = std::allocator<std::pair<Key, T>>,
          class Container =
              s21::Set<std::pair<Key, T>, MapComp<std::pair<Key, T>, Compare>,
                       Allocator, true>>

class Map {
 public:
  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<key_type, mapped_type>;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = typename s21::Set<value_type, MapComp<value_type, Compare>,
                                     Allocator, false>::iterator;
  using const_iterator =
      typename s21::Set<value_type, MapComp<value_type, Compare>, Allocator,
                        true>::const_iterator;
  using size_type = size_t;

  Map() : set_() {}
  Map(std::initializer_list<value_type> const &items) : set_(items) {}
  Map(const Map &s) : set_(s.set_) {}

  Map(Map &&s) : set_(std::move(s.set_)) {}
  Map &operator=(const Map &s) noexcept {
    if (&s == this) return *this;
    set_ = s.set_;
    return *this;
  }

  ~Map() = default;
  Map &operator=(Map &&s) noexcept {
    set_ = std::move(s.set_);
    return *this;
  };

  T &at(const Key &key) {
    std::pair<Key, T> a{key, T()};
    auto res = set_.find(a);
    if (res.IsDefLeaf())
      throw std::out_of_range("Tree dont contain this key");
    else
      return (*res).second;
  }

  T &operator[](const Key &key) {
    std::pair<Key, T> a{key, T()};
    auto res = set_.find(a);
    if (res.IsDefLeaf()) {
      iterator t = ((set_.insert(a)).first);
      return (*t).second;
    } else
      return (*res).second;
  }

  iterator begin() { return set_.begin(); }
  iterator end() { return set_.end(); }
  bool empty() { return set_.empty(); }
  size_type size() { return set_.size(); }
  void clear() { set_.clear(); }

  size_type max_size() {
    std::allocator<T> alloc_;
    return alloc_.max_size() / 10;
  }

  std::pair<iterator, bool> insert(const value_type &value) {
    return set_.insert(value);
  }

  std::pair<iterator, bool> insert(const Key &key, const T &obj) {
    value_type pair{key, obj};
    return set_.insert(pair);
  }

  std::pair<iterator, bool> insert_or_assign(const Key &key, const T &obj) {
    auto pair = std::make_pair(key, obj);
    auto res = set_.find(pair);
    if (res.IsDefLeaf()) {
      return set_.insert(pair);
    } else {
      (*res).second = obj;
      return std::make_pair(res, false);
    }
  }

  void erase(iterator pos) { set_.erase(pos); }
  void swap(Map &other) { set_.swap(other.set_); }
  void merge(Map &other) { set_.merge(other.set_); }
  bool contains(const Key &key) { return set_.contains({key, T()}); }

  template <typename... Args>
  s21::vector<std::pair<iterator, bool>> emplace(Args &&...args) {
    return set_.emplace(std::forward<Args>(args)...);
  }

 private:
  Container set_;
};
}  // namespace s21
#endif  // CPP2_S21_CONTAINERS_1_SRC_S21_MAP_H_
