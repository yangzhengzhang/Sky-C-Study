#include <stdio.h>
#include <math.h>

int main(void)
{
    int degree;
    double radian;

    for (degree = 10; degree <= 20; degree++) {
        radian = M_PI * degree / 180;
        printf("%d   %f\n", degree, sin(radian));
    }
    return 0;
}
