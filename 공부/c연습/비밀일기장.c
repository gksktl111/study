#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <conio.h>

//비밀번호를 입력 받아서
//맞는 경우? 비밀 일기를 읽어와서 보여주고, 계속 작성하도록 합니다.
//틀린 경우? 경고 메시지를 표시하고 종료합니다.

#define MAX 10000

int main()
{
    //fgets, fputs  사용
    char line[MAX];     //파일에서 불러온 내용을 저장할 변수
    char contents[MAX]; //일기장에 입력할 내용
    char password[20];  //비밀번호 입력
    char c;             //비밀버호 입력 할 떄 키값 확인용(마스킹)

    printf("'비밀일기'에 오신 것을 환영합니다.\n");
    printf("비밀번호를 입력하세요 : ");

    //getchar()  /  getch 의 차이?
    //getchar()   엔터를 입력받아야 동작을함니다
    //getch()     키 입력 시 바로바로 동작을합니다

    int i = 0;
    while (1)
    {
        c = getch();
        if (c == 13) // Enter
        {
            password[i] = '\n';
            break;
        }
        else //비밀번호 입력중
        {
            printf("*");
            password[i] = c;
        }
        i++;
    }

    //비밀번호 : 나도코딩

    printf("\n\n=======비밀번호 확인중...======\n\n");
    if (strcmp(password, "skehzheld") == 0) // 비밀번호가 일치
    {
        printf("===비밀번호 확인 완료===\n");
        char *fileName = "c:\\secretdiary.txt";
        //파일이 없으면 생성, 파일이 있으면 append 를 한다(뒤에서 내용를 추가한다)
        FILE *file = fopen(fileName, "a + b");
        if (file == NULL)
        {
            printf("파일 열기 실패\n");
            return 1;
        }

        while (fgets(line, MAX, file) != NULL)
        {
            printf("%s", line);
        }

        printf("\n\n 내용을 계속 작성하세요! 종료하시려면 EXIT를 입력하세요\n");

        while (1)
        {
            scanf("%[^\n]", contents); //줄 바꿈 전까지 모든 값을 받아라
            getchar();                 //Enter 입력 (\n)  Flush처리

            if (strcmp(contents, "EXIT") == 0)
            {
                printf("비밀일기 입력을 종료합니다\n");
                break;
            }
            fputs(contents, file);
            fputs("\n", file);
        }
        fclose(file);
    }
    else //비밀번호가 틀린경우
    {
        printf("\n\n=====비밀번호가 틀렸어요====\n\n");
        printf("꺆!! 당신 누구야?! 감히 내 일기장을!!!!\n\n\n");
    }

    return 0;
}