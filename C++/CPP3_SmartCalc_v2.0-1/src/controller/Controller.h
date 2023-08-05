//
// Created by DimasX on 27.07.2023.
//

#ifndef CPP3_SMARTCALC_V2_0_1_SRC_CONTROLLER_CONTROLLER_H_
#define CPP3_SMARTCALC_V2_0_1_SRC_CONTROLLER_CONTROLLER_H_

#include <locale.h>

#include <future>

#include "../model/Calcmodel.h"
#include "../model/CreditModel.h"
#include "../model/DebetModel.h"
#include "qlineedit.h"

namespace s21 {
class Controller {
 public:
  explicit Controller(CalcModel *model, CreditModel *credit_model,
                      DebetModel *debet_model = nullptr)
      : model_(model), credit_model_(credit_model), debet_model_(debet_model){};

  std::string GetResult(std::string input, const std::string &var_x);

  void FillQVector(double x_start, double x_end, std::string &graph,
                   QVector<double> &vec_x, QVector<double> &vec_y,
                   QLineEdit *input_str) {
    try {
      model_->FillQVector<QVector<double>>(x_start, x_end, graph, vec_x, vec_y);
    } catch (const std::exception &e) {
      input_str->setText(QString::fromStdString(e.what()));
    }
  }
  std::map<CreditModel::TableColums, std::vector<long double> *> GetCreditAnnu(
      long double mortgage, long double percent, int month);
  std::map<CreditModel::TableColums, std::vector<long double> *> GetCreditDiff(
      long double mortgage, long double percent, int month);

  std::pair<std::vector<std::array<QString, 5>> *, std::array<QString, 5> *>
  GetDebetTable(double deposit, QDate start_date, QDate end_date,
                double interest_rate, double tax_rate, int freq_payment,
                bool capitalize, int freq_put, double put_sum,
                QDate start_date_put, int freq_withdraw, double withdraw_sum,
                QDate start_date_withdraw, QTableWidget *table_put,
                QTableWidget *table_withdraw);
  std::map<CreditModel::TableColums, long double> GetCreditResults();
  std::map<CreditModel::TableColums, std::vector<long double> *> GetCreditTable(
      long double mortgage, long double percent, int month, bool is_annu);

 private:
  CalcModel *model_;
  CreditModel *credit_model_;
  DebetModel *debet_model_;
};
};  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_SRC_CONTROLLER_CONTROLLER_H_
