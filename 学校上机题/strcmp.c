#include <stdio.h>

int len(char s[])
{
    int i = 0;
    while (s[i] != '\0')
        ++i;
    return i;
}

int cmp(char array1[], char array2[])
{
    int i, len1, diff = 0;
    len1 = len(array1);
    for (i = 0; i <= len1; i++)
        if ( (diff = (array1[i] - array2[i])) != 0)
            break;
    return diff;
}

int main(void)
{
    char array1[80], array2[80];
    int diff;

    printf("Put a string: ");
    gets(array1);
    printf("Put another string: ");
    gets(array2);

    diff = cmp(array1, array2);

    printf("%d", diff);
    return 0;
}
