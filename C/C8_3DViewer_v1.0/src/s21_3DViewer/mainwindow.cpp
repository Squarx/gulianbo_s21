#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  settings_file = QApplication::applicationDirPath() + "/set.ini";
  ui->statusbar->showMessage(settings_file);
}

MainWindow::~MainWindow() {
  //    ui->gLwidget->~glView();
  //    delete ui->gLwidget;
  delete timer;
  delete ui;
}

void MainWindow::on_radioButton_ortho_clicked() {
  ui->gLwidget->projection = 0;
  update();
}

void MainWindow::on_radioButton_frustum_clicked() {
  ui->gLwidget->projection = 1;
  update();
}

void MainWindow::on_rb_no_points_6_clicked() {
  ui->gLwidget->point_type = NO_POINTS;
}

void MainWindow::on_rb_circle_points_6_clicked() {
  ui->gLwidget->point_type = CIRCLE_POINTS;
}

void MainWindow::on_rb_square_points_6_clicked() {
  ui->gLwidget->point_type = SQUARE_POINTS;
}

void MainWindow::on_slider_point_size_6_valueChanged(int value) {
  ui->gLwidget->point_size = value;
  ui->spinbox_point_size_6->setValue(value);
}

void MainWindow::on_spinbox_point_size_6_valueChanged(int arg1) {
  ui->gLwidget->point_size = arg1;
  ui->slider_point_size_6->setValue(arg1);
}

void MainWindow::on_button_point_color_clicked() {
  ui->gLwidget->colorPoint = QColorDialog::getColor();
}

void MainWindow::on_rb_solid_line_7_clicked() {
  ui->gLwidget->line_type = SOLID_LINE;
}

void MainWindow::on_rb_dashed_line_7_clicked() {
  ui->gLwidget->line_type = DASHED_LINE;
}

void MainWindow::on_slider_line_size_7_valueChanged(int value) {
  ui->gLwidget->line_size = value;
  ui->spinbox_line_size_7->setValue(value);
}
void MainWindow::on_spinbox_line_size_7_valueChanged(int arg1) {
  ui->gLwidget->line_size = arg1;
  ui->slider_line_size_7->setValue(arg1);
}

void MainWindow::on_button_point_color_2_clicked() {
  ui->gLwidget->colorLines = QColorDialog::getColor();
}

void MainWindow::on_button_choose_file_clicked() {
  QString homePath =
      QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
  QString filename = QFileDialog::getOpenFileName(this, "Выберите файл",
                                                  homePath, tr(" (*.obj)"));
  if (filename != "") {
    QByteArray temp = filename.toLocal8Bit();
    char *str_filename = temp.data();
    //      printf("%s\n", str_filename);
    clean_all(&(ui->gLwidget->counts));
    s21_3DViewer(str_filename, &(ui->gLwidget->counts));
    ui->gLwidget->ptr_coord = ui->gLwidget->counts.resultV;
    ui->gLwidget->ptr_ind = (unsigned int *)ui->gLwidget->counts.resultF;
    ui->gLwidget->size = (ui->gLwidget->counts.f) * 6;
    ui->statusbar->showMessage(str_filename);
    update();
  }
}

void MainWindow::on_button_bg_color_clicked() {
  ui->gLwidget->colorBackground = QColorDialog::getColor();
}

void MainWindow::on_button_save_settings_clicked() {
  QSettings settings(settings_file, QSettings::NativeFormat);
  // Ortho/Frustum
  settings.setValue("radioButton_ortho", ui->radioButton_ortho->isChecked());
  settings.setValue("radioButton_frustum",
                    ui->radioButton_frustum->isChecked());
  // Points
  settings.setValue("point_type", ui->gLwidget->point_type);
  settings.setValue("point_size", ui->gLwidget->point_size);

  settings.setValue("slider_point_size", ui->slider_point_size_6->value());
  settings.setValue("spinbox_point_size", ui->spinbox_point_size_6->value());
  settings.setValue("rb_no_points", ui->rb_no_points_6->isChecked());
  settings.setValue("rb_circle_points", ui->rb_circle_points_6->isChecked());
  settings.setValue("rb_square_points", ui->rb_square_points_6->isChecked());
  settings.setValue("colorPoint", ui->gLwidget->colorPoint);

  // Lines
  settings.setValue("line_size", ui->gLwidget->line_size);
  settings.setValue("line_type", ui->gLwidget->line_type);

  settings.setValue("colorLine", ui->gLwidget->colorLines);
  settings.setValue("slider_line_size", ui->slider_line_size_7->value());
  settings.setValue("spinbox_line_size", ui->spinbox_line_size_7->value());
  settings.setValue("rb_solid_lines", ui->rb_solid_line_7->isChecked());
  settings.setValue("rb_dashed_lines", ui->rb_dashed_line_7->isChecked());

  // Background
  settings.setValue("colorBackground", ui->gLwidget->colorBackground);
}

void MainWindow::on_button_load_settings_clicked() {
  ui->statusbar->showMessage(settings_file);
  if (!settings_file.isEmpty() && QFile::exists(settings_file)) {
    QSettings settings(settings_file, QSettings::NativeFormat);
    // Ortho/Frustum
    ui->radioButton_ortho->setChecked(
        settings.value("radioButton_ortho").toBool());
    ui->radioButton_frustum->setChecked(
        settings.value("radioButton_frustum").toBool());

    // Background
    ui->gLwidget->colorBackground =
        settings.value("colorBackground").value<QColor>();

    // Points
    ui->gLwidget->point_type = settings.value("point_type").toInt();
    ui->gLwidget->point_size = settings.value("point_size").toInt();

    ui->gLwidget->colorPoint = settings.value("colorPoint").value<QColor>();
    ui->slider_point_size_6->setValue(
        settings.value("slider_point_size").toInt());
    ui->spinbox_point_size_6->setValue(
        settings.value("spinbox_point_size").toInt());
    ui->rb_no_points_6->setChecked(settings.value("rb_no_points").toBool());
    ui->rb_circle_points_6->setChecked(
        settings.value("rb_circle_points_6").toBool());
    ui->rb_square_points_6->setChecked(
        settings.value("rb_square_points_6").toBool());

    // Lines
    ui->gLwidget->line_size = settings.value("line_size").toInt();
    ui->gLwidget->line_type = settings.value("line_type").toInt();

    ui->gLwidget->colorLines = settings.value("colorLine").value<QColor>();
    ui->slider_line_size_7->setValue(
        settings.value("slider_line_size").toInt());
    ui->spinbox_line_size_7->setValue(
        settings.value("spinbox_line_size").toInt());
    ui->rb_solid_line_7->setChecked(settings.value("rb_solid_lines").toBool());
    ui->rb_dashed_line_7->setChecked(
        settings.value("rb_dashed_lines").toBool());
  }
}

void MainWindow::on_spinbox_move_x_valueChanged(int arg1) {
  double tmp = arg1;
  arg1 = arg1 - PrevPosition_x;
  PrevPosition_x = tmp;
  ui->slider_move_x->setValue(tmp);
  ui->statusbar->showMessage(QString::number(arg1));

  if (ui->gLwidget->counts.resultF != NULL &&
      ui->gLwidget->counts.resultV != NULL) {
    s21_move_matrix(&(ui->gLwidget->counts.mV), (double)arg1, 0);
    clean_long_arr(&(ui->gLwidget->counts));
    to_long_array(&(ui->gLwidget->counts));
    ui->gLwidget->ptr_coord = ui->gLwidget->counts.resultV;
    ui->gLwidget->ptr_ind = (unsigned int *)ui->gLwidget->counts.resultF;
    //  ui->gLwidget->counts.resultV;
  }
  update();
}

void MainWindow::on_slider_move_x_valueChanged(int value) {
  ui->spinbox_move_x->setValue(value);
  update();
}

void MainWindow::on_spinbox_rotate_x_valueChanged(int arg1) {
  ui->dial_rotate_x->setValue(arg1);
  double tmp = arg1;
  arg1 = arg1 - PrevRotationtion_x;
  PrevRotationtion_x = tmp;
  ui->statusbar->showMessage(QString::number(arg1));
  ui->dial_rotate_x->setValue(tmp);
  if (ui->gLwidget->counts.resultF != NULL &&
      ui->gLwidget->counts.resultV != NULL) {
    s21_x_rotation_matrix(&(ui->gLwidget->counts.mV),
                          (double)2 * 3.1415926 / 360 * arg1);
    clean_long_arr(&(ui->gLwidget->counts));
    to_long_array(&(ui->gLwidget->counts));
    ui->gLwidget->ptr_coord = ui->gLwidget->counts.resultV;
    ui->gLwidget->ptr_ind = (unsigned int *)ui->gLwidget->counts.resultF;
    //  ui->gLwidget->counts.resultV;
  }
  update();
}

void MainWindow::on_dial_rotate_x_valueChanged(int value) {
  ui->spinbox_rotate_x->setValue(value);
  update();
}

void MainWindow::on_spinbox_move_y_valueChanged(int arg1) {
  double tmp = arg1;
  arg1 = arg1 - PrevPosition_y;
  PrevPosition_y = tmp;
  ui->slider_move_y->setValue(tmp);
  ui->statusbar->showMessage(QString::number(arg1));

  if (ui->gLwidget->counts.resultF != NULL &&
      ui->gLwidget->counts.resultV != NULL) {
    s21_move_matrix(&(ui->gLwidget->counts.mV), (double)arg1, 1);
    clean_long_arr(&(ui->gLwidget->counts));
    to_long_array(&(ui->gLwidget->counts));
    ui->gLwidget->ptr_coord = ui->gLwidget->counts.resultV;
    ui->gLwidget->ptr_ind = (unsigned int *)ui->gLwidget->counts.resultF;
    //  ui->gLwidget->counts.resultV;
  }
  update();
}

void MainWindow::on_slider_move_y_valueChanged(int value) {
  ui->spinbox_move_y->setValue(value);
  update();
}

void MainWindow::on_spinbox_rotate_y_valueChanged(int arg1) {
  ui->dial_rotate_y->setValue(arg1);
  double tmp = arg1;
  arg1 = arg1 - PrevRotationtion_y;
  PrevRotationtion_y = tmp;
  ui->statusbar->showMessage(QString::number(arg1));
  if (ui->gLwidget->counts.resultF != NULL &&
      ui->gLwidget->counts.resultV != NULL) {
    s21_y_rotation_matrix(&(ui->gLwidget->counts.mV),
                          (double)2 * 3.1415926 / 360 * arg1);
    clean_long_arr(&(ui->gLwidget->counts));
    to_long_array(&(ui->gLwidget->counts));
    ui->gLwidget->ptr_coord = ui->gLwidget->counts.resultV;
    ui->gLwidget->ptr_ind = (unsigned int *)ui->gLwidget->counts.resultF;
  }
  update();
}

void MainWindow::on_dial_rotate_y_valueChanged(int value) {
  ui->spinbox_rotate_y->setValue(value);
  update();
}

void MainWindow::on_slider_move_z_valueChanged(int value) {
  ui->spinbox_move_z->setValue(value);
  update();
}

void MainWindow::on_spinbox_move_z_valueChanged(int arg1) {
  double tmp = arg1;
  arg1 = arg1 - PrevPosition_z;
  PrevPosition_z = tmp;
  ui->slider_move_z->setValue(tmp);
  ui->statusbar->showMessage(QString::number(arg1));

  if (ui->gLwidget->counts.resultF != NULL &&
      ui->gLwidget->counts.resultV != NULL) {
    s21_move_matrix(&(ui->gLwidget->counts.mV), (double)arg1, 2);
    clean_long_arr(&(ui->gLwidget->counts));
    to_long_array(&(ui->gLwidget->counts));
    ui->gLwidget->ptr_coord = ui->gLwidget->counts.resultV;
    ui->gLwidget->ptr_ind = (unsigned int *)ui->gLwidget->counts.resultF;
    //  ui->gLwidget->counts.resultV;
  }
  update();
}

void MainWindow::on_spinbox_rotate_z_valueChanged(int arg1) {
  ui->dial_rotate_z->setValue(arg1);
  double tmp = arg1;
  arg1 = arg1 - PrevRotationtion_z;
  PrevRotationtion_z = tmp;
  ui->statusbar->showMessage(QString::number(arg1));
  if (ui->gLwidget->counts.resultF != NULL &&
      ui->gLwidget->counts.resultV != NULL) {
    s21_z_rotation_matrix(&(ui->gLwidget->counts.mV),
                          (double)2 * 3.1415926 / 360 * arg1);
    clean_long_arr(&(ui->gLwidget->counts));
    to_long_array(&(ui->gLwidget->counts));
    ui->gLwidget->ptr_coord = ui->gLwidget->counts.resultV;
    ui->gLwidget->ptr_ind = (unsigned int *)ui->gLwidget->counts.resultF;
  }
  update();
}

void MainWindow::on_dial_rotate_z_valueChanged(int value) {
  ui->spinbox_rotate_z->setValue(value);
  update();
}

void MainWindow::on_spinbox_model_scale_valueChanged(double arg1) {
  ui->slider_model_scale->setValue(arg1 * 10);
  if (ui->gLwidget->counts.resultF != NULL &&
      ui->gLwidget->counts.resultV != NULL) {
    s21_scaling_matrix(&(ui->gLwidget->counts.mV), arg1 / PrevScale);
    PrevScale = arg1;
    clean_long_arr(&(ui->gLwidget->counts));
    to_long_array(&(ui->gLwidget->counts));
    ui->gLwidget->ptr_coord = ui->gLwidget->counts.resultV;
    ui->gLwidget->ptr_ind = (unsigned int *)ui->gLwidget->counts.resultF;
  }
  update();
}

void MainWindow::on_slider_model_scale_valueChanged(int value) {
  ui->spinbox_model_scale->setValue(value / 10.0);
  update();
}

void MainWindow::on_ButtonScreenShot_clicked() {
  QString desktopPath =
      QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);

  QFileDialog dialog(this);
  QString screenshot_filename =
      dialog.getSaveFileName(this, "Save screenshot as...", desktopPath,
                             "BMP (*.bmp);; JPEG (*.jpeg)");

  ui->gLwidget->setStyleSheet(
      "background-color: " + ui->gLwidget->colorBackground.name() + ";");
  QPixmap screenshot = ui->gLwidget->grab();

  screenshot.save(screenshot_filename);
}

void MainWindow::on_ButtonGif_clicked() {
  timer = new QTimer(0);
  timer->start(100);
  connect(timer, SIGNAL(timeout()), this, SLOT(record_gif()));
}

// гифка
void MainWindow::record_gif() {
  if (giftime < 5.0) {
    ui->gLwidget->setStyleSheet(
        "background-color: " + ui->gLwidget->colorBackground.name() + ";");
    img_vector.push_back(ui->gLwidget->grab().toImage());
    giftime += 0.1;
    if (giftime <= 5.0) ui->label_gif_timer->setText(QString::number(giftime));
  } else if (giftime >= 5.0) {
    save_gif();
    timer->stop();
  }
}

void MainWindow::save_gif() {
  QString desktopPath =
      QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);

  QFileDialog dialog(this);
  QString gif_filename = dialog.getSaveFileName(this, "Save gif as...",
                                                desktopPath, "GIF (*.gif);;");

  gif.setDefaultDelay(100);

  for (QVector<QImage>::Iterator img = img_vector.begin();
       img != img_vector.end(); ++img) {
    QImage imgScaled = img->scaled(640, 480);
    gif.addFrame(imgScaled);
  }

  gif.save(gif_filename);
  img_vector.clear();
  ui->label_gif_timer->clear();
  giftime = 0.0;
}
