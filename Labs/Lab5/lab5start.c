// Working with pointers...

// There are two tasks involved.  FIRST, write
// a reverse() function that uses pointers
// to do an in-place reversal of the order of
// the chars within a string (which is a char[] ).
// Test your function by using a simple main()
// that invokes your reverse() on the first
// test phrases shown below.

// SECOND, write a more complicated main() that
// uses a for() loop to iterate through the
// line[] array.

#include <stdio.h>
#include <string.h>

// A few char[] phrases to test your function.

char phraseD[] = "A";  // Simple test phrases
char phraseE[] = "AB"; // Even length string
char phraseF[] = "ABC"; // Odd length string
char phraseA[] = "AManAPlanACanalPanama";
char phraseB[] = "NotAPalindrome";
char phraseC[] = "Kayak";


// Here's the phrases[] array.  It is an array of
// POINTERS, with each pointer referencing a
// distinct phrase.  To iterate through this
// array, you'll use a variable of type char * *
// I.e., a variable that is a pointer to ANOTHER
// pointer.

#define PHRASES 6
char * phrases[PHRASES] = { phraseA, phraseB, phraseC,
			phraseD, phraseE, phraseF };


void reverse(char []); // Prototype of your function

int main() {
	char * * phrasePtr;
	// Your main for the FIRST part of the lab...

	printf("%s\n", phraseF);
	reverse(phraseF); // Example of simple call
	printf("%s\n", phraseF);

	/*
	for ( i = 0; i < PHRASES; i++ ) {
		printf("%s\n", phrases[i]);
		reverse(phrases[i]);
		printf("%s\n", phrases[i]);
		// printf("%s\n", ??? );
		// reverse( ??? );
		// printf("%s\n\n", ???);
	}
	*/

	for (phrasePtr = phrases; phrasePtr < &phrases[PHRASES]; phrasePtr++) {
		printf("%s\n", *phrasePtr);
		reverse(*phrasePtr);
		printf("%s\n", *phrasePtr);

	}

	return 0;
}

void reverse(char cA[]) {  // In place reversal of chars in a string

	char * frontP = NULL;
	char * backP = NULL;
	char c;

	frontP = cA;
	backP = &cA[strlen(cA) - 1];

	for ( ; frontP < backP; frontP++, backP-- ) {
		c = *frontP;
		*frontP = *backP;
		*backP = c;
	}
}





