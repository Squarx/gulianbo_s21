#include <stdio.h>

int Directions(int ball_x, int ball_y, int rocket_1, int rocket_2);
int vectorX = -1;
int vectorY = -1;
int scorer = 0;
int scorel = 0;

int main() {
    int PB_X = 41, PB_Y = 13;
    char c = ' ';
    int y1 = 13, y2 = 13;
    int switchpl = 1;

    printf("Choose your gamemode:\n");
    printf("1 : 1 player - 1 move\n");
    printf("2 : Some movements at the same time\n");
    scanf("%d", &switchpl);

    while (scorer < 21 && scorel < 21) {
        printf("\33[0d\33[2J");
      if (PB_X == 80) {
          scorer++;
            printf("Right player score: %d\n", scorer);
            PB_X = 41;
            PB_Y = 13;
            vectorX *= -1;
            vectorY *= -1;
        } else {
            printf("Right player score: %d\n", scorer);
        }
        if (PB_X == 2) {
            scorel++;
            printf("Left player score: %d\n", scorel);
            PB_X = 41;
            PB_Y = 13;
            vectorX *= -1;
            vectorY *= -1;
        } else {
            printf("Left player score: %d\n", scorel);
        }

  for (int i = 1; i <= 25; i++) {
    for (int j = 1; j <= 80; j++) {
        if (PB_X == j && PB_Y == i) {
            printf("O");
            continue;
        }
        if (i == 1 || i == 25) {
            printf("—");
            continue;
        }
        if (j == 1 || j == 80 || j == 40 || j == 41) {
            printf("|");
            continue;
        }
        if (j == 5 && (i == y1 - 1 || i == y1 || i == y1 + 1)) {
            printf("*");
            continue;
        }
        if (j == 75 && (i == y2 - 1 || i == y2 || i == y2 + 1)) {
            printf("*");
            continue;
        }
            printf(" ");
        }
      printf("\n");
    }

    switch (switchpl) {
        case 3 :
            switchpl = 1; printf("PLAYER 1\n");
            switch (c) {
            case 'z' :
            if (y1 < 23)
                y1 = y1 + 1;
            break;
            case 'a' :
            if (y1 > 3)
                y1 = y1 - 1;
            break;
            case ' ' : break;
            default : break;
            }
            scanf("%c", &c);
            rewind(stdin);
            if (c != '\n') {
            Directions(PB_X, PB_Y, y1, y2);
            PB_X += vectorX;
            PB_Y += vectorY;
            continue;
            }
            break;

    case 1 : switchpl = 3; printf("PLAYER 2\n");
            switch (c) {
            case 'm' :
            if (y2 < 23)
                y2 = y2 + 1;
            break;
            case 'k' :
            if (y2 > 3)
                y2 = y2 - 1;
            break;
            case ' ' : break;
            default : break;
            }
            scanf("%c", &c);
            rewind(stdin);
            if (c != '\n') {
            PB_X += vectorX;
            PB_Y += vectorY;
            continue;
            }
            break;
    case 2 :
        switch (c) {
            case 'z' :
            if (y1 < 23)
                y1 = y1 + 1;
            break;
            case 'a' :
            if (y1 > 3)
                y1 = y1 - 1;
            break;
            case 'm' :
            if (y2 < 23)
                y2 = y2 + 1;
            break;
            case 'k' :
            if (y2 > 3)
                y2 = y2 - 1;
            break;
            case ' ' : break;
            default : break;
        }
            scanf("%c", &c);
            if (c != '\n') {
            Directions(PB_X, PB_Y, y1, y2);
            PB_X += vectorX;
            PB_Y += vectorY;
            continue;
            }
            break;
    }
}
    if (scorel == 21) {
    printf("\n..... .   ..... .   . ... .....  .   ... ... .....  .       . * :.  :  :\n");
    printf(":...: :   :...: :...: :.. :...:  :   :.. :..   :    :   .   : : : . :  :\n");
    printf(":     :.. :   :   :   :.. : :..  :.. :.. :     :     ..  ..   : :  .:  o\n");
    }
    if (scorel == 21) {
    printf("..... .   ..... .   . ... .....  ..... *  ... .  . ..... .       . * :.  :  :\n");
    printf(":...: :   :...: :...: :.. :...:  :...: : :... :..:   :   :   .   : : : . :  :\n");
    printf(":     :.. :   :   :   :.. : :..  : :.. : :..: :  :   :    ..  ..   : :  .:  o\n");}
    return 0;
    }

int Directions(int ball_x, int ball_y, int rocket_1, int rocket_2) {
    if (vectorY == -1 && ball_x == 6) {
        if (ball_y + vectorY == rocket_1 + 1) {
            vectorX = -1 * vectorX;
            vectorY = -1 * vectorY;
        }
        if (ball_y + vectorY == rocket_1 || ball_y + vectorY  == rocket_1 - 1)
            vectorX = -1 * vectorX;
    }
    if (vectorY == 1 && ball_x == 6) {
        if (ball_y + vectorY == rocket_1 - 1) {
            vectorX = -1 * vectorX;
            vectorY = -1 * vectorY;
        }
        if (ball_y + vectorY == rocket_1 || ball_y + vectorY  == rocket_1 + 1)
            vectorX = -1 * vectorX;
    }
    if (ball_y == 24)
        vectorY = -1;
    if (ball_y == 2)
        vectorY = 1;
    if (vectorY == 1 && ball_x == 73) {
        if (ball_y + vectorY == rocket_2 - 1) {
            vectorX = -1 * vectorX;
            vectorY = -1 * vectorY;
        }
        if (ball_y + vectorY == rocket_2 || ball_y + vectorY  == rocket_2 + 1)
            vectorX = -1 * vectorX;
    }
    if (vectorY == -1 && ball_x == 73) {
        if (ball_y + vectorY == rocket_2 + 1) {
            vectorX = -1 * vectorX;
            vectorY = -1 * vectorY;
        }
        if (ball_y + vectorY == rocket_2 || ball_y + vectorY  == rocket_2 - 1)
            vectorX = -1 * vectorX;
    }
    return 0;
}

