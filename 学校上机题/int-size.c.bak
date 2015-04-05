#include <stdio.h>

int main(void)
{
    int num[10], i, higherZero = 0, equalZero = 0, lowerZero = 0;

    for (i = 0; i < 10; i++) {
        printf("%d.Print the number: ", i + 1);
        scanf("%d", &num[i]);
        if (num[i] < 0)
            lowerZero++;
        else if (num[i] > 0)
            higherZero++;
        else
            equalZero++;
    }

    printf("\nGreater Than 0 : %d\nLower Than 0: %d\nEqual 0: %d\n", higherZero, lowerZero, equalZero);

    return 0;
}
