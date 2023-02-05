#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);
int less_10(int* n);

void output_result(int max_v,
                   int min_v,
                   double mean_v,
                   double variance_v);

int main() {
    int n, data[NMAX];
    if (input(data, &n)) {
        output(data, n);
        output_result(max(data, n),
                      min(data, n),
                      mean(data, n),
                      variance(data, n));
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
int max(int* num_1, int n) {
    int max = *num_1;
    for (int *p = num_1; p - num_1 < n; p++) {
        if (max < *p) max = *p;
    }
    return max;
}

int min(int* num_1, int n) {
    int min = *num_1;
    for (int *p = num_1; p - num_1 < n; p++) {
        if (min > *p) min = *p;
    }
    return min;
}

double mean(int* num_1, int n) {
    int sum = 0;
    for (int *p = num_1; p - num_1 < n; p++) {
        sum += *p;
    }
    double average = (1.0 * sum)/(1.0 * n);
    return average;
}
double variance(int* num_1, int n) {
    double sigma = 0, average = mean(num_1, n);
    for (int *p = num_1; p - num_1 < n; p++) {
        sigma += 1.0*(average - *p) * (average - *p) / n;
    }
    return sigma;
}

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
    printf("%d %d %.6lf %.6lf", max_v, min_v, mean_v, variance_v);
}
