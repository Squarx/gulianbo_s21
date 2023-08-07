#ifndef CPP2_S21_CONTAINeRS_1_SRC_S21_LIST_H_
#define CPP2_S21_CONTAINeRS_1_SRC_S21_LIST_H_

#include <cstdlib>
#include <iostream>
#include <limits>
namespace s21 {

template <class T>
class List {
 public:
  class ListIterator;

  class LNode {
   public:
    LNode() = default;
    explicit LNode(T Data) { data = Data; }
    LNode(const LNode &n) { CopyNode(n); }
    LNode(LNode &&n) { MoveNode(n); }
    ~LNode() = default;
    T data;
    LNode *next = nullptr;
    LNode *prev = nullptr;
    LNode &operator=(const LNode &n) noexcept {
      CopyNode(n);
      return *this;
    }
    LNode &operator=(LNode &&n) noexcept {
      MoveNode(n);
      return *this;
    }

   private:
    LNode &CopyNode(const LNode &n) {
      if (this != &n) {
        data = n.data;
        next = n.next;
        prev = n.prev;
      }
      return *this;
    }

    LNode &MoveNode(const LNode &n) {
      if (this != &n) {
        this = &n;
        n = nullptr;
      }
      return *this;
    }
  };

  class ListIteratorConst {
   public:
    ListIteratorConst() = default;
    explicit ListIteratorConst(ListIterator p) : pointer(p.pointer) {}
    explicit ListIteratorConst(LNode *p) : pointer(p) {}
    explicit ListIteratorConst(const LNode *p) : pointer(p) {}
    ~ListIteratorConst() = default;

    const T &operator*() const { return pointer->data; }
    ListIteratorConst &operator++() {
      pointer = pointer->next;
      return *this;
    }
    ListIteratorConst &operator--() {
      pointer = pointer->prev;
      return *this;
    }

    ListIteratorConst &operator=(ListIterator p) {
      pointer = (Node *)p.pointer;
      return *this;
    }

    bool operator==(ListIteratorConst p) { return pointer == p.pointer; }
    bool operator!=(ListIteratorConst p) { return pointer != p.pointer; }
    bool operator==(ListIterator p) { return pointer == p.pointer; }
    bool operator!=(ListIterator p) { return pointer != p.pointer; }

    friend List;

   protected:
    const LNode *pointer = nullptr;
  };

  class ListIterator {
   public:
    LNode *pointer = nullptr;

    ListIterator() = default;
    explicit ListIterator(ListIteratorConst p) : pointer(p.pointer) {}
    explicit ListIterator(LNode *p) : pointer(p) {}
    ~ListIterator() = default;

    T &operator*() { return pointer->data; }

    ListIterator &operator++() {
      pointer = pointer->next;
      return *this;
    }

    ListIterator &operator--() {
      pointer = pointer->prev;
      return *this;
    }

    ListIterator operator-(int count) {
      auto tmp = *this;
      for (int i = 0; i < count; i++) tmp.pointer = tmp.pointer->prev;
      return tmp;
    }

    ListIterator operator+(int count) {
      auto tmp = *this;
      for (int i = 0; i < count; i++) tmp.pointer = tmp.pointer->next;
      return tmp;
    }

    bool operator==(ListIteratorConst p) { return pointer == p.pointer; }
    bool operator!=(ListIteratorConst p) { return pointer != p.pointer; }
    bool operator==(ListIterator p) { return pointer == p.pointer; }
    bool operator!=(ListIterator p) { return pointer != p.pointer; }
  };

  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = ListIterator;
  using const_iterator = ListIteratorConst;
  using size_type = size_t;
  using Node = LNode;

  List() = default;
  List(size_type n) {
    for (size_type i = 0; i < n; i++) push_back(0);
  }
  List(std::initializer_list<value_type> const &items) {
    for (auto const &val : items) push_back(val);
  }
  List(const List &l);
  List(List &&l);
  ~List() { clear(); }
  List &operator=(List &&l) noexcept;
  List &operator=(const List &l) noexcept;

  const_reference front() const { return *cbegin(); }
  const_reference back() const {
    if ((--cend()).pointer != nullptr) return *(--cend());
    return *(cend());
  }
  const_iterator cbegin() const {
    if (end_node_.next) return const_iterator(end_node_.next);
    return cend();
  }
  const_iterator cend() const { return const_iterator(&end_node_); }

  reference front() { return *begin(); }
  reference back() {
    if ((--end()).pointer) return *(--end());
    return *(end());
  }
  iterator begin() {
    if (end_node_.next) return iterator(end_node_.next);
    return end();
  }
  iterator end() { return iterator(&end_node_); }

  bool empty() { return size_ == 0; }
  size_type size() { return size_; }
  size_type max_size() {
    return std::numeric_limits<std::ptrdiff_t>().max() / sizeof(Node);
  }

  void clear();
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void push_front(const_reference value);
  void pop_front();
  void swap(List &other);
  void merge(List &other);
  void splice(const_iterator pos, List &other);
  void reverse();
  void unique();
  void sort();
  template <class... Args>
  iterator emplace(const_iterator pos, Args &&...args);
  template <class... Args>
  void emplace_back(Args &&...args) {
    for (auto item_ : {std::forward<Args>(args)...}) {
      emplace(cend(), item_);
    }
  }
  template <class... Args>
  void emplace_front(Args &&...args) {
    for (auto item_ : {std::forward<Args>(args)...}) {
      emplace(cbegin(), item_);
    }
  }

 private:
  Node end_node_{};
  size_type size_ = 0;

  void NodeInit(const_reference value);
  void MoveList(List &l);
  void CopyList(const List &l);
  void DataSwap(iterator from, iterator to) {
    std::swap(from.pointer->data, to.pointer->data);
  }
  void DataSwap(iterator &start, iterator &end, iterator &pivot);
  void MyQuickSort(iterator start, iterator end, int size);
  void NodeMove(iterator from, iterator to);
};

template <class T>
void List<T>::NodeInit(const_reference value) {
  Node *init = new Node(value);
  end_node_.prev = init;
  end_node_.next = init;
  init->prev = &end_node_;
  init->next = &end_node_;
  size_++;
}

template <class T>
List<T>::List(const List &l) {
  CopyList(l);
}

template <class T>
void List<T>::CopyList(const List &l) {
  if (l.size_ == 0) return;
  auto iter = l.cbegin();
  auto end = l.cend();
  while (iter != end) {
    push_back(*iter);
    ++iter;
  }
}

template <class T>
List<T>::List(List &&l) {
  MoveList(l);
}

template <class T>
void List<T>::MoveList(List &l) {
  if (this == &l || l.size_ == 0) return;

  Node *head = l.end_node_.next;
  Node *tail = l.end_node_.prev;

  size_ = l.size_;
  end_node_.next = head;
  end_node_.prev = tail;

  head->prev = tail->next = &end_node_;

  l.end_node_.next = l.end_node_.prev = nullptr;
  l.size_ = 0;
}

template <class T>
List<T> &List<T>::operator=(List &&l) noexcept {
  clear();
  if (!(l.empty())) MoveList(l);
  return *this;
}

template <class T>
List<T> &List<T>::operator=(const List &l) noexcept {
  if (this != &l) {
    clear();
    if (l.size_ != 0) CopyList(l);
  }
  return *this;
}

template <class T>
void List<T>::erase(List::iterator pos) {
  if (pos.pointer == &end_node_) return;
  pos.pointer->prev->next = pos.pointer->next;
  pos.pointer->next->prev = pos.pointer->prev;

  delete pos.pointer;
  --size_;
}

template <class T>
typename List<T>::iterator List<T>::insert(List::iterator pos,
                                           const_reference value) {
  if (end_node_.next == nullptr) {
    NodeInit(value);
    pos.pointer = end_node_.next;
  } else {
    Node *new_node = new Node(value);
    Node *prev_node = pos.pointer->prev;
    Node *next_node = pos.pointer;

    new_node->next = next_node;
    new_node->prev = prev_node;

    next_node->prev = new_node;
    prev_node->next = new_node;

    pos.pointer = new_node;
    size_++;
  }
  return pos;
}

template <class T>
void List<T>::pop_back() {
  if (end_node_.prev != nullptr) {
    erase(--end());
  }
}

template <class T>
void List<T>::push_back(const_reference value) {
  insert(end(), value);
}

template <class T>
void List<T>::push_front(const_reference value) {
  insert(begin(), value);
}

template <class T>
void List<T>::pop_front() {
  if (end_node_.next != nullptr) erase(begin());
}

template <class T>
void List<T>::clear() {
  if (end_node_.next == &end_node_) return;
  while (size_ != 0) {
    pop_front();
  }
  end_node_.next = end_node_.prev = nullptr;
}

template <class T>
void List<T>::swap(List &other) {
  Node *tail = other.end_node_.prev;
  Node *head = other.end_node_.next;

  other.end_node_.next = end_node_.next;
  other.end_node_.prev = end_node_.prev;

  if (end_node_.next)
    end_node_.next->prev = end_node_.prev->next = &other.end_node_;

  end_node_.next = head;
  end_node_.prev = tail;

  if (head) head->prev = tail->next = &end_node_;

  int size_tmp = size_;
  size_ = other.size_;
  other.size_ = size_tmp;
}

template <class T>
void List<T>::merge(List &other) {
  if (other.size_ != 0) {
    auto iter = cbegin();
    splice(iter, other);
  }
  sort();
}

template <class T>
void List<T>::splice(List::const_iterator pos, List &other) {
  Node *tail = const_cast<Node *>(pos.pointer);
  Node *head = tail->prev;

  head->next = other.end_node_.next;
  other.end_node_.next->prev = head;

  tail->prev = other.end_node_.prev;
  other.end_node_.prev->next = tail;

  other.end_node_.next = other.end_node_.prev = nullptr;

  size_ += other.size_;
  other.size_ = 0;
}

template <class T>
void List<T>::reverse() {
  iterator iter = begin();
  end_node_.next = end_node_.prev;
  end_node_.prev = iter.pointer;
  iterator end = this->end();

  while (iter != end) {
    Node *tmp = iter.pointer->prev;
    iter.pointer->prev = iter.pointer->next;
    iter.pointer->next = tmp;
    --iter;
  }
}

template <class T>
void List<T>::unique() {
  iterator iter = begin();
  iterator end = --(this->end());
  iterator tmp;

  while (iter != end) {
    if (iter.pointer->data == iter.pointer->next->data) {
      tmp = iter;
      ++iter;
      erase(tmp);
    } else
      ++iter;
  }
}

template <class T>
void List<T>::sort() {
  iterator iter = begin();
  iterator end = --(this->end());
  if (size_ == 1 || iter == end) return;
  MyQuickSort(iter, end, size_);
}

template <class T>
void List<T>::MyQuickSort(iterator start, iterator end, int size) {
  if (start == end || size <= 1) return;
  iterator start_tmp(start);
  iterator end_tmp(end);
  int size1 = size / 2 == 0 ? size / 2 - 1 : size / 2;
  iterator pivot(start + size1);

  DataSwap(start, end, pivot);

  while (end != pivot) {
    if (*end <= *pivot) {
      auto from = end;
      if (end == end_tmp) end_tmp = end - 1;
      --end;
      NodeMove(from, pivot);
      size1++;
    } else {
      --end;
    }
  }

  while (start != pivot) {
    if (*start >= *pivot) {
      auto from = start;
      if (start == start_tmp) start_tmp = start + 1;
      ++start;
      NodeMove(from, pivot + 1);
      size1--;
    } else {
      ++start;
    }
  }

  int size2 = size - size1;
  MyQuickSort(start_tmp, pivot - 1, size1);
  MyQuickSort(pivot, end_tmp, size2);
}

template <class T>
void List<T>::DataSwap(iterator &start, iterator &end, iterator &pivot) {
  while (start != end && end.pointer->next != start.pointer && start != pivot &&
         end != pivot) {
    if (*start <= *pivot) ++start;
    if (*end >= *pivot) --end;
    if (*start > *pivot && *end < *pivot) DataSwap(start, end);
  }
}

template <class T>
void List<T>::NodeMove(iterator from, iterator to) {
  from.pointer->prev->next = from.pointer->next;
  from.pointer->next->prev = from.pointer->prev;

  to.pointer->prev->next = from.pointer;
  from.pointer->prev = to.pointer->prev;
  to.pointer->prev = from.pointer;
  from.pointer->next = to.pointer;
}

template <class T>
template <class... Args>
typename List<T>::iterator List<T>::emplace(List::const_iterator pos,
                                            Args &&...args) {
  iterator tmp(const_cast<Node *>(pos.pointer));
  tmp = insert(tmp, std::forward<Args>(args)...);
  return tmp;
}

}  // namespace s21
#endif  // CPP2_S21_CONTAINeRS_1_SRC_S21_LIST_H_
