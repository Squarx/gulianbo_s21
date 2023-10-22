#include "../front.h"

void Front::on_move_spin_x_valueChanged(double arg1) {
  try {
    cont_->MoveFigure(arg1, ui_->move_spin_y->value(),
                      ui_->move_spin_z->value());
    cont_->DrawScene();
  } catch (std::runtime_error const &e) {
    ErrorMessage("Error", e.what());
  }
}

void Front::on_move_spin_y_valueChanged(double arg1) {
  try {
    cont_->MoveFigure(ui_->move_spin_x->value(), arg1,
                      ui_->move_spin_z->value());
    cont_->DrawScene();
  } catch (std::runtime_error const &e) {
    ErrorMessage("Error", e.what());
  }
}

void Front::on_move_spin_z_valueChanged(double arg1) {
  try {
    cont_->MoveFigure(ui_->move_spin_x->value(), ui_->move_spin_y->value(),
                      arg1);
    cont_->DrawScene();
  } catch (std::runtime_error const &e) {
    ErrorMessage("Error", e.what());
  }
}

void Front::on_rotate_spin_x_valueChanged(double arg1) {
  try {
    cont_->RotateFigure(arg1, ui_->rotate_spin_y->value(),
                        ui_->rotate_spin_z->value());
    cont_->DrawScene();
  } catch (std::runtime_error const &e) {
    ErrorMessage("Error", e.what());
  }
}

void Front::on_rotate_spin_y_valueChanged(double arg1) {
  try {
    cont_->RotateFigure(ui_->rotate_spin_x->value(), arg1,
                        ui_->rotate_spin_z->value());
    cont_->DrawScene();
  } catch (std::runtime_error const &e) {
    ErrorMessage("Error", e.what());
  }
}

void Front::on_rotate_spin_z_valueChanged(double arg1) {
  try {
    cont_->RotateFigure(ui_->rotate_spin_x->value(),
                        ui_->rotate_spin_y->value(), arg1);
    cont_->DrawScene();
  } catch (std::runtime_error const &e) {
    ErrorMessage("Error", e.what());
  }
}

void Front::on_scale_spin_valueChanged(double arg1) {
  try {
    cont_->ScaleFigure(arg1, arg1, arg1);
    cont_->DrawScene();
  } catch (std::runtime_error const &e) {
    ErrorMessage("Error", e.what());
  }
}

void Front::on_horizontalScrollBar_vertexes_R_valueChanged(int value) {
  ui_->spinBox_vertexes_R->setValue(value);
  viewer_->SetVertexRedColor(static_cast<double>(value) / 100.0);

  ReDraw();
}

void Front::on_spinBox_vertexes_R_valueChanged(int arg1) {
  ui_->horizontalScrollBar_vertexes_R->setValue(arg1);
}

void Front::on_horizontalScrollBar_vertexes_G_valueChanged(int value) {
  ui_->spinBox_vertexes_G->setValue(value);
  viewer_->SetVertexGreenColor(static_cast<double>(value) / 100.0);

  ReDraw();
}

void Front::on_spinBox_vertexes_G_valueChanged(int arg1) {
  ui_->horizontalScrollBar_vertexes_G->setValue(arg1);
}

void Front::on_horizontalScrollBar_vertexes_B_valueChanged(int value) {
  ui_->spinBox_vertexes_B->setValue(value);
  viewer_->SetVertexBlueColor(static_cast<double>(value) / 100.0);

  ReDraw();
}

void Front::on_spinBox_vertexes_B_valueChanged(int arg1) {
  ui_->horizontalScrollBar_vertexes_B->setValue(arg1);
}

void Front::on_horizontalScrollBar_edges_R_valueChanged(int value) {
  ui_->spinBox_edges_R->setValue(value);
  viewer_->SetEdgesRedColor(static_cast<double>(value) / 100.0);

  ReDraw();
}

void Front::on_spinBox_edges_R_valueChanged(int arg1) {
  ui_->horizontalScrollBar_edges_R->setValue(arg1);
}

void Front::on_horizontalScrollBar_edges_G_valueChanged(int value) {
  ui_->spinBox_edges_G->setValue(value);
  viewer_->SetEdgesGreenColor(static_cast<double>(value) / 100.0);

  ReDraw();
}

void Front::on_spinBox_edges_G_valueChanged(int arg1) {
  ui_->horizontalScrollBar_edges_G->setValue(arg1);
}

void Front::on_horizontalScrollBar_edges_B_valueChanged(int value) {
  ui_->spinBox_edges_B->setValue(value);
  viewer_->SetEdgesBlueColor(static_cast<double>(value) / 100.0);

  ReDraw();
}

void Front::on_spinBox_edges_B_valueChanged(int arg1) {
  ui_->horizontalScrollBar_edges_B->setValue(arg1);
}

void Front::on_spinBox_bgr_R_valueChanged(int arg1) {
  ui_->horizontalScrollBar_bgr_R->setValue(arg1);
}

void Front::on_horizontalScrollBar_bgr_R_valueChanged(int value) {
  ui_->spinBox_bgr_R->setValue(value);
  viewer_->SetBgRedColor(static_cast<double>(value) / 100.0);

  ReDraw();
}

void Front::on_spinBox_bgr_G_valueChanged(int arg1) {
  ui_->horizontalScrollBar_bgr_G->setValue(arg1);
}

void Front::on_horizontalScrollBar_bgr_G_valueChanged(int value) {
  ui_->spinBox_bgr_G->setValue(value);
  viewer_->SetBgGreenColor(static_cast<double>(value) / 100.0);

  ReDraw();
}

void Front::on_spinBox_bgr_B_valueChanged(int arg1) {
  ui_->horizontalScrollBar_bgr_B->setValue(arg1);
}

void Front::on_horizontalScrollBar_bgr_B_valueChanged(int value) {
  ui_->spinBox_bgr_B->setValue(value);
  viewer_->SetBgBlueColor(static_cast<double>(value) / 100.0);

  ReDraw();
}

void Front::on_projection_type_currentIndexChanged(int index) {
  viewer_->SetIsParallel(index ? true : false);

  ReDraw();
}

void Front::on_spinBox_edges_size_valueChanged(int arg1) {
  viewer_->SetLineWidth(static_cast<float>(arg1));

  ReDraw();
}

void Front::on_spinBox_vertexes_size_valueChanged(int arg1) {
  viewer_->SetPointSize(static_cast<float>(arg1));

  ReDraw();
}

void Front::on_radioButton_quads_toggled(bool checked) {
  if (checked) {
    viewer_->SetVertexesType(kSquare);

    ReDraw();
  }
}

void Front::on_radioButton_norm_toggled(bool checked) {
  if (checked) {
    viewer_->SetVertexesType(kOff);

    ReDraw();
  }
}

void Front::on_radioButton_circles_toggled(bool checked) {
  if (checked) {
    viewer_->SetVertexesType(kCircles);

    ReDraw();
  }
}

void Front::on_radioButton_stipple_toggled(bool checked) {
  if (checked) {
    viewer_->SetLinesType(kStripple);

    ReDraw();
  }
}

void Front::on_radioButton_line_none_toggled(bool checked) {
  if (checked) {
    viewer_->SetLinesType(kOff);

    ReDraw();
  }
}

void Front::on_radioButton_line_smooth_toggled(bool checked) {
  if (checked) {
    viewer_->SetLinesType(kSmooth);

    ReDraw();
  }
}
