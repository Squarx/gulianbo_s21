//
// Created by Gulian Boris on 12/23/22.
//

#ifndef C2_S21_STRINGPLUS_0_SRC_TEST_H_
#define C2_S21_STRINGPLUS_0_SRC_TEST_H_
#include <check.h>

#include "../s21_string.h"
#define BUFF_SIZE 256

Suite *test_g(void);
Suite *s21_sprintf_f_suite(void);
Suite *s21_sprintf_c_suite(void);
Suite *s21_sprintf_s_suite(void);
Suite *s21_sprintf_u_suite(void);
Suite *s21_sprintf_nyar_suite(void);
Suite *test_orig(void);
#endif  // C2_S21_STRINGPLUS_0_SRC_TEST_H_
