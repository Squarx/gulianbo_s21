#ifndef INC_3D_VIEWER_SRC_BACKEND_VERTEX_VERTEX_H_
#define INC_3D_VIEWER_SRC_BACKEND_VERTEX_VERTEX_H_

#include <cmath>

namespace s21 {

class Vertex {
  struct Point {
    Point(double x1, double y1, double z1) : x(x1), y(y1), z(z1) {}
    double x;
    double y;
    double z;
  };

 public:
  Vertex(double x, double y, double z) : position_(x, y, z) {}
  Point GetPosition() { return position_; }

  void TranslateX(double value);
  void TranslateY(double value);
  void TranslateZ(double value);

  void MoveX(double value) { position_.x += value; }
  void MoveY(double value) { position_.y += value; }
  void MoveZ(double value) { position_.z += value; }

  void RotateX(double value);
  void RotateY(double value);
  void RotateZ(double value);

  void Scale(double x, double y, double z);

 private:
  Point position_;
};

}  // namespace s21

#endif  // INC_3D_VIEWER_SRC_BACKEND_VERTEX_VERTEX_H_
