#include <stdio.h>

#define WIDTH 6

int max(int [], int);

int main(void)
{
    int array[] = {4, 3, 6, 2, 8, 6};
    printf("The max is %d\n", max(array,WIDTH));

    return 0;
}

int max(int a[], int n)
{
    int i, max;
    for (i = 1, max = a[0]; i < n; i++)
        if (max < a[i])
            max = a[i];
    return max;
}
