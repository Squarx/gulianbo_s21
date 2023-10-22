#include "qt_draw_scene.h"

#include <QDir>
#include <QFileDialog>

QtDrawScene::QtDrawScene()
    : vbo_(QOpenGLBuffer::VertexBuffer), ibo_(QOpenGLBuffer::IndexBuffer) {}

void QtDrawScene::DrawScene(s21::Scene scene) {
  if (scene.GetFigures().size() > 0) {
    draw_ = std::make_pair(scene.GetFigures()[0].GetVerticesDouble(),
                           scene.GetFigures()[0].GetEdgesInt());
  }

  UpdateView();
}

size_t QtDrawScene::GetVerticesCount() { return draw_.first.size(); }

size_t QtDrawScene::GetEdgesCount() { return draw_.second.size(); }

void QtDrawScene::UpdateView() {
#ifdef __APPLE__
  CreateObjectVAO();
#else
  initializeGL();
#endif
  update();
}

void QtDrawScene::initializeGL() {
  last_mouse_pos_ = QPoint();
  initializeOpenGLFunctions();

#ifndef MACOS
  CreateObjectVAO();
#endif
}

void QtDrawScene::resizeGL(int w, int h) {
  glViewport(0, 0, w, h);

  aspect_ratio_ =
      static_cast<float>(static_cast<float>(w) / static_cast<float>(h));
}

void QtDrawScene::PaintLines() {
  if (line_type_ != kOff) {
    glColor3f(edges_color_r_, edges_color_g_, edges_color_b_);
    glLineWidth(line_width_);

    if (line_type_ == kStripple) {
      glLineStipple(4, 0x3333);
      glEnable(GL_LINE_STIPPLE);
    } else {
      glDisable(GL_LINE_STIPPLE);
    }

    glDrawElements(GL_LINES, size_, GL_UNSIGNED_INT, nullptr);
  }
}

void QtDrawScene::PaintPoints() {
  if (vertexes_type_ != kOff) {
    glColor3f(vertex_color_r_, vertex_color_g_, vertex_color_b_);

    if (vertexes_type_ == kCircles) {
      glEnable(GL_POINT_SMOOTH);
    } else {
      glDisable(GL_POINT_SMOOTH);
    }

    glPointSize(point_size_);

    glDrawElements(GL_POINTS, size_, GL_UNSIGNED_INT, nullptr);
  }
}

void QtDrawScene::paintGL() {
  glClearColor(bg_color_r_, bg_color_g_, bg_color_b_, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  SetUpMatrix();

  vao_.bind();
  PaintLines();
  PaintPoints();
  vao_.release();
}

void QtDrawScene::CreateObjectVAO() {
  glDisableVertexAttribArray(0);

#ifdef __APPLE__
  vao_.destroy();
  vao_.create();
#endif

  QVector<GLfloat> vertices =
      QVector<GLfloat>(draw_.first.begin(), draw_.first.end());

  QVector<GLuint> indices =
      QVector<GLuint>(draw_.second.begin(), draw_.second.end());

  size_ = indices.size();

  vao_.bind();

  vbo_.create();
  vbo_.bind();
  vbo_.allocate(vertices.constData(), vertices.size() * sizeof(GLfloat));

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), nullptr);
  glEnableVertexAttribArray(0);

  ibo_.create();
  ibo_.bind();
  ibo_.allocate(indices.constData(), indices.size() * sizeof(GLuint));

  vao_.release();
}

void QtDrawScene::SetUpMatrix() {
  projection_matrix_.setToIdentity();

  if (is_parallel_) {
    projection_matrix_.ortho(-2.0f, 2.0f, -2.0f, 2.0f, -100.0f, 100.0f);
  } else {
    projection_matrix_.perspective(60, aspect_ratio_, 0.1f, 100.0f);
  }

  glMatrixMode(GL_PROJECTION);
  glLoadMatrixf(projection_matrix_.constData());

  model_view_matrix_.setToIdentity();
  model_view_matrix_.translate(QVector3D(0.0f, 0.0f, -6.0));

  model_view_matrix_.scale(QVector3D(scale_, scale_, scale_));
  model_view_matrix_.rotate(x_rot_, QVector3D(1.0, 0.0, 0.0));
  model_view_matrix_.rotate(y_rot_, QVector3D(0.0, 1.0, 0.0));

  glMatrixMode(GL_MODELVIEW);
  glLoadMatrixf(model_view_matrix_.constData());
}

void QtDrawScene::SetIsParallel(bool is_parallel) {
  is_parallel_ = is_parallel;
}

void QtDrawScene::SetLineWidth(float line_width) { line_width_ = line_width; }

void QtDrawScene::SetPointSize(float point_size) { point_size_ = point_size; }

void QtDrawScene::SetVertexesType(Types type) { vertexes_type_ = type; }

void QtDrawScene::SetLinesType(Types type) { line_type_ = type; }

void QtDrawScene::mouseMoveEvent(QMouseEvent *event) {
  if (event->buttons() & Qt::LeftButton) {
    QPoint delta = event->pos() - last_mouse_pos_;

    x_rot_ += 0.2 * delta.y();
    y_rot_ += 0.2 * delta.x();

    update();
  }

  last_mouse_pos_ = event->pos();
}

void QtDrawScene::mousePressEvent(QMouseEvent *event) {
  last_mouse_pos_ = event->pos();
}

void QtDrawScene::wheelEvent(QWheelEvent *event) {
  int numDegrees = event->angleDelta().y() / 8;
  float deltaScale = numDegrees / 1000.0f;

  scale_ += deltaScale;

  update();
}
