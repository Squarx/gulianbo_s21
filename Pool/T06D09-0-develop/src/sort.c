#include <stdio.h>
#define NMAX 10

int input(int *a);
void output(int *a, int n);
void squaring(int *a, int* n);
int less_10(int n);
void sort_slow(int* a, int n);

int main() {
    int data[NMAX];
    if (input(data)) {
        sort_slow(data, NMAX);
        output(data, NMAX);
    }
    return 0;
}

int input(int *a) {
    if (less_10(10)) {
        for (int *p = a; p - a < NMAX; p++) {
            if (!scanf("%d", p)) {
                printf("n/a");
                return 0;
                break;
            }
        }
    } else {
        printf("n/a");
        return 0;
    }
    return 1;
}

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        if ( p - a < n - 1 ) {
            printf("%d ", *p);
        } else {
            printf("%d", *p);
        }
    }
}

int less_10(int n) {
    if ( n != NMAX || n <= 0 ) {
        return 0;
    } else {
        return 1;
    }
}

void sort_slow(int* a, int n) {
    int save;
    for (int* i = a; i - a < n ; i++) {
        for (int* j = a; j - a < n - 1 ; j++) {
            if (*j > *(j+1)) {
                  save = *j;
                *j = *(j+1);
                *(j+1) = save;
            }
        }
    }
}
