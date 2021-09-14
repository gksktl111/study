#include <stdio.h>
#include <string.h>

//문자열 상수가 주소란 증거
/*
int main()
{
    printf("apple이 저장된 시작 주소 값 : %p\n", "apple");
    printf("두 번째 문자의 주소 값 : %p\n", "apple" + 1);
    printf("첫 번째 문자 : %c\n", *"apple");
    printf("두 번째 문자 : %c\n",*("apple" + 1));
    printf("배열로 표현한 세 번째 문자 : %c\n","apple"[2]);

    return 0;
}
*/

//포인터로 문자열을 사용하는법
//포인터를 사용하면 문자열의 값을 바꿀수 있다
/*
int main()
{
    char *deesert = "apple";                    //포인터에 문자열 초기화

    printf("오늘 후식은 %s입니다\n",deesert);    //문자열 출력
    deesert = "banana";                         //새로운 문자열 대입
    printf("내일 후식은 %s입니다\n",deesert);    //바뀐 문자열 출력

    return 0;
}
*/

//같은 문자열을 여러번 사용하는 경우 하나의 문자열만 메모리에 저장하고
// 그 주소를 공유하는 방식을 사용하여 최적화 된다
/*
int main()
{
    char *pa = "apple";
    char *pb = "apple";

    printf("%p \n %p",pa,pb);

    return 0;
}
*/

//scanf함수를 사용한 문자열 입력
/*
int main()
{
    char str[80];

    printf("문자열 입력\n");
    scanf("%s", str);                                         //%s를 사용하고 배열명을 준다.
    printf("첫 번째 단어 : %s\n", str);                       //배열에 입력된 문자열 출력
    scanf("%s", str);
    printf("버퍼에 남아있는 두 번째 단어 : %s\n", str);       //scanf함수는 공백 없는 연속문자를 받기때문에 공백 전까지만 출력되고 나머지는 버퍼에 남아있게된다

    return 0;
}
*/

//gets 함수로 한 줄의 문자열 입력(gets함수에로 개행문자(\n)은 널문자(\0)로 바뀌어 버퍼에 저장된다)

/*
int main()
{
    char str[80];

    printf("공백이 포함된 문자열 입력 : ");
    gets(str);                                              //배열명을 주고 함수 호출
    printf("입력한 문자열은 %s입니다.", str);

    return 0;
}
*/

//fgets함수의 문자열 입력 방법 (fgets함수는 개행 문자뒤에 널문자를 넣어서 버퍼에 저장한다)
/*
int main()
{
    char str[80];

    printf("공백이 포함된 문자열 입력 : ");
    fgets(str, sizeof(str), stdin);         //3가지 인수를 사용(str : 배열명, sizeof : 배열의 크기 확인, stdin : 키보드의 표준 입력 버퍼를 사용하라)
    str[strlen(str) - 1] = '\0';            //버퍼에서 개행문자를 제거하는 방법

    printf("입력된 문자열은 %s입니다.\n", str);

    return 0;
}
*/

//개행 문자로 인해 gets함수가 입력을 못하는 경우
//버퍼를 초기화 하는 함수로는 (getchar(), scanf("%*c"), fgets(stdin) 등이 있다)
/*
int main()
{
    int age;
    char name[20];

    printf("나이 입력 : ");
    scanf("%d", &age);

    getchar();

    printf("이름 입력 : ");
    gets(name);
    printf("나이 : %d, 이름 : %s\n", age, name);

    return 0;
}
*/

//문자열을 출력하는 puts와 fputs 함수

/*
int main()
{
    char str[80] = "apple juice";              //배열에 문자열 초기화
    char *ps = "banana";                       //포인터에 문자열 연결

    puts(str);                                 //apple juice 출력후 줄바꿈
    fputs(ps, stdout);                         //banana 출력
    puts("milk");                              //그 뒤에 milk출력

    return 0;
}
*/

//gets함수 직접 구현해 보기
/*
int main()
{
    int i = 0;
    char str[20];
    char ch;

    do
    {
        ch = getchar();
        str[i] = ch;
        i++;
    } while (ch != '\n');

    str[i] = '\0';
    printf("%s", str);

    return 0;
}
*/

/*
int main()
{
    char ani[20];
    char why[80];
    printf("좋아하는 동물 : ");
    scanf("%s", ani);

    getchar();

    printf("좋아하는 이유 : ");
    fgets(why, sizeof(why), stdin);
    printf("%s is %s", ani, why);
    return 0;
}
*/

//strcpy 함수의 사용법
/*
int main()
{
    char str1[80] = "strawberry";               //char 배열에 문자열 초기화
    char str2[80] = "apple";                    //char 배열에 문자열 초기화
    char *ps1 = "banana";                       //포인터에 문자열 상수 연결
    char *ps2 = str2;                           //포인터에 배열 연결

    printf("최초 문자열 : %s\n", str1); 
    strcpy(str1, str2);                         //다른 char 배열의 문자열 복사
    printf("바뀐 문자열 : %s\n", str1);

    strcpy(str1, ps1);                          //문자열 상수를 연결한 포인터 사용
    printf("바뀐 문자열 : %s\n", str1);

    strcpy(str1, ps2);                          //배열을 연결한 포인터 사용
    printf("바뀐 문자열 : %s\n", str1);

    strcpy(str1, "banana");                     //문자열 상수 사용
    printf("바뀐 문자열 : %s\n", str1);

    return 0;
}
*/

//strcpy 함수에서 기억할 2가지
//안수는  char 배열이나 배열명을 저장한 포인터만 사용할 수 있습니다.
//인수는 문자열의 시작 위치를 알 수 있다면 어떤 것이든 사용할 수 있습니다.

//strncpy 함수를 사용한 문자열 복사
//strncpy 함수는 끝에 NULL문자를 넣지 않는다 넣을려면 따로 넣어 줘야 한다
/*
int main()
{
    char str[80] = "mango tree";        //배열 초기화

    strncpy(str, "apple-pie", 5);       //문자열에서 다섯 문자만 복사
    printf("%s\n", str);                //출력

    return 0;
}*/

// 문자열을 붙이는 strcat, strncat 함수
// 일종의 문자열 더하기 연산자 느낌

//strcat, strncat 함수를 사용한 문자열 붙이기
/*
int main()
{
    char str[80] = "straw";

    strcat(str, "berry");
    printf("%s\n", str);
    strncat(str, "piece", 3);
    printf("%s\n", str);

    return 0;
}*/

// strcat 함수 사용 시 주의 사함
// 메모리를 침범할 수 있다(붙여넣기 하는 배열의 크기가 충분히 커야 한다)
// 배열을 초기화해야 한다(함수로 붙혀넣기 전에 널 문자의 위치를 찾으므로 반드시 초기화 해야한다 그렇지 않으면 쓰레기 값의 중간부터 붙여넣을 가능성이 크다)

//배열을 초기화 하는 방법 들
/*
char str[80] {'\0'};        //명시적으로 널 문자를 초기화
char str[80] = {0};         //널 문자의 아스키 코드 값으로 초기화
char str[80] = "";          //큰따옴표 안에 아무것도 없으므로 널 문자만 초기화
char[0] = '\0';             //첫 번째 배열 요소만 별도로 초기화 
*/

//문자열 길이를 계산하는 strlen 함수
//두 문자열 중 길이가 긴 단어 출력

/*
int main()
{
    char str1[80], str2[80];
    char *resp;

    printf("두개의 과일 이름 입력 : ");
    scanf("%s%s", str1, str2);
    if (strlen(str1) > strlen(str2))
        resp = str1;
    else
        resp = str2;
    printf("이름이 긴 과일은 : %s\n", resp);

    return 0;
}
*/

//문자열을 비교하는 strcmp, strncmp 함수
//strcmp 함수는 두 문자열의 사전 순서를 판단하여 결과를 반환함, 사전순서는 사전에 단어가 수록되는 알파벳 순서를 말함
/*
int main()
{
    char str1[80] = "pear";
    char str2[80] = "peach";

    printf("사전에 나중에 나오는 과일 이름 : ");
    if (strcmp(str1, str2) > 0)                 //str1이 str2보다 사전에 나중에 나오면 1반환
        printf("%s\n", str1);                   //str1 출력
    else
        printf("%s\n", str2);                   //str2 출력

    return 0;
}
*/

//strcpy와 기능이 같은 함수의 구현
/*
char *mystrcpy(char *pd, char *ps);

int main()
{
    char str[80] = "strawberry";

    printf("바꾸기 전 문자열 : %s\n", str);
    mystrcpy(str, "apple");
    printf("바꾼 후 문자열 : %s\n",str);
    printf("다른 문자열 대입 : %s\n",mystrcpy(str,"kiwi"));

    return 0;
}

char *mystrcpy(char *pd, char *ps)
{
    char *po = pd;

    while (*ps != '\0')
    {
        *pd = *ps;
        pd++;
        ps++;
    }
    *pd = '\0';

    return po;          //복사가 끝난 저장 공간의 시작 주소 반환
}
*/

//2,5

//p.1

/*
int main()
{
    char str1[16] = "";
    char str2[16] = "";
    int i = 0;

    printf("단어 입력 : ");
    scanf("%s", str1);

    int n = strlen(str1);

    while (i < 5)
    {
        str2[i] = str1[i];                      // 문자열의 5자를 다른 문자열로 옮긴다
        i++;
    }

    if (n > 5)
    {
        strncat(str2, "**********", n - 5);    //그후 초과된 문자만큼 * 을 붙여준다
    }

    printf("입력한 단어 : %s, 생략한 단어 : %s\n", str1, str2);             //출력한다

    return 0;
}
*/

//키보드로 세 단어를 입력받아 사전 순서대로 출력하라

//입력, 비교, 나열, 출력

/*
void array_exchange(char a[20], char b[20]);

int main()
{
    char a[20] = "";
    char b[20] = "";
    char c[20] = "";

    printf("세 단어 입력 : ");
    scanf("%s%s%s", a, b, c);

    if (strcmp(a, b) > 0)
    {
        array_exchange(a, b);
    }

    if (strcmp(a, c) > 0)
    {
        array_exchange(a, c);
    }

    if (strcmp(b, c) > 0)
    {
        array_exchange(b, c);
    }

    printf("%s, %s, %s\n", a, b, c);

    return 0;
}

void array_exchange(char a[20], char b[20])
{
    char t[20];

    strcpy(t, a);
    strcpy(a, b);
    strcpy(b, t);

    return a, b;
}
*/

