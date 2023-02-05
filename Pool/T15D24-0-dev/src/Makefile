FLAGS = -c
CC = gcc
SOURCES = modules_db.c modules.c levels.c status_events.c
OBJECTS = $(SOURCES:c=o)
EXECUTABLE = xdatabase
all : $(EXECUTABLE)
		del *.o
$(EXECUTABLE) : $(OBJECTS)
	$(CC) $(OBJECTS) -o $@
# .c.o :
# 	$(CC) -c $< -o $@
# test : db func
# 	$(CC) modules.o modules_db.o -o test
# 	del *.o
# db : modules_db.c
# 	$(CC) $(FLAGS) modules.c