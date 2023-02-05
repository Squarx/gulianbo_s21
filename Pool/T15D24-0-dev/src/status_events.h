#ifndef SRC_STATUS_EVENTS_H_
#define SRC_STATUS_EVENTS_H_
#include <stdio.h>
#include <stdlib.h>
typedef struct Stat_event
{
 int id_event;
 int id_module;
 int stat_mod;
 char date[11];
 char time[9];
}EV;
void print_all_EV(FILE* file);
void print_record_EV(EV record);
int get_records_count_in_file_EV(FILE *pfile);
int get_file_size_in_bytesEV(FILE *pfile);
EV read_record_from_fileEV(FILE *pfile, int index);
void print_someEV(FILE* file, int len);
void sel_EV(void);
#endif