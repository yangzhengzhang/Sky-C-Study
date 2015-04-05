#include <stdio.h>

void scan_num(int num[])
{
    int i;

    for (i = 0; i < 10; i++)
        scanf("%d", num++);
}

void compare(int num[])
{
    int *max = num, *min = num;
    int i, temp;

    for(i = 1; i < 10; i++) {
        if (*(num + i) > *max)
            max = num + i;
        else if (*(num + i) < *min) {
            min = num + i;
        }
    }

    temp = *min;
    *min = *num;
    *num = temp;

    temp = *max;
    *max = *(num + 9);
    *(num + 9) = temp;

}

void print_num(int num[])
{
    int i;

    for (i = 0; i < 10; i++)
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
