#include <stdio.h>

int main(void)
{
    int i, a[100], n[100], t, k[100], b, j;

    scanf("%d", &t);


    for(j = 0; j < t; j++)
    {
        scanf("%d", &n[j]);
        scanf("%d", &a[j]);

        b = a[j];

        for (i = 1, k[j] = 0; n[j] > 0; b--)
        {
            if (b == 0 && i == 1)
            {
                k[j]++;
                break;
            }
            else if(b == 0)
            {
                b = a[j] + 1;
                n[j]--;
                k[j]++;
            }
            i++;
            if (i > n[j])
                i = 1;
        }
    }


    for (j = 0; j < t; j++)
        printf("Case #%d: %d\n", j + 1, k[j]);

    return 0;
}
