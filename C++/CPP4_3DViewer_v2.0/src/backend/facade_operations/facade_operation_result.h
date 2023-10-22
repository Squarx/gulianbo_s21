#ifndef INC_3D_VIEWER_SRC_BACKEND_FACADE_OPERATIONS_FACADE_OPERATION_RESULT_H_
#define INC_3D_VIEWER_SRC_BACKEND_FACADE_OPERATIONS_FACADE_OPERATION_RESULT_H_

#include <iostream>

namespace s21 {

class FacadeOperationResult {
 public:
  FacadeOperationResult() : is_success_(false), error_message_("no error"){};
  FacadeOperationResult(bool is_true, std::string& error)
      : is_success_(is_true), error_message_(error){};

  std::string GetErrorMessage() { return error_message_; }
  void SetErrorMessage(std::string& str) { error_message_ = str; }

  bool IsSuccess() { return is_success_; }
  void SetSuccess(bool value) { is_success_ = value; }

 private:
  bool is_success_;
  std::string error_message_;
};

}  // namespace s21

#endif  // INC_3D_VIEWER_SRC_BACKEND_FACADE_OPERATIONS_FACADE_OPERATION_RESULT_H_
