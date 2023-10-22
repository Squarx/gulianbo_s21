#include "norm_params.h"

namespace s21 {

void NormParams::ClearParams() {
  x_max = x_min = y_max = y_min = z_max = z_min = scale_factor = 0;
}

void NormParams::CalculateParams(const Figure& f) {
  double margins = 0.25f;
  auto vertices = f.GetVertices();

  x_min = x_max = vertices.at(0).GetPosition().x;
  y_min = y_max = vertices.at(0).GetPosition().y;
  z_min = z_max = vertices.at(0).GetPosition().z;

  for (auto v : vertices) {
    if (v.GetPosition().x < x_min) {
      x_min = v.GetPosition().x;
    }

    if (v.GetPosition().x > x_max) {
      x_max = v.GetPosition().x;
    }

    if (v.GetPosition().y < y_min) {
      y_min = v.GetPosition().y;
    }

    if (v.GetPosition().y > y_max) {
      y_max = v.GetPosition().y;
    }

    if (v.GetPosition().z < z_min) {
      z_min = v.GetPosition().z;
    }

    if (v.GetPosition().z > z_max) {
      z_max = v.GetPosition().z;
    }
  }

  x_mean = (x_max + x_min) / 2.0;
  y_mean = (y_max + y_min) / 2.0;
  z_mean = (z_max + z_min) / 2.0;
  max_distance =
      std::max(std::max(x_max - x_min, y_max - y_min), z_max - z_min);

  scale_factor = 0.8 / (max_distance * margins);
}

void NormParams::UpdateFov(double n_fov) { fov = n_fov; }

}  // namespace s21
