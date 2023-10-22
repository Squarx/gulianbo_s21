#ifndef INC_3D_VIEWER_SRC_BACKEND_SCENE_SCENE_H_
#define INC_3D_VIEWER_SRC_BACKEND_SCENE_SCENE_H_

#include <vector>

#include "../figure/figure.h"

namespace s21 {

class Scene {
 public:
  std::vector<Figure> GetFigures();

  void MoveFigures(double x, double y, double z);
  void ScaleFigures(double x, double y, double z);
  void RoatateFigures(double x, double y, double z);

  void NormMoveFigures(double x, double y, double z);
  void NormScaleFigures(double x);

  void AddFigure(const Figure& f);
  void ClearScene();

 private:
  std::vector<Figure> figures_;
};

}  // namespace s21

#endif  // INC_3D_VIEWER_SRC_BACKEND_SCENE_SCENE_H_
