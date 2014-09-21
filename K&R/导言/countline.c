#include <stdio.h>

main(void)
{
    char c, nl;

    while ((c = getchar()) != EOF) {
        if (c == '\t')
            printf("\\t");
        else if (c == '\\')
            printf("\\\\");
        else if (c == '\b')
            printf("\\b");
        else
            putchar(c);
    }

    return 0;
}
