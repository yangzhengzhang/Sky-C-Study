#include <stdio.h>

#define DIF ('a' - 'A')

int main(void)
{
    char input;

    while ((input = getchar()) != EOF) {
        if (input >= 'A' && input <= 'Z') {
            printf("%c", input + DIF);
        } else {
            putchar(input);
        }
    }
    return 0;
}
