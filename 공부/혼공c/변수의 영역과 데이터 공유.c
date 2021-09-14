#include <stdio.h>

//지역 변수의 특징 1) 지역 변수는 사용범위가 블록 내부로 제한됨 다른 함수에서 사용할수 없음
//지역 변수의 특징 2) 지역 변수는 이름이 같아도 선언된 함수가 다르면 각각 독립된 저장 공간을 갖는다

//두 함수에서 같은 이름의 지역 변수를 사용한 경우
/*
void assign(void);

int main()
{
    auto int a = 0;

    assign();
    printf("main 함수 a : %d\n", a);

    return 0;
}

void assign(void)
{
    int a = 10;

    printf("assign 함수 a : %d\n", a);
}
*/

//블록 안에서 사용하는 지역 변수
//특정 블록에서 변수를 선언하면 필요한 경우 잠깐 사용하고
//메모리를 재활용하는 효과가 있다

/*
int main()
{
    int a = 10, b = 20;

    printf("교환전 a와 b의 값 : %d, %d\n", a, b);
    {
        int temp;                                                   //이 블록 에서 temp변수를 사용 하고 다시 수거함

        temp = a;   
        a = b;
        b = temp;
    }
    printf("교환 후 a와 b의 값 : %d, %d\n", a, b);

    return 0;
}*/

//전역 변수
//특정 함수의 블록에 포함되지 않는다 어떤 함수에서도 사용가능하다
//전역 변수는 초기화 하지 않아도 자동으로  0으로 초기화 된다

/*
void assign10();
void assign20();

int a;

int main()
{
    printf("함수 호출 전 a 값 : %d\n", a);

    assign10();
    assign20();

    printf("함수 호출 후 a 값 : %d\n", a);

    return 0;
}

void assign10()
{
    a = 10;
}

void assign20()
{
    int a;

    a = 20;
}
*/

//정적 지역 변수(static)

/*
void auto_func(void);
void static_func(void);

int main()
{
    int i;

    printf("일반 지역 변수(auto)를 사용한 함수...\n");
    for (i = 0; i < 3; i++)
    {
        auto_func();
    }

    printf("정적 지역 변수(static)를 사용한 함수...\n");
    for (i = 0; i < 3; i++)
    {
        static_func();
    }

    return 0;
}

void auto_func(void)
{
    int a = 0;

    a++;
    printf("%d\n", a);
}

void static_func(void)
{
    static int a;

    a++;
    printf("%d\n", a);
}
*/

//레지스터 변수(register)
//cpu의 레지스터 부분에 변수를 할당
//연산속도가 빠름, 전역 변수로 할당 불가
//컴파일러가 레지스터에 생성할지 말지를 결정함

/*
int main()
{
    register int i;
    int sum = 0;

    for (i = 1; i < 10000; i++)
    {
        sum += i;
    }

    printf("%d\n", sum);

    return 0;
}*/

//함수의 데이터 공유 방법
//원본 데이터를 보존할수있음, 안정성을 담보 해야하는 상황에 유용
//다만 원본 데이터의 수정이 목적이면 사용이 제한적

//10을 더하기 위해 값을 인수로 주는 경우

/*
int add_ten(int a);

int main()
{
    int a = 10;

    a = add_ten(a);
    printf("a : %d\n", a);

    return 0;
}

int add_ten(int a)
{
    return a = a + 10;
}
*/

//주소를 전달하는 방법
//원본 데이터를 바꿀때 유용
//그러나 사용법이 복잡하고, 절대 바꾸면 안될 데이터를 다룰때 문제가 생길수도 있음
//따라서 꼭 필요한 경우가 아니면 값을 복사해서 전달하는 방식으로 사용

/*
void add_ten(int *pa);

int main()
{
    int a = 10;

    add_ten(&a);
    printf("a : %d\n", a);

    return 0;
}

void add_ten(int *pa)
{
    *pa = *pa + 10;
}
*/

//주소를 반환하는 함수
//주의 1) 반환값의 자료형은 반환값을 저장할 포인터의 자료형과 같아야 합니다
//주의 2) 지역 변수의 주소를 반환해서는 안 됩니다

/*
int *sum(int a, int b);

int main()
{
    int *resp;

    resp = sum(10, 20);
    printf("두 정수의합 : %d\n", *resp);

    return 0;
}

int *sum(int a, int b)
{
    static int res;

    res = a + b;

    return &res;
}
*/

//도전 실전 예제

//2개의 전역 변수를 사용하고 함수를 사용해 입력,교환,출력 을 하라

/*
void input_data(int *pa, int *pb);
void swap_data(void);
void print_data(int a, int b);

int a, b;

int main()
{
    input_data(&a, &b);
    swap_data();
    print_data(a, b);

    return 0;
}

void input_data(int *pa, int *pb)
{
    printf("두 정수 입력 : ");
    scanf("%d%d", pa, pb);
}

void swap_data(void)
{
    int temp;

    temp = a;
    a = b;
    b = temp;
}

void print_data(int a, int b)
{
    printf("두 정수 출력 : %d, %d", a, b);
}
*/

