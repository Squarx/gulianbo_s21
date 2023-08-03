#include "mainwindow.h"

#include <QWidget>

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent, s21::Controller* controller)
    : QMainWindow(parent), ui(new Ui::MainWindow()), controller_(controller) {
  ui->setupUi(this);
  calc_view = new SmartCalcView(nullptr, controller_);
}

MainWindow::~MainWindow() {
  delete ui;
  delete calc_view;
}

void MainWindow::on_pushButton_clicked() {
  calc_view->show();
  this->close();
}
