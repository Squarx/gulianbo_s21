#ifndef SRC_LOGGER_H_
#define SRC_LOGGER_H_
#include  <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "log_levels.h"
FILE* log_init(char *filename);
int logcat(FILE* log_file, char *message, enum log_level level);
int log_close(FILE* log_file);
#endif  // SRC_LOGGER_H_
