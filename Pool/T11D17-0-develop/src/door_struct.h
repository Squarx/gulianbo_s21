#ifndef SRC_DOOR_STRUCT_H_
#define SRC_DOOR_STRUCT_H_
#include <stdio.h>
struct door {
    int id;
    int status;
};
void set_close(struct door* doors, int n);
void output(struct door* doors, int n);
void sort_slow(struct door *a, int n);
#endif  //  SRC_DOOR_STRUCT_H_
