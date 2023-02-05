// #include "database.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct test1
{
    int id;
    char name[10];
}TEST1;
typedef struct test2
{
    float GLAG;
    char name[100];
}TEST2;

struct test1* input (void) ;
int main () {
    TEST1* a = input();
    a->id = 5;
    strcpy(a->name, "asdasd");
    
    TEST1* b = input();
    b->id = 5;
    strcpy(b->name, "Bname");
    printf("%s\n", a->name);
    printf("%s", b->name);
    return 0;
}
struct test1* input (void) {
    struct test1* a = calloc (1, sizeof(TEST1));
    return a;
}