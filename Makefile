CC=gcc
COPT=-Wall -c

all: helloworld

helloworld: helloworld.o
	$(CC) -Wall helloworld.o -o helloworld

helloworld.o: helloworld.c
	$(CC) $(COPT) helloworld.c

clean:
	rm -rf *.o helloworld
