//
// Created by Gulian Boris on 1/16/23.
//
#include "Smart_calc.h"

long double s21_smart_calc(char *string, int mode, long double variable,
                           int *error) {
  *error = validator(string, mode);
  long double res = 0 / 0.;
  if (!(*error)) {
    long double data[256] = {0};
    OP functions[256] = {0};
    int top_num = 0;
    int top_func = 0;
    char *cursor_str = string;

    while (cursor_str && *cursor_str) {
      cursor_str = parse_token(cursor_str, &top_num, &top_func, data, functions,
                               string, variable, error);
    }

    while (!(*error) && top_func > 0) {
      *error = calculation(&top_num, &top_func, data, functions);
    }
    if (!(*error) && top_num > 1) *error = 7;
    if (!(*error)) {
      res = data[top_num];
      top_num = pop_num(top_num, data);
    }
    //
    //    print_arr_num(top_num, data);
    //    print_arr_func(top_func, functions);
    //    if (*error) fprintf(stderr, "TEST error\n");
    //    else
    //    printf("%d\n", top_num);
  }
  return res;
}
void print_arr_func(int top, OP *data) {
  while (top > 0) {
    char name[10] = {0};
    if (data[top].name == PLUS) name[0] = '+';
    if (data[top].name == MIN) name[0] = '-';
    if (data[top].name == MUL) name[0] = '*';
    if (data[top].name == DIV) name[0] = '/';
    if (data[top].name == POW) name[0] = '^';
    if (data[top].name == MOD) strcpy(name, "mod");
    ;
    if (data[top].name == L_branch) name[0] = '(';
    if (data[top].name == R_branch) name[0] = ')';
    if (data[top].name == COS) strcpy(name, "cos");
    if (data[top].name == SIN) strcpy(name, "sin");
    if (data[top].name == TAN) strcpy(name, "tan");
    if (data[top].name == ACOS) strcpy(name, "acos");
    if (data[top].name == ASIN) strcpy(name, "asin");
    if (data[top].name == ATAN) strcpy(name, "atan");
    if (data[top].name == SQRT) strcpy(name, "sqrt");
    if (data[top].name == LN) strcpy(name, "ln");
    if (data[top].name == LOG) strcpy(name, "log");
    printf("%s[%d]\n", name, top);
    top--;
  }
}
void print_arr_num(int top, long double *data) {
  while (top > 1) {
    printf("curr num[%d] =%Lf\n", top, data[top]);
    top--;
  }
  if (top == 1)
    printf("first num[%d] =%Lf |\n", top, data[top]);
  else
    printf("No member in stack num\n");
}
/**
 * @brief парсит строку, берет 1 токен и возвращает курсор строки на место после
 *токена
 * @brief пссле распределяет токен на 2 стека число и функция
 * @brief если функция то он может сжать решение если след токен имеет pritity <
 *old.priority ||  елси встретил ) => (f(x)) = res
 * @param cursor_str
 * @param top_num
 * @param top_func
 * @return
 **/
char *parse_token(char *cursor_str, int *top_num, int *top_func,
                  long double *arr_num, OP *arr_func, char *start,
                  long double variable, int *error) {
  if (cursor_str != NULL && *cursor_str != '\0') {
    long double data = 0;
    if (is_unar_mimus(cursor_str, start)) {
      *top_num = num_add(*top_num, -1, arr_num);
      *top_func = func_add(MUL, *top_func, arr_func);
      cursor_str++;
    } else {
      if (*cursor_str != '\0' &&
          strchr("0123456789",
                 *cursor_str)) {  // тут ли? обратобка -9.123123 не -sin...
        cursor_str = get_num(cursor_str, &data);
        *top_num = num_add(*top_num, data, arr_num);
      }
      if (*cursor_str != '\0') {
        // here +-/*^ mod ()
        if (is_func_two_arg(cursor_str)) {
          int name = -1;
          cursor_str = get_name_func(cursor_str, &name);
          int priority = get_priority(name);
          // automult
          if (name == L_branch && *top_num > 0 &&
              arr_func[*top_func].name <
                  COS) {  // (2 + 2)^2(2 + 1)^2 name != pow || mod ??
            smart_mult(cursor_str, start, top_func, top_num, arr_func, arr_num);
          }
          *error = compress_func(top_num, top_func, arr_num, arr_func, name,
                                 priority);
          if (*error) {
            *error = 7;
            //          fprintf(stderr, "TEST error\n");
          }
        } else {
          // sin cos tg ln log
          if (is_func_one_arg(cursor_str)) {
            int name = -1;
            smart_mult(cursor_str, start, top_func, top_num, arr_func, arr_num);
            cursor_str = get_name_func(cursor_str, &name);
            *top_func = func_add(name, *top_func, arr_func);
          } else {
            // xX space (no function like sin() () +-)
            if (strchr("\r\n\t\v\f ", *cursor_str))
              cursor_str++;
            else {
              if (*cursor_str == 'x' || *cursor_str == 'X') {
                smart_mult(cursor_str, start, top_func, top_num, arr_func,
                           arr_num);
                *top_num = num_add(*top_num, variable, arr_num);
                cursor_str++;
              } else {
                cursor_str = NULL;
                *error = 5;
                //                fprintf(stderr, "INVALID COMMAND\n");
              }
            }
          }
        }
      }
    }
  }
  return cursor_str;
}

void smart_mult(char *cursor_str, char *start, int *top_func, int *top_num,
                OP *arr_func, long double *arr_num) {
  int add_mult = 0;
  add_mult = auto_mult(cursor_str, start);
  if (add_mult) {
    if (*top_func > 0 && !is_func_one_arg(cursor_str) &&
        M <= arr_func[*top_func].priotity) {
      while ((*top_func > 0 && M <= arr_func[*top_func].priotity) &&
             arr_func[*top_func].name != L_branch) {
        calculation(top_num, top_func, arr_num, arr_func);
      }
    }
    *top_func = func_add(MUL, *top_func, arr_func);
  }
}

int auto_mult(char *cusror, char *start) {
  int add = 0;
  if (cusror >= start + 1) {
    if (*cusror != 'x' && *cusror != 'X') {
      cusror--;
      if (cusror != start && *cusror == '(') cusror--;
    } else {
      cusror--;
    }
    while (cusror > start && strchr("\r\n\t\v\f ", *cusror)) {
      //    printf("|%c|\n", *cusror);
      cusror--;
    }
    add = is_num(cusror, start) || strchr(".)xX0123456789", *cusror) != NULL;
  }
  // 2 (1 + 2) || 4. (1 +2) || (2 + 3) (3 + 2)
  return add;
}

int is_func_one_arg(char *cursor) {
  int res = 0;
  if (cursor && *cursor != '\0') {
    if (memcmp(cursor, "cos", 3) == 0) res = 1;
    if (memcmp(cursor, "sin", 3) == 0) res = 1;
    if (memcmp(cursor, "tan", 3) == 0) res = 1;
    if (memcmp(cursor, "acos", 4) == 0) res = 1;
    if (memcmp(cursor, "asin", 4) == 0) res = 1;
    if (memcmp(cursor, "atan", 4) == 0) res = 1;
    if (memcmp(cursor, "sqrt", 4) == 0) res = 1;
    if (memcmp(cursor, "ln", 2) == 0) res = 1;
    if (memcmp(cursor, "log", 3) == 0) res = 1;
    //    if (memcmp(cursor, "ln", 2) == 0) res = 1;
  }
  return res;
}

/**
 * @brief - сжимает количество функций производя подсчеты
 * @param top_num
 * @param top_func
 * @param arr_num
 * @param arr_func
 * @param name
 * @param priority
 */
int compress_func(int *top_num, int *top_func, long double *arr_num,
                  OP *arr_func, int name, int priority) {
  int error = 0;
  if ((priority <= arr_func[*top_func].priotity &&
       !(arr_func[*top_func].name == POW && name == POW)) ||
      name == R_branch) {
    if (name == R_branch) priority = 1;
    while (!error &&
           (*top_func > 0 && priority <= arr_func[*top_func].priotity) &&
           arr_func[*top_func].name != L_branch) {
      error = calculation(top_num, top_func, arr_num, arr_func);
    }
  }
  if (!error && name != R_branch) {
    *top_func = func_add(name, *top_func, arr_func);
  } else {
    if (!error) {
      *top_func = pop_func(*top_func, arr_func);
      if (arr_func[*top_func].name >= COS) {  // cos(...) => cos( => cos
        calc_func(top_num, top_func, arr_num, arr_func);
      }
      //      printf("%Lf\n", arr_num[*top_num]);
    }
  }
  return error;
}

int calculation(int *top_num, int *top_func, long double *arr_num,
                OP *arr_func) {
  int error = 0;
  if (arr_func[*top_func].name < COS) {
    if (*top_num < 2) {
      error = 7;
    } else {
      long double res = 0;
      long double b = arr_num[*top_num];
      *top_num = pop_num(*top_num, arr_num);
      long double a = arr_num[*top_num];
      *top_num = pop_num(*top_num, arr_num);
      int func = arr_func[*top_func].name;
      //  printf("a = %Lf b = %Lf\n", a, b);
      *top_func = pop_func(*top_func, arr_func);
      //  printf("oper = %d\n", func);
      if (func == PLUS) res = a + b;
      if (func == MIN) res = a - b;
      if (func == MUL) res = a * b;
      if (func == DIV) res = a / b;
      if (func == POW)
        res = (double)pow((double)a, (double)b);  // left priority 2^2^3
      if (func == MOD) res = fmodl(a, b);
      //  if (func == COS) res = cos(a, b);
      *top_num = num_add(*top_num, res, arr_num);
    }
  } else {
    error = calc_func(top_num, top_func, arr_num, arr_func);
  }
  return error;
}
int calc_func(int *top_num, int *top_func, long double *arr_num, OP *arr_func) {
  int error = 0;
  if (*top_num < 1) {
    error = 1;
  } else {
    long double res = 0;
    long double a = arr_num[*top_num];
    *top_num = pop_num(*top_num, arr_num);
    int func = arr_func[*top_func].name;
    //  printf("a = %Lf\n", a);
    *top_func = pop_func(*top_func, arr_func);
    //  printf("oper = %d\n", func);
    if (func == COS) res = cosl(a);
    if (func == SIN) res = sinl(a);
    if (func == TAN) res = tanl(a);
    if (func == ACOS) res = acosl(a);
    if (func == ASIN) res = asinl(a);
    if (func == ATAN) res = atanl(a);
    if (func == SQRT) res = sqrtl(a);
    if (func == LN) res = logl(a);
    if (func == LOG) res = log10l(a);
    *top_num = num_add(*top_num, res, arr_num);
  }
  return error;
}

int is_func_two_arg(char *cursor) {
  int res = 0;
  if (cursor && *cursor != '\0') {
    if (*cursor == '+' || *cursor == '-' || *cursor == '*' || *cursor == '/' ||
        *cursor == '^' || *cursor == '(' || *cursor == ')')
      res = 1;
    if (memcmp(cursor, "mod", 3) == 0) res = 1;
  }
  return res;
}
// num

char *get_num(char *cursor_str, long double *num) {
  long double data = 0;
  for (int i = 0; *cursor_str != '\0' && strchr("0123456789", *cursor_str);
       cursor_str++, i++)
    data = 10 * data + (int)(*cursor_str - 48);
  //      data = sign * data;
  if (*cursor_str != '\0' && *cursor_str == '.') {
    cursor_str++;
    long double drob = 0;
    int i = 0;
    long double ten = 1;
    for (; *cursor_str != '\0' && strchr("0123456789", *cursor_str);
         cursor_str++, i++) {
      ten /= 10;
      drob += ten * (int)(*cursor_str - 48);
    }
    data += drob;
  }
  *num = data;
  return cursor_str;
}

int num_add(int top, long double num, long double *data) {
  data[++top] = num;
  return top;
}

int pop_num(int top, long double *data) {
  data[top--] = 0;
  return top;
}

// func
int func_add(int name, int top_func, OP *data_func) {
  top_func++;
  data_func[top_func].name = name;
  if (name < MUL)
    data_func[top_func].priotity = L;
  else if (name < POW)
    data_func[top_func].priotity = M;
  else if (name < COS)
    data_func[top_func].priotity = H;
  else
    data_func[top_func].priotity = F;

  //  printf("NAME = %d, prioruty = %d\n", data_func[top_func].name,
  //  data_func[top_func].priotity);
  return top_func;
}

int pop_func(int top_func, OP *data_func) {
  data_func[top_func].name = 0;
  data_func[top_func].priotity = 0;
  top_func--;
  return top_func;
}

int validator(char *str, int mode) {
  int error = 0;
  char *cursor = NULL;
  if (str == NULL) {
    error = 1;
  } else {
    cursor = str;
    error = mismatch_brackets(cursor);
    //    if (error) fprintf(stderr, "INVALID STRING :: MISMATCH BRACKETS
    //    ()\n");
    if (!error) {
      error = empty_brackets(cursor);
      //      if (error) fprintf(stderr, "INVALID STRING :: EMPTY BRACKETS () or
      //      ( ... )\n");
    }
    if (!error) {
      error = float_correct(cursor);
      //      if (error) fprintf(stderr, "FLOAT HAS MORE THAN 1 DOT\n");
    }
    if (!error) {
      cursor = str;
      for (; *cursor != '\0' && !error; cursor++)
        if ((*cursor == 'x' || *cursor == 'X') && mode == CALC) error = 4;
      //      if (error) fprintf(stderr, "INVALID STRING :: HAVE X in CALC
      //      mode\n");
    }
  }
  return error;
}
/**
 *
 * @param cursor
 * @return 0 - OK 3 - more dot than one
 */
int float_correct(char *cursor) {
  int error = 0;
  char *start = NULL;
  start = cursor;
  while (*cursor != '\0' && !error) {
    while (*cursor != '\0' && !is_num(cursor, start)) cursor++;
    if (*cursor != '\0') {
      int cnt_dot = 0;
      if (*cursor != '\0' && *(cursor + 1) != '\0' && *cursor == '-') cursor++;
      while (!error && strchr("1234567890.", *cursor)) {
        if (*cursor == '.') cnt_dot++;
        if (cnt_dot > 1) error = 3;
        cursor++;
      }
    }
  }
  return error;
}
/**
 *
 * @param cursor
 * @return 0 - OK 1 - mismatch
 */
int mismatch_brackets(char *cursor) {
  int left_bracket = 0;
  int right_bracket = 0;
  while (*cursor != '\0') {
    if (*cursor == '(') left_bracket++;
    if (*cursor == ')') right_bracket++;
    cursor++;
  }
  return left_bracket == right_bracket ? 0 : 1;
}
/**
 *
 * @param cursor
 * @return 0 - OK 2 - empty
 */
int empty_brackets(char *cursor) {
  int error = 0;
  while (*cursor != '\0' && !error) {
    if (*cursor == '(') {
      cursor++;
      while (strchr("\r\n\t\v\f ", *cursor)) cursor++;
      if (*cursor == ')') error = 2;
    }
    if (*cursor != '\0' && !error) cursor++;
  }
  return error;
}

/**
 *
 * @param cursor
 * @param start_str
 * @return 1 is unar minus (-a)
 */
int is_unar_mimus(char *cursor, const char *start_str) {
  int res = 0;
  if (*cursor == '-') {
    if (cursor >= start_str + 1) {  // если минус в начале строки это унарный
      char *tmp = cursor - 1;
      while (tmp > start_str && strchr("\r\n\t\v\f ", *tmp))
        tmp--;  // скипаем все пробелы
      if (strchr("+-*/^d(", *tmp)) res = 1;
      // [ + - * / ^ moD ( ] -a
      else
        res = 0;
    } else {
      res = 1;  //
    }
  }
  return res;
}
int is_num(char *cursor, const char *start_str) {
  int res = 0;
  if (cursor && *cursor != '\0') {
    if (*cursor >= '0' && *cursor <= '9') res = 1;
    if (*cursor == '-') {
      char *tmp_cur = NULL;
      tmp_cur = cursor + 1;
      while (*tmp_cur != '\0' && strchr("\r\n\t\v\f ", *tmp_cur)) tmp_cur++;
      if (*cursor >= '0' && *cursor <= '9') {
        tmp_cur = cursor;
        if (tmp_cur - 1 >= start_str) tmp_cur--;
        while (cursor > start_str && strchr("\r\n\t\v\f ", *cursor)) cursor--;
        if ((*cursor >= '0' && *cursor <= '9') || *cursor == 'x' ||
            *cursor == 'X' || *cursor == ')')
          res = 0;
        else
          res = 1;
      } else {
        res = 0;
      }
    }
  }
  //  res ? printf("Is num |%s|\n", cursor) : printf("Not a num|%s|\n", cursor);
  return res;
}

char *get_name_func(char *cursor, int *name) {
  char *res = NULL;
  if (cursor && *cursor != '\0') {
    if (*cursor == '+') {
      *name = PLUS;
      res = cursor + 1;
    }
    if (res == NULL && *cursor == '-') {
      *name = MIN;
      res = cursor + 1;
    }
    if (res == NULL && *cursor == '*') {
      *name = MUL;
      res = cursor + 1;
    }
    if (res == NULL && *cursor == '/') {
      *name = DIV;
      res = cursor + 1;
    }
    if (res == NULL && *cursor == '^') {
      *name = POW;
      res = cursor + 1;
    }
    if (res == NULL && memcmp(cursor, "mod", 3) == 0) {
      *name = MOD;
      res = cursor + 3;
    }
    if (res == NULL && *cursor == '(') {
      *name = L_branch;
      res = cursor + 1;
    }
    if (res == NULL && *cursor == ')') {
      *name = R_branch;
      res = cursor + 1;
    }
    if (res == NULL && memcmp(cursor, "cos", 3) == 0) {
      *name = COS;
      res = cursor + 3;
    }
    if (res == NULL && memcmp(cursor, "sin", 3) == 0) {
      *name = SIN;
      res = cursor + 3;
    }
    if (res == NULL && memcmp(cursor, "tan", 3) == 0) {
      *name = TAN;
      res = cursor + 3;
    }
    if (res == NULL && memcmp(cursor, "acos", 4) == 0) {
      *name = ACOS;
      res = cursor + 4;
    }
    if (res == NULL && memcmp(cursor, "asin", 4) == 0) {
      *name = ASIN;
      res = cursor + 4;
    }
    if (res == NULL && memcmp(cursor, "atan", 4) == 0) {
      *name = ATAN;
      res = cursor + 4;
    }
    if (res == NULL && memcmp(cursor, "sqrt", 4) == 0) {
      *name = SQRT;
      res = cursor + 4;
    }
    if (res == NULL && memcmp(cursor, "ln", 2) == 0) {
      *name = LN;
      res = cursor + 2;
    }
    if (res == NULL && memcmp(cursor, "log", 3) == 0) {
      *name = LOG;
      res = cursor + 3;
    }
  }
  return res;
}

int get_priority(int name) {
  int res = 0;
  if (name == COS) res = F;
  if (name == PLUS || name == MIN) res = L;
  if (name == MUL || name == DIV) res = M;
  if (name == POW || name == MOD) res = H;
  if (name == L_branch || name == R_branch) res = 100;
  return res;
}
