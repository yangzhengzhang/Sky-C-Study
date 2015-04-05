#include <stdio.h>
int power(int num, int pow);

int main(void)
{
    int lower, upper, i;

    printf("Print the lower and upper(space to divide): ");
    scanf("%d %d", &lower, &upper);
    for (i = lower; i <= upper; i++) {
        printf("%d   %d   %d\n", i, power(i, 2), power(i, 3));
    }
    return 0;
}

int power(int num, int pow)
{
    int n, result;
    result = num;

    for (n = 1; n < pow; n++)
        result *= num;
    return result;
}
