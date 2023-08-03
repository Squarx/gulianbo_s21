//
// Created by DimasX on 27.07.2023.
//

#include "Controller.h"

namespace s21 {

std::string Controller::GetResult(std::string input, const std::string &var_x) {
  setlocale(LC_ALL, "en_US.UTF-8");
  std::pair<bool, long double> result{};
  if ((input.find('x') != std::string::npos ||
       input.find('X') != std::string::npos) &&
      var_x.empty()) {
    result = std::make_pair(false, 0);
  } else {
    if (!var_x.empty()) {
      result = model_->GetResult(input, std::stold(var_x));
    } else {
      result = model_->GetResult(input);
    }
  }
  return std::to_string(result.second);
}
std::array<std::vector<double> *, 5> Controller::GetCreditAnnu(double mortgage,
                                                               double percent,
                                                               int month) {
  credit_model_->SetVars(mortgage, percent, month);
  credit_model_->EvaluateAnnu();
  return credit_model_->GetVectors();
}

std::array<std::vector<double> *, 5> Controller::GetCreditDiff(double mortgage,
                                                               double percent,
                                                               int month) {
  credit_model_->SetVars(mortgage, percent, month);
  credit_model_->EvaluateDiff();
  return credit_model_->GetVectors();
}

std::array<double, 4> Controller::GetCreditResults() {
  return credit_model_->CalculateResults();
}

std::pair<std::vector<std::array<QString, 5>> *, std::array<QString, 3> *>
Controller::GetDebetTable(double deposit, QDate start_date, QDate end_date,
                          double interest_rate, double tax_rate,
                          int freq_payment, bool capitalize, int freq_put,
                          double put_sum, QDate start_date_put,
                          int freq_withdraw, double withdraw_sum,
                          QDate start_date_withdraw, QTableWidget *table_put,
                          QTableWidget *table_withdraw) {
  debet_model_->SetVaribles(
      deposit, start_date, end_date, interest_rate, tax_rate, freq_payment,
      capitalize, freq_put, put_sum, start_date_put, freq_withdraw,
      withdraw_sum, start_date_withdraw, table_put, table_withdraw);
  debet_model_->Calculate();
  return debet_model_->GetResults();
}
};  // namespace s21
