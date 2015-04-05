#include <stdio.h>

int pow10(int num, int times)
{
    int i;
    for (i = 1; i <= times; i++)
        num *= 10;
    return num;
}

int digit(int num)
{
    int i = 1;
    while (num / 10) {
        ++i;
        num = num / 10;
    }
    return i;
}

int reverse(int bits, int num, int result)
{
    result += pow10(num % 10, bits - 1);

    if (num / 10)
        reverse(bits - 1, num / 10, result);
    else
        return result;
}

int main(void)
{
    int num, bits;
    scanf("%d", &num);

    bits = digit(num);

    printf("%d", reverse(bits, num, 0));
    return 0;
}
