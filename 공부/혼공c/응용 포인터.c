#include <stdio.h>

// 이중 포인터

// 포인터와 이중 포인터의 관계

/*
int main()
{
    int a = 10; // int형 변수의 선언과 초기화
    int *pi;    // 포인터 선언
    int **ppi;  // 이중 포인터 선언

    pi = &a;   // int형 변수의 주소를 저장한 포인터
    ppi = &pi; // 포인터의 주소를 저장한 이중 포인터

    printf("------------------------------------\n");
    printf("변수      변숫값      &연산     *연산      **연산\n");
    printf("------------------------------------\n");
    printf("    a %10d %10u\n", a, &a);
    printf("   pi %10u %10u %10d\n",pi,&pi,*pi);
    printf("  ppi %10u %10u %10u %10u\n",ppi,&ppi,*ppi,**ppi);
    printf("------------------------------------\n")
;
    return 0;
}
*/

// 다중 포인터 (2중 포인터의 주소는 3중 포인터에 저장한다)

// 이중 포인터를 사용한 포인터 교환

/*
void swap_ptr(char **ppa, char **ppb);

int main()
{
    char *pa = "success";
    char *pb = "failuer";

    printf("pa -> %s, pb - > %s\n", pa, pb);
    swap_ptr(&pa, &pb);                             
    printf("pa -> %s, pb - > %s\n", pa, pb);

    return 0;
}

void swap_ptr(char **ppa, char **ppb)
{
    char *pt;

    pt = *ppa;
    *ppa = *ppb;
    *ppb = pt;
}
*/

//포인터 배열의 값을 출력하는 함수

/*
void print_str(char **pps, int cnt);

int main()
{
    char *ptr_ary[] = {"eagle", "tiger", "lion", "squirrel"};
    int count;

    count = sizeof(ptr_ary) / sizeof(ptr_ary[0]); // 배열 요소의 수 계산
    print_str(ptr_ary, count);

    return 0;
}

void print_str(char **pps, int cnt)
{
    int i;

    for (i = 0; i < cnt; i++)
    {
        printf("%s\n",pps[i]);
    }
}
*/

// 주소로 쓰이는 배열명과 배열의 주소 비교

/*
int main()
{
    int ary[5];

    printf("   ary의 값 : %u\t", ary);
    printf("ary의 주소 : %u\n", &ary);
    printf("    ary + 1 : %u\t", ary + 1);
    printf("  &ary + 1 : %u\n", &ary + 1);

    return 0;
}
*/

// 2차원 배열과 배열 포인터

// 배열 포인터로 2차원 배열의 값 출력
/*
int main()
{
    int ary[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    int(*pa)[4]; // int형 변수 4개의 배열을 가리키는 배열 포인터
    int i, j;

    pa = ary;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%5d", pa[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
*/

// 2차원 배열의값을 출력하는 함수

/*
void print_ary(int (*pa)[4]);

int main()
{
    int ary[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

    print_ary(ary);

    return 0;
}

void print_ary(int (*pa)[4])
{
    int i,j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%5d",pa[i][j]);
        }
        printf("\n");
    }
}
*/

// 2차원 배열의 요소를 참조하는 원리

//------------------------------------------------------------------------------------------------

// 함수 포인터와 void 포인터

// 함수 포인터의 개념

// 함수 포인터를 사용한 함수 호출

/*
int sum(int, int);

int main()
{
    int (*fp)(int, int); // 함수 포인터 선언
    int res;             // 반환값을 저장할 변수

    fp = sum;            // 함수명을 함수 포인터에 저장
    res = fp(10, 20);    // 함수  포인터로 함수 호충
    printf("result : %d\n", res);    // 반환값 출력

    return 0;
}

int sum(int a, int b)
{
    return (a + b);
}
*/

// 함수 포인터로 원하는 함수를 호출하는 프로그램

/*
void func(int (*fp)(int, int));         // 함수 포인터를 매개변수로 갖는 함수
int sum(int a, int b);                  // 두 정수를 더하는 함수
int mul(int a, int b);                  // 두 정수를 곱하는 함수
int max(int a, int b);                  // 두 정수 중에 큰 값을 구하는 함수

int main()
{
    int sel;                                    // 선택된 번호 저장

    printf("01 두 정수의 합\n");                 // 선택지
    printf("02 두 정수의 곱\n");
    printf("03 두 정수 중에서 큰 값 계산\n");
    printf("원하는 연산을 선택하세요\n");
    scanf("%d",&sel);                           // 입력

    switch (sel)
    {
    case 1: func(sum); break;                   // 1이면 func에 덧셈 기능 추가
    case 2: func(mul); break;                   // 2이면 func에 곱셈 기능 추가
    case 3: func(max); break;                   // 3이면 func에 큰 값 구하는 기능 추가
    }

    return 0;
}

void func(int (*fp)(int, int))
{
    int a,b;
    int res;

    printf("두 정수의 값을 입력하세요 : ");
    scanf("%d%d",&a,&b);
    res = fp(a,b);
    printf("결과값은 : %d\n",res);
    
}

int sum(int a, int b)
{
    return (a+b);
}   

int mul(int a, int b)
{
    return (a*b);
}   

int max(int a, int b)
{
    if(a > b) return a;
    else return b;
}
*/

// void 포인터

// void 포인터의 사용

// 어떤 자료형이든 저장 가능
// 그러나 정해진 자료형이 없기 떄문에 간접 참조 연산에 의한 포인터 연산은 불가능

/*
int main()
{
    int a = 10;
    double b = 3.5;
    void *vp;

    vp = &a;
    printf("a : %d\n", *(int *)vp);                 // int *로 형변환

    vp = &b;
    printf("b : %.1lf\n",*(double *)vp);            //double *로 형변환

    return 0;
}
*/

// 두 명의 나이와 키를 입력한후 바꾼다
// 단, 나이와 키를 바꾸는 함수는 int 형과 double형을 모두 교환할수 있도록 하나의 함수로 구현

/*
void swap(char *data_type, void *pa, void *pb);

int main()
{
    int age1, age2;
    double height1, height2;

    printf("첫 번째 사람의 나이와 키 입력 : ");
    scanf("%d %lf", &age1, &height1);

    printf("두 번째 사람의 나이와 키 입력 : ");
    scanf("%d %lf", &age2, &height2);

    swap("int", &age1, &age2);
    swap("double", &height1, &height2);

    printf("첫 번째 사람의 나이와 키 : %d, %.1lf\n", age1, height1);
    printf("두 번째 사람의 나이와 키 : %d, %.1lf\n", age2, height2);

    return 0;
}

void swap(char *data_type, void *pa, void *pb)
{
    int temp;
    double dtemp;

    if(strcmp(data_type,"int") == 0)                //strcmp 같은 문자열이면 0 반환
    {
        temp = *(int *)pa;
        *(int *)pa = *(int *)pb;
        *(int *)pb = temp;
    }

    if(strcmp(data_type,"double") == 0)
    {
        dtemp = *(double *)pa;
        *(double *)pa = *(double *)pb;
        *(double *)pb = dtemp;
    }
}
*/

// 만약 자료형이 정해지지 않았다면 void로 받고 if 문으로 함수에서 구분하는 방법을 사용하자