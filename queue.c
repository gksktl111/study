#include <stdio.h>

#define MAXSIZE 10 // 큐의 크기

int queue[MAXSIZE];
int front, rear;

void init_queue(void)
{
    front = rear = 0;
}

void clear_queue(void)
{
    front = rear;
}

int put(int val)
{
    if ((rear + 1) % MAXSIZE == front)
    { // 큐가 꽉 찼는지 확인
        printf(" Queue Overflow.");
        return -1;
    }

    queue[rear] = val;       // rear가 큐의 끝 다음의 빈공간이므로 바로 저장
    rear = ++rear % MAXSIZE; // rear를 다음 빈공간으로 변경

    return val;
}

int get(void)
{
    int i;

    if (front == rear) // 큐가 비어 있는지 확인
    {
        printf(" Queue Underflow.");
        return (-1);
    }

    i = queue[front];          // front의 값을 가져옴
    front = ++front % MAXSIZE; // front를 다음 데이터 요소로

    return i;
}

void print_queue(void)
{
    printf(" Queue From Front------> To Rear ");

    for (int i = front; i != rear; i = ++i % MAXSIZE)
    {
        printf("%-6d", queue[i]);
    }
}

void main(void)
{
    int i;
    init_queue();
    printf(" Put 5, 4, 7, 8, 2, 1");
    put(5);
    put(4);
    put(7);
    put(8);
    put(2);
    put(1);
    print_queue();
    printf(" Get");
    i = get();
    print_queue();
    printf(" get value is %d", i);
    printf(" Put 3, 2, 5, 7");
    put(3);
    put(2);
    put(5);
    put(7);
    print_queue();
    printf(" Now queue is full, put 3");
    put(3);
    print_queue();
    printf(" Initialize Queue");
    clear_queue();
    print_queue();
    printf(" Now queue is empty, get");
    i = get();
    print_queue();
    printf(" get value is %d", i);
}
