#include <stdio.h>

#define WIDTH 6

float dif(double [], int num);

int main(void)
{
    double array[] = {4.3, 5.3, 2.6, 9.2, 2.8, 3.6};
    printf("The dif between max and min is : %g", dif(array, WIDTH));

    return 0;
}

float dif(double array[], int num)
{
    int i;
    float max, min;

    for (i = 0, max = *array, min = *array; i < num; i++) {
        if (*(array + i) > max)
            max = *(array + i);
        if (*(array + i) < min)
            min = *(array + i);
    }

    printf("%g\n", min);
    printf("%g\n", max);

    return max - min;
}
