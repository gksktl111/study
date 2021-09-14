#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//구조체

/*
struct GameInfo {
	char *name;
	int year;
	int price;
	char *company;	
	
	struct GameInfo * friendGame;
};

typedef struct {
	char *name;
	int year;
	int price;
	char *company;	
	
	struct GameInfo * friendGame;
} GAME_INFO;

int main()
{
	//구조체사용
	struct GameInfo gameinfo1;
	gameinfo1.name = "나도게임";
	gameinfo1.year = 2021;
	gameinfo1.price = 50;
	gameinfo1.company = "나도회사";
	
	printf("--게임 출시 정보--\n");
	printf("  게임명  : %s\n",gameinfo1.name);
	printf("  출시일  : %d\n",gameinfo1.year);
	printf("  가격    : %d\n",gameinfo1.price);
	printf("  회사    : %s\n",gameinfo1.company);
	
	struct GameInfo gameinfo2 = {"너도게임", 2021, 100, "너도회사"};
	
	printf("--게임 출시 정보--\n");
	printf("  게임명  : %s\n",gameinfo2.name);
	printf("  출시일  : %d\n",gameinfo2.year);
	printf("  가격    : %d\n",gameinfo2.price);
	printf("  회사    : %s\n",gameinfo2.company);
	
	//구조체 배열
	
	struct GameInfo gameArray[2] = {
		{"나도게임", 2021, 50, "나도회사"},
		{"너도게임", 2021, 100, "너도회사"}
	};
	
	//구조체 포인터
	
	struct GameInfo * gamePtr;
	gamePtr = &gameinfo1;
	
	printf("\n\n--미션맨의 게임 출시 정보--\n");
	printf("  게임명  : %s\n",(*gamePtr).name);
	printf("  출시일  : %d\n",(*gamePtr).year);
	printf("  가격    : %d\n",(*gamePtr).price);
	printf("  회사    : %s\n",(*gamePtr).company);
	
		//구조체 포인터일때는 화살표를 사용한다

	
	printf("\n\n--미션맨의 게임 출시 정보--\n");
	printf("  게임명  : %s\n",gamePtr->name);
	printf("  출시일  : %d\n",gamePtr->year);
	printf("  가격    : %d\n",gamePtr->price);
	printf("  회사    : %s\n",gamePtr->company);
		
	//연관업체 게임 소개(구조체 안에 구조체)
	
	gameinfo1.friendGame = &gameinfo2;
	
	printf("\n\n--연관업체의 게임 출시 정보--\n");
	printf("  게임명  : %s\n",gameinfo1.friendGame->name);
	printf("  출시일  : %d\n",gameinfo1.friendGame->year);
	printf("  가격    : %d\n",gameinfo1.friendGame->price);
	printf("  회사    : %s\n",gameinfo1.friendGame->company);
	
	//typedef
	//자료형에 별명을 지정
	
	typedef int c;
	typedef float n;
	c a = 10;
	n num = 3.21123; 
	
	printf("\n\n a의 값 : %d\n",a);
	printf("\n\n n의 값 : %.2f\n",num);
	
	typedef struct GameInfo GI;
	GI game1;
	game1.name = "한글게임";
	game1.year = 2021;
	game1.price = 12000000;
	game1.company = "steam";
	
	printf("\n\n--연관업체의 게임 출시 정보--\n");
	printf("  게임명  : %s\n",game1.name);
	printf("  출시일  : %d\n",game1.year);
	printf("  가격    : %d\n",game1.price);
	printf("  회사    : %s\n",game1.company);
	
	GAME_INFO game2;
	game2.name = "dddd";
	game2.year = 21321;
	game2.price = 123213;
	game2.company = "asdsada";
	
	printf("\n\n--연관업체의 게임 출시 정보--\n");
	printf("  게임명  : %s\n",game2.name);
	printf("  출시일  : %d\n",game2.year);
	printf("  가격    : %d\n",game2.price);
	printf("  회사    : %s\n",game2.company);
	
	return 0;
}
*/

//5마리의 고양이가 있다
//아무 키나 눌러서 랜덤으로 고양이를 뽑되
//5마리 모두 다 수집을 해서 열심히 키우면 되는 게임
//그런데 중복 발생 가능

//고양이
//이름, 나이, 성격, 키우기 난이도 (레벨)

typedef struct
{
    char *name;      //이름
    int age;         //나이
    char *character; //성격
    int level;       //키우기 난이도(1~5)
} CAT;

//현재까지 보유한 고양이
int collection[5] = {0, 0, 0, 0, 0};
int cnt = 0;
//전체 고양이 리스트
CAT cats[5];

void initCats();
void printfCat(int selected);

int main()
{
    srand(time(NULL));

    initCats();

    while (1)
    {
        printf("두근두근~! 어느 고양이의 집사가 될까요?\n아무키나 눌러서 확인하세요");
        getchar();

        cnt++;

        int selected = rand() % 5;
        printfCat(selected); //고양이 정보 출력

        collection[selected] = 1; //뽑은 고양이 처리

        int collectAll = checkCollection();
        if (collectAll == 1)
        {
            break;
        }
    }

    return 0;
}

void initCats()
{
    cats[0].name = "깜냥이";
    cats[0].age = 5;
    cats[0].character = "온순";
    cats[0].level = 1;

    cats[1].name = "귀요미";
    cats[1].age = 3;
    cats[1].character = "날카로움";
    cats[1].level = 2;

    cats[2].name = "수줍이";
    cats[2].age = 7;
    cats[2].character = "늘 잠만 잠";
    cats[2].level = 3;

    cats[3].name = "까꿍이";
    cats[3].age = 2;
    cats[3].character = "시끄러움";
    cats[3].level = 4;

    cats[4].name = "돼냥이";
    cats[4].age = 1;
    cats[4].character = "배고픔";
    cats[4].level = 5;
}

void printfCat(int selected)
{
    printf("\n\n==당신은 이 고양이의 집사가 되었어요!\n\n");
    printf("이름        : %s\n", cats[selected].name);
    printf("나이        : %d\n", cats[selected].age);
    printf("특징(성격)  : %s\n", cats[selected].character);
    printf("레벨        : ");

    for (int i = 0; i < cats[selected].level; i++)
    {
        printf("%s", " ★ ");
    }
    printf("\n\n");
}

int checkCollection()
{
    //현재 보유한 고양이도 출력
    //다모았는지 출력

    int collectAll = 1;

    printf("\n\n=====현재 보유한 고양이 목록이에요====\n\n");
    for (int i = 0; i < 5; i++)
    {
        if (collection[i] == 0) // 고양이  수집 X
        {
            printf("%10s", "(빈 박스)");
            collectAll = 0;
        }
        else //고양이 수집 O
        {
            printf("%10s", cats[i].name);
        }
    }
    printf("\n============================================\n\n");

    if (collectAll) //모든 고양이를 다모은 경우
    {
        printf("총 뽑기 횟수는 %d회 입니다", cnt);
        printf("\n\n축하합니다~! 모든 고양이를 다 모았습니다. 열심히 키워주세요\n\n");
    }

    return collectAll;
}















