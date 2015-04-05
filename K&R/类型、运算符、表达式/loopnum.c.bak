#include <math.h>
#include <stdio.h>

main(void)
{
    double i, j,max;
    max = 0;
    for (i = 1000; i <= 99999999;i++)
    {
        j = floor(i/1000);

        if ((int)sqrt(j) == sqrt(j)) {
            if (i > max) {
                max = i;
            }
        }
    }
    printf("%lld\n", sqrt(max));
}
