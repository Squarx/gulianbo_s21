#ifndef INC_3D_VIEWER_SRC_BACKEND_QT_DRAW_SCENE_QT_DRAW_SCENE_H
#define INC_3D_VIEWER_SRC_BACKEND_QT_DRAW_SCENE_QT_DRAW_SCENE_H

#include <qfiledialog.h>

#include <QFileDialog>
#include <QMatrix4x4>
#include <QMouseEvent>
#include <QOpenGLBuffer>
#include <QOpenGLFunctions>
#include <QOpenGLFunctions_4_5_Core>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLWidget>
#include <QWidget>

#include "../../backend/scene/scene.h"
#include "base_scene_drawer.h"
#include "qopenglbuffer.h"
#include "qopenglvertexarrayobject.h"

class QtDrawScene : public s21::BaseSceneDrawer {
  Q_OBJECT

 public:
  QtDrawScene();
  ~QtDrawScene() {}

  void DrawScene(s21::Scene scene) override;

  void SetScale(double s) { scale_ = s; }
  double GetScale() { return scale_; }

  void SetVertexColor(double red, double green, double blue) override;
  void SetVertexRedColor(double red) override;
  void SetVertexGreenColor(double green) override;
  void SetVertexBlueColor(double blue) override;

  void SetEdgesColor(double red, double green, double blue) override;
  void SetEdgesRedColor(double red) override;
  void SetEdgesGreenColor(double green) override;
  void SetEdgesBlueColor(double blue) override;

  void SetBgColor(double red, double green, double blue) override;
  void SetBgRedColor(double red) override;
  void SetBgGreenColor(double green) override;
  void SetBgBlueColor(double blue) override;

  void SetIsParallel(bool is_parallel) override;
  void SetLineWidth(float line_width) override;
  void SetPointSize(float point_size) override;

  void SetVertexesType(Types type) override;
  void SetLinesType(Types type) override;

  void ResetFocus() override {
    x_rot_ = y_rot_ = 0;
    scale_ = 1;
  }

  size_t GetVerticesCount();
  size_t GetEdgesCount();

 protected:
  void initializeGL() override;
  void resizeGL(int w, int h) override;
  void paintGL() override;
  void mouseMoveEvent(QMouseEvent *mo) override;
  void mousePressEvent(QMouseEvent *mo) override;
  void wheelEvent(QWheelEvent *event) override;

 private:
  GLuint size_ = 0;
  float x_rot_ = 0.0f;
  float y_rot_ = 0.0f;
  double scale_ = 1;

  double vertex_color_r_ = 0.0;
  double vertex_color_g_ = 0.0;
  double vertex_color_b_ = 0.0;

  double edges_color_r_ = 0.0;
  double edges_color_g_ = 0.0;
  double edges_color_b_ = 0.0;

  double bg_color_r_ = 0.0;
  double bg_color_g_ = 0.0;
  double bg_color_b_ = 0.0;

  bool is_parallel_ = false;

  float line_width_ = 1;
  float point_size_ = 1;

  float aspect_ratio_ = 1;

  Types line_type_ = Types::kSmooth;

  Types vertexes_type_;

  QPoint last_mouse_pos_;

  std::pair<std::vector<double>, std::vector<unsigned int>> draw_;

  QOpenGLVertexArrayObject vao_;
  QOpenGLBuffer vbo_;
  QOpenGLBuffer ibo_;

  QOpenGLBuffer vbo_points_;

  QMatrix4x4 projection_matrix_;
  QMatrix4x4 model_view_matrix_;

  void CreateObjectVAO();
  void SetUpMatrix();
  void PaintLines();
  void PaintPoints();

  void UpdateView();
};

#endif  // INC_3D_VIEWER_SRC_BACKEND_QT_DRAW_SCENE_QT_DRAW_SCENE_H
