#include "smartcalc.h"

#include "creditcalc.h"
#include "ui_smartcalc.h"

SmartCalcView::SmartCalcView(QWidget* parent, s21::Controller* controller)
    : QWidget(parent),
      ui(new Ui::SmartCalc),
      controller_(controller),
      float_validator_(new QDoubleValidator(-1e6, 1e6, 6, this)),
      validator_input_(
          new QRegularExpressionValidator(r_theory_of_everything, this)),
      plot_view_(new QPlot(nullptr, controller)),
      credit_view_(new CreditCalc(nullptr, controller)),
      debet_view_(new DebetCalc(nullptr, controller))

{
  ui->setupUi(this);

  float_validator_->setLocale(QLocale::C);
  float_validator_->setNotation(QDoubleValidator::StandardNotation);
  ui->LineInput->setValidator(validator_input_);
  ui->lineEdit_x_value->setValidator(float_validator_);

  QList<QAbstractButton*> buttons = ui->NumsGroup->buttons();
  for (QAbstractButton* button : buttons)
    connect(button, &QPushButton::clicked, this,
            &SmartCalcView::digits_numbers);

  buttons = ui->TrigonometricGroup->buttons();
  for (QAbstractButton* button : buttons)
    connect(button, &QPushButton::clicked, this,
            &SmartCalcView::trigonometric_func);

  ui->LineInput->setText("0");
  ui->LineInput->setReadOnly(1);

  connect(plot_view_, &QPlot::CalcWindow, this, &SmartCalcView::show);
  connect(credit_view_, &CreditCalc::CalcWindow, this, &SmartCalcView::show);
  connect(debet_view_, &DebetCalc::CalcWindow, this, &SmartCalcView::show);

  std::vector<QString> set_up;
  set_up.push_back(
      "((((8 - 2 * 4) ^ 2 + 15) * 3 - 5) / 2) + (4 mod 3) * (2 ^ 3) - (10 / 5) "
      "* (-2 + 1)");
  set_up.push_back("(((7 + 3) * (6 - 2)) ^ 3 mod 5) / 4");
  set_up.push_back(
      "((((8 - 2 * 4) ^ 2 + 15) * 3 - 5) / 2) + (4 mod 3.3) * (2 ^ 3) - (10 / "
      "5) * (-2 + 1) + cos(0) - sin(30) * tan(45) + acos(1/23.2^2) * "
      "asin(atan(log(123.2^2/6)) * asin(123.123^-2)) / atan(1) + sqrt(16) - "
      "ln(1) + log(100)");
  set_up.push_back("(7 + 2) * (10 - 3) ^ 2 - 6 mod 6");
  set_up.push_back("((((9 + 3) ^ 2) mod 7) + 4 * (8 - 2)) ^ 3 - 1");
  set_up.push_back("((((8 * 2) - (6 ^ 2)) mod 5) + 3 * 4) / (7 + 1)");
  set_up.push_back("((6 * 2 ^ 3) + 7 mod 5) - ((10 / 2) ^ 2) + 3");
  set_up.push_back("(((-3 + 7) * 5) ^ 2 + 6 / 2) mod 4");
  set_up.push_back("(((9 - 2) ^ 3) mod 5 * (7 - 4)) + 12 / 4");
  set_up.push_back(
      "sin(45) + cos(30) * tan(60) - acos(0.5) * asin(0.25) / atan(1) + "
      "sqrt(25) - ln(1) + log(100)");
  set_up.push_back("(tan(90) + sin(60) * cos(30)) / (log(100) - sqrt(16))");
  set_up.push_back(
      "((asin(0.5) ^ 2) + (acos(0.3) * atan(1.2))) / (tan(45) + sin(30))");
  set_up.push_back(
      "((((8 - 2 * 4) ^ 2 + 15) * 3 - 5) / 2) + (4 mod 3) * (2 ^ 3) - (10 / 5) "
      "* (-2 + 1) + cos(0) - sin(30) * tan(45) + acos(1/23.2^2) * "
      "asin(atan(log(123.2^2/6)) * asin(123.123^-2)) / atan(1) + sqrt(16) - "
      "ln(1) + log(100) + sin(45) + cos(30) * tan(60) - acos(0.5) * asin(0.25) "
      "/ atan(1) + sqrt(25) - ln(1) + log(100) + (tan(90) + sin(60) * cos(30)) "
      "/ (log(100) - sqrt(16)) + ((asin(0.5) ^ 2) + (acos(0.3) * atan(1.2))) / "
      "(tan(45) + sin(30))");
  set_up.push_back("Errors");
  set_up.push_back("((4 + 2) * 3 - 5)) / 2");
  set_up.push_back(
      "(((8 - 2 * 4) ^ 2 + 15) * 3 - 5) / 2) + (4 mod 3) * (2 ^ 3) - (10 / 5) "
      "* (-2 + 1)");
  set_up.push_back(
      "(((8 - 2 * 4) ^ 2 + 15) * 3 - 5) / (2.123 ^ 2)) + (4 mod 3) * (2 ^ 3) - "
      "(10 / 5) * (-2 + 1)");
  set_up.push_back("(((7 + 3) * (6 - 2) ^ 3 mod 5) / 4");
  set_up.push_back("cos(45 + sin(30) - tan(60)");
  set_up.push_back("acos(0.5) * asin(0.25) / atan(1)");
  for (const QString& expression : set_up) {
    ui->listWidget->addItem(expression);
  }
}

SmartCalcView::~SmartCalcView() {
  delete ui;
  delete float_validator_;
  delete validator_input_;
  delete plot_view_;
  delete credit_view_;
  delete debet_view_;
}

void SmartCalcView::on_pushButton_eq_clicked() {
  QString currentText = ui->LineInput->text();
  bool textFound = false;

  for (int i = 0; i < ui->listWidget->count() && !textFound; ++i)
    if (currentText == ui->listWidget->item(i)->text()) textFound = true;

  if (!textFound) {
    ui->listWidget->insertItem(0, currentText);
  }

  ui->LineInput->setText(QString::fromStdString(controller_->GetResult(
      currentText.toStdString(), ui->lineEdit_x_value->text().toStdString())));
}

void SmartCalcView::on_listWidget_doubleClicked() {
  QListWidgetItem* item = ui->listWidget->currentItem();

  if (item) {
    QString text = item->text();
    ui->LineInput->setText(text);
    ui->LineInput->setFocus(Qt::OtherFocusReason);
  }
}

void SmartCalcView::digits_numbers() {
  QPushButton* button = (QPushButton*)sender();
  if (ui->LineInput->text() == '0' && button->text() != "0" &&
      button->text() != '.')
    ui->LineInput->setText("");
  if (!(ui->LineInput->text() == '0' && button->text() == '0'))
    ui->LineInput->setText(ui->LineInput->text() + button->text());
}

void SmartCalcView::on_pushButton_AC_clicked() { ui->LineInput->setText("0"); }

void SmartCalcView::on_pushButton_rm_clicked() {
  ui->LineInput->backspace();
  if (ui->LineInput->text() == "") ui->LineInput->setText("0");
}

void SmartCalcView::trigonometric_func() {
  if (ui->LineInput->text() == '0') ui->LineInput->setText("");
  QPushButton* button = (QPushButton*)sender();
  QString tmp = button->text();
  tmp.chop(2);
  ui->LineInput->setText(ui->LineInput->text() + tmp);
}

void SmartCalcView::keyPressEvent(QKeyEvent* e) {
  if (ui->LineInput->hasFocus() && e->key() == Qt::Key_Escape)
    ui->LineInput->clearFocus();
  if (e->key() == Qt::Key_Equal || e->key() == 16777220 ||
      e->key() == 16777221) {
    ui->pushButton_eq->click();
  }
  if (ui->checkBox_KeyboardMode->isChecked()) {
    if (e->key() == Qt::Key_Backspace || e->key() == Qt::Key_Delete) {
      ui->LineInput->backspace();
      if (ui->LineInput->text() == "") ui->LineInput->setText("0");
    }
  }
}

void SmartCalcView::on_checkBox_KeyboardMode_stateChanged() {
  if (ui->checkBox_KeyboardMode->isChecked()) {
    ui->LineInput->setReadOnly(0);
    ui->LineInput->setFocus(Qt::OtherFocusReason);
  } else {
    ui->LineInput->setReadOnly(1);
  }
}

void SmartCalcView::on_pushButton_to_gpaph_clicked() {
  plot_view_->show();
  this->close();
}

void SmartCalcView::on_pushButton_to_credit_clicked() {
  credit_view_->show();
  this->close();
}

void SmartCalcView::on_pushButton_to_debet_clicked() {
  debet_view_->show();
  this->close();
}
