#include <stdio.h>

int main(void)
{
    char c;

    while ((c = getchar()) != EOF)
    {
        if (c > 'A' && c <= 'Z')
            putchar(c - 1);
        else if (c == 'A')
            putchar('Z');
        else
            putchar(c);
    }

    return 0;
}
