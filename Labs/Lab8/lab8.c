#include <stdio.h>

// Revise in-process value to hold new LS digit
// by adding new digit to 10 times the existing value

int newLSDigit(int inVal, char inChar) {
	inVal *= 10;
	inVal += (inChar - '0');
	return inVal;
}

// Convert a base-10 digit string to an integer
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

int main() {

	int myInt;
	strToInt(&myInt, "7654321");
	printf("%d\n", myInt);
	return 0;
}
