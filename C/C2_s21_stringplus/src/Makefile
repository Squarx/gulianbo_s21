CC= gcc -ansi -std=c11
CFLAGS:= -Wall -Werror -Wextra
OS=$(shell uname)
LDFLAGS= -o
SOURCES= $(wildcard *.c)
SOURCES_TEST= $(wildcard sprintf_test/*c)
OBJECTS=$(patsubst %.c,%.o,$(SOURCES))
EXECUTABLE= sprintf
LIBRARY= s21_string.a
ALL_FILES= $(wildcard *.c handmade_test/*.c handmade_test/*.h sprintf_test/*.c sprintf_test/*.h)
Vgrind= CK_FORK=no valgrind --vgdb=no\
				--leak-check=full --show-leak-kinds=all\
				--trace-children=yes --track-origins=yes\
				-v --verbose -q --quiet -s
#-lcheck_pic -pthread -lrt -lm -lsubunit
ifeq ($(OS), Linux)
	CHECK_FLAGS=  -lcheck_pic -pthread -lrt -lm -lsubunit
else
	CHECK_FLAGS= -lcheck
endif

all : clean build test gcov_report

build: $(LIBRARY)

rebuild: clean build

$(LIBRARY): clean $(OBJECTS)
	ar rcs $(LIBRARY) $(OBJECTS)
	ranlib $(LIBRARY)
	rm -rf $(OBJECTS)


test: $(LIBRARY)
	$(CC) $(CFLAGS) $(SOURCES_TEST) $(CHECK_FLAGS) -L. $(LIBRARY) $(LDFLAGS) $(EXECUTABLE)
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

check:
	$(pwd)
	cp ../materials/linters/.clang-format .
	clang-format -n $(ALL_FILES)
	rm -f .clang-format

clean:
	rm -rf *.gcda *.gcno gcov gcov_report.info $(EXECUTABLE) report s21_string.a

opt:
	$(CC)  $(SOURCES)  handmade_test/main.c $(LDFLAGS) $(EXECUTABLE)
	./$(EXECUTABLE)

VG:
	$(CC)  -O0 -g $(SOURCES)  handmade_test/main.c $(LDFLAGS) $(EXECUTABLE)
	$(Vgrind) ./$(EXECUTABLE)



test_Valgrind: $(LIBRARY)
	$(CC) -g $(CFLAGS) $(SOURCES_TEST) $(CHECK_FLAGS) -L. $(LIBRARY) $(LDFLAGS) $(EXECUTABLE)
	$(Vgrind) ./$(EXECUTABLE)
test_Valgrind_docker: clean
	$(CC) -O0 -g $(CFLAGS) $(SOURCES_TEST) $(SOURCES) -pthread -lrt -lm -lcheck  $(LDFLAGS) $(EXECUTABLE)
	$(Vgrind) ./$(EXECUTABLE)











