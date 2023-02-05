CC=gcc
CFLAGS=-c -Wall -Wextra -Werror

strlen_tests: s21_string_test_1.o s21_string.o 
	$(CC) s21_string_test.o s21_string.o -o ../build/Quest_1
	-rm  *.o
s21_string_test_1.o : s21_string_test.c
	$(CC) $(CFLAGS) -DSTRLEN s21_string_test.c



s21_string.o : s21_string.c
	$(CC) $(CFLAGS) s21_string.c




strcmp_tests: s21_string_test_2.o s21_string.o 
	$(CC) s21_string_test.o s21_string.o -o ../build/Quest_2
	-rm  *.o
s21_string_test_2.o : s21_string_test.c
	$(CC) $(CFLAGS) -DSTRCMP s21_string_test.c



strcpy_tests : s21_string_test_3.o s21_string.o 
	$(CC) s21_string_test.o s21_string.o -o ../build/Quest_3
	-rm  *.o
s21_string_test_3.o : s21_string_test.c
	$(CC) $(CFLAGS) -DCOPY s21_string_test.c


strcat_tests : s21_string_test_4.o s21_string.o
	$(CC) s21_string_test.o s21_string.o -o ../build/Quest_4
	-rm  *.o
s21_string_test_4.o : s21_string_test.c
	$(CC) $(CFLAGS) -DCAT s21_string_test.c


strchr_tests : s21_string_test_5.o s21_string.o
	$(CC) s21_string_test.o s21_string.o -o ../build/Quest_5
	-rm  *.o
s21_string_test_5.o : s21_string_test.c
	$(CC) $(CFLAGS) -DSEARCH s21_string_test.c


strstr_tests : s21_string_test_6.o s21_string.o
	$(CC) s21_string_test.o s21_string.o -o ../build/Quest_6
	-rm  *.o
s21_string_test_6.o : s21_string_test.c
	$(CC) $(CFLAGS) -DSTRSTR s21_string_test.c



strtok_tests : s21_string_test_7.o s21_string.o
	$(CC) s21_string_test.o s21_string.o -o ../build/Quest_7
	-rm  *.o
s21_string_test_7.o : s21_string_test.c
	$(CC) $(CFLAGS) -DSTRTOK s21_string_test.c

c.o: 
	$(CC) $(CFLAGS) $< -o $@

clean : 
	-rm  *.o
clean_all :
	-rm main *.o