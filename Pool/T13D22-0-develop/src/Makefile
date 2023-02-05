CC=gcc
CFLAGS=-c -Wall -Werror -Wextra
SOURCE1=cipher.c

cipher : cipher.o
	gcc cipher.o -o ../build/cipher
	rm -f *.o
cipher.o : $(SOURCE1)
	$(CC) -DUSUAL $(CFLAGS) $(SOURCE1)

test : Q_5.F LOG
	gcc Q_5.o logger.o -o try
	rm -f *.o
TEST.o : TEST.c
	$(CC) -c TEST.c
LOG : logger.c
	$(CC) $(CFLAGS) logger.c
logging_cipher : cipher_log LOG
	$(CC) cipher.o logger.o -o ../build/logging_cipher
	rm -f *.o
Q_5.o : Q_5.c 
	$(CC) $(CFLAGS) -DLOG Q_5.c

cipher_log : $(SOURCE1) 
	$(CC) $(CFLAGS) -DLOG cipher.c