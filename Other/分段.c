#include <stdio.h>

int main(void)
{
    int num, i, count[11];

    for (i = 0; i <= 10; i++)
        count[i] = 0;

    printf("请输入[0,100]的数\n");
    scanf("%d", &num);
    while (num != -1) {
        if(num >= 0 && num <=100)
            count[num / 10]++;
        else
            printf("请输入正确范围的数字\n");
        printf("请输入[0,100]的数\n");
        scanf("%d", &num);
    }

    for (i = 0; i <= 10; i++)
        printf("%5d", count[i]);

    return 0;
}
