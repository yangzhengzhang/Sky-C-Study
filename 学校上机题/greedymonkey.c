#include <stdio.h>

int main(void)
{
    int i, peaches;

    for (i = 9, peaches = 1; i > 0; i--)
        peaches = (peaches + 1) * 2;

    printf("%d", peaches);

    return 0;
}
