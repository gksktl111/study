#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 파일을 열고 닫는 프로그램
/*
int main()
{
    FILE *fp;

    fp = fopen("a.txt", "r");   // a.txt 파일을 읽기 전용으로 개방  (read)
    if (fp == NULL) // fp가 널 포인터면 파일 개방 실패
    {
        printf("파일이 열리지 않았습니다.\n");
        return 1;   // 프로그램 종료
    }
    printf("파일이 열렸습니다!\n");
    fclose(fp);

    return 0;
}
*/

// 개방 모드의 종류
// r : (파일이 있을때)읽기 위해 개방   //(파일이 없을때) NULL반환
// w : (파일이 있을때)파일의 내용을 지우고 쓰기 위해 개방 // (파일이 없을때) 새로운 파일 생성
// a : (파일이 있을때)파일의 끝에 추가하기 위해 개방 // (파일이 없을때) 새로운 파일 생성

// 문자열을 한 문자씩 파일로 출력하기
/*
int main()
{
    FILE *fp;   // 파일 포인터 선언
    char str[] = "banana"; // 출력할 문자열 선언
    int i;  // 반복 제어 변수

    fp = fopen("b.txt", "w"); // 쓰기 전용으로 개방
    if (fp == NULL) // 파일 개방 확인
    {
        printf("파일을 만들지 못했습니다.\n");
        return 1;
    }

    i = 0;  // 문자 배열의 첫 번째 문자부터 출력
    while (str[i] != '\0')// 널문자가 아니면
    {
        fputc(str[i], fp);  // 문자를 파일에 출력
        i++;    // 다음으로 이동
    }
    fputc('\n', fp);    // 개행을 파일에 입력
    fclose(fp); // 파일닫음

    return 0;
}
*/

// 표준 입출력 스트림을 사용한 문자열 출력
/*
int main()
{
    int ch; // 입력할 문자를 저장할 변수

    while (1)
    {
        ch = getchar(); // 키보드에서 문자 입력
        if (ch == EOF) // <Ctrl> + <Z>로 입력 종료
        {
            break;
        }
        putchar(ch);    // 화면에 문자 출력
    }
    
    return 0;
}
*/

// stdin과 stdout을 사용한 문자 입출력

/*
int main()
{
    int ch; // 입력할 문자를 저장할 변수

    while (1)
    {
        ch = fgetc(stdin); // 키보드에서 문자 입력
        if (ch == EOF) // <Ctrl> + <d>로 입력 종료
        {
            printf("ddddd");
            break;
        }
        fputc(ch, stdout);    // 화면에 문자 출력
    }
    
    return 0;
}
*/

// 텍스트 파일은 아스키 코드값에따라 저장
// 그 이외는 바이너리 파일 방식

// 파일의 형태와 개방 모드가 다른경우
/*
int main()
{
    FILE *fp;
    int ary[10] = {13, 10, 13, 13, 10, 26, 13, 10, 13, 10};
    int i, res;

    fp = fopen("a.txt", "wb");  // 바이너리 파일로 개방
    for (i = 0; i < 10; i++)
    {
        fputc(ary[i],fp);
    }
    fclose(fp);

    fp = fopen("a.txt", "rt");
    while (1)
    {
        res = fgetc(fp);
        if (res == EOF) break;
        printf("%4d",res);
    }
    fclose(fp);

    return 0;
}
*/

// a+모드로 파일의 내용을 확인하며 출력
/*
int main()
{
    FILE *fp;

    char str[20];

    fp = fopen("a.txt", "a+");  // 읽기 가능한 추가 모드로 개방
    if (fp == NULL)
    {
        printf("파일을 만들지 못했습니다.\n");
        return 0;
    }
    
    while (1)
    {
        printf("과일 이름 : ");
        scanf("%s",str);
        if (strcmp(str, "end") == 0)    // end입력시 종료
        {
            break;
        }
        else if(strcmp(str, "list") == 0)   // list를 입력하면 파일의 내용 확인
        {
            fseek(fp, 0, SEEK_SET);
            while (1)
            {
                fgets(str,sizeof(str), fp); // 과일 이름을 읽음
                if (feof(fp))   // 파일의 내용을 모두 읽으면 종료
                {
                    break;
                }
                printf("%s",str);
            }
        }
        else
        {
            fprintf(fp,"%s\n",str);
        }
    }
    fclose(fp);

    return 0;
}
*/

//  fgets, fputs (한 줄씩 입출력) , 여러 줄의 문장을 입력하여 한 줄로 출력
/*
int main()
{
    FILE *ifp, *ofp;
    char str[80];
    char *res;

    ifp = fopen("a.txt", "r");  // 입력 파일을 읽기 전용으로 개방
    if (ifp == NULL)
    {
        printf("입력  파일을 열지 못했습니다.\n");
        return 1;
    }
    
    ofp = fopen("b.txt", "w");  // 출력 파일을 쓰기 전용으로 개방
    if (ofp == NULL)
    {
        printf("출력 파일을 열지 못했습니다.\n");
        return 1;
    }
    
    while (1)
    {
        res = fgets(str,sizeof(str), ifp);
        if (res == NULL)    // 반환값이 널 포인터면 종료
        {
            break;
        }
        str[strlen(str) -1] = '\0'; // 개행 문자 제거
        fputs(str,ofp);
        fputs(" ", ofp);
    }
    
    fclose(ifp);
    fclose(ofp);

    return 0;
}
*/

//  fscanf, fprintf : 다양한 형태의 입출력
//  fscanf는 파일의 데이터를 모두읽으면 EOF반환

// 다양한 자료형을 형식에 맞게 입출력
/*
int main()
{
    FILE *ifp, *ofp;
    char name[20];
    int kor, eng, math;
    int total;
    double avg;
    int res;    // fscanf함수의 반환값 저장

    ifp = fopen("a.txt", "r");   // 입력 파일을 읽기 전용으로 개방
    if (ifp == NULL)
    {
        printf("입력 파일을 열지못했습니다.\n");
        return 1;
    }
    
    ofp =fopen("b.txt", "w");    // 출력 파일을 쓰기 전욜으로 개방
    if (ofp == NULL)
    {
        printf("출력 파일을 열지못했습니다.\n");
        return 1;
    }

    while (1)
    {
        res = fscanf(ifp, "%s%d%d%d",name,&kor,&eng,&math);
        if (res == EOF)    // 파일의 데이터를 모두 읽으면 EOF 반환
        {
            break;
        }
        total = kor + eng + math;
        avg = total / 3.0;
        fprintf(ofp, "%s%5d%7.1lf\n",name,total,avg);
    }
    
    fclose(ifp);
    fclose(ofp);

    return 0;
}
*/

// 스트림 파일의 버퍼 공유 문제와 fflush 함수

// 버퍼를 공유함으로 인해 발생하는 문제
/*
int main()
{
    FILE *fp;
    int age;
    char name[20];

    fp = fopen("a.txt", "r");
    
    fscanf(fp, "%d", &age);
    fgetc(fp);  // 스트림 버퍼에서 개행 문자를 읽어낸다
    fgets(name, sizeof(name),fp);

    printf("나이 : %d, 이름 : %s",age,name);
    fclose(fp);

    return 0;
}
*/

// fread, fwrite 함수
/*
int main()
{
    FILE *afp, *bfp;
    int num = 10;
    int res;

    afp = fopen("a.txt", "wt"); // 텍스트 모드로 출력 파일 개방
    fprintf(afp, "%d", num);

    bfp = fopen("b.txt", "wb"); // 바이너리 모드로 출력 파일 개방
    fwrite(&num, sizeof(num), 1,bfp);

    fclose(afp);
    fclose(bfp);

    bfp = fopen("b.txt", "rb"); //바이너리 모드로 입력 파일 개방
    fread(&res, sizeof(res), 1,bfp);
    printf("%d",res);

    fclose(bfp);

    return 0;
}
*/

/*
int main()
{
    FILE *fp;
    char str[20]  = "empty";
    int ch;

    fp = fopen("a.txt", "r");
    ch = fgetc(fp);
    while (fgetc(fp) != EOF);

    fgets(str, sizeof(str), fp);    // 이미 버퍼에 입력되어있는 데이터를 전부 써버려서 str에 초기화 되어있는 empty 입력
    printf("%s", str);
    fclose(fp);
    
    return 0;
}
*/

/*
int main()
{
    FILE *ifp, *ofp, *efp;
    char a[20], b[20]; // 비교할 대상

    ifp = fopen("b.txt", "r");
    if (ifp == NULL)
    {
        printf("파일이 열리지 않았습니다.\n");
        return 1;
    }

    ofp = fopen("a.txt", "r");
    if (ofp == NULL)
    {
        printf("파일이 열리지 않았습니다.\n");
        return 1;
    }

    efp = fopen("c.txt", "w");
    if (efp == NULL)
    {
        printf("파일이 열리지 않았습니다.\n");
        return 1;
    }

    while (1)
    {
        if (feof(ifp)) // ifp의 파일을 모두읽으면 종료
        {
            break;
        }

        fgets(a, sizeof(a), ifp); // ifp 파일 읽어들임

        while (1)
        {
            fgets(b, sizeof(b), ofp); // ofp 파일 읽어들임
            if (strcmp(a, b) == 0)    // 비교후 같으면 a의 다음 단어로
            {
                break;
            }

            if (feof(ofp))
            {
                fputs(a, efp); // 없는 단어 검출 efp에 저장
                break;
            }
        }
        rewind(ofp); // ofp의 커서 위치를 맨위로 다시 설정
    }
    fclose(ifp);
    fclose(ofp);
    fclose(efp);

    return 0;
}
*/
