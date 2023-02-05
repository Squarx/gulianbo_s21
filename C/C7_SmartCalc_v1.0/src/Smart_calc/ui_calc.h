/********************************************************************************
** Form generated from reading UI file 'calc.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALC_H
#define UI_CALC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_Calc
{
public:
    QPushButton *pushButton_ln;
    QPushButton *pushButton_div;
    QLineEdit *lineEdit_var;
    QPushButton *pushButton_history;
    QLabel *start_ox;
    QCheckBox *Handmode;
    QPushButton *pushButton_res;
    QLineEdit *lineEdit_end;
    QPushButton *pushButton_0;
    QCheckBox *checkBox_scale_x;
    QLineEdit *lineEdit_size_pen;
    QCustomPlot *widget;
    QLabel *label;
    QPushButton *pushButton_9;
    QPushButton *pushButton_rm;
    QPushButton *pushButton_log;
    QPushButton *pushButton_7;
    QLineEdit *lineEdit_end_y;
    QCheckBox *Autoscale;
    QPushButton *pushButton_dot;
    QPushButton *pushButton_atan;
    QLabel *end_ox;
    QLabel *start_oy;
    QPushButton *pushButton_mul;
    QLineEdit *result_show;
    QPushButton *pushButton_5;
    QPushButton *pushButton_3;
    QPushButton *pushButton_asin;
    QLineEdit *lineEdit_beg_y;
    QPushButton *pushButton_8;
    QCheckBox *Graph_mode;
    QPushButton *pushButton_sqrt;
    QPushButton *pushButton_cos;
    QPushButton *pushButton_Lbranch;
    QLabel *label_size_pen;
    QPushButton *pushButton_6;
    QLabel *label_fX;
    QLineEdit *lineEdit_beg;
    QPushButton *pushButton_Rbranch;
    QPushButton *pushButton_tg;
    QLabel *end_oy;
    QLineEdit *lineEdit_step;
    QPushButton *pushButton_var;
    QPushButton *pushButton_sum;
    QPushButton *pushButton_acos;
    QPushButton *pushButton_get_graph;
    QLabel *step_ox;
    QPushButton *pushButton_sin;
    QPushButton *pushButton_sub;
    QPushButton *pushButton_AC;
    QPushButton *pushButton_4;
    QCheckBox *checkBox_scale_y;
    QPushButton *pushButton_2;
    QPushButton *Graph_replot;
    QPushButton *pushButton_pow;
    QPushButton *pushButton_1;
    QPushButton *pushButton;
    QPushButton *pushButton_Deposit;

    void setupUi(QWidget *Calc)
    {
        if (Calc->objectName().isEmpty())
            Calc->setObjectName(QString::fromUtf8("Calc"));
        Calc->resize(1540, 790);
        Calc->setMinimumSize(QSize(1540, 790));
        pushButton_ln = new QPushButton(Calc);
        pushButton_ln->setObjectName(QString::fromUtf8("pushButton_ln"));
        pushButton_ln->setGeometry(QRect(540, 440, 100, 100));
        pushButton_ln->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgba(128, 128, 128, 90);\n"
"  border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_div = new QPushButton(Calc);
        pushButton_div->setObjectName(QString::fromUtf8("pushButton_div"));
        pushButton_div->setGeometry(QRect(340, 240, 100, 100));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_div->sizePolicy().hasHeightForWidth());
        pushButton_div->setSizePolicy(sizePolicy);
        pushButton_div->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(255, 151, 57);\n"
"  color: white; \n"
"  border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}\n"
""));
        lineEdit_var = new QLineEdit(Calc);
        lineEdit_var->setObjectName(QString::fromUtf8("lineEdit_var"));
        lineEdit_var->setGeometry(QRect(490, 640, 251, 101));
        QFont font;
        font.setPointSize(30);
        lineEdit_var->setFont(font);
        pushButton_history = new QPushButton(Calc);
        pushButton_history->setObjectName(QString::fromUtf8("pushButton_history"));
        pushButton_history->setGeometry(QRect(440, 170, 301, 71));
        pushButton_history->setStyleSheet(QString::fromUtf8("  border: 1px solid gray;"));
        start_ox = new QLabel(Calc);
        start_ox->setObjectName(QString::fromUtf8("start_ox"));
        start_ox->setGeometry(QRect(757, 100, 140, 40));
        start_ox->setFont(font);
        Handmode = new QCheckBox(Calc);
        Handmode->setObjectName(QString::fromUtf8("Handmode"));
        Handmode->setGeometry(QRect(40, 20, 161, 21));
        QFont font1;
        font1.setPointSize(25);
        Handmode->setFont(font1);
        pushButton_res = new QPushButton(Calc);
        pushButton_res->setObjectName(QString::fromUtf8("pushButton_res"));
        pushButton_res->setGeometry(QRect(340, 640, 100, 100));
        sizePolicy.setHeightForWidth(pushButton_res->sizePolicy().hasHeightForWidth());
        pushButton_res->setSizePolicy(sizePolicy);
        pushButton_res->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(255, 151, 57);\n"
"  color: white; \n"
"  border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        lineEdit_end = new QLineEdit(Calc);
        lineEdit_end->setObjectName(QString::fromUtf8("lineEdit_end"));
        lineEdit_end->setGeometry(QRect(880, 160, 161, 40));
        pushButton_0 = new QPushButton(Calc);
        pushButton_0->setObjectName(QString::fromUtf8("pushButton_0"));
        pushButton_0->setGeometry(QRect(40, 640, 200, 100));
        sizePolicy.setHeightForWidth(pushButton_0->sizePolicy().hasHeightForWidth());
        pushButton_0->setSizePolicy(sizePolicy);
        pushButton_0->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QPushButton {\n"
"   border: 1px solid gray;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"\n"
"background: QLinearGradient(x1: 0, y1: 0, \n"
"                            x2: 1, y2: 1, \n"
"                            stop: 0.2   rgba(0, 0, 0, 0), \n"
"                            stop: 0.5 rgba(102, 181, 255, 200), \n"
"                            stop: 1   rgba(102, 181, 255, 255));\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 rgb(183, 182, 184));\n"
"}"));
        checkBox_scale_x = new QCheckBox(Calc);
        checkBox_scale_x->setObjectName(QString::fromUtf8("checkBox_scale_x"));
        checkBox_scale_x->setGeometry(QRect(1330, 330, 141, 51));
        QFont font2;
        font2.setPointSize(20);
        checkBox_scale_x->setFont(font2);
        lineEdit_size_pen = new QLineEdit(Calc);
        lineEdit_size_pen->setObjectName(QString::fromUtf8("lineEdit_size_pen"));
        lineEdit_size_pen->setGeometry(QRect(1450, 260, 81, 41));
        lineEdit_size_pen->setFont(font2);
        widget = new QCustomPlot(Calc);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(790, 240, 500, 500));
        widget->setStyleSheet(QString::fromUtf8("  border: 1px solid gray;"));
        label = new QLabel(Calc);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(450, 640, 51, 101));
        label->setFont(font1);
        pushButton_9 = new QPushButton(Calc);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(240, 340, 100, 100));
        sizePolicy.setHeightForWidth(pushButton_9->sizePolicy().hasHeightForWidth());
        pushButton_9->setSizePolicy(sizePolicy);
        pushButton_9->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QPushButton {\n"
"   border: 1px solid gray;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"\n"
"background: QLinearGradient(x1: 0, y1: 0, \n"
"                            x2: 1, y2: 1, \n"
"                            stop: 0.2   rgba(0, 0, 0, 0), \n"
"                            stop: 0.5 rgba(102, 181, 255, 200), \n"
"                            stop: 1   rgba(102, 181, 255, 255));\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 rgb(183, 182, 184));\n"
"}"));
        pushButton_rm = new QPushButton(Calc);
        pushButton_rm->setObjectName(QString::fromUtf8("pushButton_rm"));
        pushButton_rm->setGeometry(QRect(140, 240, 100, 100));
        sizePolicy.setHeightForWidth(pushButton_rm->sizePolicy().hasHeightForWidth());
        pushButton_rm->setSizePolicy(sizePolicy);
        pushButton_rm->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(255, 151, 57);\n"
"  color: white; \n"
"  border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}\n"
""));
        pushButton_log = new QPushButton(Calc);
        pushButton_log->setObjectName(QString::fromUtf8("pushButton_log"));
        pushButton_log->setGeometry(QRect(640, 440, 100, 100));
        pushButton_log->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgba(128, 128, 128, 90);\n"
"  border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_7 = new QPushButton(Calc);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(40, 340, 100, 100));
        sizePolicy.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy);
        pushButton_7->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QPushButton {\n"
"   border: 1px solid gray;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"\n"
"background: QLinearGradient(x1: 0, y1: 0, \n"
"                            x2: 1, y2: 1, \n"
"                            stop: 0.2   rgba(0, 0, 0, 0), \n"
"                            stop: 0.5 rgba(102, 181, 255, 200), \n"
"                            stop: 1   rgba(102, 181, 255, 255));\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 rgb(183, 182, 184));\n"
"}"));
        lineEdit_end_y = new QLineEdit(Calc);
        lineEdit_end_y->setObjectName(QString::fromUtf8("lineEdit_end_y"));
        lineEdit_end_y->setGeometry(QRect(1180, 160, 161, 40));
        Autoscale = new QCheckBox(Calc);
        Autoscale->setObjectName(QString::fromUtf8("Autoscale"));
        Autoscale->setGeometry(QRect(1070, 30, 141, 41));
        Autoscale->setFont(font1);
        pushButton_dot = new QPushButton(Calc);
        pushButton_dot->setObjectName(QString::fromUtf8("pushButton_dot"));
        pushButton_dot->setGeometry(QRect(240, 640, 100, 100));
        sizePolicy.setHeightForWidth(pushButton_dot->sizePolicy().hasHeightForWidth());
        pushButton_dot->setSizePolicy(sizePolicy);
        pushButton_dot->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgba(128, 128, 128, 90);\n"
"  border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_atan = new QPushButton(Calc);
        pushButton_atan->setObjectName(QString::fromUtf8("pushButton_atan"));
        pushButton_atan->setGeometry(QRect(640, 340, 100, 100));
        pushButton_atan->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgba(128, 128, 128, 90);\n"
"  border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        end_ox = new QLabel(Calc);
        end_ox->setObjectName(QString::fromUtf8("end_ox"));
        end_ox->setGeometry(QRect(760, 160, 140, 40));
        end_ox->setFont(font);
        start_oy = new QLabel(Calc);
        start_oy->setObjectName(QString::fromUtf8("start_oy"));
        start_oy->setGeometry(QRect(1057, 100, 140, 40));
        start_oy->setFont(font);
        pushButton_mul = new QPushButton(Calc);
        pushButton_mul->setObjectName(QString::fromUtf8("pushButton_mul"));
        pushButton_mul->setGeometry(QRect(340, 340, 100, 100));
        sizePolicy.setHeightForWidth(pushButton_mul->sizePolicy().hasHeightForWidth());
        pushButton_mul->setSizePolicy(sizePolicy);
        pushButton_mul->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(255, 151, 57);\n"
"  color: white; \n"
"  border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        result_show = new QLineEdit(Calc);
        result_show->setObjectName(QString::fromUtf8("result_show"));
        result_show->setEnabled(true);
        result_show->setGeometry(QRect(39, 140, 401, 100));
        result_show->setFont(font);
        result_show->setFocusPolicy(Qt::ClickFocus);
        result_show->setMaxLength(256);
        result_show->setCursorPosition(0);
        result_show->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        result_show->setReadOnly(true);
        pushButton_5 = new QPushButton(Calc);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(140, 440, 100, 100));
        sizePolicy.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy);
        pushButton_5->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QPushButton {\n"
"   border: 1px solid gray;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"\n"
"background: QLinearGradient(x1: 0, y1: 0, \n"
"                            x2: 1, y2: 1, \n"
"                            stop: 0.2   rgba(0, 0, 0, 0), \n"
"                            stop: 0.5 rgba(102, 181, 255, 200), \n"
"                            stop: 1   rgba(102, 181, 255, 255));\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 rgb(183, 182, 184));\n"
"}"));
        pushButton_3 = new QPushButton(Calc);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(40, 540, 100, 100));
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);
        pushButton_3->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QPushButton {\n"
"   border: 1px solid gray;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"\n"
"background: QLinearGradient(x1: 0, y1: 0, \n"
"                            x2: 1, y2: 1, \n"
"                            stop: 0.2   rgba(0, 0, 0, 0), \n"
"                            stop: 0.5 rgba(102, 181, 255, 200), \n"
"                            stop: 1   rgba(102, 181, 255, 255));\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 rgb(183, 182, 184));\n"
"}"));
        pushButton_asin = new QPushButton(Calc);
        pushButton_asin->setObjectName(QString::fromUtf8("pushButton_asin"));
        pushButton_asin->setGeometry(QRect(540, 340, 100, 100));
        pushButton_asin->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgba(128, 128, 128, 90);\n"
"  border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        lineEdit_beg_y = new QLineEdit(Calc);
        lineEdit_beg_y->setObjectName(QString::fromUtf8("lineEdit_beg_y"));
        lineEdit_beg_y->setGeometry(QRect(1180, 100, 161, 40));
        pushButton_8 = new QPushButton(Calc);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(140, 340, 100, 100));
        sizePolicy.setHeightForWidth(pushButton_8->sizePolicy().hasHeightForWidth());
        pushButton_8->setSizePolicy(sizePolicy);
        pushButton_8->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QPushButton {\n"
"   border: 1px solid gray;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"\n"
"background: QLinearGradient(x1: 0, y1: 0, \n"
"                            x2: 1, y2: 1, \n"
"                            stop: 0.2   rgba(0, 0, 0, 0), \n"
"                            stop: 0.5 rgba(102, 181, 255, 200), \n"
"                            stop: 1   rgba(102, 181, 255, 255));\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 rgb(183, 182, 184));\n"
"}"));
        Graph_mode = new QCheckBox(Calc);
        Graph_mode->setObjectName(QString::fromUtf8("Graph_mode"));
        Graph_mode->setGeometry(QRect(40, 60, 171, 81));
        Graph_mode->setFont(font1);
        pushButton_sqrt = new QPushButton(Calc);
        pushButton_sqrt->setObjectName(QString::fromUtf8("pushButton_sqrt"));
        pushButton_sqrt->setGeometry(QRect(440, 440, 100, 100));
        pushButton_sqrt->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgba(128, 128, 128, 90);\n"
"  border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_cos = new QPushButton(Calc);
        pushButton_cos->setObjectName(QString::fromUtf8("pushButton_cos"));
        pushButton_cos->setGeometry(QRect(440, 240, 100, 100));
        pushButton_cos->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgba(128, 128, 128, 90);\n"
"  border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_Lbranch = new QPushButton(Calc);
        pushButton_Lbranch->setObjectName(QString::fromUtf8("pushButton_Lbranch"));
        pushButton_Lbranch->setGeometry(QRect(440, 540, 100, 100));
        pushButton_Lbranch->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgba(128, 128, 128, 90);\n"
"  border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        label_size_pen = new QLabel(Calc);
        label_size_pen->setObjectName(QString::fromUtf8("label_size_pen"));
        label_size_pen->setGeometry(QRect(1320, 260, 131, 41));
        label_size_pen->setFont(font1);
        pushButton_6 = new QPushButton(Calc);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(40, 440, 100, 100));
        sizePolicy.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy);
        pushButton_6->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QPushButton {\n"
"   border: 1px solid gray;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"\n"
"background: QLinearGradient(x1: 0, y1: 0, \n"
"                            x2: 1, y2: 1, \n"
"                            stop: 0.2   rgba(0, 0, 0, 0), \n"
"                            stop: 0.5 rgba(102, 181, 255, 200), \n"
"                            stop: 1   rgba(102, 181, 255, 255));\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 rgb(183, 182, 184));\n"
"}"));
        label_fX = new QLabel(Calc);
        label_fX->setObjectName(QString::fromUtf8("label_fX"));
        label_fX->setGeometry(QRect(50, 150, 31, 31));
        label_fX->setFont(font2);
        lineEdit_beg = new QLineEdit(Calc);
        lineEdit_beg->setObjectName(QString::fromUtf8("lineEdit_beg"));
        lineEdit_beg->setGeometry(QRect(880, 100, 161, 40));
        pushButton_Rbranch = new QPushButton(Calc);
        pushButton_Rbranch->setObjectName(QString::fromUtf8("pushButton_Rbranch"));
        pushButton_Rbranch->setGeometry(QRect(540, 540, 100, 100));
        pushButton_Rbranch->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgba(128, 128, 128, 90);\n"
"  border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_tg = new QPushButton(Calc);
        pushButton_tg->setObjectName(QString::fromUtf8("pushButton_tg"));
        pushButton_tg->setGeometry(QRect(640, 240, 100, 100));
        pushButton_tg->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgba(128, 128, 128, 90);\n"
"  border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        end_oy = new QLabel(Calc);
        end_oy->setObjectName(QString::fromUtf8("end_oy"));
        end_oy->setGeometry(QRect(1060, 160, 140, 40));
        end_oy->setFont(font);
        lineEdit_step = new QLineEdit(Calc);
        lineEdit_step->setObjectName(QString::fromUtf8("lineEdit_step"));
        lineEdit_step->setGeometry(QRect(880, 40, 161, 40));
        pushButton_var = new QPushButton(Calc);
        pushButton_var->setObjectName(QString::fromUtf8("pushButton_var"));
        pushButton_var->setGeometry(QRect(640, 540, 100, 100));
        pushButton_var->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgba(128, 128, 128, 90);\n"
"  border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_sum = new QPushButton(Calc);
        pushButton_sum->setObjectName(QString::fromUtf8("pushButton_sum"));
        pushButton_sum->setGeometry(QRect(340, 440, 100, 100));
        sizePolicy.setHeightForWidth(pushButton_sum->sizePolicy().hasHeightForWidth());
        pushButton_sum->setSizePolicy(sizePolicy);
        pushButton_sum->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(255, 151, 57);\n"
"  color: white; \n"
"  border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_acos = new QPushButton(Calc);
        pushButton_acos->setObjectName(QString::fromUtf8("pushButton_acos"));
        pushButton_acos->setGeometry(QRect(440, 340, 100, 100));
        pushButton_acos->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgba(128, 128, 128, 90);\n"
"  border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_get_graph = new QPushButton(Calc);
        pushButton_get_graph->setObjectName(QString::fromUtf8("pushButton_get_graph"));
        pushButton_get_graph->setGeometry(QRect(1370, 80, 141, 71));
        pushButton_get_graph->setFont(font2);
        step_ox = new QLabel(Calc);
        step_ox->setObjectName(QString::fromUtf8("step_ox"));
        step_ox->setGeometry(QRect(757, 40, 140, 40));
        step_ox->setFont(font);
        pushButton_sin = new QPushButton(Calc);
        pushButton_sin->setObjectName(QString::fromUtf8("pushButton_sin"));
        pushButton_sin->setGeometry(QRect(540, 240, 100, 100));
        pushButton_sin->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgba(128, 128, 128, 90);\n"
"  border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_sub = new QPushButton(Calc);
        pushButton_sub->setObjectName(QString::fromUtf8("pushButton_sub"));
        pushButton_sub->setGeometry(QRect(340, 540, 100, 100));
        sizePolicy.setHeightForWidth(pushButton_sub->sizePolicy().hasHeightForWidth());
        pushButton_sub->setSizePolicy(sizePolicy);
        pushButton_sub->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(255, 151, 57);\n"
"  color: white; \n"
"  border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_AC = new QPushButton(Calc);
        pushButton_AC->setObjectName(QString::fromUtf8("pushButton_AC"));
        pushButton_AC->setGeometry(QRect(40, 240, 100, 100));
        sizePolicy.setHeightForWidth(pushButton_AC->sizePolicy().hasHeightForWidth());
        pushButton_AC->setSizePolicy(sizePolicy);
        pushButton_AC->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgba(128, 128, 128, 90);\n"
"  border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        pushButton_4 = new QPushButton(Calc);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(240, 440, 100, 100));
        sizePolicy.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy);
        pushButton_4->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QPushButton {\n"
"   border: 1px solid gray;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"\n"
"background: QLinearGradient(x1: 0, y1: 0, \n"
"                            x2: 1, y2: 1, \n"
"                            stop: 0.2   rgba(0, 0, 0, 0), \n"
"                            stop: 0.5 rgba(102, 181, 255, 200), \n"
"                            stop: 1   rgba(102, 181, 255, 255));\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 rgb(183, 182, 184));\n"
"}"));
        checkBox_scale_y = new QCheckBox(Calc);
        checkBox_scale_y->setObjectName(QString::fromUtf8("checkBox_scale_y"));
        checkBox_scale_y->setGeometry(QRect(1330, 370, 141, 51));
        checkBox_scale_y->setFont(font2);
        pushButton_2 = new QPushButton(Calc);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(140, 540, 100, 100));
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);
        pushButton_2->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QPushButton {\n"
"   border: 1px solid gray;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"\n"
"background: QLinearGradient(x1: 0, y1: 0, \n"
"                            x2: 1, y2: 1, \n"
"                            stop: 0.2   rgba(0, 0, 0, 0), \n"
"                            stop: 0.5 rgba(102, 181, 255, 200), \n"
"                            stop: 1   rgba(102, 181, 255, 255));\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 rgb(183, 182, 184));\n"
"}"));
        Graph_replot = new QPushButton(Calc);
        Graph_replot->setObjectName(QString::fromUtf8("Graph_replot"));
        Graph_replot->setGeometry(QRect(1370, 160, 141, 51));
        Graph_replot->setFont(font2);
        pushButton_pow = new QPushButton(Calc);
        pushButton_pow->setObjectName(QString::fromUtf8("pushButton_pow"));
        pushButton_pow->setGeometry(QRect(240, 240, 100, 100));
        sizePolicy.setHeightForWidth(pushButton_pow->sizePolicy().hasHeightForWidth());
        pushButton_pow->setSizePolicy(sizePolicy);
        pushButton_pow->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(255, 151, 57);\n"
"  color: white; \n"
"  border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_1 = new QPushButton(Calc);
        pushButton_1->setObjectName(QString::fromUtf8("pushButton_1"));
        pushButton_1->setGeometry(QRect(240, 540, 100, 100));
        sizePolicy.setHeightForWidth(pushButton_1->sizePolicy().hasHeightForWidth());
        pushButton_1->setSizePolicy(sizePolicy);
        pushButton_1->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QPushButton {\n"
"   border: 1px solid gray;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"\n"
"background: QLinearGradient(x1: 0, y1: 0, \n"
"                            x2: 1, y2: 1, \n"
"                            stop: 0.2   rgba(0, 0, 0, 0), \n"
"                            stop: 0.5 rgba(102, 181, 255, 200), \n"
"                            stop: 1   rgba(102, 181, 255, 255));\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 rgb(183, 182, 184));\n"
"}"));
        pushButton = new QPushButton(Calc);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(1340, 470, 151, 61));
        pushButton_Deposit = new QPushButton(Calc);
        pushButton_Deposit->setObjectName(QString::fromUtf8("pushButton_Deposit"));
        pushButton_Deposit->setGeometry(QRect(1340, 560, 151, 71));

        retranslateUi(Calc);

        QMetaObject::connectSlotsByName(Calc);
    } // setupUi

    void retranslateUi(QWidget *Calc)
    {
        Calc->setWindowTitle(QCoreApplication::translate("Calc", "Form", nullptr));
        pushButton_ln->setText(QCoreApplication::translate("Calc", "ln(X)", nullptr));
#if QT_CONFIG(accessibility)
        pushButton_div->setAccessibleDescription(QString());
#endif // QT_CONFIG(accessibility)
        pushButton_div->setText(QCoreApplication::translate("Calc", "/", nullptr));
        pushButton_history->setText(QCoreApplication::translate("Calc", "10*sin(x)", nullptr));
        start_ox->setText(QCoreApplication::translate("Calc", "Start OX", nullptr));
        Handmode->setText(QCoreApplication::translate("Calc", "Handmode", nullptr));
#if QT_CONFIG(accessibility)
        pushButton_res->setAccessibleDescription(QString());
#endif // QT_CONFIG(accessibility)
        pushButton_res->setText(QCoreApplication::translate("Calc", "=", nullptr));
#if QT_CONFIG(shortcut)
        pushButton_res->setShortcut(QString());
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(accessibility)
        pushButton_0->setAccessibleDescription(QString());
#endif // QT_CONFIG(accessibility)
        pushButton_0->setText(QCoreApplication::translate("Calc", "0", nullptr));
        checkBox_scale_x->setText(QCoreApplication::translate("Calc", "Scale OX", nullptr));
        label->setText(QCoreApplication::translate("Calc", "X = ", nullptr));
#if QT_CONFIG(accessibility)
        pushButton_9->setAccessibleDescription(QString());
#endif // QT_CONFIG(accessibility)
        pushButton_9->setText(QCoreApplication::translate("Calc", "9", nullptr));
#if QT_CONFIG(accessibility)
        pushButton_rm->setAccessibleDescription(QString());
#endif // QT_CONFIG(accessibility)
        pushButton_rm->setText(QCoreApplication::translate("Calc", "rm", nullptr));
        pushButton_log->setText(QCoreApplication::translate("Calc", "log(X)", nullptr));
#if QT_CONFIG(accessibility)
        pushButton_7->setAccessibleDescription(QString());
#endif // QT_CONFIG(accessibility)
        pushButton_7->setText(QCoreApplication::translate("Calc", "7", nullptr));
        Autoscale->setText(QCoreApplication::translate("Calc", "Autoscale", nullptr));
#if QT_CONFIG(accessibility)
        pushButton_dot->setAccessibleDescription(QString());
#endif // QT_CONFIG(accessibility)
        pushButton_dot->setText(QCoreApplication::translate("Calc", ".", nullptr));
        pushButton_atan->setText(QCoreApplication::translate("Calc", "atan(X)", nullptr));
        end_ox->setText(QCoreApplication::translate("Calc", "End OX", nullptr));
        start_oy->setText(QCoreApplication::translate("Calc", "Start OY", nullptr));
#if QT_CONFIG(accessibility)
        pushButton_mul->setAccessibleDescription(QString());
#endif // QT_CONFIG(accessibility)
        pushButton_mul->setText(QCoreApplication::translate("Calc", "*", nullptr));
        result_show->setText(QString());
#if QT_CONFIG(accessibility)
        pushButton_5->setAccessibleDescription(QString());
#endif // QT_CONFIG(accessibility)
        pushButton_5->setText(QCoreApplication::translate("Calc", "5", nullptr));
#if QT_CONFIG(accessibility)
        pushButton_3->setAccessibleDescription(QString());
#endif // QT_CONFIG(accessibility)
        pushButton_3->setText(QCoreApplication::translate("Calc", "3", nullptr));
        pushButton_asin->setText(QCoreApplication::translate("Calc", "asin(X)", nullptr));
#if QT_CONFIG(accessibility)
        pushButton_8->setAccessibleDescription(QString());
#endif // QT_CONFIG(accessibility)
        pushButton_8->setText(QCoreApplication::translate("Calc", "8", nullptr));
        Graph_mode->setText(QCoreApplication::translate("Calc", "Graph mode", nullptr));
        pushButton_sqrt->setText(QCoreApplication::translate("Calc", "sqrt(x)", nullptr));
        pushButton_cos->setText(QCoreApplication::translate("Calc", "cos(X)", nullptr));
        pushButton_Lbranch->setText(QCoreApplication::translate("Calc", "(", nullptr));
        label_size_pen->setText(QCoreApplication::translate("Calc", "Size of Pen", nullptr));
#if QT_CONFIG(accessibility)
        pushButton_6->setAccessibleDescription(QString());
#endif // QT_CONFIG(accessibility)
        pushButton_6->setText(QCoreApplication::translate("Calc", "6", nullptr));
        label_fX->setText(QCoreApplication::translate("Calc", "f(x)  ", nullptr));
        pushButton_Rbranch->setText(QCoreApplication::translate("Calc", ")", nullptr));
        pushButton_tg->setText(QCoreApplication::translate("Calc", "tg(X)", nullptr));
        end_oy->setText(QCoreApplication::translate("Calc", "End OY", nullptr));
        pushButton_var->setText(QCoreApplication::translate("Calc", "x", nullptr));
#if QT_CONFIG(accessibility)
        pushButton_sum->setAccessibleDescription(QString());
#endif // QT_CONFIG(accessibility)
        pushButton_sum->setText(QCoreApplication::translate("Calc", "+", nullptr));
        pushButton_acos->setText(QCoreApplication::translate("Calc", "acos(X)", nullptr));
        pushButton_get_graph->setText(QCoreApplication::translate("Calc", "Calculate graph", nullptr));
        step_ox->setText(QCoreApplication::translate("Calc", "Step OX", nullptr));
        pushButton_sin->setText(QCoreApplication::translate("Calc", "sin(X)", nullptr));
#if QT_CONFIG(accessibility)
        pushButton_sub->setAccessibleDescription(QString());
#endif // QT_CONFIG(accessibility)
        pushButton_sub->setText(QCoreApplication::translate("Calc", "-", nullptr));
#if QT_CONFIG(accessibility)
        pushButton_AC->setAccessibleDescription(QString());
#endif // QT_CONFIG(accessibility)
        pushButton_AC->setText(QCoreApplication::translate("Calc", "AC", nullptr));
#if QT_CONFIG(accessibility)
        pushButton_4->setAccessibleDescription(QString());
#endif // QT_CONFIG(accessibility)
        pushButton_4->setText(QCoreApplication::translate("Calc", "4", nullptr));
        checkBox_scale_y->setText(QCoreApplication::translate("Calc", "Scale OY", nullptr));
#if QT_CONFIG(accessibility)
        pushButton_2->setAccessibleDescription(QString());
#endif // QT_CONFIG(accessibility)
        pushButton_2->setText(QCoreApplication::translate("Calc", "2", nullptr));
        Graph_replot->setText(QCoreApplication::translate("Calc", "Resize", nullptr));
#if QT_CONFIG(accessibility)
        pushButton_pow->setAccessibleDescription(QString());
#endif // QT_CONFIG(accessibility)
        pushButton_pow->setText(QCoreApplication::translate("Calc", "^", nullptr));
#if QT_CONFIG(accessibility)
        pushButton_1->setAccessibleDescription(QString());
#endif // QT_CONFIG(accessibility)
        pushButton_1->setText(QCoreApplication::translate("Calc", "1", nullptr));
        pushButton->setText(QCoreApplication::translate("Calc", "Mortgage", nullptr));
        pushButton_Deposit->setText(QCoreApplication::translate("Calc", "Deposit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Calc: public Ui_Calc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALC_H
