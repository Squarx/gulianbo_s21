#include <stdio.h>
#include <math.h>
#define NMAX 30

int input(int *a, int *n);
void output(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);
int less_10(int* n);
int solved(int* num_1, int n);
int main() {
    int n, data[NMAX];
    if (input(data, &n)) {
        printf("%d", solved(data, n));
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

int less_10(int* n) {
    if ( *n > NMAX || *n <= 0 ) {
        return 0;
    } else {
        return 1;
    }
}

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        if ( p - a < n - 1 ) {
            printf("%d ", *p);
        } else {
            printf("%d\n", *p);
        }
    }
}

double mean(int* num_1, int n) {
    int sum = 0;
    for (int *p = num_1; p - num_1 < n; p++) {
        sum += *p;
    }
    double average = (1.0 * sum) / (1.0 * n);
    return average;
}
double variance(int* num_1, int n) {
    double sigma = 0, average = mean(num_1, n);
    for (int *p = num_1; p - num_1 < n; p++) {
        sigma += 1.0*(average - *p) * (average - *p) / (1.0 * n);
    }
    return sigma;
}

int solved(int* num_1, int n) {
    int x = 0;
    double avg  = mean(num_1, n);
    double var = variance(num_1, n);
    for (int *p = num_1; p - num_1 < n; p++) {
        if ( *p %2 == 0 && *p >= avg && *p <= avg + 3 * sqrt(var) && *p != 0 ) {
            x = *p;
            break;
        }
    }
    return x;
}
