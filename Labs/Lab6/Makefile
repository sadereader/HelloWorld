lab6: lab6start.o lab6a.o lab6b.o
	gcc lab6start.o lab6a.o lab6b.o -o lab6

lab6start.o: lab6start.c
	gcc -c -g -Wall -O0 lab6start.c

# For Friday's next-to-last lab exercise of
# writing a replacement "toLower()" function,
# make the following two lines active:

lab6a.o: lab6a.s
	gcc -c -g lab6a.s
#
# AND comment out these two lines:
#lab6a.o: lab6a.c
#	gcc -c -g -Wall -O0 lab6a.c

# For Friday's FINAL lab exercise of writing
# a replacement "newLSDigit()" function,
# make the following two lines active:
#
lab6b.o: lab6b.s
	gcc -c -g lab6b.s
#
# AND comment out these two lines:
#lab6b.o: lab6b.c
#	gcc -c -g -Wall -O0 lab6b.c

clean:
	rm -rf *.o lab6
