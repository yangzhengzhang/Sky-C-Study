#include <stdio.h>
#define WIDTH 6

int max(int [], int);

int main(void)
{
    int array[] = {4, 3, 6, 2, 8, 6};
    printf("The max is : %d\n", max(array, WIDTH));

    return 0;
}

int max(int array[], int num)
{
    int i, max;

    max = *array;

    for (i = 0; i < num; i++)
        if (*(array + i) > max)
            max = *(array + i);

    return max;
}
