#include <stdio.h>

void chline(char, int, int);

int main(void)
{
    int i, j;
    char ch;

    printf("Please input a char: ");
    scanf("%c", &ch);
    printf("Please input two number(use space to divide): ");
    scanf("%d %d", &i, &j);

    chline(ch, i, j);
    return 0;
}

void chline(char ch, int i, int j)
{
    int k, m;
    for (k = 1; k <= j; k++) {
        for (m = 1; m <= i; m++)
            printf("%c", ch);
        putchar('\n');
    }
}
