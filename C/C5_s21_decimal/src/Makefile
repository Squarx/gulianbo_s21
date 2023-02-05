GCC=gcc -std=c11 -Wall -Werror -Wextra
OS=$(shell uname)
Q1=s21_decimal.a
BASE=s21_math_oper.c s21_convert_opers.c s21_comparison.c s21_other_opers.c
OBJS_MAIN=core.o
OBJS_MATH=s21_math_oper.o
OBJS_CONV=s21_convert_opers.o
OBJS_COMP=s21_comparison.o
OBJS_OTHER=s21_other_opers.o
OBJS_2=test/test_s21_decimal_main.c test/test_s21_decimal_i.c test/test_s21_decimal_a.c test/test_s21_decimal_g.c # test/s21_is_greater_test.c

ifeq ($(OS), Linux)
	LINUX=-lsubunit
else
	VIEWHTML=open ./report/index.html
endif

all: $(Q1) test gcov_report

$(Q1): $(OBJS_1) $(OBJS_MAIN) $(OBJS_MATH) $(OBJS_CONV) $(OBJS_COMP) $(OBJS_OTHER)
	ar rcs $(Q1) $(OBJS_1) $(OBJS_MAIN) $(OBJS_MATH) $(OBJS_CONV) $(OBJS_COMP) $(OBJS_OTHER)
	ranlib $(Q1)

.c.o:
	$(GCC) -c -g -o $@ $<

test: $(Q1) $(OBJS_2)
	$(GCC) $(OBJS_2) -lcheck -fsanitize=address $(BASE) -lm $(LINUX) -L. $(Q1) -o test.out
	./test.out

gcov_report: $(Q1) $(OBJS_2)
	rm -rf *.o *.gcno *.gcda
	$(GCC) $(OBJS_2) $(BASE) --coverage -lcheck -lm $(LINUX) -L. $(Q1) -o gcov
	./gcov
	lcov -t "gcov" -o gcov_report.info --no-external -c -d .
	genhtml -o report gcov_report.info
	$(VIEWHTML)

rebuild: clean all

clean:
	rm -rf  *.gcno  *.inf *.info gcov
	rm -rf ./math_oper/*.o *.gcda *.a test.out ./report  *.o *.dSYM a.out
	
main:
	$(GCC) $(BASE) test_decimal.c

check:
	$(pwd)
	cp ../materials/linters/.clang-format .
	clang-format -n *.c *.h ./*/*.c ./*/*.h
	rm -f .clang-format