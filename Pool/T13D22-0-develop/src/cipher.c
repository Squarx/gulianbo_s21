#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include "log_levels.h"
#include "logger.h"
#define M_DEBUG " DEBUGGING"
#define M_TRACE "Tracing programm"
#define M_INFO "something about program"
#define M_WARN "Chto to opasnoe"
#define M_ERR   "Voobshe oshibka"
void quest_1();
#ifdef LOG
void reader(char* path, int* flag, int* flag_empty , FILE* log);
void add_str(void);
void quest_2(char *path, int* flag, int* flag_empty, FILE* log);
void coder(char* path, char* fileName, int* flag, int* flag_empty, int key, FILE* log);
void H_cleaner(char* path, char* fileName, FILE* log);
void case_3(FILE* log);
#endif
#ifdef USUAL
void quest_2U(char *path, int* flag, int* flag_empty);
void coderU(char* path, char* fileName, int* flag, int* flag_empty, int key);
void H_cleanerU(char* path, char* fileName);
void case_3U(void);
void readerU(char* path, int* flag, int* flag_empty);
#endif
int main() {
    quest_1();
    return 0;
}
#ifdef LOG
void reader(char* path, int* flag, int* flag_empty, FILE* log) {
    FILE* f;
    int n = 0;
    if ((f = fopen(path, "r"))== NULL) *flag = 0;
    char c;
    if (*flag) {
        #ifdef LOG
        logcat(log, "file was opened", trace);
        #endif
        while (fscanf(f, "%c", &c) == 1) {
        fprintf(stdout, "%c", c);
        n++;
        #ifdef LOG
        logcat(log, M_TRACE, trace);
        #endif
        }
        if (n == 0) *flag_empty = 0;
        fclose(f);
        #ifdef LOG
        logcat(log, "file was closed", trace);
        #endif
    }
}
#endif
void quest_1() {
    #ifdef LOG
    FILE* log = log_init("log.txt");
    #endif
    int flag = 1;
    int input = 1;
    int flag_empty = 1;
    char* path = calloc(100, sizeof(char));
    int first_1 = 0;
    #ifdef LOG
    logcat(log, M_INFO, info);
    #endif
    while (input) {
        flag = 1;
        rewind(stdin);
        if (!scanf("%d", &input)) {
            printf("n/a\n");
            rewind(stdin);
            input = 1;
            continue;
        }
        if (input) {
            switch (input) {
                char str[1];
                case 1 :
                    if (path == NULL) flag = 0;
                    rewind(stdin);
                    if (flag)
                        if (!scanf("%s", path)) flag = 0;
                    #ifdef LOG
                    if (flag) reader(path, &flag, &flag_empty, log);
                    #endif
                    #ifdef USUAL
                    if (flag) readerU(path, &flag, &flag_empty);
                    #endif
                    if (flag && flag_empty) printf("\n");
                    #ifdef LOG
                    logcat(log, M_INFO, info);
                    #endif
                    if (!flag_empty) printf("n/a\n");
                    if (!flag) printf("n/a\n");
                    rewind(stdin);
                    if (flag) first_1 = 1;
                    break;
                case -1 :
                    input = -1;
                    break;
                case 2 :
                    if (first_1 && flag) {
                        #ifdef LOG
                        quest_2(path, &flag, &flag_empty, log);
                        #endif
                        #ifdef USUAL
                        quest_2U(path, &flag, &flag_empty);
                        #endif
                        input = 1;
                        #ifdef LOG
                        logcat(log, M_WARN, warning);
                        #endif
                    } else {
                    scanf("%s", str);
                    #ifdef LOG
                    logcat(log, M_ERR, error);
                    #endif
                    input = 1;
                    printf("n/a\n");
                    }
                    break;
                case 3 :
                    #ifdef LOG
                    case_3(log);
                    #endif
                    #ifdef USUAL
                    case_3U();
                    #endif
                    break;
                default :
                    input = 1;
                    printf("n/a\n");
                    break;
            }
        }
        if (input == -1 || input == 0) break;
    }
    #ifdef LOG
    log_close(log);
    #endif
    free(path);
}
#ifdef LOG
void quest_2(char *path, int* flag, int* flag_empty, FILE* log) {
    rewind(stdin);
    // char str[100];
        char* str = calloc (100, sizeof(char));
        if (str == NULL) *flag = 0;
        if (*flag) {
            rewind(stdin);
            if (!scanf("%[^\n]", str)) *flag = 0;
        }
        if (*flag) {
            FILE* f;
            f = fopen(path, "a+");
            if (!*flag_empty) {
                fprintf(f, "%s", str);
            } else {
                fprintf(f, "\n%s", str);
            }
            fclose(f);
            #ifdef LOG
            reader(path, flag, flag_empty, log);
            #endif
            printf("\n");
        }
        if (!*flag) printf("n/a");
        free(str);
}
#endif
#ifdef LOG
void coder(char* path, char* fileName, int* flag, int* flag_empty, int key, FILE* log) {
    FILE* tmp;
    char* tmpFile = calloc(20, sizeof(char));
    strcpy(tmpFile, "");
    tmpFile = strcpy(tmpFile, path);
    tmpFile = strcat(strcat(tmpFile, "tmp"), fileName);
    if ((tmp = fopen(tmpFile, "w")) == NULL) {
        printf("n/a");
        #ifdef LOG
        logcat(log, M_ERR, error);
        #endif
    }
    FILE* f;
    char* origFile = calloc(20, sizeof(char));
    origFile = strcat(strcpy(origFile, path), fileName);
    int n = 0;
    if ((f = fopen(origFile, "r"))== NULL) *flag = 0;
    char c;
    if (*flag) {
        while (fscanf(f, "%c", &c) == 1) {
            if (c >= 'A' && c <= 'Z') {
                #ifdef LOG
                logcat(log, M_INFO, info);
                #endif
                fprintf(tmp, "%c", ((((int)c + key - 65) % 26)) + 65);
            } else if (c >= 'a' && c <= 'z') {
                #ifdef LOG
                logcat(log, M_INFO, info);
                #endif
                fprintf(tmp, "%c", (((int)c + key - 97) % 26) + 97);
            } else {
                #ifdef LOG
                logcat(log, M_INFO, info);
                #endif
                fprintf(tmp, "%c", c);
            }
            n++;
        }
        if (n == 0) *flag_empty = 0;
    }
    fclose(tmp);
    fclose(f);
    if (remove(origFile) == -1) {
        printf("remove()");
        #ifdef LOG
        logcat(log, M_ERR, error);
        #endif
    }
    if (rename(tmpFile, origFile) == -1) {
        printf("rename()");
        #ifdef LOG
        logcat(log, M_ERR, error);
        #endif
    }
    free(tmpFile);
    free(origFile);
    #ifdef LOG
    logcat(log, "File freed succeed", error);
    #endif
}
#endif
#ifdef LOG
void H_cleaner(char* path, char* fileName, FILE* log) {
    FILE* file;
    char* fname;
    #ifdef LOG
    logcat(log, M_INFO, info);
    #endif
    fname = strcat(path, fileName);
    file = fopen(fname, "w");
    fclose(file);
    #ifdef LOG
    logcat(log, "File freed succeed", error);
    #endif
}
#endif
#ifdef LOG
void case_3(FILE* log) {
    int flag = 1;
    int emp = 1;
    DIR* direcory;
        struct dirent* entry;
        char* path;
        int key;
        path = calloc(100, sizeof(char));
        printf(" PATH  = %s", path);
        printf("Path = \n");
        scanf("%s", path);
        printf("Key = \n");
        scanf("%d", &key);
        if ((direcory = opendir(path)) != NULL) {
            while ((entry = readdir(direcory)) != NULL) {
                if (entry->d_name[strlen(entry->d_name) - 1] == 'c' &&
                entry->d_name[strlen(entry->d_name) - 2] == '.') {
                    char* p_1 = calloc(100, sizeof(char));
                    strcpy(p_1, path);
                    printf("File.c start coding= %s\n", entry->d_name);
                    coder(p_1, entry->d_name, &flag, &emp, key, log);
                    printf("File.c coding done = %s\n", entry->d_name);
                    free(p_1);
                }
                if (entry->d_name[strlen(entry->d_name) - 1] == 'h' &&
                entry->d_name[strlen(entry->d_name) - 2] == '.') {
                    printf("File.h cleaning start= %s\n", entry->d_name);
                    char* p_2 = calloc(100, sizeof(char));
                    strcpy(p_2, path);
                    H_cleaner(p_2, entry->d_name, log);
                    printf("File.h cleaning DONE= %s\n", entry->d_name);
                    free(p_2);
                }
            }
            if (closedir(direcory) == -1) {
            printf("Eror cloding\n");
            #ifdef LOG
            logcat(log, M_ERR, error);
            #endif
            }
        } else {
            printf("Dir isn't exist\n");
            #ifdef LOG
            logcat(log, M_ERR, error);
            #endif
        }
        free(path);
}
#endif
#ifdef USUAL
void quest_2U(char *path, int* flag, int* flag_empty) {
    rewind(stdin);
    // char str[100];
        char* str = calloc (100, sizeof(char));
        if (str == NULL) *flag = 0;
        if (*flag) {
            rewind(stdin);
            if (!scanf("%[^\n]", str)) *flag = 0;
        }
        if (*flag) {
            FILE* f;
            f = fopen(path, "a+");
            if (!*flag_empty) {
                fprintf(f, "%s", str);
            } else {
                fprintf(f, "\n%s", str);
            }
            fclose(f);
            readerU(path, flag, flag_empty);
            printf("\n");
        }
        if (!*flag) printf("n/a");
        free(str);
}
void coderU(char* path, char* fileName, int* flag, int* flag_empty, int key) {
    FILE* tmp;
    char* tmpFile = calloc(20, sizeof(char));
    strcpy(tmpFile, "");
    tmpFile = strcpy(tmpFile, path);
    tmpFile = strcat(strcat(tmpFile, "tmp"), fileName);
    if ((tmp = fopen(tmpFile, "w")) == NULL) {
        printf("n/a");
    }
    FILE* f;
    char* origFile = calloc(20, sizeof(char));
    origFile = strcat(strcpy(origFile, path), fileName);
    int n = 0;
    if ((f = fopen(origFile, "r"))== NULL) *flag = 0;
    char c;
    if (*flag) {
        while (fscanf(f, "%c", &c) == 1) {
            if (c >= 'A' && c <= 'Z') {
                fprintf(tmp, "%c", ((((int)c + key - 65) % 26)) + 65);
            } else if (c >= 'a' && c <= 'z') {
                fprintf(tmp, "%c", (((int)c + key - 97) % 26) + 97);
            } else {
                fprintf(tmp, "%c", c);
            }
            n++;
        }
        if (n == 0) *flag_empty = 0;
    }
    fclose(tmp);
    fclose(f);
    if (remove(origFile) == -1) {
        printf("remove()");
    }
    if (rename(tmpFile, origFile) == -1) {
        printf("rename()");
    }
    free(tmpFile);
    free(origFile);
}
void H_cleanerU(char* path, char* fileName) {
    FILE* file;
    char* fname;
    fname = strcat(path, fileName);
    file = fopen(fname, "w");
    fclose(file);
}
void case_3U(void) {
    int flag = 1;
    int emp = 1;
    DIR* direcory;
        struct dirent* entry;
        char* path;
        int key;
        path = calloc(100, sizeof(char));
        printf(" PATH  = %s", path);
        printf("Path = \n");
        scanf("%s", path);
        printf("Key = \n");
        scanf("%d", &key);
        if ((direcory = opendir(path)) != NULL) {
            while ((entry = readdir(direcory)) != NULL) {
                if (entry->d_name[strlen(entry->d_name) - 1] == 'c' &&
                entry->d_name[strlen(entry->d_name) - 2] == '.') {
                    char* p_1 = calloc(100, sizeof(char));
                    strcpy(p_1, path);
                    printf("File.c start coding= %s\n", entry->d_name);
                    coderU(p_1, entry->d_name, &flag, &emp, key);
                    printf("File.c coding done = %s\n", entry->d_name);
                    free(p_1);
                }
                if (entry->d_name[strlen(entry->d_name) - 1] == 'h' &&
                entry->d_name[strlen(entry->d_name) - 2] == '.') {
                    printf("File.h cleaning start= %s\n", entry->d_name);
                    char* p_2 = calloc(100, sizeof(char));
                    strcpy(p_2, path);
                    H_cleanerU(p_2, entry->d_name);
                    printf("File.h cleaning DONE= %s\n", entry->d_name);
                    free(p_2);
                }
            }
            if (closedir(direcory) == -1) {
            printf("Eror cloding\n");
            }
        } else {
            printf("Dir isn't exist\n");
        }
        free(path);
}
void readerU(char* path, int* flag, int* flag_empty) {
    FILE* f;
    int n = 0;
    if ((f = fopen(path, "r"))== NULL) *flag = 0;
    char c;
    if (*flag) {
        while (fscanf(f, "%c", &c) == 1) {
        fprintf(stdout, "%c", c);
        n++;
        }
        if (n == 0) *flag_empty = 0;
        fclose(f);
    }
}
#endif
