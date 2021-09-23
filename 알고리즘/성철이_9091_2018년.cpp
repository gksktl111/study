#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int is_vps();

int main() 
{

	int num = 0;
	int T = 0;
	scanf("%d", &T);

	while (num < T) 
	{

		if (is_vps() == 0) 
		{
			printf("YES\n");
		}
		else 
		{
			printf("NO\n");
		}
		num++;
	}
	return 0;
}


int is_vps()
{
	char* string = (char*)malloc(sizeof(char) * 51);
	scanf("%s", string);
	int len = strlen(string);
	int i = 0;
	int res = 0;
	for (i = 0; i < len; i++) 
	{
		if (string[i] == '(') 
		{
			res++;
		}
		if(string[i] == ')') 
		{
			res--;
		}

		if (res < 0) 
		{
			free(string);
			return res;
		}
	}
	free(string);
	return res;
}