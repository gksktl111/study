#include <stdio.h>

#define SIZE 10000

int stack[SIZE];
int top = -1;

int isFull()
{
    if (top >= SIZE - 1)
    {
        printf("Error : stack is Full!\n");
        return 1;
    }
    return 0;
}

int isEmpty()
{
    if (top == -1)
    {
        printf("-1");
        return 1;
    }
    return 0;
}

void push(data)
{
    if (!isFull())
    {
        top++;
        stack[top] = data;
    }
}

int pop(data)
{
    if (!isEmpty())
    {
        int tmp = stack[top];
        top--;
        return tmp;
    }
}

int main()
{
    int n;
    char com;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%s", &com);
        
        if (com == "push")
        {
            scanf("%d");
            push(com);
        }
        else if (com == "top")
        {
            if (!isEmpty())
            {
                printf("%d\n", stack[top]);
            }
        }
        else if (com == "size")
        {
            printf("%d\n", top + 1);
        }
        else if (com == "empty")
        {
            printf("%d\n", isEmpty());
        }
        else if (com == "pop")
        {
            if (!isEmpty())
            {
                printf("%d\n", pop());
            }
        }
    }

    return 0;
}