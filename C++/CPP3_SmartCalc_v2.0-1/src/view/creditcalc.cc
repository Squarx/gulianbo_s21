#include "creditcalc.h"

#include "ui_creditcalc.h"
CreditCalc::CreditCalc(QWidget* parent, s21::Controller* c)
    : QWidget(parent),
      ui(new Ui::CreditCalc),
      controller_(c),
      month_val(new QIntValidator(0, 800)),
      mortgage_val(new QIntValidator(0, 100 * 1e6)),
      percent_val(new QDoubleValidator(1e-2, 1e1, 2))

{
  ui->setupUi(this);
  percent_val->setLocale(QLocale::C);
  percent_val->setNotation(QDoubleValidator::StandardNotation);
  ui->lineEdit_percent->setValidator(percent_val);

  ui->lineEdit_sum->setValidator(mortgage_val);
  ui->lineEdit_month->setValidator(month_val);
  ui->radioButton_annu->setChecked(true);
  ui->lineEdit_sum->setText("200000");
  ui->lineEdit_percent->setText("12");
  ui->lineEdit_month->setText("24");
}

CreditCalc::~CreditCalc() {
  ui->tableWidget->clear();
  ui->tableWidget_results->clear();
  delete month_val;
  delete mortgage_val;
  delete percent_val;
  delete ui;
}

void CreditCalc::on_pushButton_go_back_clicked() {
  emit CalcWindow();
  this->close();
}

void CreditCalc::FillTable() {
  auto result = controller_->GetCreditResults();
  for (size_t i = 0; i < table[0]->size(); i++) {
    QTableWidgetItem* item_payment =
        new QTableWidgetItem(QString::number((*table[0])[i], 'f', 2));

    QTableWidgetItem* debt_ost_before =
        new QTableWidgetItem(QString::number(table[1]->at(i), 'f', 2));

    QTableWidgetItem* item_percent_part =
        new QTableWidgetItem(QString::number(table[2]->at(i), 'f', 2));

    QTableWidgetItem* monthly_payment =
        new QTableWidgetItem(QString::number(table[3]->at(i), 'f', 2));

    QTableWidgetItem* debt_ost_after =
        new QTableWidgetItem(QString::number(table[4]->at(i), 'f', 2));

    ui->tableWidget->setItem(i, 0, item_payment);
    ui->tableWidget->setItem(i, 1, debt_ost_before);
    ui->tableWidget->setItem(i, 2, item_percent_part);
    ui->tableWidget->setItem(i, 3, monthly_payment);
    ui->tableWidget->setItem(i, 4, debt_ost_after);
  }

  QTableWidgetItem* all_payments_q =
      new QTableWidgetItem(QString::number(result.at(0), 'f', 2));
  QTableWidgetItem* all_percents_q =
      new QTableWidgetItem(QString::number(result.at(1), 'f', 2));
  QTableWidgetItem* overpayment =
      new QTableWidgetItem(QString::number(result.at(2), 'f', 2));
  QTableWidgetItem* overpayment_percent =
      new QTableWidgetItem(QString::number(result.at(3), 'f', 2));

  ui->tableWidget_results->setRowCount(1);
  ui->tableWidget_results->setItem(0, 0, all_payments_q);
  ui->tableWidget_results->setItem(0, 1, all_percents_q);
  ui->tableWidget_results->setItem(0, 2, overpayment);
  ui->tableWidget_results->setItem(0, 3, overpayment_percent);
}

void CreditCalc::on_pushButton_clicked() {
  ui->tableWidget->clearContents();
  ui->tableWidget_results->clearContents();
  double mortgage = 0, percent = 0;
  int month = 0;
  mortgage = ui->lineEdit_sum->text().toDouble();
  percent = ui->lineEdit_percent->text().toDouble();
  month = ui->lineEdit_month->text().toDouble();
  ui->tableWidget->setRowCount(month);

  if (ui->radioButton_annu->isChecked()) {
    table = controller_->GetCreditAnnu(mortgage, percent, month);
  } else {
    table = controller_->GetCreditDiff(mortgage, percent, month);
  }
  FillTable();
}
