/********************************************************************************
** Form generated from reading UI file 'true_deposit.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRUE_DEPOSIT_H
#define UI_TRUE_DEPOSIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_true_deposit
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QRadioButton *radioButton_per_pay_once;
    QRadioButton *radioButton_per_pay_day;
    QRadioButton *radioButton_per_pay_month;
    QRadioButton *radioButton_per_pay_year;
    QRadioButton *radioButton_cap_yes;
    QRadioButton *radioButton_cap_no;
    QLabel *label_7;
    QLabel *label_8;
    QRadioButton *radioButton_refill_no;
    QRadioButton *radioButton_refill_month;
    QRadioButton *radioButton_refill_year;
    QLabel *label_9;
    QRadioButton *radioButton_with_no;
    QRadioButton *radioButton_with_month;
    QRadioButton *radioButton_with_year;
    QLineEdit *lineEdit_get_deposit;
    QLineEdit *lineEdit_get_time;
    QLineEdit *lineEdit_get_percent;
    QLineEdit *lineEdit_get_percent_tax;
    QLineEdit *lineEdit_get_additional_refill;
    QLineEdit *lineEdit_get_additional_withdrawal;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLineEdit *lineEdit_res_percents;
    QLineEdit *lineEdit_res_taxes;
    QLineEdit *lineEdit_res_deposit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QButtonGroup *Kapitalization;
    QButtonGroup *Per_payments;
    QButtonGroup *Refill;

    void setupUi(QWidget *true_deposit)
    {
        if (true_deposit->objectName().isEmpty())
            true_deposit->setObjectName(QString::fromUtf8("true_deposit"));
        true_deposit->resize(1201, 601);
        label = new QLabel(true_deposit);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(470, 10, 221, 81));
        QFont font;
        font.setPointSize(40);
        label->setFont(font);
        label_2 = new QLabel(true_deposit);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 100, 121, 31));
        QFont font1;
        font1.setPointSize(20);
        label_2->setFont(font1);
        label_3 = new QLabel(true_deposit);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 130, 121, 31));
        label_3->setFont(font1);
        label_4 = new QLabel(true_deposit);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 160, 121, 31));
        label_4->setFont(font1);
        label_5 = new QLabel(true_deposit);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(30, 190, 121, 31));
        label_5->setFont(font1);
        label_6 = new QLabel(true_deposit);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(30, 220, 201, 51));
        label_6->setFont(font1);
        radioButton_per_pay_once = new QRadioButton(true_deposit);
        Per_payments = new QButtonGroup(true_deposit);
        Per_payments->setObjectName(QString::fromUtf8("Per_payments"));
        Per_payments->addButton(radioButton_per_pay_once);
        radioButton_per_pay_once->setObjectName(QString::fromUtf8("radioButton_per_pay_once"));
        radioButton_per_pay_once->setGeometry(QRect(160, 230, 99, 20));
        radioButton_per_pay_day = new QRadioButton(true_deposit);
        Per_payments->addButton(radioButton_per_pay_day);
        radioButton_per_pay_day->setObjectName(QString::fromUtf8("radioButton_per_pay_day"));
        radioButton_per_pay_day->setGeometry(QRect(160, 250, 99, 20));
        radioButton_per_pay_month = new QRadioButton(true_deposit);
        Per_payments->addButton(radioButton_per_pay_month);
        radioButton_per_pay_month->setObjectName(QString::fromUtf8("radioButton_per_pay_month"));
        radioButton_per_pay_month->setGeometry(QRect(160, 270, 111, 20));
        radioButton_per_pay_year = new QRadioButton(true_deposit);
        Per_payments->addButton(radioButton_per_pay_year);
        radioButton_per_pay_year->setObjectName(QString::fromUtf8("radioButton_per_pay_year"));
        radioButton_per_pay_year->setGeometry(QRect(160, 290, 99, 20));
        radioButton_cap_yes = new QRadioButton(true_deposit);
        Kapitalization = new QButtonGroup(true_deposit);
        Kapitalization->setObjectName(QString::fromUtf8("Kapitalization"));
        Kapitalization->addButton(radioButton_cap_yes);
        radioButton_cap_yes->setObjectName(QString::fromUtf8("radioButton_cap_yes"));
        radioButton_cap_yes->setGeometry(QRect(160, 330, 99, 20));
        radioButton_cap_no = new QRadioButton(true_deposit);
        Kapitalization->addButton(radioButton_cap_no);
        radioButton_cap_no->setObjectName(QString::fromUtf8("radioButton_cap_no"));
        radioButton_cap_no->setGeometry(QRect(160, 350, 99, 20));
        label_7 = new QLabel(true_deposit);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(30, 320, 121, 51));
        label_7->setFont(font1);
        label_8 = new QLabel(true_deposit);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(30, 380, 121, 51));
        label_8->setFont(font1);
        radioButton_refill_no = new QRadioButton(true_deposit);
        Refill = new QButtonGroup(true_deposit);
        Refill->setObjectName(QString::fromUtf8("Refill"));
        Refill->addButton(radioButton_refill_no);
        radioButton_refill_no->setObjectName(QString::fromUtf8("radioButton_refill_no"));
        radioButton_refill_no->setGeometry(QRect(160, 380, 99, 20));
        radioButton_refill_month = new QRadioButton(true_deposit);
        Refill->addButton(radioButton_refill_month);
        radioButton_refill_month->setObjectName(QString::fromUtf8("radioButton_refill_month"));
        radioButton_refill_month->setGeometry(QRect(160, 400, 111, 20));
        radioButton_refill_year = new QRadioButton(true_deposit);
        Refill->addButton(radioButton_refill_year);
        radioButton_refill_year->setObjectName(QString::fromUtf8("radioButton_refill_year"));
        radioButton_refill_year->setGeometry(QRect(160, 420, 99, 20));
        label_9 = new QLabel(true_deposit);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(20, 440, 121, 51));
        label_9->setFont(font1);
        radioButton_with_no = new QRadioButton(true_deposit);
        radioButton_with_no->setObjectName(QString::fromUtf8("radioButton_with_no"));
        radioButton_with_no->setGeometry(QRect(160, 460, 99, 20));
        radioButton_with_month = new QRadioButton(true_deposit);
        radioButton_with_month->setObjectName(QString::fromUtf8("radioButton_with_month"));
        radioButton_with_month->setGeometry(QRect(160, 480, 111, 20));
        radioButton_with_year = new QRadioButton(true_deposit);
        radioButton_with_year->setObjectName(QString::fromUtf8("radioButton_with_year"));
        radioButton_with_year->setGeometry(QRect(160, 500, 99, 20));
        lineEdit_get_deposit = new QLineEdit(true_deposit);
        lineEdit_get_deposit->setObjectName(QString::fromUtf8("lineEdit_get_deposit"));
        lineEdit_get_deposit->setGeometry(QRect(150, 110, 113, 21));
        lineEdit_get_time = new QLineEdit(true_deposit);
        lineEdit_get_time->setObjectName(QString::fromUtf8("lineEdit_get_time"));
        lineEdit_get_time->setGeometry(QRect(150, 140, 113, 21));
        lineEdit_get_percent = new QLineEdit(true_deposit);
        lineEdit_get_percent->setObjectName(QString::fromUtf8("lineEdit_get_percent"));
        lineEdit_get_percent->setGeometry(QRect(150, 170, 113, 21));
        lineEdit_get_percent_tax = new QLineEdit(true_deposit);
        lineEdit_get_percent_tax->setObjectName(QString::fromUtf8("lineEdit_get_percent_tax"));
        lineEdit_get_percent_tax->setGeometry(QRect(150, 200, 113, 21));
        lineEdit_get_additional_refill = new QLineEdit(true_deposit);
        lineEdit_get_additional_refill->setObjectName(QString::fromUtf8("lineEdit_get_additional_refill"));
        lineEdit_get_additional_refill->setGeometry(QRect(290, 400, 113, 21));
        lineEdit_get_additional_withdrawal = new QLineEdit(true_deposit);
        lineEdit_get_additional_withdrawal->setObjectName(QString::fromUtf8("lineEdit_get_additional_withdrawal"));
        lineEdit_get_additional_withdrawal->setGeometry(QRect(290, 460, 113, 21));
        label_10 = new QLabel(true_deposit);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(630, 210, 121, 51));
        label_10->setFont(font1);
        label_11 = new QLabel(true_deposit);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(630, 260, 121, 51));
        label_11->setFont(font1);
        label_12 = new QLabel(true_deposit);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(630, 300, 121, 51));
        label_12->setFont(font1);
        lineEdit_res_percents = new QLineEdit(true_deposit);
        lineEdit_res_percents->setObjectName(QString::fromUtf8("lineEdit_res_percents"));
        lineEdit_res_percents->setGeometry(QRect(750, 230, 113, 21));
        lineEdit_res_taxes = new QLineEdit(true_deposit);
        lineEdit_res_taxes->setObjectName(QString::fromUtf8("lineEdit_res_taxes"));
        lineEdit_res_taxes->setGeometry(QRect(750, 270, 113, 21));
        lineEdit_res_deposit = new QLineEdit(true_deposit);
        lineEdit_res_deposit->setObjectName(QString::fromUtf8("lineEdit_res_deposit"));
        lineEdit_res_deposit->setGeometry(QRect(750, 310, 113, 21));
        pushButton = new QPushButton(true_deposit);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(600, 450, 161, 71));
        pushButton->setFont(font1);
        pushButton_2 = new QPushButton(true_deposit);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(990, 490, 161, 61));

        retranslateUi(true_deposit);

        QMetaObject::connectSlotsByName(true_deposit);
    } // setupUi

    void retranslateUi(QWidget *true_deposit)
    {
        true_deposit->setWindowTitle(QCoreApplication::translate("true_deposit", "Form", nullptr));
        label->setText(QCoreApplication::translate("true_deposit", "True Deposit", nullptr));
        label_2->setText(QCoreApplication::translate("true_deposit", "Deposit", nullptr));
        label_3->setText(QCoreApplication::translate("true_deposit", "Time (month)", nullptr));
        label_4->setText(QCoreApplication::translate("true_deposit", "Perecent (n%)", nullptr));
        label_5->setText(QCoreApplication::translate("true_deposit", "Tax Rate (n%)", nullptr));
        label_6->setText(QCoreApplication::translate("true_deposit", "Periodicity of \n"
"payments", nullptr));
        radioButton_per_pay_once->setText(QCoreApplication::translate("true_deposit", "Once a time", nullptr));
        radioButton_per_pay_day->setText(QCoreApplication::translate("true_deposit", "Once a day", nullptr));
        radioButton_per_pay_month->setText(QCoreApplication::translate("true_deposit", "Once a month", nullptr));
        radioButton_per_pay_year->setText(QCoreApplication::translate("true_deposit", "Once a year", nullptr));
        radioButton_cap_yes->setText(QCoreApplication::translate("true_deposit", "Yes", nullptr));
        radioButton_cap_no->setText(QCoreApplication::translate("true_deposit", "No", nullptr));
        label_7->setText(QCoreApplication::translate("true_deposit", "Capitalization", nullptr));
        label_8->setText(QCoreApplication::translate("true_deposit", "Refill", nullptr));
        radioButton_refill_no->setText(QCoreApplication::translate("true_deposit", "No", nullptr));
        radioButton_refill_month->setText(QCoreApplication::translate("true_deposit", "Once a month", nullptr));
        radioButton_refill_year->setText(QCoreApplication::translate("true_deposit", "Once a year", nullptr));
        label_9->setText(QCoreApplication::translate("true_deposit", "Withdrawal", nullptr));
        radioButton_with_no->setText(QCoreApplication::translate("true_deposit", "No", nullptr));
        radioButton_with_month->setText(QCoreApplication::translate("true_deposit", "Once a month", nullptr));
        radioButton_with_year->setText(QCoreApplication::translate("true_deposit", "Once a year", nullptr));
        lineEdit_get_deposit->setText(QCoreApplication::translate("true_deposit", "10000", nullptr));
        lineEdit_get_time->setText(QCoreApplication::translate("true_deposit", "12", nullptr));
        lineEdit_get_percent->setText(QCoreApplication::translate("true_deposit", "10", nullptr));
        lineEdit_get_percent_tax->setText(QCoreApplication::translate("true_deposit", "100", nullptr));
        label_10->setText(QCoreApplication::translate("true_deposit", "Get %", nullptr));
        label_11->setText(QCoreApplication::translate("true_deposit", "SUM TAX", nullptr));
        label_12->setText(QCoreApplication::translate("true_deposit", "Final deposit", nullptr));
        pushButton->setText(QCoreApplication::translate("true_deposit", "Calculate", nullptr));
        pushButton_2->setText(QCoreApplication::translate("true_deposit", "Reset", nullptr));
    } // retranslateUi

};

namespace Ui {
    class true_deposit: public Ui_true_deposit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRUE_DEPOSIT_H
