CC= gcc
CFLAGS= -g -Wall -pedantic -std=c99
LIBS = 



all: test_socketTable

test_socketTable: test_socketTable.c socketTable.o
	$(CC) $(CFLAGS) -o test_socketTable test_socketTable.c socketTable.o $(LIBS)

socketTable: socketTable.c
	$(CC) $(CFLAGS) -o socketTable socketTable.c $(LIBS)

.c.o:
	gcc -c $(CFLAGS) $< -o $@ $(LIBS)

cleano:
	rm -f *.o

clean:
	rm *.o