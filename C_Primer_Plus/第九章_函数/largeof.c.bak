#include <stdio.h>

void large_of(double *, double *);

int main(void)
{
    double a, b;

    printf("Please input two numbers: ");
    scanf("%lf %lf", &a, &b);

    large_of(&a , &b);

    printf("The larger one is a = %f, b = %f", a, b);
    return 0;
}

void large_of(double *x, double *y)
{
    *y = *x = (*x > *y) ? *x : *y;
}
