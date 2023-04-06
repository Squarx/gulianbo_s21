CXX= g++
CXXFLAGS=  -Wall -Werror -Wextra  -std=c++17
GTESTFLAGS = -lgtest
LIBRARY=s21_matrix_oop.a


MAINSRC= $(wildcard *.cpp)
SRC= $(wildcard s21_matrix_oop.cpp)
TESTSRC = $(wildcard test/*.cpp)
ALLFILES= $(wildcard *.cpp test/*.cpp *.h test/*.h)
EXECUTABLE= matrix
TESTEXEC = test_matrix

OBJECTS= $(patsubst %.cpp, %.o, $(SRC))

Vgrind= CK_FORK=no valgrind --vgdb=no\
				--leak-check=full --show-leak-kinds=all\
				--trace-children=yes --track-origins=yes\
				-v --verbose -q --quiet -s




all: style clean $(LIBRARY) test gcov_report

clean:
	rm -rf $(EXECUTABLE) $(TESTEXEC)
	rm -rf *.gcda *.gcno report test.info $(LIBRARY) $(OBJECTS)

test: clean $(TESTEXEC)
	./$(TESTEXEC)

$(TESTEXEC): clean
	$(CXX)  $(SRC) $(TESTSRC) -o $(TESTEXEC) $(CXXFLAGS)  $(GTESTFLAGS)

gcov_report: clean
	$(CXX) --coverage $(SRC) $(TESTSRC) -o $(TESTEXEC) $(CXXFLAGS)  $(GTESTFLAGS)
	./$(TESTEXEC)
	lcov -t "test" -o test.info -c -d . --no-external
	genhtml -o report test.info
	open ./report/index.html

$(LIBRARY): clean $(OBJECTS)
	ar rcs $(LIBRARY) $(OBJECTS)
	ranlib $(LIBRARY)
	rm -rf $(OBJECTS)

main:
	$(CXX) $(CXXFLAGS) $(MAINSRC) -o $(EXECUTABLE)
	./$(EXECUTABLE)

VG:
	$(CXX) $(CXXFLAGS) $(MAINSRC) -o $(EXECUTABLE)
	$(Vgrind) ./$(EXECUTABLE)

testLeaks: clean $(TESTEXEC)
	leaks -atExit -- ./$(TESTEXEC)

style:
	clang-format --style="Google" -i $(ALLFILES)

style1:
	cp ../materials/linters/.clang-format .
	clang-format -i $(ALLFILES)
	rm -f .clang-format

check:
	cp ../materials/linters/.clang-format .
	clang-format -n $(ALLFILES)
	rm -f .clang-format


testVG: clean $(TESTEXEC)
	$(Vgrind) ./$(TESTEXEC)
