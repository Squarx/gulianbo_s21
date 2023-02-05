#include <stdio.h>
#include <stdlib.h>
double** Minor(double ** a, int n, int x);
double det(double ** a, int n);
const int s = 10;
double** Dynamic_Allocate2(int height, int weight, int* flag);
void input(int height, int weight, double  **Arr, int* flag);
void Dy_cleaner2(int height, double  **Arr);

int main() {
    double** a;
    int n , m, flag = 1;
    while (1) {
        if (scanf("%d %d", &n, &m) != 2 || n <= 0 || m <= 0 || n != m) {
            flag = 0;
            break;
        }
        a = Dynamic_Allocate2(n , n, &flag);
        if (!flag) break;
        input(n, n, a, &flag);
        if (!flag) {
            Dy_cleaner2(n, a);
            break;
        }
        printf("%.6lf", det(a, n));
        Dy_cleaner2(n, a);
        break;
    }
    if (!flag) printf("n/a");
    return 0;
}
double** Minor(double ** a, int n, int x) {
    double** minor = malloc((n - 1) * sizeof(double *));
    for (int i = 0; i < n - 1; ++i)
        minor[i] = malloc((n - 1) * sizeof(double));
    for (int i = 1; i < n; ++i)
        for (int j = 0, k = 0; j < n; j++, k++) {
            if (j == x) {
                k--;
                continue;
            }
            minor[i - 1][k] = a[i][j];
        }
    return minor;
}
double det(double ** a, int n) {
    if (n == 1)
        return a[0][0];
    if (n == 2)
        return (a[1][1] * a[0][0]) - (a[0][1] * a[1][0]);
    double res = 0;
    int znak = 1;
    for (int i = 0; i < n; ++i) {
        double** mun = Minor(a, n, i);
        res += znak * a[0][i] * det(mun, n - 1);
        Dy_cleaner2(n - 1, mun);
        znak *= -1;
    }
    return res;
}
double** Dynamic_Allocate2(int height, int weight, int* flag) {
    double** point_arr = malloc(height * sizeof(double*));
    if (point_arr != NULL) {
         for (int i = 0; i < height ; i++) {
             point_arr[i] = malloc(weight*sizeof(double));
             if (point_arr[i] == NULL) {
                 *flag = 0;
                 break;
             }
        }
    } else {
    *flag = 0;
    }
    return point_arr;
}

void Dy_cleaner2(int height, double  **Arr) {
    for ( int i = 0; i < height; i++ ) {
        free(Arr[i]);
    }
    free(Arr);
}

void input(int height, int weight, double  **Arr, int* flag) {
    for ( int i = 0; i < height; i++ ) {
            for ( int j = 0; j < weight; j++ ) {
                if (!scanf("%lf", &Arr[i][j])) {
                    *flag = 0;
                    break;
                }
            }
        }
}
void output(int height, int weight, int  **Arr) {
    for ( int i = 0; i < height; i++ ) {
            for ( int j = 0; j < weight; j++ ) {
                if (j < weight -1) {
                printf("%d ", Arr[i][j]);
                } else {
                    printf("%d", Arr[i][j]);
                }
            }
            if (i < height -1) {
              printf("\n");
            }
        }
}
