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
                   T &vec_y) {
    int num_steps = 1e4;
    try {
      if (x_start > x_end) std::swap(x_start, x_end);
      double step = (x_end - x_start) / static_cast<double>(num_steps);
      for (auto i = 0; i < num_steps; i++) {
        double curr_val = x_start + i * step;
        auto value = GetResult(graph, curr_val);
        vec_x.push_back(curr_val);
        vec_y.push_back(value);
      }
    } catch (const std::exception &e) {
      vec_x.clear();
      vec_y.clear();
      throw;
    }
  }

  long double GetResult(std::string &input, long double var_x = 0);

 private:
  typedef struct Operation {
    explicit Operation(int name) {
      name_ = name;
      priority_ = GetPriority(name);
    }
    Operation(int name, int priority) {
      name_ = name;
      priority_ = priority;
    }
    [[nodiscard]] int Priority() const { return priority_; }
    [[nodiscard]] int Name() const { return name_; }
    static int GetPriority(int name) noexcept;

   private:
    int name_;
    int priority_;
  } OP;

  enum operators {
    kMin,
    kPlus,
    kMul,
    kDiv,
    kPow,
    kMod,
    kLBranch,
    kRBranch,
    kCos,
    kSin,
    kTan,
    kAcos,
    kAsin,
    kAtan,
    kSqrt,
    kLn,
    kLog,
  };

  enum priority { kL, kSpec, kM, kUn, kH, kF, kLB };

  bool ProcessNumericToken(std::string::const_iterator &start,
                           const std::string::const_iterator &end);
  bool ProcessOperation(std::string::const_iterator &start,
                        const std::string::const_iterator &end);
  bool ProcessX(std::string::const_iterator &start,
                const std::string::const_iterator &end, long double var_x);
  void CompressFunc(OP current_operation);
  bool AddMult(std::string::const_iterator &cursor);
  void SmartMult(std::string::const_iterator &cursor);
  bool IsUnOp(std::string::const_iterator &cursor);
  void NonUnProcess(const std::string &token,
                    std::string::const_iterator &start);

  static inline bool IsFuncTwoArg(int name) { return name < kLBranch; }
  static inline bool IsBranch(int name) {
    return name == kLBranch || name == kRBranch;
  }

  void ClearData() noexcept;
  void CalculateTwoArgs();
  void CalculateOneArgs();
  void Calculate();

  const std::regex numeric_pattern_{R"(^(\d*[.])?\d+([eE][-+]?\d+)?)"};
  const std::regex operator_pattern_{
      R"(^([-+*\/\^]|mod|\(|\)|cos|sin|tan|acos|asin|atan|sqrt|ln|log))"};
  const std::regex var_x_pattern_{R"(^(x|X))"};
  const std::map<std::string, int> operation_dict_{
      {"-", kMin},     {"+", kPlus},    {"*", kMul},     {"/", kDiv},
      {"^", kPow},     {"mod", kMod},   {"(", kLBranch}, {")", kRBranch},
      {"cos", kCos},   {"sin", kSin},   {"tan", kTan},   {"acos", kAcos},
      {"asin", kAsin}, {"atan", kAtan}, {"sqrt", kSqrt}, {"ln", kLn},
      {"log", kLog}};

  std::string::const_iterator str_start_{};
  std::list<long double> numeric_stack_{};
  std::list<OP> operation_stack_{};
  std::smatch match_{};
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_SRC_MODEL_CALCMODEL_H_
