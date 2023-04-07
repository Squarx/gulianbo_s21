#ifndef C8_3DVIEWER_V1_0_0_SRC_S21_3DVIEWER_H_
#define C8_3DVIEWER_V1_0_0_SRC_S21_3DVIEWER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_matrix.h"

#define is_numb(a) ((a) >= '0' && (a) <= '9')
#define is_start_numb(a, b) ((a) == '-' || (a) == ' ') && is_numb(b)

typedef struct v_f_count {
  int v;
  int f;
  matrix_t mV;
  matrix_t mF;
  int error;
  double *resultV;
  int *resultF;
} V_F;

void parser_v(FILE *txt, char *path, V_F *count);
void result_mul(const char *line, int *i, double *result, int *len);
double numb_count(const char *line, int *i);
void file_open(FILE *txt, char *path, V_F *count);
int s21_3DViewer(char *path,
                 V_F *count);  // int s21_3DViewer(char *path, V_F *count);
void clean_long_arr(V_F *A);
void clean_all(V_F *A);
void to_long_array(V_F *count);
void counterF(int len, int *column, char *str, V_F *count, int *f);
void counterV(int len, int *column, char *str, V_F *count, int *v);
#endif  // C8_3DVIEWER_V1_0_0_SRC_S21_3DVIEWER_H_
