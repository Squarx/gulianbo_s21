#ifndef INC_3D_VIEWER_STRATEGY_VERTEX_PARSER_H
#define INC_3D_VIEWER_STRATEGY_VERTEX_PARSER_H

#include <iterator>

#include "abstract_parcer.h"

namespace s21 {

class VertexParser : public AbstractParcer {
 public:
  VertexParser() = default;

  void Parce(const std::string& line, Figure& figure) override;
};

}  // namespace s21

#endif  // INC_3D_VIEWER_STRATEGY_VERTEX_PARSER_H
