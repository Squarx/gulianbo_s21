#ifndef CPP2_S21_CONTAINERS_1_SRC_S21_ARRAY_H_
#define CPP2_S21_CONTAINERS_1_SRC_S21_ARRAY_H_

#include <cstdlib>
#include <iostream>

namespace s21 {

template <class T, size_t S>
class Array {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;
  using iterator = T *;
  using const_iterator = const T *;

  Array() = default;
  Array(std::initializer_list<value_type> const &items) {
    if (items.size() > size_) throw std::length_error("Array's size error");
    int count = 0;
    for (auto const &val : items) {
      array_[count] = val;
      count++;
    }
  }
  Array(const Array &a) { CopyArray(a); }
  Array(Array &&a) noexcept : Array(a) {}
  ~Array() = default;

  Array &operator=(Array &&a) noexcept {
    CopyArray(a);
    return *this;
  }

  Array &operator=(const Array &a) noexcept {
    CopyArray(a);
    return *this;
  }

  bool empty() { return size_ == 0; }
  size_type size() { return size_; }
  size_type max_size() { return size_; }

  reference at(size_type pos) {
    if (pos >= size_) throw std::length_error("Array's size error");
    return array_[pos];
  }
  reference operator[](size_type pos) { return array_[pos]; }

  iterator begin() { return data(); }
  iterator end() { return (data() + size_); }
  iterator data() { return array_; };
  const_iterator cbegin() { return const_iterator(data()); }
  const_iterator cend() { return const_iterator(data() + size_); }

  const_reference front() const { return array_[0]; }
  const_reference back() const { return array_[size_ - 1]; }

  void swap(Array &other) {
    if (size_ != other.size_) throw std::length_error("Array's size error");
    for (size_type i = 0; i < size_; i++) {
      value_type tmp = array_[i];
      array_[i] = other.array_[i];
      other.array_[i] = tmp;
    }
  }
  void fill(const_reference value) {
    for (size_type i = 0; i < size_; i++) array_[i] = value;
  };

 private:
  value_type array_[S];
  size_type size_ = S;

  void CopyArray(const Array &a) {
    if (size_ != a.size_) throw std::length_error("Array's size error");
    for (size_type i = 0; i < size_; i++) array_[i] = a.array_[i];
  }
};

}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_1_SRC_S21_ARRAY_H_
