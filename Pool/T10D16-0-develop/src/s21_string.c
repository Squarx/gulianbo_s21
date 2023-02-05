#include "s21_string.h"
int strl(char* str) {
  int length = 0;
  for (; *(str + length); length++) {
    continue;
  }
  return length;
}
int cmp(char* str1, char* str2) {
    int res = 0;
    for (; *str1 && *str1 == *str2; str1++, str2++)
    if (*str1-*str2 > 0) {
        res = 1;
    }
    if (*str1-*str2 < 0) {
        res = -1;
    }
    if (*str1-*str2 == 0) {
        res = 0;
    }
    return res;
}
char* copy(char *str1, char *str2) {
  int a = strl(str2);
  str1 = malloc (a * sizeof(char));
  char *addres = str1;
    while ( *str2 != '\0' ) {
        *str1++ = *str2++;
    }
        return addres;
}

char* my_strcat(char* source, char* destination) {
    char* ptr = malloc((strl(destination) + strl(source)) * sizeof(char));
    for (int i = 0; i < strl(source); i++) {
        ptr[i] = source[i];
    }
    for (int i = strl(source), y = 0; i < (strl(destination) + strl(source)); i++, y++) {
        ptr[i] = destination[y];
    }
    return ptr;
}
char* my_strchr(char* s, char c) {
    char* p = NULL;
    while (*s) {
      if (*s == c) {
        p = s;
        break;
        } else {
          s++;
          }
    }
    return p;
}
int compare(char *X, char *Y) {
    while (*X && *Y) {
        if (*X != *Y) {
            break;
        }
        X++;
        Y++;
    }
    return (*Y == '\0');
}
char* my_strstr(char* X, char* Y) {
    char* p = NULL;
    while (*X != '\0') {
        if ((*X == *Y) && compare(X, Y)) {
            p = X;
            break;
        }
        X++;
    }
    return p;
}
int is_delim(char c, char *delim) {
    int x = 0;
  while (*delim != '\0') {
    if (c == *delim) {
      x = 1;
      break;
    }
    delim++;
  }
  return x;
}
char *strtok1(char *str, char *delim) {
    static char *last_str = NULL;
    if (str == NULL) {
        str = last_str;
    }
    if (str == NULL) {
        return NULL;
    }
    int i = 0;
    int j = 0;
    int k = 0;
    int is_delim = 0;
    while (str[i] != '\0') {
        is_delim = 0;
        j = 0;
        while (delim[j] != '\0') {
            if (str[i] == delim[j]) {
                is_delim = 1;
                break;
            }
            j++;
        }
        if (!is_delim) {
            break;
        }
        i++;
    }
    if (str[i] == '\0') {
        last_str = NULL;
        return NULL;
    }
    last_str = str + i;
    while (last_str[k] != '\0') {
        is_delim = 0;
        j = 0;
        while (delim[j] != '\0') {
            if (last_str[k] == delim[j]) {
                is_delim = 1;
                break;
            }
            j++;
        }
        if (is_delim) {
            break;
        }
        k++;
    }
    if (last_str[k] == '\0') {
        last_str = NULL;
    } else {
        last_str[k] = '\0';
        last_str = last_str + k + 1;
    }
    return str + i;
}

