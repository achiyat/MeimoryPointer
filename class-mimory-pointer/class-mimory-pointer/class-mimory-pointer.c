#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)

int* alloc5Numbers(int a, int b, int c, int d, int e)
{
	int* place;
	int* original;
	place = malloc(5 * sizeof(int));
	original = place;

	if (place == NULL)
	{
		printf("error message");
	}
	else
	{
		*place = a;
		place++;
		*place = b;
		place++;
		*place = c;
		place++;
		*place = d;
		place++;
		*place = e;
	}
	return original;
}

int printNum(int* numberList)
{
	int sum = 0;
	int* ptr = numberList;
	for (int i = 0; i < 5; i++)
	{
		sum += *ptr;  // sum+=3     sum=sum+3
		ptr++;
	}

	return sum;
}

int main()
{
	int* savemeimory = alloc5Numbers(10, 20, 30, 40, 50);
	int sum = printNum(savemeimory);
	printf("%d", sum);

	free(savemeimory);

	return 0;
}
/*
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
*/