CC=gcc
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=data_module_entry.c data_process.c ../data_libs/data_io.c ../data_libs/data_stat.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=main

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
	-rm ../data_libs/data_io.o ../data_libs/data_stat.o *.o
c.o: 
	$(CC) $(CFLAGS) $< -o $@
clean : 
	-rm main *.o
	-rm ../data_libs/data_io.o ../data_libs/data_stat.o