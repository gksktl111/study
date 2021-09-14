#include <stdio.h>

extern int count; //main.c 파일의 전역 변수 count 공유
int total = 0;

int input_data()
{
    int pos; // 양수 저장

    while (1)
    {
        printf("양수 입력 : ");
        scanf("%d", &pos);
        if (pos < 0) break;      // 음수면 입력 종료
        count++;        // 개수 증가
        total += pos; // 입력값을 total에 누적
    }

    return total; // 전역 변수 total의 값 반환
}