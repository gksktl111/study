#include <stdio.h>

int main()
{
    int a, b;
    char cal;

    printf("두 정수를 입력하세요 : ");
    scanf("%d%c%d", &a, &cal, &b);

    if (cal == '+')
    {
        printf("%d %c %d = %d\n", a, cal, b, a + b);
    }
    else if (cal == '-')
    {
        printf("%d %c %d = %d\n", a, cal, b, a - b);
    }
    else if (cal == '*')
    {
        printf("%d %c %d = %d\n", a, cal, b, a * b);
    }
    else if (cal == '/')
    {
        printf("%d %c %d = %d\n", a, cal, b, a / b);
    }

    return 0;
}