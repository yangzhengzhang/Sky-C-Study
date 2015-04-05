#include <stdio.h>

int main(void)
{
    char line[255];
    int i, length;

    printf("Print a sentence: ");
    for (i = 0; i < 255; i++) {
        scanf("%c", &line[i]);
        if (line[i] == '\n')
            break;
    }
    for (i -= 1; i >= 0; i--)
        printf("%c", line[i]);

    return 0;
}
