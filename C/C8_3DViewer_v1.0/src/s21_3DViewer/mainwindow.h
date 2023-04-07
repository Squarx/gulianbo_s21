#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "glview.h"
#include "qtgifimage/src/gifimage/qgifimage.h"
namespace Ui {
class MainWindow;
}
extern "C" {
#include "../s21_3DViewer.h"
#include "../s21_matrix.h"
}
class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget *parent = nullptr);
  enum { NO_POINTS, CIRCLE_POINTS, SQUARE_POINTS, SOLID_LINE, DASHED_LINE };
  ~MainWindow();

 private slots:
  void on_radioButton_ortho_clicked();

  void on_radioButton_frustum_clicked();

  void on_rb_no_points_6_clicked();

  void on_rb_circle_points_6_clicked();

  void on_rb_square_points_6_clicked();

  void on_slider_point_size_6_valueChanged(int value);

  void on_button_point_color_clicked();

  void on_rb_solid_line_7_clicked();

  void on_rb_dashed_line_7_clicked();

  void on_slider_line_size_7_valueChanged(int value);

  void on_button_point_color_2_clicked();

  void on_button_choose_file_clicked();

  void on_button_bg_color_clicked();

  void on_spinbox_point_size_6_valueChanged(int arg1);

  void on_spinbox_line_size_7_valueChanged(int arg1);

  void on_button_save_settings_clicked();

  void on_button_load_settings_clicked();

  void on_spinbox_move_x_valueChanged(int arg1);

  void on_slider_move_x_valueChanged(int value);

  void on_spinbox_rotate_x_valueChanged(int arg1);

  void on_dial_rotate_x_valueChanged(int value);

  void on_spinbox_move_y_valueChanged(int arg1);

  void on_slider_move_y_valueChanged(int value);

  void on_spinbox_rotate_y_valueChanged(int arg1);

  void on_dial_rotate_y_valueChanged(int value);

  void on_slider_move_z_valueChanged(int value);

  void on_spinbox_move_z_valueChanged(int arg1);

  void on_spinbox_rotate_z_valueChanged(int arg1);

  void on_dial_rotate_z_valueChanged(int value);

  void on_spinbox_model_scale_valueChanged(double arg1);

  void on_slider_model_scale_valueChanged(int value);

  void on_ButtonScreenShot_clicked();

  void on_ButtonGif_clicked();

  void record_gif();
  void save_gif();

 private:
  QGifImage gif;
  QTimer *timer;
  Ui::MainWindow *ui;
  QString settings_file;
  double PrevPosition_x = 0;
  double PrevRotationtion_x = 0;
  double PrevPosition_y = 0;
  double PrevRotationtion_y = 0;
  double PrevPosition_z = 0;
  double PrevRotationtion_z = 0;
  double PrevScale = 1;
  double giftime = 0;
  QVector<QImage> img_vector;
};

#endif  // MAINWINDOW_H
