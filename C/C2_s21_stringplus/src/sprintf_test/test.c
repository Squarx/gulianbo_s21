//
// Created by Gulian Boris on 12/15/22.
//
#include "test.h"

int main(void) {
  Suite *s;
  Suite *b;
  Suite *c;
  Suite *str;
  Suite *u;
  Suite *orig;
  Suite *nyar;

  //
  SRunner *runner_s;
  SRunner *runner_b;
  SRunner *runner_c;
  SRunner *runner_str;
  SRunner *runner_u;
  SRunner *runner_orig;
  SRunner *runner_nyar;

  //
  s = test_g();
  b = s21_sprintf_f_suite();
  c = s21_sprintf_c_suite();
  str = s21_sprintf_s_suite();
  u = s21_sprintf_u_suite();
  orig = test_orig();
  nyar = s21_sprintf_nyar_suite();

  //
  runner_s = srunner_create(s);
  runner_b = srunner_create(b);
  runner_c = srunner_create(c);
  runner_str = srunner_create(str);
  runner_u = srunner_create(u);
  runner_orig = srunner_create(orig);
  runner_nyar = srunner_create(nyar);

  //
  printf("here MY test \n");
  srunner_run_all(runner_s, CK_NORMAL);
  printf("here  test F \n");
  srunner_run_all(runner_b, CK_NORMAL);
  printf("here  test C \n");
  srunner_run_all(runner_c, CK_NORMAL);
  printf("here  test S \n");
  srunner_run_all(runner_str, CK_NORMAL);
  printf("here  test U \n");
  srunner_run_all(runner_u, CK_NORMAL);
  printf("orig\n");
  srunner_run_all(runner_orig, CK_NORMAL);
  printf("Kris\n");
  srunner_run_all(runner_nyar, CK_NORMAL);

  //
  srunner_free(runner_s);
  srunner_free(runner_b);
  srunner_free(runner_c);
  srunner_free(runner_str);
  srunner_free(runner_u);
  srunner_free(runner_orig);
  srunner_free(runner_nyar);

  return 0;
}

START_TEST(first) {
  int val1 = -123123123;
  short int val2 = -12312;
  long int val3 = 1231231231231231312;
  char str1[500] = {0};
  char str2[500] = {0};
  char *test1 = "|%+ -#100.20d| |%-0+ #200.12hd| |%ld|";
  //    void *p = 0x0;
  unsigned int n1 = 0, n2 = 0;
  int r1 = sprintf(str1, test1, val1, val2, val3);
  int r2 = s21_sprintf(str2, test1, val1, val2, val3);

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_d) {
  char str1[1000] = {0};
  char str2[1000] = {0};
  short h = 34;
  char *format =
      "%0+-#25.40d%-  +30.2d%10.12d%11d%*d%*.*d%+-25.*d%+10.2ld%-11.*hd";
  int r1 = sprintf(str1, format, 253, 335, 1234, 34, 10, 25, 5, 15, 345, 5, 666,
                   456789l, 5, h);
  int r2 = s21_sprintf(str2, format, 253, 335, 1234, 34, 10, 25, 5, 15, 345, 5,
                       666, 456789l, 5, h);

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_i) {
  char str1[1000] = {0};
  char str2[1000] = {0};
  short h = 34;
  long l = 2353423523424;
  int r1 = sprintf(str1, "%+50.i%-10.20i%10.i%012i%*.*i%-10.*i%+10.1li%*.25hi",
                   34567, 225, 5230, 125, 10, 5, 456, 10, 377, l, 12, h);
  int r2 =
      s21_sprintf(str2, "%+50.i%-10.20i%10.i%012i%*.*i%-10.*i%+10.1li%*.25hi",
                  34567, 225, 5230, 125, 10, 5, 456, 10, 377, l, 12, h);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_chars_f) {
  char orig[256] = {0};
  char my[256] = {0};
  char *format = "%000   +# -0#16.100c";
  char test1 = 'V';
  s21_sprintf(my, format, test1);
  sprintf(orig, format, test1);

  ck_assert_str_eq(orig, my);
}
END_TEST

START_TEST(main_my) {
  char orig[256] = {0};
  char my[256] = {0};
  char *format = "%+- #200.18Le";
  long double test1 = 12123123123 * 1e-100;
  s21_sprintf(my, format, test1);
  sprintf(orig, format, test1);

  ck_assert_str_eq(orig, my);
}
END_TEST

START_TEST(s21_sprintf_test_f) {
  char str1[1000] = {0};
  char str2[1000] = {0};
  int r1 = sprintf(
      str1, "%+-10.3f%+10.2f%15.10f%+*.6f%*.10f%-10.*f%25.*f%25.f%#+10.f%*.*f",
      2546.4324, 3452.4325, 5678.43256, 25, 456789.243242, 10, 3456789123.43245,
      2, 12345.6788, 1, 34.4325432, 4325678.43242, 34567.2345432, 10, 2,
      34567.43244);
  int r2 = s21_sprintf(
      str2, "%+-10.3f%+10.2f%15.10f%+*.6f%*.10f%-10.*f%25.*f%25.f%#+10.f%*.*f",
      2546.4324, 3452.4325, 5678.43256, 25, 456789.243242, 10, 3456789123.43245,
      2, 12345.6788, 1, 34.4325432, 4325678.43242, 34567.2345432, 10, 2,
      34567.43244);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_g) {
  char str1[1000] = {0};
  char str2[1000] = {0};
  int r1 = sprintf(
      str1, "%g%23g%-10g%015g%#10.5g%0#15.10g%+10.6g%#*.g%-10.*g%+#25.8g",
      2345.4324, 23445.2342, 1234.234242, 3456.3424, 0.00001234, -324234.234,
      2345.4234, 5, 23456.4324, 9, 234567.43242, 0.0000034);
  int r2 = s21_sprintf(
      str2, "%g%23g%-10g%015g%#10.5g%0#15.10g%+10.6g%#*.g%-10.*g%+#25.8g",
      2345.4324, 23445.2342, 1234.234242, 3456.3424, 0.00001234, -324234.234,
      2345.4234, 5, 23456.4324, 9, 234567.43242, 0.0000034);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(r1, r2);
}
END_TEST
//
START_TEST(s21_sprintf_test_G) {
  char str1[1000] = {0};
  char str2[1000] = {0};
  int r1 = sprintf(
      str1,
      "%G%25G%#-15G%017G%#05.2G%#010.16G%+#8.6G%*.8G%#-10.*G%+#12.16G%*.*G",
      43242.43242, 123432.43242, 0000.1234, -34252.43242, 1234.5,
      111.432534243243242, 4324.43242, 25, -3213.43242, 16, -43.43242353242342,
      111.24324242, 25, 5, 0.000000342);
  int r2 = s21_sprintf(
      str2,
      "%G%25G%#-15G%017G%#05.2G%#010.16G%+#8.6G%*.8G%#-10.*G%+#12.16G%*.*G",
      43242.43242, 123432.43242, 0000.1234, -34252.43242, 1234.5,
      111.432534243243242, 4324.43242, 25, -3213.43242, 16, -43.43242353242342,
      111.24324242, 25, 5, 0.000000342);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_o) {
  char str1[1000] = {0};
  char str2[1000] = {0};
  unsigned short h = 253;
  unsigned long l = 4325234324242l;
  int r1 =
      sprintf(str1, "%-25.10o%-10o%#-30.2o%#*.10o\n%#*.*o%25.*o%#.10ho%*lo",
              12345, 6532, 43522, 10, 64342, 15, 2, 343, 6, 678, h, 10, l);
  int r2 =
      s21_sprintf(str2, "%-25.10o%-10o%#-30.2o%#*.10o\n%#*.*o%25.*o%#.10ho%*lo",
                  12345, 6532, 43522, 10, 64342, 15, 2, 343, 6, 678, h, 10, l);

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_x) {
  char str1[1000] = {0};
  char str2[1000] = {0};
  unsigned short h = 345;
  unsigned long l = 52342353242l;
  int r1 = sprintf(str1,
                   "%x%-25x%#10x%#-10x%#10.5x%-25.34x%#-10.2x%*.*x%#*.10x%20.*"
                   "x%#10.*x%*.5hx%10.25lx",
                   235, 1234, 3456, 12345, 222234, 68432, 34567, 10, 15, 3452,
                   8, 23452, 10, 34254, 3, 33334, 10, h, l);
  int r2 = s21_sprintf(str2,
                       "%x%-25x%#10x%#-10x%#10.5x%-25.34x%#-10.2x%*.*x%#*.10x%"
                       "20.*x%#10.*x%*.5hx%10.25lx",
                       235, 1234, 3456, 12345, 222234, 68432, 34567, 10, 15,
                       3452, 8, 23452, 10, 34254, 3, 33334, 10, h, l);

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_X) {
  char str1[1000] = {0};
  char str2[1000] = {0};
  unsigned short h = 234;
  unsigned long l = 4325243132l;
  int r1 = sprintf(str1,
                   "%X%-10X%15X%#-15X%#20.3X%-30.12X%#-12.3X%*.*X%#*.15X%21.*X%"
                   "#12.*X%*.8hx%14.12lX",
                   235, 1234, 3456, 12345, 222234, 68432, 34567, 10, 15, 3452,
                   8, 23452, 10, 34254, 3, 33334, 10, h, l);
  int r2 = s21_sprintf(str2,
                       "%X%-10X%15X%#-15X%#20.3X%-30.12X%#-12.3X%*.*X%#*.15X%"
                       "21.*X%#12.*X%*.8hx%14.12lX",
                       235, 1234, 3456, 12345, 222234, 68432, 34567, 10, 15,
                       3452, 8, 23452, 10, 34254, 3, 33334, 10, h, l);

  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_p) {
  char str1[1000] = {0};
  char str2[1000] = {0};
  void *p1 = (void *)0x123456789;
  void *p2 = (void *)4325234;
  void *p3 = (void *)0x123f324b;
  void *p4 = (void *)432520;
  int r1 = sprintf(str1, "%p%20p%-15p%10p%-15p%*p%10p%*p", p1, p2, p3, p4, p2,
                   10, p3, p1, 10, p4);
  int r2 = s21_sprintf(str2, "%p%20p%-15p%10p%-15p%*p%10p%*p", p1, p2, p3, p4,
                       p2, 10, p3, p1, 10, p4);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_s) {
  char str1[1000] = {0};
  char str2[1000] = {0};
  int r1 = sprintf(str1, "%s%23s%-15s%10.s%15.2s%16.*s%*.*s%*s", "aboba",
                   "helloworld", "ABOBA", "ABOBBAAA", "AAABOBA", 10, "QWERTY",
                   15, 4, "AAAAABOOOOOBAAA", 10, "ABOBAAAAA");
  int r2 = s21_sprintf(str2, "%s%23s%-15s%10.s%15.2s%16.*s%*.*s%*s", "aboba",
                       "helloworld", "ABOBA", "ABOBBAAA", "AAABOBA", 10,
                       "QWERTY", 15, 4, "AAAAABOOOOOBAAA", 10, "ABOBAAAAA");
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_u) {
  char str1[1000] = {0};
  char str2[1000] = {0};
  unsigned short h = 115;
  unsigned long l = 123325242342l;
  int r1 =
      sprintf(str1, "%u%15u%-20u%010u%-15.10u%20.*u%*.*u%*.10u%-20.12lu%19hu",
              4321u, 34567u, 2342u, 12346u, 234542u, 10, 234523u, 10, 5, 2345u,
              20, 2432u, l, h);
  int r2 = s21_sprintf(
      str2, "%u%15u%-20u%010u%-15.10u%20.*u%*.*u%*.10u%-20.12lu%19hu", 4321u,
      34567u, 2342u, 12346u, 234542u, 10, 234523u, 10, 5, 2345u, 20, 2432u, l,
      h);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

// *******************************

START_TEST(sprintf_simple_int) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "This is a simple value %d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_precise_int) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%.5i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_width_int) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%5d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_minus_width_int) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%-5i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_plus_width_int) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%+12d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_padding_int) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%012i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_star_width_int) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%0*d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                   sprintf(str2, format, 5, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_star_precision_int) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%0.*i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                   sprintf(str2, format, 5, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_many_flags_many_ints) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char format[] = "%0.*i %d %4.*i %013d %d";
  int val = 69;
  ck_assert_int_eq(
      s21_sprintf(str1, format, 5, val, -10431, 13, 5311, 0, -581813581),
      sprintf(str2, format, 5, val, -10431, 13, 5311, 0, -581813581));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_flags_long_int) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%+5.31li";
  long int val = 698518581899;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_flags_short_int) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%-16.9hi";
  short int val = 6958;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_flags_another_long_int) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%0.*ld";
  long val = 8581385185;
  ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                   sprintf(str2, format, 5, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_zero_precision_zero_int) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%.0d";
  int val = 0;

  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_space_flag_int) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "% d";
  int val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_width) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%15u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_flags) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%-16u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_precision) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%.51u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_many_flags) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "% 5.51u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_short) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%hu";
  unsigned short int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_long) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%lu";
  unsigned long int val = 949149114140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_many) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%lu, %u, %hu, %.5u, %5.u";
  unsigned long int val = 949149114140;
  ck_assert_int_eq(
      s21_sprintf(str1, format, val, 14, 1441, 14414, 9681),
      sprintf(str2, format, val, (unsigned)14, (unsigned short)1441,
              (unsigned)14414, (unsigned)9681));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_width) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%15o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_flags) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%-16o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_precision) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%.51o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_many_flags) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%-5.51o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_zero) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%o";
  ck_assert_int_eq(s21_sprintf(str1, format, 0), sprintf(str2, format, 0));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_hash) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%#o";
  int val = 57175;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_short) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%hd";
  short int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_long) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%lo";
  long int val = 949149114140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_many) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%lo, %o, %ho, %.5o, %5.o";
  long int val = 949149114140;
  ck_assert_int_eq(
      s21_sprintf(str1, format, val, 14, 1441, 14414, 9681),
      sprintf(str2, format, val, (unsigned)14, (unsigned short)1441,
              (unsigned)14414, (unsigned)9681));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%lo";
  long int val = 84518;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_zero) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%u";
  ck_assert_int_eq(s21_sprintf(str1, format, 0),
                   sprintf(str2, format, (unsigned)0));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_width) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%5x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_flags) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%#-10x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_precision) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%.15x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_many) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%#-10x%x%X%#x%#X%5.5x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val, val, val, val, val, val),
                   sprintf(str2, format, val, val, val, val, val, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_many_flags) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%#-5.10x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_zero) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%#x";
  unsigned val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_huge) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%#x";
  unsigned val = 18571;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_short) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%#hx";
  unsigned short val = 12352;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_long) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%#lx";
  unsigned long val = 18571757371571;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_one_longer_width) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%#2x";
  unsigned val = 1;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_two_longer_width) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%#30x";
  unsigned val = 1;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_one_char) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%c";
  char val = 'X';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_one_precision) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%.5c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_one_flags) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "% -5c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_one_width) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%15c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_one_many) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%-5.3c%c%c%c%c Hello! ABOBA";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val, 'c', 'a', 'b', 'b'),
                   sprintf(str2, format, val, 'c', 'a', 'b', 'b'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_one_many_flags) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%-5.3c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%s";
  char *val = "I LOVE STRINGS AND TESTS AND SCHOOL21 NO JOKE";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string_precision) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%.15s";
  char *val = "I LOVE STRINGS AND TESTS AND SCHOOL21 NO JOKE";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string_width) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%15s";
  char *val = "69 IS MY FAVORITE NUMBER";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string_flags) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%-15.9s";
  char *val = "69 IS MY FAVORITE NUMBER";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string_long) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%s";
  char *val =
      "69 IS MY FAVORITE NUMBER THIS IS SUPPOSED TO BE A VERY LONG STRING";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string_many) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%s%s%s%s";
  char *val =
      "69 IS MY FAVORITE NUMBER THIS IS SUPPOSED TO BE A VERY LONG STRING";
  char *s1 = "";
  char *s2 = "87418347813748913749871389480913";
  char *s3 = "HAHAABOBASUCKER";
  ck_assert_int_eq(s21_sprintf(str1, format, val, s1, s2, s3),
                   sprintf(str2, format, val, s1, s2, s3));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_ptr) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%p";
  ck_assert_int_eq(s21_sprintf(str1, format, format),
                   sprintf(str2, format, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_ptr_width) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%15p";
  ck_assert_int_eq(s21_sprintf(str1, format, format),
                   sprintf(str2, format, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_ptr_precision) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%.5p";
  ck_assert_int_eq(s21_sprintf(str1, format, format),
                   sprintf(str2, format, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_null_ptr) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "%p";
  char *ptr = NULL;
  ck_assert_int_eq(s21_sprintf(str1, format, ptr), sprintf(str2, format, ptr));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string_width_huge) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char *val = "kjafdiuhfjahfjdahf";
  char *format = "%120s";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_n_specifier) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  int ret = 0;
  char *format = "Hello, my sexy little aboba abobushka abobina %n";
  ck_assert_int_eq(s21_sprintf(str1, format, &ret),
                   sprintf(str2, format, &ret));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_precision) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char *format = "%Lf";
  long double val = 513515.131513515151351;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_width) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char *format = "%10Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_precision_zero) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char *format = "%.0Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_precision_empty) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char *format = "%.Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_precision_huge) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char *format = "%.15Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_precision_huge_negative) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char *format = "%.15Lf";
  long double val = -15.35581134;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_huge) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char *format = "%Lf";
  long double val = 72537572375.1431341;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_flags) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char *format = "% f";
  float val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_many) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char *format = "% .0f %.lf %Lf %f %lf %Lf";
  float val = 0;
  double val1 = 0;
  long double val2 = 3515315.153151;
  float val3 = 5.5;
  double val4 = 9851.51351;
  long double val5 = 95919539159.53151351131;
  ck_assert_int_eq(s21_sprintf(str1, format, val, val1, val2, val3, val4, val5),
                   sprintf(str2, format, val, val1, val2, val3, val4, val5));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_precision) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char *format = "%.17Le";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_precision_zero) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char *format = "%.0Le";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_precision_empty) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char *format = "%.Le";
  long double val = 15.000009121;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_e_precision_huge) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char *format = "%.15Le";
  long double val = 0.000000000000000123;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_precision_huge_negative) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char *format = "%.15Le";
  long double val = -15.35581134;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_huge) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char *format = "%Le";
  long double val = 72537572375.1431341;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_flags) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char *format = "%015E";
  float val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_width) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char *format = "%15e";
  float val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_many) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char *format = "% .0e %.le %Le %e %le %Le";
  float val = 0;
  double val1 = 0;
  long double val2 = 3515315.153151;
  float val3 = 5.5;
  double val4 = 0.094913941;
  long double val5 = 95919539159.53151351131;
  ck_assert_int_eq(s21_sprintf(str1, format, val, val1, val2, val3, val4, val5),
                   sprintf(str2, format, val, val1, val2, val3, val4, val5));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_E_int) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char *format = "%.17LE";
  long double val = 4134121;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_all_empty) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  ck_assert_int_eq(s21_sprintf(str1, "abc"), sprintf(str2, "abc"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_empty_format_and_parameters) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "abc"), sprintf(str2, "abc"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_char) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "%c", '\t'), sprintf(str2, "%c", '\t'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_char) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "%c%c%c%c%c", '\t', '\n', '0', 'S', 's'),
                   sprintf(str2, "%c%c%c%c%c", '\t', '\n', '0', 'S', 's'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_string) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "%s", "Drop Sega PLS"),
                   sprintf(str2, "%s", "Drop Sega PLS"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_string) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  ck_assert_int_eq(
      s21_sprintf(str1, "%s%s%s%s%s", "Drop", " ", "Sega", " ", "PLS"),
      sprintf(str2, "%s%s%s%s%s", "Drop", " ", "Sega", " ", "PLS"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_dec) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "%d", 666), sprintf(str2, "%d", 666));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_dec) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "%d%d%d%d", -999, 0, 666, -100),
                   sprintf(str2, "%d%d%d%d", -999, 0, 666, -100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_int) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "%i", -0), sprintf(str2, "%i", -0));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_int) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "%i%i%i%i", -999, 0, 666, -100),
                   sprintf(str2, "%i%i%i%i", -999, 0, 666, -100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_float) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  ck_assert_int_eq(s21_sprintf(str1, "%f", 0.0001),
                   sprintf(str2, "%f", 0.0001));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_float) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  ck_assert_int_eq(
      s21_sprintf(str1, "%f%f%f%f", -999.666, 0.0001, 666.999, -100.001),
      sprintf(str2, "%f%f%f%f", -999.666, 0.0001, 666.999, -100.001));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_unsigned_dec) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  ck_assert_int_eq(s21_sprintf(str1, "%u", 100),
                   sprintf(str2, "%u", (unsigned)100));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_unsigned_dec) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "%u%u%u%u", 999, 0, 666, 100),
                   sprintf(str2, "%u%u%u%u", (unsigned)999, (unsigned)0,
                           (unsigned)666, (unsigned)100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_char_with_alignment_left) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "%8c", '\t'), sprintf(str2, "%8c", '\t'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_char_with_alignment_right) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "%-8c", '\t'),
                   sprintf(str2, "%-8c", '\t'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_char_with_alignment) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  ck_assert_int_eq(
      s21_sprintf(str1, "%3c%-11c%10c%-2c%c", '\t', '\n', '0', 'S', 's'),
      sprintf(str2, "%3c%-11c%10c%-2c%c", '\t', '\n', '0', 'S', 's'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

// START HEX TEST
START_TEST(sprintf_test_one_hex_lower) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  ck_assert_int_eq(s21_sprintf(str1, "%x", (unsigned)INT32_MIN),
                   sprintf(str2, "%x", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%x", 0), sprintf(str2, "%x", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%x", INT32_MAX),
                   sprintf(str2, "%x", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_hex_upper) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "%X", (unsigned)INT32_MIN),
                   sprintf(str2, "%X", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%X", 0), sprintf(str2, "%x", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%X", INT32_MAX),
                   sprintf(str2, "%X", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_hex_lower) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  ck_assert_int_eq(
      s21_sprintf(str1, "%x%x%x%x%x", 12340987, 135, 0, -1230, -123213123),
      sprintf(str2, "%x%x%x%x%x", 12340987, 135, 0, -1230, -123213123));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_hex_upper) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  ck_assert_int_eq(
      s21_sprintf(str1, "%X%X%X%X%X", 12340987, 135, 0, -1230, -123213123),
      sprintf(str2, "%X%X%X%X%X", 12340987, 135, 0, -1230, -123213123));
  ck_assert_str_eq(str1, str2);
}
END_TEST
// END HEX TEST

// START HEX WITH ALIGNMENT
START_TEST(sprintf_test_one_hex_lower_with_alignment_left) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "%-3x", (unsigned)INT32_MIN),
                   sprintf(str2, "%-3x", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%-3x", 0), sprintf(str2, "%-3x", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%-3x", INT32_MAX),
                   sprintf(str2, "%-3x", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_hex_lower_with_alignment_right) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "%13x", (unsigned)INT32_MIN),
                   sprintf(str2, "%13x", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%13x", 0), sprintf(str2, "%13x", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%13x", INT32_MAX),
                   sprintf(str2, "%13x", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_hex_upper_with_alignment_left) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "%-60X", INT32_MIN),
                   sprintf(str2, "%-60X", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%-60X", 0), sprintf(str2, "%-60X", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%-60X", INT32_MAX),
                   sprintf(str2, "%-60X", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_hex_upper_with_alignment_right) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "%7X", (unsigned)INT32_MIN),
                   sprintf(str2, "%7X", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%7X", 0), sprintf(str2, "%7X", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%7X", INT32_MAX),
                   sprintf(str2, "%7X", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_hex_lower_with_alignment) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  ck_assert_int_eq(
      s21_sprintf(str1, "%2x%-7x%9x%11x%0x", 12340987, 100, 0, 1, -666999),
      sprintf(str2, "%2x%-7x%9x%11x%0x", 12340987, 100, 0, 1, -666999));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_hex_upper_with_alignment) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  ck_assert_int_eq(
      s21_sprintf(str1, "%2X%-7X%9X%11X%0X", 12340987, 100, 0, 1, -666999),
      sprintf(str2, "%2X%-7X%9X%11X%0X", 12340987, 100, 0, 1, -666999));
  ck_assert_str_eq(str1, str2);
}
END_TEST
// START HEX WITH ALIGNMENT

// START HEX TEST WITH #
START_TEST(sprintf_test_one_hex_with_hashtag) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "%#x", INT32_MIN),
                   sprintf(str2, "%#x", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%#x", 0), sprintf(str2, "%#x", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%#x", INT32_MAX),
                   sprintf(str2, "%#x", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_hex_upper_with_hashtag) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "%#X", INT32_MIN),
                   sprintf(str2, "%#X", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%#X", 0), sprintf(str2, "%#X", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%#X", INT32_MAX),
                   sprintf(str2, "%#X", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_hex_lower_with_hashtag_and_alignm) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  ck_assert_int_eq(
      s21_sprintf(str1, "%#x%#x%3x%#32x%#-1x", 87, 1222224535, -13, -0,
                  123213123),
      sprintf(str2, "%#x%#x%3x%#32x%#-1x", 87, 1222224535, -13, -0, 123213123));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_hex_upper_with_hashtag_and_alignm) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  ck_assert_int_eq(
      s21_sprintf(str1, "%#X%#X%3X%#32X%#-1X", 87, 1222224535, -13, -0,
                  123213123),
      sprintf(str2, "%#X%#X%3X%#32X%#-1X", 87, 1222224535, -13, -0, 123213123));
  ck_assert_str_eq(str1, str2);
}
END_TEST
// END HEX TEST WITH #

// START HEX TEST with width *
START_TEST(sprintf_test_one_hex_lower_with_width_star) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "%*x", 11, INT32_MIN),
                   sprintf(str2, "%*x", 11, (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);

  ck_assert_int_eq(s21_sprintf(str1, "%*x", 11, 0),
                   sprintf(str2, "%*x", 11, 0));
  ck_assert_str_eq(str1, str2);

  ck_assert_int_eq(s21_sprintf(str1, "%*x", 11, INT32_MAX),
                   sprintf(str2, "%*x", 11, INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_hex_upper_with_width_star) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "%*X", 11, INT32_MIN),
                   sprintf(str2, "%*X", 11, (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);

  ck_assert_int_eq(s21_sprintf(str1, "%*X", 11, 0),
                   sprintf(str2, "%*X", 11, 0));
  ck_assert_str_eq(str1, str2);

  ck_assert_int_eq(s21_sprintf(str1, "%*X", 11, INT32_MAX),
                   sprintf(str2, "%*X", 11, INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_hex_lower_with_width_star_and_align_and_hashtag) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "%#*x%*x%-12x%3x%*x", 9, 127312897, 0, -1,
                               199, -123978, 3, -1251),
                   sprintf(str2, "%#*x%*x%-12x%3x%*x", 9, 127312897, -0, -1,
                           199, -123978, 3, -1251));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_hex_upper_with_width_star) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "%#*X%*X%-12X%3X%*X", 9, 127312897, 0, -1,
                               199, -123978, 3, -1251),
                   sprintf(str2, "%#*X%*X%-12X%3X%*X", 9, 127312897, 0, -1, 199,
                           -123978, 3, -1251));
  ck_assert_str_eq(str1, str2);
}
END_TEST
// END HEX TEST WITH Width *

// START HEX TEST WITH precision
START_TEST(sprintf_test_one_hex_lower_with_precision) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  int a = s21_sprintf(str1, "%*.6x", 11, 0);
  int b = sprintf(str2, "%*.6x", 11, 0);
  ck_assert_int_eq(a, b);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_hex_upper_with_precision) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  int a = s21_sprintf(str1, "%*.6X", 11, INT32_MIN);
  int b = sprintf(str2, "%*.6X", 11, (unsigned)INT32_MIN);
  ck_assert_int_eq(a, b);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_hex_lower_with_precision_and_other) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  int a = s21_sprintf(
      str1, "%#3.*x%#3x%-7.*x%#-1.8x%4.3x%#2.15x%*.*x%*.1x%3x%-1x", 3, 126714,
      4444444, 0, 6423235, 0, 666, 999, 13, 5, 419, 9, 41, -41, 33);
  int b = sprintf(str2, "%#3.*x%#3x%-7.*x%#-1.8x%4.3x%#2.15x%*.*x%*.1x%3x%-1x",
                  3, 126714, 4444444, 0, 6423235, 0, 666, 999, 13, 5, 419, 9,
                  41, -41, 33);
  ck_assert_int_eq(a, b);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_hex_upper_with_precision_and_other) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  ck_assert_int_eq(
      s21_sprintf(str1, "%#3.*X%#3x%-7.*X%#-1.8X%4.3X%#2.15x%*.*X%*.1X%3X%-1X",
                  3, -126714, 4444444, 0, 6423235, 0, 666, 999, 13, 5, -419, 9,
                  41, -41, 33),
      sprintf(str2, "%#3.*X%#3x%-7.*X%#-1.8X%4.3X%#2.15x%*.*X%*.1X%3X%-1X", 3,
              -126714, 4444444, 0, 6423235, 0, 666, 999, 13, 5, -419, 9, 41,
              -41, 33));
  ck_assert_str_eq(str1, str2);
}
END_TEST
// END HEX TEST WITH precision

// START HEX TEST WITH Length
START_TEST(sprintf_test_one_hex_lower_with_length) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "%hx", -11),
                   sprintf(str2, "%hx", (unsigned short)-11));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%hx", 0),
                   sprintf(str2, "%hx", (unsigned short)0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%hx", 11),
                   sprintf(str2, "%hx", (unsigned short)11));
  ck_assert_str_eq(str1, str2);
  long unsigned int val = INT32_MAX;
  ck_assert_int_eq(s21_sprintf(str1, "%lx", val), sprintf(str2, "%lx", val));
  ck_assert_str_eq(str1, str2);
  long unsigned int v = 0;
  ck_assert_int_eq(s21_sprintf(str1, "%lx", v), sprintf(str2, "%lx", v));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_hex_upper_with_length) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "%hx", -11),
                   sprintf(str2, "%hx", (unsigned short)-11));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%hx", 0),
                   sprintf(str2, "%hx", (unsigned short)0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%hx", 11),
                   sprintf(str2, "%hx", (unsigned short)11));
  ck_assert_str_eq(str1, str2);
  long unsigned int val = INT32_MAX;
  ck_assert_int_eq(s21_sprintf(str1, "%lx", val), sprintf(str2, "%lx", val));
  ck_assert_str_eq(str1, str2);
  long unsigned int v = 0;
  ck_assert_int_eq(s21_sprintf(str1, "%lx", v), sprintf(str2, "%lx", v));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf1) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%10ld";

  ck_assert_int_eq(s21_sprintf(str1, format, 1), sprintf(str2, format, 1));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf2) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%1.1f";

  ck_assert_int_eq(s21_sprintf(str1, format, 1.1), sprintf(str2, format, 1.1));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf3) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%8.3c";

  ck_assert_int_eq(s21_sprintf(str1, format, 'a'), sprintf(str2, format, 'a'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf4) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%+5.5d aboba";

  int val = 10000;
  int a = s21_sprintf(str1, format, val);
  int b = sprintf(str2, format, val);
  ck_assert_int_eq(a, b);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf6) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%7.7f";

  ck_assert_int_eq(s21_sprintf(str1, format, 11.123456),
                   sprintf(str2, format, 11.123456));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf7) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%7.4s";

  ck_assert_int_eq(s21_sprintf(str1, format, "aboba floppa"),
                   sprintf(str2, format, "aboba floppa"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf8) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%6.6u";

  ck_assert_int_eq(s21_sprintf(str1, format, 12341151),
                   sprintf(str2, format, 12341151));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf9) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%li%ld%lu";

  ck_assert_int_eq(s21_sprintf(str1, format, 666666666666, 777, 111),
                   sprintf(str2, format, 666666666666, 777, 111));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf10) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%hi%hd%hu";

  ck_assert_int_eq(s21_sprintf(str1, format, 666, -777, 111),
                   sprintf(str2, format, 666, -777, 111));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf11) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%+li%+lu%+d%+lf";

  ck_assert_int_eq(s21_sprintf(str1, format, -123, 321, -5555, -1213.123),
                   sprintf(str2, format, -123, 321, -5555, -1213.123));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf12) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%-11.11li%-35.5lu%-3.5ld%33.19Lf";
  long double k = 333.33213;

  ck_assert_int_eq(
      s21_sprintf(str1, format, 66666666666, 5555555555, 44444444444, k),
      sprintf(str2, format, 66666666666, 5555555555, 44444444444, k));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf14) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "% 0.0li% 0.0lu% 0.0ld % 0.0lf";

  ck_assert_int_eq(s21_sprintf(str1, format, 1, 222, 33333333333, -166513.1232),
                   sprintf(str2, format, 1, 222, 33333333333, -166513.1232));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf15) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "% 0.0hi% 0.0hu% 0.0hd % 0.0hf";

  ck_assert_int_eq(s21_sprintf(str1, format, 1, 222, 33333333333, -166513.1232),
                   sprintf(str2, format, 1, 222, 33333333333, -166513.1232));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf16) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "% c";

  ck_assert_int_eq(s21_sprintf(str1, format, 'a'), sprintf(str2, format, 'a'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf17) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "% s";

  ck_assert_int_eq(s21_sprintf(str1, format, "aboba likes floppa"),
                   sprintf(str2, format, "aboba likes floppa"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf18) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "% s% c";

  ck_assert_int_eq(s21_sprintf(str1, format, "", 'f'),
                   sprintf(str2, format, "", 'f'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf20) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%-115s";

  ck_assert_int_eq(s21_sprintf(str1, format, "Nick her"),
                   sprintf(str2, format, "Nick her"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf24) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%+2.1c%+4.2d%+5.4i%+10.2f%+55.55s%+1.1u";

  ck_assert_int_eq(
      s21_sprintf(str1, format, 'f', 21, 42, 666.666,
                  "Lorem ipsum dolor sit amet. Aut quam ducimus.", 11),
      sprintf(str2, format, 'f', 21, 42, 666.666,
              "Lorem ipsum dolor sit amet. Aut quam ducimus.", 11));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf25) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%.f";

  ck_assert_int_eq(s21_sprintf(str1, format, 121.123),
                   sprintf(str2, format, 121.123));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf26) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%%";

  ck_assert_int_eq(s21_sprintf(str1, format), sprintf(str2, format, 1));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf27) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%%%%%%%%";

  ck_assert_int_eq(s21_sprintf(str1, format), sprintf(str2, format, 1));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf28) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  int n1;
  int n2;
  int a = s21_sprintf(str1, "%d%n", 123, &n1);
  int b = sprintf(str2, "%d%n", 123, &n2);

  ck_assert_int_eq(a, b);
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf29) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%-.f";

  ck_assert_int_eq(s21_sprintf(str1, format, 111.111),
                   sprintf(str2, format, 111.111));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf30) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%-.1d";

  ck_assert_int_eq(s21_sprintf(str1, format, 111), sprintf(str2, format, 111));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf31) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%e";
  double x = 111;
  ck_assert_int_eq(s21_sprintf(str1, format, x), sprintf(str2, format, x));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf32) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%e%e%e%e";

  ck_assert_int_eq(s21_sprintf(str1, format, 11.111, 222.2222, 666., -555.125),
                   sprintf(str2, format, 11.111, 222.2222, 666., -555.125));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf33) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%Le";
  long double x = 122.1231;

  ck_assert_int_eq(s21_sprintf(str1, format, x), sprintf(str2, format, x));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf35) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%.10e";

  ck_assert_int_eq(s21_sprintf(str1, format, 111.184314818),
                   sprintf(str2, format, 111.184314818));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf36) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%5.3e%3.2e%lf";

  ck_assert_int_eq(s21_sprintf(str1, format, 0.000111, 111.555, 1.999),
                   sprintf(str2, format, 0.000111, 111.555, 1.999));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf37) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%E";

  ck_assert_int_eq(s21_sprintf(str1, format, 0.666666),
                   sprintf(str2, format, 0.666666));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf38) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%E%E%E";

  ck_assert_int_eq(s21_sprintf(str1, format, 0.0000999, 111.9999, 6.666),
                   sprintf(str2, format, 0.0000999, 111.9999, 6.666));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf39) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%e ABOBA %Lf %Lf %Le";
  long double c = 848181;
  long double a = 0.00000001;
  long double b = 1111111.11;
  ck_assert_int_eq(s21_sprintf(str1, format, 123.123, a, b, c),
                   sprintf(str2, format, 123.123, a, b, c));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf40) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%#e Floppa %#E%#f";

  ck_assert_int_eq(s21_sprintf(str1, format, 123.111, 0.0000999, 0.555),
                   sprintf(str2, format, 123.111, 0.0000999, 0.555));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf41) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%.Lf";
  long double a = 7.9418438184;

  ck_assert_int_eq(s21_sprintf(str1, format, a), sprintf(str2, format, a));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf42) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%#5p";
  int a = 5;
  ck_assert_int_eq(s21_sprintf(str1, format, &a), sprintf(str2, format, &a));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf43) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%.5o";

  ck_assert_int_eq(s21_sprintf(str1, format, 12345),
                   sprintf(str2, format, 12345));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf44) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%#5lX";
  long hex = 314818438141;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_trailing_zero) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%g";
  double hex = 0.50300;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_large) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%g";
  double hex = 5131.43141;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_small) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%g";
  double hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_precision) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%.5g";
  double hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_precision_zero) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%.0g";
  double hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_precision_missing) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%.g";
  double hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_many_zeroes_in_front) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%.g";
  double hex = 0.0004;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_one_zero) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%g";
  double hex = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_zero) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%.5g";
  double hex = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_mantiss) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%g";
  double hex = 0.0000005;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_mantiss_flags) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%5.8g";
  double hex = 0.0000005;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_short_no_mantiss) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%g";
  double hex = 0.005;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_LG) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%LG";
  long double hex = 0.000005;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_many) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char format[] = "%LG %g %G %Lg %.5g";
  long double hex = 0.000005;
  double hex1 = 41.1341;
  double hex2 = 848.9000;
  long double hex3 = 0.0843;
  double hex4 = 0.0005;
  double hex5 = 0.8481481;
  ck_assert_int_eq(s21_sprintf(str1, format, hex, hex1, hex2, hex3, hex4, hex5),
                   sprintf(str2, format, hex, hex1, hex2, hex3, hex4, hex5));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_width_char) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  char *format = "This is a simple wide char %5c";
  char w = 'c';
  int a = s21_sprintf(str1, format, w);
  int b = sprintf(str2, format, w);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
}
END_TEST

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

START_TEST(s21_nums_f) {
  char s21_buffer[256] = {0};
  char buffer[256] = {0};
  s21_sprintf(s21_buffer,
              "%-2i %+5i % 4i %2i %4d %d %15d %-+15d %22u %5u %4u %3u", 101,
              -210, -0, '0', 101, -210, -0, '0', (unsigned int)101,
              (unsigned int)210, (unsigned int)-0, (unsigned int)'0');
  sprintf(buffer, "%-2i %+5i % 4i %2i %4d %d %15d %-+15d %22u %5u %4u %3u", 101,
          -210, -0, '0', 101, -210, -0, '0', (unsigned int)101,
          (unsigned int)210, (unsigned int)-0, (unsigned int)'0');
  ck_assert_str_eq(s21_buffer, buffer);
}
END_TEST

START_TEST(s21_nums2_f) {
  char s21_buffer[256] = {0};
  char buffer[256] = {0};

  s21_sprintf(s21_buffer, "%- 5li %-5hi %12hu %-4lu %hi %li %hi %li",
              (long int)125123123123, (short int)160, (unsigned short)101,
              (unsigned long)210, (short int)0, (long int)0, (short int)-25,
              (long int)-51);
  sprintf(buffer, "%- 5li %-5hi %12hu %-4lu %hi %li %hi %li",
          (long int)125123123123, (short int)160, (unsigned short)101,
          (unsigned long)210, (short int)0, (long int)0, (short int)-25,
          (long int)-51);
  ck_assert_str_eq(s21_buffer, buffer);
}
END_TEST

START_TEST(s21_nums3_f) {
  char s21_buffer[256] = {0};
  char buffer[256] = {0};
  s21_sprintf(s21_buffer, "%-+6.4f %-2.2lf %5.5f %f %f", 100.0, 0.01, 0.10,
              -12.0, 0.00001);
  sprintf(buffer, "%-+6.4f %-2.2f %5.5f %f %f", 100.0, 0.01, 0.10, -12.0,
          0.00001);
  ck_assert_str_eq(s21_buffer, buffer);

  char s21_buffer2[256] = {0};
  char buffer2[256] = {0};
  s21_sprintf(s21_buffer2, "%lf %lf %lf %lf %lf %lf", 0.0 / 0.0, 1.0 / 0.0,
              0.0 / 1.0, -0.0 / 0.0, -1.0 / 0.0, -0.0 / 1.0);
  sprintf(buffer2, "%lf %lf %lf %lf %lf %lf", 0.0 / 0.0, 1.0 / 0.0, 0.0 / 1.0,
          -0.0 / 0.0, -1.0 / 0.0, -0.0 / 1.0);
  ck_assert_str_eq(s21_buffer2, buffer2);

  char s21_buffer3[256] = {0};
  char buffer3[256] = {0};
  s21_sprintf(s21_buffer3, "%lg %lG %#lg le", 234243.234, 8427348.234, 123.0,
              155.2);
  sprintf(buffer3, "%lg %lG %#lg le", 234243.234, 8427348.234, 123.0);
  ck_assert_str_eq(s21_buffer3, buffer3);
}
END_TEST
// hard part
START_TEST(s21_sprintf_inf) {
  char s21_buffer[256] = {0};
  char buffer[256] = {0};
  char format[] = "%#*.*f";
  int width = 33;
  int accuracy = 100;
  float value = 1 / 0.;
  s21_sprintf(s21_buffer, format, width, accuracy, value);
  sprintf(buffer, format, width, accuracy, value);
  ck_assert_str_eq(buffer, s21_buffer);
  char format2[] = "%+#*.*f";
  width = -33;
  accuracy = -100;
  value = -1 / 0.;
  s21_sprintf(s21_buffer, format2, width, accuracy, value);
  sprintf(buffer, format2, width, accuracy, value);
  ck_assert_str_eq(buffer, s21_buffer);
  width = -200;
  accuracy = -120;
  value = -0 / 0.;
  s21_sprintf(s21_buffer, format2, width, accuracy, value);
  sprintf(buffer, format2, width, accuracy, value);
  ck_assert_str_eq(buffer, s21_buffer);
}

START_TEST(s21_sprintf_without_spec) {
  char str1[200] = {0};
  char str2[200] = {0};
  char format[] = "%+#0   -*.*K";
  int width = 33;
  int accuracy = 100;
  float value = -0 / 0.;
  s21_sprintf(str1, format, width, accuracy, value);
  sprintf(str2, format, width, accuracy, value);
  ck_assert_str_eq(str1, str2);
}

START_TEST(s21_sprintf_e_round) {
  char str1[200] = {0};
  char str2[200] = {0};
  char format[] = "%+#0   -*.*e";
  int width = 33;
  int accuracy = 0;
  float value = -9.999999 * 1e10;
  s21_sprintf(str1, format, width, accuracy, value);
  sprintf(str2, format, width, accuracy, value);
  ck_assert_str_eq(str1, str2);
}
START_TEST(s21_sprintf_f_round) {
  char str1[200] = {0};
  char str2[200] = {0};
  char format[] = "%+#0   -*.*f";
  int width = 33;
  int accuracy = 0;
  float value = -9.999999;
  s21_sprintf(str1, format, width, accuracy, value);
  sprintf(str2, format, width, accuracy, value);
  ck_assert_str_eq(str1, str2);
}

START_TEST(s21_sprintf_s_NULL) {
  char str1[200] = {0};
  char str2[200] = {0};
  char format[] = "%30.50s";
  char *n = NULL;
  s21_sprintf(str1, format, n);
  sprintf(str2, format, n);
  ck_assert_str_eq(str1, str2);
}
START_TEST(s21_sprintf_X_sharp) {
  char str1[300] = {0};
  char str2[300] = {0};
  char format[] = "%#0X";
  long long very_big = 9223372036854775807ll;
  s21_sprintf(str1, format, very_big);
  sprintf(str2, format, very_big);
  ck_assert_str_eq(str1, str2);
}
//
Suite *test_g(void) {
  Suite *s;
  TCase *tc_bin;
  TCase *eternal_sprintf;

  s = suite_create("Gulianbo");
  tc_bin = tcase_create("Bin");
  eternal_sprintf = tcase_create("ETERNAL");
  tcase_add_test(eternal_sprintf, s21_sprintf_inf);
  tcase_add_test(eternal_sprintf, s21_sprintf_without_spec);
  tcase_add_test(eternal_sprintf, s21_sprintf_e_round);
  tcase_add_test(eternal_sprintf, s21_sprintf_f_round);
  tcase_add_test(eternal_sprintf, s21_sprintf_s_NULL);
  tcase_add_test(eternal_sprintf, s21_sprintf_X_sharp);
  suite_add_tcase(s, eternal_sprintf);

  tcase_add_test(tc_bin, first);
  tcase_add_test(tc_bin, s21_sprintf_test_d);
  tcase_add_test(tc_bin, s21_chars_f);
  tcase_add_test(tc_bin, s21_sprintf_test_i);
  tcase_add_test(tc_bin, s21_sprintf_test_f);
  tcase_add_test(tc_bin, s21_sprintf_test_g);
  tcase_add_test(tc_bin, s21_sprintf_test_G);
  tcase_add_test(tc_bin, s21_sprintf_test_o);
  tcase_add_test(tc_bin, s21_sprintf_test_X);
  tcase_add_test(tc_bin, s21_sprintf_test_x);
  tcase_add_test(tc_bin, s21_sprintf_test_p);
  tcase_add_test(tc_bin, s21_sprintf_test_u);
  tcase_add_test(tc_bin, s21_sprintf_test_s);
  tcase_add_test(tc_bin, main_my);
  tcase_add_test(tc_bin, sprintf_simple_int);
  tcase_add_test(tc_bin, sprintf_precise_int);
  tcase_add_test(tc_bin, sprintf_width_int);
  tcase_add_test(tc_bin, sprintf_minus_width_int);
  tcase_add_test(tc_bin, sprintf_plus_width_int);
  tcase_add_test(tc_bin, sprintf_padding_int);
  tcase_add_test(tc_bin, sprintf_star_width_int);
  tcase_add_test(tc_bin, sprintf_star_precision_int);
  tcase_add_test(tc_bin, sprintf_many_flags_many_ints);
  tcase_add_test(tc_bin, sprintf_flags_long_int);
  tcase_add_test(tc_bin, sprintf_flags_short_int);
  tcase_add_test(tc_bin, sprintf_flags_another_long_int);
  tcase_add_test(tc_bin, sprintf_zero_precision_zero_int);
  tcase_add_test(tc_bin, sprintf_space_flag_int);
  tcase_add_test(tc_bin, sprintf_unsigned_val);
  tcase_add_test(tc_bin, sprintf_unsigned_val_width);
  tcase_add_test(tc_bin, sprintf_unsigned_val_flags);
  tcase_add_test(tc_bin, sprintf_unsigned_val_precision);
  tcase_add_test(tc_bin, sprintf_unsigned_val_many_flags);
  tcase_add_test(tc_bin, sprintf_unsigned_val_short);
  tcase_add_test(tc_bin, sprintf_unsigned_val_long);
  tcase_add_test(tc_bin, sprintf_unsigned_val_many);

  tcase_add_test(tc_bin, sprintf_octal_width);
  tcase_add_test(tc_bin, sprintf_octal_flags);
  tcase_add_test(tc_bin, sprintf_octal_precision);
  tcase_add_test(tc_bin, sprintf_octal_many_flags);
  tcase_add_test(tc_bin, sprintf_octal_short);
  tcase_add_test(tc_bin, sprintf_octal_long);
  tcase_add_test(tc_bin, sprintf_octal_many);
  tcase_add_test(tc_bin, sprintf_octal);
  tcase_add_test(tc_bin, sprintf_octal_zero);
  tcase_add_test(tc_bin, sprintf_octal_hash);
  tcase_add_test(tc_bin, sprintf_unsigned_zero);
  tcase_add_test(tc_bin, sprintf_hex_width);
  tcase_add_test(tc_bin, sprintf_hex_flags);
  tcase_add_test(tc_bin, sprintf_hex_precision);
  tcase_add_test(tc_bin, sprintf_hex_many);
  tcase_add_test(tc_bin, sprintf_hex_many_flags);
  tcase_add_test(tc_bin, sprintf_hex_zero);
  tcase_add_test(tc_bin, sprintf_hex_huge);
  tcase_add_test(tc_bin, sprintf_hex_short);
  tcase_add_test(tc_bin, sprintf_hex_long);
  tcase_add_test(tc_bin, sprintf_hex_one_longer_width);
  tcase_add_test(tc_bin, sprintf_hex_two_longer_width);
  tcase_add_test(tc_bin, sprintf_one_char);
  tcase_add_test(tc_bin, sprintf_one_precision);
  tcase_add_test(tc_bin, sprintf_one_flags);
  tcase_add_test(tc_bin, sprintf_one_width);
  tcase_add_test(tc_bin, sprintf_one_many);
  tcase_add_test(tc_bin, sprintf_one_many_flags);
  tcase_add_test(tc_bin, sprintf_string);
  tcase_add_test(tc_bin, sprintf_string_precision);
  tcase_add_test(tc_bin, sprintf_string_width);
  tcase_add_test(tc_bin, sprintf_string_flags);
  tcase_add_test(tc_bin, sprintf_string_long);
  tcase_add_test(tc_bin, sprintf_string_many);
  tcase_add_test(tc_bin, sprintf_ptr);
  tcase_add_test(tc_bin, sprintf_ptr_width);
  tcase_add_test(tc_bin, sprintf_ptr_precision);
  tcase_add_test(tc_bin, sprintf_null_ptr);
  tcase_add_test(tc_bin, sprintf_n_specifier);
  tcase_add_test(tc_bin, sprintf_string_width_huge);
  tcase_add_test(tc_bin, sprintf_float_precision);
  tcase_add_test(tc_bin, sprintf_float_width);
  tcase_add_test(tc_bin, sprintf_float_precision_zero);
  tcase_add_test(tc_bin, sprintf_float_precision_empty);
  tcase_add_test(tc_bin, sprintf_float_precision_huge);
  tcase_add_test(tc_bin, sprintf_float_precision_huge_negative);
  tcase_add_test(tc_bin, sprintf_float_huge);
  tcase_add_test(tc_bin, sprintf_float_flags);
  tcase_add_test(tc_bin, sprintf_float_many);
  tcase_add_test(tc_bin, sprintf_e_precision);
  tcase_add_test(tc_bin, sprintf_e_precision_zero);
  tcase_add_test(tc_bin, sprintf_e_precision_empty);
  tcase_add_test(tc_bin, sprintf_e_precision_huge);
  tcase_add_test(tc_bin, sprintf_e_precision_huge_negative);
  tcase_add_test(tc_bin, sprintf_e_huge);
  tcase_add_test(tc_bin, sprintf_e_many);
  tcase_add_test(tc_bin, sprintf_e_width);
  tcase_add_test(tc_bin, sprintf_e_flags);
  tcase_add_test(tc_bin, sprintf_E_int);
  tcase_add_test(tc_bin, sprintf_all_empty);
  tcase_add_test(tc_bin, sprintf_empty_format_and_parameters);
  tcase_add_test(tc_bin, sprintf_test_one_char);
  tcase_add_test(tc_bin, sprintf_test_many_char);
  tcase_add_test(tc_bin, sprintf_test_one_string);
  tcase_add_test(tc_bin, sprintf_test_many_string);
  tcase_add_test(tc_bin, sprintf_test_one_dec);
  tcase_add_test(tc_bin, sprintf_test_many_dec);
  tcase_add_test(tc_bin, sprintf_test_one_int);
  tcase_add_test(tc_bin, sprintf_test_many_int);
  tcase_add_test(tc_bin, sprintf_test_one_float);
  tcase_add_test(tc_bin, sprintf_test_many_float);
  tcase_add_test(tc_bin, sprintf_test_one_unsigned_dec);
  tcase_add_test(tc_bin, sprintf_test_many_unsigned_dec);
  tcase_add_test(tc_bin, sprintf_test_one_char_with_alignment_left);
  tcase_add_test(tc_bin, sprintf_test_one_char_with_alignment_right);
  tcase_add_test(tc_bin, sprintf_test_many_char_with_alignment);
  tcase_add_test(tc_bin, sprintf_test_one_hex_lower);
  tcase_add_test(tc_bin, sprintf_test_one_hex_upper);
  tcase_add_test(tc_bin, sprintf_test_many_hex_lower);
  tcase_add_test(tc_bin, sprintf_test_many_hex_upper);
  tcase_add_test(tc_bin, sprintf_test_one_hex_lower_with_alignment_left);
  tcase_add_test(tc_bin, sprintf_test_one_hex_lower_with_alignment_right);
  tcase_add_test(tc_bin, sprintf_test_one_hex_upper_with_alignment_left);
  tcase_add_test(tc_bin, sprintf_test_one_hex_upper_with_alignment_right);
  tcase_add_test(tc_bin, sprintf_test_many_hex_lower_with_alignment);
  tcase_add_test(tc_bin, sprintf_test_many_hex_upper_with_alignment);
  tcase_add_test(tc_bin, sprintf_test_one_hex_with_hashtag);
  tcase_add_test(tc_bin, sprintf_test_one_hex_upper_with_hashtag);
  tcase_add_test(tc_bin, sprintf_test_many_hex_lower_with_hashtag_and_alignm);
  tcase_add_test(tc_bin, sprintf_test_many_hex_upper_with_hashtag_and_alignm);
  tcase_add_test(tc_bin, sprintf_test_one_hex_lower_with_width_star);
  tcase_add_test(tc_bin, sprintf_test_one_hex_upper_with_width_star);
  tcase_add_test(
      tc_bin,
      sprintf_test_many_hex_lower_with_width_star_and_align_and_hashtag);
  tcase_add_test(tc_bin, sprintf_test_many_hex_upper_with_width_star);
  tcase_add_test(tc_bin, sprintf_test_one_hex_lower_with_precision);
  tcase_add_test(tc_bin, sprintf_test_one_hex_upper_with_precision);
  tcase_add_test(tc_bin, sprintf_test_many_hex_lower_with_precision_and_other);
  tcase_add_test(tc_bin, sprintf_test_many_hex_upper_with_precision_and_other);
  tcase_add_test(tc_bin, sprintf_test_one_hex_lower_with_length);
  tcase_add_test(tc_bin, sprintf_test_one_hex_upper_with_length);
  tcase_add_test(tc_bin, sprintf_test_sprintf1);
  tcase_add_test(tc_bin, sprintf_test_sprintf2);
  tcase_add_test(tc_bin, sprintf_test_sprintf3);
  tcase_add_test(tc_bin, sprintf_test_sprintf4);
  tcase_add_test(tc_bin, sprintf_test_sprintf6);
  tcase_add_test(tc_bin, sprintf_test_sprintf7);
  tcase_add_test(tc_bin, sprintf_test_sprintf8);
  tcase_add_test(tc_bin, sprintf_test_sprintf9);
  tcase_add_test(tc_bin, sprintf_test_sprintf10);
  tcase_add_test(tc_bin, sprintf_test_sprintf11);
  tcase_add_test(tc_bin, sprintf_test_sprintf12);
  tcase_add_test(tc_bin, sprintf_test_sprintf14);
  tcase_add_test(tc_bin, sprintf_test_sprintf15);
  tcase_add_test(tc_bin, sprintf_test_sprintf16);
  tcase_add_test(tc_bin, sprintf_test_sprintf17);
  tcase_add_test(tc_bin, sprintf_test_sprintf18);
  tcase_add_test(tc_bin, sprintf_test_sprintf20);
  tcase_add_test(tc_bin, sprintf_test_sprintf24);
  tcase_add_test(tc_bin, sprintf_test_sprintf25);
  tcase_add_test(tc_bin, sprintf_test_sprintf28);
  tcase_add_test(tc_bin, sprintf_test_sprintf29);
  tcase_add_test(tc_bin, sprintf_test_sprintf30);
  tcase_add_test(tc_bin, sprintf_test_sprintf31);
  tcase_add_test(tc_bin, sprintf_test_sprintf32);
  tcase_add_test(tc_bin, sprintf_test_sprintf33);
  tcase_add_test(tc_bin, sprintf_test_sprintf35);
  tcase_add_test(tc_bin, sprintf_test_sprintf36);
  tcase_add_test(tc_bin, sprintf_test_sprintf37);
  tcase_add_test(tc_bin, sprintf_test_sprintf38);
  tcase_add_test(tc_bin, sprintf_test_sprintf39);
  tcase_add_test(tc_bin, sprintf_test_sprintf40);
  tcase_add_test(tc_bin, sprintf_test_sprintf41);
  tcase_add_test(tc_bin, sprintf_test_sprintf42);
  tcase_add_test(tc_bin, sprintf_test_sprintf43);
  tcase_add_test(tc_bin, sprintf_test_sprintf44);
  tcase_add_test(tc_bin, sprintf_test_sprintf26);
  tcase_add_test(tc_bin, sprintf_test_sprintf27);
  tcase_add_test(tc_bin, sprintf_g_trailing_zero);
  tcase_add_test(tc_bin, sprintf_g_large);
  tcase_add_test(tc_bin, sprintf_g_small);
  tcase_add_test(tc_bin, sprintf_g_precision);
  tcase_add_test(tc_bin, sprintf_g_precision_zero);
  tcase_add_test(tc_bin, sprintf_g_precision_missing);
  tcase_add_test(tc_bin, sprintf_g_many_zeroes_in_front);
  tcase_add_test(tc_bin, sprintf_g_one_zero);
  tcase_add_test(tc_bin, sprintf_g_mantiss);
  tcase_add_test(tc_bin, sprintf_g_mantiss_flags);
  tcase_add_test(tc_bin, sprintf_g_short_no_mantiss);
  tcase_add_test(tc_bin, sprintf_LG);
  tcase_add_test(tc_bin, sprintf_g_many);
  tcase_add_test(tc_bin, sprintf_g_zero);
  tcase_add_test(tc_bin, sprintf_width_char);
  tcase_add_test(tc_bin, sprintf_0);
  tcase_add_test(tc_bin, sprintf_1);
  tcase_add_test(tc_bin, sprintf_2);
  tcase_add_test(tc_bin, sprintf_3);
  tcase_add_test(tc_bin, sprintf_4);
  tcase_add_test(tc_bin, sprintf_5);
  tcase_add_test(tc_bin, sprintf_6);
  tcase_add_test(tc_bin, sprintf_7);
  tcase_add_test(tc_bin, sprintf_8);
  tcase_add_test(tc_bin, sprintf_9);
  tcase_add_test(tc_bin, sprintf_10);
  tcase_add_test(tc_bin, sprintf_11);
  tcase_add_test(tc_bin, sprintf_12);
  tcase_add_test(tc_bin, sprintf_13);
  tcase_add_test(tc_bin, sprintf_14);
  tcase_add_test(tc_bin, sprintf_15);
  tcase_add_test(tc_bin, sprintf_16);
  tcase_add_test(tc_bin, sprintf_17);
  tcase_add_test(tc_bin, sprintf_18);
  tcase_add_test(tc_bin, sprintf_19);
  tcase_add_test(tc_bin, sprintf_20);
  tcase_add_test(tc_bin, sprintf_21);
  tcase_add_test(tc_bin, sprintf_22);
  tcase_add_test(tc_bin, sprintf_23);
  tcase_add_test(tc_bin, sprintf_24);
  tcase_add_test(tc_bin, sprintf_30);
  tcase_add_test(tc_bin, sprintf_31);
  tcase_add_test(tc_bin, sprintf_32);
  tcase_add_test(tc_bin, sprintf_33);
  tcase_add_test(tc_bin, sprintf_34);
  tcase_add_test(tc_bin, sprintf_40);
  tcase_add_test(tc_bin, sprintf_41);
  tcase_add_test(tc_bin, sprintf_42);
  tcase_add_test(tc_bin, sprintf_43);
  tcase_add_test(tc_bin, sprintf_44);
  tcase_add_test(tc_bin, sprintf_50);
  tcase_add_test(tc_bin, sprintf_51);
  tcase_add_test(tc_bin, sprintf_52);
  tcase_add_test(tc_bin, sprintf_53);
  tcase_add_test(tc_bin, sprintf_54);
  tcase_add_test(tc_bin, sprintf_55);
  tcase_add_test(tc_bin, s21_nums_f);
  tcase_add_test(tc_bin, s21_nums2_f);
  tcase_add_test(tc_bin, s21_nums3_f);
  suite_add_tcase(s, tc_bin);

  return s;
}