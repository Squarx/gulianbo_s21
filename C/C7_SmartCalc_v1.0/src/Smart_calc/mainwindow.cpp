#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    calc = new Calc;

}

MainWindow::~MainWindow()
{
  delete calc;
  delete ui;

}


void MainWindow::on_pushButton_clicked()
{
    this->close();
    calc->show();
}


