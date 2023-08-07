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
      int_validator_(std::make_unique<QIntValidator>(-1e6, 1e6, this)),
      float_validator_(
          std::make_unique<MyQDoubleValidator>(-1e6, 1e6, 6, this)),
      validator_input_(std::make_unique<QRegularExpressionValidator>(
          r_theory_of_everything_, this)) {
  ui->setupUi(this);
  SetUpValidators();
  SetUpVisibility();
  SetUpGraph();
}

QPlot::~QPlot() { delete ui; }

void QPlot::SetUpVisibility() {
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

void QPlot::SetUpValidators() {
  float_validator_->setLocale(QLocale::C);
  float_validator_->setNotation(QDoubleValidator::StandardNotation);
  ui->lineEdit_start_x->setValidator(int_validator_.get());
  ui->lineEdit_start_y->setValidator(int_validator_.get());
  ui->lineEdit_end_x->setValidator(int_validator_.get());
  ui->lineEdit_end_y->setValidator(int_validator_.get());
  ui->lineEdit->setValidator(validator_input_.get());
}
void QPlot::SetUpGraph() {
  ui->widget_plot->setBackground(Qt::transparent);
  ui->widget_plot->setInteraction(QCP::iRangeZoom, true);
  ui->widget_plot->setInteraction(QCP::iRangeDrag, true);
  ui->widget_plot->xAxis->setTickLabelColor(base_pen_.color());
  ui->widget_plot->xAxis->setTickLabelColor(base_pen_.color());
  ui->widget_plot->yAxis->setTickLabelColor(base_pen_.color());
  ui->widget_plot->xAxis->setBasePen(base_pen_.color());
  ui->widget_plot->yAxis->setBasePen(base_pen_.color());

  ui->widget_plot->xAxis->setTicks(true);
  ui->widget_plot->xAxis->setSubTicks(true);
  ui->widget_plot->xAxis->setTickPen(base_pen_.color());
  ui->widget_plot->xAxis->setSubTickPen(base_pen_.color());
  ui->widget_plot->yAxis->setTicks(true);
  ui->widget_plot->yAxis->setSubTicks(true);
  ui->widget_plot->yAxis->setTickPen(base_pen_.color());
  ui->widget_plot->yAxis->setSubTickPen(base_pen_.color());
}

void QPlot::on_pushButton_get_graph_clicked() {
  QLineEdit* input = ui->lineEdit;
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
  controller_->FillQVector(x_start, x_end, graph, x, y, input);
  OnQVectorFilled(x, y);
}

void QPlot::OnQVectorFilled(const QVector<double>& x,
                            const QVector<double>& y) {
  if (x.empty() || y.empty()) {
    return;
  }

  ui->widget_plot->graph(0)->addData(x, y);

  long double x_start = ui->lineEdit_start_x->text().toDouble();
  long double x_end = ui->lineEdit_end_x->text().toDouble();
  double min_y = *std::min_element(y.constBegin(), y.constEnd());
  double max_y = *std::max_element(y.constBegin(), y.constEnd());
  bool invalid_range = (std::isnan(min_y) || std::isinf(min_y) ||
                        std::isnan(max_y) || std::isinf(max_y));

  if (ui->checkBox_autoscale->isChecked() && !invalid_range) {
    ui->widget_plot->xAxis->setRange(x_start, x_end);
    ui->widget_plot->yAxis->setRange(min_y, max_y);
  } else {
    if (invalid_range && ui->checkBox_autoscale->isChecked()) {
      ui->checkBox_autoscale->click();
    }

    long double y_start = ui->lineEdit_start_y->text().toDouble();
    long double y_end = ui->lineEdit_end_y->text().toDouble();
    ui->widget_plot->xAxis->setRange(x_start, x_end);
    ui->widget_plot->yAxis->setRange(y_start, y_end);
  }

  ui->widget_plot->graph(0)->setPen(base_pen_.color());
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
