CC= gcc -ansi -std=c11
CFLAGS:= -Wall -Werror -Wextra -lm
OS=$(shell uname)
LDFLAGS= -o
SOURCES= $(wildcard files/other/*.c  files/math/*.c files/trig/*.c)
SOURCES_LIB= $(wildcard files/other/*.c  files/math/*.c files/trig/*.c)
SOURCES_TEST= $(wildcard test/*.c)
OBJECTS= $(patsubst %.c, %.o, $(SOURCES_LIB))
EXECUTABLE= math
ALL_FILES= $(wildcard files/other/*  files/math/* files/trig/* *.h main_hands/*)
LIBRARY= s21_math.a
Vgrind= CK_FORK=no valgrind --vgdb=no\
				--leak-check=full --show-leak-kinds=all\
				--trace-children=yes --track-origins=yes\
				-v --verbose -q --quiet -s
ifeq ($(OS), Linux)
	CHECK_FLAGS= -lcheck_pic -pthread -lrt -lm -lsubunit
else
	CHECK_FLAGS= -lcheck
endif

all: clean $(LIBRARY) test gcov_report
clean:
	rm -rf *.gcda *.gcno gcov gcov_report.info $(EXECUTABLE) report $(LIBRARY)

$(LIBRARY): clean $(OBJECTS)
	ar rcs $(LIBRARY) $(OBJECTS)
	ranlib $(LIBRARY)
	rm -rf $(OBJECTS)
test: $(LIBRARY)
	$(CC) $(CFLAGS) $(SOURCES_TEST) $(CHECK_FLAGS) -L. $(LIBRARY) $(LDFLAGS) $(EXECUTABLE)
	clear
	./$(EXECUTABLE)
gcov_report: clean
	$(CC) --coverage $(CFLAGS) $(SOURCES_TEST) $(CHECK_FLAGS) $(SOURCES) $(LDFLAGS) gcov
	./gcov
	lcov -t "gcov" -o gcov_report.info --no-external -c -d .
	genhtml -o report gcov_report.info
	open report/index.html
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf gcov
	rm -rf gcov_report.info
test_Valgrind: clean
	$(CC) -O0 -g $(CFLAGS) $(SOURCES_TEST) $(CHECK_FLAGS) $(SOURCES) $(LDFLAGS) $(EXECUTABLE)
	$(Vgrind) ./$(EXECUTABLE)

check:
	$(pwd)
	cp ../materials/linters/.clang-format .
	clang-format -n $(ALL_FILES)
	rm -f .clang-format

build:
	$(CC) $(SOURCES) main_hands/s21_math.c -lm $(LDFLAGS) $(EXECUTABLE)
	./$(EXECUTABLE)