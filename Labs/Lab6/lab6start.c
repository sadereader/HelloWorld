// Read text file, storing each "word" into a struct in an array.
// Convert "word" to integer value using strToInt(), and store result.
// Traverse the array in REVERSE order, printing out stuff.
//    If slot IS an integer, printf its value using "%d"
//    If slot is NOT an integer, printf the "word" using "%s"
//    While traversing in reverse, ALSO sum up the integers
// Finally, print out the computed sum using putMSDigit()

#include <stdio.h> // Supports getchar() and printf()
#include <string.h> // library routines that handle "string"
#include <stdlib.h>  // Contains malloc()

/*********  Global variables ***************/

struct wordLog {  // A struct that catalogues a single word
	char * thisWord; // A pointer to the "string", which is of varying length
	int intVal;  // integer value of the string (-1 if NOT an integer)
};

struct wordLog allWords[20];  // Array of structs, 1 struct per each distinct word

char word[20]; // To hold 1 word


/************  Function prototypes  *****************/
extern int newLSDigit(int, char);  // An external function
extern char toLower(char); // toLower() function from lab4

int get1Word();      // get1Word() function from lab4
void putMSDigit(long int);  // Provided below
void strToInt(int *, char []);  // Provided below

int main() {
	// Declare necessary variables
	int wordChars, wordNumber = 0, i;
	long int sum = 0;

	// For all the words in the file...
		// get1Word(), until no more words
	while ((wordChars = get1Word()))
	{
		allWords[wordNumber].thisWord = (char *)malloc(wordChars+1);
		strcpy(allWords[wordNumber].thisWord, word);
		strToInt(&allWords[wordNumber].intVal, word);
		wordNumber++;
	}
		// Allocate enough space to hold the word
		// Store the word into the right place in the array
		// Is it an integer?  Then strToInt()...
		// On to the next word!

	printf("%d words overall\n", wordNumber); // Edit to print your variable's value

	for (i = wordNumber; i > 0; i-- ) {  // For each stored word (in reverse order!)
		// If it's alphabetic, printf with "%s"
		// If it's an integer, printf its value with "%d"
		// Also create sum of integer values
		if (allWords[i-1].intVal > 0) {
			printf("%d\n", allWords[i-1].intVal);
			sum += allWords[i-1].intVal;
		}
		else
			printf("%s\t%d\n", allWords[i-1].thisWord, allWords[i-1].intVal);
	}
	printf("Sum of all digits in hex: \t0x");
	putMSDigit(sum); // Edit to print your sum of integers
	putchar('\n');

	return 0;
}

int get1Word() { // Get 1 word into global word[]
	int charsInWord = 0;
	char thisChar;
	int  wordBegun = 0;

	while ((thisChar = getchar()) != EOF) {
		if (   ((thisChar >= 'A') && (thisChar <= 'Z'))
		    || ((thisChar >= 'a') && (thisChar <= 'z'))
		    || ((thisChar >= '0') && (thisChar <= '9'))  ) {
			wordBegun = 1;
			word[charsInWord++] = toLower(thisChar);
			continue;
		}
		if (wordBegun)
			break;
	}
	word[charsInWord] = '\0';
	return charsInWord; // return # valid chars in word[] with terminating '\0' attached
}

// A recursive function to print a long int to the console
// in hex format.

void putMSDigit(long int outVal) {
	char temp;
	if (outVal >= 16)  // Is there a higher-order digit?
		putMSDigit(outVal / 16); // If so, go print it first!
	temp = (char)(outVal % 16); // AFTER higher order digits, do THIS digit
	putchar(temp > 9 ? 'A'+(temp-10) : '0'+temp);  // Int to ASCII hex
}

// A function to convert a string of ASCII numerals
// (in base-10) into an integer.  Parses the string
// in order from left to right, i.e., looks at
// highest-order digit first.  Each digit it encounters,
// it calls the newLSDigit() function, which adjusts
// the current converted value to insert the encountered
// digit as the new LOW-order digit of the integer.
// If a non-numeral ASCII char is found in the string,
// a -1 is returned, indicating a failed conversion.
// You must provide it with a POINTER to the place
// to store the result, as well as with the string.

void strToInt(int * return2Here, char aString[]) {
	int temp = 0;
	int ix;
	char aChar;

	for (ix = 0 ;  ; ix++) {
		aChar = aString[ix];
		if (aChar < '0' || aChar > '9')
			break;
		temp = newLSDigit(temp, aChar);
	}
	*return2Here = (aChar == '\0') ? temp : -1;
}
