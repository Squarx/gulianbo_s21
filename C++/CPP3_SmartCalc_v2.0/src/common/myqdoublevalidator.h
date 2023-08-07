//
// Created by DimasX on 05.08.2023.
//

#ifndef CPP3_SMARTCALC_V2_0_1_SRC_COMMON_MYQDOUBLEVALIDATOR_H_
#define CPP3_SMARTCALC_V2_0_1_SRC_COMMON_MYQDOUBLEVALIDATOR_H_

#include <QDoubleValidator>

class MyQDoubleValidator : public QDoubleValidator {
 public:
  MyQDoubleValidator(double bottom, double top, int decimals,
                     QObject *parent = 0)
      : QDoubleValidator(bottom, top, decimals, parent){};

  QValidator::State validate(QString &input, int &pos) const override {
    const QValidator::State origState = QDoubleValidator::validate(input, pos);

    if ((origState == QValidator::Intermediate) && (input.toDouble() > top())) {
      return QValidator::Invalid;
    } else {
      return origState;
    }
  }
};

#endif  // CPP3_SMARTCALC_V2_0_1_SRC_COMMON_MYQDOUBLEVALIDATOR_H_
