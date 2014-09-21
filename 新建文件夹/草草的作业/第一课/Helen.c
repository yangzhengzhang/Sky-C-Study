#include <stdio.h>
#include <math.h>

main(void)
{
    float a, b, c, S;

    printf("Print the three side length:\n");
    scanf("%f%f%f", &a, &b, &c);

    S = sqrt((a + b + c) * (a + b - c) * (a + c - b) * (b + c - a)) / 4;

    printf("The area is %.2f", S);

    return 0;
}
