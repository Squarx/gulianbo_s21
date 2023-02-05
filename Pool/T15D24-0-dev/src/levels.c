#include "levels.h"
void sel_levels(void) {
    FILE* f;
    char c;
    char* input = calloc(1, sizeof(char));
    f = fopen("../materials/master_levels.db", "rb");
    printf("Write a number for printing or press ENTER to see all\n");
    scanf("%c", &c);
    !scanf("%[^\n]", input)
        ? print_all_levels(f)
        : atoi(input)
            ? print_some_levels(f, atoi(input))
            : printf("n/a"); 
    fclose(f);
}
void print_all_levels(FILE* file) {
    int len = get_records_count_in_file_lev(file);
    for (int i = 0 ; i < len; i++) {
        print_levels(read_record_from_file_levels(file, i));
    }
}
void print_some_levels(FILE* file, int len) {
    int max = get_records_count_in_file_lev(file);
    if (len > max) len = max;
    for (int i = 0 ; i < len; i++) {
        print_levels(read_record_from_file_levels(file, i));
    }
}
void print_levels(LEV record) {
    printf("%d %d %d\n", record.lMemory, record.cntCells, record.flagDef);
}
int get_records_count_in_file_lev(FILE *pfile) {
    return get_file_size_in_bytes_lev(pfile) / sizeof(LEV);
}
int get_file_size_in_bytes_lev(FILE *pfile) {
    int size = 0;
    fseek(pfile, 0, SEEK_END);
    size = ftell(pfile);
    rewind(pfile);
    return size;
}
struct Levels read_record_from_file_levels(FILE *pfile, int index) {
  int offset = index * sizeof(struct Levels);
    fseek(pfile, offset, SEEK_SET);
    struct Levels record;
    fread(&record, sizeof(struct Levels), 1, pfile);
    rewind(pfile);
    return record;
}

