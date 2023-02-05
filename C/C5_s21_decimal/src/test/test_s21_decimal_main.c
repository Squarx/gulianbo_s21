#include <check.h>
#include <stdio.h>

#include "../s21_decimal.h"
#include "test_s21_decimal.h"

int main(void) {
  Suite *s;
  SRunner *runner;

  s = test_i();
  runner = srunner_create(s);
  srunner_add_suite(runner, test_a());
  srunner_add_suite(runner, test_g());
  // srunner_add_suite(runner, suite_is_greater());

  srunner_run_all(runner, CK_NORMAL);
  srunner_free(runner);
  return 0;
}
