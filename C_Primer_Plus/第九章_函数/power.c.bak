#include <stdio.h>

double power(double n, double p);

int main(void)
{
    double n, p;

    printf("Please input the number you need to power: ");
    scanf("%lf", &n);
    printf("Please input the number of power:");
    scanf("%lf", &p);

    printf("The answer is %f", power(n, p));
    return 0;
}

double power(double n, double p)
{
    int i;
    double pow = 1.0;

    if (n == 0)
        pow = 0;
    if (p == 0)
        pow = 1;
    else if (p < 0)
        for (i = 1; i <= -p; i++)
            pow /= n;
    else if(p > 0)
        for (i = 1; i <= p; i++)
            pow *= n;
    return pow;
}
