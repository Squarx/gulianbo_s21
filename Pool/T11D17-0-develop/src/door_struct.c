#include "door_struct.h"

void set_close(struct door* doors, int n) {
  for (int i = 0; i < n; i++)
    doors[i].status = 0;
}
void output(struct door* doors, int n) {
  for (int i = 0; i < n; i++) {
    if (i < n - 1) {
            printf("%d, %d\n", doors[i].id, doors[i].status);
    } else {
        printf("%d, %d", doors[i].id, doors[i].status);
    }
    }
}
void sort_slow(struct door *a, int n) {
    int save;
    for (int i = 0; i < n ; i++) {
        for (int j = 0; j < n - 1 ; j++) {
            if (a[j].id > a[j+1].id) {
                  save = a[j].id;
                a[j].id =  a[j+1].id;
                 a[j+1].id = save;
            }
        }
    }
}
