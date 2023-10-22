.PHONY: install
CXX= @g++
CXXFLAGS=  -Wall -Werror -Wextra  -std=c++17 -g
CXXFLAGS_DEV= -std=c++17 -g
INCDIRS=-I/usr/include/qt4 -I/usr/include/qt4/QtGui -I/usr/include/qt4/QtCore -I/usr/include/qt4/QFileDialog /usr/local/lib/QtWidgets.framework/Headers/qfiledialog.h /usr/local/lib/QtWidgets.framework/Headers/QFileDialog
QTLIBS=-lQtCore -lQtGui -lQFileDialog
GTESTFLAGS = -lgtest -pthread -lstdc++

EXECUTABLE_APP = Viewer_3D
EXECUTABLE_MAIN = main
EXECUTABLE_TEST = Viewer_3D_Test

GCOV = gcov_report
SRC_GCOV_TEST = $(GCOV)/$(EXECUTABLE_TEST)

OBJECTS= $(patsubst %.cc, %.o, $(SRC))

SRC= $(wildcard *.h)

ALL_FILES = $(shell find . \( -name '*.h' -o -name '*.cc' -o -name '*.cpp' \) -print0 | xargs -0)
BACKEND_FILES = $(shell find backend/ \( -name '*.h' -o -name '*.cc' \) -print0 | xargs -0)
BACKEND_FILES2 = $(wildcard backend/normalization_parameters/**.cc backend/scene/*.cc backend/strategy/*.cc backend/file_reader/*.cc backend/figure/*.cc backend/vertex/*.cc backend/solver/*.h)
INTERNAL_FILES = $(shell find internal/ \( -name '*.h' -o -name '*.cc' \) -print0 | xargs -0)
CONTROLLER_FILES = $(shell find controller/ \( -name '*.h' -o -name '*.cc' \) -print0 | xargs -0)
FRONTEND_FILES = $(shell find front/ \( -name '*.h' -o -name '*.cc' \) -print0 | xargs -0)
LIBS_FILES = $(shell find libs/ \( -name '*.h' -o -name '*.cc' \) -print0 | xargs -0)
MAIN_FILE = $(wildcard *.cc *./h)
TEST_FILES= $(shell find tests/ \( -name '*.h' -o -name '*.cc' \) -print0 | xargs -0)

VGRND= CK_FORK=no valgrind --vgdb=no\
				--leak-check=full --show-leak-kinds=all\
				--trace-children=yes --track-origins=yes\
				-v --verbose -q --quiet -s

ARCHIVE=Archive_3D_Viewer_v2_0
OS=$(shell uname -s)

all: install open

vs_main: clean
	$(CXX) -g $(CXXFLAGS1) $(MAIN_FILE) $(BACKEND_FILES) -o $(EXECUTABLE_MAIN)

install: build_install
ifeq ($(OS), Darwin)
	@mv front/3DViewer_v2-0.app/Contents/MacOS/3DViewer_v2-0 $(EXECUTABLE_APP)
	@rm -rf front/3DViewer_v2-0.app
else
	@mv front/3DViewer_v2-0 $(EXECUTABLE_APP)
endif

uninstall:
	@rm -rf build*/
	@rm -rf $(EXECUTABLE_APP)

open:
	@./$(EXECUTABLE_APP)

dvi:
	open ./help/index.html

dist:
	rm -rf ${ARCHIVE}
	mkdir ${ARCHIVE}
	mkdir ${ARCHIVE}/src
	cp -r $(EXECUTABLE_APP) ${ARCHIVE}/src/
	tar cvzf ${ARCHIVE}.tgz ${ARCHIVE}
	zip -r ${ARCHIVE}.zip ${ARCHIVE}

archive_obj:
	zip -r objects.zip objects

unarchive_obj:
	unzip objects.zip

tests: clean
	$(CXX) $(BACKEND_FILES2) $(TEST_FILES) -o $(EXECUTABLE_TEST) $(CXXFLAGS)  $(GTESTFLAGS)
	@echo "======= TESTS ======="
	@./$(EXECUTABLE_TEST)

main: clean
	$(CXX) $(CXXFLAGS_DEV) $(MAIN_FILE) $(BACKEND_FILES) -o $(EXECUTABLE_MAIN)
	./$(EXECUTABLE_MAIN)

main1: clean
	$(CXX) $(CXXFLAGS1) $(MAIN_FILE) $(BACKEND_FILES) $(CONTROLLER_FILES) -o $(EXECUTABLE_MAIN)
	./$(EXECUTABLE_MAIN)

clean:
	@rm -rf $(EXECUTABLE_MAIN) $(OBJECTS) $(EXECUTABLE_TEST) -rf *.gcda *.gcno *.o $(GCOV) report test.info $(LIBRARY) $(ARCHIVE)* backend/**/*.gch Viewer_3D_Test.dSYM


check_style:
	@cp ../materials/linters/.clang-format ../
	@echo "======= CHECK GOOGLE CODE STYLE ======="
	clang-format -n $(ALL_FILES)

do_style:
	@cp ../materials/linters/.clang-format ../
	@echo "======= DO GOOGLE CODE STYLE ======="
	clang-format --style=Google -i $(ALL_FILES)

leak: main
	leaks -atExit -- ./$(EXECUTABLE_MAIN)

leak_tests: clean $(TEST_EXEC)
	leaks -atExit -- ./$(EXECUTABLE_TEST)

leak_launch:
		leaks -atExit -- $(EXECUTABLE_APP)

VG: clean
	$(CXX) -g $(CXXFLAGS_DEV) $(MAIN_FILE) $(BACKEND_FILES) -o $(EXECUTABLE_MAIN)
	$(VGRND) ./$(EXECUTABLE_MAIN)

testVG: clean tests
	$(VGRND) ./$(EXECUTABLE_TEST)
	rm $(EXECUTABLE_TEST)

launchVG:
	$(VGRND) $(EXECUTABLE_APP)

build_install:
	@make clean
ifeq ($(OS), Darwin)
	@cd front && qmake "CONFIG+=mac" && make -j6 && make clean && rm -rf Makefile
else
	@cd front && qmake6 && make && make clean && rm Makefile
endif

$(GCOV): build_gcov_report
	open ./$(GCOV)/report/index.html

build_gcov_report: clean
build_gcov_report:
	@echo "======= MAKE GCOV REPORT ======="
	@mkdir -p -- $(GCOV)
	$(CXX) --coverage $(BACKEND_FILES2) $(TEST_FILES) -o $(SRC_GCOV_TEST) $(CXXFLAGS) $(GTESTFLAGS)
	@./$(SRC_GCOV_TEST)
ifeq ($(OS), Darwin)
	lcov -t "test" -o ./$(GCOV)/test.info -c -d . --no-external --ignore-errors mismatch
else
	lcov -t "test" -o ./$(GCOV)/test.info -c -d . --no-external
endif
	genhtml -o ./$(GCOV)/report ./$(GCOV)/test.info

build_main: clean
	$(CXX) $(CXXFLAGS_DEV) $(MAIN_FILE) $(BACKEND_FILES) -o $(EXECUTABLE_MAIN)
