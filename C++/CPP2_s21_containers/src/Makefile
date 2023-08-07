CXX= g++
CXXFLAGS=  -Wall -Werror -Wextra  -std=c++17 -g
MAINSRC= $(wildcard main.cc)
EXECUTABLE= s21_containers
OBJECTS= $(patsubst %.cc, %.o, $(SRC))
TESTEXEC = s21_test_containers
SRC= $(wildcard *.h)
TESTSRC= $(wildcard test/*.cc)
GTESTFLAGS = -lgtest -lgmock -pthread
ALLFILE = $(wildcard test/*.cc test/*.h *.h *.cc)
VGRND= CK_FORK=no valgrind --vgdb=no\
				--leak-check=full --show-leak-kinds=all\
				--trace-children=yes --track-origins=yes\
				-v --verbose -q --quiet -s



all: clean gcov_report

clean:
	rm -rf $(EXECUTABLE) $(TESTEXEC)
	rm -rf *.gcda *.gcno report test.info $(LIBRARY)

test: clean $(TESTEXEC)
	./$(TESTEXEC)
	rm $(TESTEXEC)

$(TESTEXEC): clean
	$(CXX) $(TESTSRC) -o $(TESTEXEC) $(CXXFLAGS)  $(GTESTFLAGS)

gcov_report: clean
	$(CXX) --coverage $(TESTSRC) -o $(TESTEXEC) $(CXXFLAGS)  $(GTESTFLAGS)
	./$(TESTEXEC)
	lcov -t "test" -o test.info -c -d . --no-external
	genhtml -o report test.info
	open ./report/index.html

style:
	clang-format -i --style=Google $(ALLFILE)

check:
	clang-format -n --style=Google $(ALLFILE)

leak: main
	leaks -atExit -- ./$(EXECUTABLE)

lt: clean $(TESTEXEC)
	leaks -atExit -- ./$(TESTEXEC)

main: clean
	$(CXX) $(CXXFLAGS1) $(MAINSRC) -o $(EXECUTABLE)
	./$(EXECUTABLE)

VG: clean
	$(CXX) -g $(CXXFLAGS1) $(MAINSRC) -o $(EXECUTABLE)
	$(VGRND) ./$(EXECUTABLE)

testVG: clean $(TESTEXEC)
	$(VGRND) ./$(TESTEXEC)
	rm $(TESTEXEC)
