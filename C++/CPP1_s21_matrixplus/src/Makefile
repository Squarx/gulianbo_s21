CC= g++
SOURCES= $(wildcard *.cpp)
EXECUTABLE= matrix
Vgrind= CK_FORK=no valgrind --vgdb=no\
				--leak-check=full --show-leak-kinds=all\
				--trace-children=yes --track-origins=yes\
				-v --verbose -q --quiet -s

all:
	$(CC) $(SOURCES) -o $(EXECUTABLE)
	./$(EXECUTABLE)

VG:
	$(CC) -g $(SOURCES) -o $(EXECUTABLE)
	$(Vgrind) ./$(EXECUTABLE)

clean:
	rm -rf $(EXECUTABLE)