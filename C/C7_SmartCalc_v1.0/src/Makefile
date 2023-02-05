CC=gcc
FILES= *.c
CFLAGS= -Wall -Wextra -Werror -pedantic -std=c11
EXECUTABLE= a.out
SOURCES_TEST= $(wildcard tests/*.c)
LDFLAGS= -o
OBJECTS= $(patsubst %.c, %.o, $(SOURCES_TEST))
LDFLAG= -o
ALL_FILES=$(wildcard *.c Smart_calc/*.c)
ifeq ($(OS), Linux)
	CHECK_FLAGS= -lcheck_pic -pthread -lrt -lm -lsubunit
else
	CHECK_FLAGS= -lcheck
endif
Vgrind= CK_FORK=no valgrind --vgdb=no\
				--leak-check=full --show-leak-kinds=all\
				--trace-children=yes --track-origins=yes\
				-v --verbose -q --quiet -s

all : clean install test gcov_report
m:
	$(CC)  main/*.c   $(FILES) -lm -o $(EXECUTABLE)
	./$(EXECUTABLE)

vg:
	$(CC) $(CFLAGS) $(FILES) -lm -o $(EXECUTABLE)
	$(Vgrind) ./$(EXECUTABLE)

test: $(OBJECTS)
	$(CC)  $(CFLAGS) $(SOURCES_TEST) $(CHECK_FLAGS) $(FILES) -lm -o $(EXECUTABLE)
	clear
	./$(EXECUTABLE)
	rm -rf $(OBJECTS) $(EXECUTABLE)

clean:
	rm -rf $(EXECUTABLE) $(OBJECTS) *.gcda *.gcno gcov gcov_report.info report  Smart_calc/Makefile build Archive_CalcApp_v1_0/


gcov_report: clean
	$(CC) --coverage  $(SOURCES_TEST) $(CHECK_FLAGS) $(FILES) $(LDFLAGS) gcov
	./gcov
	lcov -t "gcov" -o gcov_report.info --no-external -c -d .
	genhtml -o report gcov_report.info
	open report/index.html
	rm -rf *.gcda *.gcno gcov gcov_report.info

c: clean

install :
	mkdir build
	cd Smart_calc && qmake && make && make clean && rm -rf Makefile && mv Smart_calc.app ../build

uninstall :
	rm -rf build
open:
	build/./Smart_calc.app/Contents/MacOS/Smart_calc

dvi:
	open dvi.md


dist:
	rm -rf Archive_CalcApp_v1_0/
	mkdir Archive_CalcApp_v1_0
	mkdir Archive_CalcApp_v1_0/src
	cp -r ./build/Smart_calc.app Archive_CalcApp_v1_0/src
	tar cvzf Archive_CalcApp_v1_0.tgz Archive_CalcApp_v1_0/
	rm -rf Archive_CalcApp_v1_0/

dist_zip:
	rm -rf Archive_CalcApp_v1_0/
	mkdir Archive_CalcApp_v1_0
	mkdir Archive_CalcApp_v1_0/src
	cp -r ./build/Smart_calc.app Archive_CalcApp_v1_0/src
	zip -r Smart_calc_v1_0.zip ./build/Smart_calc.app
style:
	cp ../materials/linters/.clang-format .
	clang-format -i $(ALL_FILES)
	rm -f .clang-format
check:
	cp ../materials/linters/.clang-format .
	clang-format -n $(ALL_FILES)
	rm -f .clang-format