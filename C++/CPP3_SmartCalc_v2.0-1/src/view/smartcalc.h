#ifndef SMARTCALC_H
#define SMARTCALC_H

#include <QKeyEvent>
#include <QRegularExpression>
#include <QRegularExpressionValidator>

#include "../controller/Controller.h"
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

 private:
  const QRegularExpression r_theory_of_everything{
      R"(^((\d*[.])?\d+([eE][-+]?\d+)?|([+\-*\/^]{1})?|(\(|\))?|(mod|cos\(|sin\(|tan\(|acos\(|asin\(|atan\(|sqrt\(|ln\(|log\(|(\s))?|(x|X)?)+$)"};

  Ui::SmartCalc *ui;
  s21::Controller *controller_;
  QDoubleValidator *float_validator_;
  QValidator *validator_input_;
  QPlot *plot_view_;
  CreditCalc *credit_view_;
  DebetCalc *debet_view_;
};

#endif  // SMARTCALC_H
