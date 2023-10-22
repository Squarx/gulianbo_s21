#include "facets_parcer.h"

namespace s21 {

void FacetsParser::Parce(const std::string &line, Figure &figure) {
  std::string token_str = line.substr(2);
  std::istringstream iss(token_str);
  std::vector<std::string> coord((std::istream_iterator<std::string>(iss)),
                                 std::istream_iterator<std::string>());

  if (coord.size() < 2) {
    throw std::runtime_error("To low vertexes");
  }

  for (const std::string &token : coord) {
    if (!(isdigit(token[0]) || (token[0] == '-' && isdigit(token[1])))) {
      throw std::runtime_error("Incorrect token. No vertex in");
    }

    std::istringstream iss1(token);
    getline(iss1, num_, '/');

    //  Process Vertex Indexes [0]
    v_coord_ = std::stoi(num_);
    v_coord_ += (v_coord_ <= 0)
                    ? static_cast<long long>(figure.GetVertices().size())
                    : (-1);

    if (first_id_ >= 0) {
      figure.AddEdge(Edge(prev_id_, v_coord_));
    } else {
      first_id_ = v_coord_;
    }

    prev_id_ = v_coord_;
  }

  figure.AddEdge(Edge(prev_id_, first_id_));
  first_id_ = -1;
}

}  // namespace s21
