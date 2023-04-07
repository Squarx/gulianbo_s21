CC= gcc -ansi -std=c11
CFLAGS= -Wall -Werror -Wextra -lm
OS=$(shell uname)
LDFLAGS= -o
SOURCES_LIB= $(wildcard s21_3DViewer.c) $(wildcard s21_matrix.c)
SOURCES_TEST= test.c
OBJECTS= $(patsubst %.c, %.o, $(SOURCES_LIB))
EXECUTABLE= 3DViewer
LIBRARY =  s21_3DViewer.a
ALL_FILES = $(wildcard ./*.c ./*.h)
VG= CK_FORK=no valgrind --vgdb=no --leak-check=full\
--show-leak-kinds=all --track-origins=yes -v --verbose -q --quiet -s

#VG= CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes -v --verbose -q --quiet -s

ifeq ($(OS), Linux)
	CHECK_FLAGS= -lcheck_pic -pthread -lrt -lm -lsubunit
else
	CHECK_FLAGS= -lcheck
endif

all: dvi clean install tests gcov_report open

clean:
	rm -rf $(EXECUTABLE) $(OBJECTS)  */*.o *.a *.gcda *.gcno gcov gcov_report.info report  s21_3DViewer/Makefile build Archive_CalcApp_v1_0/ 3DViewer_v1_0.zip 3DViewerApp_v1_0.tgz

install:
	mkdir ../build
	cd s21_3DViewer && qmake && make && make clean && rm -rf Makefile && mv s21_3DViewer.app ../../build

uninstall:
	rm -rf ../build

rebuild: uninstall clean install open

open:
	../build/s21_3DViewer.app/Contents/MacOS/s21_3DViewer

dvi:
	open Instruction_3DViewer.md

dist:
	rm -rf ../Archive_3DViewer_v1_0/
	mkdir ../Archive_3DViewer_v1_0
	mkdir ../Archive_3DViewer_v1_0/src
	cp -r ../src/* ../Archive_3DViewer_v1_0/src
	tar cvzf 3DViewerApp_v1_0.tgz ../Archive_3DViewer_v1_0/
	zip -r 3DViewer_v1_0.zip ../Archive_3DViewer_v1_0/
	rm -rf Archive_3DViewer_v1_0

tests: $(LIBRARY)
	$(CC)  $(CFLAGS) $(SOURCES_TEST) $(CHECK_FLAGS) -L. $(LIBRARY) $(LDFLAGS) $(EXECUTABLE)
	clear
	./$(EXECUTABLE)

$(LIBRARY): clean $(OBJECTS)
	ar rcs $(LIBRARY) $(OBJECTS)
	ranlib $(LIBRARY)
	rm -rf $(OBJECTS)

gcov_report: clean $(LIBRARY)
	$(CC) --coverage $(SOURCES_TEST) $(LIBRARY) $(SOURCES_LIB) $(CHECK_FLAGS) $(LDFLAGS) gcov
	./gcov
	lcov -t "gcov" -o gcov_report.info --no-external -c -d .
	genhtml -o report gcov_report.info
	open report/index.html
	rm -rf *.gcda *.gcno gcov gcov_report.info

style:
	cp ../materials/linters/.clang-format .
	clang-format -i $(ALL_FILES) */*.h */*.cpp
	rm -f .clang-format

check:
	$(pwd)
	cp ../materials/linters/.clang-format .
	clang-format -n $(ALL_FILES) */*.h */*.cpp
	rm -f .clang-format


VG: $(LIBRARY)
	$(CC) -O0 -g $(CFLAGS) $(SOURCES_TEST) $(SOURCES_LIB) $(CHECK_FLAGS) -L. $(LIBRARY) $(LDFLAGS) $(EXECUTABLE)
	clear
	$(VG) ./$(EXECUTABLE)

Docker: $(LIBRARY)
	$(CC) -O0 -g $(CFLAGS) $(SOURCES_TEST) $(SOURCES_LIB) -lcheck -L. $(LIBRARY) $(LDFLAGS) $(EXECUTABLE)
	clear
	$(VG) ./$(EXECUTABLE)