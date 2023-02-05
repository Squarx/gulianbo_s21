#include <stdio.h>
#include "modules.h"
#include "levels.h"
#include "status_events.h"
void printMenu(void);
void swither(void);
void select(void);
int main () {
    printMenu();
    swither();

    return 0;
}
void printMenu(void) {
    printf("Please choose one operation:\n");
    printf("\t1. SELECT\n");
    printf("\t2. INSERT\n");
    printf("\t3. UPDATE\n");
    printf("\t4. DELETE\n");
    printf("\t5. Get all active additional modules (last module status is 1)\n");
    printf("\t6. Delete modules by ids\n");
    printf("\t7. Set protected mode for module by id\n");
    printf("\t8. Move module by id to specified memory level and cell\n");
    printf("\t9. Set protection flag of the specified memory level\n");
}
void swither(void) {
    int input;
    if (!scanf("%d", &input)) {
        printf("n/a");
    } else {
        switch (input)
        {
        case 1:
            select();
            break;
        
        default:
            break;
        }
    }
}
void select(void) {
    printf("Please choose a table:\n \
                1. Modules\n \
                2. Levels\n \
                3. Status events\n");
    int input;
    if (!scanf("\n %d", &input)) {
        printf("n/a");
    } else {
        switch (input)
        {
        case 1:
            sel_modules();
            break;
        case 2 :
            sel_levels();
            break;
        case 3 :
            sel_EV();
            break;
        default:
            printf("n/a");
            break;
        }
    }
}
