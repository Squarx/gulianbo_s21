#include <stdio.h>
#include <stdlib.h>
typedef struct my_struct  {
    int year;
    int month;
    int day;
    int hour;
    int min;
    int sec;
    int stat;
    int code;
}TEST;
struct my_struct read_record_from_file(FILE *pfile, int index);
void reder_b(char* path);
int copmpre(int a, int b);
int get_records_count_in_file(FILE *pfile);
int get_file_size_in_bytes(FILE *pfile);
void swap_records_in_file(FILE *pfile, int record_index1, int record_index2);
void write_record_in_file(FILE *pfile, const struct my_struct *record_to_write, int index);
void print_all(FILE* file);
void print_record(TEST record);
void sry_bytes(FILE* f);
void quest_1(char* path);
int inputer(TEST* write);
int getdate(int* day, int* month, int* year);
int main() {
    char path[255];
    scanf("%s", path);
    quest_1(path);
    return 0;
}
void quest_1(char* path) {
    FILE* f;
    int input;
    TEST write;
    if ((f = fopen(path, "rb+")) != NULL) {
            if (scanf("%d", &input)) {
                switch (input) {
                    case 0 :
                        if (get_records_count_in_file(f) != 0) {
                            print_all(f);
                        } else {
                            printf("n/a");
                        }
                        break;
                    case 1 :
                        if (get_records_count_in_file(f) != 0) {
                            sry_bytes(f);
                            print_all(f);
                            fclose(f);
                        } else {
                            printf("n/a");
                        }
                        break;
                    case 2 :
                            if (inputer(&write)) {
                                write_record_in_file(f, &write, get_records_count_in_file(f));
                                sry_bytes(f);
                                print_all(f);
                            } else {
                                printf("n/a");
                            }
                        break;
                    default :
                        printf("n/a");
                        break;
                }
        } else {
            printf("n/a");
        }
    } else {
        printf("n/a");
    }
    fclose(f);
}
int inputer(TEST* write) {
    int flag = 1;
    int res = 1;
    if (scanf("%d %d %d %d %d %d %d %d", &write->year, &write->month, &write->day,
    &write->hour, &write->min, &write->sec, &write->stat, &write->code) != 8) flag  = 0;
    if (flag) {
    if (write->year < 0) flag = 0;
    if (write->month < 1 || write->month > 12) flag = 0;
    if (write->month !=2 && (write->day < 1 || write->day > 31)) flag = 0;
    if (write->month ==2 && (write->day < 1 || write->day > 29)) flag = 0;
    if (write->hour < 0 || write->hour > 24) flag = 0;
    if (write->min < 0 || write->min > 60) flag = 0;
    if (write->sec < 0 || write->sec > 60) flag = 0;
    if (write->stat < 0 || write->stat > 1) flag = 0;
    }
    if (!flag) res = 0;
    return res;
}
void sry_bytes(FILE* f) {
    int cnt = get_records_count_in_file(f);
    // printf("CNT  = %d\n", cnt);
    TEST Str_1;
    TEST Str_2;
    for (int i = 0; i < cnt; i++) {
        Str_1 = read_record_from_file(f, i);
            for (int j = 0; j < cnt - 1; j++) {
                Str_2 = read_record_from_file(f, j);
                int flag = 1;
                flag = copmpre(Str_1.year, Str_2.year);
                if (flag == 0) flag = copmpre(Str_1.month, Str_2.month);
                if (flag == 0) flag = copmpre(Str_1.day, Str_2.day);
                if (flag == 0) flag = copmpre(Str_1.hour, Str_2.hour);
                if (flag == 0) flag = copmpre(Str_1.min, Str_2.min);
                if (flag == 0) flag = copmpre(Str_1.sec, Str_2.sec);
                if (flag == -1) {
                    swap_records_in_file(f, j, i);
                    Str_1 = read_record_from_file(f, j);
                }
            }
    }
}

void print_all(FILE* file) {
    int len = get_records_count_in_file(file);
    for (int i =0 ; i < len; i++) {
        print_record(read_record_from_file(file, i));
    }
}
void print_record(TEST record) {
    printf("%d %d %d %d %d %d %d %d\n", record.year, record.month, record.day,
    record.hour, record.min, record.sec, record.stat, record.code);
}

struct my_struct read_record_from_file(FILE *pfile, int index) {
    int offset = index * sizeof(struct my_struct);
    fseek(pfile, offset, SEEK_SET);
    struct my_struct record;
    fread(&record, sizeof(struct my_struct), 1, pfile);
    rewind(pfile);
    return record;
}
int get_records_count_in_file(FILE *pfile) {
    return get_file_size_in_bytes(pfile) / sizeof(TEST);
}
int get_file_size_in_bytes(FILE *pfile) {
    int size = 0;
    fseek(pfile, 0, SEEK_END);
    size = ftell(pfile);
    rewind(pfile);
    return size;
}
void swap_records_in_file(FILE *pfile, int record_index1, int record_index2) {
    struct my_struct record1 = read_record_from_file(pfile, record_index1);
    struct my_struct record2 = read_record_from_file(pfile, record_index2);
    write_record_in_file(pfile, &record1, record_index2);
    write_record_in_file(pfile, &record2, record_index1);
}
void write_record_in_file(FILE *pfile, const struct my_struct *record_to_write, int index) {
    int offset = index * sizeof(struct my_struct);
    fseek(pfile, offset, SEEK_SET);
    fwrite(record_to_write, sizeof(struct my_struct), 1, pfile);
    fflush(pfile);
    rewind(pfile);
}
int copmpre(int a, int b) {
    int res;
    if (a > b) res = 1;
    if (a == b) res = 0;
    if (b > a) res = -1;
    return res;
}
