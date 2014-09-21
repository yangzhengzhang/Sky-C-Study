#include <stdio.h>

int main(void)
{
    char const tra[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    char nums[100][10000];
    int t, n, r, counter[100] = {0}, minus[100] = {0}, i, j, k;

    scanf("%d", &t);
    for (i = 0; i < t; i++)
    {
        scanf("%d", &n);
        scanf("%d", &r);
        k = 0;
        if (n < 0)
        {
            n = -n;
            minus[i] = 1;
        }
        while (n / r != 0)
        {
            nums[i][k++] = tra[n % r];
            counter[i]++;
            n /= r;
        }
        nums[i][k++] = tra[n % r];
    }

    for (i = 0; i < t; i++)
    {
        if (minus[i])
            putchar('-');

        for(j = counter[i]; j >= 0; j--)
        {
            putchar(nums[i][j]);
        }
        putchar('\n');
    }
}
