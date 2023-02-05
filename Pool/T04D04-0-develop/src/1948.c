#include <stdio.h>
int num_of_del(int a);
int ostatok(int a, int b);
int posit(int x);
int solved(int x);
int main(void) {
    int x;
    if (scanf("%d", &x) == 1) {
        if (posit(x) > 1) {
            solved(x);
        } else {
            printf("n/a");
        }
    } else {
        printf("n/a");
    }
return 0;
}
int num_of_del(int a) {
    int ostatok(int a, int b);
    int i, cnt = 1;
    for ( i = a - 1; i > 1; i = i - 1 ) {
        if (ostatok(a, i) == 0) {
            cnt += 1;
        }
    }
    return cnt;
}
int ostatok(int a, int b) {
    int res = a;
    while (res >= b) {
        res -= b;
    }
    return res;
}
int posit(int x) {
    int a;
    if (x >= 0) {
        a = x;
        } else {
        a = -x;
        }
    return a;
}
int solved(int x) {
    int a, i;
    a = posit(x);
        for ( i = a; i > 1; i -= 1 ) {
            if ((ostatok(a, i) == 0) && (num_of_del(i) == 1)) {
                break;
            }
        }
    printf("%d", i);
return 0;
}

