#include <stdio.h>
#include <math.h>
int main(void) {
    float x, a;
    if (scanf("%f", &x) == 1) {
        a = 7*pow(10, -3)*pow(x, 4)+((22.8*pow(x, (float)(1/3))-pow(10, 3)*x+3)/
                                     (float)(x*x/2)-x*pow(10+x, (float)(2/x))-1.01);
        printf("%.1lf", a);
    } else {
        printf("n/a");
    }
    return 0;
}
