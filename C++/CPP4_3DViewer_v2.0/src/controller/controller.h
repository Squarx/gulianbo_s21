#ifndef INC_3D_VIEWER_SRC_CONTROLLER_CONTROLLER_H_
#define INC_3D_VIEWER_SRC_CONTROLLER_CONTROLLER_H_

#include "../backend/facade/facade.h"
#include "../backend/qt_draw_scene/qt_draw_scene.h"

namespace s21 {

class Controller {
 public:
  explicit Controller(Facade *fac) : fac_(fac){};

  void MoveFigure(double x, double y, double z);

  void RotateFigure(double x, double y, double z);

  void ScaleFigure(double x, double y, double z);

  void LoadFigure(const std::string &path);

  size_t GetVerticesCount();
  size_t GetEdgesCount();

  QtDrawScene *GetView();

  void DrawScene();

  NormParams LoadParams();

  Scene &GetScene() { return fac_->GetScene(); }

 private:
  Facade *fac_;
};

}  // namespace s21

#endif  // INC_3D_VIEWER_SRC_CONTROLLER_CONTROLLER_H_
