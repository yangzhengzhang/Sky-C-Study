#include <stdio.h>

int main(void)
{
    int a, b;

    a = 1;
    b = ++a, a * 2;

    printf("%d", b);

    return 0;
}
