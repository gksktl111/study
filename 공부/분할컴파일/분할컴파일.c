#include <stdio.h>

// 사용자 정의 헤더파일을 사용하는 프로그램
/*
#include "student.h"

int main()
{
    Student a = {315, "홍길동"};

    printf("학번 : %d, 이름 : %s\n",a.num,a.name);

    return 0;
}
*/

// 다양한 매크로명 사용

/*
#define PI 3.14159
#define LIMIT 100.0
#define MSG "passed!"
#define ERR_PRN printf("허용 범위를 벗어났습니다!\n")

int main()
{
    double radius, area;

    printf("반지름을 입력하세요(10이하) : ");
    scanf("%lf", &radius);
    area = PI * radius * radius;
    if (area > LIMIT) ERR_PRN;
    else printf("원의 면적 : %.2lf (%s)\n",area,MSG);

    return 0;
}
*/

// 매크로 함수를 사용한 프로그램
/*
#define SUM(a, b) ((a) + (b))
#define MUL(a, b) ((a) * (b))

int main()
{
    int a = 10, b = 20;
    int x = 30, y = 40;
    int res;

    printf("a + b = %d\n", SUM(a, b));
    printf("x + Y = %d\n", SUM(x, y));
    res = 30 / MUL(2, 5);
    printf("res : %d\n", res);

    return 0;
}
*/

/*
void func();

int main()
{
    printf("컴파일 날짜와 시간 : %s, %s\n\n", __DATE__, __TIME__);
    printf("파일명 : %s\n", __FILE__);
    printf("함수명 : %s\n", __FUNCTION__);
    printf("행번호 : %d\n", __LINE__);

#line 100 "macro.c"
    func();

    return 0;
}

void func()
{
    printf("\n");
    printf("파일명 : %s\n", __FILE__);
    printf("함수명 : %s\n", __FUNCTION__);
    printf("행번호 : %d\n", __LINE__);
}
*/

// #과 ##을 사용한 매크로 함수

/*
#define PRINT_EXPR(x) printf(#x " = %d\n", x)
#define NAME_CAT(x, y) (x##y)

int main()
{
    int a1, a2;

    NAME_CAT(a, 1) = 10;
    NAME_CAT(a, 2) = 20;
    PRINT_EXPR(a1 + a2);
    PRINT_EXPR(a2 - a1);

    return 0;
}
*/

// 조건부 컴파일 지시자
/*
#define VER 6
#define BIT16

int main()
{
    int max;

#if VER >= 6
    printf("버전 %d입니다.\n",VER);
#else
#error 컴파일러 버전은 6.0 이상이어야 합니다
#endif
#ifdef BIT16
    max = 32767;
#else 
    max = 2147483647;
#endif

    printf("int 형 변수의 최댓값 : %d\n",max);

    return 0;
}
*/

// pragma 지시자
/*
#pragma pack(push, 1)
typedef struct
{
    char ch;
    int in;
} Sample1;

#pragma pack(pop)
typedef struct
{
    char ch;
    int i;
} Sampel2;

int main()
{
    printf("Sample1 구조체의 크기 : %d바이트\n", sizeof(Sample1));
    printf("Sample2 구조체의 크기 : %d바이트\n", sizeof(Sampel2));

    return 0;
}
*/

// 두 정수의 평균을 구하는 프로그램
/*
void input_data(int *, int *); // 두 정수를 입력하는 함수 선언
double average(int, int);      // 평균을 구하는 함수 선언

int main()
{
    int a, b;
    double avg;

    input_data(&a, &b);
    avg = average(a, b);
    printf("%d와 %d의 평균 : %.1lf\n", a, b, avg);

    return 0;
}
*/

// 전역 변수에 extern과 static을 사용한 프로그램 main, pint_data 함수 정의

int input_data();
double average();
void print_data(double);

int count = 0;        // 입력한 양수의 수 누적
static int total = 0; // 입력한 양수의 합

int main()
{
    double avg; // 입력한 양수의 평균

    total = input_data();
    avg = average();
    print_data(avg);

    return 0;
}

void print_data(double avg)
{
    printf("입력한 양수의 개수 : %d\n", count);
    printf("전체 합과 평균 : %d, %.1lf\n", total, avg);
}