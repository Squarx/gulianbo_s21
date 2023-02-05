#include <stdio.h>
int maxim(int a, int b);
int main(void) {
    int a, b;
    if (scanf("%d %d", &a, &b) == 2) {
        printf("%d", maxim(a, b));
    } else {
        printf("n/a");
    }
    return 0;
}
int maxim(int a, int b) {
    int max = a;
    if (b > max) {
        max = b;
    }
    return(max);
}
