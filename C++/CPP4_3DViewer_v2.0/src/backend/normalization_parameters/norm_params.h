#ifndef INC_3D_VIEWER_SRC_BACKEND_NORMALIZATION_PARAMETERS_NORM_PARAMS_H
#define INC_3D_VIEWER_SRC_BACKEND_NORMALIZATION_PARAMETERS_NORM_PARAMS_H

#include "../figure/figure.h"

namespace s21 {

class NormParams {
 public:
  void ClearParams();
  void CalculateParams(const Figure& f);

  void UpdateFov(double n_fov);

  double x_max{}, x_min{};
  double y_max{}, y_min{};
  double z_max{}, z_min{};
  double x_mean{}, y_mean{}, z_mean{};
  double max_distance{};
  double aspect_screen = 16. / 9.;
  double fov = 60.0f;
  double scale_factor{};
};

}  // namespace s21

#endif  // INC_3D_VIEWER_SRC_BACKEND_NORMALIZATION_PARAMETERS_NORM_PARAMS_H
