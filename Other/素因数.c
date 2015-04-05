#include <stdio.h>

int Prime(int num);

int main(void)
{
    int num, array[50];

    printf("请输入一个数： ");
    scanf("%d", &num);
    printf("%d = ", num);
    Prime(num);

    return 0;
}

int Prime(int num)
{
    int i;

    for (i = 2; i <= num; i++)
        if (num % i == 0) {
            printf("% d", i);
            return (Prime(num / i));
        }
}
