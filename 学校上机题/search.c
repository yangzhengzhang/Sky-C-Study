#include <stdio.h>

#define NUM 10

int main(void)
{
    int a[NUM]= {1, 4, 6, 9, 13, 16, 19, 28, 40, 100};
    int i, j, temp, searching;   /* ѭ�� */

    int result = -1;
    int low = 0, high = NUM - 1, guess;
    guess = low + (high - low) / 2;
    printf("Please puts the number you want to search: ");
    scanf("%d", &searching);


    /* �۰���� */
    while (low <= high) {
        guess = low + (high - low) / 2;
        if (a[guess] == searching) {
            result = a[guess];
            break;
        }
        else if (a[guess] > searching)
                high = guess - 1;
        else
            low = guess + 1;
    }
    if (result != -1) {  /* ���û���ҵ���Ӧֵ */
        for (a[guess] = 0, i = guess; i < NUM - 1; i++)
            a[i] = a[i + 1];
        for (i = 0; i < NUM - 1; i++)
            printf("%d ",a[i]);
    }
    else
        printf("������û���������");


    return 0;
}
