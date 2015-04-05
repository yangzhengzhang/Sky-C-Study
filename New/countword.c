#include <stdio.h>

#define IN 1
#define OUT 0

int main(void)
{
    int c, nw, state;

    state = OUT;
    nw = 0;
    while ((c = getchar()) != EOF) {
        if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z' || c >= '0' && c <= '9')
        {
            state = IN;
        }
        else if (state == IN)
        {
            nw++;
            state = OUT;
        }
    }

    printf("%d\n", nw);

    return 0;
}
