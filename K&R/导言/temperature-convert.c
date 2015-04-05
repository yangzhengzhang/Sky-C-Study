#include <stdio.h>

float convert(float fahrenheit);

main(void)
{
    printf("The centigrade is %1.1f .", convert(20.0));

    return 0;
}

float convert(float fahrenheit)
{
    float centigrade;

    centigrade = (5.0 / 9.0) * (fahrenheit -32.0);

    return centigrade;
}
