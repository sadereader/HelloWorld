// A function to integrate a new least-significant
// decimal digit into an integer.  Increases the
// existing integer value by a power of 10, then
// adds the new L.S. digit into the "ones" column.

int newLSDigit(int inVal, char inChar) {
	inVal *= 10;
	inVal += (inChar - '0');
	return inVal;
}

