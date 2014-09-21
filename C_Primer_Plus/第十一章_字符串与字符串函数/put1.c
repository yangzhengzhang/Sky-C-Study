#include <stdio.h>

void put1(const char * string)
{
    int count = 0;
    while (* string)
    {
        putchar(*string++);
        count++;
    }
    putchar('\n');
    return (count);
}
