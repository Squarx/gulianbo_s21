// "Copyright 2022 gulianbo"
// Created by Gulian Boris on 10/30/22.
//
#include "s21_cat.h"
int main(int argc, char **argv) {
  int nflg = 0;
  int bflg = 0;
  int sflg = 0;
  int eflg = 0;
  int tflg = 0;
  int vflg = 0;

  int end = counter_flags(argc, argv, &nflg, &bflg, &sflg, &eflg, &tflg, &vflg);
  int start = argc - end + 1;
  if (argc == 2) {
    reader(argv[1]);
  } else {
    for (int i = start; i < argc; i++)
      reader_file(argv[i], nflg, bflg, sflg, eflg, tflg, vflg);
  }
  return 0;
}

void reader(char *arr) {
  FILE *b;
  char c;
  if ((b = fopen(arr, "r")) != NULL) {
    for (; !feof(b);) {
      fscanf(b, "%c", &c);
      if (feof(b)) break;
      printf("%c", c);
    }
    fclose(b);
  } else {
    fprintf(stderr, "cat: %s: No such file or directory\n", arr);
  }
}

int counter_flags(int argc, char **argv, int *nflg, int *bflg, int *sflg,
                  int *eflg, int *tflg, int *vflg) {
  for (; argc > 1 && argv[1][0] == '-'; argc--, argv++) {
    if (strcmp(argv[1], "--number-nonblank") == 0) {
      *bflg += 1;
      continue;
    }
    if (strcmp(argv[1], "--number") == 0) {
      *nflg += 1;
      continue;
    }
    if (strcmp(argv[1], "--squeeze-blank") == 0) {
      *sflg += 1;
      continue;
    }
    if (strcmp(argv[1], "--") == 0) break;
    for (int i = 1; argv[1][i] != '\0'; i++) {
      //            printf("ARG = %c\n", argv[1][i]);
      switch (argv[1][i]) {
        case 0:
          break;
        case 'n':
          *nflg += 1;
          break;
        case 'b':
          *bflg += 1;
          break;
        case 's':
          *sflg += 1;
          break;
        case 'e':
          *eflg += 1;
          *vflg += 1;
          break;
        case 't':
          *tflg += 1;
          *vflg += 1;
          break;
        case 'E':
          *eflg += 1;
          break;
        case 'v':
          *vflg += 1;
          break;
        case 'T':
          *tflg += 1;
          break;
        default:
          fprintf(stderr,
                  "cat: illegal option -- %c\nusage: cat [-benstuv] [file ...]",
                  argv[1][i]);
          exit(1);
      }
    }
  }
  return argc;
}

void reader_file(char *path, int nflg, int bflg, int sflg, int eflg, int tflg,
                 int vflg) {
  FILE *file;
  if (bflg && nflg) nflg = 0;
  if ((file = fopen(path, "r")) != NULL) {
    int flag = 1;
    int i = 1;
    while (!feof(file)) {
      int c = fgetc(file);
      if (feof(file)) break;
      if (sflg && flag && (c == '\n')) {
        fscanf(file, "%*[\n]");
      }
      if (flag && (nflg || (bflg && c != '\n'))) {
        printf("%6d\t", i++);
        flag = 0;
      }
      if (tflg && c == 9) {
        printf("^");
        c = 'I';
      }
      if (eflg && c == '\n') printf("$");
      if (vflg) {
        if ((c >= 0 && c < 9) || (c > 10 && c < 32)) {
          printf("^%c", c + 64);
          continue;
        }
        if ((c > 126) && (c <= 160)) {
          if (c == 127) {
            printf("^%c", c - 64);
          } else {
            printf("M-^%c", c - 64);
          }
          continue;
        }
      }
      printf("%c", c);
      flag = (c == '\n') ? 1 : 0;
    }
  } else {
    fprintf(stderr, "cat: %s: No such file or directory\n", path);
  }
}
