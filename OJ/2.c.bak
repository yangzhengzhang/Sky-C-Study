#include <stdio.h>

int main(void)
{
    int x, i, counter = 0, p, temp;

    scanf("%d", &x);
    scanf("%d", &p);

    for (i = 1; i <= x; i++)
    {
        temp = i;

        while (temp > 0)
        {
            if (temp % 10 == p)
                counter++;
            temp /= 10;
        }
    }

    printf("%d", counter);

    return 0;
}
