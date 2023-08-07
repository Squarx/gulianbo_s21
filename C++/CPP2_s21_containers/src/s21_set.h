#ifndef CPP2_S21_CONTAINERS_1_SRC_S21_SET_H_
#define CPP2_S21_CONTAINERS_1_SRC_S21_SET_H_

#include <cstdlib>
#include <iostream>

#include "s21_tree.h"
#include "s21_vector.h"
namespace s21 {

template <class Key, class Compare = std::less<Key>,
          class Allocator = std::allocator<Key>, bool IsUniq = true>
class Set {
 public:
  using key_type = Key;
  using value_type = Key;
  using reference = Key &;
  using const_reference = const Key &;
  using iterator =
      typename s21::Tree<Key, Compare, Allocator>::template RBIterator<false>;
  using const_iterator =
      typename s21::Tree<Key, Compare, Allocator>::template RBIterator<true>;
  using size_type = size_t;
  using allocator_traits = std::allocator_traits<Allocator>;

  /*=========================================================*/
  /*                                                         */
  /*                     SET CONSTRUCTORS                    */
  /*                                                         */
  /*=========================================================*/
  Set() : map_tree_(nullptr), alloc_(Allocator()) { ConstructSet(); }

  Set(std::initializer_list<value_type> const &items) : Set() {
    for (auto &i : items)
      if (!IsUniq || (IsUniq && map_tree_->IsDefLeaf(map_tree_->Search(i))))
        map_tree_->Insert(i);
  }

  Set(const Set &s) : Set() {
    if (s.map_tree_->Size()) {
      for (auto i = s.map_tree_->Begin(); i != s.map_tree_->End(); ++i) {
        map_tree_->Insert(*i);
      }
    }
  }

  Set(Set &&s) { MoveTree(s); }

  void MoveTree(Set &s) {
    map_tree_ = s.map_tree_;
    s.map_tree_ = nullptr;
  }

  ~Set() { DeallocMapTree(); }

  void DeallocMapTree() {
    if (map_tree_) {
      allocator_traits::destroy(alloc_, map_tree_);
      allocator_traits::deallocate(
          alloc_,
          reinterpret_cast<typename allocator_traits::pointer>(map_tree_),

          sizeof(map_tree_));
    }
  }

  Set &operator=(const Set &s) noexcept {
    if (&s == this) return *this;
    DeallocMapTree();
    ConstructSet();
    for (auto i = s.map_tree_->Begin(); i != s.map_tree_->End(); ++i) {
      map_tree_->Insert(*i);
    }
    return *this;
  }

  Set &operator=(Set &&m) noexcept {
    if (&m == this) return *this;
    DeallocMapTree();
    MoveTree(m);
    return *this;
  }
  /*=========================================================*/
  /*                                                         */
  /*                     MAP Iterators                       */
  /*                                                         */
  /*=========================================================*/
  iterator begin() const { return map_tree_->Begin(); }
  iterator end() { return map_tree_->End(); }
  /*=========================================================*/
  /*                                                         */
  /*                     Set Capacity                        */
  /*                                                         */
  /*=========================================================*/
  bool empty() { return map_tree_->IsEmpty(); }
  size_type size() { return map_tree_->Size(); }
  size_type max_size() { return map_tree_->MaxSize(); }
  /*=========================================================*/
  /*                                                         */
  /*                     SET Modifiers                       */
  /*                                                         */
  /*=========================================================*/
  //
  void clear() {
    if (map_tree_) map_tree_->Clear();
  }
  std::pair<iterator, bool> insert(const value_type &value) {
    auto res = map_tree_->Search(value);
    if (!IsUniq || (IsUniq && map_tree_->IsDefLeaf(res))) {
      auto it = map_tree_->Insert(value);
      return std::make_pair(it, true);
    } else {
      iterator it = iterator(map_tree_, res);
      return std::make_pair(it, false);
    }
  }

  void erase(const iterator &pos) const { map_tree_->Remove(*pos); }

  void swap(Set &other) {
    std::swap(map_tree_, other.map_tree_);
    std::swap(alloc_, other.alloc_);
  }

  void merge(Set &other) {
    auto it = other.begin();
    while (it != other.end()) {
      auto node = *it++;
      if (insert(node).second) {
        auto next_node = *it;
        other.map_tree_->Remove(node);
        if (it != other.end()) it = other.find(next_node);
      }
    }
  }
  iterator find(const Key &key) {
    return iterator(map_tree_, map_tree_->Search(key));
  }

  bool contains(const Key &key) { return !(find(key).IsDefLeaf()); }

  template <typename... Args>
  s21::vector<std::pair<iterator, bool>> emplace(Args &&...args) {
    s21::vector<std::pair<iterator, bool>> result;
    for (auto item_ : {std::forward<Args>(args)...}) {
      result.push_back(insert(item_));
    }
    return result;
  }
  void ConstructSet() {
    map_tree_ = reinterpret_cast<Tree<Key, Compare, Allocator> *>(
        allocator_traits::allocate(alloc_,
                                   sizeof(Tree<Key, Compare, Allocator>)));
    allocator_traits::construct(alloc_, map_tree_);
  }

 private:
  Tree<Key, Compare, Allocator> *map_tree_ = nullptr;
  Allocator alloc_;
};

}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_1_SRC_S21_SET_H_
