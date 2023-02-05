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
int get_file_size_in_bytes(FILE *pfile);
int get_records_count_in_file(FILE *pfile);
int getdate(int* day, int* month, int* year);
void get_code(FILE* file);
void quest_1(char* path);
struct my_struct read_record_from_file(FILE *pfile, int index);
int main() {
    char path[255];
    scanf("%s", path);
    quest_1(path);
    return 0;
}
void quest_1(char* path) {
    FILE* f;
    if ((f = fopen(path, "rb+")) != NULL) {
        get_code(f);
    } else {
        printf("n/a");
    }
    fclose(f);
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
            read_record_from_file(file, i).year  == year) {
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
