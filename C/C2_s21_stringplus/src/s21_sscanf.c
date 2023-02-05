#include "s21_string.h"

int s21_sscanf(const char *str, const char *format, ...) {
  Fl flag_s = {0};
  va_list list = {0};
  if (!(int)s21_strlen(str)) {
    flag_s.count_scan = -1;
  } else {
    va_start(list, format);
    while (flag_s.end == 0 && flag_s.exit == 0) {
      parser(&flag_s, format, str);
      if (flag_s.exit == 0) {
        spec_check(&list, &flag_s, str);
      }
    }
    va_end(list);
  }
  return flag_s.count_scan;
}

void str_parsing(Fl *flag, va_list *list, const char *str) {
  if (flag->width == '*') {
    while (s21_strchr("\n\t\f\r ", str[flag->pos])) flag->pos++;
    for (int i = 0; !(tab_check(str[flag->pos])) && str[flag->pos] != ' ';
         i++) {
      flag->pos++;
    }
  } else {
    flag->count_scan++;
    if (flag->lengh == 'l') {
      flag->pointer = va_arg(*list, wchar_t *);
    } else {
      flag->pointer = va_arg(*list, char *);
    }
    int i = 0;
    for (; !(tab_check(str[flag->pos]) || str[flag->pos] == ' ') &&
           flag->width != 0;
         i++, flag->width--) {
      ((char *)flag->pointer)[i] = str[flag->pos++];
    }
    ((char *)flag->pointer)[i] = '\0';
  }
  if (tab_check(str[flag->pos])) flag->pos++;
}

void char_parsing(Fl *flag, va_list *list, const char *str) {
  while (flag->width != 0) {
    if (flag->width != '*') {
      flag->count_scan++;
      if (flag->lengh == 'l') {
        *va_arg(*list, wchar_t *) = (unsigned char)str[flag->pos];
      } else {
        *va_arg(*list, char *) = str[flag->pos];
      }
    }
    flag->pos++;
    flag->width = 0;
  }
}

void numb_parsing(Fl *flag, va_list *list, const char *str) {
  if (str[flag->pos] == '\0') {
    flag->exit = 1;
  } else {
    long int result = 0;
    char sign = '0';
    if (sign_check(str[flag->pos])) {
      sign = str[flag->pos++];
      if (numb_check(str[flag->pos]) && flag->width != '*') {
        flag->width--;
      } else {
        flag->width = '*';
      }
    }
    flag->error = 1;
    if (str[flag->pos] != '0' || flag->spec != 'i') {
      for (int i = flag->width;
           str[flag->pos] != ' ' && flag->exit == 0 && i != 0; i--) {
        flag->error = 0;
        if (numb_check(str[flag->pos])) {
          if (flag->width != '*') {
            result *= 10;
            result += (int)(str[flag->pos] - '0');
          }
          flag->pos++;
        } else {
          if (i == flag->width) {
            flag->width = '*';
            flag->exit = 1;
          }
          i = 1;
        }
      }
    }
    if (sign == '-') {
      result *= -1;
    }
    if (flag->error == 0) {
      add_to_list_for_numb(flag, list, result, 0);
    } else {
      flag->exit = 1;
    }
  }
}

void add_to_list_for_numb(Fl *flag, va_list *list, long int result,
                          long double d_result) {
  if (flag->width != '*') {
    if (flag->spec != 'n') flag->count_scan++;
    if (flag->spec == 'u') {
      if (flag->lengh == 'g') {
        *va_arg(*list, unsigned long long int *) =
            (unsigned long long int)result;
      } else if (flag->lengh == 'h') {
        *va_arg(*list, short unsigned int *) = (short unsigned int)result;
      } else if (flag->lengh == 'l') {
        *va_arg(*list, long unsigned int *) = (long unsigned int)result;
      } else {
        *va_arg(*list, unsigned int *) = (unsigned int)result;
      }
    } else if (notation_check(flag->spec)) {
      if (flag->lengh == 'L') {
        *va_arg(*list, long double *) = d_result;
      } else if (flag->lengh == 'l') {
        *va_arg(*list, double *) = (double)d_result;
      } else {
        *va_arg(*list, float *) = (float)d_result;
      }
    } else {
      if (flag->lengh == 'h') {
        *va_arg(*list, short int *) = (short int)result;
      } else if (flag->lengh == 'l') {
        *va_arg(*list, long int *) = result;
      } else if (flag->lengh == 'g') {
        *va_arg(*list, long long int *) = (long long int)result;
      } else {
        *va_arg(*list, int *) = (int)result;
      }
    }
  }
}

void numb_point_parsing(Fl *flag, va_list *list, const char *str) {
  char sign = '+';
  int flag_w = 0;
  if (flag->width == '*') flag_w = 1;
  if (sign_check(str[flag->pos])) {
    sign = str[flag->pos++];
    flag->width--;
  }
  if (str[flag->pos] != '\0') {
    long double result = 0;

    result_count(flag, str, &result, &flag_w);

    if (sign == '-') {
      result *= -1;
    }
    if (flag_w == 1) flag->width = '*';
    add_to_list_for_numb(flag, list, 0, result);
  }
}

void result_count(Fl *flag, const char *str, long double *result, int *flag_w) {
  for (int i = flag->width; str[flag->pos] != ' ' && flag->exit == 0 && i != 0;
       i--) {
    int len = 0;
    if (numb_check(str[flag->pos])) {
      *result *= 10;
      *result += (int)(str[flag->pos] - '0');
      flag->pos++;
    } else if (str[flag->pos] == '.' && (numb_check(str[flag->pos + 1]) ||
                                         numb_check(str[flag->pos - 1]))) {
      flag->pos++;
      flag->width--;
      while (numb_check(str[flag->pos]) && flag->width != 0) {
        *result *= 10;
        *result += str[flag->pos++] - '0';
        len++;
        flag->width--;
      }
      if (str[flag->pos] == 'e' || str[flag->pos] == 'E')
        if_e(flag, str, &len, result);
      result_mul(result, &len);
      i = 1;
    } else if (str[flag->pos] == 'e' || str[flag->pos] == 'E') {
      if_e(flag, str, &len, result);
      result_mul(result, &len);
      if (flag->width == 0) i = 1;
    } else {
      flag->exit = 1;
      if (i == (int)flag->width) *flag_w = 1;
    }
    flag->width--;
  }
}

void result_mul(long double *result, int *len) {
  while (*len > 0) {
    *result *= 0.1;
    *len -= 1;
  }
}

void if_e(Fl *flag, const char *str, int *len, long double *result) {
  char sign = '+';
  flag->width--;
  flag->pos++;
  if (sign_check(str[flag->pos])) {
    sign = str[flag->pos++];
    flag->width--;
  }
  if (numb_check(str[flag->pos]) && flag->width != 0) {
    int notation_len = 0;
    while (numb_check((int)str[flag->pos]) && flag->width != 0) {
      notation_len *= 10;
      notation_len += (int)(str[flag->pos++] - '0');
      flag->width--;
    }
    if (sign == '-') {
      *len += notation_len;
    } else {
      for (int k = notation_len; k > 0; k--) {
        *result *= 10;
      }
    }
  } else {
    flag->exit = 1;
  }
}

void sixteen_numb(Fl *flag, va_list *list, const char *str) {
  int flag_w = 0;
  if (flag->width == '*') flag_w = 1;
  if (str[flag->pos] != '\0') {
    unsigned long long int result = 0;
    int sign = 0;
    if (str[flag->pos] == '+') flag->pos++;
    if (str[flag->pos] == '-') {
      sign = 1;
      flag->pos++;
      if (flag->spec == 'p') flag->width = 1;
    }
    int len = numb_counter(flag, str, flag->pos);
    if (str[flag->pos] == '0' &&
        (str[flag->pos + 1] == 'x' || str[flag->pos + 1] == 'X')) {
      flag->pos += 2;
      len -= 2;
    }
    if (len > 16) {
      result = 4294967295;
      len = 0;
    }
    for (int i = len;
         str[flag->pos] != ' ' && flag->exit == 0 && i != 0 && flag->width != 0;
         i--, flag->width--) {
      int c = 0;
      c_check(flag, &c, str);
      if (flag->exit == 0) {
        result += ((int)(str[flag->pos] - c)) * s21_pow(16, len - 1);
        flag->pos++;
        len--;
      }
    }
    if (sign == 1) result = (unsigned long long)((long long)result * -1);
    flag->exit = 0;
    if (flag_w != 1 && len != -1) {
      flag->count_scan++;
      add_to_list_sixnumb(flag, list, result);
    }
  }
}

void c_check(Fl *flag, int *c, const char *str) {
  if (numb_check(str[flag->pos])) {
    *c = 48;
  } else if (abc_check(str[flag->pos])) {
    if (str[flag->pos] >= 'a' && str[flag->pos] <= 'f') {
      *c = 87;
    } else {
      *c = 55;
    }
  } else {
    flag->exit = 1;
  }
}

void add_to_list_sixnumb(Fl *flag, va_list *list,
                         unsigned long long int result) {
  if (flag->spec == 'p') {  // else i,x,X
    *((unsigned long long int *)va_arg(*list, void **)) = (0x0 + result);
  } else {
    if (flag->lengh == 'h') {
      *va_arg(*list, short int *) = (short int)result;
    } else if (flag->lengh == 'l') {
      *va_arg(*list, long int *) = (long int)result;
    } else if (flag->lengh == 'g') {
      if (flag->spec == 'x' || flag->spec == 'X') {
        *va_arg(*list, unsigned long long int *) = result;
      } else {
        *va_arg(*list, long long *) = (long long)result;
      }
    } else {
      *va_arg(*list, unsigned int *) = (unsigned int)result;
    }
  }
}

unsigned long long int s21_pow(int numb, int pow) {
  unsigned long long int result = 1;
  for (int i = 0; i < pow; i++) {
    result *= numb;
  }
  return result;
}
// TODO: correct to point count and width flag
int numb_counter(Fl *flags, const char *str, int pos) {
  int len = 0, flag = 0, flag1 = 0;
  int width = (int)flags->width;
  while (str[pos] != ' ' && str[pos] != '\0' && flag1 == 0 && width != 0) {
    if (str[pos] == '.' || flag == 1) {
      flag = 1;
      flags->len_point++;
    } else {
      if (numb_check(str[pos]) || abc_check(str[pos])) {
        if ((str[pos] != '9' && str[pos] != '8') || flags->spec != 'o') {
          len++;
        } else {
          flag1 = 1;
        }
      } else {
        flag1 = 1;
      }
    }
    pos++;
    width--;
  }
  return len == 0 ? -1 : len;
}

void type_check(Fl *flag, const char *str) {
  flag->type = 10;
  int i = flag->pos;
  if (sign_check(str[i])) i++;
  if (str[i++] == '0') {
    if (str[i] == 'x' || str[i] == 'X') {
      flag->type = 16;
    } else if (str[i] >= '0' && str[i] <= '7') {
      int flag_9 = 0;
      for (; str[i] != ' '; i++) {
        if (str[i] == '9') {
          flag_9 = 1;
        }
      }
      if (flag_9 == 0) {
        flag->type = 8;
      }
    }
  }
}

void eight_parsing(Fl *flag, va_list *list, const char *str) {
  int sign = 0;
  if (sign_check(str[flag->pos])) {
    if (str[flag->pos] == '-') sign = 1;
    flag->pos++;
    if (flag->width > 0) flag->width--;
  }
  long long int result = 0;
  int len = 0;
  len = numb_counter(flag, str, flag->pos) - 1;
  if (flag->width != -1 && len > flag->width) {
    len = flag->width - 1;
  }
  for (int i = (int)flag->width;
       str[flag->pos] != ' ' && flag->exit == 0 && i != 0; i--) {
    if ((str[flag->pos] >= '0' && str[flag->pos] <= '7') ||
        str[flag->pos] == '-') {
      result += (long long int)((int)(str[flag->pos] - '0') * s21_pow(8, len));
      flag->pos++;
    } else {
      if (len < 1 && result == 0 && i == flag->width) flag->width = '*';
      flag->exit = 1;
    }
    len--;
  }
  if (sign == 1) result *= -1;
  if (flag->width != '*') {
    flag->count_scan++;
    add_to_list_eightnumb(flag, list, result);
  }
}

void add_to_list_eightnumb(Fl *flag, va_list *list, long long int result) {
  if (flag->spec == 'o') {
    if (flag->lengh == 'h') {
      *va_arg(*list, short unsigned int *) = (short unsigned int)result;
    } else if (flag->lengh == 'l') {
      *va_arg(*list, unsigned long int *) = (unsigned long int)result;
    } else if (flag->lengh == 'g') {
      *va_arg(*list, unsigned long long int *) = (unsigned long long int)result;
    } else {
      *va_arg(*list, unsigned int *) = (unsigned int)result;
    }
  } else {  // i
    if (flag->lengh == 'h') {
      *va_arg(*list, short int *) = (short int)result;
    } else if (flag->lengh == 'l') {
      *va_arg(*list, long int *) = (long int)result;
    } else if (flag->lengh == 'g') {
      *va_arg(*list, long long int *) = result;
    } else {
      *va_arg(*list, int *) = (int)result;
    }
  }
}

void spec_check(va_list *list, Fl *flag, const char *str) {
  if (flag->spec != 'c' && (str[flag->pos] == ' ' || flag->pos != 0)) {
    while (str[flag->pos] == ' ' ||
           (str[flag->pos] == '\n' && str[flag->pos - 1] != '\\')) {
      flag->pos++;
    }
    if (str[flag->pos] == '\0' && flag->count_scan == 0) flag->count_scan = -1;
  }
  if (str[flag->pos] != '\0' || flag->spec == 'n') {
    if (flag->spec == 'c') {
      char_parsing(flag, list, str);
    } else if (flag->spec == 'd' || flag->spec == 'u') {
      numb_parsing(flag, list, str);
    } else if (flag->spec == 'i') {
      type_check(flag, str);
      if (flag->type == 10) {
        numb_parsing(flag, list, str);
      } else if (flag->type == 8) {
        eight_parsing(flag, list, str);
      } else if (flag->type == 16) {
        sixteen_numb(flag, list, str);
      }
    } else if (notation_check(flag->spec)) {
      numb_point_parsing(flag, list, str);
    } else if (flag->spec == 's') {
      str_parsing(flag, list, str);
    } else if (flag->spec == 'n') {
      if (flag->width != '*') {
        add_to_list_for_numb(flag, list, flag->pos, 0);
      }
    } else if (flag->spec == 'x' || flag->spec == 'X' || flag->spec == 'p') {
      sixteen_numb(flag, list, str);
    } else if (flag->spec == 'o') {
      eight_parsing(flag, list, str);
    } else {
      flag->exit = 1;
      flag->count_format++;
      fprintf(stderr, "Incorrect specificator");
    }
    flag->spec = 0;
    flag->width = 0;
    flag->lengh = 0;
  }
}

void parser(Fl *flag, const char *format, const char *str) {
  int i = flag->count_format;
  while (format[i] != '%' && format[i] != '\0') {
    if (tab_check(format[i]) || format[i] == ' ') {
      while (str[flag->pos] != '\0' &&
             (tab_check(str[flag->pos]) || str[flag->pos] == ' '))
        flag->pos++;
    } else if (format[i] == str[flag->pos]) {
      flag->pos++;
    } else if (format[i] != ' ') {
      flag->exit = 1;
    }
    i++;
  }
  if (format[i + 1] == '%' && format[i + 2] == '%' && str[flag->pos] == '%') {
    i += 2;
    flag->pos++;
  }
  if (format[i] == '%') i++;
  if (format[i] != '\0') {
    if (format[i] == '*') {
      flag->width = '*';
      i++;
    } else if (numb_check(format[i])) {
      while (numb_check(format[i])) {
        flag->width *= 10;
        flag->width += (int)(format[i++] - '0');
      }
    }
    if (format[i] == 'l' || format[i] == 'L' || format[i] == 'h') {
      if (format[i] == 'l' && format[i + 1] == 'l') {
        flag->lengh = 'g';
        i += 2;
      } else {
        flag->lengh = format[i++];
      }
    }
    if (spec_letter_check(format[i])) {
      flag->spec = format[i++];
    }
  }
  if (format[i] != '\0') {
    flag->count_format = i;
  } else {
    flag->end = 1;
  }
  if (flag->width == 0) flag->width--;
}
