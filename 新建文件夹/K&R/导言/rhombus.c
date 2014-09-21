#include <stdio.h>

#define LINE 7

main(void)
{
    int now, space, block;

    for (now = 1; now <= LINE;now++) {
        if (now <=(LINE/2 + 1)) {
            for (space = ((LINE/2 + 1) - now); space > 0; space--) {
                printf(" ");
            }

            for (block = 1; block <= now * 2 - 1; block++) {
                printf("*");
            }
        }

        if (now > (LINE/2 + 1)) {
            for (space = (now - (LINE/2 + 1)); space > 0; space--) {
                printf(" ");
            }

            for (block = (LINE - now) * 2 + 1; block > 0; block--) {
                printf("*");
            }
        }
        printf("\n");
    }

    return 0;
}
