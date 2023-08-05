#ifndef CREDITCALC_H
#define CREDITCALC_H

#include "../common/MyQDoubleValidator.h"
#include "../controller/Controller.h"
namespace Ui {
class CreditCalc;
}

class CreditCalc : public QWidget {
  Q_OBJECT

 public:
  explicit CreditCalc(QWidget* parent = nullptr, s21::Controller* c = nullptr);
  CreditCalc(const CreditCalc&) = delete;
  CreditCalc& operator=(const CreditCalc&) = delete;
  ~CreditCalc();
 signals:
  void CalcWindow();

 private slots:
  void on_pushButton_go_back_clicked();

  void on_pushButton_clicked();

  void RenderError();

 private:
  using TableColums = s21::CreditModel::TableColums;
  void FillTable();
  Ui::CreditCalc* ui;
  s21::Controller* controller_;
  std::unique_ptr<QIntValidator> month_val;
  std::unique_ptr<QIntValidator> mortgage_val;
  std::unique_ptr<MyQDoubleValidator> percent_val;
  std::map<TableColums, std::vector<long double>*> table{};
};

#endif  // CREDITCALC_H
