#include <stdio.h>

int main(void)
{
    int t, n[100], doors[50][100], i, j, counter, k;

    scanf("%d", &t);

    for (i = 0; i < t; i++)
    {
        scanf("%d", &n[i]);
        for (j = 0; j < n[i]; j++)
        {
            for (k = 0; k < n[i]; k++)
            {
                if ((k + 1) % (j + 1) == 0)
                    if (doors[i][k] == 0)
                        doors[i][k] = 1;
                    else
                        doors[i][k] = 0;
            }
        }
    }

    for (i = 0; i < t; i++)
    {
        counter = 0;
        for (j = 0; j < n[i]; j++)
            if (doors[i][j] == 1)
                counter++;
        printf("%d\n", counter);
    }

    return 0;
}
