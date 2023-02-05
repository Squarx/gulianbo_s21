#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "door_struct.h"
#include "list.h"
#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

void initialize_doors(struct door* doors);
void test_add(struct node* test, struct door* doors);
void test_rem(struct node* test);

int main() {
    struct node* test;
    struct door doors[DOORS_COUNT];
    initialize_doors(doors);
    sort_slow(doors, DOORS_COUNT);
    test = init(doors);
    test_add(test, doors);
    test_rem(test);
    destroy(test);
    return 0;
}

void initialize_doors(struct door* doors) {
    srand(time(0));
    int seed = rand() % MAX_ID_SEED;
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].id = (i + seed) % DOORS_COUNT;
        doors[i].status = rand() % 2;
    }
}

void test_add(struct node* test, struct door* doors) {
    printf("Before add ID = %d, STATUS = %d\n", test ->field->id, test->field->status);
    print_struct(test);
    for (int i = 0; i < DOORS_COUNT; i++) {
        add_door(test, &doors[i]);
    }
    printf("After add\n");
    print_struct(test);
    printf("\nSuccess\n");
}
void test_rem(struct node* test) {
    struct node* fined = find_door(14, test);
    printf("For delete ID  = %d , SEARCHED STATUS = %d\n", fined -> field -> id, fined -> field -> status);
    remove_door(fined, test);
    printf("\nPOSLE delete\n");
    print_struct(test);
    printf("\nSuccess\n");
}
