#include "scene.h"

namespace s21 {

std::vector<Figure> Scene::GetFigures() { return figures_; }

void Scene::MoveFigures(double x, double y, double z) {
  for (Figure& f : figures_) {
    f.MoveVertexArray(x, y, z);
    f.UpdateDoubles();
  }
}

void Scene::ScaleFigures(double x, double y, double z) {
  for (Figure& f : figures_) {
    f.ScaleVertexArray(x, y, z);
    f.UpdateDoubles();
  }
}

void Scene::NormMoveFigures(double x, double y, double z) {
  for (Figure& f : figures_) {
    f.NormMoveVertexArray(x, y, z);
    f.UpdateDoubles();
  }
}

void Scene::NormScaleFigures(double x) {
  for (Figure& f : figures_) {
    f.NormScaleVertexArray(x);
    f.UpdateDoubles();
  }
}

void Scene::RoatateFigures(double x, double y, double z) {
  for (Figure& f : figures_) {
    f.RotateVertexArray(x, y, z);
    f.UpdateDoubles();
  }
}

void Scene::AddFigure(const Figure& f) { figures_.push_back(f); }

void Scene::ClearScene() { figures_.clear(); }

}  // namespace s21
