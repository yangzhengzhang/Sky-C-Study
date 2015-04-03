#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
/*
void myqsort(int **nums,int n, int m)
{
    int temp[4];
    int i = n, j = m;

    if (n  > m)
        return;

    while (i != j)
    {
        while (nums[3][j] >= nums[3][n] && i < j)
            j--;
        while (nums[3][i] <= nums[3][n] && i < j)
            i++;

        if (i < j)
        {
            temp[0] = nums[0][i];
            temp[1] = nums[1][i];
            temp[2] = nums[2][i];
            temp[3] = nums[3][i];
            nums[0][i] = nums[0][j];
            nums[1][i] = nums[1][j];
            nums[2][i] = nums[2][j];
            nums[3][i] = nums[3][j];
            nums[0][j] = temp[0];
            nums[1][j] = temp[1];
            nums[2][j] = temp[2];
            nums[3][j] = temp[3];
        }
    }

    temp[0] = nums[0][n];
    temp[1] = nums[1][n];
    temp[2] = nums[2][n];
    temp[3] = nums[3][n];
    nums[0][n] = nums[0][i];
    nums[1][n] = nums[1][i];
    nums[2][n] = nums[2][i];
    nums[3][n] = nums[3][i];
    nums[0][i] = temp[0];
    nums[1][i] = temp[1];
    nums[2][i] = temp[2];
    nums[3][i] = temp[3];

    nums[n] = nums[i];
    nums[i] = temp;


    myqsort(nums, 0, i - 1);
    myqsort(nums, i + 1, m);
}
*/
int main(void)
{
    char *temp = (char*)malloc(sizeof(char)), *head;
    char c;
    int HashTableMax = 100;
    int (*HashTable)[HashTableMax] = (char (*)[HashTableMax])malloc(sizeof(char [HashTableMax]));
    int status = 0, asciiSum = 0, length = 0;
    int same = 0;
    int position;
    int i, j;
    int maxPosition = 0, maxCount = 0;


    head = temp;
   /* printf("p = %d\n", head);*/

    for (i = 0; i < HashTableMax; i++)
    {
        HashTable[0][i] = 0;
        HashTable[1][i] = 0;
        HashTable[2][i] = 0;
        HashTable[3][i] = 0;
    }

    while ((c = getchar()) != EOF)
    {
        if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z' || c >= '0' && c <= '9')
        {
            status = 1;
            c = tolower(c);
            *(temp + length) = c;
            asciiSum += c;
            length++;
        }
        else if (status == 1)
        {
            *(temp + length) = '\0';
            //printf("String:%s, AsciiSum: %d, length: %d\n", temp, asciiSum, length);
            position = asciiSum % 83;
            /*printf("%d", HashTable[3][position]);*/
            //Sleep(2000);

            if (!HashTable[3][position])
            {
                HashTable[0][position] = asciiSum;
                HashTable[1][position] = length;
                HashTable[2][position] = head;
                HashTable[3][position]++;
                //printf("String:%s, AsciiSum: %d, length: %d\n", temp, asciiSum, length);
                printf("New one, String:%s, AsciiSum: %d, length: %d, counter: %d\n", HashTable[2][position], HashTable[0][position], HashTable[1][position], HashTable[3][position]);
            }
            else
            {
                same = 0;
                i = position;
                while (1)
                {
                    //printf("没找到相同的 开始循环！\n");
                    /*printf("Length: %d", HashTable[1][i]);*/
                    if (!HashTable[1][i])
                        break;
                    if (HashTable[1][i] == length)
                    {
/*                        printf("找到啦长度不错哒!\n");*/
                        if (strcmp(head, (char *)HashTable[2][i]) == 0)
                        {
                            position = i;
                            HashTable[3][position]++;
                            printf("Haved, String:%s, AsciiSum: %d, length: %d, counter: %d\n", HashTable[2][i], HashTable[0][i], HashTable[1][i], HashTable[3][i]);
                            same = 1;
                            break;
                        }

                    }
                    i++;
                    if (i > HashTableMax)
                    {
/*                        printf("开始新一轮");
                        Sleep(200);*/
                        i = 0;
                    }
                    else if (i == position)
                        break;
                }
                if (!same)
                {
                    i = position;
                    while (1)
                    {
                        if (!HashTable[3][i])
                        {
                            position = i;
                            HashTable[0][position] = asciiSum;
                            HashTable[1][position] = length;
                            HashTable[2][position] = head;
                            HashTable[3][position]++;
                            //printf("String:%s, AsciiSum: %d, length: %d\n", temp, asciiSum, length);
                            printf("Adding, String:%s, AsciiSum: %d, length: %d, counter: %d\n", HashTable[2][i], HashTable[0][i], HashTable[1][i], HashTable[3][i]);
                            break;
                        }
                        i++;
                        /*printf("Now i = %d\n", i);*/
                        if (i > HashTableMax)
                            i = 0;
                        else if (i == position)
                        {
                            /*printf("开始重新分配");*/
                            HashTableMax *= 2;
                            (*HashTable)[HashTableMax] = (char (*)[HashTableMax])realloc((*HashTable)[HashTableMax], sizeof(char [HashTableMax]));
                            /*printf("已重新分配");*/

                            for (j = HashTableMax / 2; j < HashTableMax; j++)
                            {
                                /*printf("Here is : %d\n", j);*/
                                HashTable[0][j] = 0;
                                HashTable[1][j] = 0;
                                HashTable[2][j] = 0;
                                HashTable[3][j] = 0;
                            }
                        }
                    }
                }
            }
            if (HashTable[3][position] > maxCount)
            {
                maxPosition = position;
                maxCount = HashTable[3][position];
                /*printf("最高纪录已刷新");*/
            }
            temp += (length + 1);
            head = temp;
            /*printf("p = %d\n", head);*/
            length = 0;
            asciiSum = 0;
            status = 0;
        }
    }

    position = maxPosition;

    printf("String:%s, AsciiSum: %d, length: %d, counter: %d\n", HashTable[2][position], HashTable[0][position], HashTable[1][position], HashTable[3][position]);


    return 0;
}
