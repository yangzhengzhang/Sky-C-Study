#include <stdio.h>

int main(void)
{
    int a, b, c;
    int *max, *min, *middle;

    printf("Please input 3 numbers(use space to divide): ");
    scanf("%d %d %d", &a, &b, &c);

    if (a > b && a > c)
    {
        max = &a;
        if (b > c) {
            min = &c;
            middle = &b;
        } else {
            min = &b;
            middle = &c;
        }
    } else if (b > a && b > c) {
        max = &b;
        if (a > c) {
            min = &c;
            middle = &a;
        } else {
            min = &a;
            middle = &c;
        }
    } else {
        max = &c;
        if (b > a)
        {
            min = &a;
            middle = &b;
        } else {
            min = &b;
            middle = &a;
        }
    }

    printf("%d %d %d", *min, *middle, *max);

    return 0;
}
