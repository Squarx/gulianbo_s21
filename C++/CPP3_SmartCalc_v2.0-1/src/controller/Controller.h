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

namespace s21 {
class Controller {
 public:
  explicit Controller(CalcModel *model, CreditModel *credit_model,
                      DebetModel *debet_model = nullptr)
      : model_(model), credit_model_(credit_model), debet_model_(debet_model){};

  std::string GetResult(std::string input, const std::string &var_x);
  template <class T>
  void FillQVector(double x_start, double x_end, std::string &graph, T &vec_x,
                   T &vec_y) {
    model_->FillQVector<T>(x_start, x_end, graph, vec_x, vec_y);
  }
  std::array<std::vector<double> *, 5> GetCreditAnnu(double mortgage,
                                                     double percent, int month);
  std::array<std::vector<double> *, 5> GetCreditDiff(double mortgage,
                                                     double percent, int month);

  std::pair<std::vector<std::array<QString, 5>> *, std::array<QString, 3> *>
  GetDebetTable(double deposit, QDate start_date, QDate end_date,
                double interest_rate, double tax_rate, int freq_payment,
                bool capitalize, int freq_put, double put_sum,
                QDate start_date_put, int freq_withdraw, double withdraw_sum,
                QDate start_date_withdraw, QTableWidget *table_put,
                QTableWidget *table_withdraw);
  std::array<double, 4> GetCreditResults();

 private:
  CalcModel *model_;
  CreditModel *credit_model_;
  DebetModel *debet_model_;
};
};  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_SRC_CONTROLLER_CONTROLLER_H_
