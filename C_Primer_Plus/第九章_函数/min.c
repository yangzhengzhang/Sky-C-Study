#include <stdio.h>

double min(double x, double y);

int main(void)
{
    double x, y;
    printf("Please input two numbers: ");
    scanf("%lf%lf", &x, &y);
    printf("The min is %.3f", min(x, y));
    return 0;
}

double min(double x, double y)
{
    return x < y ? x : y;
}
