#ifndef INC_3D_VIEWER_SRC_BACKEND_FIGURE_FIGURE_H_
#define INC_3D_VIEWER_SRC_BACKEND_FIGURE_FIGURE_H_

#include <cmath>
#include <vector>

#include "../edge/edge.h"

namespace s21 {

class Figure {
 public:
  void AddVertex(Vertex vertex);
  void AddEdge(Edge edge);

  void MoveVertexArray(double x, double y, double z);
  void ScaleVertexArray(double x, double y, double z);
  void RotateVertexArray(double x, double y, double z);

  void NormMoveVertexArray(double x, double y, double z);
  void NormScaleVertexArray(double x);

  void UpdateDoubles();

  [[nodiscard]] std::vector<Vertex> GetVertices() const;
  [[nodiscard]] std::vector<double>& GetVerticesDouble();
  [[nodiscard]] std::vector<unsigned int> GetEdgesInt();
  [[nodiscard]] std::vector<Edge> GetEdges();

  void ClearFigure();

 private:
  double prev_x = 0;
  double prev_y = 0;
  double prev_z = 0;

  double prev_scale_x = 1;
  double prev_scale_y = 1;
  double prev_scale_z = 1;

  double prev_rx = 0;
  double prev_ry = 0;
  double prev_rz = 0;

  std::vector<Vertex> vertices_;
  std::vector<Edge> edges_;
  std::vector<double> vertices_double_;
  std::vector<unsigned int> edges_int_;
};

}  // namespace s21

#endif  // INC_3D_VIEWER_SRC_BACKEND_FIGURE_FIGURE_H_
