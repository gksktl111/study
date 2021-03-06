#include <stdio.h>

//2차원 배열은 행렬 구조와 같다
//이러한 2차원 배열은 메모리 주소가 연속성을 갖는다

//학생 3명긔 네 과목 총점과 평균을 구하는 프로그램

/*
int main()
{
    int scoer[3][4];                                                            //3명의 네 과목 점수를 저장할 2차우너 배열 선언
    int total;                                                                  
    double avg;
    int i, j;

    for (i = 0; i < 3; i++)                                                     
    {
        printf("%d번 학생의 4과목의 점수 입력 : ", i + 1);
        for (j = 0; j < 4; j++)
        {
            scanf("%d", &scoer[i][j]);
        }
    }

    for (i = 0; i < 3; i++)
    {
        total = 0;
        for (j = 0; j < 4; j++)
        {
            total += scoer[i][j];
        }
        avg = total / 4.0;
        printf("%d번 학생의 총점 : %d, 평균 : %.2lf\n", i + 1, total, avg);
    }

    return 0;
}
*/

//메모리에서의 2차원 배열
//2차원 배열은 실은 1차원 배열과 같다
// □□□□
// □□□□
// □□□□
//이러한 형식이 아니라
// □□□□(1행) □□□□(2행) □□□□(3행)(구분을 위해 일부러 띄어놈) 이러한 형식으로 1차원 배열의 형태로 메모리에 연속적으로 할당된다

//-----------------------------------------------------------------------------------------------------------------------------------

//2차원 배열의 초기화

//2차원 배열의 다양한 초기화 방법

/*
int main()
{
    int num[3][4] = {
        //2차원 배열의 선언과 초기화
        {1, 2, 3, 4},   //num의 0행
        {5, 6, 7, 8},   //num의 1행
        {9, 10, 11, 12} //num의 2행
    };

    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%5d", num[i][j]);
        }
        printf("\n");
    }

    return 0;
}
*/

//2차원 배열에서 일부 초깃값 생략
//남은 공간은 0으로 초기화
//int num[3][4] = {{1},{5, 6}, {9, 10, 11} };

//행의 수 생략 (열의 개수는 생략 불가)
//남은 공간은 0으로 초기화
//int num[][4] = { {1}, {2, 3}, {4, 5, 6} };

//1차원 배열의 초기화 방식으로 초기화 (행단위로 차례로 나열)
//남은 공간은 0으로 초기화
//int num[3][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

//행의 수를 계산 하는법    cnt = sizeof(score) / sizeof(score[0]);

//여려 개의 동물 이름을 입출력하는 프
//한 행은 하나의 문자열을 저장하는 부분배열

/*
int main()
{
    char animal[5][20] = {};
    int i;
    int count;

    count = sizeof(animal) / sizeof(animal[0]);         //행의 수 계산
    for (i = 0; i < count; i++)                         //행의 수만큼 반복
    {
        scanf("%s", animal[i]);
    }

    for (i = 0; i < count; i++)
    {
        printf("%s   ", animal[i]);
    }

    return 0;
}
*/

// ---------------------------------------------------------------------------------------------
// 2차원 char배열의 초기화

// 2차원 char배열에 동물 이름을 초기화하는 방법

/*
int main()
{
    char animal[5][10] = {                              //문자 상수로 하나씩 초기화
        {'d', 'o', 'g', '\0'},
        {'t', 'i', 'g', 'e', 'r', '\0'},
        {'r', 'a', 'b', 'b', 'i', 't', '\0'},
        {'h', 'o', 'r', 's', 'e', '\0'},
        {'c', 'a', 't', '\0'} 
    };

    // 문자열 상수로 한 행씩 초기화 행의 수 생략 가능
    char animal2[5][10] = {"dog", "tiger", "rabbit", "hores", "cat"};
    int i;

    for (i = 0; i < 5; i++)
    {
        printf("%s ",animal[i]);
    }
    printf("\n");

    for (i = 0; i < 5; i++)
    {
        printf("%s ",animal2[i]);
    }
    
    return 0;
}
*/

// 3차원 배열
// 2차원 배열을 요소로 갖는것뿐 다를건 없다

/*
int main()
{
    int score[2][3][4] = {
        {{72, 80, 95, 60}, {68, 98, 83, 90}, {75, 72, 84, 90}},
        {{66, 85, 90, 88}, {95, 92, 88, 95}, {43, 72, 56, 75}}
    };
    int i, j, k;

    for (i = 0; i < 2; i++)
    {
        printf("%d반 점수...\n",i+1);
        for (j = 0; j < 3; j++)
        {
            for (k = 0; k < 4; k++)
            {
                printf("%5d",score[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
*/

// 3차원 배열을 사용할때는 그 논리적 구조에 맞게 3중 for문을 사용하는 것이 좋다
// 이때 각 for문은 바깥쪽부터 면, 행, 열을 다루는 반복문으로 사용된다

// ------------------------------------------------------------------------------------------------------

// 포인터 배열

// 포인터 배열 선언과 사용

// 포인터 배열로 여려 개의 문자열 출력
/*
int main()
{
    char *pary[5];
    int i;

    pary[0] = "dog";
    pary[1] = "elephant";
    pary[2] = "hores";
    pary[3] = "tiger";
    pary[4] = "lion";

    for (i = 0; i < 5; i++)
    {
        printf("%s ", pary[i]);
    }
    return 0;
}
*/

// 포인터 배열의 초기화
// 2차원 char 배열의 초기화 방식과 같다
// 포인터 배열의 초기화는 문자열의시작 주소만 배열 요소에 저장되며
// 2차원 char 배열의 초기화는 문자열 자체를 배열의 공간에 저장합니다 두 가지 모두 초기화 방법이 같으므로
//컴파일러는 선언되 배열에 따라 적절한 초가화를 수행합니다.

// 2차원 배열처럼 활용하는 포인터 배열
/*
int main()
{
    int ary1[4] = {1, 2, 3, 4};
    int ary2[4] = {11, 12, 13, 14};
    int ary3[4] = {21, 22, 23, 24};
    int *pary[3] = {ary1, ary2, ary3};
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%5d", pary[i][j]);
        }
        printf("\n");
    }
    return 0;
}
*/

/*
int main()
{
    int ary[5][6] = {
        {1, 2, 3, 4, 5, 0},
        {6, 7, 8, 9, 10, 0},
        {11, 12, 13, 14, 15, 0},
        {16, 17, 18, 19, 20, 0},
        {0, 0, 0, 0, 0, 0}
    };
    int i, j, temp = 0;
    int sum = 0;

    for (i = 0; i < 4; i++)
    {
        temp = 0;
        for (j = 0; j < 5; j++)
        {
            temp += ary[i][j];
        }
        ary[i][j] = temp;
        sum += temp;
    }

    for (j = 0; j < 5; j++)
    {   
        temp = 0;
        for (i = 0; i < 4; i++)
        {
            temp += ary[i][j];
        }
        ary[i][j] = temp;
    }

    sum = 0;

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 5; j++)
        {
            sum += ary[i][j];       
        }
    }
    
    ary[4][5] = sum;

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 6; j++)
        {
            printf("%5d", ary[i][j]);
        }
        printf("\n");
    }

    return 0;
}
*/

