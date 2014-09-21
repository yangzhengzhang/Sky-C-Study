#include <stdio.h>

int main(void)
{
    int a, b, temp;
    a = 8;
    b = 10;
    a = a + b;
    b = a - b;
    a = a - b;
    printf("%d %d", a, b);

    return 0;
}
