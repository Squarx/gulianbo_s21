#include <stdio.h>
void Merge_SORT(int* A, int* B, int n);
int Merge_Split(int* B, int Start, int End, int* A);
void Merge_MERGE(int* A, int Start, int Mid, int End, int* B);
void CopyArray(int* A, int Start,  int End, int* B);
void printer(int* b, int n);
void Quick_Sort(int *A, int ind_l, int ind_r);
int input(int *a);
int less_10(int* n);
int main() {
    int a[10];
    int b[10];
    int c[10];
    int d[10];
    if (input(a)) {
        CopyArray(a, 0, 10, b);
        printf("\n");
        Merge_SORT(b, c, 10);
        CopyArray(a, 0, 10, d);
        Quick_Sort(d, 0, 9);
        printer(b, 10);
        printf("\n");
        printer(d, 10);
    } else {
        printf("n/a");
    }
    return 0;
}

void Merge_SORT(int* A, int* B, int n) {
    CopyArray(A, 0, n, B);
    Merge_Split(B, 0, n, A);
}

int Merge_Split(int* B,  int Start,  int End, int* A) {
    int Mid, x = 1;
    if (End - Start <= 1) {
        x = 0;
        return x;
    }
    Mid = (End + Start) / 2;
    Merge_Split(A, Start,  Mid, B);
    Merge_Split(A, Mid, End, B);
    Merge_MERGE(B, Start, Mid, End, A);
    return 0;
}

void Merge_MERGE(int* A, int Start, int Mid, int End, int* B) {
    int i = Start;
    int j = Mid;
    int k;
    for (k = Start; k < End; k++) {
        if (i < Mid && (j >= End || A[i] <= A[j])) {
            B[k] = A[i];
            i = i + 1;
        } else {
            B[k] = A[j];
            j = j + 1;
        }
    }
}

void CopyArray(int* A, int Start,  int End, int* B) {
    int k;
    for (k = Start; k < End; k++)
        B[k] = A[k];
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

void Quick_Sort(int *A, int ind_l, int ind_r) {
  int pivot;
  int l_hold = ind_l;
  int r_hold = ind_r;
  pivot = A[ind_l];
  while (ind_l < ind_r) {
    while ((A[ind_r] >= pivot) && (ind_l < ind_r))
      ind_r--;
    if (ind_l != ind_r) {
      A[ind_l] = A[ind_r];
      ind_l++;
    }
    while ((A[ind_l] <= pivot) && (ind_l < ind_r))
      ind_l++;
    if (ind_l != ind_r) {
      A[ind_r] = A[ind_l];
      ind_r--;
    }
  }
  A[ind_l] = pivot;
  pivot = ind_l;
  ind_l = l_hold;
  ind_r = r_hold;
  if (ind_l < pivot)
    Quick_Sort(A, ind_l, pivot - 1);
  if (ind_r > pivot)
    Quick_Sort(A, pivot + 1, ind_r);
}

int input(int *a) {
    int x = 1;
    float pp = 0;
        for (int *p = a; p - a < 10; p++) {
            if (!(scanf("%f", &pp) == 1 && pp == (int) pp)) {
                x = 0;
                break;
            } else {
                *p = (int)pp;
            }
        }
    return x;
}
