#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[]) {
  s21::CalcModel model;
  s21::CreditModel credit_model;
  s21::DebetModel debet_model;
  s21::Controller cont(&model, &credit_model, &debet_model);
  QApplication a(argc, argv);
  MainWindow w(nullptr, &cont);
  w.show();
  return a.exec();
}
