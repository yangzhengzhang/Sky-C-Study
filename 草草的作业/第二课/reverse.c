#include <stdio.h>

#define LENGTH 3

int main(void)
{
    int num, a, b, c;

    printf("Print a three-place num: ");
    scanf("%d", &num);
    if (num < 100 || num > 1000) {
        printf("Your number isn't three places.\n");
    } else {
        a = num / 100;
        b = (num - a * 100) / 10;
        c = num - (a * 100 + b * 10);
        printf("The num is %d%d%d", c, b,a);
    }

    return 0;
}
