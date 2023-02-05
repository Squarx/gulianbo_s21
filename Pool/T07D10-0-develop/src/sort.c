#include <stdio.h>
#include <stdlib.h>

void output(int *a, int n);
int less_10(int n);
void sort_slow(int* a, int n);
int input(int *a, int n);
int main() {
    int c;
    if (scanf("%d", &c) && c == 10) {
        int* p = (int*) calloc(c, sizeof(int));
        if (input(p, c)) {
            sort_slow(p, c);
            output(p, c);
            free(p);
        }
    } else {
        printf("n/a");
    }
    return 0;
}

int input(int *a, int n) {
    if (less_10(n)) {
        for (int *p = a; p - a < n; p++) {
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
    if ( n != 10 || n <= 0 ) {
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
