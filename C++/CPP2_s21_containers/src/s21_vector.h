//
// Created by DimasX on 28.04.2023.
//

#ifndef CPP2_S21_CONTAINERS_1_SRC_S1_H_
#define CPP2_S21_CONTAINERS_1_SRC_S1_H_

#include <iostream>

namespace s21 {

template <class T, class Allocator = std::allocator<T>>
class vector {
  template <bool IsConst>
  class VectorIterator {
    using pointer = std::conditional_t<IsConst, const T *, T *>;
    using reference = std::conditional_t<IsConst, const T &, T &>;
    using difference_type = ptrdiff_t;

   private:
    pointer ptr_;

   public:
    VectorIterator() noexcept : ptr_(nullptr) {}
    explicit VectorIterator(pointer ptr_in) noexcept : ptr_(ptr_in) {}
    ~VectorIterator() = default;

    reference operator*() const { return *ptr_; }
    reference operator[](difference_type n) { return *(ptr_ + n); }
    VectorIterator &operator++() {
      ptr_++;
      return *this;
    }

    VectorIterator &operator--() {
      ptr_--;
      return *this;
    }

    VectorIterator operator++(int) {
      auto tmp = *this;
      ptr_++;
      return tmp;
    }
    VectorIterator operator--(int) {
      auto tmp = *this;
      ptr_--;
      return tmp;
    }
    inline bool operator!=(const VectorIterator &other) const noexcept {
      return ptr_ != other.ptr_;
    }
    inline bool operator==(const VectorIterator &other) const noexcept {
      return ptr_ == other.ptr_;
    }
    inline bool operator==(const T *other) const noexcept {
      return ptr_ == other;
    }

    VectorIterator operator+(difference_type n) const {
      auto tmp = *this;
      tmp.ptr_ += n;
      return tmp;
    }

    VectorIterator operator-(difference_type n) {
      auto tmp = *this;
      tmp.ptr_ -= n;
      return tmp;
    }

    const VectorIterator &operator+=(difference_type n) {
      ptr_ += n;
      return *this;
    }

    const VectorIterator &operator-=(difference_type n) {
      ptr_ -= n;
      return *this;
    }

    difference_type inline operator-(
        const VectorIterator &other) const noexcept {
      return ptr_ - other.ptr_;
    }

    inline bool operator<(const VectorIterator &other) const noexcept {
      return ptr_ < other.ptr_;
    }

    inline bool operator>(const VectorIterator &other) const noexcept {
      return ptr_ > other.ptr_;
    }

    inline bool operator<=(const VectorIterator &other) const noexcept {
      return ptr_ <= other.ptr_;
    }
    inline bool operator>=(const VectorIterator &other) const noexcept {
      return ptr_ >= other.ptr_;
    }

    operator VectorIterator<true>() const { return VectorIterator<true>(ptr_); }
  };

  friend bool operator==(const T *ref, VectorIterator<true> x) {
    return x == ref;
  }

  /*=========================================================*/
  /*                                                         */
  /*                     VECTOR MEMBER TYPE                  */
  /*                                                         */
  /*=========================================================*/

 public:
  using value_type = T;
  using allocator_traits = std::allocator_traits<Allocator>;
  using reference = T &;
  using const_reference = const T &;
  using iterator = VectorIterator<false>;
  using const_iterator = VectorIterator<true>;
  using size_type = size_t;
  /*=========================================================*/
  /*                                                         */
  /*                     VECTOR ITERATORS                    */
  /*                                                         */
  /*=========================================================*/

  iterator begin() const {
    VectorIterator<false> iter(arr_);
    return iter;
  }
  iterator end() const {
    VectorIterator<false> iter(arr_ + m_size_);
    return iter;
  }
  /*=========================================================*/
  /*                                                         */
  /*                     VECTOR CONSTRUCTORS                 */
  /*                                                         */
  /*=========================================================*/
  vector() noexcept
      : m_size_(0), m_capacity_(0), arr_(nullptr), alloc_(Allocator()) {}
  vector(std::initializer_list<value_type> const &items,
         const Allocator &alloc_in = Allocator())
      : m_size_(items.size()),
        m_capacity_(m_size_),
        arr_(nullptr),
        alloc_(alloc_in) {
    arr_ = allocator_traits::allocate(alloc_, m_size_);
    size_type i = 0;
    for (auto it = items.begin(); it != items.end(); it++) {
      allocator_traits::construct(alloc_, arr_ + i++, *it);
    }
  }

  vector(size_type count, const Allocator &alloc_in = Allocator())
      : m_size_(count), m_capacity_(count), arr_(nullptr), alloc_(alloc_in) {
    arr_ = allocator_traits::allocate(alloc_, count);
    for (size_type i = 0; i < count; ++i) {
      allocator_traits::construct(alloc_, arr_ + i, T());
    }
  }

  vector(const vector &other)
      : m_size_(other.m_size_),
        m_capacity_(other.m_capacity_),
        arr_(nullptr),
        alloc_(allocator_traits::select_on_container_copy_construction(
            other.GetAlloc())) {
    arr_ = allocator_traits::allocate(alloc_, m_size_);
    size_type i = 0;
    for (auto it = other.begin(); it != other.end(); it++) {
      allocator_traits::construct(alloc_, arr_ + i++, *it);
    }
  }

  vector(vector &&other)
      : m_size_(other.m_size_),
        m_capacity_(other.m_capacity_),
        arr_(other.arr_),
        alloc_(std::move(other.alloc_)) {
    other.arr_ = nullptr;
    other.m_capacity_ = other.m_size_ = 0;
  }
  ~vector() {
    clear();
    allocator_traits::deallocate(alloc_, arr_, m_capacity_);
  }

  vector &operator=(const vector &other) {
    if (&other != this) {
      DeallocArray();
      m_size_ = other.m_size_;
      m_capacity_ = other.m_capacity_;
      alloc_ = allocator_traits::select_on_container_copy_construction(
          other.GetAlloc());
      arr_ = allocator_traits::allocate(alloc_, other.m_size_);
      size_type i = 0;
      for (auto it = other.begin(); it != other.end(); it++) {
        allocator_traits::construct(alloc_, arr_ + i++, *it);
      }
    }
    return *this;
  }

  vector &operator=(vector &&other) noexcept {
    if (&other != this) {
      DeallocArray();
      m_size_ = other.m_size_;
      m_capacity_ = other.m_capacity_;
      alloc_ = std::move(other.alloc_);
      arr_ = other.arr_;
      other.arr_ = nullptr;
      other.m_capacity_ = other.m_size_ = 0;
    }
    return *this;
  }

  /*=========================================================*/
  /*                                                         */
  /*                     VECTOR ELEMENT ACCESS               */
  /*                                                         */
  /*=========================================================*/
  reference at(size_type pos) {
    if (pos >= m_size_) throw std::out_of_range("Index out of range");
    return arr_[pos];
  }

  reference operator[](size_type pos) { return arr_[pos]; }

  const_reference operator[](size_type pos) const { return arr_[pos]; }
  reference front() {
    if (empty()) throw std::out_of_range("Index out of range");
    return arr_[0];
  }
  reference back() {
    if (empty()) throw std::out_of_range("Index out of range");
    return arr_[m_size_ - 1];
  }
  const_reference front() const {
    if (empty()) throw std::out_of_range("Index out of range");
    return arr_[0];
  }
  const_reference back() const {
    if (empty()) throw std::out_of_range("Index out of range");
    return arr_[m_size_ - 1];
  }
  T *data() { return arr_; }
  const T *data() const { return arr_; }
  /*=========================================================*/
  /*                                                         */
  /*                     VECTOR CAPACITY                     */
  /*                                                         */
  /*=========================================================*/
  [[nodiscard]] bool empty() const { return !m_size_; }
  [[nodiscard]] size_type size() const { return m_size_; }
  [[nodiscard]] size_type max_size() const {
    return allocator_traits::max_size(alloc_);
  }

  void reserve(size_type size) {
    if (size > max_size())
      throw std::length_error("Cannot allocate more than max size");
    if (size > m_capacity_) {
      T *new_arr = allocator_traits::allocate(alloc_, size);
      MoveToNewArr(new_arr, m_size_);
      DeallocArray();
      arr_ = new_arr;
      m_capacity_ = size;
    }
  }

  size_type capacity() { return m_capacity_; }
  size_type capacity() const { return m_capacity_; }
  void shrink_to_fit() {
    if (m_size_ == m_capacity_) return;
    if (m_size_ == 0) {
      DeallocArray();
    } else {
      T *new_arr = allocator_traits::allocate(alloc_, m_size_);
      MoveToNewArr(new_arr, m_size_);
      DeallocArray();
      arr_ = new_arr;
    }
    m_capacity_ = m_size_;
  }
  /*=========================================================*/
  /*                                                         */
  /*                     VECTOR MODIFIERS                    */
  /*                                                         */
  /*=========================================================*/

  void clear() noexcept {
    for (size_type j = 0; j < m_size_; ++j) {
      allocator_traits::destroy(alloc_, arr_ + j);
    }
    m_size_ = 0;
  }

  iterator insert(iterator pos, const_reference value) {
    if (pos < begin() || pos > end())
      throw std::out_of_range("The place does not belong to the vector");
    size_t index = pos - begin();
    if (m_size_ >= m_capacity_) reserve(m_capacity_ == 0 ? 1 : m_capacity_ * 2);
    allocator_traits::construct(alloc_, arr_ + m_size_, T());
    std::move_backward(arr_ + index, arr_ + m_size_, arr_ + m_size_ + 1);
    allocator_traits::construct(alloc_, arr_ + index, value);
    m_size_ += 1;
    return VectorIterator<false>(arr_ + index);
  }

  iterator erase(iterator pos) {
    if (pos < begin() || pos > end())
      throw std::out_of_range("The place does not belong to the vector");
    size_t index = pos - begin();
    std::move(arr_ + index + 1, arr_ + m_size_, arr_ + index);
    allocator_traits::destroy(alloc_, arr_ + m_size_ - 1);
    --m_size_;
    return begin() + index;
  }
  void push_back(const_reference value) {
    if (m_size_ >= m_capacity_) reserve(m_capacity_ == 0 ? 1 : m_capacity_ * 2);
    allocator_traits::construct(alloc_, arr_ + m_size_, value);
    m_size_++;
  }

  void pop_back() {
    if (empty()) throw std::out_of_range("Index out of range");
    allocator_traits::destroy(alloc_, arr_ + (--m_size_));
  }

  void swap(vector &other) {
    std::swap(other.m_size_, m_size_);
    std::swap(other.m_capacity_, m_capacity_);
    std::swap(other.arr_, arr_);
    std::swap(alloc_, other.alloc_);
  }

  template <typename... Args>
  iterator emplace(const_iterator pos, Args &&...args) {
    if (pos < begin() || pos > end())
      throw std::out_of_range("The place does not belong to the vector");
    const size_t num_args = sizeof...(Args);
    const size_t index = pos - begin();
    if (m_size_ + num_args > m_capacity_) {
      if (!m_capacity_)
        reserve(1);
      else {
        reserve(num_args < m_size_ ? m_capacity_ * 2
                                   : ((m_capacity_ + num_args) * 2));
        for (auto ind = arr_ + m_size_ + num_args; ind >= arr_ + m_size_;
             ind--) {
          allocator_traits::construct(alloc_, ind, T());
        }
        std::move_backward(arr_ + index, arr_ + m_size_,
                           arr_ + m_size_ + num_args);
      }
    }

    size_t arg_count = 0;
    for (auto item_ : {std::forward<Args>(args)...}) {
      allocator_traits::construct(alloc_, arr_ + index + arg_count++, T(item_));
    }
    m_size_ += arg_count;
    return begin() + index;
  }

  template <typename... Args>
  iterator emplace_back(Args &&...args) {
    emplace(std::move(end()), std::forward<Args>(args)...);
    return end() - 1;
  }

  /*=========================================================*/
  /*                                                         */
  /*                     VECTOR CUSTOM                       */
  /*                                                         */
  /*=========================================================*/

  void MoveToNewArr(T *new_arr, size_type count) {
    for (size_type i = 0; i < count; ++i) {
      allocator_traits::construct(alloc_, new_arr + i, std::move(arr_[i]));
    }
  }

  void DeallocArray() {
    if (arr_ != nullptr) {
      for (size_type j = 0; j < m_size_; ++j) {
        allocator_traits::destroy(alloc_, arr_ + j);
      }
      allocator_traits::deallocate(alloc_, arr_, m_capacity_);
    }
    arr_ = nullptr;
  }

  Allocator GetAlloc() const noexcept { return alloc_; }

 private:
  size_t m_size_;
  size_t m_capacity_;
  T *arr_;
  Allocator alloc_;
};
}  // namespace s21
#endif  // CPP2_S21_CONTAINERS_1_SRC_S1_H_
