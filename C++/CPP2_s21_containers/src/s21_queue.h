#ifndef CPP2_S21_CONTAINERS_1_SRC_S21_QUEUE_H_
#define CPP2_S21_CONTAINERS_1_SRC_S21_QUEUE_H_

#include <cstdlib>
#include <iostream>

namespace s21 {

template <class T, class Container = s21::List<T> >
class Queue {
 public:
  using value_type = typename Container::value_type;
  using reference = typename Container::reference;
  using const_reference = typename Container::const_reference;
  using size_type = typename Container::size_type;

  Queue() : list_(){};
  Queue(std::initializer_list<value_type> const &items) : list_(items) {}
  Queue(const Queue &s) : list_(s.list_) {}
  Queue(Queue &&s) noexcept : list_(std::move(s.list_)){};
  ~Queue() = default;

  Queue &operator=(Queue &&s) noexcept {
    list_ = std::move(s.list_);
    return *this;
  };
  Queue &operator=(const Queue &s) noexcept {
    list_ = s.list_;
    return *this;
  };

  const_reference front() const { return list_.front(); }
  const_reference back() const { return list_.back(); }
  reference front() { return list_.front(); }
  reference back() { return list_.back(); }

  bool empty() { return list_.empty(); }
  size_type size() { return list_.size(); }
  void push(const_reference value) { list_.push_back(value); }
  void pop() { list_.pop_front(); };
  void swap(Queue &other) { list_.swap(other.list_); };

  template <typename... Args>
  void emplace_back(Args &&...args) {
    list_.emplace_back(std::forward<Args>(args)...);
  }

 private:
  Container list_;
};

}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_1_SRC_S21_QUEUE_H_
