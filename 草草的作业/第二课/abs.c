#include <stdio.h>

int main(void)
{
    int num;

    printf("print a num: ");
    scanf("%d", &num);
    if (num < 0)
        num = -num;
    printf("abs:%d", num);
    return 0;
}
