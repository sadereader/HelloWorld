CC=gcc
COPT=-Wall -c

all: c

c: c.o
	$(CC) -Wall c.o -o c

c.o: c.c
	$(CC) $(COPT) c.c

clean:
	rm -rf *.o c
