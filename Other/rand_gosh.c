#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/*  random function */
int random(double num)
{
    if (num > 0 && num <= 0.022)
        return 5;
    else if (num > 0.022 && num <= 0.157)
        return 4;
    else if (num > 0.157 && num <= 0.5)
        return 3;
    else if (num > 0.5 && num <= 0.843)
        return 2;
    else if (num > 0.843 && num <= 0.978)
        return 1;
    else if (num > 0.978 && num <= 1)
        return 0;
}

int main(void)
{
    int array[4][100], num, i, j, sum;
    double randnum;

    /* create a seed    */
    srand((int)time(0));

    for (j = 0; j < 4; j++) {
        for (i = 0, sum = 0; i < 99; i++) {
            randnum = rand() / (float)RAND_MAX; /* Create num : 0 - 1 */
            num = random(randnum);
            array[j][i] = num;
            sum += num;
        }

        /* random the last num */
        switch (sum % 3) {
            case 0:
                while (num = random(rand() / (float)RAND_MAX))
                if (num == 0 || num == 3)
                        break;
                break;
            case 1:
                while (num = random(rand() / (float)RAND_MAX))
                    if (num == 2 || num == 5)
                        break;
                break;
            case 2:
                while (num = random(rand() / (float)RAND_MAX))
                    if (num == 1 || num == 4)
                        break;
                break;
        }
        array[j][i] = num;

        sum += num;
        printf("%d\n", sum);    /* print sum to check */
    }

    /* output */
    for (i = 0; i < 100; i++)
        for (j = 0; j < 4; j++) {
            printf("%4d", array[j][i]);
            if (j == 3)
                printf("\n");
        }

    return 0;
}
