#include <stdio.h>
// 5개의 문자를 저장하기 위해 스택 자료구조 사용

#define SIZE 5

char stack[SIZE]; // 스택을 넣기 위한 배열
int top = -1;     //맨 위의 원소를 나타낼 top변수, 기본값은 -1

int isFull() // 스택이 포화 상태인지 검사하는 함수
{
    if (top >= SIZE - 1) // top이 최대 크기와 같거나 클 경우
    {
        printf("Error : Stack is Full. \n");
        return 1;
    }
    print("dddd");
    return 0;
}

int isEmpty() // 스택이 공백 상태인지 검사하는 함수
{
    if (top == -1) // 공백 상태인 경우
    {
        printf("Error : Stack is Empty. \n");
        return 1;
    }
    return 0;
}

void push(data) // 스택에 원소를 삽입하는 함수
{
    if (!isFull()) // 스택이 포화상태가 아닐 경우
    {
        top++;             // top을 1증가
        stack[top] = data; // 해당 공간에 data 삽입
    }
}

char pop() //  스택에 원소를 제거하는 함수, 여기서 반환형은 char 이지만 해당 stack 배열 자료형에 따라 변경하면됨
{
    if (!isEmpty()) // 배열이 비어있지 않은 경우
    {
        char tmp = stack[top]; // top 원소를 임시 변수 tmp에 저장
        top--;                 // top 변수 1감소
        return tmp;            // tmp 반환
    }
}

char peek() // 스택의 맨 위의 원소를 반환하는 함수
{
    if (!isEmpty()) // 스택이 비어 있지 않은 경우
    {
        return stack[top]; // 맨위 스택 반환
    }
}

void print_Stack() //  스택의 모든 원소를 출력할 함수
{
    if (!isEmpty()) // 스택이 비어 있지 않으면
    {
        for (int i = 0; i <= top; i++) // stack의 원소를 출력하기 위한 for 문
        {
            printf("%c ", stack[i]);
        }
        printf("\n");
    }
}

int main()
{
    print_Stack(); // 스택 공백상태 에러 발생
    push('A');
    push('B');
    push('C');
    print_Stack();
    pop();
    push('D');
    push('E');
    push('F');
    push('G'); // 스택 포화 상태 에러 발생
    print_Stack();
    pop();
    pop();
    print_Stack();
}

https:///rpatm.tistory.com/40