#include "data_process.h"
#include "../data_libs/data_io.h"
#include "../data_libs/data_stat.h"
#include <stdio.h>
#include <stdlib.h>
int main() {
    double *data;
    float n;
    int flag = 1;
    while (1) {
    if (!scanf("%f", &n) || n != (int)n || n <= 0) {
       flag = 0;
       break;
    }
    data = malloc (n * sizeof(double));
    if (data == NULL) {
        flag = 0;
       break;
    }
    input(data, n, &flag);
    if (!flag) {
        free(data);
        break;
    }
    if (normalization(data, n, &flag)) {
        if (!flag) break;
        output(data, n);
    } else {
        printf("ERROR");
    }
    free(data);
    break;
    }
    if (!flag) printf("n/a");
    return 0;
}
