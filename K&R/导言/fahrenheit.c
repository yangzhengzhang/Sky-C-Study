#include <stdio.h>

main(void)
{
    float fahr, celsius;
    int step, upper, lower;

    lower = 0;
    upper = 200;
    step = 20;

    celsius = upper;

    printf("Fahr\tCelsius\n");

    while(celsius >= lower) {
        fahr = celsius * 9.0 / 5.0 + 32.0;
        printf("%3.0f\t%6.2f\n", celsius, fahr);
        celsius -= step;
    }
}
