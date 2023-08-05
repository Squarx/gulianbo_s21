#ifndef DEBETCALC_H
#define DEBETCALC_H

#include "../common/MyQDoubleValidator.h"
#include "../controller/Controller.h"

namespace Ui {
class DebetCalc;
}

class DebetCalc : public QWidget {
  Q_OBJECT

 public:
  explicit DebetCalc(QWidget* parent = nullptr, s21::Controller* c = nullptr);
  ~DebetCalc();
 signals:
  void CalcWindow();

 private slots:
  void on_pushButton_go_back_clicked();

  void on_pushButton_start_clicked();

  void SettingUp(const QDate& date);

  void on_calendarWidget_activated(const QDate& date);

  void on_pushButton_confirm_clicked();

  void on_pushButton_select_put_clicked();

  void on_pushButton_custom_add_put_clicked();

  void on_pushButton_put_delete_clicked();

  void on_pushButton_calculate_clicked();

  void on_comboBox_put_currentTextChanged(const QString& arg1);

  void on_pushButton_start_put_clicked();

  void on_comboBox_withdraw_currentTextChanged(const QString& arg1);

  void on_pushButton_start_withdraw_clicked();

  void on_pushButton_select_withdraw_clicked();

  void on_pushButton_custom_add_withdraw_clicked();

  void on_pushButton_withdraw_delete_clicked();

  int GetFreq(const QString& button_text);

  bool Validate(int freq_put, int freq_withdraw);

  void RenderError(const QString& err = "Error");

 private:
  using TableColumns = s21::DebetModel::TableColumns;
  using ResultColumns = s21::DebetModel::ResultColumns;

  enum States { kDefaut, kStart, kPut, kWithdraw, kCPut, kCWithdraw };
  enum Period { kDay, kMonth, kYear, kOnce, kNo, kCustom };

  Ui::DebetCalc* ui;
  s21::Controller* controller_;
  QDate start_date;
  std::unique_ptr<QIntValidator> month_validator_;
  std::unique_ptr<MyQDoubleValidator> percents_validator_;
  std::unique_ptr<MyQDoubleValidator> operation_validator_;
  std::unique_ptr<MyQDoubleValidator> deposit_validator_;
  int state = kDefaut;
};

#endif  // DEBETCALC_H
