//
// Created by DimasX on 27.07.2023.
//

#ifndef CPP3_SMARTCALC_V2_0_1_SRC_MODEL_CALCMODEL_H_
#define CPP3_SMARTCALC_V2_0_1_SRC_MODEL_CALCMODEL_H_

#include <cmath>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <regex>
#include <stdexcept>
#include <string>
#include <utility>

namespace s21 {
class CalcModel {
 public:
  template <class T>
  void FillQVector(double x_start, double x_end, std::string &graph, T &vec_x,
                   T &vec_y) noexcept {
    int num_steps = 1e4;
    bool err = false;
    if (x_start > x_end) std::swap(x_start, x_end);
    double step = (x_end - x_start) / static_cast<double>(num_steps);
    for (auto i = 0; !err && i < num_steps; i++) {
      double curr_val = x_start + i * step;
      auto value = GetResult(graph, curr_val);
      err = value.first;
      vec_x.push_back(curr_val);
      vec_y.push_back(value.second);
    }
    if (err) {
      vec_x.clear();
      vec_y.clear();
    }
  }

  std::pair<bool, long double> GetResult(std::string &input,
                                         long double var_x = 0) noexcept;

 private:
  typedef struct Operation {
    Operation(int name, int priority) {
      this->name_ = name;
      this->priority_ = priority;
    }
    int name_;
    int priority_;
  } OP;

  enum operators {
    kMin = 1,
    kPlus = 2,
    kMul = 3,
    kDiv = 4,
    kPow = 5,
    kMod = 6,
    kLBranch = 7,
    kRBranch = 8,
    kCos = 11,
    kSin = 12,
    kTan = 13,
    kAcos = 14,
    kAsin = 15,
    kAtan = 16,
    kSqrt = 17,
    kLn = 18,
    kLog = 19,
  };

  enum priority { kRB = 1, kL = 1, kSpec = 2, kM = 3, kH = 5, kF = 6, kLB = 7 };

  bool ProcessNumericToken(std::string::const_iterator &start,
                           const std::string::const_iterator &end) noexcept;
  bool ProcessOperation(std::string::const_iterator &start,
                        const std::string::const_iterator &end) noexcept;
  bool ProcessX(std::string::const_iterator &start,
                const std::string::const_iterator &end,
                long double var_x) noexcept;
  void CompressFunc(OP current_operation) noexcept;
  void Calculate() noexcept;
  bool AddMult(std::string::const_iterator &cursor) noexcept;
  void SmartMult(std::string::const_iterator &cursor) noexcept;
  bool IsUnOp(std::string::const_iterator &cursor);
  void NonUnProcess(const std::string &token,
                    std::string::const_iterator &start) noexcept;
  static int GetPriority(int name) noexcept;
  static inline bool IsFuncTwoArg(int name) noexcept { return name < kLBranch; }
  static inline bool IsBranch(int name) noexcept {
    return name == kLBranch || name == kRBranch;
  }
  void ClearData() noexcept;
  void CalculateTwoArgs() noexcept;
  void CalculateOneArgs() noexcept;

  const std::regex numeric_pattern_{R"(^(\d*[.])?\d+([eE][-+]?\d+)?)"};
  const std::regex operator_pattern_{
      R"(^([-+*\/\^]|mod|\(|\)|cos|sin|tan|acos|asin|atan|sqrt|ln|log))"};
  const std::regex var_x_pattern_{R"(^(x|X))"};
  const std::map<std::string, int> operation_dict{
      {"-", kMin},     {"+", kPlus},    {"*", kMul},     {"/", kDiv},
      {"^", kPow},     {"mod", kMod},   {"(", kLBranch}, {")", kRBranch},
      {"cos", kCos},   {"sin", kSin},   {"tan", kTan},   {"acos", kAcos},
      {"asin", kAsin}, {"atan", kAtan}, {"sqrt", kSqrt}, {"ln", kLn},
      {"log", kLog}};

  std::string::const_iterator str_start_{};
  std::list<long double> numeric_stack_{};
  std::list<OP> operation_stack_{};
  std::smatch match_{};
  bool error_{false};
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_SRC_MODEL_CALCMODEL_H_
