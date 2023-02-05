#include <stdio.h>
#include <stdlib.h>

int** Dynamic_Allocate2(int height, int weight, int* flag);
void Dy_cleaner2(int height, int  **Arr);
int* To_row(int height, int weight, int** A);
void sort_slow(int* a, int n);
void printer(int* b, int n);
void sort_vertical(int** A, int* B, int h, int w);
void sort_horizontal(int** A, int* B, int h, int w);
void input(int height, int weight, int  **Arr, int* flag);
void output(int height, int weight, int  **Arr);


int main() {
    int height, weight, flag = 1;
    while (1) {
        if (scanf("%d %d", &height, &weight) != 2 || height <= 0 || weight <= 0) {
            flag = 0;
            break;
        }
        int** my_arr = Dynamic_Allocate2(height, weight, &flag);
        if (!flag) break;
        input(height, weight, my_arr, &flag);
        if (!flag) {
            Dy_cleaner2(height, my_arr);
            break;
        }
        int* raw = To_row(height, weight, my_arr);
        if (!flag) {
            Dy_cleaner2(height, my_arr);
            break;
        }
        sort_slow(raw, height * weight);
        sort_vertical(my_arr, raw, height, weight);
        output(height, weight, my_arr);
        printf("\n");
        sort_horizontal(my_arr, raw, height, weight);
        printf("\n");
        output(height, weight, my_arr);
        Dy_cleaner2(height, my_arr);
        free(raw);
        break;
    }
    if (!flag) printf("n/a");
    return 0;
}

void input(int height, int weight, int  **Arr, int* flag) {
    for ( int i = 0; i < height; i++ ) {
            for ( int j = 0; j < weight; j++ ) {
                if (!scanf("%d", &Arr[i][j])) {
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

void sort_vertical(int** A, int* B, int h, int w) {
    int k = 0;
        for (int j = 0; j < w; j++) {
            if (j % 2 != 0) {
                for (int i = h -1; i >= 0; i--) {
                    A[i][j] = B[k];
                    k++;
                }
            } else {
                for (int i = 0; i < h; i++) {
                    A[i][j] = B[k];
                    k++;
                }
            }
        }
}
void sort_horizontal(int** A, int* B, int h, int w) {
    int k = 0;
        for (int i = 0; i < h; i++) {
            if (i % 2 == 1) {
                for (int j = w -1; j >= 0; j--) {
                    A[i][j] = B[k];
                    k++;
                }
            } else {
                for (int j = 0; j < w; j++) {
                    A[i][j] = B[k];
                    k++;
                }
            }
        }
}

int** Dynamic_Allocate2(int height, int weight, int* flag) {
    int** point_arr = malloc(height * sizeof(int*));
    if (point_arr != NULL) {
         for (int i = 0; i < height ; i++) {
             point_arr[i] = malloc(weight*sizeof(int));
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

void Dy_cleaner2(int height, int  **Arr) {
    for ( int i = 0; i < height; i++ ) {
        free(Arr[i]);
    }
    free(Arr);
}
int* To_row(int height, int weight, int** A) {
    int* B = malloc(height* weight * sizeof(int));
    int k = 0;
    for (int i = 0 ; i < height; i++) {
        for (int j = 0; j < weight; j++) {
            B[k] = A[i][j];
            k++;
        }
    }
    return B;
}

void sort_slow(int* a, int n) {
    int save;
    for (int* i = a; i - a < n ; i++) {
        for (int* j = a; j - a < n - 1 ; j++) {
            if (*j > *(j+1)) {
                  save = *j;
                *j = *(j+1);
                *(j+1) = save;
            }
        }
    }
}
void printer(int* b, int n) {
    for (int* a = b; a - b < n ; a++) {
        if ( a - b < n - 1 ) {
            printf("%d ", *a);
        } else {
            printf("%d", *a);
        }
    }
}
