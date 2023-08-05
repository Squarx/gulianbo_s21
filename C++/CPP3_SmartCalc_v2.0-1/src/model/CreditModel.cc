//
// Created by Gulian Boris on 8/2/23.
//

#include "CreditModel.h"

namespace s21 {
void CreditModel::EvaluateAnnu() {
  Cleaner();
  try {
    percent_ = percent_ / 100.0 / 12.;
    long double monthly_payment =
        mortgage_ *
        (percent_ + (percent_ / (powl(1. + percent_, month_) - 1.)));

    for (auto i = 0; i < month_; i++) {
      monthly_payment_.push_back(monthly_payment);
      debt_before_.push_back(mortgage_);
      long double percent_part = mortgage_ * percent_;
      part_percent_.push_back(percent_part);
      long double debt_part = monthly_payment - percent_part;
      part_debt_.push_back(debt_part);
      mortgage_ -= debt_part;
      debt_after_.push_back(mortgage_);
      all_payments_ += monthly_payment;
      all_percents_ += percent_part;
    }
  } catch (const std::exception& e) {
    Cleaner();
  }
}

void CreditModel::EvaluateDiff() {
  Cleaner();
  try {
    percent_ = percent_ / 100.0 / 12.;
    long double debt_part = mortgage_ / month_;

    for (auto i = 0; i < month_; i++) {
      debt_before_.push_back(mortgage_);
      long double percent_part = mortgage_ * percent_;
      part_percent_.push_back(percent_part);
      long double monthly_payment = debt_part + percent_part;
      monthly_payment_.push_back(monthly_payment);
      part_debt_.push_back(debt_part);
      mortgage_ -= debt_part;
      debt_after_.push_back(mortgage_);
      all_payments_ += monthly_payment;
      all_percents_ += percent_part;
    }
  } catch (const std::exception& e) {
    Cleaner();
  }
}

std::map<CreditModel::TableColums, std::vector<long double>*>
CreditModel::GetVectors() {
  return {{kMonthlyPayment, &monthly_payment_},
          {kDebtBefore, &debt_before_},
          {kPartPercents, &part_percent_},
          {kPartDebt, &part_debt_},
          {kDebtAfter, &debt_after_}};
}

void CreditModel::Cleaner() {
  monthly_payment_.clear();
  debt_before_.clear();
  part_percent_.clear();
  part_debt_.clear();
  debt_after_.clear();
  all_payments_ = all_percents_ = 0;
}
void CreditModel::SetVars(long double mortgage, long double percent,
                          int month) {
  mortgage_ = mortgage;
  percent_ = percent;
  month_ = month;
  start_mortgage_ = mortgage_;
}
std::map<CreditModel::TableColums, long double>
CreditModel::CalculateResults() {
  return {{kResPayments, all_payments_},
          {kResPercents, all_percents_},
          {kResOverPayment, all_payments_ - start_mortgage_},
          {kResOverPaymentPercentage,
           (all_payments_ - start_mortgage_) / start_mortgage_ * 100}};
}

};  // namespace s21
