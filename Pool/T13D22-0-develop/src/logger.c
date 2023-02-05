
#include "log_levels.h"
FILE* log_init(char *filename) {
    FILE* f;
    f = fopen(filename, "w+");
    return f;
}
int logcat(FILE* log_file, char *message, enum log_level level) {
    time_t now;
    time(&now);
    struct tm *l_time = localtime(&now);
    switch (level) {
        case 0 :
            fprintf(log_file, "| DEBUG | %02d:%02d:%02d | %s\n", l_time -> tm_hour,
            l_time -> tm_min, l_time -> tm_sec, message);
            break;
        case 1 :
            fprintf(log_file, "| TRACE | %02d:%02d:%02d | %s\n", l_time -> tm_hour,
            l_time -> tm_min, l_time -> tm_sec, message);
            break;
        case 2 :
            fprintf(log_file, "| INFO  | %02d:%02d:%02d | %s\n", l_time -> tm_hour,
            l_time -> tm_min, l_time -> tm_sec, message);
            break;
        case 3 :
            fprintf(log_file, "|WARNING| %02d:%02d:%02d | %s\n", l_time -> tm_hour,
            l_time -> tm_min, l_time -> tm_sec, message);
            break;
        case 4 :
            fprintf(log_file, "| EROOR | %02d:%02d:%02d | %s\n", l_time -> tm_hour,
            l_time -> tm_min, l_time -> tm_sec, message);
            break;
    }
    return 0;
}
int log_close(FILE* log_file) {
    int res = 1;
    if (fclose(log_file) == 0) {
        res = 0;
    }
    return res;
}
