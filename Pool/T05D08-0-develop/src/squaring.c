#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int* n);
void squaring(int *a, int* n);
int less_10(int* n);

int main() {
    int n, data[NMAX];
    if (input(data, &n)) {
        squaring(data, &n);
        output(data, &n);
    }
    return 0;
}

int input(int *a, int *n) {
    scanf("%d", n);
    if (less_10(n)) {
        for (int *p = a; p - a < *n; p++) {
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

void output(int *a, int* n) {
    for (int *p = a; p - a < *n; p++) {
        if ( p - a < *n - 1 ) {
            printf("%d ", *p);
        } else {
            printf("%d", *p);
        }
    }
}

void squaring(int *a, int* n) {
    for (int *p = a; p - a < *n; p++) {
        *p = *p * *p;
    }
}

int less_10(int* n) {
    if ( *n > NMAX || *n <= 0 ) {
        return 0;
    } else {
        return 1;
    }
}
