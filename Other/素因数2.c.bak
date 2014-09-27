#include <stdio.h>

int main(void)
{
    int num, i;

    scanf("%d", &num);

    for (i = 2; num > 1; ) {
        if (num % i == 0)
            printf("%d ", (num /= i, i));
        else
            ++i;
    }
    putchar('\n');

    return 0;
}
