#include <stdio.h>

#include "print_module.h"

char print_char(char ch)  {
    return putchar(ch);
}

void print_log(char(*print)(char), char* message) {
    char c;
    int hours, minutes, seconds;
    time_t now;
    time(&now);
    struct tm *l_time = localtime(&now);
    hours = l_time -> tm_hour;
    minutes = l_time -> tm_min;
    seconds = l_time -> tm_sec;
    printf("%s ", Log_prefix);
    printf("%02d:%02d:%02d ", hours, minutes, seconds);
    for (int i = 0; message[i] != '\n'; i++) {
        c = message[i];
        print(c);
    }
}
