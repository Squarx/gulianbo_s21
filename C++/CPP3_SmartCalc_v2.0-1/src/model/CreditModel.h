//
// Created by Gulian Boris on 8/2/23.
//

#ifndef CPP3_SMARTCALC_V2_0_1_SRC_MODEL_CREDITMODEL_H_
#define CPP3_SMARTCALC_V2_0_1_SRC_MODEL_CREDITMODEL_H_

#include <array>
#include <cmath>
#include <vector>

namespace s21 {
class CreditModel {
 public:
  CreditModel() {}
  void Cleaner();
  void EvaluateAnnu();
  void EvaluateDiff();
  std::array<std::vector<double> *, 5> GetVectors();
  void SetVars(double mortgage, double percent, int month);
  std::array<double, 4> CalculateResults();

 private:
  double mortgage_, percent_;
  std::vector<double> monthly_payment_{};
  std::vector<double> debt_before_{};
  std::vector<double> part_percent_{};
  std::vector<double> part_debt_{};
  std::vector<double> debt_after_{};
  int month_;
  double all_payments_{}, all_percents_{}, start_mortgage_;
};
};  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_SRC_MODEL_CREDITMODEL_H_
