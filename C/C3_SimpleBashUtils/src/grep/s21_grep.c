#include "s21_grep.h"

int main(int argc, char **argv) {
  char *tmp = calloc(1, sizeof(int));

  if (tmp != NULL) {
    regex_t *tmplates;
    Flg flags = {0};
    char *files[1024];
    char *patterns[1024];
    int cnt_tmplates = 0;

    cleaner(1024, files, patterns);
    int error = 0;
    int withBE = behaviour(argc, argv, &error);
    if (!error) parserV2(argc, argv, &flags, files, patterns, &error, withBE);
    int cflags = (flags.i) ? REG_ICASE | REG_NEWLINE : REG_NEWLINE;
    tmplates = regex_compiler(patterns, &error, cflags, &cnt_tmplates);
    if (tmplates == NULL) error = 1;
    if (!error) {
      reader_files(files, tmplates, flags, cnt_tmplates, patterns);
    }
    freesher(patterns, tmplates, cnt_tmplates);
    free(tmp);
  } else {
    fprintf(stderr, "No memory on PC\n");
  }
  return 0;
}

void freesher(char **patterns, regex_t *tmplates, int cnt_tmplates) {
  if (patterns[0] != NULL) {
    for (int i = 0; patterns[i]; i++) {
      free(patterns[i]);
    }
  }
  if (tmplates != NULL) {
    for (int i = 0; i < cnt_tmplates; i++) {
      regfree(&(tmplates[i]));
    }
    free(tmplates);
  }
}

regex_t *regex_compiler(char **patterns, int *error, int cflags, int *cnt) {
  for (int i = 0; patterns[i]; i++) *cnt += 1;
  regex_t *list = calloc(*cnt, sizeof(regex_t));
  if (list == NULL) {
    *error = 1;
  } else {
    for (int j = 0; patterns[j] && !*error; j++) {
      if ((regcomp(&(list[j]), patterns[j], cflags))) {
        fprintf(stderr, "Could not compile regex\n");
        *error = 1;
      }
    }
  }
  return list;
}

void add_to_patterns(char *string, char **patterns, int *index_patterns,
                     int *error) {
  char *dynamix = calloc(strlen(string) + 1, sizeof(char));
  if (dynamix != NULL) {
    strcpy(dynamix, string);
    patterns[*index_patterns] = dynamix;
    *index_patterns += 1;
  } else {
    *error = 1;
  }
}

void printer_O(regex_t *templates, char *string, int cnt_templates) {
  regmatch_t pmatch[1];
  const size_t nmatch = 1;

  char *adress = string;
  for (int j = 0; j < cnt_templates; j++) {
    int match = 0;

    while (regexec(&(templates[j]), adress, nmatch, pmatch, 0) == 0) {
      int start = 0;
      for (int i = pmatch[0].rm_so; i < pmatch[0].rm_eo; i++)
        printf("%c", adress[i]);
      printf("\n");
      start = pmatch[0].rm_eo;
      adress = adress + start;
      match++;
    }
  }
}

void counter(char **files, char **patterns, int *count_files,
             int *count_patterns) {
  for (int i = 0; files[i]; i++) *count_files += 1;
  for (int i = 0; patterns[i]; i++) *count_patterns += 1;
}

int regex_matcher(regex_t *templates, char *string, int cnt_templates) {
  int status = 1;
  regmatch_t pmatch[1];
  const size_t nmatch = 1;
  for (int j = 0; j < cnt_templates && status; j++) {
    status = regexec(&(templates[j]), string, nmatch, pmatch, 0);
  }
  return !status;
}

void printer_strings(int match, int count_files, Flg flags, char *string,
                     FILE *file, char *curr_file, int num_lines,
                     int cnt_templates, regex_t *templates) {
  if (match && count_files > 1 && !flags.h) printf("%s:", curr_file);
  if (flags.n && match) printf("%d:", num_lines);
  if (match && !flags.o) {
    if (feof(file) && string[0]) {
      printf("%s\n", string);
    } else {
      printf("%s", string);
    }
  }
  if (flags.o) {
    if (match && !flags.v) {
      printer_O(templates, string, cnt_templates);
    }
    if (match && flags.v) {
      if (feof(file) && string[0]) {
        printf("%s\n", string);
      } else {
        printf("%s", string);
      }
    }
  }
}
void reader_files(char **files, regex_t *templates, Flg flags,
                  int cnt_templates, char **patterns) {
  int match = 0;
  int count_files = 0;
  int count_patterns = 0;
  int files_match = 0;
  int num_lines = 0;

  counter(files, patterns, &count_files, &count_patterns);
  for (int i = 0; files[i]; i++) {
    FILE *file;
    int cnt_str = 0;
    if ((file = fopen(files[i], "r")) != NULL) {
      num_lines = 0;
      char *string = NULL;
      size_t length = 0UL;
      files_match = 0;
      while (getline(&string, &length, file) >= 0L) {
        num_lines++;
        match = 0;
        match = regex_matcher(templates, string, cnt_templates);
        if (flags.v) {
          match = !match;
        }
        if (match) {
          cnt_str++;
          files_match++;
        }
        if (!flags.c && !flags.l) {
          printer_strings(match, count_files, flags, string, file, files[i],
                          num_lines, cnt_templates, templates);
        }
      }
      if (string != NULL) free(string);
      fclose(file);
    } else {
      if (!flags.s) {
        fprintf(stderr, "grep: %s: No such file or directory\n", files[i]);
      }
      continue;
    }
    printer_files(flags, count_files, cnt_str, files[i], files_match);
  }
}

void printer_files(Flg flags, int count_files, int cnt_str, char *curr_file,
                   int files_match) {
  if (flags.c && !flags.l)
    (count_files < 2 || flags.h) ? printf("%d\n", cnt_str)
                                 : printf("%s:%d\n", curr_file, cnt_str);
  if (flags.l) {
    if (files_match) {
      if (count_files > 1 && flags.c) {
        flags.h ? printf("1\n%s\n", curr_file)
                : printf("%s:1\n%s\n", curr_file, curr_file);
      } else {
        flags.c ? printf("1\n%s\n", curr_file) : printf("%s\n", curr_file);
      }
    } else {
      if (count_files > 1 && flags.c) {
        flags.h ? printf("0\n") : printf("%s:0\n", curr_file);
      } else {
        if (flags.c) printf("0\n");
      }
    }
  }
}

void switcher(Flg *flags, char c, int *eflg, int *fflg, int *error) {
  switch (c) {
    case 0:
      break;
    case 'e':
      flags->e += 1;
      *eflg = 1;
      break;
    case 'i':
      flags->i += 1;
      break;
    case 'v':
      flags->v += 1;
      break;
    case 'c':
      flags->c += 1;
      break;
    case 'l':
      flags->l += 1;
      break;
    case 'n':
      flags->n += 1;
      break;
    case 'h':
      flags->h += 1;
      break;
    case 's':
      flags->s += 1;
      break;
    case 'f':
      flags->f += 1;
      *fflg = 1;
      break;
    case 'o':
      flags->o += 1;
      break;
    default:
      fprintf(stderr,
              "grep: illegal option -- %c\nusage: cat [-benstuv] [file ...]",
              c);
      *error = 1;
  }
}
void parserV2(int argc, char **argv, Flg *flags, char **files, char **patterns,
              int *error, int withBE) {
  int index_patterns = 0;
  int index_files = 0;
  int eflg = 0;
  int fflg = 0;
  int first = 1;
  for (int j = 1; j < argc && !*error; j++) {
    if (argv[j][0] == '-' && !*error) {
      for (int i = 1; argv[j][i] != '\0' && !*error; i++) {
        switcher(flags, argv[j][i], &eflg, &fflg, error);
        // parse -epat1 file
        if (eflg && argv[j][i + 1] && !*error) {
          add_to_patterns(argv[j] + i + 1, patterns, &index_patterns, error);
          eflg = 0;
          break;
        }
        // parse -fFILE
        if (fflg && argv[j][i + 1] && !*error) {
          add_to_patterns(argv[j] + i + 1, patterns, &index_patterns, error);
          fflg = 0;
          break;
        }
      }
      // parse -e pat file !!(if exists file)
      //      if (withBE && eflg && (!argv[j + 1] || !argv[j + 2])) *error = 1;
      if (withBE && eflg && !*error && argv[j + 1]) {
        add_to_patterns(argv[j + 1], patterns, &index_patterns, error);
        if (argv[j + 2] && argv[j + 2][0] != '-') {
          files[index_files] = argv[j + 2];
          index_files++;
          j += 2;
        } else {
          j += 1;
        }
      }
      // parse -f file !!(if exists file)
      if (withBE && fflg && !*error && argv[j + 1]) {
        flag_f_patterns(argv[j + 1], patterns, &index_patterns, error);
        j++;
      }
      eflg = 0;
      fflg = 0;
    } else {
      // parse example withoutEF (pattern file1 file2) withEF(file1 file2)
      if (!withBE && first && !*error) {
        add_to_patterns(argv[j], patterns, &index_patterns, error);
        first = 0;
      } else {
        files[index_files] = argv[j];
        index_files++;
      }
    }
  }
}

int behaviour(int argc, char **argv, int *error) {
  int flag = 0;
  for (int j = 1; j < argc && !flag && !*error; j++) {
    if (argv[j][0] == '-') {
      flag = 0;
      for (int i = 1; argv[j][i] != '\0' && !flag && !*error; i++) {
        switch (argv[j][i]) {
          case 0:
            break;
          case 'e':
            flag = 1;
            break;
          case 'i':
            break;
          case 'v':
            break;
          case 'c':
            break;
          case 'l':
            break;
          case 'n':
            break;
          case 'h':
            break;
          case 's':
            break;
          case 'f':
            flag = 1;
            break;
          case 'o':
            break;
          default:
            if (!flag) {
              fprintf(stderr,
                      "grep: invalid option -- %c\n"
                      "usage: grep [-abcDEFGHhIiJLlmnOoqRSsUVvwxZ] [-A num] "
                      "[-B num] [-C[num]]\n"
                      "        [-e pattern] [-f file] [--binary-files=value] "
                      "[--color=when]\n"
                      "        [--context[=num]] [--directories=action] "
                      "[--label] [--line-buffered]\n"
                      "        [--null] [pattern] [file ...]",
                      argv[j][i]);
              *error = 1;
            }
        }
      }
    }
  }
  return flag;
}

void flag_f_patterns(char *path, char **patterns, int *ind_pattern,
                     int *error) {
  FILE *test;
  char c;
  if ((test = fopen(path, "r")) != NULL) {
    while (!feof(test) && !*error) {
      char *string = calloc(1024, sizeof(char));
      if (string == NULL) {
        *error = 1;
      } else {
        fscanf(test, "%1024[^\n]%c", string, &c);
        if (strlen(string) == 0) {
          free(string);
          if (!feof(test)) {
            char *perenos = calloc(2, sizeof(char));
            if (perenos == NULL) {
              *error = 1;
            } else {
              strcpy(perenos, "\n");
              patterns[*ind_pattern] = perenos;
              fscanf(test, "%*[\n]");
            }
          }
        } else {
          patterns[*ind_pattern] = string;
        }
        *ind_pattern += 1;
      }
    }
    fclose(test);
  } else {
    fprintf(stderr, "grep: %s: No such file or directory\n", path);
  }
}

void cleaner(int argc, char **files, char **patterns) {
  for (int i = 0; i < argc; i++) {
    files[i] = 0;
    patterns[i] = 0;
  }
}