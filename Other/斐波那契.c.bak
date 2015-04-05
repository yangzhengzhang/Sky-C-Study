#include <stdio.h>

int main(void)
{
    int start, former, later, end, temp, i;

    printf("print the start num: ");
    scanf("%d", &start);
    printf("print the end num: ");
    scanf("%d", &end);

    former = 0;
    later = 1;
    i = 0;

    while (former <= end) {
        if (former >= start) {
            printf("%d ", former);
            i++;
        }
        temp = later;
        later = former + later;
        former = temp;
    }

    if (i == 0)
    {
        printf("NONE");
    }

    return 0;

}
