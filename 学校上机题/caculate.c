#include <stdio.h>

int main(void)
{
    double x, y;
    int a, b;

    x=2.5;
    y=4.7;
    a=7;

    printf("%f", x+a%3*(int)(x+y)%2/4);
    return 0;
}
