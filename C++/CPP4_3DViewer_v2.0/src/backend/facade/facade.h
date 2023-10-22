#ifndef INC_3D_VIEWER_SRC_BACKEND_FACADE_FACADE_H_
#define INC_3D_VIEWER_SRC_BACKEND_FACADE_FACADE_H_

#include "../facade_operations/facade_operation_result.h"
#include "../file_reader/base_filereader.h"
#include "../file_reader/file_reader.h"
#include "../normalization_parameters/norm_params.h"
#include "../qt_draw_scene/qt_draw_scene.h"
#include "../scene/scene.h"

namespace s21 {

class Facade {
 public:
  Facade() : filereader_(std::make_shared<FileReader>()) {}

  FacadeOperationResult MoveScene(double x, double y, double z);

  FacadeOperationResult RotateScene(double x, double y, double z);

  FacadeOperationResult ScaleScene(double x, double y, double z);

  FacadeOperationResult LoadScene(const std::string& path);

  size_t GetVerticesCount();
  size_t GetEdgesCount();

  FacadeOperationResult DrawScene();

  NormParams GetParams();

  QtDrawScene* GetQtDraw();

  Scene& GetScene() { return scene_; }

 private:
  std::shared_ptr<BaseFileReader> filereader_{};
  Scene scene_{};
  NormParams params_{};

  FacadeOperationResult result_{};
  QSharedPointer<QtDrawScene> v_;
  QtDrawScene viewer_;
};

}  // namespace s21

#endif  // INC_3D_VIEWER_SRC_BACKEND_FACADE_FACADE_H_
