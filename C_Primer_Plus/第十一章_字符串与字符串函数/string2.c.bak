#include <stdio.h>
#include <ctype.h>

void input(char *p, int n);

int main(void)
{
    char a[81];
    int n;

    puts("input the char number of your string: ");
    scanf("%d", &n);
    getchar();
    puts("input your string: ");
    input(a, n);
    puts(a);

    return 0;
}

void input(char *p, int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        * (p + i) = getchar();
        if ( isspace(*(p + i)) )
            break;
    }
    *(p + i) = '\0';
}
