#include <stdio.h>

int Yang(int num);

int main(void)
{
    int num;

    printf("请输入你要的层数: ");
    scanf("%d", &num);
    Yang(num);

    return 0;
}

int Yang(int num)
{
    int i, j, k, array[num], result[num], former, later;

    for (i = 1; i <= num; i++) {
        array[0] = 1;
        array[i - 1] = 1;
        result[0] = 1;
        result[i - 1] = 1;
        for (j = 1; j < i - 1; j++) {
            former = array[j - 1];
            later = array[j];
            result[j] = former + later;
        }
        for (k = 0; k < i; k++)
            array[k] = result[k];
    }

    for (i = 0; i < num; i++)
        printf("%-3d", result[i]);

    return 0;
}
