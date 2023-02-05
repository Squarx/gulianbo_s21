#include "s21_string.h"

int s21_sprintf(char *str, const char *format, ...) {
  s21_memset(str, 0, sizeof(str));
  char *start = s21_NULL;
  start = str;
  char *curs_str = s21_NULL;
  curs_str = str;

  if (str != s21_NULL && format != s21_NULL) {
    va_list curr_arg;
    va_start(curr_arg, format);
    char *sym_format = (char *)format;
    int index_str = 0;
    for (int i = 0; *sym_format && *sym_format != '\0'; i++) {
      if (*sym_format != '%') {
        *curs_str++ = *sym_format++;
        index_str++;
      } else {
        OPT opt = {0};
        sym_format++;
        sym_format = fill_struct(sym_format, &opt, &curr_arg);
        //        printf("width %d\n", opt.width);
        if (opt.specifier != '\0') {
          if (opt.specifier != 'n') {
            curs_str = write_to_arr(curs_str, opt, &curr_arg);
          } else {
            int for_n = 0;
            for_n = (int)(curs_str - start);
            int *num = va_arg(curr_arg, int *);
            *num = for_n;
          }
        } else {
          char c = '\0';
          c = *(sym_format++);
          opt.specifier = 'c';
          curs_str = i_hate_flag_c(c, curs_str, opt);
        }
      }
    }
    va_end(curr_arg);
  }
  *(curs_str) = '\0';
  return (int)(curs_str - start);
}

//
/**
 * @brief add to token width
 * @param src
 * @param opt_orig
 * " Для спецификаторов c d "
 * @example src  = [+00123] width = 10 '!-' src = [    +00123] (10 chars)
 * @example src  = [+00123] width = 10 '-' src =  [+00123    ] (10 chars)
 * " Для остальных  еще есть заполнитель 0 "
 */
void add_width(char *src, OPT *opt_orig) {
  char tmp[500] = {0};
  int ind_tmp = 0;
  int ind_src = 0;
  int len_src = (int)my_strlen(src);
  if (opt_orig->width > len_src) {
    char zapoln = (opt_orig->f_zero) ? '0' : ' ';
    if (!opt_orig->f_minus) {
      if (opt_orig->f_zero && *src != '\0' &&
          (my_strchr("+ -", src[ind_src]) !=
           s21_NULL)) {  // костыли для спецификторов E e
        tmp[ind_tmp++] = src[ind_src++];
      }
      for (int i = 0; i < opt_orig->width - len_src; i++) {
        tmp[ind_tmp++] = zapoln;
        my_memcpy(&tmp[ind_tmp], &src[ind_src], len_src);
      }
    } else {
      my_memcpy(&tmp[ind_tmp], src, len_src);
      ind_tmp += len_src;
      for (int i = ind_tmp; i < opt_orig->width; i++) {
        tmp[ind_tmp++] = ' ';
      }
    }
  }
  my_memcpy(src, tmp, my_strlen(tmp));
}
/**
 * @brief add to src char
 * @param src
 * @param opt_orig
 * @example src = [6,1,2] "+" => [+,6,1,2]
 * @example src = [6,1,2] "+ " = > [+6,1,2]
 * @example src = [6,1,2] " " = > [ ,6,1,2]
 * @example src = [-,6,1,2] "+ " = > [-,6,1,2]
 */
void add_sign(char *src, OPT *opt_orig) {
  char sign = '\0';
  if (*src != '-') {
    if (opt_orig->f_plus)
      sign = '+';
    else if (opt_orig->f_space)
      sign = ' ';
  }
  if (sign != '\0') {
    if (*src != '\0') my_memmove(&src[1], src, my_strlen(src));
    src[0] = sign;
  }
}
/**
 *
 * @param src токен [1,2,4] [-,2,4,5]
 * @param opt_orig
 * @return в src добавляются ведущие нули до точности
 * @example src = [-,5] acc = 2 => [-,0 ,5]
 * * @example src = [5] acc = 2 => [0 ,5]
 */
void add_accur_dui(char *src, OPT *opt_orig) {
  char tmp[500] = {0};
  int ind_tmp = 0;
  if (*src != '-' && *src != ' ' && *src != '+') {
    int len_src = 0;
    len_src = (int)my_strlen(src);
    if (len_src < opt_orig->accuracy) {
      for (int i = 0; i < opt_orig->accuracy - len_src; i++) {
        tmp[ind_tmp++] = '0';
      }
      my_memcpy(&tmp[ind_tmp], src, len_src);
      my_memcpy(src, tmp, my_strlen(tmp));
    }
  } else {
    add_accur_dui(&src[1], opt_orig);
  }
}

/**
 *
 * @param num +- num
 * @param string
 * @param opt_orig
 * @return -12345 string = [-,1,2,3,4,5]
 */
void my_itoa(long double num, char *string) {
  if (num >= 0) {
    make_token_d((unsigned long long)num, string);
  } else {
    *string++ = '-';
    make_token_d((unsigned long long)(-num), string);
  }
}

char *mem_reverse(char *arr, int n) {
  char tmp[800] = {0};
  int i = 0;
  for (; n >= 0; tmp[i] = arr[n], i++, n--)
    ;
  for (int j = 0; tmp[j] && arr[j]; arr[j] = tmp[j], j++)
    ;
  return arr;
}

/**
 *
 * @param num UNSIGNED -5 == 18446744073709551611
 * @param string
 * @param opt_orig
 * @return write  unsigned num to string
 */
void make_token_d(unsigned long long num, char *string) {
  unsigned long long closest = 0;
  int ind_str = 0;
  closest = get_closestULL(num, 10Ull);
  while (closest > 0) {
    string[ind_str++] = (char)(num - closest + 48Ull);
    num /= 10;
    closest = get_closestULL(num, 10Ull);
  }
  string[ind_str] = (char)(num + 48Ull);
  mem_reverse(&string[0], ind_str);
  //  printf("str = %s\n", string);
}
unsigned long long get_closestULL(unsigned long long num,
                                  unsigned long long delitel) {
  unsigned long long closest = delitel;
  if (num > closest) {
    closest = (unsigned long long)(num / delitel);
    closest = closest * delitel;
  } else {
    if (num == delitel)
      closest = delitel;
    else
      closest = 0;
  }
  return closest;
}

/**
 *
 * @param num - long double
 * @return меняет num на формат (1-9).дробная часть 9123 => (9.123)
 * @return степень 10-ки, поделив/умножив на которую получим начальное 9.123 *
 * 10^return  = 9123
 * @return сколько раз он поделил на 10 !!!!!
 */
int make_mantissa(long double *num) {
  int cnt_of_pow = 0;
  if (*num != 0) {
    if (*num < 1) {
      for (; *num < 1; cnt_of_pow--) {
        *num *= 10;
      }
    } else {
      for (; *num >= 10; cnt_of_pow++) {
        *num /= 10;
      }
    }
  }
  return cnt_of_pow;
}
/**
 * @brief по сути для определения +0 или -0
 * @param num
 * @return
 */
int positive(long double num) {
  double b = (double)num;
  int c = (((*((long long *)&b)) & ((long long)1 << 63)) == 0);
  return c;
}

/**
 * @brief ONLY for e || E (have cnt of pow => -e10 +e10 can be changed)
 * @param tmp
 * @param accuracy
 * @param cnt_of_pow
 */
void round_array(char *tmp, int accuracy, int *cnt_of_pow) {
  int perenos = 1;
  int start = 0;
  if (*tmp == '-') start = 1;
  for (int i = accuracy; i > start && perenos; i--) {
    if ((int)tmp[i] - 48 + perenos >= 10) {
      tmp[i] = (char)(tmp[i] + perenos - 10);
    } else {
      //        printf("tmp + i = %c\n", (int) tmp[i] + perenos);
      tmp[i] = (char)(tmp[i] + perenos);
      perenos--;
    }
  }
  if (tmp[start] - 48 + perenos >= 10) {
    tmp[start] = '1';
    *cnt_of_pow += 1;
  } else {
    tmp[start] = (char)(tmp[start] + perenos);
  }
}
/**
 * @brief Special for %f
 * @brief  округляет числа че то куда то и двигатет при переполенеии
 * @param tmp
 * @param ind_start_round  - 1 начало add perenos
 * @param ind_tmp_start_num for [-, num] = 1 for [num] = 0
 * @param ind_last_int адрес количества знаков целой части :: при переполении
 * двигается все => ++;
 */
void round_float(char *tmp, int ind_start_round, int ind_tmp_start_num,
                 int *ind_last_int) {
  //  if (tmp[ind_tmp_start_num] == '-') ind_tmp_start_num++;
  int perenos = 1;
  for (int i = ind_start_round - 1; i > ind_tmp_start_num && perenos; i--) {
    if ((int)tmp[i] - 48 + perenos >= 10) {
      tmp[i] = (char)(tmp[i] + perenos - 10);
    } else {
      tmp[i] = (char)(tmp[i] + perenos);
      perenos--;
    }
  }
  if (tmp[ind_tmp_start_num] - 48 + perenos >= 10) {
    tmp[ind_tmp_start_num] = '1';
    my_memmove(&tmp[ind_tmp_start_num + 2], &tmp[ind_tmp_start_num + 1],
               my_strlen(&tmp[ind_tmp_start_num + 1]));
    tmp[ind_tmp_start_num + 1] = '0';
    (*ind_last_int)++;
  } else {
    tmp[ind_tmp_start_num] = (char)(tmp[ind_tmp_start_num] + perenos);
  }
}
/**
 * @brief  записывет дробную часть в массив как цифры
 * @example num  = 0.009123 = > tmp = [0,0,9,0,1,2,3]
 * @param num
 * @param tmp
 * @param ind_tmp
 * @param opt
 */
void make_float_to_arr(long double num, char *tmp, int *ind_tmp, OPT *opt) {
  for (int i = 0; i < opt->accuracy + 10; i++) {
    num = num * 10;
    tmp[(*ind_tmp)++] = (char)((int)num + 48);
    num = (long double)(num - (int)num);
  }
}
/**
 * @brief вставляет на место before dst '.'
 * @example dest = [9,2,3] => [.,9,2,3]
 * @param dest
 */
void insert_dot(char *dest) {
  my_memmove(&dest[1], dest, my_strlen(dest));
  dest[0] = '.';
}

void get_rid_zero(char *tmp, OPT *opt) {
  int index_exp = 0;
  int index_dot = 0;
  char *address_exp = s21_NULL;
  char *address_dot = s21_NULL;
  if (opt->specifier == 'e') address_exp = my_strchr(tmp, 'e');
  if (opt->specifier == 'E') address_exp = my_strchr(tmp, 'E');
  if (opt->specifier == 'f') address_exp = &tmp[my_strlen(tmp)];
  index_exp = (int)(address_exp - tmp);
  address_dot = my_strchr(tmp, '.');
  index_dot = (int)(address_dot - tmp);
  char *end_tmp = s21_NULL;
  if (tmp[index_exp - 1] == '0') {
    for (int i = index_exp - 1; i >= index_dot && end_tmp == s21_NULL; i--) {
      if (tmp[i] != '0') end_tmp = &tmp[i];
    }
  }
  if (end_tmp != s21_NULL && *(end_tmp) != '.') end_tmp++;
  if (end_tmp != s21_NULL) {
    int index_last_char = (int)(end_tmp - tmp);
    my_memcpy(&tmp[index_last_char], address_exp, my_strlen(address_exp));
    s21_memset(&tmp[index_last_char + (int)my_strlen(address_exp)], 0,
               my_strlen(&tmp[index_last_char + (int)my_strlen(address_exp)]));
  }
}

char *convert_to_8(char *dest, unsigned long long num) {
  int ind = 0;
  unsigned long long closest = get_closestULL(num, 8Ull);
  int to_arr;
  while (closest > 0) {
    to_arr = (int)(num - closest);
    dest[ind++] = (char)(to_arr + 48);
    num = closest / 8;
    closest = get_closestULL(num, 8ULL);
  }
  dest[ind++] = (char)(num + 48);
  dest[ind++] = '\0';
  mem_reverse(dest, (int)my_strlen(dest) - 1);
  return dest;
}
void insert_flag_sharp(char *tmp, OPT *opt) {
  if (opt->specifier == 'o' && opt->f_sharp && *tmp != '0') {
    my_memmove(&tmp[1], tmp, my_strlen(tmp));
    tmp[0] = '0';
  }
  if ((opt->specifier == 'x' || opt->specifier == 'X') && opt->f_sharp) {
    my_memmove(&tmp[2], tmp, my_strlen(tmp));
    tmp[0] = '0';
    tmp[1] = opt->specifier == 'x' ? 'x' : 'X';
  }
}
char *convert_to_16(char *dest, unsigned long long num, char capital) {
  int ind = 0;
  int cap = 32;
  if (capital == 'X') cap = 0;
  unsigned long long closest = get_closestULL(num, 16);
  int to_arr;
  while (closest > 0) {
    to_arr = (int)(num - closest);
    dest[ind++] = (char)(to_arr < 10 ? (to_arr + 48) : (to_arr + 55 + cap));
    num = closest / 16;
    closest = get_closestULL(num, 16);
  }
  dest[ind++] = (char)(num < 10 ? (num + 48) : (num + 55 + cap));
  dest[ind++] = '\0';
  mem_reverse(dest, ((int)my_strlen(dest) - 1));
  return dest;
}

void make_ready_u(char *src, OPT *opt_orig) {
  char tmp[500] = {0};
  int ind_tmp = 0;
  // именно к src прибавляем 000 в начало
  add_accur_dui(src, opt_orig);

  int len_src = (int)my_strlen(src);
  if (opt_orig->width > len_src) {
    char zapoln = (opt_orig->f_zero && opt_orig->accuracy == -1) ? '0' : ' ';
    if (!opt_orig->f_minus) {
      for (int i = 0; i < opt_orig->width - len_src; i++) {
        tmp[ind_tmp++] = zapoln;
        my_memcpy(&tmp[ind_tmp], src, len_src);
      }
    } else {
      my_memcpy(&tmp[ind_tmp], src, len_src);
      ind_tmp += len_src;
      for (int i = ind_tmp; i < opt_orig->width; i++) {
        tmp[ind_tmp++] = zapoln;
      }
    }
  }
  my_memcpy(src, tmp, my_strlen(tmp));
}

char *get_flag(char *cursor, OPT *options) {
  while (my_strchr("-+ #0", *cursor) != s21_NULL) {
    if (*cursor == '-' && !options->f_minus) options->f_minus = 1;
    if (*cursor == '+' && !options->f_plus) options->f_plus = 1;
    if (*cursor == ' ' && !options->f_space) options->f_space = 1;
    if (*cursor == '#' && !options->f_sharp) options->f_sharp = 1;
    if (*cursor == '0' && !options->f_zero) options->f_zero = 1;
    cursor += 1;
  }
  return cursor;
}
/**
 * @brief get width from cursor/ if there is NO width => width = 0 (default)
 * @param cursor
 * @param options
 * @param curr_arg
 * @return
 */
char *get_width(char *cursor, OPT *options, va_list *curr_arg) {
  if (*cursor != '*') {
    for (int i = 0; my_strchr("0123456789", *cursor); cursor++, i++)
      options->width = 10 * options->width + (int)(*cursor - 48);
  } else {
    options->width = (int)va_arg(*curr_arg, int);
    if (options->width < 0) {
      options->width = -options->width;
      if (options->f_minus == 0) options->f_minus = 1;
    }
    cursor++;
  }
  return cursor;
}
/**
 * @brief get accuracy from cursor/ if there is NO accuracy => examples
 * @param cursor
 * @param options
 * @param curr_arg
 * @var options-> accuracy  => INT
 * @example NO accuracy at ALL |%d| accuracy = -1 (default = 0!!!!! usually
 * convert to 6)
 * @example '.'               |%.d| accuracy = 0
 * @example '.25'             |%.25d| accuracy = 25
 * @return
 */
char *get_accur(char *cursor, OPT *options, va_list *curr_arg) {
  options->accuracy = -1;
  if (*cursor == '.') {
    options->accuracy = 0;
    if (*++cursor != '*') {
      for (int i = 0; my_strchr("0123456789", *cursor); cursor++, i++)
        options->accuracy = 10 * options->accuracy + (int)(*cursor - 48);
    } else {
      options->accuracy = (int)va_arg(*curr_arg, int);
      if (options->accuracy < 0) {
        options->accuracy = 6;
        //        options->f_minus = 0;
      }
      cursor++;
    }
  }
  return cursor;
}

/**
 * @brief get len from cursor// if NO len => length = '\0' (default)
 * @param cursor
 * @param options
 * @return
 */
char *get_len(char *cursor, OPT *options) {
  if (my_strchr("hlL", *cursor)) options->length = (char)*cursor++;
  return cursor;
}
/**
 * @brief get spec from cursor// if NO spec => spec = '\0' (default)
 * @param cursor
 * @param options
 * @return
 */
char *get_spec(char *cursor, OPT *options) {
  if (my_strchr("cdieEfgGosuxXpn%", *cursor)) options->specifier = *cursor++;
  return cursor;
}

char *fill_struct(char *cursor, OPT *opt, va_list *curr_arg) {
  cursor = get_flag(cursor, opt);
  cursor = get_width(cursor, opt, curr_arg);
  cursor = get_accur(cursor, opt, curr_arg);
  cursor = get_len(cursor, opt);
  cursor = get_spec(
      cursor, opt);  // выставка курсора чтения символов строки после парсинга
  return cursor;
}

char *i_hate_flag_c(int c, char *string, OPT opt) {
  int ind_tmp = 0;
  char tmp_char[1000] = {0};
  if (c != '\0') {
    tmp_char[ind_tmp++] = (char)c;
    //    opt.accuracy = -1;
    //#if !(defined __APPLE__ || defined __MACH__)
    //      opt.f_zero = 0;
    //#endif
    add_width(tmp_char, &opt);

    int len_tmp = (int)my_strlen(tmp_char);
    my_memcpy(string, tmp_char, len_tmp);

    string += len_tmp;
  } else {
    //#if defined __APPLE__ || defined __MACH__
    if (!opt.f_minus) {
      opt.f_zero = 0;
      opt.width -= 1;
      add_width(tmp_char, &opt);
      int len_tmp = (int)my_strlen(tmp_char) + 1;
      my_memcpy(string, tmp_char, len_tmp + 1);
      string += len_tmp;
    } else {
      opt.f_zero = 0;
      opt.width -= 1;
      add_width(tmp_char, &opt);
      int len_tmp = (int)my_strlen(tmp_char) + 1;
      *string = '\0';
      string += len_tmp;
    }
    //#else
    //      *string++ = '\0';
    //#endif
  }
  return string;
}

char *write_to_arr(char *string, OPT opt, va_list *curr_arg) {
  if (opt.specifier == 'c') {
    char c = (char)va_arg(*curr_arg, int);
    string = i_hate_flag_c(c, string, opt);
  }
  if (opt.specifier == 'd' || opt.specifier == 'i') {
    long long int num = 0;
    if (!opt.length) num = (int)va_arg(*curr_arg, int);
    if (opt.length == 'h') num = (short int)va_arg(*curr_arg, int);
    if (opt.length == 'l') num = (long int)va_arg(*curr_arg, long int);
    char num_str[1000] = {0};
    if (!(num == 0 && opt.accuracy == 0))
      my_itoa(num, num_str);  // Win возможно на мак4е по другому
    add_sign(num_str, &opt);
    if (opt.accuracy != -1) opt.f_zero = 0;
    add_accur_dui(num_str, &opt);
    add_width(num_str, &opt);
    //    my_strcat(string, num_str);
    my_memcpy(string, num_str, my_strlen(num_str));
    string += (int)my_strlen(num_str);
  }
  if (opt.specifier == 'e' || opt.specifier == 'E' || opt.specifier == 'f' ||
      opt.specifier == 'g' || opt.specifier == 'G') {
    long double num = 0;
    int nan = 0;
    int inf = 0;
    int pos = 0;
    if (opt.accuracy == -1) opt.accuracy = 6;
    if (opt.length == 'L') {
      num = (long double)va_arg(*curr_arg, long double);
    } else {
      num = (double)va_arg(*curr_arg, double);
    }
    nan = isnan(num);
    inf = isinf(num);
    pos = positive(num);
    if (!nan && !inf) {
      if (opt.specifier == 'f') {
        string = i_hate_flag_f(num, string, &opt);
      } else if (opt.specifier == 'e' || opt.specifier == 'E') {
        string = i_hate_flag_e(num, string, &opt);
      } else {
        if (opt.accuracy == 0) opt.accuracy = 1;
        string = i_hate_flag_g(num, string, &opt);
      }
    } else {
      opt.f_zero = 0;
      opt.accuracy = -1;
      if (nan) {
        string = i_hate_flag_s("nan", string, &opt);
      }
      if (inf) {
        if (pos) {
          string = opt.f_plus ? i_hate_flag_s("+inf", string, &opt)
                              : i_hate_flag_s("inf", string, &opt);
        } else {
          string = i_hate_flag_s("-inf", string, &opt);
        }
      }
    }
  }
  if (opt.specifier == 'o' || opt.specifier == 'x' || opt.specifier == 'X' ||
      opt.specifier == 'u') {
    long double num = 0;
    if (opt.length == 'h') num = (short int)va_arg(*curr_arg, int);
    if (opt.length == 'l') num = (long int)va_arg(*curr_arg, long int);
    if (!opt.length) num = (int)va_arg(*curr_arg, int);
    if (num != num) num = 0;
    if (isinf(num)) num = 0;
    if (opt.specifier == 'o') {
      string = i_hate_flag_o(num, string, &opt);
    } else if (opt.specifier == 'u') {
      string = i_hate_flag_u((unsigned long long)num, string, &opt);
    } else {
      string = i_hate_flag_X(num, string, &opt);
    }
  }
  if (opt.specifier == 'p') {
    long long num = 0;
    num = (long long)va_arg(*curr_arg, long long);
    string = i_hate_flag_p(num, string, &opt);
  }
  if (opt.specifier == 's') {
    char *src = va_arg(*curr_arg, char *);
    string = i_hate_flag_s(src, string, &opt);
  }
  if (opt.specifier == '%') {
    string = i_hate_flag_percent(string, &opt);
  }
  return string;
}
char *i_hate_flag_percent(char *string, OPT *opt_orig) {
  char tmp[500] = {0};
  int ind_tmp = 0;
  tmp[ind_tmp++] = '%';
  add_width(tmp, opt_orig);

  my_memcpy(string, tmp, my_strlen(tmp));
  string += (int)my_strlen(tmp);
  return string;
}
char *i_hate_flag_u(unsigned long long num, char *string, OPT *opt_orig) {
  int ind_str = 0;

  char tmp[500] = {0};
  if (opt_orig->length == 'l') make_token_d(num, tmp);
  if (opt_orig->length == 'h') make_token_d((unsigned short)num, tmp);
  if (!opt_orig->length) make_token_d((unsigned int)num, tmp);
  make_ready_u(tmp, opt_orig);
  int ready = (int)my_strlen(tmp);
  my_memcpy(string, tmp, ready);
  ind_str += ready;
  return &string[ind_str];
}

char *i_hate_flag_s(char *src, char *dest, OPT *opt_orig) {
  int ind_dest = 0;
  char tmp[500] = {0};
  if (src != s21_NULL) {
    if (opt_orig->accuracy < 0 || opt_orig->accuracy > (int)my_strlen(src)) {
      opt_orig->accuracy = (int)my_strlen(src);
    }
    my_memcpy(tmp, src, (s21_size_t)opt_orig->accuracy);
    add_width(tmp, opt_orig);

    my_memcpy(dest, tmp, my_strlen(tmp));
    ind_dest = (int)my_strlen(tmp);
  } else {
    dest = i_hate_flag_s("(null)", dest, opt_orig);
  }
  return src == NULL ? dest : &dest[ind_dest];
}

char *i_hate_flag_p(long double num, char *string, OPT *opt_orig) {
  char tmp[500] = {0};
  int ind_str = 0;
  int ind_tmp = 0;
  i_hate_flag_X(num, &tmp[ind_tmp], opt_orig);
  int len_tmp = (int)my_strlen(tmp);
  my_memcpy(string, tmp, (s21_size_t)len_tmp);
  ind_str += len_tmp;
  return &string[ind_str];
}

char *i_hate_flag_X(unsigned long long num, char *string, OPT *opt_orig) {
  if (num == 0) opt_orig->f_sharp = 0;
  if (opt_orig->specifier == 'p') {
    opt_orig->f_sharp = 1;
    opt_orig->specifier = 'x';
    opt_orig->length = 'l';
  }
  int ind_str = 0;
  char tmp[500] = {0};
  if (!(num == 0 && opt_orig->accuracy == 0)) {
    if (opt_orig->length == 'l' || opt_orig->length == 'L')
      convert_to_16(tmp, num, opt_orig->specifier);
    if (!opt_orig->length)
      convert_to_16(tmp, (unsigned)num, opt_orig->specifier);
    if (opt_orig->length == 'h')
      convert_to_16(tmp, (unsigned short)num, opt_orig->specifier);
    if (opt_orig->accuracy == -1) {  // точности нет даже .
      if (!opt_orig->f_zero) {       // %#10
        insert_flag_sharp(tmp, opt_orig);
        add_width(tmp, opt_orig);
        my_memcpy(&string[ind_str], tmp, my_strlen(tmp));
        ind_str += (int)my_strlen(tmp);
      } else {
        if (opt_orig->f_sharp) {
          opt_orig->width -= 2;
          add_width(tmp, opt_orig);
          insert_flag_sharp(tmp, opt_orig);
          my_memcpy(&string[ind_str], tmp, my_strlen(tmp));
          ind_str += (int)my_strlen(tmp);
        } else {
          add_width(tmp, opt_orig);
          my_memcpy(&string[ind_str], tmp, my_strlen(tmp));
          ind_str += (int)my_strlen(tmp);
        }
      }
    } else {
      opt_orig->f_zero = 0;  // нет реакции ширины на флаг 0
      add_accur_dui(tmp, opt_orig);
      insert_flag_sharp(tmp, opt_orig);
      add_width(tmp, opt_orig);
      my_memcpy(&string[ind_str], tmp, my_strlen(tmp));
      ind_str += my_strlen(tmp);
    }
  }
  return &string[ind_str];
}
char *i_hate_flag_o(long double num, char *string, OPT *opt_orig) {
  int ind_str = 0;
  char tmp[500] = {0};
  if (!(num == 0 && opt_orig->accuracy == 0)) {
    if (opt_orig->length == 'l' || opt_orig->length == 'L')
      convert_to_8(tmp, num);
    if (!opt_orig->length) convert_to_8(tmp, (unsigned)num);
    if (opt_orig->length == 'h') convert_to_8(tmp, (unsigned short)num);
    if (opt_orig->accuracy != -1) opt_orig->f_zero = 0;
    add_accur_dui(tmp, opt_orig);
    insert_flag_sharp(tmp, opt_orig);
    add_width(tmp, opt_orig);
    my_memcpy(&string[ind_str], tmp, my_strlen(tmp));
    ind_str += (int)my_strlen(tmp);
  }
  return &string[ind_str];
}

char *i_hate_flag_g(long double num, char *string, OPT *opt_orig) {
  char tmp[500] = {0};
  long double tmp_num = 0;
  tmp_num = num < 0 ? -num : num;
  int tmp_pow = 0;
  tmp_pow = make_mantissa(&tmp_num);
  if (num != 0 && (tmp_pow < -4 || tmp_pow >= opt_orig->accuracy)) {
    if (opt_orig->specifier == 'g')
      opt_orig->specifier = 'e';
    else
      opt_orig->specifier = 'E';
    opt_orig->accuracy -= 1;
    i_hate_flag_e(num, tmp, opt_orig);
    if (!opt_orig->f_sharp) get_rid_zero(tmp, opt_orig);
    add_width(tmp, opt_orig);
    my_memcpy(string, tmp, my_strlen(tmp));
    string += (int)my_strlen(tmp);
  } else {
    opt_orig->accuracy -= (tmp_pow + 1);
    //    printf("here=  %d\n", opt_orig->accuracy);
    opt_orig->specifier = 'f';
    i_hate_flag_f(num, tmp, opt_orig);
    if (!opt_orig->f_sharp) get_rid_zero(tmp, opt_orig);
    add_width(tmp, opt_orig);
    my_memcpy(string, tmp, my_strlen(tmp));
    string += (int)my_strlen(tmp);
  }
  return string;
}

char *i_hate_flag_e(long double num, char *string, OPT *opt) {
  char tmp[1000] = {0};
  int ind_tmp = 0;
  int pow = 0;
  if (!positive(num)) {
    num = -num;
    tmp[ind_tmp++] = '-';
  }
  pow = make_mantissa(&num);
  tmp[ind_tmp++] = (char)((int)num + 48);
  num = (long double)(num - (int)num);
  make_float_to_arr(num, tmp, &ind_tmp, opt);
  int round_last = 0;  // округление массива
  int ind_start_round = opt->accuracy + 1;
  int ind_exp = 0;
  if (*tmp == '-') ind_start_round += 1;
  round_last = (tmp[ind_start_round] >= '5');
  if (round_last) round_array(tmp, ind_start_round - 1, &pow);
  if (*tmp != '-') {
    my_memmove(&tmp[2], &tmp[1], my_strlen(&tmp[1]));
    tmp[1] = '.';
    ind_exp = 2;
  } else {
    my_memmove(&tmp[3], &tmp[2], my_strlen(&tmp[2]));
    tmp[2] = '.';
    ind_exp = 3;
  }

  //готова манисса
  ind_tmp = ind_start_round + 1;
  tmp[ind_tmp++] = opt->specifier == 'e' ? 'e' : 'E';
  // степень в массив зо знаком
  char tmp_arr_pow[20] = {0};
  if ((pow < 0 && pow > -10) || (pow >= 0 && pow < 10)) {
    if (pow < 0 && pow > -10) {
      tmp_arr_pow[0] = '-';
      tmp_arr_pow[1] = '0';
      my_itoa(-pow, &tmp_arr_pow[2]);
    } else {
      tmp_arr_pow[0] = '+';
      tmp_arr_pow[1] = '0';
      my_itoa(pow, &tmp_arr_pow[2]);
    }
  } else {
    if (pow >= 10) {
      tmp_arr_pow[0] = '+';
      my_itoa(pow, &tmp_arr_pow[1]);
    } else {
      my_itoa(pow, tmp_arr_pow);
    }
  }
  my_strcpy(&tmp[ind_tmp], tmp_arr_pow);
  ind_tmp += (int)my_strlen(tmp_arr_pow);
  s21_memset(&tmp[ind_tmp], 0, my_strlen(&tmp[ind_tmp]));
  // готов токен
  if ((tmp[ind_exp] == 'e' || tmp[ind_exp] == 'E') && !opt->f_sharp) {
    my_memmove(&tmp[ind_exp - 1], &tmp[ind_exp], my_strlen(&tmp[ind_exp]));
    tmp[--ind_tmp] = '\0';
  }
  // обработка токена
  add_sign(tmp, opt);
  add_width(tmp, opt);
  //  printf("tmp = %s\n", tmp);
  my_memcpy(string, tmp, my_strlen(tmp));
  string += (int)my_strlen(tmp);
  return string;
}

char *i_hate_flag_f(long double num, char *string, OPT *opt) {
  char tmp[400] = {0};
  int ind_tmp = 0;
  int ind_tmp_start_num = 0;
  if (!positive(num)) {
    num = -num;
    tmp[ind_tmp++] = '-';
    ind_tmp_start_num = 1;
  }

  my_itoa(num, &tmp[ind_tmp]);
  num = num - (long long)num;

  ind_tmp = (int)my_strlen(tmp);
  int ind_last_int = (int)my_strlen(tmp);

  make_float_to_arr(num, tmp, &ind_tmp, opt);
  int round_last = 0;  // округление массива
  int ind_start_round = ind_last_int + opt->accuracy;
  round_last = (tmp[ind_start_round] >= '5');
  if (round_last)
    round_float(tmp, ind_start_round, ind_tmp_start_num, &ind_last_int);
  insert_dot(&tmp[ind_last_int]);
  if (opt->accuracy == 0 && !opt->f_sharp) {
    s21_memset(&tmp[ind_last_int], 0, my_strlen(&tmp[ind_last_int]));
  } else {
    s21_memset(&tmp[ind_last_int + 1 + opt->accuracy], '\0',
               my_strlen(&tmp[ind_last_int + 1 + opt->accuracy]));
  }
  add_sign(tmp, opt);
  add_width(tmp, opt);
  my_memcpy(string, tmp, my_strlen(tmp));
  string += (int)my_strlen(tmp);
  //  if (tmp[0] == '-' && tmp[1] == '-') {
  //    my_memcpy(string, &tmp[1], my_strlen(&tmp[1]));
  //    string += (int)my_strlen(&tmp[1]);
  //  } else {
  //    my_memcpy(string, tmp, my_strlen(tmp));
  //    string += (int)my_strlen(tmp);
  //  }

  return string;
}

void *my_memcpy(void *dest, const void *src, s21_size_t n) {
  unsigned char *dst = (unsigned char *)dest;
  unsigned char *source = (unsigned char *)src;
  for (int i = 0; i < (int)n; dst[i] = source[i], i++)
    ;
  return (unsigned char *)dest;
}

char *my_strcpy(char *dest, const char *src) {
  char *dst = dest;
  char *source = (char *)src;
  for (int i = 0; source[i]; dst[i] = source[i], i++)
    ;
  return dest;
}

s21_size_t my_strlen(const char *str) {
  s21_size_t len = 0;
  if (str != s21_NULL)
    for (; *str; str += 1, len += (s21_size_t)1)
      ;
  return len;
}
void *my_memmove(void *dest, const void *src, s21_size_t n) {
  register char *dst = (char *)dest;
  register char *sorce = (char *)src;
  if (dst < sorce) {
    for (; n; *dst = *sorce, n--, ++dst, sorce++)
      ;
  } else {
    dst = (char *)dest + (n - 1);
    sorce = (char *)src + (n - 1);
    for (; n; *dst = *sorce, n--, dst--, sorce--)
      ;
  }
  return dest;
}

char *my_strchr(const char *str, int c) {
  char *find = s21_NULL;
  char *ptr = (char *)str;
  if (c != '\0') {
    for (; *ptr && find == s21_NULL; *ptr == c ? find = ptr : ptr++)
      ;
  } else {
    find = &ptr[my_strlen(str)];
  }
  return find;
}
