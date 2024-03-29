#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>
#define s21_NULL ((void *)0)
typedef long unsigned s21_size_t;

#if defined __APPLE__ || defined __MACH__
#define s21_error                                                       \
    {                                                                          \
        "Undefined error: 0", "Operation not permitted", "No such file or directory",                \
            "No such process", "Interrupted system call",                      \
            "Input/output error", "Device not configured",                     \
            "Argument list too long", "Exec format error",                     \
            "Bad file descriptor", "No child processes",                       \
            "Resource deadlock avoided", "Cannot allocate memory",             \
            "Permission denied", "Bad address", "Block device required",       \
            "Resource busy", "File exists", "Cross-device link",               \
            "Operation not supported by device", "Not a directory",            \
            "Is a directory", "Invalid argument",                              \
            "Too many open files in system", "Too many open files",            \
            "Inappropriate ioctl for device", "Text file busy",                \
            "File too large", "No space left on device", "Illegal seek",       \
            "Read-only file system", "Too many links", "Broken pipe",          \
            "Numerical argument out of domain", "Result too large",            \
            "Resource temporarily unavailable", "Operation now in progress",   \
            "Operation already in progress", "Socket operation on non-socket", \
            "Destination address required", "Message too long",                \
            "Protocol wrong type for socket", "Protocol not available",        \
            "Protocol not supported", "Socket type not supported",             \
            "Operation not supported", "Protocol family not supported",        \
            "Address family not supported by protocol family",                 \
            "Address already in use", "Can't assign requested address",        \
            "Network is down", "Network is unreachable",                       \
            "Network dropped connection on reset",                             \
            "Software caused connection abort", "Connection reset by peer",    \
            "No buffer space available", "Socket is already connected",        \
            "Socket is not connected", "Can't send after socket shutdown",     \
            "Too many references: can't splice", "Operation timed out",        \
            "Connection refused", "Too many levels of symbolic links",         \
            "File name too long", "Host is down", "No route to host",          \
            "Directory not empty", "Too many processes", "Too many users",     \
            "Disc quota exceeded", "Stale NFS file handle",                    \
            "Too many levels of remote in path", "RPC struct is bad",          \
            "RPC version wrong", "RPC prog. not avail",                        \
            "Program version wrong", "Bad procedure for program",              \
            "No locks available", "Function not implemented",                  \
            "Inappropriate file type or format", "Authentication error",       \
            "Need authenticator", "Device power is off", "Device error",       \
            "Value too large to be stored in data type",                       \
            "Bad executable (or shared library)",                              \
            "Bad CPU type in executable", "Shared library version mismatch",   \
            "Malformed Mach-o file", "Operation canceled",                     \
            "Identifier removed", "No message of desired type",                \
            "Illegal byte sequence", "Attribute not found", "Bad message",     \
            "EMULTIHOP (Reserved)", "No message available on STREAM",          \
            "ENOLINK (Reserved)", "No STREAM resources", "Not a STREAM",       \
            "Protocol error", "STREAM ioctl timeout",                          \
            "Operation not supported on socket", "Policy not found",           \
            "State not recoverable", "Previous owner died",                    \
            "Interface output queue is full"                                    \
    }

#else
#define s21_error                                                        \
    {                                                                          \
        "Undefined error 0", "Operation not permitted", "No such file or directory",                \
            "No such process", "Interrupted system call",                      \
            "Input/output error", "No such device or address",                 \
            "Argument list too long", "Exec format error",                     \
            "Bad file descriptor", "No child processes",                       \
            "Resource temporarily unavailable", "Cannot allocate memory",      \
            "Permission denied", "Bad address", "Block device required",       \
            "Device or resource busy", "File exists",                          \
            "Invalid cross-device link", "No such device", "Not a directory",  \
            "Is a directory", "Invalid argument",                              \
            "Too many open files in system", "Too many open files",            \
            "Inappropriate ioctl for device", "Text file busy",                \
            "File too large", "No space left on device", "Illegal seek",       \
            "Read-only file system", "Too many links", "Broken pipe",          \
            "Numerical argument out of domain",                                \
            "Numerical result out of range", "Resource deadlock avoided",      \
            "File name too long", "No locks available",                        \
            "Function not implemented", "Directory not empty",                 \
            "Too many levels of symbolic links", "Unknown error 41",           \
            "No message of desired type", "Identifier removed",                \
            "Channel number out of range", "Level 2 not synchronized",         \
            "Level 3 halted", "Level 3 reset", "Link number out of range",     \
            "Protocol driver not attached", "No CSI structure available",      \
            "Level 2 halted", "Invalid exchange",                              \
            "Invalid request descriptor", "Exchange full", "No anode",         \
            "Invalid request code", "Invalid slot", "Unknown error 58",        \
            "Bad font file format", "Device not a stream",                     \
            "No data available", "Timer expired", "Out of streams resources",  \
            "Machine is not on the network", "Package not installed",          \
            "Object is remote", "Link has been severed", "Advertise error",    \
            "Srmount error", "Communication error on send", "Protocol error",  \
            "Multihop attempted", "RFS specific error", "Bad message",         \
            "Value too large for defined data type",                           \
            "Name not unique on network", "File descriptor in bad state",      \
            "Remote address changed",                                          \
            "Can not access a needed shared library",                          \
            "Accessing a corrupted shared library",                            \
            ".lib section in a.out corrupted",                                 \
            "Attempting to link in too many shared libraries",                 \
            "Cannot exec a shared library directly",                           \
            "Invalid or incomplete multibyte or wide character",               \
            "Interrupted system call should be restarted",                     \
            "Streams pipe error", "Too many users",                            \
            "Socket operation on non-socket", "Destination address required",  \
            "Message too long", "Protocol wrong type for socket",              \
            "Protocol not available", "Protocol not supported",                \
            "Socket type not supported", "Operation not supported",            \
            "Protocol family not supported",                                   \
            "Address family not supported by protocol",                        \
            "Address already in use", "Cannot assign requested address",       \
            "Network is down", "Network is unreachable",                       \
            "Network dropped connection on reset",                             \
            "Software caused connection abort", "Connection reset by peer",    \
            "No buffer space available",                                       \
            "Transport endpoint is already connected",                         \
            "Transport endpoint is not connected",                             \
            "Cannot send after transport endpoint shutdown",                   \
            "Too many references: cannot splice", "Connection timed out",      \
            "Connection refused", "Host is down", "No route to host",          \
            "Operation already in progress", "Operation now in progress",      \
            "Stale file handle", "Structure needs cleaning",                   \
            "Not a XENIX named type file", "No XENIX semaphores available",    \
            "Is a named type file", "Remote I/O error", "Disk quota exceeded", \
            "No medium found", "Wrong medium type", "Operation canceled",      \
            "Required key not available", "Key has expired",                   \
            "Key has been revoked", "Key was rejected by service",             \
            "Owner died", "State not recoverable",                             \
            "Operation not possible due to RF-kill",                           \
            "Memory page has hardware error"                                   \
    }
#endif

s21_size_t s21_strlen(const char *str);
int s21_strcmp(const char *str1, const char *str2);
int s21_strncmp(const char *str1, const char *str2, size_t n);
char *s21_strcpy(char *dest, const char *src);
char *s21_strncpy(char *dest, const char *src, size_t n);
char *s21_strcat(char *dest, const char *src);
char *s21_strncat(char *dest, const char *src, size_t n);
char *s21_strchr(const char *str, int c);
char *s21_strrchr(const char *str, int c);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);
void *s21_memchr(const void *str, int c, size_t n);
int s21_memcmp(const void *str1, const void *str2, size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memmove(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strpbrk(const char *str1, const char *str2);
s21_size_t s21_strspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);
void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);

// sprintf_func and sscanf functions and structures

#define notation_check(c) (c) == 'e' || (c) == 'E' || (c) == 'f' || (c) == 'G' || (c) == 'g'
#define numb_check(c) ((c) >= '0' && (c) <= '9')
#define sign_check(c) (c) == '-' || (c) == '+'
#define abc_check(c) ((c) >= 'A' && (c) <= 'F') || ((c) >= 'a' && (c) <= 'f') || (c) == 'x' || (c) == 'X'
#define spec_letter_check(c) (c) == 'c' || (c) == 'd' || (c) == 'u' || (c) == 'i' || notation_check(c) || (c) == 'o' || (c) == 's' || (c) == 'x' || (c) == 'X' || (c) == 'p' || (c) == 'n'
#define tab_check(c) (c) == '\t' || (c) == '\n' || (c) == '\0'

typedef struct flags {
  int width; // ширина
  int error;
  char lengh; // длина
  char spec;
  int end;
  int count_format;
  int exit;
  int count_scan;
  int pos;
  int len_point;
  char sign;
  int type;
  void *pointer;
}Fl;

int s21_sscanf(const char *str, const char *format, ...);
void parser(Fl *flag, const char *format, const char *str);
void spec_check(va_list *list, Fl *flag, const char *str);
void str_parsing(Fl *flag, va_list *list, const char *str);
void char_parsing(Fl *flag, va_list *list, const char *str);
void numb_parsing(Fl *flag, va_list *list, const char *str);
void add_to_list_for_numb(Fl *flag, va_list *list, long int result, long double d_result);
void add_to_list_sixnumb(Fl *flag, va_list *list, unsigned long long int result);
void add_to_list_eightnumb(Fl *flag, va_list *list, long long int result);
void numb_point_parsing(Fl *flag, va_list *list, const char *str);
void if_e(Fl *flag, const char *str, int *len, long double *result);
void result_mul(long double *result, int *len);
void result_count(Fl *flag, const char *str, long double *result, int *flag_w);
int numb_counter(Fl *flags, const char *str, int pos);
unsigned long long int s21_pow(int numb, int pow);
void sixteen_numb(Fl *flag, va_list *list, const char *str);
void c_check(Fl *flag, int *c, const char *str);
void type_check(Fl *flag, const char *str);
void eight_parsing(Fl *flag, va_list *list, const char *str);

typedef struct options {
  int f_minus;
  int f_plus;
  int f_space;
  int f_sharp;
  int f_zero;
  int width;
  int accuracy;
  char length;
  char specifier;
} OPT;
int s21_sprintf(char *str, const char *format, ...);
void make_token_d(unsigned long long num, char *string);
unsigned long long get_closestULL(unsigned long long num, unsigned long long delitel);
void add_accur_dui(char *src, OPT *opt_orig);
void add_sign(char *src, OPT *opt_orig);
void add_width(char *src, OPT *opt_orig);
void set_to_zero(char* src);
void print_res(char* arr1, char* arr2);
int make_mantissa(long double *num);
int positive(long double num);
char *build_string(OPT *opt, char *string, char *tmp, char sign_of_num, char sign_of_pow, int cnt_of_pow);
void def_signs(long double num, char *sign_of_num, char *sign_of_pow, OPT* opt);
void round_array(char *tmp, int accuracy, int *cnt_of_pow);
void my_itoa(long double num, char *string);
void make_float_to_arr(long double num, char* tmp, int* ind_tmp,  OPT* opt);
void insert_dot(char* dest);
void round_float(char *tmp, int ind_start_round, int ind_tmp_start_num, int *ind_last_int);
void get_rid_zero(char *tmp, OPT* opt);
void my_itoa_Lf_and_maker_mantiese(long double* num, char *string);
char *mem_reverse(char *arr, int n);
char *convert_to_8(char *dest, unsigned long long num);
void insert_flag_sharp(char* tmp, OPT* opt);
char *convert_to_16(char *dest, unsigned long long num, char capital);
void make_ready_u(char *src, OPT *opt_orig);

//
char *get_flag(char *cursor, OPT *options);
char *get_width(char *cursor, OPT *options, va_list *curr_arg);
char *get_accur(char *cursor, OPT *options, va_list *curr_arg);
char *get_len(char *cursor, OPT *options);
char *get_spec(char *cursor, OPT *options);
char* fill_struct(char* cursor, OPT* opt, va_list* curr_arg);
//
char *write_to_arr(char *string, OPT opt, va_list *curr_arg);
char* i_hate_flag_c(int c, char *string, OPT opt);
char *i_hate_flag_e(long double num, char *string, OPT *opt);
char *i_hate_flag_f(long double num, char *string, OPT *opt);
char *i_hate_flag_g(long double num, char *string, OPT *opt_orig);
char *i_hate_flag_o(long double num, char *string, OPT *opt_orig);
char *i_hate_flag_X(unsigned long long num, char *string, OPT *opt_orig);
char *i_hate_flag_p(long double num, char *string, OPT *opt_orig);
char *i_hate_flag_s(char *src, char *dest, OPT *opt_orig);
char *i_hate_flag_u(unsigned long long num, char *string, OPT *opt_orig);
char *i_hate_flag_percent(char *string, OPT *opt_orig);
//
char *my_strcpy(char *dest, const char *src);
size_t my_strlen(const char *str);
void *my_memmove(void *dest, const void *src, size_t n);
char *my_strchr(const char *str, int c);
void *my_memcpy(void *dest, const void *src, size_t n);


#endif  // SRC_S21_STRING_H_
