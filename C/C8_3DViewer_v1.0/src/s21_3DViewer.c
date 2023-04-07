#include "s21_3DViewer.h"

int s21_3DViewer(char *path, V_F *count) {
  *count = (V_F){0};
  FILE *txt = NULL;
  if (path != NULL) {
    file_open(txt, path, count);
    if (count->error == 0) {
      parser_v(txt, path, count);
      to_long_array(count);
    }
  } else {
    count->error = 1;
  }
  return count->error;
}

void to_long_array(V_F *count) {
  count->resultV = calloc((count->v + 1) * 3, sizeof(double));
  count->resultF = calloc(count->f * 6, sizeof(double));
  if (count->resultV != NULL && count->resultF != NULL) {
    int k = 0;
    for (int i = 0; i < (count->v + 1); i++) {
      for (int j = 0; j < 3; j++) {
        count->resultV[k] = count->mV.matrix[i][j];
        k++;
      }
    }
    k = 0;
    for (int i = 0; i < count->f; i++) {
      for (int j = 0; j < 6; j++) {
        count->resultF[k] = (int)count->mF.matrix[i][j];
        k++;
      }
    }
  }
}

void clean_all(V_F *A) {
  s21_remove_matrix(&A->mV);
  s21_remove_matrix(&A->mF);
  free(A->resultV);
  free(A->resultF);
}

void clean_long_arr(V_F *A) {
  free(A->resultV);
  free(A->resultF);
}

void file_open(FILE *txt, char *path, V_F *count) {
  txt = fopen(path, "r");
  if (txt != NULL) {
    char str[128] = {0};
    while (!feof(txt) && fgets(str, 128, txt) != NULL) {
      if (str[0] == 'v' && str[1] == ' ') count->v++;
      if (str[0] == 'f') count->f++;
      memset(str, 0, 128);
    }
    fclose(txt);
  } else {
    count->error = 1;
  }
}

void parser_v(FILE *txt, char *path, V_F *count) {
  txt = fopen(path, "r");
  if (txt != NULL) {
    char str[128] = {0};
    count->error = s21_create_matrix((count->v + 1), 3, &count->mV);
    count->error = s21_create_matrix(count->f, 6, &count->mF);
    int v = 1, f = 0;
    if (count->error == 0) {
      for (int i = 0; !feof(txt) && fgets(str, 128, txt) != NULL; i++) {
        int column = 0;
        int len = (int)strlen(str);
        if (str[0] == 'v' && str[1] == ' ') {
          counterV(len, &column, str, count, &v);
        } else if (str[0] == 'f' && str[1] == ' ') {
          counterF(len, &column, str, count, &f);
        }
      }
    }
    fclose(txt);
  }
}
void counterV(int len, int *column, char *str, V_F *count, int *v) {
  for (int j = 1; j <= len && *column < 3; j++) {
    if (str[j - 1] == '-' || (str[j - 1] == ' ' && is_numb(str[j]))) {
      count->mV.matrix[*v][*column] = numb_count((const char *)str, &j);
      (*column) += 1;
    }
  }
  (*v) += 1;
}
void counterF(int len, int *column, char *str, V_F *count, int *f) {
  for (int j = 1; j <= len && *column < 3; j++) {  // 0 ????
    if (is_start_numb(str[j - 1], str[j])) {
      double result = 0;
      result = numb_count((const char *)str, &j);
      if (result < 0) result += count->v + 1;
      if (*column == 0) {
        count->mF.matrix[*f][0] = count->mF.matrix[*f][5] = result;
      } else if (*column == 1) {
        count->mF.matrix[*f][1] = count->mF.matrix[*f][2] = result;
      } else {
        count->mF.matrix[*f][3] = count->mF.matrix[*f][4] = result;
      }
      (*column) += 1;
    }
  }
  (*f) += 1;
}

double numb_count(const char *line, int *i) {
  double result = 0;
  int minus = 0;
  if (line[*(i)-1] == '-') minus = 1;
  result_mul(line, i, &result, NULL);
  if (line[*i] == '.') {
    (*i)++;
    int len = 0;
    result_mul(line, i, &result, &len);
    while (len > 0) {
      result *= 0.1;
      len--;
    }
  }
  (*i)--;
  return minus == 0 ? result : (result * -1);
}

void result_mul(const char *line, int *i, double *result, int *len) {
  while (is_numb(line[*i])) {
    *result *= 10;
    *result += (int)(line[(*i)++] - '0');
    if (len != NULL) (*len)++;
  }
}
