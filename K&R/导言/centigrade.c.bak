#include <stdio.h>

/*  when fahr= 0, 20, 30, ..., 300,
    print Fahrenheit & centigrade comparison table  */
main(void)
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;  /*  the lower limit of thermometer  */
    upper = 300;    /*  the higher limit of thermometer */
    step = 20;  /*  step    */

    fahr = lower;
    while (fahr <= upper) {
        celsius = 5.0 * (fahr - 32.0) / 9.0;
        printf("%3.0f\t%6.2f\n", fahr, celsius);
        fahr = fahr + step;
    }
}
