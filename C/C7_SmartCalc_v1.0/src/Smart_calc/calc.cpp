#include "calc.h"
#include "ui_calc.h"
#define float "(([+-]?[0-9]+([.][0-9]*)?|[.]{1}[0-9]+))|"
#define FLOAT_NUM float "([+-]|(log|ln))+"
Calc::Calc(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::Calc)
{
  ui->setupUi(this);
  dep = new Deposit;
  vklad = new true_deposit;
//  connect(ui->tabWidget, QTabWidget::currentCh, this, Calc::show);
  ui->lineEdit_beg->setValidator(int_val);
  ui->lineEdit_end->setValidator( int_val);
  float_val->setNotation(QDoubleValidator::StandardNotation);
  ui->lineEdit_step->setValidator(float_val);
  ui->widget->setBackground(Qt::transparent);
  ui->widget->setInteraction(QCP::iRangeZoom, true);
  ui->widget->setInteraction(QCP::iRangeDrag, true);
  ui->checkBox_scale_x->setChecked(1);
  ui->checkBox_scale_y->setChecked(1);
  ui->widget->xAxis->setTickLabelColor(QColor(255, 151, 57));
  ui->widget->yAxis->setTickLabelColor(QColor(255, 151, 57));
  ui->Autoscale->hide();
  ui->start_oy->hide();
  ui->end_oy->hide();
  ui->lineEdit_beg_y->hide();
  ui->lineEdit_end_y->hide();
  ui->Graph_replot->hide();
  ui->lineEdit_size_pen->hide();
  ui->label_size_pen->hide();
  //  QRegularExpression rx(FLOAT_NUM);
  //  QRegularExpressionValidator* vali_num = new QRegularExpressionValidator(rx, this);
  //  ui->valid_test->setValidator(vali_num);
  connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_dot, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_div, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_mul, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_sub, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_sum, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_pow, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_var, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_Lbranch, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_Rbranch, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  if (ui->result_show->text().contains("=")) {
      ui->result_show->backspace();
      ui->pushButton_res->click();
    }
  //
  connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(functions()));
  connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(functions()));
  connect(ui->pushButton_tg, SIGNAL(clicked()), this, SLOT(functions()));
  connect(ui->pushButton_acos, SIGNAL(clicked()), this, SLOT(functions()));
  connect(ui->pushButton_asin, SIGNAL(clicked()), this, SLOT(functions()));
  connect(ui->pushButton_atan, SIGNAL(clicked()), this, SLOT(functions()));
  connect(ui->pushButton_sqrt, SIGNAL(clicked()), this, SLOT(functions()));
  connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(functions()));
  connect(ui->pushButton_log, SIGNAL(clicked()), this, SLOT(functions()));
  //
  ui->pushButton_var->hide();
  ui->step_ox->hide();
  ui->start_ox->hide();
  ui->end_ox->hide();
  ui->lineEdit_step->hide();
  ui->lineEdit_beg->hide();
  ui->lineEdit_end->hide();
  ui->widget->hide();
  ui->label_fX->hide();
  ui->pushButton_get_graph->hide();
  ui->lineEdit_step->setText("0.1");
  ui->lineEdit_beg->setText("-10");
  ui->lineEdit_end->setText("10");
  ui->lineEdit_beg_y->setText("-10");
  ui->lineEdit_end_y->setText("10");
}

Calc::~Calc()
{
//   ui->lineEdit_beg.
  //  int_val->deleteLater();
  //  float_val->deleteLater();
  delete int_val;
  delete float_val;
  delete dep;
  delete vklad;
  delete ui;

//  QIntValidator* int_val = new QIntValidator( -1e6, 1e6 );
//  QIntValidator* float_val = new QIntValidator( -1e6, 1e6 );
}

void Calc::keyPressEvent(QKeyEvent *e)
{
  if (ui->result_show->hasFocus() && e->key() == Qt::Key_Escape) ui->result_show->clearFocus();
  if (!(ui->result_show->hasFocus())) {
      QString tmp = "";
      if (isalpha(e->key())) {
          tmp = (char) (e->key() + 32);
        } else {
          tmp = (char) e->key();
        }

      if (ui->Handmode->isChecked()) {
          if (e->key() == Qt::Key_Backspace || e->key() == Qt::Key_Delete) {
              ui->result_show->backspace();
              if (ui->result_show->text() == "") ui->result_show->setText("0");
            }
          if (e->key() == Qt::Key_Equal || e->key() == 16777220 || e->key() == 16777221) {
              tmp = "";
              ui->pushButton_res->click();
            } else {
              if (e->key() != Qt::Key_Escape && e->key() != Qt::Key_Delete && e->key() != Qt::Key_Backspace && e->key() != Qt::Key_Equal && e->key() != 16777220 && e->key() != 16777221 && e->key() != 16777248
                  ) {
                  if (ui->result_show->text() == '0' && tmp != "0" && tmp != '.') ui->result_show->setText("");
                  if (!(ui->result_show->text() == '0' && tmp == '0'))  ui->result_show->setText(ui->result_show->text() + tmp);

                }
            }
        }
    }

}

void Calc::digits_numbers() {
  QPushButton* button = (QPushButton* ) sender();
  if (ui->result_show->text() == '0' && button->text() != "0" && button->text() != '.') ui->result_show->setText("");
  if (!(ui->result_show->text() == '0' && button->text() == '0'))ui->result_show->setText(ui->result_show->text() + button->text());
}

void Calc::functions()
{
  if (ui->result_show->text() == '0') ui->result_show->setText("");
  QPushButton* button = (QPushButton*) sender();
  QString tmp = button->text();
  tmp.chop(2);
  ui->result_show->setText(ui->result_show->text() + tmp);
}



void Calc::on_pushButton_AC_clicked()
{
  ui->result_show->setText("0");
}


void Calc::on_pushButton_rm_clicked()
{
  ui->result_show->backspace();
  if (ui->result_show->text() == "") ui->result_show->setText("0");
}


void Calc::on_pushButton_res_clicked()
{
  if(ui->result_show->hasFocus()) printf("On focus\n");
  int mode = 0;
  if (ui->Graph_mode->isChecked()){
      ui->pushButton_get_graph->click();
      mode = 1;
    }
  ui->pushButton_history->setText(ui->result_show->text());
  double res = 0;
  int error = 0;
  std::string str1 = ui->result_show->text().toStdString();
  const char* p = str1.c_str();
  double x = 0;

  if (ui->Graph_mode->isChecked()) {
      mode = 1;
      std::string str2 = ui->lineEdit_var->text().toStdString();
      const char* for_x = str2.c_str();
      x = s21_smart_calc((char*)for_x, 0, 0, &error);
    }
  if (!error) {
      res  = (double) s21_smart_calc((char*)p, mode, x, &error);
    }
  if (error  == 0) {
      ui->result_show->setText(QString::number(res, 'g', 15));
    } else {
      if (error == 1) ui->result_show->setText("INVALID STRING :: MISMATCH BRACKETS ()");
      if (error == 2) ui->result_show->setText("INVALID STRING :: EMPTY BRACKETS () or ( ... )");
      if (error == 3) ui->result_show->setText("FLOAT HAS MORE THAN 1 DOT");
      if (error == 4) ui->result_show->setText("INVALID STRING :: HAVE X in CALC mode");
      if (error == 5) ui->result_show->setText("INVALID COMMAND");
      if (error == 6) ui->result_show->setText("Functions more than numbers");
      if (error == 7) ui->result_show->setText("INVALID STRING :: Have function in () but no number");

    }

}


void Calc::on_Handmode_stateChanged(int arg1)
{
  if (ui->Handmode->isChecked()) {
      ui->result_show->setReadOnly(0);
    } else {

      ui->result_show->setReadOnly(1);
    }


}


void Calc::on_Graph_mode_stateChanged(int arg1)
{   if (ui->Graph_mode->isChecked()) {
      ui->pushButton_var->show();
      ui->step_ox->show();
      ui->start_ox->show();
      ui->end_ox->show();
      ui->lineEdit_step->show();
      ui->lineEdit_beg->show();
      ui->lineEdit_end->show();
      ui->widget->show();
      ui->label_fX->show();
      ui->pushButton_get_graph->show();
      ui->Autoscale->show();
      ui->Graph_replot->show();
      ui->lineEdit_beg_y->show();
      ui->lineEdit_end_y->show();
      ui->start_oy->show();
      ui->end_oy->show();
      ui->label_size_pen->show();
      ui->lineEdit_size_pen->show();

    } else {
      ui->Autoscale->hide();
      ui->pushButton_var->hide();
      ui->step_ox->hide();
      ui->start_ox->hide();
      ui->end_ox->hide();
      ui->lineEdit_step->hide();
      ui->lineEdit_beg->hide();
      ui->lineEdit_end->hide();
      ui->widget->hide();
      ui->label_fX->hide();
      ui->pushButton_get_graph->hide();
      ui->Graph_replot->hide();
      ui->start_oy->hide();
      ui->end_oy->hide();
      ui->lineEdit_beg_y->hide();
      ui->lineEdit_end_y->hide();
      ui->label_size_pen->hide();
      ui->lineEdit_size_pen->hide();
    }
}




void Calc::on_pushButton_history_clicked()
{
  ui->result_show->setText(ui->pushButton_history->text());
}


void Calc::on_pushButton_get_graph_clicked()
{
  //  ui->widget->xAxis.colo;
  QPen Pen1;
  Pen1.setColor(QColor(255, 151, 57));
  Pen1.setWidthF(ui->lineEdit_size_pen->text().toDouble());
  int error = 0;
  ui->widget->removeGraph(0);
  double xBeg = 0, xEnd = 0, step = 0, X = 0;
  unsigned long long N = 0;
  QVector<double> x,y;
  x.clear();
  y.clear();
  step = ui->lineEdit_step->text().toDouble();
  xBeg = ui->lineEdit_beg->text().toDouble();
  xEnd = ui->lineEdit_end->text().toDouble();
  double x_start = 0, x_end = 0;
  if (xBeg > xEnd) {
      double tmp = xBeg;
      xBeg = xEnd;
      xEnd = tmp;
    }
  if (xBeg < 0) x_start = xBeg * 1.2;
  else x_start = xBeg * 0.8;
  if (xEnd > 0) x_end = xEnd * 1.2;
  else x_end = xEnd * 0.8;
  ui->widget->xAxis->setRange(x_start, x_end);
  std::string str1 = ui->result_show->text().toStdString();
  const char* p = str1.c_str();
  double y_start = 0;
  double y_end = 0;
  N = (xEnd - xBeg) / step;
  if (N > 100000) {
      N = 100000;
      step  = (xEnd - xBeg)/100000;
      ui->lineEdit_step->setText(QString::number(step, 'g', 6));
    }
  for (unsigned long long i = 0; i < N; i++) {
      X = s21_smart_calc((char*)p, 1, xBeg + i * step, &error);
      x.push_back(xBeg + i * step);
      y.push_back(X);
      if (X <= y_start) y_start = X;
      if (X >= y_end) y_end = X;
    }

  if (ui->Autoscale->isChecked()) {
      if (y_start < 0) y_start *= 1.2;
      else y_start *= 0.8;
      if (y_end < 0) y_end *= 0.8;
      else y_end *= 1.2;
    } else {
      y_start = ui->lineEdit_beg_y->text().toDouble();
      y_end = ui->lineEdit_end_y->text().toDouble();
    }
  if (y_start > y_end) {
      double tmp = y_start;
      y_start = y_end;
      y_end = tmp;
    }
  ui->widget->yAxis->setRange(y_start, y_end);
  ui->widget->addGraph();
  ui->widget->graph()->setPen(Pen1);
  ui->widget->setBackground(Qt::transparent);
  //                                                 ui->widget->graph()->setBrush(QColor(100,50,200));
  ui->widget->graph()->addData(x,y);
  ui->widget->replot();
  x.clear();
  y.clear();

}

void Calc::on_Graph_replot_clicked()
{
  if (ui->widget->graph(0) != NULL) {
      QPen Pen1;
      Pen1.setColor(QColor(255, 151, 57));
      Pen1.setWidthF(ui->lineEdit_size_pen->text().toDouble());
      ui->widget->graph()->setPen(Pen1);
      double y_start = 0;
      double y_end = 0;
      QCPDataRange y1,y2;
      double xBeg = 0, xEnd = 0, X = 0;
      //      step = ui->lineEdit_step->text().toDouble();
      xBeg = ui->lineEdit_beg->text().toDouble();
      xEnd = ui->lineEdit_end->text().toDouble();
      double x_start = 0, x_end = 0;
      if (xBeg > xEnd) {
          double tmp = xBeg;
          xBeg = xEnd;
          xEnd = tmp;
        }
      if (xBeg < 0) x_start = xBeg * 1.2;
      else x_start = xBeg * 0.8;
      if (xEnd > 0) x_end = xEnd * 1.2;
      else x_end = xEnd * 0.8;
      if (ui->Autoscale->isChecked()) {
//                long int N = (xEnd - xBeg) / step;
          for (int i = 0; i < ui->widget->graph()->data()->size(); i++) {
              X = ui->widget->graph()->data()->at(i)->value;
              if (X <= y_start) y_start = X;
              if (X >= y_end) y_end = X;
            }
          if (y_start > y_end) {
              double tmp = y_start;
              y_start = y_end;
              y_end = tmp;
            }
          if (y_start < 0) y_start *= 1.2;
          else y_start *= 0.8;
          if (y_end < 0) y_end *= 0.8;
          else y_end *= 1.2;

        } else {
          y_start = ui->lineEdit_beg_y->text().toDouble();
          y_end = ui->lineEdit_end_y->text().toDouble();
          if (y_start > y_end) {
              double tmp = y_start;
              y_start = y_end;
              y_end = tmp;
            }
        }
      ui->widget->xAxis->setRange(x_start, x_end);
      ui->widget->yAxis->setRange(y_start, y_end);
      ui->widget->replot();
    }
}


void Calc::on_Autoscale_stateChanged(int arg1)
{
  if (!(ui->Autoscale->isChecked())) {
      ui->start_oy->show();
      ui->end_oy->show();
      ui->lineEdit_beg_y->show();
      ui->lineEdit_end_y->show();
    } else {
      ui->start_oy->hide();
      ui->end_oy->hide();
      ui->lineEdit_beg_y->hide();
      ui->lineEdit_end_y->hide();
    }
}


void Calc::on_checkBox_scale_x_stateChanged(int arg1)
{
        ui->widget->setInteraction(QCP::iRangeZoom, true);
  if(!(ui->checkBox_scale_x->isChecked())){
      ui->widget->axisRect()->setRangeZoomAxes(0, ui->widget->yAxis);
    }
  if (ui->checkBox_scale_x->isChecked() && ui->checkBox_scale_y->isChecked()){
      ui->widget->axisRect()->setRangeZoomAxes(ui->widget->xAxis, ui->widget->yAxis);
    }
  if (!(ui->checkBox_scale_x->isChecked()) && !(ui->checkBox_scale_y->isChecked())) ui->widget->setInteraction(QCP::iRangeZoom, false);
}


void Calc::on_checkBox_scale_y_stateChanged(int arg1)
{
        ui->widget->setInteraction(QCP::iRangeZoom, true);
  if(!(ui->checkBox_scale_y->isChecked())){
      ui->widget->axisRect()->setRangeZoomAxes(ui->widget->xAxis, 0);
    }
  if (ui->checkBox_scale_x->isChecked() && ui->checkBox_scale_y->isChecked()){
      ui->widget->axisRect()->setRangeZoomAxes(ui->widget->xAxis, ui->widget->yAxis);
    }
  if (!(ui->checkBox_scale_x->isChecked()) && !(ui->checkBox_scale_y->isChecked())) ui->widget->setInteraction(QCP::iRangeZoom, false);

}




void Calc::on_pushButton_clicked()
{
  this->close();
  dep->show();

}


void Calc::on_pushButton_Deposit_clicked()
{
    this->close();
    vklad->show();
}

