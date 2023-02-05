#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int Stat_writer(int height, int weight, int arr[height][weight], int* flag);
void Stat_printer(int height, int weight, int Array[height][weight], int *flag);

void Dy_writer(int height, int weight, int  **Arr, int* flag);
void Dy_printer(int height, int weight, int **Arr);

int** Dynamic_Allocate1(int height, int weight, int* flag);
void Dy_cleaner1(int  **Arr);

int** Dynamic_Allocate2(int height, int weight, int* flag);
void Dy_cleaner2(int height, int  **Arr);

int** Dynamic_Allocate3(int height, int weight, int* flag);
void Dy_cleaner3(int  **Arr);

void inputer(int* flag);

int main() {
    int flag = 1;
        inputer(&flag);
  return 0;
}

int Stat_writer(int height, int weight, int arr[height][weight], int* flag) {
    arr[height][weight] = 0;
    for (int i = 0 ; i < height ; i++) {
        for (int j = 0; j < weight; j++) {
            if (!scanf("%d", &arr[i][j])) {
                *flag = 0;
                break;
            }
            if (!*flag) break;
        }
        if (!*flag) break;
    }
    return  arr[height][weight];
}

void Stat_printer(int height, int weight, int Array[height][weight], int *flag) {
    if (*flag) {
           for (int i = 0 ; i < height ; i++) {
            for (int j = 0; j < weight; j++) {
                if (j < weight -1) {
                printf("%d ", Array[i][j]);
                } else {
                printf("%d", Array[i][j]);
                }
            }
               if (i < height -1) {
                 printf("\n");
               }
           }
    }
}
// DYNAMIC PRINTERand WRITER
void Dy_writer(int height, int weight, int  **Arr, int* flag) {
for ( int i = 0; i < height; i++ ) {
        for ( int j = 0; j < weight; j++ ) {
            if (!scanf("%d", &Arr[i][j])) {
                *flag = 0;
                break;
            }
        }
    }
}

void Dy_printer(int height, int weight, int  **Arr) {
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

// DYNAMIC 1
int** Dynamic_Allocate1(int height, int weight, int* flag) {
    int** single_array_matrix = malloc(height * weight * sizeof(int) + height * sizeof(int*));
    if (single_array_matrix != NULL) {
        int* ptr = (int*) (single_array_matrix + height);
        for ( int i = 0; i < height; i++ ) {
        single_array_matrix[i] = ptr + height * i;
        }
    } else {
        *flag = 0;
    }
    return single_array_matrix;
}
void Dy_cleaner1(int **Arr) {
    free(Arr);
}
// DYNAMIC 2


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
// DYNAMC 3
int** Dynamic_Allocate3(int height, int weight, int* flag) {
    int** point_array = malloc (height * sizeof(int*));
    if (point_array != NULL) {
        int* values_array = malloc (height * weight * sizeof(int));
            if (values_array != NULL) {
                for (int i = 0; i < height; i++) {
                    point_array[i] = values_array + weight * i;
                }
            } else {
                *flag = 0;
            }
    } else {
        *flag = 0;
    }
return point_array;
}

void Dy_cleaner3(int  **Arr) {
    free(Arr[0]);
    free(Arr);
}

// INPUT
void inputer(int* flag) {
    while (1) {
    int input;
        if (!scanf("%d", &input)) {
            *flag = 0;
            break;
        }
        if (!*flag) break;
        int height, weight;
        if (scanf("%d %d", &height, &weight) != 2) {
            *flag = 0;
            break;
        }
        if (!*flag) break;
    switch (input) {
        case 1 : {
            if (!(height <= MAX && weight <= MAX && height > 0 && weight > 0)) {
                *flag = 0;
                break;
            }
            int arr_stat[height][weight];
            Stat_writer(height, weight, arr_stat, flag);
            if (!flag) {
                printf("n/a");
            } else {
                Stat_printer(height, weight, arr_stat, flag);
            }
            break;
            }
        case 2 : {
            int **my_arr = Dynamic_Allocate1(height, weight, flag);
            if (!*flag) break;
            Dy_writer(height, weight, my_arr, flag);
            if (!*flag) break;
            Dy_printer(height, weight, my_arr);
            if (!*flag) break;
            Dy_cleaner1(my_arr);
            break;
        }
        case 3 : {
            int** my_arr = Dynamic_Allocate2(height, weight, flag);
            if (!*flag) break;
            Dy_writer(height, weight, my_arr, flag);
            if (!*flag) break;
            Dy_printer(height, weight, my_arr);
            Dy_cleaner2(height, my_arr);
            break;
        }
        case 4 : {
            int** my_arr = Dynamic_Allocate3(height, weight, flag);
            if (!*flag) break;
            Dy_writer(height, weight, my_arr, flag);
            if (!*flag) break;
            Dy_printer(height, weight, my_arr);
            Dy_cleaner3(my_arr);
            break;
        }
        default : {
                *flag = 0;
                break;
            }
    }
        break;
    }
    if (!*flag) printf("n/a");
}

