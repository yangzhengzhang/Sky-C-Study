#include <stdio.h>

int main(void)
{
    int a = 15, b = 18, c = 19;
    int x;
    x=a||b++||c++;
    printf("%d", x);
    return 0;
}
