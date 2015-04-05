#include <stdio.h>

int main(void)
{
    int a, b, c;
    int *max, *min, *middle;

    printf("Please input 3 numbers(use space to divide): ");
    scanf("%d %d %d", &a, &b, &c);

    middle = &c;

    if (a > b)
    {
        max = &a;
        min = &b;
    } else {
        min = &a;
        max = &b;
    }

    if (*min > c)
    {
        middle = min;
        min = &c;
    } else if (*max < c) {
        middle = max;
        max = &c;
    }

    printf("%d %d %d", *min, *middle, *max);

    return 0;
}
