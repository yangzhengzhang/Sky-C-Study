#include <stdio.h>

int len(char s[])
{
    int i = 0;
    while (s[i] != '\0')
        ++i;
    return i;
}

void copy(char array1[], char array2[])
{
    int i, len1;
    len1 = len(array2);

    for (i = 0; i <= len1; i++)
        array1[i] = array2[i];
}

int main(void)
{
    char array1[40], array2[40];

    printf("Put a string: ");
    gets(array2);
    copy(array1, array2);

    printf("%s", array1);
    return 0;
}
