#include <stdio.h>

int main(void)
{
    char word;

    printf("Print the word:\n");
    while ((word = getchar()) != EOF) {
        printf("    ");
        putchar(word);
        printf("\n");
    }
    return 0;
}
