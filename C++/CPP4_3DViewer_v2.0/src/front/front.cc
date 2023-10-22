#include "front.h"

Front::Front(s21::Controller *controller, QWidget *parent)
    : QMainWindow(parent), ui_(new Ui::Front) {
  ui_->setupUi(this);
  settings_ = new QSettings(this);

  if (!settings_->contains("projection_type")) {
    CreateDefaultSettings();
  }

  cont_ = controller;
  viewer_ = cont_->GetView();
  LoadToViewer();

  ui_->view_widget->addWidget(viewer_, 0, 0);

  gif_timer_ = new QTimer(0);
  connect(gif_timer_, &QTimer::timeout, this, &Front::GifCreator);
}

void Front::LoadToViewer() {
  if (ui_->radioButton_norm->isChecked()) {
    viewer_->SetVertexesType(kOff);
  } else if (ui_->radioButton_circles->isChecked()) {
    viewer_->SetVertexesType(kCircles);
  } else if (ui_->radioButton_quads->isChecked()) {
    viewer_->SetVertexesType(kSquare);
  }

  if (ui_->radioButton_line_none->isChecked()) {
    viewer_->SetLinesType(kOff);
  } else if (ui_->radioButton_line_smooth->isChecked()) {
    viewer_->SetLinesType(kSmooth);
  } else if (ui_->radioButton_stipple->isChecked()) {
    viewer_->SetLinesType(kStripple);
  }
}

Front::~Front() {
  viewer_->setParent(nullptr);
  delete gif_timer_;
  delete ui_;
}

void Front::showEvent(QShowEvent *event) {
  Q_UNUSED(event);
  LoadSettings();
}

void Front::SetFilePath(std::string filename) { file_path_ = filename; }

void Front::InitFile(std::string filename) {
  QFileInfo fileinfo(QString::fromStdString(filename));
  QString objName = fileinfo.fileName();
  this->setWindowTitle(objName + " - Viewer3D");

  ui_->label_info_v->setNum(static_cast<int>(cont_->GetVerticesCount()));
  ui_->label_info_e->setNum(static_cast<int>(cont_->GetEdgesCount()));
  ui_->label_info_name->setText(objName);
}

void Front::GifTimer() {
  gif_timer_->setInterval(10);
  gif_timer_->start();
}

void Front::GifCreator() {
  QImage image = viewer_->grabFramebuffer();
  gif_image_->addFrame(image);

  if (number_frames_ == 240) {
    gif_timer_->stop();
    gif_image_->save(gif_file_name_);

    number_frames_ = 0;

    ErrorMessage("Complete", "Gif saved.");

    delete gif_image_;

    ui_->pushButton_gif->setText("Record Gif");
    ui_->pushButton_gif->setEnabled(true);
  }

  ++number_frames_;

  if (!ui_->pushButton_gif->isEnabled()) {
    ui_->pushButton_gif->setText(
        QString::number(static_cast<int>(number_frames_ / 2.4)) + "%");
  }
}

void Front::ErrorMessage(QString type, QString message) {
  QMessageBox message_box;
  message_box.setFixedSize(500, 200);
  message_box.information(0, type, message);
}

void Front::ReDraw() {
  try {
    cont_->DrawScene();
  } catch (std::runtime_error const &e) {
    ErrorMessage("Error", e.what());
  }
}
