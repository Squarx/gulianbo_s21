#include "vertex_parser.h"

namespace s21 {

void VertexParser::Parce(const std::string& line, Figure& figure) {
  std::string shifted_line = line.substr(2);
  std::istringstream iss(shifted_line);

  std::vector<double> coord((std::istream_iterator<double>(iss)),
                            std::istream_iterator<double>());

  if (coord.size() != 3) {
    throw std::runtime_error("Invalid vertex");
  }

  figure.AddVertex(Vertex(coord[0], coord[1], coord[2]));
}

}  // namespace s21
