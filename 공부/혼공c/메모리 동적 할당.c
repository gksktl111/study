#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 프로그램 실행중 동적할당 할때는 malloc 함수를
// 반활할때는 free 함수를 사용합니다.
// 이 함수들을 사용 할때는 stdlib.h 헤더파일을 인클루드해야 사용할수있다

// 동적 할당한 저장 공간을 사용하는 프로그램

/*
int main()
{  
    int *pi;
    double *pd;

    pi = (int *)malloc(sizeof(int));        // 메모리 동적 할당 후 포인터 연결
    if( pi == NULL)                         // 동적 할당에 실패하면 NULL 포인터 반환
    {
        printf("# 메모리가 부족합니다 .\n");  // 예외 상황 메시지 출력
        exit(1);                            // 프로그램 종료
    }

    pd = (double *)malloc(sizeof(double));  
    if( pd == NULL)                         // 동적 할당에 실패하면 NULL 포인터 반환
    {
        printf("# 메모리가 부족합니다 .\n");  // 예외 상황 메시지 출력
        exit(1);                            // 프로그램 종료
    }

    *pi = 10;
    *pd = 3.4;

    printf("정수형으로 사용 : %d\n",*pi);
    printf("실수형으로 사용 : %.1lf\n",*pd);

    free(pi);                               // 동적 할당 영역 반환
    free(pd);

    return 0;
}
*/

// 동적 할당 영역을 배열처럼 사용
/*
int main()
{
    int *pi;
    int i, sum = 0;

    pi = (int *)malloc(5 * sizeof(int)); //저장 공간 20 바이트 할당    
    if (pi == NULL)
    {
        printf("메모리가 부족합니다,\n");
        exit(1);
    }

    printf("다섯 명의 나이를 입력하세요 : ");
    for (i = 0; i < 5; i++)
    {
        scanf("%d",&pi[i]);
        sum += pi[i];
    }

    printf("다섯 명의 평균 나이 %.1lf\n",(sum / 5.0));
    free(pi);

    return 0;    
}
*/

// calloc, realloc 함수를 사용한 양수 입력

/*
int main()
{
    int *pi;
    int size = 5;
    int count = 0;
    int num;
    int i;

    pi = (int *)calloc(size, sizeof(int));
    while (1)
    {
        printf("양수만 입력하세요 => ");
        scanf("%d", &num);
        if (num <= 0) break;
        if (count == size)
        {
            size += 5;                                  
            pi = (int *)realloc(pi,size * sizeof(int));
        }
        pi[count++] = num;
    }
    for (i = 0; i < count; i++)
    {
        printf("%5d", pi[i]);
    }
    free(pi);

    return 0;
}
*/

// 동적 할당을 사용한 문자열 처리

// 3개의 문자열을 저장하기 위한 동적할당

/*
int main()
{
    char temp[80];                                      // 임시 char 배열
    char *str[3];                                       // 동적 할당 영역을 연결할 포인터 배열
    int i;                          

    for (i = 0; i < 3; i++)
    {
        printf("문자열을 입력하세요 : ");
        gets(temp);                                     // 문지열 입력
        str[i] = (char *)malloc(strlen(temp) + 1);      // 문자열 저장 공간 할당(temp 문자열의 길이만큼 할당하고 +1하여 널문자도 삽입)
        strcpy(str[i], temp);                           // 동적 할당 영역에 문자열 복사
    }

    for (i = 0; i < 3; i++)
    {
        printf("%s\n",str[i]);
    }
    
    for (i = 0; i < 3; i++)
    {
        free(str[i]);                                  // 동적 할당 영역 반환
    }
    
    return 0;
}
*/

//동적 할당 영역에 저장한 문자열을 함수로 처리하는 예

/*
void print_str(char **ps);

int main()
{
    char temp[80];
    char *str[21] = { 0 };
    int i = 0;

    while (i < 20)
    {
        printf("문자열을 입력하세요 : ");
        gets(temp);
        if (strcmp(temp, "end") == 0) break;
        str[i] = (char *)malloc(strlen(temp) + 1);
        strcpy(str[i], temp);
        i++;
    }
    print_str(str);

    for (i = 0; str[i] != NULL; i++)
    {
        free(str[i]);
    }

    return 0;
}

void print_str(char **ps)
{
    while (*ps != NULL)
    {
        printf("%s\n",*ps);
        ps++;
    }
    
}
*/

// 명령행 인수를 출력하는 프로그램

/*
int main(int argc, char **argv)
{
    int i;

    for (i = 0; i < argc; i++)
    {
        printf("%s\n",argv[i]);
    }
    
    return 0;
}
*/

/*
int main()
{
    int **matrix = malloc(4 * sizeof(int *));
    int i, j;

    for (i = 0; i < 4; i++)
    {
        matrix[i] = malloc(5 * sizeof(int));
    }

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 5; j++)
        {
            matrix[i][j] = i + j;
        }
    }

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 5; j++)
        {
            printf("%3d", matrix[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < 4; i++)
    {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
*/

/*
int main()
{
    int i, j;

    for (i = 2; i <= 50; i++)
    {
        for (j = 2; j <= i; j++)
        {
            if (i % j == 0) break;
        }
        if (i == j) printf("%d ", i);
    }
    return 0;
}
*/

// 소수 계산 프로그램

int main()
{
    int num;  // 테스트 케이스값
    int i, j; // 반복 변수

    printf("양수 입력 : ");
    scanf("%d", &num); // 이 값 까지의 소수를 출력

    int y = num / 5;     // 세로
    int x = num - 2 % 5; // 마지막 가로의 칸 갯수 (0 과 1은 제외 이므로 -2)

    int **m = malloc(y * sizeof(int *)); // 세로 영역 동적 할당

    for (i = 0; i < y; i++)
    {
        m[i] = malloc(5 * sizeof(int)); // 가로 영역 동적 할당
        if (i == y)
        {
            m[i] = malloc(x * sizeof(int)); // 마지막 줄 가로 영역 동적 할당
        }
    }

    for (i = 2; i < num; i++)
    {
        for (j = 2; j <= i; j++)
        {
            if (i % j == 0)
            {
                break;
            }
        }
        if (i == j)
        {
            printf(" %d ", i);
        }
        else
        {
            printf(" X ");
        }

        if((i % 5) == 0)
        {
            printf("\n");
        }
    }

    return 0;
}