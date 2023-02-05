
#include "test.h"
START_TEST(sprintf_0) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %f leh";
  float q = 33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST

START_TEST(sprintf_1) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %f leh";
  float q = -33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_2) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %f leh";
  float q = 0;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_3) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %f leh";
  float q = 33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_4) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %f leh";
  float q = -33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_5) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %f leh";
  float q = -33.30;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_6) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %f leh";
  float q = 33.30;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
//+++++++++=+++++++++++++++++++++
START_TEST(sprintf_7) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % f leh";
  float q = 33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST

START_TEST(sprintf_8) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % f leh";
  float q = -33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_9) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % f leh";
  float q = 0;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_10) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % f leh";
  float q = 33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_11) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % f leh";
  float q = -33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_12) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % f leh";
  float q = -33.30;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_13) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % f leh";
  float q = 33.30;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
//+++++++++=+++++++++++++++++++++
START_TEST(sprintf_14) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-f leh";
  float q = 33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST

START_TEST(sprintf_15) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-f leh";
  float q = -33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_16) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-f leh";
  float q = 0;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_17) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-f leh";
  float q = 33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_18) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-f leh";
  float q = -33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_19) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-f leh";
  float q = -33.30;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_20) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-f leh";
  float q = 33.30;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
//+++++++++=+++++++++++++++++++++
START_TEST(sprintf_21) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+f leh";
  float q = 33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST

START_TEST(sprintf_22) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+f leh";
  float q = -33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_23) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+f leh";
  double q = 0;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_24) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+f leh";
  float q = 33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_25) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+f leh";
  float q = -33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_26) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+f leh";
  float q = -33.30;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_27) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+f leh";
  float q = 33.30;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
//+++++++++=+++++++++++++++++++++
START_TEST(sprintf_28) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %3f leh";
  float q = 33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_29) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %3f leh";
  float q = -33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_30) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %3f leh";
  float q = 0;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_31) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %3f leh";
  float q = 333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_32) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %3f leh";
  float q = -333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_33) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %3f leh";
  float q = 3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_34) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %3f leh";
  float q = -3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_35) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %3f leh";
  float q = 33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_36) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %3f leh";
  float q = -33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_37) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %4f leh";
  float q = 33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_38) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %4f leh";
  float q = -33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_39) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %4f leh";
  float q = 33.333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_40) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %4f leh";
  float q = -33.333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
//====================
START_TEST(sprintf_41) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %f leh";
  double q = 33.0;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_42) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %f leh";
  float q = -33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_43) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %f leh";
  float q = 0;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_44) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %.3f leh";
  float q = 33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_45) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %.3f leh";
  float q = -33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_46) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %.3f leh";
  float q = 33.000;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_47) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %.3f leh";
  float q = -33.000;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_48) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %.0f leh";
  float q = 33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_50) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %.0f leh";
  float q = -33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_51) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %.0f leh";
  float q = 0;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_52) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %.0f leh";
  float q = 33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_53) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %.0f leh";
  float q = -33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_54) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %.0f leh";
  float q = 33.000;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_55) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %.0f leh";
  float q = -33.000;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
//========================
START_TEST(sprintf_56) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %lf leh";
  double q = 33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_57) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %lf leh";
  double q = -33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_58) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %lf leh";
  double q = 0;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_59) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %lf leh";
  double q = 33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_60) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %lf leh";
  double q = 33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_61) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %lf leh";
  double q = 33.333333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_62) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %lf leh";
  double q = -33.333333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_63) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %lf leh";
  double q = 33.33333333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_64) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %lf leh";
  double q = -33.333333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
//+++++++++=+++++++++++++++++++++
START_TEST(sprintf_65) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % -f leh";
  float q = 33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST

START_TEST(sprintf_66) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % -f leh";
  float q = -33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_67) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % -f leh";
  float q = 0;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_68) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % -f leh";
  float q = 33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_69) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % -f leh";
  float q = -33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_70) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % -f leh";
  float q = -33.30;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_71) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % -f leh";
  float q = 33.30;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
//+++++++++=+++++++++++++++++++++
START_TEST(sprintf_72) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+f leh";
  float q = 33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST

START_TEST(sprintf_73) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+f leh";
  float q = -33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_74) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+f leh";
  float q = 0;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_75) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+f leh";
  float q = 33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_76) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+f leh";
  float q = -33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_77) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+f leh";
  float q = -33.30;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_78) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+f leh";
  float q = 33.30;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
//+++++++++=+++++++++++++++++++++
START_TEST(sprintf_79) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % 3f leh";
  float q = 33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_80) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % 3f leh";
  float q = -33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_81) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % 3f leh";
  float q = 0;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_82) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % 3f leh";
  float q = 333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_83) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % 3f leh";
  float q = -333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_84) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % 3f leh";
  float q = 3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_85) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % 3f leh";
  float q = -3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_86) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % 3f leh";
  float q = 33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_87) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % 3f leh";
  float q = -33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_88) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % 4f leh";
  float q = 33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_89) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % 4f leh";
  float q = -33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_90) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % 4f leh";
  float q = 33.333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_91) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % 4f leh";
  float q = -33.333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
//====================
START_TEST(sprintf_92) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % .3f leh";
  float q = 33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_93) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % .3f leh";
  float q = -33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_94) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % .3f leh";
  float q = 0;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_95) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % .3f leh";
  float q = 33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_96) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % .3f leh";
  float q = -33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_97) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % .3f leh";
  float q = 33.000;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_98) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % .3f leh";
  float q = -33.000;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_99) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % .0f leh";
  float q = 33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_100) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % .0f leh";
  float q = -33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_101) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % .0f leh";
  float q = 0;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_102) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % .0f leh";
  float q = 33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_103) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % .0f leh";
  float q = -33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_104) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % .0f leh";
  float q = 33.000;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_105) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % .0f leh";
  float q = -33.000;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
//========================
START_TEST(sprintf_106) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % lf leh";
  double q = 33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_107) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % lf leh";
  double q = -33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_108) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % lf leh";
  double q = 0;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_109) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % lf leh";
  double q = 33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_110) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % lf leh";
  double q = 33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_111) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % lf leh";
  double q = 33.333333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_112) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % lf leh";
  double q = -33.333333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_113) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % lf leh";
  double q = 33.33333333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_114) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % lf leh";
  double q = -33.333333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
//+++++++++=+++++++++++++++++++++
START_TEST(sprintf_115) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-3f leh";
  float q = 33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_116) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-3f leh";
  float q = -33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_117) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-3f leh";
  float q = 0;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_118) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-3f leh";
  float q = 333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_119) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-3f leh";
  float q = -333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_120) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-3f leh";
  float q = 3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_121) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-3f leh";
  float q = -3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_122) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-3f leh";
  float q = 33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_123) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-3f leh";
  float q = -33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_124) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-4f leh";
  float q = 33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_125) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-4f leh";
  float q = -33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_126) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-4f leh";
  float q = 33.333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_127) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-4f leh";
  float q = -33.333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
//====================
START_TEST(sprintf_128) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-.3f leh";
  float q = 33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_129) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-.3f leh";
  float q = -33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_130) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-.3f leh";
  float q = 0;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_131) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-.3f leh";
  float q = 33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_132) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-.3f leh";
  float q = -33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_133) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-.3f leh";
  float q = 33.000;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_134) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-.3f leh";
  float q = -33.000;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_135) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-.0f leh";
  float q = 33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_136) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-.0f leh";
  float q = -33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_137) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-.0f leh";
  float q = 0;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_138) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-.0f leh";
  float q = 33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_139) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-.0f leh";
  float q = -33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_140) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-.0f leh";
  float q = 33.000;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_141) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-.0f leh";
  float q = -33.000;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
//========================
START_TEST(sprintf_142) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-lf leh";
  double q = 33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_143) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-lf leh";
  double q = -33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_144) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-lf leh";
  double q = 0;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_145) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-lf leh";
  double q = 33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_146) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-lf leh";
  double q = 33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_147) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-lf leh";
  double q = 33.333333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_148) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-lf leh";
  double q = -33.333333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_149) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-lf leh";
  double q = 33.33333333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_150) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-lf leh";
  double q = -33.333333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
//+++++++++=+++++++++++++++++++++
START_TEST(sprintf_151) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+3f leh";
  float q = 33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_152) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+3f leh";
  float q = -33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_153) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+3f leh";
  float q = 0;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_154) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+3f leh";
  float q = 333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_155) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+3f leh";
  float q = -333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_156) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+3f leh";
  float q = 3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_157) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+3f leh";
  float q = -3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_158) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+3f leh";
  float q = 33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_159) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+3f leh";
  float q = -33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_160) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+4f leh";
  float q = 33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_161) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+4f leh";
  float q = -33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_162) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+4f leh";
  float q = 33.333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_163) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+4f leh";
  float q = -33.333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
//====================
START_TEST(sprintf_164) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+.3f leh";
  float q = 33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_165) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+.3f leh";
  float q = -33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_166) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+.3f leh";
  float q = 0;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_167) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+.3f leh";
  float q = 33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_168) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+.3f leh";
  float q = -33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_169) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+.3f leh";
  float q = 33.000;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_170) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+.3f leh";
  float q = -33.000;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_171) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+.0f leh";
  float q = 33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_172) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+.0f leh";
  float q = -33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_173) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+.0f leh";
  float q = 0;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_174) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+.0f leh";
  float q = 33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_175) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+.0f leh";
  float q = -33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_176) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+.0f leh";
  float q = 33.000;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_177) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+.0f leh";
  float q = -33.000;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
//========================
START_TEST(sprintf_178) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+lf leh";
  double q = 33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_179) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+lf leh";
  double q = -33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_180) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+lf leh";
  double q = 0;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_181) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+lf leh";
  double q = 33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_182) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+lf leh";
  double q = 33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_183) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+lf leh";
  double q = 33.333333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_184) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+lf leh";
  double q = -33.333333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_185) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+lf leh";
  double q = 33.33333333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_186) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+lf leh";
  double q = -33.333333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
//==================================
//+++++++++=+++++++++++++++++++++
START_TEST(sprintf_187) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+3f leh";
  float q = 33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_188) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+3f leh";
  float q = -33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_189) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+3f leh";
  float q = 0;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_190) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+3f leh";
  float q = 333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_191) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+3f leh";
  float q = -333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_192) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+3f leh";
  float q = 3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_193) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+3f leh";
  float q = -3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_194) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+3f leh";
  float q = 33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_195) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+3f leh";
  float q = -33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_196) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+4f leh";
  float q = 33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_197) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+4f leh";
  float q = -33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_198) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+4f leh";
  float q = 33.333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_199) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+4f leh";
  float q = -33.333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
//====================
START_TEST(sprintf_200) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+.3f leh";
  float q = 33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_201) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+.3f leh";
  float q = -33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_202) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+.3f leh";
  float q = 0;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_203) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+.3f leh";
  float q = 33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_204) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+.3f leh";
  float q = -33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_205) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+.3f leh";
  float q = 33.000;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_206) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+.3f leh";
  float q = -33.000;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_207) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+.0f leh";
  float q = 33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_208) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+.0f leh";
  float q = -33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_209) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+.0f leh";
  float q = 0;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_210) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+.0f leh";
  float q = 33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_211) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+.0f leh";
  float q = -33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_212) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+.0f leh";
  float q = 33.000;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_213) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+.0f leh";
  float q = -33.000;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
//========================
START_TEST(sprintf_214) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+lf leh";
  double q = 33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_215) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+lf leh";
  double q = -33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_216) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+lf leh";
  double q = 0;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_217) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+lf leh";
  double q = 33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_218) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+lf leh";
  double q = 33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_219) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+lf leh";
  double q = 33.333333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_220) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+lf leh";
  double q = -33.333333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_221) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+lf leh";
  double q = 33.33333333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_222) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+lf leh";
  double q = -33.333333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
//+++++++++=+++++++++++++++++++++
START_TEST(sprintf_223) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %- 3f leh";
  float q = 33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_224) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %- 3f leh";
  float q = -33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_225) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %- 3f leh";
  float q = 0;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_226) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %- 3f leh";
  float q = 333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_227) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %- 3f leh";
  float q = -333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_228) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %- 3f leh";
  float q = 3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_229) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %- 3f leh";
  float q = -3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_230) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %- 3f leh";
  float q = 33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_231) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %- 3f leh";
  float q = -33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_232) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %- 4f leh";
  float q = 33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_233) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %- 4f leh";
  float q = -33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_234) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %- 4f leh";
  float q = 33.333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_235) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %- 4f leh";
  float q = -33.333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
//====================
START_TEST(sprintf_236) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %- .3f leh";
  float q = 33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_237) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %- .3f leh";
  float q = -33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_238) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %- .3f leh";
  float q = 0;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_239) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %- .3f leh";
  float q = 33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_240) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %- .3f leh";
  float q = -33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_241) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %- .3f leh";
  float q = 33.000;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_242) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %- .3f leh";
  float q = -33.000;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_243) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %- .0f leh";
  float q = 33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_244) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %- .0f leh";
  float q = -33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_245) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %- .0f leh";
  float q = 0;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_246) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %- .0f leh";
  float q = 33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_247) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %- .0f leh";
  float q = -33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_248) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %- .0f leh";
  float q = 33.000;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_249) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %- .0f leh";
  float q = -33.000;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
//========================
START_TEST(sprintf_250) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %- lf leh";
  double q = 33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_251) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %- lf leh";
  double q = -33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_252) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %- lf leh";
  double q = 0;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_253) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %- lf leh";
  double q = 33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_254) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %- lf leh";
  double q = 33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_255) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %- lf leh";
  double q = 33.333333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_256) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %- lf leh";
  double q = -33.333333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_257) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %- lf leh";
  double q = 33.33333333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_258) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %- lf leh";
  double q = -33.333333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
//====================
START_TEST(sprintf_259) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %3.3f leh";
  float q = 33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_260) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %3.3f leh";
  float q = -33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_261) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %3.3f leh";
  float q = 0;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_262) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %4.3f leh";
  float q = 33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_263) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %4.3f leh";
  float q = -33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_264) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %.4f leh";
  double q = 33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_265) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %4.4f leh";
  double q = -33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_267) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %3.4f leh";
  double q = 33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_268) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %3.4f leh";
  double q = -33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_269) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %4.3f leh";
  double q = 33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_270) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %4.3f leh";
  double q = -33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_271) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %4.4f leh";
  float q = 33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_272) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %4.4f leh";
  float q = -33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_273) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %4.3f leh";
  float q = 33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_274) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %4.3f leh";
  float q = -33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_275) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %3.4f leh";
  float q = 33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_276) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %3.4f leh";
  float q = -33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_277) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %5.4f leh";
  float q = 33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_278) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %5.4f leh";
  float q = -33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_279) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %4.4f leh";
  float q = 33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_280) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %4.4f leh";
  float q = -33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_281) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %3.4f leh";
  float q = 33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_282) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %3.4f leh";
  float q = -33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_283) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %4.3f leh";
  float q = 33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_284) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %4.3f leh";
  float q = -33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
//====================
START_TEST(sprintf_285) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % 3.3f leh";
  float q = 33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_286) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % 3.3f leh";
  float q = -33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_287) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % 3.3f leh";
  float q = 0;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_288) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % 4.3f leh";
  float q = 33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_289) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % 4.3f leh";
  float q = -33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_290) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % 4.4f leh";
  double q = 33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_291) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % 4.4f leh";
  double q = -33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_292) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % 3.4f leh";
  double q = 33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_293) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % 3.4f leh";
  double q = -33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_294) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % 4.3f leh";
  double q = 33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_295) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % 4.3f leh";
  double q = -33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_296) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % 4.4f leh";
  float q = 33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_297) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % 4.4f leh";
  float q = -33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_298) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % 4.3f leh";
  float q = 33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_299) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % 4.3f leh";
  float q = -33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_300) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % 3.4f leh";
  float q = 33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_301) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % 3.4f leh";
  float q = -33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_302) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % 5.4f leh";
  float q = 33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_303) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % 5.4f leh";
  float q = -33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_304) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % 4.4f leh";
  float q = 33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_305) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % 4.4f leh";
  float q = -33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_306) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % 3.4f leh";
  float q = 33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_307) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % 3.4f leh";
  float q = -33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_308) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % 4.3f leh";
  float q = 33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_309) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % 4.3f leh";
  float q = -33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
//====================
START_TEST(sprintf_310) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-3.3f leh";
  float q = 33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_311) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-3.3f leh";
  float q = -33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_312) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-3.3f leh";
  float q = 0;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_313) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-4.3f leh";
  float q = 33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_314) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-4.3f leh";
  float q = -33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_315) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-4.4f leh";
  float q = 33.0;
  //  printf("Orig = %s\n", test_str);
  //  printf("My = %s\n", test_str_1);
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));

  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_316) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  //  char parameters[] = "leh %-4.4f leh";
  float q = -33.;
  ck_assert_int_eq(s21_sprintf(test_str, "leh %-4.4f leh", q),
                   sprintf(test_str_1, "leh %-4.4f leh", q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_317) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-3.4f leh";
  float q = 33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_318) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-3.4f leh";
  float q = -33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_319) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-4.3f leh";
  double q = 33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_320) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-4.3f leh";
  float q = -33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_321) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-4.4f leh";
  float q = 33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_322) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-4.4f leh";
  float q = -33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_323) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-4.3f leh";
  float q = 33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_324) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-4.3f leh";
  float q = -33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_325) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-3.4f leh";
  float q = 33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_326) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-3.4f leh";
  float q = -33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_327) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-5.4f leh";
  float q = 33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_328) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-5.4f leh";
  float q = -33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_329) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-4.4f leh";
  float q = 33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_330) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-4.4f leh";
  float q = -33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_331) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-3.4f leh";
  float q = 33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_332) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-3.4f leh";
  float q = -33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_333) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-4.3f leh";
  float q = 33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_334) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-4.3f leh";
  float q = -33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
//====================
START_TEST(sprintf_335) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+3.3f leh";
  float q = 33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_336) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+3.3f leh";
  float q = -33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_337) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+3.3f leh";
  float q = 0;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_338) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+4.3f leh";
  float q = 33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_339) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+4.3f leh";
  float q = -33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_340) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+4.4f leh";
  double q = 33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_341) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+4.4f leh";
  double q = -33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_342) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+3.4f leh";
  double q = 33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_343) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+3.4f leh";
  double q = -33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_344) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+4.3f leh";
  double q = 33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_345) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+4.3f leh";
  double q = -33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_346) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+4.4f leh";
  float q = 33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_347) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+4.4f leh";
  float q = -33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_348) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+4.3f leh";
  float q = 33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_349) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+4.3f leh";
  float q = -33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_350) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+3.4f leh";
  float q = 33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_351) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+3.4f leh";
  float q = -33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_352) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+5.4f leh";
  float q = 33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_353) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+5.4f leh";
  float q = -33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_354) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+4.4f leh";
  float q = 33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_355) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+4.4f leh";
  float q = -33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_356) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+3.4f leh";
  float q = 33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_357) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+3.4f leh";
  float q = -33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_358) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+4.3f leh";
  float q = 33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_359) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+4.3f leh";
  float q = -33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
//====================
START_TEST(sprintf_360) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+3.3f leh";
  float q = 33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_361) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+3.3f leh";
  float q = -33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_362) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+3.3f leh";
  float q = 0;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_363) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+4.3f leh";
  float q = 33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_364) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+4.3f leh";
  float q = -33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_365) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+4.4f leh";
  double q = 33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_366) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+4.4f leh";
  double q = -33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_367) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+3.4f leh";
  double q = 33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_368) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+3.4f leh";
  double q = -33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_369) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+4.3f leh";
  double q = 33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_370) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+4.3f leh";
  double q = -33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_371) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+4.4f leh";
  float q = 33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_372) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+4.4f leh";
  float q = -33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_373) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+4.3f leh";
  float q = 33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_374) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+4.3f leh";
  float q = -33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_375) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+3.4f leh";
  float q = 33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_376) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+3.4f leh";
  float q = -33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_377) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+5.4f leh";
  float q = 33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_378) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+5.4f leh";
  float q = -33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_379) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+4.4f leh";
  float q = 33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_380) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+4.4f leh";
  float q = -33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_381) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+3.4f leh";
  float q = 33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_382) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+3.4f leh";
  float q = -33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_383) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+4.3f leh";
  float q = 33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_384) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+4.3f leh";
  float q = -33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
//====================
START_TEST(sprintf_385) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %3.3lf leh";
  double q = 33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_386) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %3.3lf leh";
  double q = -33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_387) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %3.3lf leh";
  double q = 0;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_388) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %4.3lf leh";
  double q = 33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_389) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %4.3lf leh";
  double q = -33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_390) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %4.4lf leh";
  double q = 33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_391) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %4.4lf leh";
  double q = -33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_392) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %3.4lf leh";
  double q = 33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_393) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %3.4lf leh";
  double q = -33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_394) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %4.3lf leh";
  double q = 33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_395) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %4.3lf leh";
  double q = -33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_396) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %4.4lf leh";
  double q = 33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_397) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %4.4lf leh";
  double q = -33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_398) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %4.3lf leh";
  double q = 33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_399) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %4.3lf leh";
  double q = -33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_400) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %3.4lf leh";
  double q = 33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_401) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %3.4lf leh";
  double q = -33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_402) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %5.4lf leh";
  double q = 33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_403) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %5.4lf leh";
  double q = -33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_404) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %4.4lf leh";
  double q = 33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_405) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %4.4lf leh";
  double q = -33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_406) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %3.4lf leh";
  double q = 33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_407) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %3.4lf leh";
  double q = -33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_408) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %4.3lf leh";
  double q = 33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_409) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %4.3lf leh";
  double q = -33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
//====================
START_TEST(sprintf_410) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % 3.3lf leh";
  double q = 33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_411) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % 3.3lf leh";
  double q = -33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_412) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % 3.3lf leh";
  double q = 0;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_413) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % 4.3lf leh";
  double q = 33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_414) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % 4.3lf leh";
  double q = -33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_415) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % 4.4lf leh";
  double q = 33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_416) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % 4.4lf leh";
  double q = -33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_417) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % 3.4lf leh";
  double q = 33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_418) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % 3.4lf leh";
  double q = -33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_419) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % 4.3lf leh";
  double q = 33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_420) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % 4.3lf leh";
  double q = -33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_421) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % 4.4lf leh";
  double q = 33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_422) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % 4.4lf leh";
  double q = -33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_423) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % 4.3lf leh";
  double q = 33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_424) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % 4.3lf leh";
  double q = -33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_425) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % 3.4lf leh";
  double q = 33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_426) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % 3.4lf leh";
  double q = -33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_427) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % 5.4lf leh";
  double q = 33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_428) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % 5.4lf leh";
  double q = -33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_429) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % 4.4lf leh";
  double q = 33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_430) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % 4.4lf leh";
  double q = -33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_431) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % 3.4lf leh";
  double q = 33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_432) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % 3.4lf leh";
  double q = -33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_433) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % 4.3lf leh";
  double q = 33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_434) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % 4.3lf leh";
  double q = -33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
//====================
START_TEST(sprintf_435) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-3.3lf leh";
  double q = 33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_436) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-3.3lf leh";
  double q = -33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_437) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-3.3lf leh";
  double q = 0;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_438) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-4.3lf leh";
  double q = 33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_439) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-4.3lf leh";
  double q = -33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_440) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-4.4lf leh";
  double q = 33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_441) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-4.4lf leh";
  double q = -33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_442) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-3.4lf leh";
  double q = 33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_443) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-3.4lf leh";
  double q = -33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_444) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-4.3lf leh";
  double q = 33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_445) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-4.3lf leh";
  double q = -33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_446) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-4.4lf leh";
  double q = 33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_447) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-4.4lf leh";
  double q = -33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_448) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-4.3lf leh";
  double q = 33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_449) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-4.3lf leh";
  double q = -33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_450) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-3.4lf leh";
  double q = 33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_451) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-3.4lf leh";
  double q = -33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_452) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-5.4lf leh";
  double q = 33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_453) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-5.4lf leh";
  double q = -33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_454) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-4.4lf leh";
  double q = 33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_455) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-4.4lf leh";
  double q = -33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_456) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-3.4lf leh";
  double q = 33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_457) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-3.4lf leh";
  double q = -33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_458) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-4.3lf leh";
  double q = 33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_459) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-4.3lf leh";
  double q = -33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
//====================
START_TEST(sprintf_460) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+3.3lf leh";
  double q = 33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_461) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+3.3lf leh";
  double q = -33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_462) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+3.3lf leh";
  double q = 0;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_463) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+4.3lf leh";
  double q = 33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_464) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+4.3lf leh";
  double q = -33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_465) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+4.4lf leh";
  double q = 33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_466) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+4.4lf leh";
  double q = -33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_467) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+3.4lf leh";
  double q = 33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_468) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+3.4lf leh";
  double q = -33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_469) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+4.3lf leh";
  double q = 33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_470) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+4.3lf leh";
  double q = -33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_471) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+4.4lf leh";
  double q = 33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_472) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+4.4lf leh";
  double q = -33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_473) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+4.3lf leh";
  double q = 33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_474) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+4.3lf leh";
  double q = -33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_475) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+3.4lf leh";
  double q = 33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_476) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+3.4lf leh";
  double q = -33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_477) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+5.4lf leh";
  double q = 33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_478) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+5.4lf leh";
  double q = -33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_479) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+4.4lf leh";
  double q = 33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_480) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+4.4lf leh";
  double q = -33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_481) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+3.4lf leh";
  double q = 33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_482) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+3.4lf leh";
  double q = -33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_483) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+4.3lf leh";
  double q = 33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_484) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+4.3lf leh";
  double q = -33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
//====================
START_TEST(sprintf_485) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+3.3lf leh";
  double q = 33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_486) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+3.3lf leh";
  double q = -33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_487) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+3.3lf leh";
  double q = 0;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_488) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+4.3lf leh";
  double q = 33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_489) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+4.3lf leh";
  double q = -33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_490) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+4.4lf leh";
  double q = 33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_491) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+4.4lf leh";
  double q = -33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_492) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+3.4lf leh";
  double q = 33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_493) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+3.4lf leh";
  double q = -33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_494) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+4.3lf leh";
  double q = 33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_495) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+4.3lf leh";
  double q = -33.3;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_496) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+4.4lf leh";
  double q = 33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_497) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+4.4lf leh";
  double q = -33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_498) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+4.3lf leh";
  double q = 33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_499) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+4.3lf leh";
  double q = -33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_500) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+3.4lf leh";
  double q = 33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_501) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+3.4lf leh";
  double q = -33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_502) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+5.4lf leh";
  double q = 33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_503) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+5.4lf leh";
  double q = -33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_504) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+4.4lf leh";
  double q = 33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_505) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+4.4lf leh";
  double q = -33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_506) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+3.4lf leh";
  double q = 33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_507) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+3.4lf leh";
  double q = -33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_508) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+4.3lf leh";
  double q = 33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_509) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+4.3lf leh";
  double q = -33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
//=============================
START_TEST(sprintf_510) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-10.4f leh";
  double q = 33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_511) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-10.4lf leh";
  double q = -33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_512) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-10.4lf leh";
  double q = 33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_513) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-10.4lf leh";
  double q = -33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_514) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-10.4lf leh";
  double q = 33.33333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_515) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-10.4lf leh";
  double q = -33.33333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
//===================================
START_TEST(sprintf_516) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-10.4f leh";
  double q = 33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_517) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-10.4f leh";
  double q = -33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_518) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-10.4f leh";
  double q = 33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_519) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-10.4f leh";
  double q = -33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_520) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-10.4f leh";
  double q = 33.33333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_521) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-10.4f leh";
  double q = -33.33333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
//===================================
START_TEST(sprintf_522) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % 10.4f leh";
  float q = 33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_523) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % 10.4f leh";
  double q = -33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_524) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % 10.4f leh";
  float q = 33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_525) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % 10.4f leh";
  float q = -33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_526) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % 10.4f leh";
  float q = 33.33333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_527) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh % 10.4f leh";
  float q = -33.33333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
//===================================
START_TEST(sprintf_528) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+10.4f leh";
  double q = 33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_529) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+10.4f leh";
  double q = -33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_530) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+10.4f leh";
  double q = 33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_531) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+10.4f leh";
  double q = -33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_532) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+10.4f leh";
  double q = 33.33333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_533) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %+10.4f leh";
  double q = -33.33333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
//===================================
START_TEST(sprintf_534) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+10.4f leh";
  double q = 33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_535) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+10.4f leh";
  double q = -33.33;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_536) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+10.4f leh";
  double q = 33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_537) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+10.4f leh";
  double q = -33.3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_538) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+10.4f leh";
  double q = 33.33333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
START_TEST(sprintf_539) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-+10.4f leh";
  double q = -33.33333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}

Suite *s21_sprintf_f_suite(void) {
  Suite *s;
  TCase *ts_core;
  s = suite_create("s21_sprintf_f");  //создает набор кейсов с заданным именем
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
  tcase_add_test(ts_core, sprintf_25);
  tcase_add_test(ts_core, sprintf_26);
  tcase_add_test(ts_core, sprintf_27);
  tcase_add_test(ts_core, sprintf_28);
  tcase_add_test(ts_core, sprintf_29);
  tcase_add_test(ts_core, sprintf_30);
  tcase_add_test(ts_core, sprintf_31);
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
  tcase_add_test(ts_core, sprintf_44);
  tcase_add_test(ts_core, sprintf_45);
  tcase_add_test(ts_core, sprintf_46);
  tcase_add_test(ts_core, sprintf_47);
  tcase_add_test(ts_core, sprintf_48);
  tcase_add_test(ts_core, sprintf_50);
  tcase_add_test(ts_core, sprintf_51);
  tcase_add_test(ts_core, sprintf_52);
  tcase_add_test(ts_core, sprintf_53);
  tcase_add_test(ts_core, sprintf_54);
  tcase_add_test(ts_core, sprintf_55);
  tcase_add_test(ts_core, sprintf_56);
  tcase_add_test(ts_core, sprintf_57);
  tcase_add_test(ts_core, sprintf_58);
  tcase_add_test(ts_core, sprintf_59);
  tcase_add_test(ts_core, sprintf_60);
  tcase_add_test(ts_core, sprintf_61);
  tcase_add_test(ts_core, sprintf_62);
  tcase_add_test(ts_core, sprintf_63);
  tcase_add_test(ts_core, sprintf_64);
  tcase_add_test(ts_core, sprintf_65);
  tcase_add_test(ts_core, sprintf_66);
  tcase_add_test(ts_core, sprintf_67);
  tcase_add_test(ts_core, sprintf_68);
  tcase_add_test(ts_core, sprintf_69);
  tcase_add_test(ts_core, sprintf_70);
  tcase_add_test(ts_core, sprintf_71);
  tcase_add_test(ts_core, sprintf_72);
  tcase_add_test(ts_core, sprintf_73);
  tcase_add_test(ts_core, sprintf_74);
  tcase_add_test(ts_core, sprintf_75);
  tcase_add_test(ts_core, sprintf_76);
  tcase_add_test(ts_core, sprintf_77);
  tcase_add_test(ts_core, sprintf_78);
  tcase_add_test(ts_core, sprintf_79);
  tcase_add_test(ts_core, sprintf_80);
  tcase_add_test(ts_core, sprintf_81);
  tcase_add_test(ts_core, sprintf_82);
  tcase_add_test(ts_core, sprintf_83);
  tcase_add_test(ts_core, sprintf_84);
  tcase_add_test(ts_core, sprintf_85);
  tcase_add_test(ts_core, sprintf_86);
  tcase_add_test(ts_core, sprintf_87);
  tcase_add_test(ts_core, sprintf_88);
  tcase_add_test(ts_core, sprintf_89);
  tcase_add_test(ts_core, sprintf_90);
  tcase_add_test(ts_core, sprintf_91);
  tcase_add_test(ts_core, sprintf_92);
  tcase_add_test(ts_core, sprintf_93);
  tcase_add_test(ts_core, sprintf_94);
  tcase_add_test(ts_core, sprintf_95);
  tcase_add_test(ts_core, sprintf_96);
  tcase_add_test(ts_core, sprintf_97);
  tcase_add_test(ts_core, sprintf_98);
  tcase_add_test(ts_core, sprintf_99);
  tcase_add_test(ts_core, sprintf_100);
  tcase_add_test(ts_core, sprintf_101);
  tcase_add_test(ts_core, sprintf_102);
  tcase_add_test(ts_core, sprintf_103);
  tcase_add_test(ts_core, sprintf_104);
  tcase_add_test(ts_core, sprintf_105);
  tcase_add_test(ts_core, sprintf_106);
  tcase_add_test(ts_core, sprintf_107);
  tcase_add_test(ts_core, sprintf_108);
  tcase_add_test(ts_core, sprintf_109);
  tcase_add_test(ts_core, sprintf_110);
  tcase_add_test(ts_core, sprintf_111);
  tcase_add_test(ts_core, sprintf_112);
  tcase_add_test(ts_core, sprintf_113);
  tcase_add_test(ts_core, sprintf_114);
  tcase_add_test(ts_core, sprintf_115);
  tcase_add_test(ts_core, sprintf_116);
  tcase_add_test(ts_core, sprintf_117);
  tcase_add_test(ts_core, sprintf_118);
  tcase_add_test(ts_core, sprintf_119);
  tcase_add_test(ts_core, sprintf_120);
  tcase_add_test(ts_core, sprintf_121);
  tcase_add_test(ts_core, sprintf_122);
  tcase_add_test(ts_core, sprintf_123);
  tcase_add_test(ts_core, sprintf_124);
  tcase_add_test(ts_core, sprintf_125);
  tcase_add_test(ts_core, sprintf_126);
  tcase_add_test(ts_core, sprintf_127);
  tcase_add_test(ts_core, sprintf_128);
  tcase_add_test(ts_core, sprintf_129);
  tcase_add_test(ts_core, sprintf_130);
  tcase_add_test(ts_core, sprintf_131);
  tcase_add_test(ts_core, sprintf_132);
  tcase_add_test(ts_core, sprintf_133);
  tcase_add_test(ts_core, sprintf_134);
  tcase_add_test(ts_core, sprintf_135);
  tcase_add_test(ts_core, sprintf_136);
  tcase_add_test(ts_core, sprintf_137);
  tcase_add_test(ts_core, sprintf_138);
  tcase_add_test(ts_core, sprintf_139);
  tcase_add_test(ts_core, sprintf_140);
  tcase_add_test(ts_core, sprintf_141);
  tcase_add_test(ts_core, sprintf_142);
  tcase_add_test(ts_core, sprintf_143);
  tcase_add_test(ts_core, sprintf_144);
  tcase_add_test(ts_core, sprintf_145);
  tcase_add_test(ts_core, sprintf_146);
  tcase_add_test(ts_core, sprintf_147);
  tcase_add_test(ts_core, sprintf_148);
  tcase_add_test(ts_core, sprintf_149);
  tcase_add_test(ts_core, sprintf_150);
  tcase_add_test(ts_core, sprintf_151);
  tcase_add_test(ts_core, sprintf_152);
  tcase_add_test(ts_core, sprintf_153);
  tcase_add_test(ts_core, sprintf_154);
  tcase_add_test(ts_core, sprintf_155);
  tcase_add_test(ts_core, sprintf_156);
  tcase_add_test(ts_core, sprintf_157);
  tcase_add_test(ts_core, sprintf_158);
  tcase_add_test(ts_core, sprintf_159);
  tcase_add_test(ts_core, sprintf_160);
  tcase_add_test(ts_core, sprintf_161);
  tcase_add_test(ts_core, sprintf_162);
  tcase_add_test(ts_core, sprintf_163);
  tcase_add_test(ts_core, sprintf_164);
  tcase_add_test(ts_core, sprintf_165);
  tcase_add_test(ts_core, sprintf_166);
  tcase_add_test(ts_core, sprintf_167);
  tcase_add_test(ts_core, sprintf_168);
  tcase_add_test(ts_core, sprintf_169);
  tcase_add_test(ts_core, sprintf_170);
  tcase_add_test(ts_core, sprintf_171);
  tcase_add_test(ts_core, sprintf_172);
  tcase_add_test(ts_core, sprintf_173);
  tcase_add_test(ts_core, sprintf_174);
  tcase_add_test(ts_core, sprintf_175);
  tcase_add_test(ts_core, sprintf_176);
  tcase_add_test(ts_core, sprintf_177);
  tcase_add_test(ts_core, sprintf_178);
  tcase_add_test(ts_core, sprintf_179);
  tcase_add_test(ts_core, sprintf_180);
  tcase_add_test(ts_core, sprintf_181);
  tcase_add_test(ts_core, sprintf_182);
  tcase_add_test(ts_core, sprintf_183);
  tcase_add_test(ts_core, sprintf_184);
  tcase_add_test(ts_core, sprintf_185);
  tcase_add_test(ts_core, sprintf_186);
  tcase_add_test(ts_core, sprintf_187);
  tcase_add_test(ts_core, sprintf_188);
  tcase_add_test(ts_core, sprintf_189);
  tcase_add_test(ts_core, sprintf_190);
  tcase_add_test(ts_core, sprintf_191);
  tcase_add_test(ts_core, sprintf_192);
  tcase_add_test(ts_core, sprintf_193);
  tcase_add_test(ts_core, sprintf_194);
  tcase_add_test(ts_core, sprintf_195);
  tcase_add_test(ts_core, sprintf_196);
  tcase_add_test(ts_core, sprintf_197);
  tcase_add_test(ts_core, sprintf_198);
  tcase_add_test(ts_core, sprintf_199);
  tcase_add_test(ts_core, sprintf_200);
  tcase_add_test(ts_core, sprintf_201);
  tcase_add_test(ts_core, sprintf_202);
  tcase_add_test(ts_core, sprintf_203);
  tcase_add_test(ts_core, sprintf_204);
  tcase_add_test(ts_core, sprintf_205);
  tcase_add_test(ts_core, sprintf_206);
  tcase_add_test(ts_core, sprintf_207);
  tcase_add_test(ts_core, sprintf_208);
  tcase_add_test(ts_core, sprintf_209);
  tcase_add_test(ts_core, sprintf_210);
  tcase_add_test(ts_core, sprintf_211);
  tcase_add_test(ts_core, sprintf_212);
  tcase_add_test(ts_core, sprintf_213);
  tcase_add_test(ts_core, sprintf_214);
  tcase_add_test(ts_core, sprintf_215);
  tcase_add_test(ts_core, sprintf_216);
  tcase_add_test(ts_core, sprintf_217);
  tcase_add_test(ts_core, sprintf_218);
  tcase_add_test(ts_core, sprintf_219);
  tcase_add_test(ts_core, sprintf_220);
  tcase_add_test(ts_core, sprintf_221);
  tcase_add_test(ts_core, sprintf_222);
  tcase_add_test(ts_core, sprintf_223);
  tcase_add_test(ts_core, sprintf_224);
  tcase_add_test(ts_core, sprintf_225);
  tcase_add_test(ts_core, sprintf_226);
  tcase_add_test(ts_core, sprintf_227);
  tcase_add_test(ts_core, sprintf_228);
  tcase_add_test(ts_core, sprintf_229);
  tcase_add_test(ts_core, sprintf_230);
  tcase_add_test(ts_core, sprintf_231);
  tcase_add_test(ts_core, sprintf_232);
  tcase_add_test(ts_core, sprintf_233);
  tcase_add_test(ts_core, sprintf_234);
  tcase_add_test(ts_core, sprintf_235);
  tcase_add_test(ts_core, sprintf_236);
  tcase_add_test(ts_core, sprintf_237);
  tcase_add_test(ts_core, sprintf_238);
  tcase_add_test(ts_core, sprintf_239);
  tcase_add_test(ts_core, sprintf_240);
  tcase_add_test(ts_core, sprintf_241);
  tcase_add_test(ts_core, sprintf_242);
  tcase_add_test(ts_core, sprintf_243);
  tcase_add_test(ts_core, sprintf_244);
  tcase_add_test(ts_core, sprintf_245);
  tcase_add_test(ts_core, sprintf_246);
  tcase_add_test(ts_core, sprintf_247);
  tcase_add_test(ts_core, sprintf_248);
  tcase_add_test(ts_core, sprintf_249);
  tcase_add_test(ts_core, sprintf_250);
  tcase_add_test(ts_core, sprintf_251);
  tcase_add_test(ts_core, sprintf_252);
  tcase_add_test(ts_core, sprintf_253);
  tcase_add_test(ts_core, sprintf_254);
  tcase_add_test(ts_core, sprintf_255);
  tcase_add_test(ts_core, sprintf_256);
  tcase_add_test(ts_core, sprintf_257);
  tcase_add_test(ts_core, sprintf_258);
  tcase_add_test(ts_core, sprintf_259);
  tcase_add_test(ts_core, sprintf_260);
  tcase_add_test(ts_core, sprintf_261);
  tcase_add_test(ts_core, sprintf_262);
  tcase_add_test(ts_core, sprintf_263);
  tcase_add_test(ts_core, sprintf_264);
  tcase_add_test(ts_core, sprintf_265);
  // tcase_add_test(ts_core, sprintf_266);
  tcase_add_test(ts_core, sprintf_267);
  tcase_add_test(ts_core, sprintf_268);
  tcase_add_test(ts_core, sprintf_269);
  tcase_add_test(ts_core, sprintf_270);
  tcase_add_test(ts_core, sprintf_271);
  tcase_add_test(ts_core, sprintf_272);
  tcase_add_test(ts_core, sprintf_273);
  tcase_add_test(ts_core, sprintf_274);
  tcase_add_test(ts_core, sprintf_275);
  tcase_add_test(ts_core, sprintf_276);
  tcase_add_test(ts_core, sprintf_277);
  tcase_add_test(ts_core, sprintf_278);
  tcase_add_test(ts_core, sprintf_279);
  tcase_add_test(ts_core, sprintf_280);
  tcase_add_test(ts_core, sprintf_281);
  tcase_add_test(ts_core, sprintf_282);
  tcase_add_test(ts_core, sprintf_283);
  tcase_add_test(ts_core, sprintf_284);
  tcase_add_test(ts_core, sprintf_285);
  tcase_add_test(ts_core, sprintf_286);
  tcase_add_test(ts_core, sprintf_287);
  tcase_add_test(ts_core, sprintf_288);
  tcase_add_test(ts_core, sprintf_289);
  tcase_add_test(ts_core, sprintf_290);
  tcase_add_test(ts_core, sprintf_291);
  tcase_add_test(ts_core, sprintf_292);
  tcase_add_test(ts_core, sprintf_293);
  tcase_add_test(ts_core, sprintf_294);
  tcase_add_test(ts_core, sprintf_295);
  tcase_add_test(ts_core, sprintf_296);
  tcase_add_test(ts_core, sprintf_297);
  tcase_add_test(ts_core, sprintf_298);
  tcase_add_test(ts_core, sprintf_299);
  tcase_add_test(ts_core, sprintf_300);
  tcase_add_test(ts_core, sprintf_301);
  tcase_add_test(ts_core, sprintf_302);
  tcase_add_test(ts_core, sprintf_303);
  tcase_add_test(ts_core, sprintf_304);
  tcase_add_test(ts_core, sprintf_305);
  tcase_add_test(ts_core, sprintf_306);
  tcase_add_test(ts_core, sprintf_307);
  tcase_add_test(ts_core, sprintf_308);
  tcase_add_test(ts_core, sprintf_309);
  tcase_add_test(ts_core, sprintf_310);
  tcase_add_test(ts_core, sprintf_311);
  tcase_add_test(ts_core, sprintf_312);
  tcase_add_test(ts_core, sprintf_313);
  tcase_add_test(ts_core, sprintf_314);
  tcase_add_test(ts_core, sprintf_315);
  tcase_add_test(ts_core, sprintf_316);
  tcase_add_test(ts_core, sprintf_317);
  tcase_add_test(ts_core, sprintf_318);
  tcase_add_test(ts_core, sprintf_319);
  tcase_add_test(ts_core, sprintf_320);
  tcase_add_test(ts_core, sprintf_321);
  tcase_add_test(ts_core, sprintf_322);
  tcase_add_test(ts_core, sprintf_323);
  tcase_add_test(ts_core, sprintf_324);
  tcase_add_test(ts_core, sprintf_325);
  tcase_add_test(ts_core, sprintf_326);
  tcase_add_test(ts_core, sprintf_327);
  tcase_add_test(ts_core, sprintf_328);
  tcase_add_test(ts_core, sprintf_329);
  tcase_add_test(ts_core, sprintf_330);
  tcase_add_test(ts_core, sprintf_331);
  tcase_add_test(ts_core, sprintf_332);
  tcase_add_test(ts_core, sprintf_333);
  tcase_add_test(ts_core, sprintf_334);
  tcase_add_test(ts_core, sprintf_335);
  tcase_add_test(ts_core, sprintf_336);
  tcase_add_test(ts_core, sprintf_337);
  tcase_add_test(ts_core, sprintf_338);
  tcase_add_test(ts_core, sprintf_339);
  tcase_add_test(ts_core, sprintf_340);
  tcase_add_test(ts_core, sprintf_341);
  tcase_add_test(ts_core, sprintf_342);
  tcase_add_test(ts_core, sprintf_343);
  tcase_add_test(ts_core, sprintf_344);
  tcase_add_test(ts_core, sprintf_345);
  tcase_add_test(ts_core, sprintf_346);
  tcase_add_test(ts_core, sprintf_347);
  tcase_add_test(ts_core, sprintf_348);
  tcase_add_test(ts_core, sprintf_349);
  tcase_add_test(ts_core, sprintf_350);
  tcase_add_test(ts_core, sprintf_351);
  tcase_add_test(ts_core, sprintf_352);
  tcase_add_test(ts_core, sprintf_353);
  tcase_add_test(ts_core, sprintf_354);
  tcase_add_test(ts_core, sprintf_355);
  tcase_add_test(ts_core, sprintf_356);
  tcase_add_test(ts_core, sprintf_357);
  tcase_add_test(ts_core, sprintf_358);
  tcase_add_test(ts_core, sprintf_359);
  tcase_add_test(ts_core, sprintf_360);
  tcase_add_test(ts_core, sprintf_361);
  tcase_add_test(ts_core, sprintf_362);
  tcase_add_test(ts_core, sprintf_363);
  tcase_add_test(ts_core, sprintf_364);
  tcase_add_test(ts_core, sprintf_365);
  tcase_add_test(ts_core, sprintf_366);
  tcase_add_test(ts_core, sprintf_367);
  tcase_add_test(ts_core, sprintf_368);
  tcase_add_test(ts_core, sprintf_369);
  tcase_add_test(ts_core, sprintf_370);
  tcase_add_test(ts_core, sprintf_371);
  tcase_add_test(ts_core, sprintf_372);
  tcase_add_test(ts_core, sprintf_373);
  tcase_add_test(ts_core, sprintf_374);
  tcase_add_test(ts_core, sprintf_375);
  tcase_add_test(ts_core, sprintf_376);
  tcase_add_test(ts_core, sprintf_377);
  tcase_add_test(ts_core, sprintf_378);
  tcase_add_test(ts_core, sprintf_379);
  tcase_add_test(ts_core, sprintf_380);
  tcase_add_test(ts_core, sprintf_381);
  tcase_add_test(ts_core, sprintf_382);
  tcase_add_test(ts_core, sprintf_383);
  tcase_add_test(ts_core, sprintf_384);
  tcase_add_test(ts_core, sprintf_385);
  tcase_add_test(ts_core, sprintf_386);
  tcase_add_test(ts_core, sprintf_387);
  tcase_add_test(ts_core, sprintf_388);
  tcase_add_test(ts_core, sprintf_389);
  tcase_add_test(ts_core, sprintf_390);
  tcase_add_test(ts_core, sprintf_391);
  tcase_add_test(ts_core, sprintf_392);
  tcase_add_test(ts_core, sprintf_393);
  tcase_add_test(ts_core, sprintf_394);
  tcase_add_test(ts_core, sprintf_395);
  tcase_add_test(ts_core, sprintf_396);
  tcase_add_test(ts_core, sprintf_397);
  tcase_add_test(ts_core, sprintf_398);
  tcase_add_test(ts_core, sprintf_399);
  tcase_add_test(ts_core, sprintf_400);
  tcase_add_test(ts_core, sprintf_401);
  tcase_add_test(ts_core, sprintf_402);
  tcase_add_test(ts_core, sprintf_403);
  tcase_add_test(ts_core, sprintf_404);
  tcase_add_test(ts_core, sprintf_405);
  tcase_add_test(ts_core, sprintf_406);
  tcase_add_test(ts_core, sprintf_407);
  tcase_add_test(ts_core, sprintf_408);
  tcase_add_test(ts_core, sprintf_409);
  tcase_add_test(ts_core, sprintf_410);
  tcase_add_test(ts_core, sprintf_411);
  tcase_add_test(ts_core, sprintf_412);
  tcase_add_test(ts_core, sprintf_413);
  tcase_add_test(ts_core, sprintf_414);
  tcase_add_test(ts_core, sprintf_415);
  tcase_add_test(ts_core, sprintf_416);
  tcase_add_test(ts_core, sprintf_417);
  tcase_add_test(ts_core, sprintf_418);
  tcase_add_test(ts_core, sprintf_419);
  tcase_add_test(ts_core, sprintf_420);
  tcase_add_test(ts_core, sprintf_421);
  tcase_add_test(ts_core, sprintf_422);
  tcase_add_test(ts_core, sprintf_423);
  tcase_add_test(ts_core, sprintf_424);
  tcase_add_test(ts_core, sprintf_425);
  tcase_add_test(ts_core, sprintf_426);
  tcase_add_test(ts_core, sprintf_427);
  tcase_add_test(ts_core, sprintf_428);
  tcase_add_test(ts_core, sprintf_429);
  tcase_add_test(ts_core, sprintf_430);
  tcase_add_test(ts_core, sprintf_431);
  tcase_add_test(ts_core, sprintf_432);
  tcase_add_test(ts_core, sprintf_433);
  tcase_add_test(ts_core, sprintf_434);
  tcase_add_test(ts_core, sprintf_435);
  tcase_add_test(ts_core, sprintf_436);
  tcase_add_test(ts_core, sprintf_437);
  tcase_add_test(ts_core, sprintf_438);
  tcase_add_test(ts_core, sprintf_439);
  tcase_add_test(ts_core, sprintf_440);
  tcase_add_test(ts_core, sprintf_441);
  tcase_add_test(ts_core, sprintf_442);
  tcase_add_test(ts_core, sprintf_443);
  tcase_add_test(ts_core, sprintf_444);
  tcase_add_test(ts_core, sprintf_445);
  tcase_add_test(ts_core, sprintf_446);
  tcase_add_test(ts_core, sprintf_447);
  tcase_add_test(ts_core, sprintf_448);
  tcase_add_test(ts_core, sprintf_449);
  tcase_add_test(ts_core, sprintf_450);
  tcase_add_test(ts_core, sprintf_451);
  tcase_add_test(ts_core, sprintf_452);
  tcase_add_test(ts_core, sprintf_453);
  tcase_add_test(ts_core, sprintf_454);
  tcase_add_test(ts_core, sprintf_455);
  tcase_add_test(ts_core, sprintf_456);
  tcase_add_test(ts_core, sprintf_457);
  tcase_add_test(ts_core, sprintf_458);
  tcase_add_test(ts_core, sprintf_459);
  tcase_add_test(ts_core, sprintf_460);
  tcase_add_test(ts_core, sprintf_461);
  tcase_add_test(ts_core, sprintf_462);
  tcase_add_test(ts_core, sprintf_463);
  tcase_add_test(ts_core, sprintf_464);
  tcase_add_test(ts_core, sprintf_465);
  tcase_add_test(ts_core, sprintf_466);
  tcase_add_test(ts_core, sprintf_467);
  tcase_add_test(ts_core, sprintf_468);
  tcase_add_test(ts_core, sprintf_469);
  tcase_add_test(ts_core, sprintf_470);
  tcase_add_test(ts_core, sprintf_471);
  tcase_add_test(ts_core, sprintf_472);
  tcase_add_test(ts_core, sprintf_473);
  tcase_add_test(ts_core, sprintf_474);
  tcase_add_test(ts_core, sprintf_475);
  tcase_add_test(ts_core, sprintf_476);
  tcase_add_test(ts_core, sprintf_477);
  tcase_add_test(ts_core, sprintf_478);
  tcase_add_test(ts_core, sprintf_479);
  tcase_add_test(ts_core, sprintf_480);
  tcase_add_test(ts_core, sprintf_481);
  tcase_add_test(ts_core, sprintf_482);
  tcase_add_test(ts_core, sprintf_483);
  tcase_add_test(ts_core, sprintf_484);
  tcase_add_test(ts_core, sprintf_485);
  tcase_add_test(ts_core, sprintf_486);
  tcase_add_test(ts_core, sprintf_487);
  tcase_add_test(ts_core, sprintf_488);
  tcase_add_test(ts_core, sprintf_489);
  tcase_add_test(ts_core, sprintf_490);
  tcase_add_test(ts_core, sprintf_491);
  tcase_add_test(ts_core, sprintf_492);
  tcase_add_test(ts_core, sprintf_493);
  tcase_add_test(ts_core, sprintf_494);
  tcase_add_test(ts_core, sprintf_495);
  tcase_add_test(ts_core, sprintf_496);
  tcase_add_test(ts_core, sprintf_497);
  tcase_add_test(ts_core, sprintf_498);
  tcase_add_test(ts_core, sprintf_499);
  tcase_add_test(ts_core, sprintf_500);
  tcase_add_test(ts_core, sprintf_501);
  tcase_add_test(ts_core, sprintf_502);
  tcase_add_test(ts_core, sprintf_503);
  tcase_add_test(ts_core, sprintf_504);
  tcase_add_test(ts_core, sprintf_505);
  tcase_add_test(ts_core, sprintf_506);
  tcase_add_test(ts_core, sprintf_507);
  tcase_add_test(ts_core, sprintf_508);
  tcase_add_test(ts_core, sprintf_509);
  tcase_add_test(ts_core, sprintf_510);
  tcase_add_test(ts_core, sprintf_511);
  tcase_add_test(ts_core, sprintf_512);
  tcase_add_test(ts_core, sprintf_513);
  tcase_add_test(ts_core, sprintf_514);
  tcase_add_test(ts_core, sprintf_515);
  tcase_add_test(ts_core, sprintf_516);
  tcase_add_test(ts_core, sprintf_517);
  tcase_add_test(ts_core, sprintf_518);
  tcase_add_test(ts_core, sprintf_519);
  tcase_add_test(ts_core, sprintf_520);
  tcase_add_test(ts_core, sprintf_521);
  tcase_add_test(ts_core, sprintf_522);
  tcase_add_test(ts_core, sprintf_523);
  tcase_add_test(ts_core, sprintf_524);
  tcase_add_test(ts_core, sprintf_525);
  tcase_add_test(ts_core, sprintf_526);
  tcase_add_test(ts_core, sprintf_527);
  tcase_add_test(ts_core, sprintf_528);
  tcase_add_test(ts_core, sprintf_529);
  tcase_add_test(ts_core, sprintf_530);
  tcase_add_test(ts_core, sprintf_531);
  tcase_add_test(ts_core, sprintf_532);
  tcase_add_test(ts_core, sprintf_533);
  tcase_add_test(ts_core, sprintf_534);
  tcase_add_test(ts_core, sprintf_535);
  tcase_add_test(ts_core, sprintf_536);
  tcase_add_test(ts_core, sprintf_537);
  tcase_add_test(ts_core, sprintf_538);
  tcase_add_test(ts_core, sprintf_539);
  suite_add_tcase(s, ts_core);
  return s;
}
