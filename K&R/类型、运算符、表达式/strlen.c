#include <stdio.h>

#define SKY "skyao"

enum boolean { NO, YES };

main(void) {
    printf("%d", YES);
}

int strlen(char s[])
{
    int i;

    i = 0;
    while (s[i] != '\0')
        ++i;
    return i;
}
