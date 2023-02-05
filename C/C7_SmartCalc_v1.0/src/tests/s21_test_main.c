#include "s21_test_calc.h"

int main(void) {
  Suite *s;
  SRunner *runner;
  s = Calc();
  runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  srunner_free(runner);
  return 0;
}