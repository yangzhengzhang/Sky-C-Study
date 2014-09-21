#include <stdio.h>

int main(void)
{
    int a, b, c;
    int *max, *min, *middle;

    printf("Please input 3 numbers(use space to divide): ");
    scanf("%d %d %d", &a, &b, &c);

    middle = &c;

    max = a > b ? &a : &b;
    min = a > b ? &b : &a;
    printf("%d %d %d\n", *min, *middle, *max);

    middle = *min > c ? min : &c;
    min = *min > c ? &c : min;
    printf("%d %d %d\n", *min, *middle, *max);

    middle = *max > c ? &c : max;
    max = *max > c ? max : &c;

    printf("%d %d %d\n", *min, *middle, *max);

    return 0;
}
