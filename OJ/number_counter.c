#include <stdio.h>

int main(void)
{
    int i = 0, lock = 1;
    char c;

    while ((c = getchar()) != '\n')
    {
        if (lock == 1 && c == '0')
        {
            continue;
        }
        else
        {
            lock = 0;
            i++;
        }
    }

    printf("%d", i);
    return 0;
}
