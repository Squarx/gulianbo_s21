#include "test.h"

START_TEST(sprintf_0) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %u leh";
  unsigned int q = 333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_1) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %u leh";
  unsigned int q = -333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_2) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %u leh";
  unsigned int q = 0;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_3) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %u leh";
  unsigned int q = 33.33333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_4) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %u leh";
  unsigned int q = 33.33333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
//============================
START_TEST(sprintf_5) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %3u leh";
  unsigned int q = 333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_6) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %3u leh";
  unsigned int q = -333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_7) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %4u leh";
  unsigned int q = 333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_8) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %4u leh";
  unsigned int q = -333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_9) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %2u leh";
  unsigned int q = 333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_10) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %2u leh";
  unsigned int q = -333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_11) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %8u leh";
  unsigned int q = 333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_12) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %8u leh";
  unsigned int q = -333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_13) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %0u leh";
  unsigned int q = -333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
//============================
START_TEST(sprintf_14) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %.3u leh";
  unsigned int q = 333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_15) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %.3u leh";
  unsigned int q = -333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_16) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %.4u leh";
  unsigned int q = 333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_17) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %.4u leh";
  unsigned int q = -333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_18) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %.2u leh";
  unsigned int q = 333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_19) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %.2u leh";
  unsigned int q = -333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_20) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %.8u leh";
  unsigned int q = 333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_21) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %.8u leh";
  unsigned int q = -333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_22) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %.0u leh";
  unsigned int q = -333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
//==================================
START_TEST(sprintf_23) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-3u leh";
  unsigned int q = 333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_24) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-3u leh";
  unsigned int q = -333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_25) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-4u leh";
  unsigned int q = 333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_26) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-4u leh";
  unsigned int q = -333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_27) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-2u leh";
  unsigned int q = 333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_28) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-2u leh";
  unsigned int q = -333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_29) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-8u leh";
  unsigned int q = 333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_30) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-8u leh";
  unsigned int q = -333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_31) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-0u leh";
  unsigned int q = -333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
//============================
START_TEST(sprintf_32) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-.3u leh";
  unsigned int q = 333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_33) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-.3u leh";
  unsigned int q = -333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_34) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-.4u leh";
  unsigned int q = 333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_35) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-.4u leh";
  unsigned int q = -333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_36) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-.2u leh";
  unsigned int q = 333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_37) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-.2u leh";
  unsigned int q = -333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_38) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-.8u leh";
  unsigned int q = 333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_39) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-.8u leh";
  unsigned int q = -333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_40) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-.0u leh";
  unsigned int q = -333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
//============================
START_TEST(sprintf_41) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-u leh";
  unsigned int q = 333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_42) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-u leh";
  unsigned int q = -333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_43) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-u leh";
  unsigned int q = 0;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_44) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-u leh";
  unsigned int q = 33.333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_45) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-u leh";
  unsigned int q = 33.3333333333333333333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
//=============================
START_TEST(sprintf_46) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %5.5u leh";
  unsigned int q = 333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_47) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %5.5u leh";
  unsigned int q = -333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_48) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %4.5u leh";
  unsigned int q = 333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_49) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %4.5u leh";
  unsigned int q = -333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_50) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %5.4u leh";
  unsigned int q = 333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_51) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %5.4u leh";
  unsigned int q = -333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_52) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %5.5u leh";
  unsigned int q = 3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_53) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %5.5u leh";
  unsigned int q = -3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_54) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %4.5u leh";
  unsigned int q = 3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_55) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %4.5u leh";
  unsigned int q = -3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_56) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %5.4u leh";
  unsigned int q = 3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_57) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %5.4u leh";
  unsigned int q = -3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_58) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %4.4u leh";
  unsigned int q = 3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_59) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %4.4u leh";
  unsigned int q = -3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_60) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %4.3u leh";
  unsigned int q = 3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_61) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %4.3u leh";
  unsigned int q = -3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_61_1) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %3.4u leh";
  unsigned int q = 3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_61_2) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %3.4u leh";
  unsigned int q = -3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_61_3) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %4.4u leh";
  unsigned int q = 33333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_62) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %4.4u leh";
  unsigned int q = -33333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_63) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %5.4u leh";
  unsigned int q = 33333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_64) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %5.4u leh";
  unsigned int q = -33333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_65) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %4.5u leh";
  unsigned int q = 33333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_66) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %4.5u leh";
  unsigned int q = -33333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_67) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %4.4u leh";
  unsigned int q = 333333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_68) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %4.4u leh";
  unsigned int q = -333333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_69) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %5.4u leh";
  unsigned int q = 333333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_70) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %5.4u leh";
  unsigned int q = -333333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_71) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %4.5u leh";
  unsigned int q = 333333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_72) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %4.5u leh";
  unsigned int q = -333333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
//=============================
START_TEST(sprintf_73) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-5.5u leh";
  unsigned int q = 333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_74) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-5.5u leh";
  unsigned int q = -333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_75) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-4.5u leh";
  unsigned int q = 333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_76) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-4.5u leh";
  unsigned int q = -333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_77) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-5.4u leh";
  unsigned int q = 333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_78) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-5.4u leh";
  unsigned int q = -333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_79) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-5.5u leh";
  unsigned int q = 3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_80) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-5.5u leh";
  unsigned int q = -3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_81) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-4.5u leh";
  unsigned int q = 3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_82) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-4.5u leh";
  unsigned int q = -3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_83) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-5.4u leh";
  unsigned int q = 3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_84) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-5.4u leh";
  unsigned int q = -3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_85) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-4.4u leh";
  unsigned int q = 3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_86) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-4.4u leh";
  unsigned int q = -3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_87) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-4.3u leh";
  unsigned int q = 3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_88) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-4.3u leh";
  unsigned int q = -3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_89) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-3.4u leh";
  unsigned int q = 3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_90) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-3.4u leh";
  unsigned int q = -3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_91) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-4.4u leh";
  unsigned int q = 33333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_92) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-4.4u leh";
  unsigned int q = -33333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_93) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-5.4u leh";
  unsigned int q = 33333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_94) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-5.4u leh";
  unsigned int q = -33333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_95) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-4.5u leh";
  unsigned int q = 33333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_96) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-4.5u leh";
  unsigned int q = -33333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_97) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-4.4u leh";
  unsigned int q = 333333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_98) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-4.4u leh";
  unsigned int q = -333333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_99) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-5.4u leh";
  unsigned int q = 333333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_100) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-5.4u leh";
  unsigned int q = -333333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_101) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-4.5u leh";
  unsigned int q = 333333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_102) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %-4.5u leh";
  unsigned int q = -333333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
//===========================
START_TEST(sprintf_103) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %hu leh";
  unsigned int q = 333333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_104) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %hu leh";
  unsigned int q = 0;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_105) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %hu leh";
  unsigned int q = -333333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_106) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %hu leh";
  unsigned int q = 333333.3333333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_107) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %hu leh";
  unsigned short int q = 33333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_108) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %hu leh";
  unsigned short int q = 0;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_109) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %hu leh";
  unsigned short int q = -3333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_110) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %hu leh";
  unsigned short int q = 33333.3333333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_111) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %hu leh";
  unsigned long int q = 333333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_112) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %hu leh";
  unsigned long int q = 0;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_113) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %hu leh";
  unsigned long int q = -333333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_114) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %hu leh";
  unsigned long int q = 333333.3333333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
//======================================
START_TEST(sprintf_115) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %lu leh";
  unsigned long int q = 333333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_116) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %lu leh";
  unsigned long int q = -333333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_117) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %lu leh";
  unsigned long int q = 3333333333333333333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_118) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %lu leh";
  unsigned long int q = -3333333333333333333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_119) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %lu leh";
  unsigned long int q = 0;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST
START_TEST(sprintf_120) {
  char test_str[100] = {0};
  char test_str_1[100] = {0};
  char parameters[] = "leh %lu leh";
  unsigned long int q = 3333333333333333333.3333333333;
  ck_assert_int_eq(s21_sprintf(test_str, parameters, q),
                   sprintf(test_str_1, parameters, q));
  ck_assert_str_eq(test_str, test_str_1);
}
END_TEST

Suite *s21_sprintf_u_suite(void) {
  Suite *s;
  TCase *ts_core;
  s = suite_create("s21_sprintf_u");  //создает набор кейсов с заданным именем
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
  tcase_add_test(ts_core, sprintf_49);
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
  tcase_add_test(ts_core, sprintf_61_1);
  tcase_add_test(ts_core, sprintf_61_2);
  tcase_add_test(ts_core, sprintf_61_3);
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
  suite_add_tcase(s, ts_core);
  return s;
}