#include "Calcmodel.h"

namespace s21 {
std::pair<bool, long double> CalcModel::GetResult(std::string &input,
                                                  long double var_x) noexcept {
  ClearData();
  input.erase(remove_if(input.begin(), input.end(), isspace), input.end());
  str_start_ = input.cbegin();
  auto start = str_start_;
  auto end = input.cend();
  while (start != end && !error_) {
    if (!ProcessNumericToken(start, end) && !ProcessOperation(start, end) &&
        !ProcessX(start, end, var_x))
      error_ = true;
  }
  while (!error_ && !operation_stack_.empty()) Calculate();
  if (!operation_stack_.empty() || numeric_stack_.size() != 1) error_ = true;
  return std::make_pair(error_, error_ ? 0 : numeric_stack_.back());
}

bool CalcModel::ProcessX(std::string::const_iterator &start,
                         const std::string::const_iterator &end,
                         long double var_x) noexcept {
  bool result = false;
  if (std::regex_search(start, end, match_, var_x_pattern_)) {
    SmartMult(start);
    numeric_stack_.push_back(var_x);
    start = match_[0].second;
    result = true;
  }

  return result;
}

bool CalcModel::ProcessNumericToken(
    std::string::const_iterator &start,
    const std::string::const_iterator &end) noexcept {
  bool result = false;
  if (std::regex_search(start, end, match_, numeric_pattern_)) {
    std::string token = match_[0];
    long double num = std::stold(token);
    numeric_stack_.push_back(num);
    start = match_[0].second;
    result = true;
  }
  return result;
}

bool CalcModel::ProcessOperation(
    std::string::const_iterator &start,
    const std::string::const_iterator &end) noexcept {
  bool result = false;
  if (std::regex_search(start, end, match_, operator_pattern_)) {
    std::string token = match_[0];
    if (IsUnOp(start)) {
      if (token == "-") {
        numeric_stack_.push_back(-1);
        operation_stack_.emplace_back(3, kH);
      }
    } else {
      NonUnProcess(token, start);
    }
    start = match_[0].second;
    result = true;
  }
  return result;
}
void CalcModel::NonUnProcess(const std::string &token,
                             std::string::const_iterator &start) noexcept {
  int name = operation_dict.find(token)->second;
  int priority = GetPriority(name);
  OP current_operation(name, priority);
  if (IsFuncTwoArg(name) || IsBranch(name)) {
    if (name == kLBranch && !numeric_stack_.empty() &&
        operation_stack_.back().name_ < kCos) {
      SmartMult(start);
    }
    CompressFunc(current_operation);
  } else {
    SmartMult(start);
    operation_stack_.push_back(current_operation);
  }
}

void CalcModel::CompressFunc(OP current_operation) noexcept {
  if ((current_operation.priority_ <= operation_stack_.back().priority_ &&
       !(operation_stack_.back().name_ == kPow &&
         current_operation.name_ == kPow)) ||
      current_operation.name_ == kRBranch) {
    while (!error_ &&
           (!operation_stack_.empty() &&
            current_operation.priority_ <= operation_stack_.back().priority_) &&
           operation_stack_.back().name_ != kLBranch)
      Calculate();
  }
  if (!error_) {
    if (current_operation.name_ != kRBranch) {
      operation_stack_.push_back(current_operation);
    } else {
      if (!operation_stack_.empty()) {
        operation_stack_.pop_back();
      } else {
        error_ = true;
      }
      if (!operation_stack_.empty() && operation_stack_.back().name_ >= kCos)
        Calculate();
    }
  }
}

void CalcModel::CalculateTwoArgs() noexcept {
  long double res = 0;
  if (numeric_stack_.size() < 2) {
    error_ = true;
  } else {
    long double b = numeric_stack_.back();
    numeric_stack_.pop_back();
    long double a = numeric_stack_.back();
    numeric_stack_.pop_back();
    int func = operation_stack_.back().name_;
    operation_stack_.pop_back();
    switch (func) {
      case kPlus:
        res = a + b;
        break;
      case kMin:
        res = a - b;
        break;
      case kMul:
        res = a * b;
        break;
      case kDiv:
        res = a / b;
        break;
      case kPow:
        res = powl(a, b);
        break;
      case kMod:
        res = fmodl(a, b);
        break;
      default:
        break;
    }
    numeric_stack_.push_back(res);
  }
}

void CalcModel::CalculateOneArgs() noexcept {
  long double res = 0;
  if (numeric_stack_.empty()) {
    error_ = true;
  } else {
    long double a = numeric_stack_.back();
    numeric_stack_.pop_back();
    int func = operation_stack_.back().name_;
    operation_stack_.pop_back();
    switch (func) {
      case kCos:
        res = cosl(a);
        break;
      case kSin:
        res = sinl(a);
        break;
      case kTan:
        res = tanl(a);
        break;
      case kAcos:
        res = acosl(a);
        break;
      case kAsin:
        res = asinl(a);
        break;
      case kAtan:
        res = atanl(a);
        break;
      case kSqrt:
        res = sqrtl(a);
        break;
      case kLn:
        res = logl(a);
        break;
      case kLog:
        res = log10l(a);
        break;
      default:
        break;
    }
    numeric_stack_.push_back(res);
  }
}

void CalcModel::Calculate() noexcept {
  if (operation_stack_.back().name_ < kCos) {
    CalculateTwoArgs();
  } else {
    CalculateOneArgs();
  }
}

void CalcModel::SmartMult(std::string::const_iterator &cursor) noexcept {
  if (AddMult(cursor)) {
    if (!operation_stack_.empty() && kM <= operation_stack_.back().priority_)
      while ((!operation_stack_.empty() &&
              kM <= operation_stack_.back().priority_) &&
             operation_stack_.back().name_ != kLBranch)
        Calculate();
    operation_stack_.emplace_back(kMul, kM);
  }
}

bool CalcModel::AddMult(std::string::const_iterator &cursor) noexcept {
  bool result = false;
  if (cursor > str_start_ && strchr(".)xX0123456789", *(--cursor)))
    result = true;
  return result;
}

int CalcModel::GetPriority(int name) noexcept {
  int res = 0;
  if (name >= kCos)
    res = kF;
  else {
    if (name == kPlus || name == kMin) res = kL;
    if (name == kMul || name == kDiv) res = kM;
    if (name == kPow) res = kH;
    if (name == kMod) res = kSpec;
    if (name == kLBranch) res = kLB;
    if (name == kRBranch) res = kRB;
  }
  return res;
}
bool CalcModel::IsUnOp(std::string::const_iterator &cursor) {
  bool result = false;
  if (*cursor == '+' || *cursor == '-')
    if (str_start_ == cursor || (strchr("+-*/^d(", *(--cursor)))) result = true;
  return result;
}

void CalcModel::ClearData() noexcept {
  numeric_stack_.clear();
  operation_stack_.clear();
  error_ = false;
}

};  // namespace s21
