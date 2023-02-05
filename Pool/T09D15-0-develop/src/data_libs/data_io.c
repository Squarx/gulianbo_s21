#include "data_io.h"

void input(double* data, int n, int* flag) {
    for (int i = 0; i < n; i++) {
        if (!scanf("%lf", &data[i])) {
            *flag = 0;
            break;
        }
    }
}
void output(double* data, int n) {
    for (int i = 0; i < n; i++) {
        if (i != n - 1)
            printf("%.2lf ", data[i]);
        else
            printf("%.2lf", data[i]);
    }
}
void sort(double* data, int n) {
    int save;
    for (int i = 0; i < n ; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (data[i] > data[i + 1]) {
                  save = data[i];
                data[i] = data[i + 1];
                data[i + 1] = save;
            }
        }
    }
}

