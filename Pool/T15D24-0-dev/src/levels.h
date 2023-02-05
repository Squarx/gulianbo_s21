#ifndef SRC_LEVELS_H_
#define SRC_LEVELS_H_
#include <stdio.h>
#include <stdlib.h>
typedef struct Levels
{
    int lMemory;
    int cntCells;
    int flagDef;
}LEV;
void print_all_levels(FILE* file);
void print_levels(LEV record);
int get_records_count_in_file_lev(FILE *pfile);
int get_file_size_in_bytes_lev(FILE *pfile);
struct Levels read_record_from_file_levels(FILE *pfile, int index);
void print_some_levels(FILE* file, int len);
void sel_levels(void);
#endif