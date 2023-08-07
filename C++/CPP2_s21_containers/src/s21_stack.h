#ifndef CPP2_S21_CONTAINERS_1_SRC_S21_STACK_H_
#define CPP2_S21_CONTAINERS_1_SRC_S21_STACK_H_

#include <cstdlib>
#include <iostream>

namespace s21 {

template <class T, class Container = s21::List<T> >
class Stack {
 public:
  using value_type = typename Container::value_type;
  using reference = typename Container::reference;
  using const_reference = typename Container::const_reference;
  using size_type = typename Container::size_type;

  Stack() : list_() {}
  Stack(std::initializer_list<value_type> const &items) : list_(items) {}
  Stack(const Stack &s) : list_(s.list_) {}
  Stack(Stack &&s) : list_(std::move(s.list_)) {}
  ~Stack() = default;

  Stack &operator=(Stack &&s) noexcept {
    list_ = std::move(s.list_);
    return *this;
  }
  Stack &operator=(const Stack &s) noexcept {
    list_ = s.list_;
    return *this;
  }

  const_reference top() { return list_.back(); }

  bool empty() { return list_.empty(); }
  size_type size() { return list_.size(); }
  void push(const_reference value) { list_.push_back(value); }
  void pop() { list_.pop_back(); }
  void swap(Stack &other) { list_.swap(other.list_); };

  template <typename... Args>
  void emplace_front(Args &&...args) {
    for (auto item_ : {std::forward<Args>(args)...}) push(item_);
  }

 private:
  Container list_;
};
}  // namespace s21
#endif  // CPP2_S21_CONTAINERS_1_SRC_S21_STACK_H_
