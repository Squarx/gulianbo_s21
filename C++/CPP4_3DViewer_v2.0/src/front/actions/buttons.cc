#include "../front.h"

void Front::on_pushButton_select_name_clicked() {
  std::string filename = OpenFile();

  SetFilePath(filename);

  ui_->pushButton_reset->click();
}

void Front::on_pushButton_save_settings_clicked() { SaveSettings(); }

void Front::on_pushButton_screenshot_clicked() {
  QFileDialog file_dialog_img(this);
  QString f_name = file_dialog_img.getSaveFileName(
      this, tr("Save a screenshot"), ".jpeg", tr("image (*.bmp *.jpeg)"));

  QImage image = viewer_->grabFramebuffer();

  image.save(f_name);
}

void Front::on_pushButton_gif_clicked() {
  gif_file_name_ = QFileDialog::getSaveFileName(this, tr("Save GIF"), ".gif",
                                                tr("Gif Files (*.gif)"));

  if (gif_file_name_ != "") {
    ui_->pushButton_gif->setDisabled(true);

    gif_image_ = new QGifImage;
    gif_image_->setDefaultDelay(10);

    GifTimer();
  } else {
    ErrorMessage("Error", "Directory error!");
  }
}

void Front::on_pushButton_reset_clicked() {
  ui_->scale_spin->setValue(1.0);
  ui_->rotate_spin_x->setValue(0);
  ui_->rotate_spin_y->setValue(0);
  ui_->rotate_spin_z->setValue(0);
  ui_->move_spin_x->setValue(0.0);
  ui_->move_spin_y->setValue(0.0);
  ui_->move_spin_z->setValue(0.0);

  viewer_->ResetFocus();

  if (file_path_.size() > 3) {
    try {
      cont_->LoadFigure(file_path_);
      cont_->DrawScene();
      InitFile(file_path_);
    } catch (std::runtime_error const &e) {
      ErrorMessage("Error", e.what());
    }
  }
}
