#include <stdio.h>
#include <stdlib.h> // 난수 생성
#include <time.h>	// 시간
#define CLOCKS_PER_SEC

//물고기 키우기 (왜 안되는지 모르겠음 clock이 안먹히는거 같기도함)

int level;
int arrayFish[6];
int *cursor; //arrayFish를 가리키며 물을 배달해 주는 역할

void initData();
void printFishes();
void decreaseWater(long elapsedTime);
int checkFishAlive();

int main()
{
	long startTime = 0;		   //게임 시작시간
	long totalElapsedTime = 0; //총 경과 시간
	long prevElapsedTime = 0;  //직전 경과 시간	(최근의 물을 준 시간)

	int num;	//몇 번 어항에 물을 줄것인지, 사용자 입력을 받음
	initData(); //초기화 할 데이터들

	cursor = arrayFish; //cursor[0] .. cursor[1] .. cursor를 배열명으로 사용할수 있음

	startTime = clock(); // 현재 시간을 millisecond (1000분의 1초) 단위로 변환

	while (1)
	{
		printFishes();
		printf("시작시간 : %d\n",startTime);
		printf("몇 번 어항에 물을 주시겠어요? ");
		scanf("%d", &num);

		//입력값 체크
		if (num < 1 || num > 6)
		{
			printf("\n입력값이 잘못되었습니다.\n");
			continue;
		}

		printf("현재시간 : %d\n",clock());
		//총 경과 시간
		totalElapsedTime = (clock() - startTime) / CLOCKS_PER_SEC 1000; // 총 경과 시간 = (시간 - 0) / 밀리초(1000분의1초)
		printf("총 경과 시간은 : %ld 초\n", totalElapsedTime);

		//직전 물 준 시간(마지막으로 물 준 시간) 이후로 흐른 시간
		prevElapsedTime = totalElapsedTime - prevElapsedTime;
		printf("최근 경과 시간 : %ld 초\n", prevElapsedTime);

		//어항의 물을 감소(증발)
		decreaseWater(prevElapsedTime);

		// 사용자가 입력한 어항에 물을 준다
		// 1. 어항에 물이 0이면? 물을 줄 필요가 없다
		if (cursor[num - 1] <= 0)
		{
			printf("%d 번 물고기는 이미 죽었습니다.. 물을 주지 않습니다\n", num);
		}
		else if (cursor[num - 1] + 1 <= 100) //2. 어항의 물이 0이 아닌 경우 물을 준다 100을 넘지 않는지 체크
		{
			//물을준다
			printf("%d 번 어항에 물을 줍니다\n\n", num);
			cursor[num - 1] += 1;
		}

		//레벨업을 할건지 확인 (레벨업은 20초 마다 한번씩 수행)
		if ((totalElapsedTime / 20) > level - 1)
		{
			//레벨업
			level++; //level : 1 -> level : 2
			printf("*** 축 레벨업 ! 기존 %d 레벨에서 %d 레벨로 업그레이드 ***\n\n", level - 1, level);

			//최종 레벨 : 5
			if (level == 5)
			{
				printf("\n\n축하합니다. 최고 레벨을 달성하셨습니다. 게임을 종료합니다");
				exit(0);
			}
		}

		//모든 물고기가 죽었는지 확인
		if (checkFishAlive() == 0)
		{
			//물고기 모두 사망
			printf("모든 물고기가.. ㅠㅠ 흑흑 \n\n");
			exit(0);
		}
		else
		{
			//최소 한마리 이상은 살아있음
			printf("물고기가 아직 살아있어요!\n");
		}

		//	
		prevElapsedTime = totalElapsedTime;	// 총경과 시간을 임시호 저장해서 반복문이 다시 돌때 사용
	}

	return 0;
}

void initData()
{
	level = 1; //게임 레벨 (1~5)
	for (int i = 0; i < 6; i++)
	{
		arrayFish[i] = 100; //어항의 물 높이 (0~100)
	}
}

// 물고기들의 어항 상태를 출력
void printFishes()
{
	printf("%3d번 %3d번 %3d번 %3d번 %3d번 %3d번\n", 1, 2, 3, 4, 5, 6);
	for (int i = 0; i < 6; i++)
	{
		printf(" %4d ", arrayFish[i]);
	}
	printf("\n\n");
}

void decreaseWater(long elapsedTime)
{
	for (int i = 0; i < 6; i++)
	{
		arrayFish[i] -= (level * 3 * (int)elapsedTime); //3 난이도 조절을 위한 값
		if (arrayFish[i] < 0)							// 어항의 값이 -가 될수는 없으니 -가 되면 0을 넣는다
		{
			arrayFish[i] = 0;
		}
	}
}

int checkFishAlive()
{
	for (int i = 0; i < 6; i++)
	{
		if (arrayFish[i] > 0)
			return 1; //참 true
	}
	return 0;	// 죽음
}