#include <stdio.h>

int main(void)
{
    int num, breakfast[300], lunch[300], dinner[300], i, sum[300], rank[300], temp, value, sum1[300], j;
    int max, rankbefore, rankafter;

    scanf("%d", &num);

    for (i = 0; i < num; i++)
    {
        scanf("%d", breakfast + i);
        scanf("%d", lunch + i);
        scanf("%d", dinner + i);

        rank[i] = i + 1;
        sum[i] = breakfast[i] + lunch[i]+dinner[i];
        sum1[i] = breakfast[i] + lunch[i]+dinner[i];
    }

    for (i = 0; i < num; i++)
    {
        max = i;
        value = sum[i];

        for (j = i + 1; j < num; j++)
        {
            if (value < sum[j])
            {
                max = j;
                value = sum[j];
            }
        }

        sum[max] = sum[i];
        sum[i] = value;

        temp = rank[max];
        rank[max] = rank[i];
        rank[i] = temp;

    }

    for (i = 0; i < 4; i++)
    {

        rankbefore = rank[i] - 1;
        rankafter = rank[i + 1] - 1;

        if (sum1[rankbefore] == sum1[rankafter])
        {
            if (breakfast[rankbefore] < breakfast[rankafter])
            {
                    temp = rank[i];
                    rank[i] = rank[i + 1];
                    rank[i + 1] = rank[i];
            }
        }

    }

    for (i = 0; i < 5; i++)
    {
        temp = rank[i] - 1;
        printf("%d ", rank[i]);
        printf("%d\n", sum1[temp]);
    }
    return 0;
}
