#ifndef CREDITCALC_H
#define CREDITCALC_H

#include "../controller/Controller.h"

namespace Ui {
class CreditCalc;
}

class CreditCalc : public QWidget {
  Q_OBJECT

 public:
  explicit CreditCalc(QWidget* parent = nullptr, s21::Controller* c = nullptr);
  ~CreditCalc();
 signals:
  void CalcWindow();

 private slots:
  void on_pushButton_go_back_clicked();

  void on_pushButton_clicked();

 private:
  void FillTable();

  Ui::CreditCalc* ui;
  s21::Controller* controller_;
  QIntValidator* month_val;
  QIntValidator* mortgage_val;
  QDoubleValidator* percent_val;
  std::array<std::vector<double>*, 5> table{};
};

#endif  // CREDITCALC_H
