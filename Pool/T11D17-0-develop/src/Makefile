CC= gcc
FLAGSC=-c -Wall -Werror -Wextra
door_struct : dmanager_module.o door_struct1.o
	gcc dmanager_module.o door_struct.o -o ../build/Quest_1
	-rm -rf *.o

dmanager_module.o : dmanager_module.c 
	$(CC) $(FLAGSC) dmanager_module.c

door_struct1.o : door_struct.c
	$(CC) $(FLAGSC) door_struct.c

list_test.o : list_test.c
	$(CC) $(FLAGSC) list_test.c

list.o : list.c 
	$(CC) $(FLAGSC) list.c

list_test : list_test.o list.o door_struct1.o
	gcc list_test.o list.o door_struct.o -o ../build/Quest_2
	-rm -rf *.o
	
	
