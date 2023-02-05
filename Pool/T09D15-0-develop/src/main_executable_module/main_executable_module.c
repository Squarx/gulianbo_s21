#include <stdio.h>
#include <stdlib.h>
#include "../data_module/data_process.h"
#include "../data_libs/data_io.h"
#include "../data_libs/data_stat.h"
#include "../yet_another_decision_module/decision.h"
int main() {
    double *data;
    int n;
    float x;
    int flag = 1;
    int flag1 = 1;
    if (scanf("%f", &x) != 1 || x!= (int)x || x <= 0) {
        flag = 0;
    } else {
        n = (int)x;
    }
    if (flag) data = malloc(n * sizeof(double));
    if (data == NULL) {
        flag = 0;
    }
    if (flag && flag1) printf("LOAD DATA...\n");
    if (flag && flag1) input(data, n, &flag1);
    if (!flag1) free(data);
    if (flag && flag1) {
    printf("RAW DATA:\n\t");
    output(data, n);
    }
    if (flag && flag1) {
    printf("\nNORMALIZED DATA:\n\t");
    normalization(data, n, &flag);
    if (!flag) free(data);
    if (flag && flag1) output(data, n);
    }
    if (flag && flag1) {
    printf("\nSORTED NORMALIZED DATA:\n\t");
    if (flag && flag1) sort(data, n);
    if (flag && flag1) output(data, n);
    }
    if (flag && flag1) {
        printf("\nFINAL DECISION:\n\t");
        if (make_decision(data, n))
            printf("YES");
        else
            printf("NO");
    }
    if (!flag || !flag1) {
        printf("n/a");
    }
    if (flag && flag1) free(data);
    return 0;
}
