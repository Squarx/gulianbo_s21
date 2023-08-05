#ifndef CPP3_SMARTCALC_V2_0_1_SRC_MODEL_DEBETMODEL_H_
#define CPP3_SMARTCALC_V2_0_1_SRC_MODEL_DEBETMODEL_H_

#include <QDate>
#include <QTableWidget>
#include <array>
#include <vector>

namespace s21 {
class DebetModel {
 public:
  enum TableColumns { kDate, kPeriod, kPayment, kOperation, kDeposit };
  enum ResultColumns {
    kAllPercents,
    kAllTaxes,
    kAllDeposit,
    kAllPuts,
    kAllWithdraws
  };

  DebetModel() {}
  void SetVaribles(double deposit, QDate start_date, QDate end_date,
                   double interest_rate, double tax_rate, int freq_payment,
                   bool capitalize, int freq_put, double put_sum,
                   QDate start_date_put, int freq_withdraw, double withdraw_sum,
                   QDate start_date_withdraw, QTableWidget* table_put,
                   QTableWidget* table_withdraw);
  std::pair<std::vector<std::array<QString, 5>>*, std::array<QString, 5>*>
  GetResults();
  void Calculate();

 private:
  enum States { kDefaut, kStart, kPut, kWithdraw, kCPut, kCWithdraw };
  enum Period { kDay, kMonth, kYear, kOnce, kNo, kCustom };

  void GenerateDepositOperationDates(
      int freq, double sum, QDate start_period, QTableWidget* widget,
      std::vector<std::pair<QDate, double>>* list);
  void ProcessPut(
      const QDate& current_date,
      std::vector<std::pair<QDate, double>>::iterator& curr_put_date);
  void ProcessWithdraw(
      const QDate& current_date,
      std::vector<std::pair<QDate, double>>::iterator& curr_withdraw_date);
  void ProcessPayment(const QDate& current_date,
                      std::vector<QDate>::iterator& curr_payment_date,
                      QDate& periodic_date, double& periodic_percents);
  void GeneratePaymentDates();
  void GetFinalResult();
  void Cleaner();

  double deposit_;
  QDate start_date_;
  QDate end_date_;
  double interest_rate_;
  double tax_rate_;
  int freq_payment_;
  bool capitalize_;
  int freq_put_;
  double put_sum_;
  QDate start_date_put_;
  int freq_withdraw_;
  double withdraw_sum_;
  QDate start_date_withdraw_;
  QTableWidget* table_put_;
  QTableWidget* table_withdraw_;
  std::vector<QDate> list_payment{};
  std::vector<std::pair<QDate, double>> list_put{};
  std::vector<std::pair<QDate, double>> list_withdraw{};
  std::vector<std::array<QString, 5>> renderer_{};
  std::array<QString, 5> output{};
  double all_persents{};
  double all_taxes{};
  double all_puts{};
  double all_withdraws{};
};
};      // namespace s21
#endif  // CPP3_SMARTCALC_V2_0_1_SRC_MODEL_DEBETMODEL_H_
