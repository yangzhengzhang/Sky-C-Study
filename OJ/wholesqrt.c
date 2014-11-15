#include <stdio.h>
#include <math.h>

int main(void)
{
    int counter = 0;
    long long num, sqr;
    int n, i;
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%lld", &num);

        sqr = sqrt(num);
        if (sqr * sqr == num)
            counter++;
    }
    i = 1.0;
    printf("%lld", sqr);

    return 0;
}
