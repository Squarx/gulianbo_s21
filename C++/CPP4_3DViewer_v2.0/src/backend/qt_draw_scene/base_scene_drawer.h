#ifndef INC_3DVIEWER_SRC_BACKEND_QT_DRAW_SCENE_BASE_SCENE_DRAWER_H
#define INC_3DVIEWER_SRC_BACKEND_QT_DRAW_SCENE_BASE_SCENE_DRAWER_H

#include <QMouseEvent>
#include <QOpenGLBuffer>
#include <QOpenGLFunctions>
#include <QOpenGLFunctions_4_5_Core>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLWidget>

#include "../../backend/scene/scene.h"
#include "../../internal/internal.h"

namespace s21 {

class BaseSceneDrawer : public QOpenGLWidget, protected QOpenGLFunctions {
 public:
  virtual void DrawScene(Scene scene) = 0;

  virtual void SetVertexColor(double red, double green, double blue) = 0;
  virtual void SetVertexRedColor(double red) = 0;
  virtual void SetVertexGreenColor(double green) = 0;
  virtual void SetVertexBlueColor(double blue) = 0;

  virtual void SetEdgesColor(double red, double green, double blue) = 0;
  virtual void SetEdgesRedColor(double red) = 0;
  virtual void SetEdgesGreenColor(double green) = 0;
  virtual void SetEdgesBlueColor(double blue) = 0;

  virtual void SetBgColor(double red, double green, double blue) = 0;
  virtual void SetBgRedColor(double red) = 0;
  virtual void SetBgGreenColor(double green) = 0;
  virtual void SetBgBlueColor(double blue) = 0;

  virtual void SetVertexesType(Types type) = 0;
  virtual void SetLinesType(Types type) = 0;

  virtual void SetIsParallel(bool is_parallel) = 0;
  virtual void SetLineWidth(float line_width) = 0;
  virtual void SetPointSize(float line_width) = 0;
  virtual void ResetFocus() = 0;

 protected:
  virtual void initializeGL() override = 0;
  virtual void resizeGL(int w, int h) override = 0;
  virtual void paintGL() override = 0;
  virtual void mouseMoveEvent(QMouseEvent *mo) override = 0;
  virtual void mousePressEvent(QMouseEvent *mo) override = 0;
  virtual void wheelEvent(QWheelEvent *event) override = 0;
};

}  // namespace s21

#endif  // INC_3DVIEWER_SRC_BACKEND_QT_DRAW_SCENE_BASE_SCENE_DRAWER_H
