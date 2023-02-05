#include <stdio.h>
int in_cycle(float a, float b);
int main(void) {
    float a, b;
    if (scanf("%f %f", &a, &b) == 2) {
        in_cycle(a, b);
    } else {
        printf("n/a");
    }
    return 0;
}
int in_cycle(float a, float b) {
    if (a*a+b*b-25 <= 0) {
        printf("GOTCHA");
    } else {
        printf("MISS");
    }
    return 0;
}
