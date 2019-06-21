#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int i;
	for (i = 0; i < 100; i++)
	{
		printf("%d\n", i * i);
		i++;
	}
	printf("Hello world\n");

	return 0;
}
