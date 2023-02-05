#include "test.h"
START_TEST(sprintf_0) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %s leh";
  char q[] = "qqq";
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST

START_TEST(sprintf_1) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %s leh";
  char q[] = "q";
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST

START_TEST(sprintf_2) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %s leh";
  char q[] = "9";
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST

START_TEST(sprintf_3) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %s leh";
  char q[] = "999";
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
// //=========================
START_TEST(sprintf_4) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-s leh";
  char q[] = "qqq";
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
//=========================
START_TEST(sprintf_5) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %3s leh";
  char q[] = "qq";
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_6) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %3s leh";
  char q[] = "qqq";
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_7) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %3s leh";
  char q[] = "qqqq";
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
//=========================
START_TEST(sprintf_8) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %.3s leh";
  char q[] = "qq";
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_9) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %.3s leh";
  char q[] = "qqq";
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_10) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %.3s leh";
  char q[] = "qqqq";
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
//=========================

//=========================
START_TEST(sprintf_12) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-3s leh";
  char q[] = "qq";
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_13) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-3s leh";
  char q[] = "qqq";
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_14) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-3s leh";
  char q[] = "qqqq";
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
//=========================
START_TEST(sprintf_15) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-.3s leh";
  char q[] = "qq";
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_16) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-.3s leh";
  char q[] = "qqq";
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_17) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-.3s leh";
  char q[] = "qqqq";
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
//=========================

//=========================
START_TEST(sprintf_19) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %3.3s leh";
  char q[] = "qqqq";
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_20) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %4.3s leh";
  char q[] = "qqqq";
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_21) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %3.4s leh";
  char q[] = "qqqq";
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_22) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %4.4s leh";
  char q[] = "qqqq";
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_23) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %5.4s leh";
  char q[] = "qqqq";
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_24) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %4.5s leh";
  char q[] = "qqqq";
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_25) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %5.5s leh";
  char q[] = "qqqq";
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
//=========================

//=========================

//=========================
START_TEST(sprintf_32) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-3.3s leh";
  char q[] = "qqqq";
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_33) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-4.3s leh";
  char q[] = "qqqq";
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_34) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-3.4s leh";
  char q[] = "qqqq";
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_35) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-4.4s leh";
  char q[] = "qqqq";
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_36) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-5.4s leh";
  char q[] = "qqqq";
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_37) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-4.5s leh";
  char q[] = "qqqq";
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_38) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-5.5s leh";
  char q[] = "qqqq";
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_39) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-5.0s leh";
  char q[] = "qqqq";
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_40) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-4.0s leh";
  char q[] = "qqqq";
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_41) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-3.0s leh";
  char q[] = "qqqq";
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_42) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-.0s leh";
  char q[] = "qqqq";
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_43) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %.0s leh";
  char q[] = "qqqq";
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
//=========================

Suite *s21_sprintf_s_suite(void) {
  Suite *s;
  TCase *ts_core;
  s = suite_create("s21_sprintf_s");  //создает набор кейсов с заданным именем
  ts_core = tcase_create("case_sprintf");
  tcase_add_test(ts_core, sprintf_0);
  tcase_add_test(ts_core, sprintf_1);
  tcase_add_test(ts_core, sprintf_2);
  tcase_add_test(ts_core, sprintf_3);
  tcase_add_test(ts_core, sprintf_4);
  tcase_add_test(ts_core, sprintf_5);
  tcase_add_test(ts_core, sprintf_6);
  tcase_add_test(ts_core, sprintf_7);
  tcase_add_test(ts_core, sprintf_8);
  tcase_add_test(ts_core, sprintf_9);
  tcase_add_test(ts_core, sprintf_10);
  tcase_add_test(ts_core, sprintf_12);
  tcase_add_test(ts_core, sprintf_13);
  tcase_add_test(ts_core, sprintf_14);
  tcase_add_test(ts_core, sprintf_15);
  tcase_add_test(ts_core, sprintf_16);
  tcase_add_test(ts_core, sprintf_17);
  tcase_add_test(ts_core, sprintf_19);
  tcase_add_test(ts_core, sprintf_20);
  tcase_add_test(ts_core, sprintf_21);
  tcase_add_test(ts_core, sprintf_22);
  tcase_add_test(ts_core, sprintf_23);
  tcase_add_test(ts_core, sprintf_24);
  tcase_add_test(ts_core, sprintf_25);
  tcase_add_test(ts_core, sprintf_32);
  tcase_add_test(ts_core, sprintf_33);
  tcase_add_test(ts_core, sprintf_34);
  tcase_add_test(ts_core, sprintf_35);
  tcase_add_test(ts_core, sprintf_36);
  tcase_add_test(ts_core, sprintf_37);
  tcase_add_test(ts_core, sprintf_38);
  tcase_add_test(ts_core, sprintf_39);
  tcase_add_test(ts_core, sprintf_40);
  tcase_add_test(ts_core, sprintf_41);
  tcase_add_test(ts_core, sprintf_42);
  tcase_add_test(ts_core, sprintf_43);

  suite_add_tcase(s, ts_core);
  return s;
}