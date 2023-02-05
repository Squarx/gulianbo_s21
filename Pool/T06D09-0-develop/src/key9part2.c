#include <stdio.h>
#define LEN 100
void printer(int* b, int n);
int input(int *a, int* n);
void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);
void sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);

int main() {
    int a[LEN];
    int b[LEN];
    int kolwo;
    int kolwo1;
    int n, n1;
    if (input(a, &kolwo) && input(b, &kolwo1)) {
        int R1[LEN];
        int R2[LEN];
        sum(a, kolwo, b, kolwo1, R1, &n);
        printer(R1, n);
        printf("\n");
        if (kolwo >= kolwo1) {
            sub(a, kolwo, b, kolwo1, R2, &n1);
            printer(R2, n1);
        } else {
            printf("n/a");
        }
    } else {
        printf("n/a");
    }
    return 0;
}

void CopyArray(int* A, int Start,  int End, int* B) {
    int k;
    for (k = Start; k < End; k++)
        B[k] = A[k];
}

void printer(int* b, int n) {
    int cnt = 0;
    int* c = b;
    while (*c == 0) {
        cnt++;
        c++;
    }
    for (int* a = (b + cnt); a - b < n ; a++) {
        if ( a - b < n - 1 ) {
            printf("%d ", *a);
        } else {
            printf("%d", *a);
        }
    }
}

int input(int *a, int* n) {
    int x = 1;
    float pp = 0;
    char pass;
    *n = 0;
    int i = 0;
    do {
        if ((scanf("%f%c", &pp, &pass)) == 2 && pp == (int) pp && pp >=0 && pp <= 9) {
            a[i] = pp;
            *n += 1;
            i++;
        } else {
            x = 0;
            break;
        }
    } while (pass != '\n' || x >= 100);
    return x;
}

void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length) {
    if (len2 > len1) {
        int* help = buff1;
        buff1 = buff2;
        buff2 = help;
        int help_l = len1;
        len1 = len2;
        len2 = help_l;
    }
    int k  = len2 - 1;
    for (int i = len1 - 1; i >= len1 - len2; i--) {
        if (result[i] + buff1[i]+buff2[k] > 9) {
            result[i] = result[i] + (buff1[i] + buff2[k]) % 10;
            result[i - 1] += 1;
        } else {
            result[i] += buff1[i] + buff2[k];
        }
        k--;
        *result_length +=1;
    }
    for (int i = len1 - len2 - 1; i >= 0; i--) {
        result[i] += buff1[i];
        *result_length +=1;
    }
}

void sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length) {
    *result_length = 0;
        int k  = len2 - 1;
        for (int i = len1 - 1; i >= len1 - len2; i--) {
            if (result[i] + buff1[i] - buff2[k] < 0) {
                result[i] += (buff1[i] - buff2[k] + 10) % 10;
                result[i - 1] -= 1;
            } else {
                result[i] += buff1[i] - buff2[k];
            }
            k--;
            *result_length +=1;
        }
        for (int i = len1 - len2 - 1; i >= 0; i--) {
            result[i] += buff1[i];
            *result_length +=1;
        }
}
