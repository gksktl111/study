#include <stdio.h>

//배열명에 정수 연산을 수행하여 배열 요소 사용
/*
int main()
{
    int ary[3];
    int i;

    *(ary + 0) = 10;
    *(ary + 1) = *(ary + 0) + 10;

    printf("세 번째 배열 요소에 기보드 입력 : ");
    scanf("%d",ary + 2);

    for (i = 0; i < 3; i++)
    {
        printf("%5d", *(ary + i));
    }

    return 0;
}
*/

//배열명 처럼 사용되는 포인터
/*
int main()
{
    int ary[3];                 //배열 선언
    int *pa = ary;              //포인터에 배열명 저장
    int i;                      //반복 제어 변수

    *pa = 10;                   //첫 번째 배열 요소에 10대입
    *(pa + 1) = 20;             //두 번째 배열 요소에 20대입
    pa[2] = pa[0] + pa[1];      //대괄호를 써서 pa를 배열명처럼 사용

    for (i = 0; i < 3; i++)     //포인터로 모든 배열 요소 출력
    {
        printf("%5d", pa[i]);
    }

    return 0;
}
*/

//배열명과 포인터의 차이

//차이점 1)sizeof 연산의 결과가 다르다

/*
int main()
{
    int ary[3];
    int *pa = ary;
    
    printf("%d\n",sizeof(ary));
    printf("%d\n",sizeof(pa));

    return 0;
}
*/

//차이점 2)변수와 상수의 차이가 있다.

//포인터는 값을 바꿀수 있지만 배열명은 값을 바꿀수없다

//포인터를 이용한 배열의 값 출력

/*
int main()
{
    int ary[3] = {10,20,30};
    int *pa = ary;
    int i;

    printf("배열의 값 : ");
    for (i = 0; i < 3; i++)
    {
        printf("%d ",*(pa++));
    }
    
    return 0;
}
*/

//포인터의 뺄셈과 관계 연산

//포인터 끼리의 뺄셈 방식 =====  포인터 - 포인터  ---> 값의 차 / 가리키는 자료형 크기

/*
int main()
{
    int ary[5] = {10, 20, 30, 40, 50};
    int *pa = ary;
    int *pb = pa + 3;

    printf("pa : %u\n", pa);
    printf("pb : %u\n", pb);
    pa++;
    printf("pb - pa : %u\n", pb - pa);

    printf("앞에 있는 배열 요소의 값 출력 : ");
    if (pa < pb)                                    //대소관게 비교
        printf("%d\n", *pa);
    else
        printf("%d\n", *pb);

    return 0;
}
*/

//배열을 처리하는 함수

/*
void print_ary(int *pa);

int main()
{
    int ary[5] = {10, 20, 30, 40, 50};

    print_ary(ary);
    
    return 0;
}

void print_ary(int *pa)
{
    int i;

    for (i = 0; i < 5; i++)
    {
        printf("%d\n", pa[i]);
    }
}
*/

//배열 요소의 개수가 다른 배열도 출력하는 함수

/*
void print_ary(int *pa, int size);

int main()
{
    int ary1[5] = {10, 20, 30, 40, 50};
    int ary2[7] = {10, 20, 30, 40, 50, 60, 70};

    print_ary(ary1, 5);
    printf("\n");
    print_ary(ary2, 7);

    return 0;
}

void print_ary(int *pa, int size)
{
    int i;

    for (i = 0; i < size; i++)
    {
        printf("%d\n", pa[i]);
    }
}
*/

//배열에 값을 입력하는 함수

/*

void input_ary(double *pa, int size);
double find_max(double *pa, int size);

int main()
{
    double ary[5];
    double max;                              //최대값을 저장할 변수
    int size = sizeof(ary) / sizeof(ary[0]); //배열 요소의 개수 계산

    input_ary(ary, size);
    max = find_max(ary, size);
    printf("배열의 최대값 : %.1lf\n", max);

    return 0;
}

void input_ary(double *pa, int size)
{
    int i;

    printf("%d개의 실수값 입력 : ", size);
    for (i = 0; i < size; i++)
    {
        scanf("%lf", pa + i);
    }
}

double find_max(double *pa, int size)
{
    int i;
    double max = pa[0];

    for (i = 0; i < size; i++)
    {
        if (max < pa[i]) max = pa[i];
    }

    return max;
}
*/

//1부터45중에 6개의 수를 입력
//중복 되는 수인지 검사 후 배열에 입력
//입력이 끝나면 순서대로 출력

/*
void input_nums(int *lotto_num);
void print_num(int *lotto_num);

int main()
{
    int lotto_num[6];

    input_nums(lotto_num);
    print_num(lotto_num);

    return 0;
}

void input_nums(int *lotto_nums)

{
    int num;
    int i, j;
    int dup;

    for (i = 0; i < 6; i++)
    {
        printf("번호 입력 : ");

        scanf("%d", &num);

        dup = 0;

        for (j = 0; j < i; j++)
        {
            if (num == lotto_nums[j])
            {
                dup = 1;

                break;
            }
        }

        if (!dup)
        {
            lotto_nums[i] = num;
        }
        else
        {
            printf("같은 번호가 있습니다!\n");

            i--;
        }
    }
}

void print_num(int *lotto_num)
{
    printf("로또 번호 : ");

    for (int i = 0; i < 6; i++)
    {
        printf("%d ", lotto_num[i]);
    }
}
*/

