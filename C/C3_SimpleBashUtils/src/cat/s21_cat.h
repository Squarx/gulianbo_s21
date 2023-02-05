// "Copyright 2022 gulianbo"
// Created by Gulian Boris on 10/30/22.
//

#ifndef SRC_CAT_S21_CAT_H_
#define SRC_CAT_S21_CAT_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reader(char *arr);
int counter_flags(int argc, char **argv, int *nflg, int *bflg, int *sflg,
                  int *eflg, int *tflg, int *vflg);

void reader_file(char *path, int nflg, int bflg, int sflg, int eflg, int tflg,
                 int vflg);
#endif  //  SRC_CAT_S21_CAT_H_
