#include <stdio.h>

#define NUM 10

int main(void)
{
    int i;
    float sales[NUM];
    float sum = 0, max = 0, min = 0;

    printf("Please input %d sales: \n", NUM);
    for (i = 0; i < NUM; i++) {
        scanf("%f", &sales[i]);
        sum += sales[i];
        if (i == 0) {   /* min max 初始化 */
            max = sales[i];
            min = sales[i];
        }
        if (sales[i] > max)
            max = sales[i];
        if (sales[i] < min)
            min = sales[i];
    }

    printf("ave = %f  range = %g\n", sum / NUM, max - min);

    return 0;
}
