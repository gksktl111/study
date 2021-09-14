#include <stdio.h>
#include <time.h>

//간단한 계산기

/*
int Calculator(int num1, char sign, int num2);

int main()
{
	int num1,num2;
	char sign;
	
	printf("ㅁ ㅁ형식으로 입력해주세요\n");
	scanf("%d%c%d",&num1,&sign,&num2);
	
	printf("답은 %d 입니다\n",Calculator(num1,sign,num2));
	
	return 0;
}

int Calculator(int num1, char sign, int num2){
	if(sign == '+')
	{
		return num1 + num2;
	}
	else if(sign == '-')
	{
		return num1 - num2; 
	}
	else if(sign == '*')
	{
		return num1 * num2;
	}
	else if(sign == '/')
	{
		return num1 / num2;
	}
}
*/

// 비밀번호 마스터

/*
int getRandomNumber(int x);
void showQuestion(int i,int num1,int num2);
void success();
void fail();

int main()
{
	srand(time(NULL));
	int answer;
	int count = 0;
	
	for(int i = 1; i <= 5; i++)
	{
		int num1 = getRandomNumber(i);
		int num2 = getRandomNumber(i);
		showQuestion(i,num1,num2);
		
		printf("정답을 입력해 주세요 : ");
		scanf("%d",&answer);
		
		if(answer == -1)
		{
			printf("프로그램을 종료합니다.\n");
			exit(0);
		}
		else if(answer == num1 * num2)
		{
			success();
			count++;
		}
		else
		{	
			fail();
		}
	}
	
	printf("5개의 문중 %d개의 문을 통과 하셨습니다!\n",count);
	
	return 0;
}
int getRandomNumber(int x)
{
	return rand() % (x * 7) + 1;
}

void showQuestion(int x,int num1,int num2)
{
	printf("\n\n\n############### %d 번째 비밀번호 ##########\n",x);
	printf("\n\n%d * %d 는?\n\n",num1,num2);
	printf("\n비밀번호를 입력하세요 (종료 : -1) >> ");
}

void success()
{
	printf("\n >> GOOD ! 정답입니다. \n");
}

void fail()
{
	printf("\n >> BAD ! 오답입니다. \n");
}
*/
