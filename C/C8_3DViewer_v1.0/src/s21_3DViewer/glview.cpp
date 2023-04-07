#include "glview.h"
glView::glView(QWidget *parent) : QOpenGLWidget(parent) {
  setWindowTitle("3DViewer");
  setGeometry(400, 200, 800, 600);

  s21_3DViewer(pathToFile, &counts);
  ptr_coord = counts.resultV;
  ptr_ind = (unsigned int *)counts.resultF;
  size = (counts.f) * 6;
}

glView::~glView() { clean_all(&counts); }

void glView::initializeGL() { glEnable(GL_DEPTH_TEST); }

// настройки OpenGL при изменении размеров окна
void glView::resizeGL(int w, int h) {
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
}

void glView::paintGL() {
  glClearColor(colorBackground.redF(), colorBackground.greenF(),
               colorBackground.blueF(), 0);  // цвет фона
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);

  glLoadIdentity();

  glTranslatef(0, 0, 0);  // что это нахрен делает

  glRotatef(xRot, 1, 0, 0);  // поворот

  glRotatef(yRot, 0, 1, 0);  // поворот
  glScaled(scale, scale, scale);

  if (!counts.error) paintObject();

  update();
}

void glView::paintObject() {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  if (projection == 0) {
    glOrtho(min_x, max_x, min_y, max_y, -1000, 1000);

  } else if (projection == 1) {
    glFrustum(min_x, max_x, min_y, max_y, -1000, 1000);
  }

  if (point_type != NO_POINTS) drawPoints();
  drawLines();
}

void glView::drawPoints() {
  if (point_type == CIRCLE_POINTS)
    glEnable(GL_POINT_SMOOTH);
  else if (point_type == SQUARE_POINTS)
    glDisable(GL_POINT_SMOOTH);
  //_________________________________________________
  glPointSize(point_size);  // размер с фронта
  glColor3d(colorPoint.redF(), colorPoint.greenF(), colorPoint.blueF());

  //_________________________________________________

  glVertexPointer(3, GL_DOUBLE, 0, ptr_coord);
  glEnableClientState(GL_VERTEX_ARRAY);
  glDrawElements(GL_POINTS, size, GL_UNSIGNED_INT, ptr_ind);
  glDisableClientState(GL_VERTEX_ARRAY);
  glDisable(GL_LINE_STIPPLE);
  glColor3d(defaultColor.redF(), defaultColor.greenF(), defaultColor.blueF());
}

void glView::drawLines() {
  glColor3d(colorLines.redF(), colorLines.greenF(), colorLines.blueF());

  if (line_type == DASHED_LINE) {
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(7, 0x3333);
  }

  glLineWidth(line_size);

  glVertexPointer(3, GL_DOUBLE, 0, ptr_coord);
  glEnableClientState(GL_VERTEX_ARRAY);
  glDrawElements(GL_LINES, size, GL_UNSIGNED_INT, ptr_ind);
  glDisableClientState(GL_VERTEX_ARRAY);
  glDisable(GL_LINE_STIPPLE);

  glColor3d(defaultColor.redF(), defaultColor.greenF(), defaultColor.blueF());
}

void glView::wheelEvent(QWheelEvent *event) {
  if (event->angleDelta().y() > 0) {
    scale += 0.02;
  } else {
    scale -= 0.02;
  }
  if (scale < 0) scale = 0.01;
  update();
}

void glView::mouseMoveEvent(QMouseEvent *mo) {
  xRot += 1 / (M_PI) * (mo->pos().y() - mPos.y());

  yRot += 1 / (M_PI) * (mo->pos().x() - mPos.x());

  mPos = mo->pos();

  update();
}

void glView::mousePressEvent(QMouseEvent *mo) { mPos = mo->pos(); }
