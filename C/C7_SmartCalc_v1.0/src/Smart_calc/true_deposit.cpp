#include "true_deposit.h"
#include "ui_true_deposit.h"
#include "mainwindow.h"
enum times {
  DAY = 1,
  MONTH = 3,
  YEAR = 4,
  END = 5,
};
true_deposit::true_deposit(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::true_deposit)
{
  ui->setupUi(this);
  ui->radioButton_per_pay_once->setChecked(1);
  ui->radioButton_cap_no->setChecked(1);
  ui->radioButton_refill_no->setChecked(1);
  ui->radioButton_with_no->setChecked(1);
  percent_val->setNotation(QDoubleValidator::StandardNotation);
  deposit_val->setNotation(QDoubleValidator::StandardNotation);
  ui->lineEdit_get_deposit->setValidator(deposit_val);
  ui->lineEdit_get_percent->setValidator(percent_val);
  ui->lineEdit_get_percent_tax->setValidator(percent_val);
  ui->lineEdit_get_time->setValidator(month_val);
  ui->lineEdit_get_additional_refill->setValidator(deposit_val);
  ui->lineEdit_get_additional_withdrawal->setValidator(deposit_val);
}

true_deposit::~true_deposit()
{
  delete deposit_val;
  delete month_val;
  delete percent_val;
  delete ui;
}

void true_deposit::on_pushButton_clicked()
{
  double deposit = ui->lineEdit_get_deposit->text().toDouble();
  int time = ui->lineEdit_get_time->text().toInt(); // month
  double percent = ui->lineEdit_get_percent->text().toDouble();
  percent /= 100;

  // PAYMENTS
  int periodicy_of_payments = 0;
  if (ui->radioButton_per_pay_day->isChecked()) periodicy_of_payments = DAY;
  if (ui->radioButton_per_pay_month->isChecked()) periodicy_of_payments = MONTH;
  if (ui->radioButton_per_pay_year->isChecked()) periodicy_of_payments = YEAR;
  if (ui->radioButton_per_pay_once->isChecked()) periodicy_of_payments = END;
  // KAPITALIZATION
  int capitalization = ui->radioButton_cap_yes->isChecked();
  // REFILL
  int refill_available = !(ui->radioButton_refill_no->isChecked());
  double payment_refill = 0;
  int periodicy_of_refilling = 0;
  if (refill_available) {
      payment_refill = ui->lineEdit_get_additional_refill->text().toDouble();
      if (ui->radioButton_refill_month->isChecked()) periodicy_of_refilling = MONTH;
      if (ui->radioButton_refill_year->isChecked()) periodicy_of_refilling = YEAR;
    }
  // WITHDRAW
  int withdraw_available = !(ui->radioButton_with_no->isChecked());
  double payment_withdraw = 0;
  int periodicy_of_withdrawing = 0;
  if (withdraw_available) {
      payment_withdraw = ui->lineEdit_get_additional_withdrawal->text().toDouble();
      if (ui->radioButton_with_month->isChecked()) periodicy_of_withdrawing = MONTH;
      if (ui->radioButton_with_year->isChecked()) periodicy_of_withdrawing = YEAR;
    }
  // TAXES
  double key_rate = 0;
  key_rate  = ui->lineEdit_get_percent_tax->text().toDouble();
  key_rate /= 100;

  // for capitalization == 0
  double res_percents_no_cap = 0;
  // tmp
  double start_dep = deposit;
  double nalog = 0;
  double tmp_percents_cap_dep_zero = 0;
  //

  for (int i = 1; deposit > 0 && i <= time * 31; i++) {
      if (capitalization == 0) {
          if (periodicy_of_payments == YEAR && i % (12 * 31) == 0) {
              res_percents_no_cap += deposit * percent;
            }
          if (periodicy_of_payments == MONTH && i % 31 == 0) {
              res_percents_no_cap += deposit * percent / 12;
            }
          if (periodicy_of_payments == DAY) {
              res_percents_no_cap += deposit * percent / 12 / 31;
            }
        } else {
          double tmp = deposit;

          if ((periodicy_of_payments == 4) && ((i % (12 * 31)) == 0)) {

              deposit += deposit * percent;

              tmp_percents_cap_dep_zero += (deposit - tmp);
            }
          if (periodicy_of_payments == MONTH && i % 31 == 0 ) {
              deposit += deposit * percent / 12;
              tmp_percents_cap_dep_zero += (deposit - tmp);
            }
          if (periodicy_of_payments == DAY) {
              deposit += deposit * percent / 12. / 31.;
              tmp_percents_cap_dep_zero += deposit - tmp;
            }
        }

      if (periodicy_of_refilling == MONTH && i % 31 == 0  && i != 0) {
          deposit += payment_refill;
        }
      if (periodicy_of_refilling == YEAR && i % (12 * 31) == 0 && i != 0) {
          deposit += payment_refill;
        }

      if (periodicy_of_withdrawing == MONTH && i % 31 == 0 && i != 0) {
          if (deposit - payment_withdraw > 0) {
              deposit -= payment_withdraw;
            }
          else {
              //              tmp_percents_cap_dep_zero += deposit;
              deposit = 0;
            }
        }
      if (periodicy_of_withdrawing == YEAR && i % (12 * 31) == 0) {
          if (deposit - payment_withdraw > 0) deposit -= payment_withdraw;
          else {
              //              tmp_percents_cap_dep_zero += deposit;
              deposit = 0;
            }
        }

    }
  if (periodicy_of_payments == END && deposit > 0) {
      if (capitalization) {
          deposit += deposit * (percent/12. * time);
        } else {
          res_percents_no_cap = deposit * (percent/12. * time);
        }
    }


  // taxes
  double cmp_sum = key_rate * 1e6;
  if (capitalization == 1) {
      if ((deposit - start_dep) > cmp_sum) {
          nalog = (deposit - start_dep) * 0.13;
          deposit -= nalog;
        }
    } else {
      if (res_percents_no_cap > cmp_sum) {
          nalog = res_percents_no_cap * 0.13;
          res_percents_no_cap -= nalog;
        }
    }
  // OUT
  if (capitalization) {
      ui->lineEdit_res_percents->setText(QString::number(tmp_percents_cap_dep_zero, 'f', 2));
//      else ui->lineEdit_res_percents->setText(QString::number(tmp_percents_cap_dep_zero, 'f', 2));
    } else {
      ui->lineEdit_res_percents->setText(QString::number(res_percents_no_cap, 'f', 2));
    }
  ui->lineEdit_res_taxes->setText(QString::number(nalog, 'f', 2));
  ui->lineEdit_res_deposit->setText(QString::number(deposit, 'f', 2));

}


void true_deposit::on_pushButton_2_clicked()
{
  MainWindow* start = new MainWindow;
  this->close();
  start->show();
}

