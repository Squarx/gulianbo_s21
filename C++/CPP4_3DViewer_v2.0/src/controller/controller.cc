#include "controller.h"

namespace s21 {

void Controller::MoveFigure(double x, double y, double z) {
  FacadeOperationResult res = fac_->MoveScene(x, y, z);

  if (!res.IsSuccess()) {
    throw std::runtime_error(res.GetErrorMessage());
  }
}

void Controller::RotateFigure(double x, double y, double z) {
  FacadeOperationResult res = fac_->RotateScene(x, y, z);

  if (!res.IsSuccess()) {
    throw std::runtime_error(res.GetErrorMessage());
  }
}

void Controller::ScaleFigure(double x, double y, double z) {
  FacadeOperationResult res = fac_->ScaleScene(x, y, z);

  if (!res.IsSuccess()) {
    throw std::runtime_error(res.GetErrorMessage());
  }
}

void Controller::LoadFigure(const std::string& path) {
  FacadeOperationResult res = fac_->LoadScene(path);

  if (!res.IsSuccess()) {
    throw std::runtime_error(res.GetErrorMessage());
  }
}

void Controller::DrawScene() {
  FacadeOperationResult res = fac_->DrawScene();

  if (!res.IsSuccess()) {
    throw std::runtime_error(res.GetErrorMessage());
  }
}

NormParams Controller::LoadParams() { return fac_->GetParams(); }

QtDrawScene* Controller::GetView() { return fac_->GetQtDraw(); }
size_t Controller::GetVerticesCount() { return fac_->GetVerticesCount(); }
size_t Controller::GetEdgesCount() { return fac_->GetEdgesCount(); }

}  // namespace s21
