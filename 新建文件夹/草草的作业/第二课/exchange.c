#include <stdio.h>

int main(void)
{
    int a, b;

    printf("print two num(space to divide): ");
    scanf("%d %d", &a, &b);
    a = a + b;
    b = a - b;
    a = a - b;
    printf("The result: %d %d", a, b);
    return 0;
}
