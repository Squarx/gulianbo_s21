#include "../front.h"

void Front::LoadSettings() {
  ui_->projection_type->setCurrentIndex(
      settings_->value("projection_type", "0").toInt());
  ui_->radioButton_line_smooth->setChecked(
      settings_->value("edges_type_line", true).toBool());
  ui_->radioButton_stipple->setChecked(
      settings_->value("edges_type_stipple", true).toBool());
  ui_->radioButton_line_none->setChecked(
      settings_->value("edges_type_none", true).toBool());
  ui_->radioButton_norm->setChecked(
      settings_->value("radioButton_norm", true).toBool());
  ui_->radioButton_circles->setChecked(
      settings_->value("radioButton_circles", true).toBool());
  ui_->radioButton_quads->setChecked(
      settings_->value("radioButton_quads", true).toBool());

  ui_->spinBox_edges_size->setValue(
      settings_->value("edges_size", "1").toInt());
  ui_->spinBox_vertexes_size->setValue(
      settings_->value("vertexes_size", "10").toInt());

  ui_->horizontalScrollBar_bgr_R->setValue(
      settings_->value("horizontalScrollBar_bgr_R").toInt());
  ui_->horizontalScrollBar_bgr_G->setValue(
      settings_->value("horizontalScrollBar_bgr_G").toInt());
  ui_->horizontalScrollBar_bgr_B->setValue(
      settings_->value("horizontalScrollBar_bgr_B").toInt());

  ui_->horizontalScrollBar_edges_R->setValue(
      settings_->value("horizontalScrollBar_edges_R").toInt());
  ui_->horizontalScrollBar_edges_G->setValue(
      settings_->value("horizontalScrollBar_edges_G").toInt());
  ui_->horizontalScrollBar_edges_B->setValue(
      settings_->value("horizontalScrollBar_edges_B").toInt());

  ui_->horizontalScrollBar_vertexes_R->setValue(
      settings_->value("horizontalScrollBar_vertexes_R").toInt());
  ui_->horizontalScrollBar_vertexes_G->setValue(
      settings_->value("horizontalScrollBar_vertexes_G").toInt());
  ui_->horizontalScrollBar_vertexes_B->setValue(
      settings_->value("horizontalScrollBar_vertexes_B").toInt());
}

void Front::SaveSettings() {
  settings_->setValue("projection_type", ui_->projection_type->currentIndex());
  settings_->setValue("edges_type_line_smooth",
                      ui_->radioButton_line_smooth->isChecked());
  settings_->setValue("edges_type_none",
                      ui_->radioButton_line_none->isChecked());
  settings_->setValue("edges_type_stipple",
                      ui_->radioButton_stipple->isChecked());

  settings_->setValue("radioButton_norm", ui_->radioButton_norm->isChecked());
  settings_->setValue("radioButton_circles",
                      ui_->radioButton_circles->isChecked());
  settings_->setValue("radioButton_quads", ui_->radioButton_quads->isChecked());

  settings_->setValue("edges_size", ui_->spinBox_edges_size->value());
  settings_->setValue("vertexes_size", ui_->spinBox_vertexes_size->value());

  settings_->setValue("horizontalScrollBar_bgr_R",
                      ui_->horizontalScrollBar_bgr_R->value());
  settings_->setValue("horizontalScrollBar_bgr_G",
                      ui_->horizontalScrollBar_bgr_G->value());
  settings_->setValue("horizontalScrollBar_bgr_B",
                      ui_->horizontalScrollBar_bgr_B->value());

  settings_->setValue("horizontalScrollBar_edges_R",
                      ui_->horizontalScrollBar_edges_R->value());
  settings_->setValue("horizontalScrollBar_edges_G",
                      ui_->horizontalScrollBar_edges_G->value());
  settings_->setValue("horizontalScrollBar_edges_B",
                      ui_->horizontalScrollBar_edges_B->value());

  settings_->setValue("horizontalScrollBar_vertexes_R",
                      ui_->horizontalScrollBar_vertexes_R->value());
  settings_->setValue("horizontalScrollBar_vertexes_G",
                      ui_->horizontalScrollBar_vertexes_G->value());
  settings_->setValue("horizontalScrollBar_vertexes_B",
                      ui_->horizontalScrollBar_vertexes_B->value());
}

void Front::CreateDefaultSettings() {
  settings_->setValue("projection_type", 0);
  settings_->setValue("edges_type_line_smooth", true);
  settings_->setValue("edges_type_stipple", false);
  settings_->setValue("edges_type_none", false);

  settings_->setValue("radioButton_norm", false);
  settings_->setValue("radioButton_circles", true);
  settings_->setValue("radioButton_quads", false);

  settings_->setValue("edges_size", 2);
  settings_->setValue("vertexes_size", 10);

  settings_->setValue("horizontalScrollBar_bgr_R", 30);
  settings_->setValue("horizontalScrollBar_bgr_G", 30);
  settings_->setValue("horizontalScrollBar_bgr_B", 30);

  settings_->setValue("horizontalScrollBar_edges_R", 57);
  settings_->setValue("horizontalScrollBar_edges_G", 255);
  settings_->setValue("horizontalScrollBar_edges_B", 255);

  settings_->setValue("horizontalScrollBar_vertexes_R", 255);
  settings_->setValue("horizontalScrollBar_vertexes_G", 26);
  settings_->setValue("horizontalScrollBar_vertexes_B", 255);
}
