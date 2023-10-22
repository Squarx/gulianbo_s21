#include "figure.h"

namespace s21 {
void Figure::AddVertex(Vertex vertex) {
  vertices_.push_back(vertex);
  vertices_double_.push_back(vertex.GetPosition().x);
  vertices_double_.push_back(vertex.GetPosition().y);
  vertices_double_.push_back(vertex.GetPosition().z);
}

void Figure::MoveVertexArray(double x, double y, double z) {
  double delta_x = x - prev_x;
  double delta_y = y - prev_y;
  double delta_z = z - prev_z;
  for (Vertex& v : vertices_) {
    v.MoveX(delta_x);
    v.MoveY(delta_y);
    v.MoveZ(delta_z);
  }
  prev_x = x;
  prev_y = y;
  prev_z = z;
}

void Figure::ScaleVertexArray(double x, double y, double z) {
  double ratio_x = x / prev_scale_x;
  double ratio_y = y / prev_scale_y;
  double ratio_z = z / prev_scale_z;
  for (Vertex& v : vertices_) {
    v.Scale(ratio_x, ratio_y, ratio_z);
  }
  prev_scale_x = x;
  prev_scale_y = y;
  prev_scale_z = z;
}

void Figure::NormMoveVertexArray(double x, double y, double z) {
  for (Vertex& v : vertices_) {
    v.MoveX(x);
    v.MoveY(y);
    v.MoveZ(z);
  }
}

void Figure::NormScaleVertexArray(double x) {
  double ratio = x;
  for (Vertex& v : vertices_) {
    v.Scale(ratio, ratio, ratio);
  }
}

void Figure::RotateVertexArray(double x, double y, double z) {
  double delta_x = x - prev_rx;
  double delta_y = y - prev_ry;
  double delta_z = z - prev_rz;

  for (Vertex& v : vertices_) {
    v.RotateX(delta_x);
    v.RotateY(delta_y);
    v.RotateZ(delta_z);
  }

  prev_rx = x;
  prev_ry = y;
  prev_rz = z;
}

void Figure::AddEdge(Edge edge) {
  edges_.push_back(edge);
  edges_int_.push_back(edge.GetBegin());
  edges_int_.push_back(edge.GetEnd());
}

void Figure::UpdateDoubles() {
  for (auto i = 0U; i < vertices_.size(); ++i) {
    vertices_double_[0 + 3 * i] = vertices_[i].GetPosition().x;
    vertices_double_[1 + 3 * i] = vertices_[i].GetPosition().y;
    vertices_double_[2 + 3 * i] = vertices_[i].GetPosition().z;
  }
}

[[nodiscard]] std::vector<Vertex> Figure::GetVertices() const {
  return vertices_;
}

[[nodiscard]] std::vector<double>& Figure::GetVerticesDouble() {
  return vertices_double_;
}
[[nodiscard]] std::vector<unsigned int> Figure::GetEdgesInt() {
  return edges_int_;
}
[[nodiscard]] std::vector<Edge> Figure::GetEdges() { return edges_; }

void Figure::ClearFigure() {
  vertices_.clear();
  edges_.clear();
  vertices_double_.clear();
  edges_int_.clear();
}
}  // namespace s21
