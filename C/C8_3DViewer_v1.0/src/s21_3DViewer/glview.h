#ifndef GLVIEW_H
#define GLVIEW_H

#ifdef __APPLE__

/* Defined before OpenGL and GLUT includes to avoid deprecation messages */

#define GL_SILENCE_DEPRECATION

#include <GLUT/glut.h>
#include <OpenGL/gl.h>

#else

#include <GL/gl.h>
#include <GL/glut.h>

#endif

#include <QWidget>
#include <QtOpenGL>
#include <QtOpenGLWidgets>
extern "C" {
#include "../s21_3DViewer.h"
#include "../s21_matrix.h"
}

class glView : public QOpenGLWidget {
  Q_OBJECT
 private:
  float xRot, yRot, zRot;  // переменные для вращения осей координат мышкой
  QPoint mPos;

 protected:
  void initializeGL() override;
  void resizeGL(int w, int h) override;
  void paintGL() override;
  void mousePressEvent(QMouseEvent *) override;
  void mouseMoveEvent(QMouseEvent *) override;
  void wheelEvent(QWheelEvent *event) override;

 public:
  V_F counts;
  matrix_t fuckingScale;
  char *pathToFile = NULL;
  //  Matrix root_matrix_F;
  //  Matrix root_matrix_V;
  QColor colorPoint = QColor(Qt::white);
  QColor defaultColor = QColor(Qt::white);
  QColor colorLines = QColor(Qt::white);
  QColor colorBackground = QColor(Qt::black);

  int projection = 0;
  int line_size = 2;
  double *ptr_coord = NULL;
  unsigned int *ptr_ind = NULL;
  int size;
  double min_x = -1, min_y = -1, max_x = 1, max_y = 1;
  double scale = 0.5;       // масштабирование
  double scale_step = 0.1;  // шаг масштабирования
  void drawPoints();
  void drawLines();
  enum { NO_POINTS, CIRCLE_POINTS, SQUARE_POINTS, SOLID_LINE, DASHED_LINE };

  int point_type = NO_POINTS;  // споcоб отборажения точек
  int line_type = SOLID_LINE;
  int point_size = 0;

  glView(QWidget *parent = nullptr);
  ~glView();
  void paintObject();
};
#endif  // GLVIEW_H
