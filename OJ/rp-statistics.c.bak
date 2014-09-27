#include <stdio.h>

int main(void)
{
    int rp[100];
    int T, n;
    int i, j;
    int change;

    scanf("%d", &T);

    for(i = 0; i < T; i++)
    {
        scanf("%d", &n);
        rp[i] = 10000;
        for (j = 0; j < n; j++)
        {
            scanf("%d", &change);
            rp[i] += change;
        }
    }

    for (i = 0; i < T; i++)
        printf("Case #%d: %d\n", i + 1
               ,rp[i]);

    return 0;
}
