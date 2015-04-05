#include <stdio.h>

void copy(char str1[], char str2[], int m)
{
    int i;

    for (i = 0; i < m - 1; i++)
        str1++;

    while (*str1)
        *(str2++) = *(str1++);

    *str2 = '\0';
}

int main(void)
{
    int m;
    char str1[60], str2[60];

    scanf("%d", &m);
    getchar();
    gets(str1);
    copy(str1, str2, m);
    puts(str2);

    return 0;
}
