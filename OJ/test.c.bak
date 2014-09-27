#include <stdio.h>

int divide(int big, int small)
{
    int r;

    r = big % small;

    while (r != 0)
    {
        big = small;
        small = r;
        r = big % small;
    }

     return small;
}

int main(void)
{
    printf("%d", divide(100, 66));

    return 0;
}
