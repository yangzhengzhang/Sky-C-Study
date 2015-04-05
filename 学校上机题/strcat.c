#include <stdio.h>

/* 统计字符串字符数 */
int len(char s[])
{
    int i = 0;
    while (s[i] != '\0')
        ++i;
    return i;
}

/* 连接字符串 */
void cat(char array1[], char array2[])
{
    int i, j;

    i = len(array1);

    for (j = 0; array2[j] != '\0'; j++, i++)
        array1[i] = array2[j];

    array1[i] = '\0';
}

int main(void)
{
    char array1[40], array2[20];

    printf("Put a string: ");
    gets(array1);
    printf("Put another string: ");
    gets(array2);

    cat(array1, array2);

    printf("%s", array1);
    return 0;
}
