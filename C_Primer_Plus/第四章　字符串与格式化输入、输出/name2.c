#include <stdio.h>
#include <string.h>

int main(void)
{
    char fname[40];
    int length;

    printf("Please input your Name like: John:\n");
    scanf("%s", fname);

    length = strlen(fname);

    printf("Your name is \"%s\"\n", fname);
    printf("Your name is \"%20s\"\n", fname);
    printf("Your name is \"%-20s\"\n", fname);
    printf("Your name is \"%*s\"\n", length + 3, fname);

    return 0;
}
