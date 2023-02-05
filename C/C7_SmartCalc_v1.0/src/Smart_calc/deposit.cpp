#include "deposit.h"
#include "ui_deposit.h"
#include <QtMath>
#include "mainwindow.h"
Deposit::Deposit(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::Deposit)
{
  ui->setupUi(this);
//  MainWindow* start = new MainWindow;
  ui->lineEdit_percent->setValidator(percent_val);
  percent_val->setNotation(QDoubleValidator::StandardNotation);
  ui->lineEdit_sum->setValidator(mortgage_val);
  ui->lineEdit_month->setValidator(month_val);
}

Deposit::~Deposit()
{
  delete percent_val;
  delete mortgage_val;
  delete month_val;
  delete ui;
}

void Deposit::on_pushButton_clicked()
{
  if (ui->radioButton->isChecked() || ui->radioButton_2->isChecked()) {
      double mortgage = 0, percent = 0, month = 0;
      mortgage = ui->lineEdit_sum->text().toDouble();
      percent = ui->lineEdit_percent->text().toDouble();
      month =ui->lineEdit_month->text().toDouble();
      if (ui->radioButton->isChecked()) {
          double res = 0 ;
          percent = percent/100/month;
          //      ui->label_10->setText(QString::number(mortgage, 'g', 15));
          //      ui->label_11->setText(QString::number(percent, 'g', 15));
          //      ui->label_12->setText(QString::number(month, 'g', 15));
          //      ui->label_13->setText(QString::number( pow(1. + percent, month), 'g', 15));
          //      ui->label_14->setText(QString::number(pow((1. + percent), month) - 1., 'g', 15));

          printf("%f %f %f\n", mortgage, percent, pow(1. + percent, month));
          res  = mortgage * percent * pow((1. + percent), month) / (pow((1. + percent), month) - 1.);
          ui->label_res_month->setText(QString::number(res, 'f', 2));
          ui->label_res_all->setText(QString::number(res * month, 'f', 2));
          ui->label_res_overp->setText(QString::number(res * month - mortgage, 'f', 2));
        } else {

          percent = percent / 100 / 12.;
          double ostatok = mortgage, min = mortgage, max = 0, viplata = 0;
          double stable = mortgage / month;
          double all = 0;
          all = viplata;
          //        printf("stable  = %f\n", stable);
          //        printf("SUMMA  = %f, viplata %f OSTAOK = %f, \n", viplata + stable, viplata, ostatok);
          while (month > 0) {
              viplata = ostatok * percent;
              ostatok = ostatok - stable;
              all += viplata;
              if (viplata > max) max = viplata;
              if (viplata < min) min = viplata;
              month--;
              //          printf("SUMMA = %f OSTAOK = %f, viplata %f\n", viplata + stable, ostatok, viplata);
            }
          ui->label_res_month->setText(QString::number(min, 'f', 2) + "..." + QString::number(max, 'f', 2));
          ui->label_res_overp->setText(QString::number(all, 'f', 2));
          ui->label_res_all->setText(QString::number(all + mortgage, 'f', 2));
        }
    }
}


void Deposit::on_pushButton_2_clicked()
{   MainWindow* start = new MainWindow;
    this->close();
     start->show();
//       delete start;
}

