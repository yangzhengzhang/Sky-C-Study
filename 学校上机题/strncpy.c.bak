#include <stdio.h>
#include <ctype.h>
void longest(char string[])
{
    int counter = 0, max = 0, position = 0, maxpostion = 0;
    int i = 0;
    char *p = string;
    do
    {
        if(isalpha(*p))
        {
            counter++;
        } else {
            if (counter > max)
            {
                max = counter;
                maxpostion = position;
            }
            counter = 0;
            position = i + 1;
        }
        i++;
    } while(*p++);

    p = string + maxpostion;
    while (*p)
    {
        putchar(*p++);
        if (!isalpha(*p))
            break;
    }
}

int main(void)
{
    char string[40];
    gets(string);
    longest(string);
    return 0;
}
