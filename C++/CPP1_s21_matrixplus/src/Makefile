CXX= g++
CXXFLAGS=  -Wall -Werror -Wextra  -std=c++17
GTESTFLAGS = -lgtest



MAINSRC= $(wildcard *.cpp)
SRC= $(wildcard s21_matrix.cpp)
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
	rm -rf $(EXECUTABLE)

test: clean $(TESTEXEC)
	./$(TESTEXEC)
$(TESTEXEC): clean
	$(CXX) $(CXXFLAGS) $(SRC) $(TESTSRC) -o $(EXECUTABLE)