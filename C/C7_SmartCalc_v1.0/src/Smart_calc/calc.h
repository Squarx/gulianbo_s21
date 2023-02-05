#ifndef CALC_H
#define CALC_H

#include <QWidget>
#include <QKeyEvent>
#include <qsizepolicy.h>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include "deposit.h"
#include "true_deposit.h"

extern "C" {
#include "../Smart_calc.h"
}
namespace Ui {
class Calc;
}

class Calc : public QWidget
{
    Q_OBJECT

public:
    explicit Calc(QWidget *parent = nullptr);
    ~Calc();

protected:

    void keyPressEvent(QKeyEvent *e) override;

private slots:
        void digits_numbers();

        void functions();

        void on_pushButton_AC_clicked();

        void on_pushButton_rm_clicked();

        void on_pushButton_res_clicked();

        void on_Handmode_stateChanged(int arg1);

        void on_Graph_mode_stateChanged(int arg1);


        void on_pushButton_history_clicked();

        void on_pushButton_get_graph_clicked();

//        void on_radioButton_std_window_clicked();

        void on_Graph_replot_clicked();

        void on_Autoscale_stateChanged(int arg1);

        void on_checkBox_scale_x_stateChanged(int arg1);

        void on_checkBox_scale_y_stateChanged(int arg1);

//        void on_pushButton_clicked();


        void on_pushButton_clicked();

        void on_pushButton_Deposit_clicked();

private:
    Deposit* dep;
    true_deposit* vklad;
    Ui::Calc *ui;
    QIntValidator* int_val = new QIntValidator( -1e6, 1e6 );
    QDoubleValidator* float_val = new QDoubleValidator( -1e6, 1e6, 8, this);
    bool checkregexp(QRegularExpression rx);

};



#endif // CALC_H
