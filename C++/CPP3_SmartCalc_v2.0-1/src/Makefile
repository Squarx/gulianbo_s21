.PHONY: install
CXX= g++
CXXFLAGS=  -Wall -Werror -Wextra  -std=c++17 -g
MAINSRC= $(wildcard main.cc model/Calcmodel.cc )
EXECUTABLE= s21_SmartCalc2
OBJECTS= $(patsubst %.cc, %.o, $(SRC))
TESTEXEC = s21_test_SmartCalc2
SRC= $(wildcard *.h)
TESTSRC= $(wildcard test/*.cc model/Calcmodel.cc)
GTESTFLAGS = -lgtest -pthread
ALLFILE = $(wildcard *.cc **/*.cc *.h **/*.h *.cpp **/*.cpp)
VGRND= CK_FORK=no valgrind --vgdb=no\
				--leak-check=full --show-leak-kinds=all\
				--trace-children=yes --track-origins=yes\
				-v --verbose -q --quiet -s
ARCHIVE=Archive_CalcApp_v2_0
DIR=build

all: clean install tests gcov_report dist

install:
	mkdir -p build
ifeq ($(shell uname),Darwin)
	cd view && qmake "CONFIG+=mac" && make && make clean && rm -rf Makefile && mv SmartCalc.app ../build
else
	cd view && qmake && make && make clean && rm -rf Makefile && mv SmartCalc ../build
endif

uninstall:
	rm -rf build

clean:
	rm -rf $(EXECUTABLE) $(OBJECTS) $(TESTEXEC) -rf *.gcda *.gcno report test.info $(LIBRARY) $(ARCHIVE)*

dvi:

dist: clean
	rm -rf ${ARCHIVE}
	mkdir ${ARCHIVE}
	mkdir ${ARCHIVE}/src
	cp -r build/* ${ARCHIVE}/src/
	tar cvzf ${ARCHIVE}.tgz ${ARCHIVE}
	zip -r ${ARCHIVE}.zip ${ARCHIVE}



rebuild: uninstall clean install open

tests: clean $(TESTEXEC)
	./$(TESTEXEC)
	rm $(TESTEXEC)

style:
	clang-format -i --style=Google $(ALLFILE)


gcov_report: clean
	$(CXX) --coverage $(TESTSRC) -o $(TESTEXEC) $(CXXFLAGS)  $(GTESTFLAGS)
	./$(TESTEXEC)
	lcov -t "test" -o test.info -c -d . --no-external
	genhtml -o report test.info
	open ./report/index.html



main: clean
	$(CXX) $(CXXFLAGS1) $(MAINSRC) -o $(EXECUTABLE)
	./$(EXECUTABLE)

VG: clean
	$(CXX) -g $(CXXFLAGS1) $(MAINSRC) -o $(EXECUTABLE)
	$(VGRND) ./$(EXECUTABLE)


$(TESTEXEC): clean
	$(CXX) $(TESTSRC) -o $(TESTEXEC) $(CXXFLAGS)  $(GTESTFLAGS)

testVG: clean $(TESTEXEC)
	$(VGRND) ./$(TESTEXEC)
	rm $(TESTEXEC)

open:
ifeq ($(shell uname),Darwin)
	build/./SmartCalc.app/Contents/MacOS/SmartCalc
else
	./build/SmartCalc
endif

check:
	clang-format -n --style=Google $(ALLFILE)



ready: style test gcov_report clean

