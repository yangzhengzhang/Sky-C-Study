#include <stdio.h>

int main(void)
{
    int i, j, m, n;

    i = 2;
    j = 5;
    m = i++;
    n = ++j;
    printf("%d %d %d %d\n", i, j, m, n);
    return 0;
}
