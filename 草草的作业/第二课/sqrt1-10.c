#include <stdio.h>
#include <math.h>

int main(void)
{
    int num;

    printf("      1--10平方根表\n==========================\n");
    for (num = 1; num <= 10; num++) {
        printf("%6d %9.3f\n==========================\n", num, sqrt(num));
    }
    return 0;
}
