#ifndef INC_3D_VIEWER_SRC_BACKEND_STRATEGY_ABSTRACT_PARCER_H
#define INC_3D_VIEWER_SRC_BACKEND_STRATEGY_ABSTRACT_PARCER_H

#include <sstream>
#include <vector>

#include "../figure/figure.h"

namespace s21 {

class AbstractParcer {
 public:
  virtual void Parce(const std::string& line, Figure& figure) = 0;
};

}  // namespace s21

#endif  // INC_3D_VIEWER_SRC_BACKEND_STRATEGY_ABSTRACT_PARCER_H
