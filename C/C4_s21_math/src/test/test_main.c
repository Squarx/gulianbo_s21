#include "test.h"
int main(void) {
  Suite *s;
  Suite *s1;
  SRunner *runner_s;
  SRunner *runner_s1;
  s = s21_math_lukeshir();
  s1 = s21_math_nyar();
  runner_s = srunner_create(s);
  runner_s1 = srunner_create(s1);
  srunner_run_all(runner_s, CK_VERBOSE);
  srunner_run_all(runner_s1, CK_VERBOSE);
  Suite *test_g = s21_gulianbo_suite();
  SRunner *runner_g = srunner_create(test_g);
  srunner_run_all(runner_g, CK_VERBOSE);
  srunner_ntests_failed(runner_g);
  srunner_free(runner_g);
  srunner_free(runner_s);
  srunner_free(runner_s1);
  return 0;
}