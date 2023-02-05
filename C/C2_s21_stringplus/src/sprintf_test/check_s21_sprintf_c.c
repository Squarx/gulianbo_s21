#include "test.h"

START_TEST(sprintf_0) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %c leh";
  char q = 'q';
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_1) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %c leh";
  char q = '9';
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_2) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %c leh";
  char q = ' ';
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_3) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %c leh";
  char q = '\n';
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_4) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %c leh";
  char q = '\0';
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
//=======================================
START_TEST(sprintf_5) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %3c leh";
  char q = 'q';
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_6) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %3c leh";
  char q = '9';
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_7) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %3c leh";
  char q = ' ';
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_8) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %3c leh";
  char q = '\n';
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_9) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %3c leh";
  char q = '\0';
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
//=======================================
START_TEST(sprintf_10) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %1c leh";
  char q = 'q';
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_11) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %1c leh";
  char q = '9';
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_12) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %1c leh";
  char q = ' ';
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_13) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %1c leh";
  char q = '\n';
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_14) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %1c leh";
  char q = '\0';
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
//=======================================
START_TEST(sprintf_15) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-1c leh";
  char q = 'q';
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_16) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-1c leh";
  char q = '9';
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_17) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-1c leh";
  char q = ' ';
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_18) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-1c leh";
  char q = '\n';
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_19) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-1c leh";
  char q = '\0';
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
//=======================================
START_TEST(sprintf_20) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-3c leh";
  char q = 'q';
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_21) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-3c leh";
  char q = '9';
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_22) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-3c leh";
  char q = ' ';
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_23) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-3c leh";
  char q = '\n';
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_24) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-3c leh";
  char q = '\0';
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
//=======================================
START_TEST(sprintf_30) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %lc leh";
  char q = 'q';
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_31) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %lc leh";
  char q = '9';
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_32) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %lc leh";
  char q = ' ';
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_33) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %lc leh";
  char q = '\n';
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_34) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %lc leh";
  char q = '\0';
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
//=======================================
START_TEST(sprintf_40) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-lc leh";
  char q = 'q';
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_41) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-lc leh";
  char q = '9';
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_42) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-lc leh";
  char q = ' ';
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_43) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-lc leh";
  char q = '\n';
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_44) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-lc leh";
  char q = '\0';
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
//=======================================
START_TEST(sprintf_50) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-3lc leh";
  char q = 'q';
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_51) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-3lc leh";
  char q = '9';
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_52) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-3lc leh";
  char q = ' ';
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_53) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-3lc leh";
  char q = '\n';
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_54) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-3lc leh";
  char q = '\0';
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
//=============================неможко доп проверки
START_TEST(sprintf_55) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %c %% leh";
  char q = 'q';
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST

Suite *s21_sprintf_c_suite(void) {
  Suite *s;
  TCase *ts_core;
  s = suite_create("s21_sprintf_c");  //создает набор кейсов с заданным именем
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
  tcase_add_test(ts_core, sprintf_11);
  tcase_add_test(ts_core, sprintf_12);
  tcase_add_test(ts_core, sprintf_13);
  tcase_add_test(ts_core, sprintf_14);
  tcase_add_test(ts_core, sprintf_15);
  tcase_add_test(ts_core, sprintf_16);
  tcase_add_test(ts_core, sprintf_17);
  tcase_add_test(ts_core, sprintf_18);
  tcase_add_test(ts_core, sprintf_19);
  tcase_add_test(ts_core, sprintf_20);
  tcase_add_test(ts_core, sprintf_21);
  tcase_add_test(ts_core, sprintf_22);
  tcase_add_test(ts_core, sprintf_23);
  tcase_add_test(ts_core, sprintf_24);
  tcase_add_test(ts_core, sprintf_30);
  tcase_add_test(ts_core, sprintf_31);
  tcase_add_test(ts_core, sprintf_32);
  tcase_add_test(ts_core, sprintf_33);
  tcase_add_test(ts_core, sprintf_34);
  tcase_add_test(ts_core, sprintf_40);
  tcase_add_test(ts_core, sprintf_41);
  tcase_add_test(ts_core, sprintf_42);
  tcase_add_test(ts_core, sprintf_43);
  tcase_add_test(ts_core, sprintf_44);
  tcase_add_test(ts_core, sprintf_50);
  tcase_add_test(ts_core, sprintf_51);
  tcase_add_test(ts_core, sprintf_52);
  tcase_add_test(ts_core, sprintf_53);
  tcase_add_test(ts_core, sprintf_54);
  tcase_add_test(ts_core, sprintf_55);

  suite_add_tcase(s, ts_core);
  return s;
}