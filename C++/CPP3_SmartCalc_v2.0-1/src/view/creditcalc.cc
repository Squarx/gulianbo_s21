#include "creditcalc.h"

#include "ui_creditcalc.h"
CreditCalc::CreditCalc(QWidget* parent, s21::Controller* c)
    : QWidget(parent),
      ui(new Ui::CreditCalc),
      controller_(c),
      month_val(std::make_unique<QIntValidator>(0, 800)),
      mortgage_val(std::make_unique<QIntValidator>(0, 100 * 1e6)),
      percent_val(std::make_unique<MyQDoubleValidator>(0.01, 50.00, 2, this)) {
  ui->setupUi(this);
  percent_val->setLocale(QLocale::C);
  percent_val->setNotation(QDoubleValidator::StandardNotation);
  ui->lineEdit_percent->setValidator(percent_val.get());
  ui->lineEdit_sum->setValidator(mortgage_val.get());
  ui->lineEdit_month->setValidator(month_val.get());
  ui->radioButton_annu->setChecked(true);
  ui->lineEdit_sum->setText("200000");
  ui->lineEdit_percent->setText("12");
  ui->lineEdit_month->setText("24");
}

CreditCalc::~CreditCalc() { delete ui; }

void CreditCalc::on_pushButton_go_back_clicked() {
  emit CalcWindow();
  this->close();
}

void CreditCalc::RenderError() {
  QTableWidgetItem* item_payment = new QTableWidgetItem("Error");

  QTableWidgetItem* debt_ost_before = new QTableWidgetItem("Error");

  QTableWidgetItem* item_percent_part = new QTableWidgetItem("Error");

  QTableWidgetItem* monthly_payment = new QTableWidgetItem("Error");

  QTableWidgetItem* debt_ost_after = new QTableWidgetItem("Error");
  ui->tableWidget->setRowCount(1);
  ui->tableWidget->setItem(0, 0, item_payment);
  ui->tableWidget->setItem(0, 1, debt_ost_before);
  ui->tableWidget->setItem(0, 2, item_percent_part);
  ui->tableWidget->setItem(0, 3, monthly_payment);
  ui->tableWidget->setItem(0, 4, debt_ost_after);
}

void CreditCalc::FillTable() {
  auto result = controller_->GetCreditResults();
  auto payment_column = table.find(TableColums::kMonthlyPayment)->second;
  auto debt_before_column = table.find(TableColums::kDebtBefore)->second;
  auto percent_part_column = table.find(TableColums::kPartPercents)->second;
  auto monthly_payment_column = table.find(TableColums::kPartDebt)->second;
  auto debt_after_column = table.find(TableColums::kDebtAfter)->second;
  if (payment_column->empty()) {
    RenderError();
    return;
  }
  for (size_t i = 0; i < table.find(TableColums::kDebtBefore)->second->size();
       i++) {
    QTableWidgetItem* item_payment =
        new QTableWidgetItem(QString::number(payment_column->at(i), 'f', 2));

    QTableWidgetItem* debt_ost_before = new QTableWidgetItem(
        QString::number(debt_before_column->at(i), 'f', 2));

    QTableWidgetItem* item_percent_part = new QTableWidgetItem(
        QString::number(percent_part_column->at(i), 'f', 2));

    QTableWidgetItem* monthly_payment = new QTableWidgetItem(
        QString::number(monthly_payment_column->at(i), 'f', 2));

    QTableWidgetItem* debt_ost_after =
        new QTableWidgetItem(QString::number(debt_after_column->at(i), 'f', 2));

    ui->tableWidget->setItem(i, 0, item_payment);
    ui->tableWidget->setItem(i, 1, debt_ost_before);
    ui->tableWidget->setItem(i, 2, item_percent_part);
    ui->tableWidget->setItem(i, 3, monthly_payment);
    ui->tableWidget->setItem(i, 4, debt_ost_after);
  }

  QTableWidgetItem* all_payments_q = new QTableWidgetItem(
      QString::number(result.find(TableColums::kResPayments)->second, 'f', 2));
  QTableWidgetItem* all_percents_q = new QTableWidgetItem(
      QString::number(result.find(TableColums::kResPercents)->second, 'f', 2));
  QTableWidgetItem* overpayment = new QTableWidgetItem(QString::number(
      result.find(TableColums::kResOverPayment)->second, 'f', 2));
  QTableWidgetItem* overpayment_percent = new QTableWidgetItem(QString::number(
      result.find(TableColums::kResOverPaymentPercentage)->second, 'f', 2));

  ui->tableWidget_results->setRowCount(1);
  ui->tableWidget_results->setItem(0, 0, all_payments_q);
  ui->tableWidget_results->setItem(0, 1, all_percents_q);
  ui->tableWidget_results->setItem(0, 2, overpayment);
  ui->tableWidget_results->setItem(0, 3, overpayment_percent);
}

void CreditCalc::on_pushButton_clicked() {
  ui->tableWidget->clearContents();
  ui->tableWidget_results->clearContents();
  long double mortgage = 0, percent = 0;
  int month = 0;
  mortgage = ui->lineEdit_sum->text().toDouble();
  percent = ui->lineEdit_percent->text().toDouble();
  month = ui->lineEdit_month->text().toDouble();
  ui->tableWidget->setRowCount(month);
  bool is_annu = ui->radioButton_annu->isChecked();
  table = controller_->GetCreditTable(mortgage, percent, month, is_annu);
  FillTable();
}
