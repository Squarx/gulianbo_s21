#include "qt_draw_scene.h"

void QtDrawScene::SetVertexColor(double red, double green, double blue) {
  vertex_color_r_ = red;
  vertex_color_g_ = green;
  vertex_color_b_ = blue;
}

void QtDrawScene::SetVertexRedColor(double red) { vertex_color_r_ = red; }

void QtDrawScene::SetVertexGreenColor(double green) { vertex_color_g_ = green; }

void QtDrawScene::SetVertexBlueColor(double blue) { vertex_color_b_ = blue; }

void QtDrawScene::SetEdgesColor(double red, double green, double blue) {
  edges_color_r_ = red;
  edges_color_g_ = green;
  edges_color_b_ = blue;
}

void QtDrawScene::SetEdgesRedColor(double red) { edges_color_r_ = red; }

void QtDrawScene::SetEdgesGreenColor(double green) { edges_color_g_ = green; }

void QtDrawScene::SetEdgesBlueColor(double blue) { edges_color_b_ = blue; }

void QtDrawScene::SetBgColor(double red, double green, double blue) {
  bg_color_r_ = red;
  bg_color_g_ = green;
  bg_color_b_ = blue;
}

void QtDrawScene::SetBgRedColor(double red) { bg_color_r_ = red; }

void QtDrawScene::SetBgGreenColor(double green) { bg_color_g_ = green; }

void QtDrawScene::SetBgBlueColor(double blue) { bg_color_b_ = blue; }
