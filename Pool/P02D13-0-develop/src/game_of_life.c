#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#define HEIGHT 25
#define WIDTH 80

int** Allocate(int height, int weight, int* flag);
void MR_Propper(int height, int **Arr);
void Printer(int height, int weight, int **Arr);
void Cleaner(int height, int weight, int **Arr);
void starter(char** Arr, int y, int x);
int Neighbours(int** Arr, int y, int x);
void Life_or_deth(int neighbours, int y, int x, int** Arr_old, int** Arr_new);
void copy(int** a, int** b, int height, int width);
void console_input(int** Arr, int* flag);
void curses_init(void);
void game_menu(int* speed_refresh, int**pole, int** pole_new);
void updater_pole(int**pole, int** pole_new, int* speed_refresh);
void curses_finish(void);

int main(void) {
    int multiplier = 6;
    int flag = 1;
    while (1) {
        int** pole = Allocate(HEIGHT, WIDTH, &flag);
        if (!flag) break;
        int** pole_new = Allocate(HEIGHT, WIDTH, &flag);
        if (!flag) {
            MR_Propper(HEIGHT, pole);
            break;
        }
        console_input(pole, &flag);
        if (!flag) {
            MR_Propper(HEIGHT, pole);
            MR_Propper(HEIGHT, pole_new);
            break;
        }
        curses_init();
        game_menu(&multiplier, pole, pole_new);
        MR_Propper(HEIGHT, pole);
        MR_Propper(HEIGHT, pole_new);
        curses_finish();
        break;
    }
    if (!flag) printf("n/a");
  return 0;
}

int** Allocate(int height, int weight, int* flag) {
  int** point_arr = malloc(height * sizeof(int*));
  if (point_arr != NULL) {
     for (int i = 0; i < height ; i++) {
         point_arr[i] = malloc(weight * sizeof(int));
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

void Printer(int height, int weight, int **Arr) {
    for ( int i = -1; i < height + 1; i++ ) {
        for ( int j = -1; j < weight + 1; j++ ) {
            if (i == -1 || i == height) {
                printw("-");
            } else if (j == -1 || j == weight) {
                printw("|");
            } else if (Arr[i][j] == 1) {
                printw("@");
                } else {
                    printw(" ");
                }
            }
      printw("\n");
    }
}

void Cleaner(int height, int weight, int **Arr) {
    for (int i = 0; i < height; i++) {
        for ( int j = 0; j < weight; j++ ) {
          Arr[i][j] = 0;
        }
    }
}

int Neighbours(int** Arr, int y, int x) {
    int count = 0;
    for (int j = -1; j < 2; j++)
        for (int i = -1; i < 2; i++)
            count += Arr[(i + y + HEIGHT) % HEIGHT][(j + x + WIDTH) % WIDTH];
    count -= Arr[y][x];
    return count;
}

void Life_or_deth(int neighbours, int y, int x, int** Arr_old, int** Arr_new) {
  if (Arr_old[y][x] == 1) {
      if (neighbours == 2 || neighbours == 3) {
        Arr_new[y][x] = 1;
      } else {
          Arr_new[y][x] = 0;
    }
  }
  if (Arr_old[y][x] == 0) {
      if (neighbours == 3) {
        Arr_new[y][x] = 1;
    } else {
        Arr_new[y][x] = 0;
    }
  }
}

void copy(int** a, int** b, int height, int width) {
  for (int i = 0; i < height ; i++) {
    for (int j = 0; j < width; j++) {
      a[i][j] = b[i][j];
    }
  }
}

void MR_Propper(int height, int **Arr) {
    for ( int i = 0; i < height; i++ ) {
        free(Arr[i]);
    }
    free(Arr);
}

void console_input(int** Arr, int* flag) {
    int tmp = 0;
    while (1) {
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                if (scanf("%1d", &tmp) && tmp != '\n') {
                    Arr[i][j] = tmp;
                } else {
                    *flag = 0;
                    break;
                }
            }
            if (!flag) break;
        }
        if (freopen("/dev/tty", "r", stdin) == NULL) {
            *flag = 0;
            break;
        }
        break;
    }
}

void curses_init(void) {
    initscr();
    raw();
    noecho();
    savetty();
    nodelay(stdscr, TRUE);
    curs_set(0);
}

void game_menu(int* multi, int**pole, int** pole_new) {
    int breaker = 1;
    while (1) {
        clear();
        printw("Current speed = %d\n", 11 - *multi);
        printw("SPEED min = 1, SPEED max = 10\n");
        printw("To INCREASE SPEED PRESS 'f'\n");
        printw("To DECREASE SPEED PRESS 's'\n");
        printw("To QIUT PRESS 'q'\n");
        int ch = getch();
        switch (ch) {
            case 's' :
                if (*multi < 10) {
                    *multi += 1;
                    printw("Speed_refresh was decreased\n");
                } else {
                    printw("Speed_refresh was not decreased\n");
                }
                break;
            case 'f' :
                if (*multi > 1) {
                    *multi -= 1;
                    printw("Speed_refresh was increased\n");
                } else {
                    printw("Speed_refresh was not increased\n");
                }
                break;
            case 'q' :
                printw("\nQuit-key was pressed\n");
                breaker = 0;
        }
        if (!breaker) {
            printw("LIFE IS OVER...\n");
            usleep(*multi);
            curs_set(1);
            refresh();
            break;
        }
        printw("\n");
        updater_pole(pole, pole_new, multi);
    }
}
void updater_pole(int**pole, int** pole_new, int* multi) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int a = Neighbours(pole, y, x);
            Life_or_deth(a, y, x, pole, pole_new);
        }
    }
    copy(pole, pole_new, HEIGHT, WIDTH);
    Printer(HEIGHT, WIDTH, pole);
    printw("\n");
    refresh();
    Cleaner(HEIGHT, WIDTH, pole_new);
    usleep(*multi * 10000);
}

void curses_finish(void) {
    curs_set(1);
    clear();
    refresh();
    resetty();
    endwin();
}
