#include <stdio.h>

double harmmean(double, double);

int main(void)
{
    double a, b;

    printf("Please input two numbers(use space to divide): ");
    scanf("%lf%lf", &a, &b);
    printf("1/(1/a+1/b)/2= %f\n", harmmean(a, b));
    return 0;
}

double harmmean(double a, double b)
{
    return 1/(1/a+1/b)/2;
}
