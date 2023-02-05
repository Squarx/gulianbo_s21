#include <stdio.h>
#define NMAX 10

int input(int *a, int *n, int* shift);
void SHIFT(int* data1, int lenth, int* data2, int shift);
void output(int *a, int n);
int less_10(int* n);
void printer(int* b, int n);
int cnt(int len, int x);
int main() {
    int n, c, data[NMAX];
    int data_s[NMAX];
    if (input(data, &n, &c)) {
        SHIFT(data, n, data_s, cnt(n, c));
        printer(data_s, n);
    } else {
        printf("n/a");
    }
    return 0;
}

int input(int *a, int *n, int* shift ) {
    int x = 1;
    scanf("%d", n);
    if (less_10(n)) {
        for (int *p = a; p - a < *n; p++) {
            if (!scanf("%d", p)) {
                x = 0;
                break;
            }
        }
    } else {
        printf("n/a");
        x = 0;
    }
    if (!scanf("%d", shift)) x = 0;
    return x;
}

int less_10(int* n) {
    if ( *n > NMAX || *n <= 0 ) {
        return 0;
    } else {
        return 1;
    }
}

void SHIFT(int* data1, int len, int* data2, int shift) {
    int i;
    for (i = 0; i <= len; i++) {
        if (i + shift >= len) {
            data2[i] = data1[i + shift - len];
            continue;
        }
        if (i + shift < 0) {
            data2[i] = data1[i + shift + len];
            continue;
        }
        data2[i] = data1[i + shift];
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
int cnt(int len, int x) {
    return x % len;
}

