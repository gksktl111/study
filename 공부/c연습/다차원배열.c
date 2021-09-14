#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
int main()
{

	int arr3[4][2] = {
		{1,2},
		{3,4},
		{5,6},
		{7,8}
	};
	
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			printf("2차원배열 (%d,%d)의 값 : %d\n",i,j,arr3[i][j]);
		}
		printf("\n");
	}

	
	int arr4[3][3][3] = {
	{
		{1,2,3},
		{4,5,6},
		{7,8,9}
	},
	{
		{11,12,13},
		{14,15,16},
		{17,18,19}
	},
	{
		{21,22,23},
		{24,25,26},
		{27,28,29}
	}
};	
		for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			for(int k = 0; k < 3; k++)
			{
				printf("3차원배열 (%d,%d,%d)의 값 : %d\n",i,j,k,arr4[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}
	
	return 0;
}
*/

// 10마리의 서로다른 동물 (각 카드 2장씩)
// 사용자로 부터 2개의 입력값을 받아서 -> 같은 동물을 찾으면 카드를 뒤집기
// 모든 동물쌍을 찾으면 게임 종료
// 총 실패 횟수 알려주기

/*
int arrayAnimal[4][5];	//카드 지도 (20장의 카드)
int checkAnimal[4][5];	//뒤집혔는지 여부 확인
char *strAnimal[10];

void initAnimalArray();
void initAnimalName();
void shuffleAnimal();
int getEmptyPostion();
int conv_pos_x(int x);
int conv_pos_y(int y);
void printfAnimals();
void printfQuestion();




int main()
{
	srand(time(NULL));
	
	initAnimalArray();
	initAnimalName();
	
	shuffleAnimal();
	
	int failCount = 0; //실패 횟수
	
	while(1)
	{
		int select1 = 0; //사용자가 선택한 처음 수
		int select2 = 0; //사용자가 선택한 두번째 수
	
		printfAnimals(); //동물 위치 출력
		printfQuestion();//문제 출력
		printf("뒤집을 카드를 2개 고르세요 : ");
		scanf("%d %d",&select1, &select2);
		
		if(select1 == select2)
		{
			continue;
		}
		
		// 좌표에 해당하는 카드를 뒤집어 보고 같은지 다른지 확인
		
		// 정수 좌표를 (x,y) 로 변환
		int firstSelect_x = conv_pos_x(select1);
		int firstSelect_y = conv_pos_y(select1);
		
		int secondSelect_x = conv_pos_x(select2);
		int secondSelect_y = conv_pos_y(select2);
		
		//카드가 뒤집혀졌던건지 확인 && 두 동물이 같은지 확인
		if((checkAnimal[firstSelect_x][firstSelect_y] == 0
		  && checkAnimal[secondSelect_x][secondSelect_y] == 0)

		  &&
		   
		   (arrayAnimal[firstSelect_x][firstSelect_y]
		   == arrayAnimal[secondSelect_x][secondSelect_y])
		  )
		{
			printf("\n\n빙고! : %s 발견 \n\n",strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
			checkAnimal[firstSelect_x][firstSelect_y] = 1;
			checkAnimal[secondSelect_x][secondSelect_y] = 1;
		}
		//다른동물인 경우
		else
		{
			printf("\n\n땡!!(틀렸거나, 이미 뒤집힌 카드입니다.)\n");
			printf("%d ; %s\n",select1,strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
			printf("%d ; %s\n",select2,strAnimal[arrayAnimal[secondSelect_x][secondSelect_y]]);
			printf("\n\n");
			
			failCount++;
		}
		// 모든 동물을 찾았는지 여부, 1 : 참, 0 : 거짓
		if(foundAllAnilmas() == 1 )
		{
			printf("\n\n 축하합니다! 모든 동물을 다 찾았네요 \n");
			printf("지금까지 총 %d 번 실수하셨습니다",failCount);
			break;
		}
		
	}
	
	return 0;
}

void initAnimalArray()
{
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			arrayAnimal[i][j] = -1;
		}
	}
}

//동물 10마리 선언

void initAnimalName()
{
	strAnimal[0] = "원숭이";
	strAnimal[1] = "하마";
	strAnimal[2] = "고양이";
	strAnimal[3] = "강아지";
	strAnimal[4] = "돼지";

	strAnimal[5] = "코끼리";
	strAnimal[6] = "기린";
	strAnimal[7] = "낙타";
	strAnimal[8] = "타조";
	strAnimal[9] = "호랑이";

}

void shuffleAnimal()
{
	//ㅁㅁㅁㅁㅁ  0  1  2  3  4
	//ㅁㅁㅁㅁㅁ  5  6  7  8  9
	//ㅁㅁㅁㅁㅁ 10 11 12 13 14
	//ㅁㅁㅁㅁㅁ 15 16 17 18 19
	
	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			int pos = getEmptyPostion();
			int x = conv_pos_x(pos);
			int y = conv_pos_y(pos);
			
			arrayAnimal[x][y] = i;
		}
	}
}

//좌표에서 빈공간 찾기

int getEmptyPostion()
{
	//ㅁㅁㅁㅁㅁ  0  1  2  3  4
	//ㅁㅁㅁㅁㅁ  5  6  7  8  9
	//ㅁㅁㅁㅁㅁ 10 11 12 13 14
	//ㅁㅁㅁㅁㅁ 15 16 17 18 19
	
	while(1)
	{
		int randPos = rand() % 20; //0 ~ 19 사이의 숫자 반환
		// 19 -> (3,4)
		int x = conv_pos_x(randPos);
		int y = conv_pos_y(randPos);
		
		if(arrayAnimal[x][y] == -1)
		{
			return randPos;
		}
	}
	
	return 0;
}

int conv_pos_x(int x)
{
	return x/5;
}

int conv_pos_y(int y)
{
	return y % 5;
}

void printfAnimals()
{
	printf("\n=======이건 비밀인데.. 몰래 보여줍니다============\n\n");
	
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			printf(" %8s ",strAnimal[arrayAnimal[i][j]]);
		}
		printf("\n");
	}
	printf("\n==================================================\n\n");
}

void printfQuestion()
{
	printf("\n\n(문제)\n");
	int seq = 0;
	
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			//카드를 뒤집어서 정답을 맞혔으면 '동물 이름'
			if(checkAnimal[i][j] != 0)
			{
				printf("  %8s",strAnimal[arrayAnimal[i][j]]);
			}
			//아직 뒤집지 못했으면 (정답을 못맞혔으면) 뒷면 -> 위치를 나타내는 숫자
			else
			{
				printf("%8d",seq);
			}
			seq++;
		}
		printf("\n");
	}
}

int foundAllAnilmas()
{
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			if(checkAnimal[i][j] == 0)
			{
				return 0;
			}
		}
	}
	return 1; //모든 동물을 찾았다
}
*/
