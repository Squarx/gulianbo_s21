#include <stdio.h>
int sum(int a, int b);
int sub(int a, int b);
int mult(int a, int b);
int dv(int a, int b);
int main(void) {
    int a, b;
    if (scanf("%d %d", &a, &b) == 2) {
        if (b != 0) {
            printf("%d %d %d %d", sum(a, b), sub(a, b), mult(a, b), dv(a, b));
        } else {
            printf("%d %d %d n/a", sum(a, b), sub(a, b), mult(a, b));
        }
    } else {
        printf("n/a");
    }
    return 0;
}
int sum(int a, int b) {
    return(a+b);
}
int sub(int a, int b) {
    return(a-b);
}
int mult(int a, int b) {
    return(a*b);
}
int dv(int a, int b) {
    return(a/b);
}
