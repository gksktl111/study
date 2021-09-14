#include <stdio.h>

//대문자를 소문자로 변경

/*
int main()
{
    char small, cap = 'G';

    if ((cap >= 'A') && (cap <= 'Z'))       //문자가 대문자이면
    {
        small = cap + ('a' - 'A');          //소문자로 바꾸기
    }
    printf("대문자 : %c %c", cap, '\n');    //대문자 출력
    printf("소문자 : %c\n", small);         //소문자 출력

    return 0;
}
*/

//공백이나 제어 문자의 입력

/*
int main()
{
    char ch1, ch2;

    scanf("%c%c", &ch1, &ch2);

    printf("[%c%c]", ch1, ch2);

    return 0;
}
*/

//getchar 함수와 putchar함수 사용 (글자 하나만 입력,출력)

/*
int main()
{
    int ch;

    ch = getchar();
    printf("입력한 문자 : ");

    putchar(ch);
    putchar('\n');

    return 0;
}
*/

//버퍼를 사용하는 문자 입력
/*
int main()
{
    char ch;
    int i;

    while (1)
    {
        scanf("%c", &ch);
        if (ch == '\n')
        {
            break;
        }
        printf("%c", ch);
    }

    return 0;
}
*/

//입력 문자의 아스키 코드 값을 출력하는 프로그램

/*
int main()
{
    int res;
    char ch;

    while (1)
    {
        res = scanf("%c", &ch);
        if (res == -1) break;
        printf("%d", ch);
    }

    return 0;
}
*/

//getchar 함수를 사용한 문자열 입력

/*
void my_gets(char *str, int size);

int main()
{
    char str[7];                            //7칸짜리 문자열 배열 생성

    my_gets(str, sizeof(str)); n", str);    //문자열과 문자열의 크기 넘겨줌
    printf("입력한 문자열 : %s\n",str);      //출력

    return 0;
}

void my_gets(char *str, int size)           //문자열과 문자열의 크기를 받음
{
    int ch;
    int i = 0;

    ch = getchar();                         //getchar 함수를 이용하여 문자를 미리 버퍼에 저장
    while ((ch != '\n') && (i < size - 1))  //배열의 크기만큼 입력
    {
        str[i] = ch;                        //입력한 문자를 배열에 저장
        i++;
        ch = getchar();                     //새로운 문자 입력(이때 버퍼에 저장되어있던 다음 문자가 입력되어진다)
    }
    str[i] = '\0';
}
*/

//scanf 와 getchar 함수는 같은 버퍼를 공유한다

//입력 버퍼 지우기(버퍼를 지우는 이유는 개행 문자가 남아있을시 다음 입력에 문제가 생길수도 있기떄문에)

/*
int main()
{
    int num, grade;

    printf("학번 입력 : ");                         //학번과 학점을 저장할 변수         
    scanf("%d", &num);                             //학번 입력
    getchar();                                     //버퍼 초기화
    printf("학점 입력 : ");
    grade = getchar();                             //학점 입력
    printf("학번 : %d, 학점 : %c\n", num, grade);

    return 0;
}
*/

//실전 예제


int main()
{
    int cnt = 0;
    int a = 0;
    char ch;

    ch = getchar();

    while (1)
    {
        if (ch == ']')
        {
            break;
        }
        else if (ch == '\n')
        {
            if (a < cnt)
            {
                a = cnt;
                cnt = 1;
                getchar();
                ch = getchar();
                continue;
            }
            else
            {
                cnt = 1;
                getchar();
                ch = getchar();
                continue;
            }
        }
        else
        {
            cnt++;
            ch = getchar();
        }
    }

    printf("가장 긴 단어의 길이 : %d\n", a);

    return 0;
}
