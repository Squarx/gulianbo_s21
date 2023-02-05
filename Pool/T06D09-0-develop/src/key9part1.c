/*------------------------------------
    Здравствуй, человек!
    Чтобы получить ключ
    поработай с комментариями.
-------------------------------------*/

#include <stdio.h>
#define NMAX 10
int sum_numbers(int *buffer, int length);
int find_numbers(int* buffer, int length, int number, int* numbers);
int input(int *a, int *n);
int less_10(int* n);
int sum(int* a, int n);
void printer(int* b, int n);

int main() {
    int n, data[NMAX];
    int data1[NMAX];
    if (input(data, &n)) {
        if (sum_numbers(data, n) != 0) {
        printf("%d\n", sum_numbers(data, n));
        printer(data1, find_numbers(data, n, sum_numbers(data, n), data1));
        } else {
            printf("n/a");
        }
    }
    return 0;
}
/*------------------------------------
    Функция должна находить
    сумму четных элементов
    с 0-й позиции.
-------------------------------------*/
int sum_numbers(int *buffer, int length) {
    int sum = 0;
    for (int* i = buffer; i - buffer < length; i++) {
        if (*i % 2 == 0) {
            sum = sum + *i;
        }
    }
    return sum;
}

/*------------------------------------
    Функция должна находить
    все элементы, на которые нацело
    делится переданное число и
    записывает их в выходной массив.
-------------------------------------*/
int find_numbers(int* buffer, int length, int number, int* numbers) {
    int i = 0;
    for (int *p = buffer; p - buffer < length; p++) {
        if (*p != 0 && (number % (*p)) == 0) {
            *numbers = *p;
            numbers++;
            i++;
        }
    }
return i;
}
int input(int *a, int *n) {
    int x = 1;
    scanf("%d", n);
    if (less_10(n)) {
        for (int *p = a; p - a < *n; p++) {
            if (!scanf("%d", p)) {
                printf("n/a");
                x = 0;
                break;
            }
        }
    } else {
        printf("n/a");
        x = 0;
    }
    return x;
}

int less_10(int* n) {
  if ( *n > NMAX || *n <= 0 ) {
      return 0;
  } else {
      return 1;
  }
}
void printer(int* b, int n) {
    for (int* a = b; a - b < n ; a++) {
        if ( a - b < n - 1 ) {
            printf("%d ", *a);
        } else {
            printf("%d", *a);
        }
    }
}
