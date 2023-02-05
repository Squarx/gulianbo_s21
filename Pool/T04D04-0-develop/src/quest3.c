#include <stdio.h>
#include<math.h>
int fib(int n);
int positive(int n);
int main(void) {
    int n, fib_sum;
    if (scanf("%d", &n)) {
    fib_sum = fib(n);
    printf("Result = %d", fib_sum);
    } else {
        printf("n/a");
    }
    return 0;
}
int fib(int n) {
    int fib_res, ps;
    if (n >= 0) {
        if (n <= 2) {
            fib_res = 1;
        } else {
            fib_res = (fib(n-1) + fib(n-2));
        }
    } else {
        n = positive(n);
        ps = pow(-1, n+1);
        if (n <= 2) {
            fib_res = ps * 1;
        } else {
            fib_res = ps * ((fib(n-1) + fib(n-2)));
        }
    }
    return fib_res;
}
int positive(int n) {
    int a;
    if (n < 0) {
        a = -n;
    } else {
        a = n;
    }
    return a;
}
