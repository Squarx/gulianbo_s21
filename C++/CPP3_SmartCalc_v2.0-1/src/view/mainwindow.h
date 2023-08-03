#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "smartcalc.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  //  MainWindow(QWidget *parent = nullptr);
  MainWindow(QWidget* parent = nullptr, s21::Controller* controller = nullptr);
  ~MainWindow();

 private slots:
  void on_pushButton_clicked();

 private:
  Ui::MainWindow* ui;
  s21::Controller* controller_;
  SmartCalcView* calc_view;
};
#endif  // MAINWINDOW_H
