#include <stdio.h>

void chline(char, int, int);

int main(void)
{
    int i, j;
    char ch;
    printf("Please input a character: ");
    scanf("%c", &ch);
    printf("Please input two numbers(use space to divide): ");
    scanf("%d %d", &i, &j);

    chline(ch, i, j);

    return 0;
}

void chline(char ch, int i, int j)
{
    int counter;
    for(counter = 1; counter < i; counter++)
        printf(" ");
    for(; counter <= j; counter++)
        printf("%c", ch);
    printf("\n");
}
