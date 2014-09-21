#include <stdio.h>

#define NUM 10

int main(void)
{
    int ages[NUM] = {5, 80, 55, 30, 60, 22, 32, 18, 43, 35};
    int i, j, temp, searching;   /* 循环 */
    int result = -1;
    int low = 0, high = NUM - 1, guess;

    guess = low + (high - low) / 2;

    printf("Please puts the age you want to search: ");
    scanf("%d", &searching);

    /* 冒泡排序 */
    for (i = 0; i < NUM; i++)
        for (j = 0; j < NUM - 1 - i; j++) {
            if (ages[j] > ages[j + 1]) {
                temp = ages[j];
                ages[j] = ages[j + 1];
                ages[j + 1] = temp;
            }
        }

    /* 折半查找 */
    while (low <= high) {
        guess = low + (high - low) / 2;
        if (ages[guess] == searching) {
            result = ages[guess];
            break;
        }
        else if (ages[guess] > searching)
                high = guess - 1;
        else
            low = guess + 1;
    }

    if (result != -1)   /* 如果没有找到对应值 */
        printf("Yes the age your printing is on our database, is it %d ?\n", result);
    else
        printf("Sorry I couldn't find the number your print: %d!\n", searching);

    return 0;
}
