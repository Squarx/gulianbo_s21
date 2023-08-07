#include "calcmodel.h"

namespace s21 {
long double CalcModel::GetResult(std::string &input, long double var_x) {
  try {
    ClearData();

    input.erase(remove_if(input.begin(), input.end(), isspace), input.end());

    str_start_ = input.cbegin();
    auto start = str_start_;
    auto end = input.cend();

    while (start != end) {
      if (!ProcessNumericToken(start, end) && !ProcessOperation(start, end) &&
          !ProcessX(start, end, var_x)) {
        throw std::runtime_error("Invalid function");
      }
    }

    while (!operation_stack_.empty()) {
      Calculate();
    }

    if (!operation_stack_.empty() || numeric_stack_.size() != 1) {
      throw std::runtime_error("Invalid count of functions");
    }
  } catch (const std::exception &e) {
    ClearData();
    throw;
  }

  return numeric_stack_.back();
}

bool CalcModel::ProcessX(std::string::const_iterator &start,
                         const std::string::const_iterator &end,
                         long double var_x) {
  bool result = false;

  if (std::regex_search(start, end, match_, var_x_pattern_)) {
    SmartMult(start);
    numeric_stack_.push_back(var_x);
    start = match_[0].second;
    result = true;
  }

  return result;
}

bool CalcModel::ProcessNumericToken(std::string::const_iterator &start,
                                    const std::string::const_iterator &end) {
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

bool CalcModel::ProcessOperation(std::string::const_iterator &start,
                                 const std::string::const_iterator &end) {
  bool result = false;

  if (std::regex_search(start, end, match_, operator_pattern_)) {
    std::string token = match_[0];

    if (IsUnOp(start)) {
      if (token == "-") {
        numeric_stack_.push_back(-1);
        operation_stack_.emplace_back(kMul, kUn);
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
                             std::string::const_iterator &start) {
  int name = operation_dict_.find(token)->second;
  Operation current_operation(name);

  if (IsFuncTwoArg(name) || IsBranch(name)) {
    if (name == kLBranch && !numeric_stack_.empty() &&
        operation_stack_.back().Name() < kCos) {
      SmartMult(start);
    }
    CompressFunc(current_operation);
  } else {
    SmartMult(start);
    operation_stack_.push_back(current_operation);
  }
}

void CalcModel::CompressFunc(Operation current_operation) {
  if ((current_operation.Priority() <= operation_stack_.back().Priority() &&
       !(operation_stack_.back().Name() == kPow &&
         current_operation.Name() == kPow)) ||
      current_operation.Name() == kRBranch) {
    while (
        (!operation_stack_.empty() &&
         current_operation.Priority() <= operation_stack_.back().Priority()) &&
        operation_stack_.back().Name() != kLBranch) {
      Calculate();
    }
  }

  if (current_operation.Name() != kRBranch) {
    operation_stack_.push_back(current_operation);
  } else {
    if (!operation_stack_.empty()) {
      operation_stack_.pop_back();
    } else {
      throw std::runtime_error("Invalid token with brackets (...)");
    }

    if (!operation_stack_.empty() && operation_stack_.back().Name() >= kCos) {
      Calculate();
    }
  }
}

void CalcModel::CalculateTwoArgs() {
  long double res = 0;

  if (numeric_stack_.size() < 2) {
    throw std::runtime_error("Invalid count functions with two args or )");
  } else {
    long double b = numeric_stack_.back();
    numeric_stack_.pop_back();

    long double a = numeric_stack_.back();
    numeric_stack_.pop_back();

    int func = operation_stack_.back().Name();
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

void CalcModel::CalculateOneArgs() {
  long double res = 0;

  if (numeric_stack_.empty()) {
    throw std::runtime_error("Invalid count functions with one arg");
  } else {
    long double a = numeric_stack_.back();
    numeric_stack_.pop_back();

    int func = operation_stack_.back().Name();
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

void CalcModel::Calculate() {
  if (operation_stack_.back().Name() < kCos) {
    CalculateTwoArgs();
  } else {
    CalculateOneArgs();
  }
}

void CalcModel::SmartMult(std::string::const_iterator &cursor) {
  if (AddMult(cursor)) {
    if (!operation_stack_.empty() && kM <= operation_stack_.back().Priority())
      while ((!operation_stack_.empty() &&
              kM <= operation_stack_.back().Priority()) &&
             operation_stack_.back().Name() != kLBranch) {
        Calculate();
      }

    operation_stack_.emplace_back(kMul, kM);
  }
}

bool CalcModel::AddMult(std::string::const_iterator &cursor) {
  bool result = false;

  if (cursor > str_start_ && strchr(".)xX0123456789", *(--cursor))) {
    result = true;
  }

  return result;
}

int CalcModel::Operation::GetPriority(int name) noexcept {
  if (name >= kCos) return kF;
  if (name == kPlus || name == kMin) return kL;
  if (name == kMul || name == kDiv) return kM;
  if (name == kPow) return kH;
  if (name == kMod) return kSpec;
  if (name == kLBranch) return kLB;
  if (name == kRBranch) return kL;
  return 0;
}

bool CalcModel::IsUnOp(std::string::const_iterator &cursor) {
  bool result = false;

  if (*cursor == '+' || *cursor == '-') {
    if (str_start_ == cursor || (strchr("+-*/^d(", *(--cursor)))) {
      result = true;
    }
  }

  return result;
}

void CalcModel::ClearData() noexcept {
  numeric_stack_.clear();
  operation_stack_.clear();
}

};  // namespace s21
