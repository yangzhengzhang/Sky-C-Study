#include <stdio.h>

int main(void)
{
    float num;

    printf("Please input a number: ");
    scanf("%f", &num);
    printf("The input is %.1f or %.1e\n", num, num);
    printf("The input is %+.3f or %.3E", num, num);
    return 0;

}
