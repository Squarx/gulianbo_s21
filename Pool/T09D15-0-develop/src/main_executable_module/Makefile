CC=gcc
CFLAGS=-c -Wall -Werror -Wextra
LDFLAGS=
SOURCES=main_executable_module.c ../yet_another_decision_module/decision.c ../data_module/data_process.c ../data_libs/data_io.c ../data_libs/data_stat.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=../../build/Quest_3
SOUR_1=main_executable_module.c data_stat.a ../yet_another_decision_module/decision.c ../data_module/data_process.c ../data_libs/data_io.c ../data_libs/data_stat.c
OB_1=$(SOUR_1:.c=.o)
EX_1=../../build/Quest_5
S_6=../data_module/data_process.c ../data_libs/data_stat.c
FL_6=-c -fPIC -Wall -Werror -Wextra
EX_6=../../build/Quest_6
SOUR_2=main_executable_module.c data_process.so ../yet_another_decision_module/decision.c ../data_module/data_process.c ../data_libs/data_io.c ../data_libs/data_stat.c
OB_6=$(SOUR_2:.c=.o)

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@
c.o: 
	$(CC) $(CFLAGS) $< -o $@
clean : 
	-rm  $(OBJECTS)
rebuild :
	make all
	make clean
open :
	$(EXECUTABLE)
data_stat.a :
	gcc -c ../data_libs/data_stat.c -o ../data_libs/data_stat.o
	ar rc data_stat.a ../data_libs/data_stat.o
	ranlib data_stat.a
	-rm ../data_libs/data_stat.o
	
build_with_static : $(SOUR_1) $(EX_1) 

$(EX_1): $(OB_1) 
	$(CC) $(OB_1) -o $@
	make clean
	make lclean
bclean :
	-rm ../../build/Quest_5
lclean :
	-rm data_stat.a
	-rm data_process.so
data_process.so : 
	$(CC) $(FL_6) $(S_6) 
	$(CC) -shared -o data_process.so *.o
	-rm *.o
build_with_dynamic : $(SOUR_2) $(EX_6)

$(EX_6): $(OB_6)
	$(CC) $(OB_6) -o $@
	make clean



