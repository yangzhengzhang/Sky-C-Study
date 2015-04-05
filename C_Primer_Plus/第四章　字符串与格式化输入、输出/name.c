#include <stdio.h>

int main(void)
{
    char fname[40];
    char lname[40];

    printf("Please input your Name like: John Hasen:\n");
    scanf("%s %s", fname, lname);
    printf("Your name is %s, %s", fname, lname);
    return 0;
}
