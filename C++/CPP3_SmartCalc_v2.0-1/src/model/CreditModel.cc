//
// Created by Gulian Boris on 8/2/23.
//

#include "CreditModel.h"

namespace s21 {
void CreditModel::EvaluateAnnu() {
  Cleaner();
  percent_ = percent_ / 100.0 / 12.;
  double monthly_payment =
      mortgage_ *
      (percent_ + (percent_ / (std::pow(1. + percent_, month_) - 1.)));

  for (long i = 0; i < month_; i++) {
    monthly_payment_.push_back(monthly_payment);
    debt_before_.push_back(mortgage_);
    double percent_part = mortgage_ * percent_;
    part_percent_.push_back(percent_part);
    double debt_part = monthly_payment - percent_part;
    part_debt_.push_back(debt_part);
    mortgage_ -= debt_part;
    debt_after_.push_back(mortgage_);
    all_payments_ += monthly_payment;
    all_percents_ += percent_part;
  }
}

void CreditModel::EvaluateDiff() {
  Cleaner();
  percent_ = percent_ / 100.0 / 12.;
  double debt_part = mortgage_ / month_;

  for (long i = 0; i < month_; i++) {
    debt_before_.push_back(mortgage_);
    double percent_part = mortgage_ * percent_;
    part_percent_.push_back(percent_part);
    double monthly_payment = debt_part + percent_part;
    monthly_payment_.push_back(monthly_payment);
    part_debt_.push_back(debt_part);
    mortgage_ -= debt_part;
    debt_after_.push_back(mortgage_);
    all_payments_ += monthly_payment;
    all_percents_ += percent_part;
  }
}

std::array<std::vector<double> *, 5> CreditModel::GetVectors() {
  return {&monthly_payment_, &debt_before_, &part_percent_, &part_debt_,
          &debt_after_};
}

void CreditModel::Cleaner() {
  monthly_payment_.clear();
  debt_before_.clear();
  part_percent_.clear();
  part_debt_.clear();
  debt_after_.clear();
  all_payments_ = all_percents_ = 0;
}
void CreditModel::SetVars(double mortgage, double percent, int month) {
  mortgage_ = mortgage;
  percent_ = percent;
  month_ = month;
  start_mortgage_ = mortgage_;
}

std::array<double, 4> CreditModel::CalculateResults() {
  return {all_payments_, all_percents_, all_payments_ - start_mortgage_,
          (all_payments_ - start_mortgage_) / start_mortgage_ * 100};
}

};  // namespace s21
