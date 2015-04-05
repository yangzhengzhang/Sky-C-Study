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
    if (n == 0)
        return 0;
    if (p == 0)
        return 1;
    else if (p > 0)
        return n * power(n, p - 1);
    else if (p < 0)
        return power(n, p + 1) / n ;
}
