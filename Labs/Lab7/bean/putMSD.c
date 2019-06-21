// putMSD.c file from Dropbox Lab7 folder

void putMSDigit(long int outVal) {
	char temp;
	if (outVal >= 16)
		putMSDigit(outVal / 16); // Recursion!
	temp = (char)(outVal % 16);
	putchar ( temp > 9 ?
			'A' + (temp - 10) : '0' + temp );
	// See 2.11, page 51

}
int main() {
	putMSDigit(0xA5B7);
	return 0;
}

