#include "qplot.h"

#include <QPalette>
#include <QtConcurrent>
#include <thread>

#include "qcustomplot.h"
#include "ui_qplot.h"

QPlot::QPlot(QWidget* parent, s21::Controller* controller)
    : QWidget(parent),
      ui(new Ui::QPlot),
      controller_(controller),
      int_validator_(new QIntValidator(-1e6, 1e6, this)),
      float_validator_(new QDoubleValidator(-1e6, 1e6, 6, this)),
      validator_input_(
          new QRegularExpressionValidator(r_theory_of_everything, this)) {
  ui->setupUi(this);
  float_validator_->setLocale(QLocale::C);
  float_validator_->setNotation(QDoubleValidator::StandardNotation);
  ui->lineEdit_start_x->setValidator(int_validator_);
  ui->lineEdit_start_y->setValidator(int_validator_);
  ui->lineEdit_end_x->setValidator(int_validator_);
  ui->lineEdit_end_y->setValidator(int_validator_);
  ui->lineEdit->setValidator(validator_input_);

  ui->widget_plot->setBackground(Qt::transparent);
  ui->widget_plot->setInteraction(QCP::iRangeZoom, true);
  ui->widget_plot->setInteraction(QCP::iRangeDrag, true);
  ui->checkBox_scale_x->setChecked(1);
  ui->checkBox_scale_y->setChecked(1);
  ui->lineEdit_start_x->setText("-10");
  ui->lineEdit_end_x->setText("10");
  ui->lineEdit_start_y->setText("-10");
  ui->lineEdit_end_y->setText("10");
  ui->lineEdit->setText("sin(x)");
  ui->listWidget->addItem("sin(X)");
  ui->listWidget->addItem("cos(X)");
}

QPlot::~QPlot() {
  delete ui;
  delete int_validator_;
  delete float_validator_;
  delete validator_input_;
}

void QPlot::on_pushButton_get_graph_clicked() {
  QString currentText = ui->lineEdit->text();
  bool textFound = false;
  for (int i = 0; i < ui->listWidget->count() && !textFound; ++i)
    if (currentText == ui->listWidget->item(i)->text()) textFound = true;

  if (!textFound) ui->listWidget->addItem(currentText);
  ui->widget_plot->removeGraph(0);
  ui->widget_plot->addGraph(0);
  long double x_start = ui->lineEdit_start_x->text().toDouble();
  long double x_end = ui->lineEdit_end_x->text().toDouble();
  std::string graph = ui->lineEdit->text().toStdString();
  QVector<double> x{}, y{};
  x.clear();
  y.clear();

  std::mutex mtx;

  std::thread thread([this, x_start, x_end, &graph, &x, &y, &mtx]() {
    std::lock_guard<std::mutex> lock(mtx);
    controller_->FillQVector<QVector<double>>(x_start, x_end, graph, x, y);
    emit onQVectorFilled(x, y);
  });
  thread.join();
}

void QPlot::onQVectorFilled(const QVector<double>& x,
                            const QVector<double>& y) {
  ui->widget_plot->graph(0)->addData(x, y);
  long double x_start = ui->lineEdit_start_x->text().toDouble();
  long double x_end = ui->lineEdit_end_x->text().toDouble();
  if (ui->checkBox_autoscale->isChecked()) {
    double minY = *std::min_element(y.constBegin(), y.constEnd());
    double maxY = *std::max_element(y.constBegin(), y.constEnd());
    ui->widget_plot->xAxis->setRange(x_start, x_end);
    ui->widget_plot->yAxis->setRange(minY, maxY);
  } else {
    long double y_start = ui->lineEdit_start_y->text().toDouble();
    long double y_end = ui->lineEdit_end_y->text().toDouble();
    ui->widget_plot->xAxis->setRange(x_start, x_end);
    ui->widget_plot->yAxis->setRange(y_start, y_end);
  }
  ui->widget_plot->replot();
}

void QPlot::on_pushButton_clicked() {
  emit CalcWindow();
  this->close();
}

void QPlot::on_checkBox_autoscale_stateChanged() {
  if (ui->checkBox_autoscale->isChecked()) {
    ui->groupBoxScale->hide();
  } else {
    ui->groupBoxScale->show();
  }
}

void QPlot::on_checkBox_scale_x_stateChanged() { ChangeZoom(); }

void QPlot::ChangeZoom() {
  if (ui->checkBox_scale_x->isChecked()) {
    if (ui->checkBox_scale_y->isChecked()) {
      ui->widget_plot->axisRect()->setRangeZoomAxes(ui->widget_plot->xAxis,
                                                    ui->widget_plot->yAxis);
    } else {
      ui->widget_plot->axisRect()->setRangeZoomAxes(ui->widget_plot->xAxis,
                                                    nullptr);
    }
  } else {
    if (ui->checkBox_scale_y->isChecked()) {
      ui->widget_plot->axisRect()->setRangeZoomAxes(nullptr,
                                                    ui->widget_plot->yAxis);
    } else {
      ui->widget_plot->axisRect()->setRangeZoomAxes(nullptr, nullptr);
    }
  }
}

void QPlot::on_checkBox_scale_y_stateChanged() { ChangeZoom(); }

void QPlot::on_listWidget_itemDoubleClicked(QListWidgetItem* item) {
  if (item) {
    QString text = item->text();
    ui->lineEdit->setText(text);
    ui->lineEdit->setFocus(Qt::OtherFocusReason);
  }
}
