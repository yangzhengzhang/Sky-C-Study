#include <stdio.h>

void to_base_n(int, int);

int main(void)
{
    int num, scale;

    printf("Please input the number: ");
    scanf("%d", &num);
    printf("Please input a number to comfirm scale: ");
    scanf("%d", &scale);

    printf("The num is ");
    to_base_n(num, scale);
    return 0;
}

void to_base_n(int num, int scale)
{
    int r;

    r = num % scale;
    if (num >= scale)
        to_base_n(num / scale, scale);
    putchar('0' + r);
}
