#ifndef SMARTCALC_H
#define SMARTCALC_H

#include <QKeyEvent>
#include <QRegularExpression>
#include <QRegularExpressionValidator>

#include "../common/myqdoublevalidator.h"
#include "../controller/controller.h"
#include "creditcalc.h"
#include "debetcalc.h"
#include "qplot.h"

namespace Ui {
class SmartCalc;
}

class SmartCalcView : public QWidget {
  Q_OBJECT

 public:
  explicit SmartCalcView(QWidget *parent = nullptr,
                         s21::Controller *controller = nullptr);
  SmartCalcView(const SmartCalcView &) = delete;
  SmartCalcView &operator=(const SmartCalcView &) = delete;
  ~SmartCalcView();

 protected:
  void keyPressEvent(QKeyEvent *e) override;

 private slots:

  void on_pushButton_eq_clicked();

  void on_listWidget_doubleClicked();

  void digits_numbers();

  void on_pushButton_AC_clicked();

  void on_pushButton_rm_clicked();

  void trigonometric_func();

  void on_checkBox_KeyboardMode_stateChanged();

  void on_pushButton_to_gpaph_clicked();

  void on_pushButton_to_credit_clicked();

  void on_pushButton_to_debet_clicked();

  void SetUpExpressions();

  void SetUpValidators();

  void SetUpConnect();

 private:
  const QRegularExpression r_theory_of_everything_{
      R"(^((\d*[.])?\d+([eE][-+]?\d+)?|([+\-*\/^]{1})?|(\(|\))?|(mod|cos\(|sin\(|tan\(|acos\(|asin\(|atan\(|sqrt\(|ln\(|log\(|(\s))?|(x|X)?)+$)"};

  Ui::SmartCalc *ui;
  s21::Controller *controller_;
  std::unique_ptr<MyQDoubleValidator> float_validator_;
  std::unique_ptr<QValidator> validator_input_;
  std::unique_ptr<QPlot> plot_view_;
  std::unique_ptr<CreditCalc> credit_view_;
  std::unique_ptr<DebetCalc> debet_view_;
};

#endif  // SMARTCALC_H
