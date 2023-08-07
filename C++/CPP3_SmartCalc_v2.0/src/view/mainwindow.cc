#include "mainwindow.h"

#include <QWidget>

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent, s21::Controller* controller)
    : QMainWindow(parent),
      ui(new Ui::MainWindow()),
      controller_(controller),
      calc_view(std::make_unique<SmartCalcView>(nullptr, controller)) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_pushButton_clicked() {
  calc_view->show();
  this->close();
}
