#ifndef DEPOSIT_H
#define DEPOSIT_H

#include <QWidget>
#include <qvalidator.h>

namespace Ui {
  class Deposit;
}

class Deposit : public QWidget
{
  Q_OBJECT

public:
  explicit Deposit(QWidget *parent = nullptr);
  ~Deposit();

private slots:
  void on_pushButton_clicked();

  void on_pushButton_2_clicked();

private:
  Ui::Deposit *ui;
  QIntValidator* month_val = new QIntValidator( 0, 100*12);
  QIntValidator* mortgage_val = new QIntValidator( 0, 100*1e6);
  QDoubleValidator* percent_val = new QDoubleValidator( 0.01, 10, 2, this);

};

#endif // DEPOSIT_H
