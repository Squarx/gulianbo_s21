CC= gcc
FLAGS= -c -Wall -Werror -Wextra

print_module : print_module.o main_module_entry_point.o
	$(CC) print_module.o main_module_entry_point.o -o ../build/Quest_1
	-rm -rf *.o
print_module.o : print_module.c 
	$(CC) $(FLAGS) print_module.c
main_module_entry_point.o : main_module_entry_point.c 
	$(CC) $(FLAGS) main_module_entry_point.c

bst_create_test : bst bst_create_test.o
	$(CC) bst.o bst_create_test.o -o ../build/Quest_3
	-rm -rf *.o
bst : bst.c 
	$(CC) $(FLAGS) bst.c

bst_create_test.o : bst_create_test.c 
	$(CC) $(FLAGS) bst_create_test.c
	
bst_insert_test : bst bst_insert_test.o
	$(CC) bst.o bst_insert_test.o -o ../build/Quest_4
	-rm -rf *.o
bst_insert_test.o : bst_insert_test.c 
	$(CC) $(FLAGS) bst_insert_test.c