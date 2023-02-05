#ifndef TRUE_DEPOSIT_H
#define TRUE_DEPOSIT_H

#include <QWidget>
#include <qvalidator.h>

namespace Ui {
  class true_deposit;
}

class true_deposit : public QWidget
{
  Q_OBJECT

public:
  explicit true_deposit(QWidget *parent = nullptr);
  ~true_deposit();

private slots:
  void on_pushButton_clicked();

  void on_pushButton_2_clicked();

private:
  Ui::true_deposit *ui;
  QIntValidator* month_val = new QIntValidator( 0, 1024);
  QDoubleValidator* deposit_val = new QDoubleValidator( 0.01, 1e8, 2, this);
  QDoubleValidator* percent_val = new QDoubleValidator( 0.01, 10, 2, this);
};

#endif // TRUE_DEPOSIT_H
