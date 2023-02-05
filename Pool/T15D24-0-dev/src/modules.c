#include "modules.h"
void sel_modules(void) {
    FILE* f;
    char c;
    char* input = calloc(1, sizeof(char));
    f = fopen("../materials/master_modules.db", "rb");
    printf("Write a number for printing or press ENTER to see all\n");
    scanf("%c", &c);
    !scanf("%[^\n]", input)
        ? print_all(f)
        : atoi(input)
            ? print_some(f, atoi(input))
            : printf("n/a"); 
    fclose(f);
}

// Average
void print_all(FILE* file) {
    int len = get_records_count_in_file(file);
    for (int i = 0 ; i < len; i++) {
        print_record(read_record_from_file(file, i));
    }
}
void print_some(FILE* file, int len) {
    int max = get_records_count_in_file(file);
    if (len > max) len = max;
    for (int i = 0 ; i < len; i++) {
        print_record(read_record_from_file(file, i));
    }
}
void print_record(MOD record) {
    printf("%02d %s %d %d %d\n", record.id, record.name_mod, record.lMemory, record.nCell, record.flagD);
}
int get_records_count_in_file(FILE *pfile) {
    return get_file_size_in_bytes(pfile) / sizeof(MOD);
}
int get_file_size_in_bytes(FILE *pfile) {
    int size = 0;
    fseek(pfile, 0, SEEK_END);
    size = ftell(pfile);
    rewind(pfile);
    return size;
}
struct Modules read_record_from_file(FILE *pfile, int index) {
    int offset = index * sizeof(struct Modules);
    fseek(pfile, offset, SEEK_SET);
    struct Modules record;
    fread(&record, sizeof(struct Modules), 1, pfile);
    rewind(pfile);
    return record;
}