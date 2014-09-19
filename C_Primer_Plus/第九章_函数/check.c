#include <stdio.h>
#include <ctype.h>

int check(char);

int main(void)
{
    char ch;
    int situation;

    printf("Please input a character: ");
    scanf("%c", &ch);

    situation = check(ch);
    if (situation != -1)
        printf("The situation is %d", situation);
    else
        printf("Please input a letter.");
    return 0;
}

int check(char ch)
{
    if (isalpha(ch))
        return tolower(ch) - 'a' + 1;
    else
        return -1;
}
