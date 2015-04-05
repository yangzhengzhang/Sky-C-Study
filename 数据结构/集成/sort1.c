<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>

typedef struct Elem {
    int value;
} Elem;

void myqsort(Elem *nums,int n, int m)
{
    Elem temp;
    int i = n, j = m;

    if (n  > m)
        return;

    while (i != j)
    {
        while (nums[j].value >= nums[n].value && i < j)
            j--;
        while (nums[i].value <= nums[n].value && i < j)
            i++;

        if (i < j)
        {
            temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
    }

    temp = nums[n];
    nums[n] = nums[i];
    nums[i] = temp;


    myqsort(nums, 0, i - 1);
    myqsort(nums, i + 1, m);
}

int main(void)
{
    Elem nums[100];
    int n, i;

    printf("输入多少个数字：");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &((nums + i)->value));
    }

    printf("排序前：");
    for (i = 0; i < n; i++)
    {
        printf("%d ", (nums + i)->value);
    }
    putchar('\n');

    myqsort(nums, 0, n - 1);

    printf("排序后：");
    for (i = 0; i < n; i++)
    {
        printf("%d ", (nums + i)->value);
    }
    return 0;
}
=======
#include <stdio.h>
#include <stdlib.h>

typedef struct Elem {
    int value;
} Elem;

void myqsort(Elem *nums,int n, int m)
{
    Elem temp;
    int i = n, j = m;

    if (n  > m)
        return;

    while (i != j)
    {
        while (nums[j].value >= nums[n].value && i < j)
            j--;
        while (nums[i].value <= nums[n].value && i < j)
            i++;

        if (i < j)
        {
            temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
    }

    temp = nums[n];
    nums[n] = nums[i];
    nums[i] = temp;


    myqsort(nums, 0, i - 1);
    myqsort(nums, i + 1, m);
}

int main(void)
{
    Elem nums[100];
    int n, i;

    printf("输入多少个数字：");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &((nums + i)->value));
    }

    printf("排序前：");
    for (i = 0; i < n; i++)
    {
        printf("%d ", (nums + i)->value);
    }
    putchar('\n');

    myqsort(nums, 0, n - 1);

    printf("排序后：");
    for (i = 0; i < n; i++)
    {
        printf("%d ", (nums + i)->value);
    }
    return 0;
}
>>>>>>> a0e8d74199742fbdb78356ff34cbaa1198f5fe58
