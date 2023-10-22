#include "facade.h"

namespace s21 {

FacadeOperationResult Facade::MoveScene(double x, double y, double z) {
  try {
    scene_.MoveFigures(x, y, z);
    result_.SetSuccess(true);
  } catch (const std::exception& e) {
    std::string what = e.what();
    std::string err = "s21 " + what;

    result_.SetErrorMessage(err);
    result_.SetSuccess(false);
  } catch (...) {
    std::string err = "s21 Unknown error";

    result_.SetErrorMessage(err);
    result_.SetSuccess(false);
  }

  return result_;
}

FacadeOperationResult Facade::RotateScene(double x, double y, double z) {
  try {
    scene_.RoatateFigures(x, y, z);
    result_.SetSuccess(true);
  } catch (const std::exception& e) {
    std::string what = e.what();
    std::string err = "s21 " + what;

    result_.SetErrorMessage(err);
    result_.SetSuccess(false);
  } catch (...) {
    std::string err = "s21 Unknown error";

    result_.SetErrorMessage(err);
    result_.SetSuccess(false);
  }

  return result_;
}

FacadeOperationResult Facade::ScaleScene(double x, double y, double z) {
  try {
    scene_.ScaleFigures(x, y, z);
    result_.SetSuccess(true);
  } catch (const std::exception& e) {
    std::string what = e.what();
    std::string err = "s21 " + what;

    result_.SetErrorMessage(err);
    result_.SetSuccess(false);
  } catch (...) {
    std::string err = "s21 Unknown error";

    result_.SetErrorMessage(err);
    result_.SetSuccess(false);
  }

  return result_;
}

FacadeOperationResult Facade::LoadScene(const std::string& path) {
  try {
    filereader_.get()->SetFilePath(path);
    scene_ = filereader_.get()->ReadScene();

    params_.CalculateParams(scene_.GetFigures()[0]);
    scene_.NormMoveFigures(-params_.x_mean, -params_.y_mean, -params_.z_mean);
    scene_.NormScaleFigures(params_.scale_factor);

    result_.SetSuccess(true);
  } catch (const std::exception& e) {
    std::string what = e.what();
    std::string err = "s21 " + what;

    result_.SetErrorMessage(err);
    result_.SetSuccess(false);
  } catch (...) {
    std::string err = "s21 Unknown error";

    result_.SetErrorMessage(err);
    result_.SetSuccess(false);
  }

  return result_;
}

FacadeOperationResult Facade::DrawScene() {
  try {
    viewer_.DrawScene(scene_);
    result_.SetSuccess(true);
  } catch (const std::exception& e) {
    std::string what = e.what();
    std::string err = "s21 " + what;

    result_.SetErrorMessage(err);
    result_.SetSuccess(false);
  } catch (...) {
    std::string err = "s21 Unknown error";

    result_.SetErrorMessage(err);
    result_.SetSuccess(false);
  }

  return result_;
}

QtDrawScene* Facade::GetQtDraw() { return &viewer_; }

NormParams Facade::GetParams() { return params_; }

size_t Facade::GetVerticesCount() { return viewer_.GetVerticesCount(); }

size_t Facade::GetEdgesCount() { return viewer_.GetEdgesCount(); }

}  // namespace s21
