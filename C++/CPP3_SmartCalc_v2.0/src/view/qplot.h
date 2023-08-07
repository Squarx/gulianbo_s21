#ifndef QPLOT_H
#define QPLOT_H

#include <QListWidgetItem>

#include "../common/myqdoublevalidator.h"
#include "../controller/controller.h"

namespace Ui {
class QPlot;
}

class QPlot : public QWidget {
  Q_OBJECT

 public:
  explicit QPlot(QWidget *parent = nullptr,
                 s21::Controller *controller = nullptr);
  ~QPlot();

 signals:
  void CalcWindow();

 private slots:
  void on_pushButton_get_graph_clicked();

  void on_pushButton_clicked();

  void on_checkBox_autoscale_stateChanged();

  void on_checkBox_scale_x_stateChanged();

  void ChangeZoom();

  void on_checkBox_scale_y_stateChanged();

  void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

  void OnQVectorFilled(const QVector<double> &x, const QVector<double> &y);

  void SetUpGraph();

  void SetUpValidators();

  void SetUpVisibility();

 private:
  const QRegularExpression r_theory_of_everything_{
      R"(^(([0-9]*[.])?[0-9]+([eE][-+]?\d+)?|([+\-*\/^]{1})?|(\(|\))?|(mod|cos\(|sin\(|tan\(|acos\(|asin\(|atan\(|sqrt\(|ln\(|log\(|(\s))?|(x|X)?)+$)"};
  QPen base_pen_{QColor(255, 151, 57)};

  Ui::QPlot *ui;
  s21::Controller *controller_;
  std::unique_ptr<QIntValidator> int_validator_;
  std::unique_ptr<MyQDoubleValidator> float_validator_;
  std::unique_ptr<QValidator> validator_input_;
};
#endif  // QPLOT_H
