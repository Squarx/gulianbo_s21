#ifndef INC_3D_VIEWER_SRC_BACKEND_STRATEGY_FACETS_PARCER_H
#define INC_3D_VIEWER_SRC_BACKEND_STRATEGY_FACETS_PARCER_H

#include <iterator>

#include "abstract_parcer.h"

namespace s21 {

class FacetsParser : public AbstractParcer {
 public:
  FacetsParser() = default;

  void Parce(const std::string &line, Figure &figure) override;

 private:
  long long first_id_ = -1;
  long long prev_id_{};
  long long v_coord_{};
  std::string num_{};
};

}  // namespace s21

#endif  // INC_3D_VIEWER_SRC_BACKEND_STRATEGY_FACETS_PARCER_H
