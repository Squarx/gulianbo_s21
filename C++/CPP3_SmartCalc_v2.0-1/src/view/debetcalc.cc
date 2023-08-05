#include "debetcalc.h"

#include "ui_debetcalc.h"

DebetCalc::DebetCalc(QWidget* parent, s21::Controller* c)
    : QWidget(parent),
      ui(new Ui::DebetCalc),
      controller_(c),
      month_validator_(std::make_unique<QIntValidator>(0, 800)),
      percents_validator_(std::make_unique<MyQDoubleValidator>(0.00, 50.00, 2)),
      operation_validator_(
          std::make_unique<MyQDoubleValidator>(0.00, 10000.00, 2)),
      deposit_validator_(std::make_unique<MyQDoubleValidator>(0.00, 1e10, 2)) {
  ui->setupUi(this);
  ui->calendarWidget->setMinimumDate(QDate::currentDate());
  ui->lineEdit_months->setValidator(month_validator_.get());
  percents_validator_->setLocale(QLocale::C);
  percents_validator_->setNotation(QDoubleValidator::StandardNotation);
  operation_validator_->setLocale(QLocale::C);
  operation_validator_->setNotation(QDoubleValidator::StandardNotation);
  deposit_validator_->setLocale(QLocale::C);
  deposit_validator_->setNotation(QDoubleValidator::StandardNotation);
  ui->lineEdit_inerest_rate->setValidator(percents_validator_.get());
  ui->lineEdit_tax_rate->setValidator(percents_validator_.get());
  ui->lineEdit_custom_sum_put->setValidator(operation_validator_.get());
  ui->lineEdit_custom_sum_withdraw->setValidator(operation_validator_.get());
  ui->lineEdit_sum_put->setValidator(operation_validator_.get());
  ui->lineEdit_sum_withdraw->setValidator(operation_validator_.get());
  ui->lineEdit_sum_deposit->setValidator(deposit_validator_.get());

  ui->lineEdit_sum_deposit->setText("100000");
  ui->label_date_start->setText("01-08-2023");
  ui->lineEdit_months->setText("12");
  ui->lineEdit_inerest_rate->setText("12");
  ui->lineEdit_tax_rate->setText("13");
  ui->calendarWidget->hide();
  ui->custom_put_view->hide();
  ui->custom_withdraw_view->hide();
  ui->lineEdit_sum_put->hide();
  ui->label_start_date_put->hide();
  ui->pushButton_start_put->hide();
  ui->lineEdit_sum_withdraw->hide();
  ui->label_start_date_withdraw->hide();
  ui->pushButton_start_withdraw->hide();
  for (int col = 0; col < ui->tableWidget_result->columnCount(); ++col) {
    ui->tableWidget_result->horizontalHeader()->setSectionResizeMode(
        col, QHeaderView::Fixed);
  }
  setStyleSheet(
      "QGridLayout{ border: 1px white; } QLabel { border: 1px solid grey; "
      "padding: 1px; }");
}

DebetCalc::~DebetCalc() { delete ui; }

void DebetCalc::on_pushButton_go_back_clicked() {
  emit CalcWindow();
  this->close();
}

void DebetCalc::on_pushButton_start_clicked() {
  state = kStart;
  ui->calendarWidget->show();
}

void DebetCalc::SettingUp(const QDate& date) {
  if (state == kStart) {
    ui->label_date_start->setText(date.toString("dd-MM-yyyy"));
    start_date = date;
  } else if (state == kCPut) {
    ui->label_custom_date_put->setText(date.toString("dd-MM-yyyy"));
  } else if (state == kPut) {
    ui->label_start_date_put->setText(date.toString("dd-MM-yyyy"));
  } else if (state == kWithdraw) {
    ui->label_start_date_withdraw->setText(date.toString("dd-MM-yyyy"));
  } else if (state == kCWithdraw) {
    ui->label_custom_date_withdraw->setText(date.toString("dd-MM-yyyy"));
  }
  state = kDefaut;
}

void DebetCalc::on_calendarWidget_activated(const QDate& date) {
  SettingUp(date);
  ui->calendarWidget->hide();
}

void DebetCalc::on_pushButton_select_put_clicked() {
  state = kCPut;
  ui->calendarWidget->show();
}

void DebetCalc::on_pushButton_confirm_clicked() {
  int cnt_m = ui->lineEdit_months->text().toInt();
  start_date = QDate::fromString(ui->label_date_start->text(), "dd-MM-yyyy");
  QDate end = start_date.addMonths(cnt_m);
  ui->label_end_date->setText(end.toString("dd-MM-yyyy"));
}

void DebetCalc::on_pushButton_custom_add_put_clicked() {
  try {
    int cnt_rows = ui->tableWidget_put->rowCount();
    QString sum = ui->lineEdit_custom_sum_put->text();

    QString date = ui->label_custom_date_put->text();
    QList<QTableWidgetItem*> found_items =
        ui->tableWidget_put->findItems(date, Qt::MatchExactly);
    if (found_items.isEmpty()) {
      QTableWidgetItem* sum_item = new QTableWidgetItem(sum);
      QTableWidgetItem* date_item = new QTableWidgetItem(date);

      ui->tableWidget_put->setRowCount(cnt_rows + 1);
      ui->tableWidget_put->setItem(cnt_rows, 1, sum_item);
      ui->tableWidget_put->setItem(cnt_rows, 0, date_item);
    }
  } catch (const std::exception& e) {
    RenderError(e.what());
  }
}

void DebetCalc::on_pushButton_put_delete_clicked() {
  auto selected_indexes =
      ui->tableWidget_put->selectionModel()->selectedIndexes();
  QList<int> rows_to_delete;
  for (const auto& index : selected_indexes) {
    if (!rows_to_delete.contains(index.row())) {
      rows_to_delete.append(index.row());
    }
  }

  std::sort(rows_to_delete.begin(), rows_to_delete.end(), std::greater<int>());

  for (int row : rows_to_delete) {
    ui->tableWidget_put->removeRow(row);
  }
}

void DebetCalc::on_comboBox_put_currentTextChanged(const QString& arg1) {
  if (arg1 == "Custom" || arg1 == "No") {
    ui->lineEdit_sum_put->hide();
    ui->label_start_date_put->hide();
    ui->pushButton_start_put->hide();
    if (arg1 != "No")
      ui->custom_put_view->show();
    else
      ui->custom_put_view->hide();
  } else {
    ui->lineEdit_sum_put->show();
    ui->label_start_date_put->show();
    ui->pushButton_start_put->show();
    ui->custom_put_view->hide();
  }
}

void DebetCalc::on_pushButton_start_put_clicked() {
  state = kPut;
  ui->calendarWidget->show();
}

void DebetCalc::on_comboBox_withdraw_currentTextChanged(const QString& arg1) {
  if (arg1 == "Custom" || arg1 == "No") {
    ui->lineEdit_sum_withdraw->hide();
    ui->label_start_date_withdraw->hide();
    ui->pushButton_start_withdraw->hide();
    if (arg1 != "No") {
      ui->custom_withdraw_view->show();
    } else {
      ui->custom_withdraw_view->hide();
    }
  } else {
    ui->lineEdit_sum_withdraw->show();
    ui->label_start_date_withdraw->show();
    ui->pushButton_start_withdraw->show();
    ui->custom_withdraw_view->hide();
  }
}

void DebetCalc::on_pushButton_start_withdraw_clicked() {
  state = kWithdraw;
  ui->calendarWidget->show();
}

void DebetCalc::on_pushButton_select_withdraw_clicked() {
  state = kCWithdraw;
  ui->calendarWidget->show();
}

void DebetCalc::on_pushButton_custom_add_withdraw_clicked() {
  try {
    int cnt_rows = ui->tableWidget_withdraw->rowCount();
    QString sum = ui->lineEdit_custom_sum_withdraw->text();

    QString date = ui->label_custom_date_withdraw->text();
    QList<QTableWidgetItem*> found_items =
        ui->tableWidget_withdraw->findItems(date, Qt::MatchExactly);
    if (found_items.isEmpty()) {
      QTableWidgetItem* sum_item = new QTableWidgetItem(sum);
      QTableWidgetItem* date_item = new QTableWidgetItem(date);

      ui->tableWidget_withdraw->setRowCount(cnt_rows + 1);
      ui->tableWidget_withdraw->setItem(cnt_rows, 1, sum_item);
      ui->tableWidget_withdraw->setItem(cnt_rows, 0, date_item);
    }
  } catch (const std::exception& e) {
    RenderError(e.what());
  }
}

void DebetCalc::on_pushButton_withdraw_delete_clicked() {
  auto selectedIndexes =
      ui->tableWidget_withdraw->selectionModel()->selectedIndexes();
  QList<int> rowsToDelete;
  for (const auto& index : selectedIndexes) {
    if (!rowsToDelete.contains(index.row())) {
      rowsToDelete.append(index.row());
    }
  }
  std::sort(rowsToDelete.begin(), rowsToDelete.end(), std::greater<int>());
  for (int row : rowsToDelete) {
    ui->tableWidget_withdraw->removeRow(row);
  }
}

void DebetCalc::RenderError(const QString& err) {
  ui->label_res_percents->setText(err);
  ui->label_res_taxes->setText(err);
  ui->label_res_deposit->setText(err);
  ui->label_all_puts->setText(err);
  ui->label_all_withdraws->setText(err);
}
int DebetCalc::GetFreq(const QString& button_text) {
  int freq = 0;
  if (button_text == "Daily") freq = kDay;
  if (button_text == "Monthly") freq = kMonth;
  if (button_text == "Annually") freq = kYear;
  if (button_text == "Custom") freq = kCustom;
  if (button_text == "Once") freq = kOnce;
  if (button_text == "No") freq = kNo;
  return freq;
}

bool DebetCalc::Validate(int freq_put, int freq_withdraw) {
  bool result = true;
  if (freq_put == kMonth || freq_put == kYear) {
    if ((ui->label_start_date_put->text().isEmpty() ||
         ui->lineEdit_sum_put->text().isEmpty()))
      result = false;
  }
  if (freq_withdraw == kMonth || freq_withdraw == kYear) {
    if ((ui->label_start_date_withdraw->text().isEmpty() ||
         ui->lineEdit_sum_withdraw->text().isEmpty()))
      result = false;
  }
  if (freq_put == kCustom && (ui->tableWidget_put->rowCount() == 0))
    result = false;
  if (freq_withdraw == kCustom && (ui->tableWidget_withdraw->rowCount() == 0))
    result = false;
  return result;
}
void DebetCalc::on_pushButton_calculate_clicked() {
  ui->pushButton_confirm->click();
  ui->tableWidget_result->clearContents();
  ui->tableWidget_result->setRowCount(0);

  double deposit = ui->lineEdit_sum_deposit->text().toDouble();
  QDate start = QDate::fromString(ui->label_date_start->text(), "dd-MM-yyyy");
  QDate end = QDate::fromString(ui->label_end_date->text(), "dd-MM-yyyy");
  double interest_rate = ui->lineEdit_inerest_rate->text().toDouble();
  double tax_rate = ui->lineEdit_tax_rate->text().toDouble();
  int freq = GetFreq(ui->comboBox_freq_payment->currentText());
  bool capitalize = ui->comboBox_capitalization->currentText() == "Yes";
  int freq_put = GetFreq(ui->comboBox_put->currentText());
  double put_sum = ui->lineEdit_sum_put->text().toDouble();
  QDate start_put =
      QDate::fromString(ui->label_start_date_put->text(), "dd-MM-yyyy");

  int freq_withdraw = GetFreq(ui->comboBox_withdraw->currentText());
  double withdraw_sum = ui->lineEdit_sum_withdraw->text().toDouble();
  QDate start_withdraw =
      QDate::fromString(ui->label_start_date_withdraw->text(), "dd-MM-yyyy");

  if (!Validate(freq_put, freq_withdraw)) {
    RenderError();
    return;
  }
  auto res = controller_->GetDebetTable(
      deposit, start, end, interest_rate, tax_rate, freq, capitalize, freq_put,
      put_sum, start_put, freq_withdraw, withdraw_sum, start_withdraw,
      ui->tableWidget_put, ui->tableWidget_withdraw);
  auto table = res.first;
  auto out = res.second;
  if (table->empty()) {
    RenderError();
    return;
  }
  ui->tableWidget_result->setRowCount(table->size());
  for (size_t i = 0; i < table->size(); ++i) {
    for (size_t j = 0; j < table->at(i).size(); ++j) {
      QTableWidgetItem* item = new QTableWidgetItem(table->at(i).at(j));
      ui->tableWidget_result->setItem(i, j, item);
    }
  }

  ui->label_res_percents->setText(out->at(ResultColumns::kAllPercents));
  ui->label_res_taxes->setText(out->at(ResultColumns::kAllTaxes));
  ui->label_res_deposit->setText(out->at(ResultColumns::kAllDeposit));
  ui->label_all_puts->setText(out->at(ResultColumns::kAllPuts));
  ui->label_all_withdraws->setText(out->at(ResultColumns::kAllWithdraws));
}
