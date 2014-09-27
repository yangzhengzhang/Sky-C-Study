#include <stdio.h>
#include <string.h>
int main(void)
{
    int counter = 0, words = 0;
    char c;

    while ((c = getchar()) != '\n')
    {
        if (!isalpha(c))
        {
            words = 0;
        } else if (words == 0) {
            counter++;
            words = 1;
        }

    }

    printf("%d", counter);
    return 0;
}
