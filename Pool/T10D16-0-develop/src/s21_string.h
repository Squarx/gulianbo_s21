#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_
#include <stdio.h>
#include <stdlib.h>
int strl(char* str);
int cmp(char* str1, char* str2);
char* copy(char *str1, char *str2);
char* my_strcat(char* destination, char* source);
char* my_strchr(char* s, char c);
int compare(char *X, char *Y);
char* my_strstr(char* X, char* Y);
int is_delim(char c, char *delim);
char *strtok1(char *s, char *delim);
#endif  //  SRC_S21_STRING_H_
