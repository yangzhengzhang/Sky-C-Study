#include <stdio.h>

int Yang(int row, int col)
{
    int len = row;
    if (row == 1 || col == 1 || col == len)
        return 1;
    if (col > len)
        return 0;
    return Yang(row - 1, col - 1) + Yang(row - 1, col);
}

int main(void)
{
    int row, i;

    scanf("%d", &row);

    for (i = 1; i <= row; ++i)
        printf("%d ", Yang(row, i));
    printf("\n");

    return 0;
}
