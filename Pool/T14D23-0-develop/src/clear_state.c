#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
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
int get_file_size_in_bytes(FILE *pfile);
int get_records_count_in_file(FILE *pfile);
int getdate(int* day, int* month, int* year);
void get_code(FILE* file);
void quest_1(char* path);
struct my_struct read_record_from_file(FILE *pfile, int index);
void print_all(FILE* file);
void print_record(TEST record);
void write_record_in_file(FILE *pfile, const struct my_struct *record_to_write, int index);
int main() {
    char path[255];
    scanf("%s", path);
    quest_1(path);
    return 0;
}
void quest_1(char* path) {
    FILE* f;
    FILE* test;
    int count = 0;
    test = fopen("try", "wb");
    int y1, m1, d1;
    int y2, m2, d2;
    int flag_min = 0;
    int falg_max = 0;
    if ((f = fopen(path, "rb+")) != NULL) {
        getdate(&d1, &m1, &y1);
        getdate(&d2, &m2, &y2);
        // printf("d1 = %d m1= %d y1 =%d \n", d1,m1,y1);
        // printf("d2 = %d m2= %d y2 =%d \n", d2,m2,y2);
        int len = get_records_count_in_file(f);
        for (int i = 0, k = 0; i < len; i++, k++) {
                flag_min = 0;
                falg_max = 0;
            TEST z = read_record_from_file(f, i);
            if (y1 < z.year + 1 && z.year -1 < y2) {
                flag_min = 1;
                falg_max = 1;
            }
            if (z.year == y1) {
                if (z.month > m1) {
                    flag_min = 1;
                }
                if (z.month == m1) {
                    if (z.day > d1) {
                        flag_min = 1;
                    }
                }
            }
            if (z.year == y2) {
                if (z.month < m2) {
                    falg_max = 1;
                }
                if (z.month == m2) {
                    if (z.day < d2) {
                        falg_max = 1;
                    }
                }
            }
            if (flag_min && falg_max) {
                k--;
            } else {
                count++;
                write_record_in_file(test, &z, k);
            }
        }

        fclose(test);
        fclose(f);
        f = fopen(path, "wb");
        test = fopen("try", "rb");
        for (int i = 0; i < count; i++) {
            TEST temp = read_record_from_file(test, i);
            write_record_in_file(f, &temp, i);
        }
        fclose(test);
        fclose(f);
        f = fopen(path, "rb");
        print_all(f);
        fclose(f);
    } else {
        printf("n/a");
    }
    remove("try");
}

int getdate(int* day, int* month, int* year) {
int res = 1;
if (scanf("%02d.%02d.%04d", day, month, year) != 3) {
    res = 0;
}
return res;
}

void get_code(FILE* file) {
    int day, month, year;
    int flag = 0;
    if (getdate(&day, &month, &year)) {
        int len = get_records_count_in_file(file);
        for (int i = 0 ; i < len; i++) {
            if (read_record_from_file(file, i).day  == day &&
            read_record_from_file(file, i).month  == month &&
            read_record_from_file(file, i).year  == year ) {
                printf("%d", read_record_from_file(file, i).code);
                flag++;
                break;
            }
        }
        if (!flag) printf("n/a");
    } else {
        printf("n/a");
    }
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
void write_record_in_file(FILE *pfile, const struct my_struct *record_to_write, int index) {
    int offset = index * sizeof(struct my_struct);
    fseek(pfile, offset, SEEK_SET);
    fwrite(record_to_write, sizeof(struct my_struct), 1, pfile);
    fflush(pfile);
    rewind(pfile);
}
