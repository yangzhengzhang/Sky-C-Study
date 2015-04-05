#include <stdio.h>

int main(void)
{
    int i, sum[10], max, value, j, num = 10;

    for (i = 0; i < 10; i++)
    {
        scanf("%d", sum+i);
    }

    for (i = 0; i < num; i++)
    {
        max = i;
        value = sum[i];

        for (j = i + 1; j < num; j++)
        {
            if (value > sum[j])
            {
                max = j;
                value = sum[j];
            }
        }

        sum[max] = sum[i];
        sum[i] = value;
    }

    for (i = 0; i < 10; i++)
    {
        printf("%d ", sum[i]);
    }

}
