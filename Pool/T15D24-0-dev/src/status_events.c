#include "status_events.h"
void sel_EV(void) {
    FILE* f;
    char c;
    char* input = calloc(1, sizeof(char));
    f = fopen("../materials/master_status_events.db", "rb");
    printf("Write a number for printing or press ENTER to see all\n");
    scanf("%c", &c);
    !scanf("%[^\n]", input)
        ? print_all_EV(f)
        : atoi(input)
            ? print_someEV(f, atoi(input))
            : printf("n/a"); 
    fclose(f);
}
void print_all_EV(FILE* file) {
    int len = get_records_count_in_file_EV(file);
    for (int i = 0 ; i < len; i++) {
        print_record_EV(read_record_from_fileEV(file, i));
    }
}
void print_someEV(FILE* file, int len) {
    int max = get_records_count_in_file_EV(file);
    if (len > max) len = max;
    for (int i = 0 ; i < len; i++) {
        print_record_EV(read_record_from_fileEV(file, i));
    }
}
void print_record_EV(EV record) {
    printf("%d %d %d %s %s\n", record.id_event, record.id_module, record.stat_mod, record.date, record.time);
}
int get_records_count_in_file_EV(FILE *pfile) {
    return get_file_size_in_bytesEV(pfile) / sizeof(EV);
}
int get_file_size_in_bytesEV(FILE *pfile) {
    int size = 0;
    fseek(pfile, 0, SEEK_END);
    size = ftell(pfile);
    rewind(pfile);
    return size;
}
EV read_record_from_fileEV(FILE *pfile, int index) {
  int offset = index * sizeof(EV);
    fseek(pfile, offset, SEEK_SET);
    EV record;
    fread(&record, sizeof(EV), 1, pfile);
    rewind(pfile);
    return record;
}

