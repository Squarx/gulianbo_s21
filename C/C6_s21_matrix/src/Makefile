CC= gcc -ansi -std=c11
CFLAGS= -Wall -Werror -Wextra -lm -g
OS=$(shell uname)
LDFLAGS= -o
SOURCES= $(wildcard func/*.c other_func/*.c)
SOURCES_LIB= $(wildcard func/*.c other_func/*.c)
SOURCES_TEST= $(wildcard test/*.c)
OBJECTS= $(patsubst %.c, %.o, $(SOURCES_LIB))
EXECUTABLE= matrix
LIBRARY=  s21_matrix.a
ALL_FILES = $(wildcard func/*.c other_func/*.c test/*.c test/*.h *.c *.h)
VG= CK_FORK=no valgrind --vgdb=no --leak-check=full\
--show-leak-kinds=all --track-origins=yes -v --verbose -q --quiet -s

ifeq ($(OS), Linux)
	CHECK_FLAGS= -lcheck_pic -pthread -lrt -lm -lsubunit
else
	CHECK_FLAGS= -lcheck
endif

all: clean $(LIBRARY) test gcov_report

test: $(LIBRARY)
	$(CC)  $(CFLAGS) $(SOURCES_TEST) $(CHECK_FLAGS) -L. $(LIBRARY) $(LDFLAGS) $(EXECUTABLE)
	clear
	./$(EXECUTABLE)

clean:
	rm -rf *.gcda *.gcno gcov gcov_report.info $(EXECUTABLE) $(OBJECTS) report $(LIBRARY)

$(LIBRARY): clean $(OBJECTS)
	ar rcs $(LIBRARY) $(OBJECTS)
	ranlib $(LIBRARY)
	rm -rf $(OBJECTS)

check:
	$(pwd)
	cp ../materials/linters/.clang-format .
	clang-format -n $(ALL_FILES)
	rm -f .clang-format

gcov_report: clean
	$(CC) --coverage  $(SOURCES_TEST) $(CHECK_FLAGS) $(SOURCES) $(LDFLAGS) gcov
	./gcov
	lcov -t "gcov" -o gcov_report.info --no-external -c -d .
	genhtml -o report gcov_report.info
	open report/index.html
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf gcov
	rm -rf gcov_report.info

style:
	$(pwd)
	cp ../materials/linters/.clang-format .
	clang-format -i $(ALL_FILES)
	rm -f .clang-format


M:
#leaks -atExit -- .
	$(CC)  matrix_main.c $(SOURCES) $(LDFLAGS) $(EXECUTABLE)
	clear
	./$(EXECUTABLE)

VG: $(LIBRARY)
	$(CC) -O0 -g $(CFLAGS) $(SOURCES_TEST) $(CHECK_FLAGS) -L. $(LIBRARY) $(LDFLAGS) $(EXECUTABLE)
	clear
	$(VG) ./$(EXECUTABLE)