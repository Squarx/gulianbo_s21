//
// Created by Gulian Boris on 8/2/23.
//

#include "DebetModel.h"

namespace s21 {
void DebetModel::GeneratePaymentDates() {
  if (freq_payment_ == kDay) {
    QDate current_date = start_date_;
    while (current_date <= end_date_) {
      list_payment.push_back(current_date);
      current_date = current_date.addDays(1);
    }
  } else if (freq_payment_ == kMonth) {
    QDate current_date = start_date_;
    while (current_date <= end_date_) {
      list_payment.push_back(current_date);
      current_date = current_date.addMonths(1);
    }
  } else if (freq_payment_ == kYear) {
    QDate current_date = start_date_;
    while (current_date <= end_date_) {
      list_payment.push_back(current_date);
      current_date = current_date.addYears(1);
    }
  } else {
    list_payment.push_back(start_date_);
    list_payment.push_back(end_date_);
  }
}

void DebetModel::GenerateDepositOperationDates(
    int freq, double sum, QDate start_period, QTableWidget* widget,
    std::vector<std::pair<QDate, double>>* list) {
  QDate current_date = start_period;
  switch (freq) {
    case kCustom:
      for (int row = 0; row < widget->rowCount(); ++row) {
        QString date_str = widget->item(row, 0)->text();
        QString value_str = widget->item(row, 1)->text();
        QDate date = QDate::fromString(date_str, "dd-MM-yyyy");
        if (date >= start_date_) {
          double value = value_str.replace(",", ".").toDouble();
          list->push_back(std::make_pair(date, value));
        }
      }
      std::sort(list->begin(), list->end());
      break;
    case kMonth:
      while (current_date <= end_date_) {
        if (current_date >= start_date_) {
          list->push_back(std::make_pair(current_date, sum));
        }
        current_date = current_date.addMonths(1);
      }
      break;
    case kYear:
      while (current_date <= end_date_) {
        if (current_date >= start_date_) {
          list->push_back(std::make_pair(current_date, sum));
        }
        current_date = current_date.addYears(1);
      }
      break;
    default:
      break;
  }
}

void DebetModel::ProcessPut(
    const QDate& current_date,
    std::vector<std::pair<QDate, double>>::iterator& curr_put_date) {
  if (!list_put.empty() && freq_put_ != kNo &&
      curr_put_date != list_put.end() && current_date == curr_put_date->first) {
    if (curr_put_date->first != start_date_) {
      deposit_ += curr_put_date->second;
      all_puts += curr_put_date->second;
      renderer_.emplace_back(std::array<QString, 5>{
          curr_put_date->first.toString("dd-MM-yyyy"), "", "",
          QString::number(curr_put_date->second), QString::number(deposit_)});
    }
    ++curr_put_date;
  }
}
void DebetModel::ProcessWithdraw(
    const QDate& current_date,
    std::vector<std::pair<QDate, double>>::iterator& curr_withdraw_date) {
  if (!list_withdraw.empty() && freq_withdraw_ != kNo &&
      curr_withdraw_date != list_withdraw.end() &&
      current_date == curr_withdraw_date->first) {
    if (curr_withdraw_date->first != start_date_) {
      QString message{};
      if (deposit_ - curr_withdraw_date->second >= 0) {
        deposit_ -= curr_withdraw_date->second;
        all_withdraws += curr_withdraw_date->second;
        message = "-" + QString::number(curr_withdraw_date->second);
      } else {
        message =
            QString("Не было снято %1, из-за размера неснижаемого остатка 0,00")
                .arg(curr_withdraw_date->second);
      }
      renderer_.push_back({curr_withdraw_date->first.toString("dd-MM-yyyy"), "",
                           "", message, QString::number(deposit_)});
    }
    ++curr_withdraw_date;
  }
}
void DebetModel::ProcessPayment(const QDate& current_date,
                                std::vector<QDate>::iterator& curr_payment_date,
                                QDate& periodic_date,
                                double& periodic_percents) {
  if (current_date == *curr_payment_date) {
    ++curr_payment_date;
    int daysDifference_periodic = periodic_date.daysTo(current_date);
    if (capitalize_) deposit_ += periodic_percents;
    renderer_.emplace_back(std::array<QString, 5>{
        current_date.toString("dd-MM-yyyy"),
        QString::number(daysDifference_periodic),
        QString::number(periodic_percents), QString::number(periodic_percents),
        QString::number(deposit_, 'f', 2)});

    periodic_percents = 0;
    periodic_date = current_date;
  }
}

void DebetModel::Calculate() {
  Cleaner();
  try {
    GeneratePaymentDates();
    GenerateDepositOperationDates(freq_put_, put_sum_, start_date_put_,
                                  table_put_, &list_put);
    GenerateDepositOperationDates(freq_withdraw_, withdraw_sum_,
                                  start_date_withdraw_, table_withdraw_,
                                  &list_withdraw);
    QDate prev_date = start_date_;
    int start_year = start_date_.year();
    int curr_year_capacity = start_date_.daysInYear();
    double rate =
        (interest_rate_ / (static_cast<double>(curr_year_capacity) * 100.));
    double periodic_percents = 0;
    QDate periodic_date = start_date_;
    auto curr_key_date = list_payment.begin();
    auto curr_put_date = list_put.begin();
    auto curr_withdraw_date = list_withdraw.begin();

    for (auto curr_date = start_date_; curr_date <= end_date_;) {
      if (curr_date.year() != start_year) {
        curr_year_capacity = curr_date.daysInYear();
        rate =
            (interest_rate_ / (static_cast<double>(curr_year_capacity) * 100.));
      }

      int daysDifference = prev_date.daysTo(curr_date);
      double percents = deposit_ * rate * daysDifference;

      all_persents += percents;
      periodic_percents += percents;

      ProcessPut(curr_date, curr_put_date);
      ProcessWithdraw(curr_date, curr_withdraw_date);
      ProcessPayment(curr_date, curr_key_date, periodic_date,
                     periodic_percents);

      prev_date = curr_date;
      curr_date = curr_date.addDays(1);
    }
    GetFinalResult();
  } catch (const std::exception& e) {
    Cleaner();
  }
}

void DebetModel::GetFinalResult() {
  double cmp_sum = tax_rate_ / 100.0 * 1e6;
  if (all_persents > cmp_sum) {
    all_taxes = (all_persents - cmp_sum) * 0.13;
  }
  QLocale locale("en_US");
  output[kAllPercents] = locale.toString(all_persents, 'f', 2);

  if (all_taxes != 0) {
    output[kAllTaxes] = locale.toString(all_taxes, 'f', 2);
  } else {
    output[kAllTaxes] =
        QString("Не облагается налогом (меньше (%1))")
            .arg(locale.toString((tax_rate_ / 100.0) * 1e6, 'f', 2));
  }

  output[kAllDeposit] = locale.toString(deposit_, 'f', 2);
  output[kAllPuts] = locale.toString(all_puts, 'f', 2);
  output[kAllWithdraws] = locale.toString(all_withdraws, 'f', 2);
}

void DebetModel::Cleaner() {
  list_payment.clear();
  list_put.clear();
  list_withdraw.clear();
  renderer_.clear();
  all_persents = all_taxes = all_puts = all_withdraws = 0;
}

std::pair<std::vector<std::array<QString, 5>>*, std::array<QString, 5>*>
DebetModel::GetResults() {
  return std::make_pair(&renderer_, &output);
}
void DebetModel::SetVaribles(double deposit, QDate start_date, QDate end_date,
                             double interest_rate, double tax_rate,
                             int freq_payment, bool capitalize, int freq_put,
                             double put_sum, QDate start_date_put,
                             int freq_withdraw, double withdraw_sum,
                             QDate start_date_withdraw, QTableWidget* table_put,
                             QTableWidget* table_withdraw) {
  Cleaner();
  deposit_ = deposit;
  start_date_ = start_date;
  end_date_ = end_date;
  interest_rate_ = interest_rate;
  tax_rate_ = tax_rate;
  freq_payment_ = freq_payment;
  capitalize_ = capitalize;
  freq_put_ = freq_put;
  put_sum_ = put_sum;
  start_date_put_ = start_date_put;
  freq_withdraw_ = freq_withdraw;
  withdraw_sum_ = withdraw_sum;
  start_date_withdraw_ = start_date_withdraw;
  table_put_ = table_put;
  table_withdraw_ = table_withdraw;
}
};  // namespace s21
