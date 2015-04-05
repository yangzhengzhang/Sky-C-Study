#include <stdio.h>

int space = 0;

int c;

main(void)
{
    while ((c = getchar()) != EOF) {
        if (c == ' ' && !space) {
            space = 1;
            putchar(c);
        } else if (c != ' ') {
            space = 0;
            putchar(c);
        }
    }

    return 0;
}
