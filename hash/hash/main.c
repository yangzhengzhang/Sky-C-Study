#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct HashTable
{
    int asciiSum;
    int strlen;
    char *head;
    int counter;
} HashTable;

int main(void)
{
    int tempLocation = 0, strmax = 100;
    char *temp = (char*)malloc(sizeof(char) * strmax), *head;
    char c;
    int HashTableMax = 100;
    HashTable *hashTable = (HashTable *)malloc(sizeof(HashTable) * HashTableMax);
//    int (*HashTable)[HashTableMax] = (int (*)[HashTableMax])malloc(sizeof(int [HashTableMax]));
    int status = 0, asciiSum = 0, length = 0;
    int same = 0;
    int position;
    int i, j;
    int maxPosition = 0, maxCount = 0;

    head = temp;
    /* printf("p = %d\n", head);*/

    for (i = 0; i < HashTableMax; i++)
    {
        hashTable[i].asciiSum = 0;
        hashTable[i].strlen = 0;
        hashTable[i].head = NULL;
        hashTable[i].counter = 0;
    }

    while ((c = getchar()) != EOF)
    {
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
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

            if (!hashTable[position].head)
            {
                hashTable[position].asciiSum = asciiSum;
                hashTable[position].strlen = length;
                hashTable[position].head = head;
                hashTable[position].counter++;
                //printf("String:%s, AsciiSum: %d, length: %d\n", temp, asciiSum, length);
                //printf("New one, String:%s, AsciiSum: %d, length: %d, counter: %d\n", hashTable[position].head, hashTable[position].asciiSum, hashTable[position].strlen, hashTable[position].counter);
            }
            else
            {
                same = 0;
                i = position;
                while (1)
                {
                    //printf("没找到相同的 开始循环！\n");
                    /*printf("Length: %d", HashTable[1][i]);*/
                    if (!hashTable[i].head)
                        break;
                    if (hashTable[i].strlen == length)
                    {
                        /*                        printf("找到啦长度不错哒!\n");*/
                        if (strcmp(head, hashTable[i].head) == 0)
                        {
                            position = i;
                            hashTable[position].counter++;
                            // printf("Haved, String:%s, AsciiSum: %d, length: %d, counter: %d\n", hashTable[position].head, hashTable[position].asciiSum, hashTable[position].strlen, hashTable[position].counter);
                            printf("Error");
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
                        if (!hashTable[i].head)
                        {
                            position = i;
                            hashTable[position].asciiSum = asciiSum;
                            hashTable[position].strlen = length;
                            hashTable[position].head = head;
                            hashTable[position].counter++;
                            //printf("String:%s, AsciiSum: %d, length: %d\n", temp, asciiSum, length);
                            // printf("Adding, String:%s, AsciiSum: %d, length: %d, counter: %d\n", hashTable[position].head, hashTable[position].asciiSum, hashTable[position].strlen, hashTable[position].counter);
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
                            hashTable = (HashTable *)realloc(hashTable, sizeof(HashTable) * HashTableMax);
                            /*printf("已重新分配");*/

                            for (j = HashTableMax / 2; j < HashTableMax; j++)
                            {
                                /*printf("Here is : %d\n", j);*/
                                hashTable[i].asciiSum = 0;
                                hashTable[i].strlen = 0;
                                hashTable[i].head = NULL;
                                hashTable[i].counter = 0;
                            }
                        }
                    }
                }
            }
            if (hashTable[position].counter > maxCount)
            {
                maxPosition = position;
                maxCount = hashTable[position].counter;
                /*printf("最高纪录已刷新");*/
            }
            temp += (length + 1);
            head = temp;
            /*printf("p = %d\n", head);*/
            length = 0;
            asciiSum = 0;
            status = 0;
            tempLocation += length;
            if (strmax - tempLocation < 50)
            {
                strmax *= 2;
                temp = (char *)realloc(temp, sizeof(char) * strmax);
            }
        }
    }

    position = maxPosition;

    printf("String:%s, AsciiSum: %d, length: %d, counter: %d\n", hashTable[position].head, hashTable[position].asciiSum, hashTable[position].strlen, hashTable[position].counter);


    return 0;
}
