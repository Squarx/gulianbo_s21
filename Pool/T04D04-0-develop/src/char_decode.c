#include <stdio.h>
void coder(void);
void decoder(void);
int main(int argc, char  *argv[]) {
    if (argc == 2) {
        char a1 = *argv[1];
        if (a1 == '0') {
            coder();
            return 0;
        } else if (a1 == '1') {
            decoder();
            return 0;
        }
    } else {
        printf("n/a");
    }
    return 0;
}
void decoder(void) {
    char d = ' ';
    int c = 0;
    while (1) {
        if ((scanf("%2X%c", &c, &d) == 2) && c != 10) {
            if (d == 32) {
                printf("%c ", c);
            } else if (d == 10) {
                printf("%c", c);
                break;
            } else {
                printf("n/a");
                break;
            }
        } else {
            printf("n/a");
            break;
        }
    }
}
void coder(void) {
    char d = ' ', c = ' ';
    while (1) {
        if (scanf("%c%c", &c, &d) && c != ' ') {
            if (d == ' ') {
                printf("%x ", c);
            } else if (d == 10) {
                printf("%x", c);
                break;
            } else {
                printf("n/a");
                break;
            }
        } else {
            printf("n/a");
            break;
        }
    }
}
