#include <stdlib.h>
#include "decision.h"
#include "../data_libs/data_io.h"
void printer(double * arr, int n);
int main(void) {
    double *data;
    int x;
    int flag = 1;
    int flag1 = 1;
    if (scanf("%d", &x) != 1 || x <= 0) flag =0;
    if (flag) data = calloc (x, sizeof(double));
    if (data == NULL) {
        flag = 0;
    }
    if (flag) input(data, x, &flag1);
    if (!flag1) free(data);
    if (flag) {
    if (make_decision(data, x))
        printf("YES");
    else
        printf("NO");
    }
    if (!flag) printf("n/a");
    if (flag && flag1) free(data);
    return 0;
}
