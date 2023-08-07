//
// Created by Gulian Boris on 8/2/23.
//

#ifndef CPP3_SMARTCALC_V2_0_1_SRC_MODEL_CREDITMODEL_H_
#define CPP3_SMARTCALC_V2_0_1_SRC_MODEL_CREDITMODEL_H_

#include <cmath>
#include <map>
#include <vector>

namespace s21 {
class CreditModel {
 public:
  enum TableColums {
    kMonthlyPayment,
    kDebtBefore,
    kPartPercents,
    kPartDebt,
    kDebtAfter,
    kResPayments,
    kResPercents,
    kResOverPayment,
    kResOverPaymentPercentage
  };

  CreditModel() {}

  void EvaluateAnnu() noexcept;
  void EvaluateDiff() noexcept;
  void SetVars(long double mortgage, long double percent, int month);

  std::map<TableColums, std::vector<long double> *> GetVectors();
  std::map<TableColums, long double> CalculateResults();

 private:
  long double mortgage_, percent_;
  int month_;
  long double all_payments_{}, all_percents_{}, start_mortgage_;

  std::vector<long double> monthly_payment_{};
  std::vector<long double> debt_before_{};
  std::vector<long double> part_percent_{};
  std::vector<long double> part_debt_{};
  std::vector<long double> debt_after_{};

  void Cleaner();
};
};      // namespace s21
#endif  // CPP3_SMARTCALC_V2_0_1_SRC_MODEL_CREDITMODEL_H_
