#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char c, str[100];
    int i, counter;

    counter = 0;

    while ((c = getchar()) != '\n') {
        str[counter] = c;
        counter++;

        if (isalpha(c)) {
            i = tolower(c) - 'a' + 1;       // 第几个英文单词
            if (islower(c))
                putchar('a' + 26 - i);
            else
                putchar('A' + 26 - i);
        } else
            putchar(c);
    }

    str[counter] = '\0';

    printf("\n");

    printf("%s", str);

    return 0;
}
