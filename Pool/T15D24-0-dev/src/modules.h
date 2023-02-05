#ifndef SRC_MODULES_H_
#define SRC_MODULES_H_
#include <stdio.h>
#include <stdlib.h>
typedef struct Modules
{
    int id;
    char name_mod[30];
    int lMemory;
    int nCell;
    int flagD;
}MOD;
void print_all(FILE* file);
void print_record(MOD record);
int get_records_count_in_file(FILE *pfile);
int get_file_size_in_bytes(FILE *pfile);
struct Modules read_record_from_file(FILE *pfile, int index);
void print_some(FILE* file, int len);
void sel_modules(void);
#endif