#ifndef INC_3D_VIEWER_SRC_BACKEND_SOLVER_SOLVER_STRATEGY_H
#define INC_3D_VIEWER_SRC_BACKEND_SOLVER_SOLVER_STRATEGY_H

#include <memory>

#include "../strategy/abstract_parcer.h"
#include "../strategy/facets_parcer.h"
#include "../strategy/vertex_parser.h"

namespace s21 {

class SolverStrategy {
 public:
  SolverStrategy(const SolverStrategy& other) = delete;
  SolverStrategy(SolverStrategy&& other) = delete;
  void operator=(const SolverStrategy& other) = delete;

  ~SolverStrategy() = default;

  /* Accessing singleton */
  static std::shared_ptr<AbstractParcer> getInstance(const std::string& str) {
    if (str.compare(0, 2, "v ") == 0) {
      if (!vertex_parcer_) {
        vertex_parcer_ = std::make_shared<VertexParser>();
      }

      return vertex_parcer_;
    }

    if (str.compare(0, 2, "f ") == 0) {
      if (!facet_parcer_) {
        facet_parcer_ = std::make_shared<FacetsParser>();
      }

      return facet_parcer_;
    }

    return nullptr;
  }

 protected:
  SolverStrategy() {}

 private:
  static std::shared_ptr<AbstractParcer> vertex_parcer_;
  static std::shared_ptr<AbstractParcer> facet_parcer_;
};

}  // namespace s21

#endif  // INC_3D_VIEWER_SRC_BACKEND_SOLVER_SOLVER_STRATEGY_H
