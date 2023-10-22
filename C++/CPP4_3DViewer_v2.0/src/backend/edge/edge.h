#ifndef INC_3D_VIEWER_SRC_BACKEND_EDGE_EDGE_H_
#define INC_3D_VIEWER_SRC_BACKEND_EDGE_EDGE_H_

#include "../vertex/vertex.h"

namespace s21 {

class Edge {
 public:
  Edge(unsigned int begin, unsigned int end)
      : begin_index_(begin), end_index_(end) {}

  [[nodiscard]] unsigned int GetBegin() const { return begin_index_; }
  [[nodiscard]] unsigned int GetEnd() const { return end_index_; }

 private:
  unsigned int begin_index_;
  unsigned int end_index_;
};

}  // namespace s21

#endif  // INC_3D_VIEWER_SRC_BACKEND_EDGE_EDGE_H_
