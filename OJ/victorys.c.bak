#include <stdio.h>

int divide(int big, int small)
{
    int r;

    r = big % small;

    while (r != 0)
    {
        big = small;
        small = r;
        r = big % small;
    }

     return small;
}

int main(void)
{
    unsigned int n[100], pd[100], pg[100], t, possible[100], big = 100, temp;
    int i;

    scanf("%u", &t);
    for (i = 0; i < t; i++)
    {
        scanf("%u", &n[i]);
        scanf("%u", &pd[i]);
        scanf("%u", &pg[i]);

        if (100 / divide(100, pd[i]) > n[i])
            possible[i] = 0;

        if( pg[i] > 100 || pg[i] == 100 && pd[i] != 100 || pg[i] == 0&& pd[i] != 0)
            possible[i] = 0;
        else
            possible[i] = 1;
    }

    for (i = 0; i < t; i++)
    {
        switch (possible[i])
        {
            case 1:
                printf("Case #%d: Possible\n", i + 1);
                break;
            case 0:
                printf("Case #%d: Broken\n", i + 1);
                break;
        }
    }

    return 0;
}
