#include <stdio.h>

int main(void)
{
    char a[3];
    int i;

    printf("���������ַ�: ");

    for (i = 0; i < 3; i++)
        scanf("%c", &a[i]);

    for (i = 0; i < 3; i++)
    {
        a[i] -= 32;
        printf("�ַ�Ϊ%c\n", a[i]);
    }

    return 0;
}
