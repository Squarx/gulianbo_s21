CC=gcc
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=yet_another_decision_module_entry.c decision.c ../data_libs/data_io.c ../data_libs/data_stat.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=main

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
	make clean
c.o: 
	$(CC) $(CFLAGS) $< -o $@
clean : 
	-rm  *.o
clean_all :
	-rm main *.o