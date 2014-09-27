#include <stdio.h>
#include <math.h>

double result(double (*p)(double))
{
    double i, s = 0.0;

    for (i = 0.0; i <= 1.0; i += (1.0/10000))
        s += (*p)(i) / 10000;
    return s;
}


int main(void)
{
    int n;
    double (*p)(double), sum;
    printf("求sin积分请按1,cos请按2,exp请按3");
    scanf("%d", &n);

    switch(n)
    {
        case 1: p = sin;
                break;
        case 2: p = cos;
                break;
        case 3: p = exp;
                break;
    }

    sum = result(p);

    printf("%f", sum);

    return 0;
}
