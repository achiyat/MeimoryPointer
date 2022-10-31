#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)

int main()
{
	int a;
	int* b;


	b = malloc(4 * sizeof(int));
	int* original = b;
	*b = 100;
	b++;
	*b = 200;
	b++;
	*b = 300;
	b++;
	*b = 400;

	b--;
	b--;
	b--;

	printf("%d\n", *b);
	b++;
	printf("%d\n", *b);
	b++;
	printf("%d\n", *b);
	b++;
	printf("%d\n", *b);
	b++;

	free(original);

	return 0;
}