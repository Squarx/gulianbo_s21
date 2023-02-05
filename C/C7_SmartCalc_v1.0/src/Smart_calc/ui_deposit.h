/********************************************************************************
** Form generated from reading UI file 'deposit.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEPOSIT_H
#define UI_DEPOSIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Deposit
{
public:
    QLineEdit *lineEdit_sum;
    QLabel *label;
    QLineEdit *lineEdit_percent;
    QLabel *label_2;
    QLineEdit *lineEdit_month;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_res_month;
    QLabel *label_res_overp;
    QLabel *label_8;
    QLabel *label_6;
    QLabel *label_res_all;
    QPushButton *pushButton;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QLabel *label_5;
    QPushButton *pushButton_2;

    void setupUi(QWidget *Deposit)
    {
        if (Deposit->objectName().isEmpty())
            Deposit->setObjectName(QString::fromUtf8("Deposit"));
        Deposit->resize(1475, 706);
        lineEdit_sum = new QLineEdit(Deposit);
        lineEdit_sum->setObjectName(QString::fromUtf8("lineEdit_sum"));
        lineEdit_sum->setGeometry(QRect(230, 120, 171, 61));
        label = new QLabel(Deposit);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 110, 141, 61));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        lineEdit_percent = new QLineEdit(Deposit);
        lineEdit_percent->setObjectName(QString::fromUtf8("lineEdit_percent"));
        lineEdit_percent->setGeometry(QRect(230, 190, 171, 61));
        label_2 = new QLabel(Deposit);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(70, 190, 141, 61));
        label_2->setFont(font);
        lineEdit_month = new QLineEdit(Deposit);
        lineEdit_month->setObjectName(QString::fromUtf8("lineEdit_month"));
        lineEdit_month->setGeometry(QRect(230, 260, 171, 61));
        label_3 = new QLabel(Deposit);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(70, 260, 141, 61));
        label_3->setFont(font);
        label_4 = new QLabel(Deposit);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(630, 120, 161, 51));
        label_4->setFont(font);
        label_res_month = new QLabel(Deposit);
        label_res_month->setObjectName(QString::fromUtf8("label_res_month"));
        label_res_month->setGeometry(QRect(880, 120, 281, 61));
        label_res_month->setFont(font);
        label_res_overp = new QLabel(Deposit);
        label_res_overp->setObjectName(QString::fromUtf8("label_res_overp"));
        label_res_overp->setGeometry(QRect(880, 200, 311, 61));
        label_res_overp->setFont(font);
        label_8 = new QLabel(Deposit);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(640, 280, 141, 61));
        label_8->setFont(font);
        label_6 = new QLabel(Deposit);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(630, 200, 141, 61));
        label_6->setFont(font);
        label_res_all = new QLabel(Deposit);
        label_res_all->setObjectName(QString::fromUtf8("label_res_all"));
        label_res_all->setGeometry(QRect(880, 280, 321, 61));
        label_res_all->setFont(font);
        pushButton = new QPushButton(Deposit);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(520, 530, 281, 91));
        radioButton = new QRadioButton(Deposit);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(1240, 69, 191, 61));
        QFont font1;
        font1.setPointSize(30);
        radioButton->setFont(font1);
        radioButton_2 = new QRadioButton(Deposit);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(1240, 140, 191, 71));
        radioButton_2->setFont(font1);
        label_5 = new QLabel(Deposit);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(550, 10, 351, 61));
        QFont font2;
        font2.setPointSize(40);
        label_5->setFont(font2);
        pushButton_2 = new QPushButton(Deposit);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(1270, 480, 161, 81));

        retranslateUi(Deposit);

        QMetaObject::connectSlotsByName(Deposit);
    } // setupUi

    void retranslateUi(QWidget *Deposit)
    {
        Deposit->setWindowTitle(QCoreApplication::translate("Deposit", "Form", nullptr));
        label->setText(QCoreApplication::translate("Deposit", "Mortgage (RUB)", nullptr));
        label_2->setText(QCoreApplication::translate("Deposit", "Percent (%)", nullptr));
        label_3->setText(QCoreApplication::translate("Deposit", "Month (n)", nullptr));
        label_4->setText(QCoreApplication::translate("Deposit", "Month Payment", nullptr));
        label_res_month->setText(QCoreApplication::translate("Deposit", "res", nullptr));
        label_res_overp->setText(QCoreApplication::translate("Deposit", "res", nullptr));
        label_8->setText(QCoreApplication::translate("Deposit", "ALL", nullptr));
        label_6->setText(QCoreApplication::translate("Deposit", "Overpay", nullptr));
        label_res_all->setText(QCoreApplication::translate("Deposit", "res", nullptr));
        pushButton->setText(QCoreApplication::translate("Deposit", "Calculate", nullptr));
        radioButton->setText(QCoreApplication::translate("Deposit", "Annu", nullptr));
        radioButton_2->setText(QCoreApplication::translate("Deposit", "Diff", nullptr));
        label_5->setText(QCoreApplication::translate("Deposit", "Mortgage calculator", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Deposit", "CALC", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Deposit: public Ui_Deposit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEPOSIT_H
