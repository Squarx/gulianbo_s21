#include "s21_string.h"
#include <stdio.h>
void s21_strlen_test(void);
void s21_strcmp_test(void);
void s21_strcpy_test(void);
void s21_strcat_test(void);
void s21_strchr_test(void);
void s21_strstr_test(void);
void s21_strtok_test(void);
#ifdef STRLEN
    #define FUNC() s21_strlen_test()
#endif

#ifdef STRCMP
    #define FUNC() s21_strcmp_test();
#endif
#ifdef COPY
    #define FUNC() s21_strcpy_test();
#endif
#ifdef CAT
    #define FUNC() s21_strcat_test();
#endif
#ifdef SEARCH
    #define FUNC() s21_strchr_test();
#endif
#ifdef STRSTR
    #define FUNC() s21_strstr_test();
#endif
#ifdef STRTOK
    #define FUNC() s21_strtok_test();
#endif
int main(void) {
    FUNC();
    return 0;
}
void s21_strlen_test(void) {
    char* Arr = "ABRACADABRA";
    char* Arr1 = "1_2";
    char* Arr2 = "\0";
    printf("Input = %s\n", Arr);
    printf("Sym = 11 ");
    if (strl(Arr) == 11) {
        printf("Success OUT = %d\n", strl(Arr));
    } else {
        printf("Fail\n");
    }
    printf("Input = %s\n", Arr1);
    printf("Sym = 3 ");
    if (strl(Arr1) == 3) {
        printf("Success OUT = %d\n", strl(Arr1));
    } else {
        printf("Fail\n");
    }
    printf("Input = %s\n", Arr2);
    printf("Sym = 0 ");
    if (strl(Arr2) == 0) {
        printf("Success OUT = %d", strl(Arr2));
    } else {
        printf("Fail");
    }
}
void s21_strcmp_test(void) {
    char* arr = "Aboba";
    char* arr1 = "Abobaba";
    char* arr2 = "Aboba";


    printf("In1= %s In2 = %s\n", arr, arr1);
    if (cmp(arr, arr1) == -1) {
        printf("SUCCESS Out = %d (In1 < In2)\n", cmp(arr, arr1));
    } else {
        printf("Fail");
    }
    printf("In1= %s In2 = %s\n", arr1, arr2);
    if (cmp(arr1, arr2) == 1) {
        printf("SUCCESS Out = %d (In1 > In2)\n", cmp(arr1, arr2));
    } else {
        printf("Fail");
    }
    printf("In1= %s In2 = %s\n", arr, arr2);
    if (cmp(arr, arr2) == 0) {
        printf("SUCCESS Out = %d (In1 == In2)\n", cmp(arr, arr2));
        } else {
            printf("Fail");
    }
}
void s21_strcpy_test(void) {
    char* arr = "Soso_ososo";
    char* arr1 = "";
    char* arr2 = "";
    char* arr3 = "mpwopowe23_sld,vs";
    printf("TEST 1: In = \"%s\"\n", arr);
    arr1 = copy(arr1, arr);
    if (cmp(arr, arr1) == 0) {
        printf("Success Out = %s\n", arr1);
    } else {
        printf("Fail Out = %s\n", arr1);
    }
    free(arr1);
    printf("TEST 2: In = \"%s\"\n", arr2);
    arr1 = copy(arr1, arr2);
    if (cmp(arr2, arr1) == 0) {
        printf("Fail Out = %s\n", arr1);
    } else {
        printf("Succes Out, str wasn't copied\n");
    }
    free(arr1);
    printf("TEST 3: In = \"%s\"\n", arr3);
    arr1 = copy(arr1, arr3);
    if (cmp(arr3, arr1) == 0) {
        printf("Success Out = %s", arr3);
    } else {
        printf("Fail Out = %s", arr1);
    }
    free(arr1);
}
void s21_strcat_test(void) {
    char* arr = "RAZ";
    char* arr1 = "DWA";
    char* arr2 = "RAZDWA";
    char* arr3 = "";
    char* arr4 = "";
    char* arr5 = "";
    char* arr6 = "Q\0";
    char* arr7 = "-qwqeqwe";
    char* arr8 = "Q-qwqeqwe";
    char* a1 = my_strcat(arr, arr1);
    printf("TEST 1 =  %s %s\n", arr, arr1);
    if (cmp(arr2, a1) == 0) {
         printf("Success Out = %s\n", a1);
    } else {
        printf("Fail Out = %s\n", a1);
    }
    free(a1);
    a1 = my_strcat(arr3, arr4);
    printf("TEST 2 =  %s %s\n", arr3, arr4);
    if (cmp(arr5, a1) == 0) {
         printf("Success Out = %s\n", a1);
    } else {
        printf("Fail Out = %s\n", a1);
    }
    free(a1);
    a1 = my_strcat(arr6, arr7);
    printf("TEST 3 =  %s %s\n", arr6, arr7);
    if (cmp(arr8, a1) == 0) {
         printf("Success Out = %s\n", a1);
    } else {
        printf("Fail Out = %s\n", a1);
    }
     free(a1);
}
void s21_strchr_test(void) {
    char* string = "you are gay";
    char c = 'o';
    char* str1 = "Amogus";
    char c1 = 'z';
    char* str2 = "Avenger";
    char c2 = 'R';
    printf("In = %s Search = %c\n", string, c);
    char *p = my_strchr(string, c);
    if (p == NULL) {
        printf("Success ! Not Found!\n");
    } else {
            printf("Index =  %ld\n", p-string+1);
            printf("Success! Found!\n");
            }
    printf("In = %s Search = %c\n", str1, c1);
    p = my_strchr(str1, c1);
    if (p == NULL) {
        printf("Success ! Not Found!\n");
    } else {
            printf("Index =  %ld\n", p-str1+1);
            printf("Success! Found!\n");
    }
    printf("In = %s Search = %c\n", str2, c2);
    p = my_strchr(str2, c2);
    if (p == NULL) {
        printf("Success ! Not Found!\n");
    } else {
        printf("Index =  %ld\n", p-str2+1);
        printf("Success! Found!\n");
        free(p);
    }
}
void s21_strstr_test(void) {
    char* arr = "Techie Delight - Ace the Technical Interviews";
    char* arr1 = "Ace";
    char* arr2 = "Baby shark tu tu ruru, mamy shark tu-tu-ru-ru-ru-ru";
    char* arr3 = "mamy";
    char* arr4 = "";
    char* arr5 = "Nothing";
    printf("In = %s\nStart with  = %s\n", arr, arr1);
    if (my_strstr(arr, arr1) == NULL) {
        printf("Success ! Not Found!\n");
        } else {
        printf("Massive  =  %s\n", my_strstr(arr, arr1));
        printf("Success!\n");
    }
    printf("In = %s\nStart with  = %s\n", arr2, arr3);
    if (my_strstr(arr2, arr3) == NULL) {
        printf("Success ! Not Found!\n");
        } else {
        printf("Massive  =  %s\n", my_strstr(arr2, arr3));
        printf("Success!\n");
    }
    printf("In = %s\nStart with  = %s\n", arr4, arr5);
    if (my_strstr(arr4, arr5) == NULL) {
        printf("Success ! Not Found!\n");
    } else {
        printf("Massive  =  %s\n", my_strstr(arr4, arr5));
        printf("Success!");
    }
}
void s21_strtok_test(void) {
    printf("TEST 1");
    char s[] = "Oh, here we go again...";
    char *delim = " ";
    char *p = strtok1(s, delim);
  printf("STROKA = %s\n SEP  =%s\n", s, delim);
  while (p) {
    printf("//%s//", p);
    p = strtok1(NULL, delim);
  }
  printf("\nSuccess");
  printf("\nTEST 2\n");
    char s1[] = "TUTNETUSEPARATORA";
  delim = " ";
  p = strtok1(s1, delim);
  printf("STROKA = %s SEP  =%s\n", s1, delim);
  while (p) {
    printf("/%s", p);
    p = strtok1(NULL, delim);
  }
  printf("\nSuccess");
  printf("\nTEST 3\n");
     char s2[] = "";
     delim = " ";
     p = strtok1(s2, delim);
     printf("STROKA = %s SEP  =%s\n", s2, delim);
     if (p != NULL) {
        while (p) {
            printf("/%s", p);
            p = strtok1(NULL, delim);
        }
    printf("\nSuccess");
     } else {
         printf("Success: stroki net");
     }
}
