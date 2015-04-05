#include <stdio.h>

int main(void)
{
    int n, x, y, extra;
    scanf("%d", &n);
    scanf("%d", &x);
    scanf("%d", &y);

    extra = n - x;
    if (extra > 0 && (y - extra * 5) <= 0)
        printf("No");
    else
        printf("Yes");

    return 0;
}
