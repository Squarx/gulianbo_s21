#include "vertex.h"

namespace s21 {

void Vertex::TranslateX(double value) { position_.x += value; }
void Vertex::TranslateY(double value) { position_.y += value; }
void Vertex::TranslateZ(double value) { position_.z += value; }

void Vertex::RotateX(double value) {
  const double value_cos = cos(value * M_PI / 180);
  const double value_sin = sin(value * M_PI / 180);

  double new_y = position_.y * value_cos - position_.z * value_sin;
  double new_z = position_.y * value_sin + position_.z * value_cos;

  position_.y = new_y;
  position_.z = new_z;
}

void Vertex::RotateY(double value) {
  const double value_cos = cos(value * M_PI / 180);
  const double value_sin = sin(value * M_PI / 180);

  double new_x = position_.x * value_cos + position_.z * value_sin;
  double new_z = -position_.x * value_sin + position_.z * value_cos;

  position_.x = new_x;
  position_.z = new_z;
}

void Vertex::RotateZ(double value) {
  const double value_cos = cos(value * M_PI / 180);
  const double value_sin = sin(value * M_PI / 180);
  double new_x = position_.x * value_cos - position_.y * value_sin;
  double new_y = position_.x * value_sin + position_.y * value_cos;

  position_.x = new_x;
  position_.y = new_y;
}

void Vertex::Scale(double x, double y, double z) {
  position_.x *= x;
  position_.y *= y;
  position_.z *= z;
}

}  // namespace s21
