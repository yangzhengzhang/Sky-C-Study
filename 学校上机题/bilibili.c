#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char c;
    int i;

    while ((c = getchar()) != '\n') {
        if (isalpha(c)) {
            i = tolower(c) - 'a' + 1;       // 第几个英文单词
            if (islower(c))
                putchar('a' + 26 - i);
            else
                putchar('A' + 26 - i);
        } else
            putchar(c);
    }

    return 0;
}
