#include <stdio.h>

extern int count;   // main.c의 전역변수 count 공유
extern int total;   // input.c의 전역 변수 total 공유

int average()
{
    return total / (double)count;   // 입력값의  평균 반환
}