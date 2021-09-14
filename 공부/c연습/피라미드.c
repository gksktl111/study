#include <stdio.h>

//피라미드 쌓기

int main()
{
	int floor = 0;
	int i, j, k;

	printf("몇층으로 쌓겠습니까? : ");
	scanf("%d", &floor);

	for (i = 0; i < floor; i++)
	{

		for (j = i; j < floor - 1; j++)
		{
			printf(" ");
		}

		for (k = 0; k < i * 2 + 1; k++)
		{
			printf("*");
		}
		printf("\n");
	}

	return 0;
}
