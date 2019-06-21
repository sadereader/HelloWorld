#include <stdio.h>

void swap(int *a, int*b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int main() {

	int iArray[5] = {1,2,3,4,5};
	int *iP = iArray;
	for (iP = iArray; iP <= &iArray[4]; iP++)
		printf("%d ", *iP);
	int x = 2, y = 4;
	printf("%d, %d\n", x, y);
	swap(&x, &y);
	printf("%d, %d\n", x, y);
	return 0;
}

/*
int main() {
	int x = 5;
	int * iPtr = &x;
	int y = 10;
	printf("iPtr=%x\n", (unsigned int)iPtr);
	printf("*iPtr=%d\n", *iPtr);
	*iPtr = *iPtr + 5;
	x *= 3;
	printf("iPtr=%x\n", (unsigned int)iPtr);
	printf("*iPtr=%d\n", *iPtr);

	x = 5;
	int *pA = &x, *pB = &y;
	printf("*pA = %d *pB = %d\n", *pA, *pB);
	pA = pB;
	x = 20;
	y = 30;
	*pA = x;
	printf("*pA = %d *pB = %d\n", *pA, *pB);
	return 0;

}
*/
