#ifndef CPP2_S21_CONTAINERS_1_SRC_S21_TREE_H_
#define CPP2_S21_CONTAINERS_1_SRC_S21_TREE_H_

#include <iostream>

namespace s21 {

enum ColorNode { BLACK, RED };

template <class T, class Compare = std::less<T>,
          class Allocator = std::allocator<T>>
class Tree {
 public:
  class Node {
    friend Tree<T, Compare, Allocator>;

   public:
    Node() = default;
    Node(const T &value, Node *parent_)
        : parent_(parent_), item_(value), color_(RED) {}
    bool IsLeftChild() { return parent_ && this == parent_->left_; }
    bool IsRightChild() { return parent_ && this == parent_->right_; }
    T &operator*() { return item_; }
    friend std::ostream &operator<<(std::ostream &os, const Node &node) {
      os << node.item_;
      return os;
    }

   private:
    Node *left_ = nullptr, *right_ = nullptr, *parent_ = nullptr;
    T item_ = T();
    ColorNode color_ = BLACK;
  };

  template <bool IsConst>
  class RBIterator {
    using pointer = std::conditional_t<IsConst, const T *, T *>;
    using reference = std::conditional_t<IsConst, const T &, T &>;
    using difference_type = ptrdiff_t;
    using TreeT = Tree<T, Compare, Allocator>;

   public:
    explicit RBIterator(const TreeT &t)
        : tree_(std::addressof(t)), node_(t.root_) {}
    RBIterator(const TreeT &t, Node &node)
        : tree_(std::addressof(t)), node_(std::addressof(node)) {}
    RBIterator(const TreeT *t, Node *n) : tree_(t), node_(n) {}
    RBIterator(const RBIterator &o) : tree_(o.tree_), node_(o.node_) {}
    [[nodiscard]] bool IsDefLeaf() const { return tree_->IsDefLeaf(node_); }
    reference operator*() const { return node_->item_; }
    [[nodiscard]] const Node *getNode() const { return node_; }

    operator RBIterator<true>() const {
      return RBIterator<true>(*tree_, *node_);
    }

    RBIterator &operator=(const RBIterator &other) {
      if (this != &other) {
        tree_ = other.tree_;
        node_ = other.node_;
      }
      return *this;
    }

    RBIterator &operator++() {
      node_ = NextNode(this->node_);
      return *this;
    }

    RBIterator operator++(int) {
      auto iter = *this;
      ++(*this);
      return iter;
    }

    RBIterator &operator--() {
      node_ = PrevNode(node_);
      return *this;
    }

    RBIterator operator--(int) {
      auto iter = *this;
      --(*this);
      return iter;
    }

    bool operator!=(const RBIterator &it) const noexcept {
      return tree_ != it.tree_ || node_ != it.node_;
    }

    bool operator==(const RBIterator &it) const noexcept {
      return tree_ == it.tree_ && node_ == it.node_;
    }

    Node *NextNode(Node *node) const {
      if (tree_->IsDefLeaf(node)) {
        return const_cast<Node *>(tree_->def_leaf_);
      }
      if (!tree_->IsDefLeaf(node->right_)) {
        return tree_->NodeMin(node->right_);
      } else {
        while (node->IsRightChild()) {
          node = node->parent_;
        }
        return node != tree_->root_ ? node->parent_
                                    : const_cast<Node *>(tree_->def_leaf_);
      }
    }

    Node *PrevNode(Node *node) const {
      if (tree_->IsDefLeaf(node)) {
        return const_cast<Node *>(tree_->NodeMax(tree_->root_));
      }
      if (!tree_->IsDefLeaf(node->left_)) {
        return tree_->NodeMax(node->left_);
      } else {
        while (node->IsLeftChild()) {
          node = node->parent_;
        }
        return node != tree_->root_ ? node->parent_
                                    : const_cast<Node *>(tree_->def_leaf_);
      }
    }

   private:
    const TreeT *tree_;
    Node *node_;
  };

 public:
  using iterator = RBIterator<false>;
  using const_iterator = RBIterator<true>;
  using pointer = Node *;
  using pointer_traits = typename std::allocator_traits<Allocator>::pointer;
  using reference = Node &;
  using const_reference = const Node &;
  using allocator_traits = std::allocator_traits<Allocator>;
  Tree() {
    def_leaf_ = reinterpret_cast<Node *>(
        allocator_traits::allocate(alloc_, sizeof(Node)));
    allocator_traits::construct(alloc_, def_leaf_);
    root_ = def_leaf_;
    cnt_nodes_ = 0;
    alloc_ = Allocator();
    comp_ = Compare();
  }

  Tree(const Tree &other) : Tree() {
    for (auto i = other.Begin(); i != other.End(); ++i) {
      Insert(*i);
    }
  }
  Tree(Tree &&other) {
    std::swap(root_, other.root_);
    std::swap(def_leaf_, other.def_leaf_);
    std::swap(cnt_nodes_, other.cnt_nodes_);
    std::swap(alloc_, other.alloc_);
    std::swap(comp_, other.comp_);
  }
  Tree &operator=(Tree &&other) {
    if (&other != this) {
      if (root_ != def_leaf_) Clear();
      if (def_leaf_) {
        allocator_traits::destroy(alloc_, (def_leaf_));
        allocator_traits::deallocate(
            alloc_, reinterpret_cast<pointer_traits>(def_leaf_), sizeof(Node));
      }
      root_ = nullptr;
      def_leaf_ = nullptr;
      cnt_nodes_ = 0;
      std::swap(root_, other.root_);
      std::swap(def_leaf_, other.def_leaf_);
      std::swap(cnt_nodes_, other.cnt_nodes_);
      std::swap(alloc_, other.alloc_);
      std::swap(comp_, other.comp_);
    }
    return *this;
  }

  Tree &operator=(const Tree &other) {
    if (&other != this) {
      if (!IsEmpty()) ClearTree(root_);
      for (auto i = other.Begin(); i != other.End(); ++i) {
        Insert(*i);
      }
    }
    return *this;
  }

  ~Tree() {
    if (root_ != def_leaf_) Clear();
    if (def_leaf_) {
      allocator_traits::destroy(alloc_, (def_leaf_));
      allocator_traits::deallocate(
          alloc_, reinterpret_cast<pointer_traits>(def_leaf_), sizeof(Node));
    }
  }
  void ClearTree(Node *node);
  void Clear() {
    if (root_ && cnt_nodes_) ClearTree(root_);
  }
  pointer Search(T key) { return Search(root_, key); }
  pointer Search(pointer node, T key) const;
  void Print();
  iterator Insert(const T &item_);
  void Remove(const T &key);
  [[nodiscard]] size_t Size() const { return cnt_nodes_; }
  [[nodiscard]] bool IsEmpty() const { return !cnt_nodes_; }
  pointer NodeMin(pointer root) const;
  pointer NodeMax(pointer root) const;
  [[nodiscard]] size_t MaxSize() const { return alloc_.max_size() / 10; }
  iterator Begin() const { return iterator(this, NodeMin(root_)); }
  iterator End() const { return iterator(this, def_leaf_); }
  bool inline IsDefLeaf(Node *node) const { return node == def_leaf_; }

  Tree(std::initializer_list<T> const &items) : Tree() {
    for (auto &i : items) Insert(i);
  }

 private:
  pointer def_leaf_ = nullptr;
  pointer root_ = nullptr;
  size_t cnt_nodes_ = 0;
  Allocator alloc_{};
  Compare comp_;

  void InsertRB(Node *x);
  void RotateLeft(Node *node);
  void RotateRight(Node *node);
  void DeleteRB(Node *x);
  void Print(Node *node, const std::string &prefix = "",
             bool isLeft = true) const;
  void SwapColor(Node *node);
  void DeleteIsLeftChild(Node *&x);
  void DeleteIsRightChild(Node *&x);
};

/*
 *   (node->parent_)
 *        |
 *       (node)
 *      /     \
 *     x       y
 *    / \     / \
 *          mid
 */
template <class T, class Compare, class Allocator>
void Tree<T, Compare, Allocator>::RotateLeft(Node *node) {
  auto y = node->right_;
  auto mid = y->left_;
  node->right_ = mid;
  if (y != def_leaf_) {
    y->parent_ = node->parent_;
    if (y->left_ != def_leaf_) y->left_->parent_ = node;
  }
  if (node->parent_) {
    node->IsLeftChild() ? node->parent_->left_ = y : node->parent_->right_ = y;
  } else {
    root_ = y;
  }
  y->left_ = node;
  node->parent_ = y;
}

/*
 *   (node->parent_)
 *        |
 *       (node)
 *      /     \
 *     x       y
 *    / \
 *        mid
 */
template <class T, class Compare, class Allocator>
void Tree<T, Compare, Allocator>::RotateRight(Node *node) {
  auto x = node->left_;
  auto mid = x->right_;
  node->left_ = mid;
  if (!IsDefLeaf(x)) {
    x->parent_ = node->parent_;
    if (!IsDefLeaf(mid)) mid->parent_ = node;
  }
  if (node->parent_) {
    node->IsRightChild() ? node->parent_->right_ = x : node->parent_->left_ = x;
  } else {
    root_ = x;
  }
  x->right_ = node;
  node->parent_ = x;
}
template <class T, class Compare, class Allocator>
void Tree<T, Compare, Allocator>::ClearTree(Node *node) {
  if (node && !IsDefLeaf(node)) {
    ClearTree(node->left_);
    ClearTree(node->right_);
    allocator_traits::destroy(alloc_, (node));
    allocator_traits::deallocate(alloc_, reinterpret_cast<pointer_traits>(node),
                                 sizeof(Node));
  }
  cnt_nodes_ = 0;
}
template <class T, class Compare, class Allocator>
void Tree<T, Compare, Allocator>::Print() {
  if (!this->root_ || !cnt_nodes_) {
    std::cout << "empty RBtree\n";
  } else
    Print(this->root_);
}

template <class T, class Compare, class Allocator>
void Tree<T, Compare, Allocator>::Print(Node *node, const std::string &prefix,
                                        bool isLeft) const {
  if (!node || IsDefLeaf(node)) {
    return;
  }
  std::cout << prefix;
  std::cout << (isLeft ? "L├── " : "R└── ");
  std::cout << node->item_ << "(" << node->color_ << ")" << std::endl;

  Print(node->left_, prefix + (isLeft ? " │   " : "    "), true);
  Print(node->right_, prefix + (isLeft ? " │   " : "    "), false);
}

template <class T, class Compare, class Allocator>
typename Tree<T, Compare, Allocator>::iterator
Tree<T, Compare, Allocator>::Insert(const T &item_) {
  Node *node = root_;
  Node *parent_ = nullptr;
  while (!IsDefLeaf(node)) {
    parent_ = node;
    node = comp_(item_, node->item_) ? node->left_ : node->right_;
  }
  node = reinterpret_cast<Node *>(
      allocator_traits::allocate(alloc_, sizeof(Node)));
  allocator_traits::construct(alloc_, node, item_, parent_);
  node->left_ = node->right_ = def_leaf_;

  if (parent_)
    (comp_(item_, parent_->item_)) ? parent_->left_ = node
                                   : parent_->right_ = node;
  else
    root_ = node;

  InsertRB(node);
  cnt_nodes_++;
  return iterator(this, node);
}

template <class T, class Compare, class Allocator>
void Tree<T, Compare, Allocator>::SwapColor(Tree::Node *node) {
  node->color_ = RED;
  node->right_->color_ = node->left_->color_ = BLACK;
}

template <class T, class Compare, class Allocator>
void Tree<T, Compare, Allocator>::InsertRB(Node *x) {
  while (x != root_ && x->parent_->color_ == RED) {
    auto father = x->parent_;
    auto grandparent = father->parent_;
    if (grandparent->left_ && grandparent->right_ &&
        grandparent->left_->color_ == RED &&
        grandparent->right_->color_ == RED) {
      SwapColor(grandparent);
      x = std::move(grandparent);
    } else {
      if (father->IsLeftChild()) {
        if (x->IsRightChild()) {
          x = x->parent_;
          RotateLeft(x);
        }
        x->parent_->color_ = BLACK;
        x->parent_->parent_->color_ = RED;
        RotateRight(grandparent);
      } else {
        if (x->IsLeftChild()) {
          x = x->parent_;
          RotateRight(x);
        }
        x->parent_->color_ = BLACK;
        x->parent_->parent_->color_ = RED;
        RotateLeft(grandparent);
      }
    }
  }
  root_->color_ = BLACK;
}

template <class T, class Compare, class Allocator>
typename Tree<T, Compare, Allocator>::pointer
Tree<T, Compare, Allocator>::Search(Node *node, T key) const {
  if (!node || IsDefLeaf(node) ||
      (!comp_(node->item_, key) && !comp_(key, node->item_)))
    return node;
  else if (!comp_(key, node->item_))
    return Search(node->right_, key);
  else
    return Search(node->left_, key);
}
template <class T, class Compare, class Allocator>
void Tree<T, Compare, Allocator>::Remove(const T &key) {
  Node *node = Search(key);
  if (!node || IsDefLeaf(node)) {
    return;
  }
  Node *child = nullptr, *dnode = nullptr;
  if (IsDefLeaf(node->left_) || IsDefLeaf(node->right_)) {
    dnode = node;
  } else {
    dnode = NodeMin(node->right_);
    node->item_ = dnode->item_;
  }

  if (!IsDefLeaf(dnode->left_)) {
    child = dnode->left_;
  } else {
    child = dnode->right_;
  }

  child->parent_ = dnode->parent_;
  if (dnode->parent_) {
    if (dnode->IsLeftChild()) {
      dnode->parent_->left_ = child;
    } else {
      dnode->parent_->right_ = child;
    }
  } else {
    root_ = child;
  }
  if (dnode->color_ == BLACK) DeleteRB(child);
  allocator_traits::deallocate(alloc_, reinterpret_cast<pointer_traits>(dnode),
                               sizeof(Node));
  cnt_nodes_--;
}
template <class T, class Compare, class Allocator>
void Tree<T, Compare, Allocator>::DeleteIsLeftChild(Node *&x) {
  auto brother = x->parent_->right_;
  if (brother->color_ == RED) {
    brother->color_ = BLACK;
    x->parent_->color_ = RED;
    RotateLeft(x->parent_);
    brother = x->parent_->right_;
  }
  if (brother->left_->color_ == BLACK && brother->right_->color_ == BLACK) {
    brother->color_ = RED;
    x = x->parent_;
  } else {
    if (brother->right_->color_ == BLACK) {
      brother->left_->color_ = BLACK;
      brother->color_ = RED;
      RotateRight(brother);
      brother = x->parent_->right_;
    }
    brother->color_ = x->parent_->color_;
    x->parent_->color_ = BLACK;
    brother->right_->color_ = BLACK;
    RotateLeft(x->parent_);
    x = root_;
  }
}
template <class T, class Compare, class Allocator>
void Tree<T, Compare, Allocator>::DeleteIsRightChild(Node *&x) {
  auto brother = x->parent_->left_;
  if (brother->color_ == RED) {
    brother->color_ = BLACK;
    x->parent_->color_ = RED;
    RotateRight(x->parent_);
    brother = x->parent_->left_;
  }
  if (brother->right_->color_ == BLACK && brother->left_->color_ == BLACK) {
    brother->color_ = RED;
    x = x->parent_;
  } else {
    if (brother->left_->color_ == BLACK) {
      brother->right_->color_ = BLACK;
      brother->color_ = RED;
      RotateLeft(brother);
      brother = x->parent_->left_;
    }
    brother->color_ = x->parent_->color_;
    x->parent_->color_ = BLACK;
    brother->left_->color_ = BLACK;
    RotateRight(x->parent_);
    x = root_;
  }
}

template <class T, class Compare, class Allocator>
void Tree<T, Compare, Allocator>::DeleteRB(Node *x) {
  while (x != root_ && x->color_ == BLACK) {
    x->IsLeftChild() ? DeleteIsLeftChild(x) : DeleteIsRightChild(x);
    def_leaf_->parent_ = nullptr;
  }
  x->color_ = BLACK;
}

template <class T, class Compare, class Allocator>
typename Tree<T, Compare, Allocator>::pointer
Tree<T, Compare, Allocator>::NodeMin(Node *root) const {
  auto node = root;
  if (!IsDefLeaf(root_)) {
    while (node->left_ && !IsDefLeaf(node->left_)) {
      node = node->left_;
    }
  }
  return node;
}
template <class T, class Compare, class Allocator>
typename Tree<T, Compare, Allocator>::pointer
Tree<T, Compare, Allocator>::NodeMax(Node *root) const {
  auto node = root;
  if (!IsDefLeaf(root_)) {
    while (node->right_ && !IsDefLeaf(node->right_)) {
      node = node->right_;
    }
  }
  return node;
}
};      // namespace s21
#endif  // CPP2_S21_CONTAINERS_1_SRC_S21_TREE_H_
