#ifndef INC_3D_VIEWER_SRC_FRONT_FRONT_H_
#define INC_3D_VIEWER_SRC_FRONT_FRONT_H_

#include <qfiledialog.h>

#include <QLabel>
#include <QMainWindow>
#include <QMessageBox>
#include <QOpenGLFramebufferObjectFormat>
#include <QPushButton>
#include <QSettings>
#include <QtConcurrent>

#include "../controller/controller.h"
#include "qgifimage.h"
#include "ui_front.h"

#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#include <GL/glut.h>
#endif

QT_BEGIN_NAMESPACE
namespace Ui {

class Front;
}
QT_END_NAMESPACE

class Front : public QMainWindow {
  Q_OBJECT

 public:
  Front(s21::Controller *controller = nullptr, QWidget *parent = nullptr);
  ~Front();

 protected:
  void showEvent(QShowEvent *event) override;

 private slots:
  void on_pushButton_select_name_clicked();

  void on_move_spin_x_valueChanged(double arg1);

  void on_move_spin_y_valueChanged(double arg1);

  void on_move_spin_z_valueChanged(double arg1);

  void on_rotate_spin_x_valueChanged(double arg1);

  void on_rotate_spin_y_valueChanged(double arg1);

  void on_rotate_spin_z_valueChanged(double arg1);

  void on_scale_spin_valueChanged(double arg1);

  void on_horizontalScrollBar_vertexes_R_valueChanged(int value);

  void on_spinBox_vertexes_R_valueChanged(int arg1);

  void on_spinBox_vertexes_G_valueChanged(int arg1);

  void on_horizontalScrollBar_vertexes_G_valueChanged(int value);

  void on_spinBox_vertexes_B_valueChanged(int arg1);

  void on_horizontalScrollBar_vertexes_B_valueChanged(int value);

  void on_horizontalScrollBar_edges_R_valueChanged(int value);

  void on_spinBox_edges_R_valueChanged(int arg1);

  void on_spinBox_edges_G_valueChanged(int arg1);

  void on_horizontalScrollBar_edges_G_valueChanged(int value);

  void on_spinBox_edges_B_valueChanged(int arg1);

  void on_horizontalScrollBar_edges_B_valueChanged(int value);

  void on_spinBox_bgr_R_valueChanged(int arg1);

  void on_horizontalScrollBar_bgr_R_valueChanged(int value);

  void on_spinBox_bgr_G_valueChanged(int arg1);

  void on_horizontalScrollBar_bgr_G_valueChanged(int value);

  void on_spinBox_bgr_B_valueChanged(int arg1);

  void on_horizontalScrollBar_bgr_B_valueChanged(int value);

  void on_pushButton_save_settings_clicked();

  void on_projection_type_currentIndexChanged(int index);

  void on_spinBox_edges_size_valueChanged(int arg1);

  void on_spinBox_vertexes_size_valueChanged(int arg1);

  void on_radioButton_quads_toggled(bool checked);

  void on_radioButton_norm_toggled(bool checked);

  void on_radioButton_circles_toggled(bool checked);

  void on_radioButton_stipple_toggled(bool checked);

  void on_pushButton_screenshot_clicked();

  void on_pushButton_gif_clicked();

  void on_pushButton_reset_clicked();

  void on_radioButton_line_none_toggled(bool checked);

  void on_radioButton_line_smooth_toggled(bool checked);

 private:
  QSettings *settings_;
  Ui::Front *ui_;
  s21::BaseSceneDrawer *viewer_;
  s21::Controller *cont_;

  QTimer *gif_timer_;
  QGifImage *gif_image_;
  QString gif_file_name_;
  std::string file_path_;
  int number_frames_ = 0;

  void InitFile(std::string filename);

  void ErrorMessage(QString type, QString message);
  void CreateDefaultSettings();

  std::string OpenFile();
  void SetFilePath(std::string filename);

  void GifTimer();
  void GifCreator();

  void LoadSettings();
  void SaveSettings();
  void LoadToViewer();

  void ReDraw();
};

#endif  // INC_3D_VIEWER_SRC_FRONT_FRONT_H_
