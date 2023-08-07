//
// Created by Gulian Boris on 10/31/22.
//

#ifndef C3_SIMPLEBASHUTILS_0_SRC_GREP_S21_GREP_H_
#define C3_SIMPLEBASHUTILS_0_SRC_GREP_S21_GREP_H_
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct flags {
  int e;
  int i;
  int v;
  int c;
  int l;
  int n;
  int h;
  int s;
  int f;
  int o;
} Flg;
int behaviour(int argc, char **argv, int *error);
void cleaner(int argc, char **files, char **patterns);
void parserV2(int argc, char **argv, Flg *flags, char **files, char **patterns,
              int *error, int withoutBE);
void flag_f_patterns(char *path, char **patterns, int *ind_pattern, int *error);
void printer(char **files, char **patterns, Flg *flags);
void reader_files(char **files, regex_t *templates, Flg flags,
                  int cnt_templates, char **patterns);
int regex_matcher(regex_t *templates, char *string, int cnt_templates);
void counter(char **files, char **patterns, int *count_files,
             int *count_patterns);
void printer_O(regex_t *templates, char *string, int cnt_templates);
void add_to_patterns(char *string, char **pattens, int *index_patterns,
                     int *error);
regex_t *regex_compiler(char **patterns, int *error, int cflags, int *cnt);
void switcher(Flg *flags, char c, int *eflag, int *fflg, int *error);
void freesher(char **patterns, regex_t *tmplates, int cnt_tmplates);
void printer_files(Flg flags, int count_files, int cnt_str, char *curr_file,
                   int files_match);
void printer_strings(int match, int count_files, Flg flags, char *string,
                     FILE *file, char *curr_file, int num_lines,
                     int cnt_templates, regex_t *templates);
#endif  // C3_SIMPLEBASHUTILS_0_SRC_GREP_S21_GREP_H_
