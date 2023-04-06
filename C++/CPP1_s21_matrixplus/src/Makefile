CXX= g++
CXXFLAGS=  -Wall -Werror -Wextra  -std=c++17
GTESTFLAGS = -lgtest



MAINSRC= $(wildcard *.cpp)
SRC= $(wildcard s21_matrix_oop.cpp)
TESTSRC = $(wildcard test/*.cpp)

EXECUTABLE= matrix
TESTEXEC = test_matrix

Vgrind= CK_FORK=no valgrind --vgdb=no\
				--leak-check=full --show-leak-kinds=all\
				--trace-children=yes --track-origins=yes\
				-v --verbose -q --quiet -s

all:
	$(CXX) $(CXXFLAGS) $(MAINSRC) -o $(EXECUTABLE)
	./$(EXECUTABLE)

VG:
	$(CXX) $(CXXFLAGS) $(MAINSRC) -o $(EXECUTABLE)
	$(Vgrind) ./$(EXECUTABLE)

clean:
	rm -rf $(EXECUTABLE) $(TESTEXEC)
		rm -rf *.gcda *.gcno report test.info


test: clean $(TESTEXEC)
	./$(TESTEXEC)
$(TESTEXEC): clean
	$(CXX)  $(SRC) $(TESTSRC) -o $(TESTEXEC) $(CXXFLAGS)  $(GTESTFLAGS)

testLeaks: clean $(TESTEXEC)
	leaks -atExit -- ./$(TESTEXEC)
gcov_report: clean
	$(CXX) --coverage $(SRC) $(TESTSRC) -o $(TESTEXEC) $(CXXFLAGS)  $(GTESTFLAGS)
	./$(TESTEXEC)
	lcov -t "test" -o test.info -c -d . --no-external
	genhtml -o report test.info
	open ./report/index.html