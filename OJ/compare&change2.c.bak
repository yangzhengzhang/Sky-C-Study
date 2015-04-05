#include <stdio.h>
#define SIZE 10

void scan_num(int num[])
{
    int i;

    for (i = 0; i < SIZE; i++)
        scanf("%d", num + i);
}

void compare(int num[])
{
    int *max = num, *min = num;
    int i, temp;

    for(i = 1; i < SIZE; i++)
        if (*(num + i) > *max)
            max = num + i;
        else if (*(num + i) < *min)
            min = num + i;

    temp = *min;
    *min = *num;
    *num = temp;

    temp = *max;
    *max = *(num + SIZE - 1);
    *(num + SIZE - 1) = temp;
}

void print_num(int num[])
{
    int i;

    for (i = 0; i < SIZE; i++)
        printf("%d ", *num++);
}

int main(void)
{
    int num[10];

    scan_num(num);
    compare(num);
    print_num(num);
    return 0;
}
