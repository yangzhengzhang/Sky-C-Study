#include <stdio.h>

int main(void)
{
    char a[3];
    int i;

    printf("输入三个字符: ");

    for (i = 0; i < 3; i++)
        scanf("%c", &a[i]);

    for (i = 0; i < 3; i++)
    {
        a[i] -= 32;
        printf("字符为%c\n", a[i]);
    }

    return 0;
}
