//
// Created by Gulian Boris on 1/16/23.
//

#ifndef SMART_CALC_SRC_SMART_CALC2_H_
#define SMART_CALC_SRC_SMART_CALC2_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
enum operators {
  MIN = 1,
  PLUS = 2,
  MUL = 3,
  DIV = 4,
  POW = 5,
  MOD = 6,
  L_branch = 7, // (
  R_branch = 8,  // )
  COS = 11,
  SIN = 12,
  TAN = 13,
  ACOS = 14,
  ASIN = 15,
  ATAN = 16,
  SQRT = 17,
  LN = 18,
  LOG = 19,
};

enum mode {
  CALC = 0,
  FUNC = 1,
};

enum priority {
  branch = 0,
  L = 1,
  M = 2,
  H = 3,
  F = 4,
};

typedef struct operations {
  int name;
  int priotity;
} OP;
// validator
int validator(char *str, int mode);
int mismatch_brackets(char *cursor);
int empty_brackets(char *cursor);
int float_correct(char *cursor);
int is_num(char *cursor, const char *start_str);
int is_unar_mimus(char *cursor, const char *start_str);
//
long double s21_smart_calc(char *string, int mode, long double variable, int *error);
char *parse_token(char *cursor_str,
                  int *top_num,
                  int *top_func,
                  long double *arr_num,
                  OP *arr_func,
                  char *start,
                  long double variable,
                  int *error);
/// stack

int num_add(int top, long double num, long double *data);
int pop_num(int top, long double *data);
int func_add(int name, int top_func, OP *data_func);
int pop_func(int top_func, OP *data_func);
char *get_num(char *cursor_str, long double *num);
//;

int is_func_two_arg(char *cursor);
char *get_name_func(char *cursor, int *name);
int get_priority(int name);
int compress_func(int *top_num, int *top_func, long double *arr_num, OP *arr_func, int name, int priority);
int calculation(int *top_num, int *top_func, long double *arr_num, OP *arr_func);
int calc_func(int *top_num, int *top_func, long double *arr_num, OP *arr_func);
int is_func_one_arg(char *cursor);
void print_arr_num(int top, long double *data);
void print_arr_func(int top, OP *data);
void smart_mult(char *cursor_str, char *start, int *top_func, int *top_num, OP *arr_func, long double *arr_num);
int auto_mult(char *cusror, char *start);
#endif //SMART_CALC_SRC_SMART_CALC2_H_
