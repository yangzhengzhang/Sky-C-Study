#include <stdio.h>

int main(void)
{
    char input;
    int i;
    i = 9;

    printf("Input a string: ");
    while ((input = getchar()) != EOF) {
        printf("%*c\n", i, input);
        i += 9;
    }
    return 0;
}
