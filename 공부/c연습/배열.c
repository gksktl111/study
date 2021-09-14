#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
int main()
{
	srand(time(NULL));
	printf("\n\n === 아빠는 대머리 게임 === \n\n");
	
	int answer;		//사용자 입력값
	int treatment = rand() % 4;		//발모제 선택 0 ~ 3
	
	int cntShowBottle = 0;	// 이번 게임에 보여줄 병 갯수
	int prevCntShowBottle = 0;	// 앞 게임의 보여준 병 갯수
	// 서로 보여주는 병갯수를 다르게 하여 정답률을 높임
	
	for(int i = 1; i <= 3; i++)
	{
		int bottle[4] = {0,0,0,0};
		
		do{
			cntShowBottle = rand() % 2 + 2; // 2,3 둘중 하나
		}while(cntShowBottle == prevCntShowBottle);
		prevCntShowBottle = cntShowBottle;
		
		int isInclude = 0;	//보여줄 병 중에 발모제가 포함되었는지 여부
		
		printf("> %d 번째 시도 : ",i);
		
		
		//보여줄 병 종류를 선택
		for(int j = 0; j < cntShowBottle; j++)
		{
			int randBottle = rand() % 4;
			
			if(bottle[randBottle] == 0)
			{
				bottle[randBottle] = 1;
				if(randBottle == treatment)
				{
					isInclude = 1;
				}
			}
			else
			{
				j--;
			}
		}
		
		for(int k = 0; k < 4; k++)
		{
			if(bottle[k] == 1)
			{
				printf("%d ",k+1);
			}
		}
		
		printf("물약을 머리에 바릅니다\n\n");
		
		if(isInclude == 1)
		{
			printf(">> 성공 ! 머리가 났어요 !!\n");
		}
		else
		{
			printf(">> 실패 ! 머리가 나지 않았어요 !!\n");
		}
		
		printf("\n...계속 하려면 아무키나 누르세요....\n\n");
		getchar();
	}
	
	printf("\n\n발모제는 몇번일까요?");
	scanf("%d",&answer);
	
	if(answer == treatment + 1)
	{
		printf("\n >> 정답입니다!\n");
	}
	else
	{
		printf("\n >> 땡 ! 틀렸어요. 정답은 %d 입니다.\n",treatment + 1);
	}
	
	return 0;
}
*/

//swap문

/*
void swap(int *pa,int *pb);

int main()
{
	int a = 10;
	int b = 20;
	
	swap(&a,&b);
	
	printf("a : %d, b : %d\n",a,b);
	
	return 0;
}

void swap(int *pa,int *pb)
{
	int temp;
	
	temp = *pa;
	*pa = *pb;
	*pb = temp;
}
*/
