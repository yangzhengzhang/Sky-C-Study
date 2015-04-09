#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_BUF 1

// 构建哈希表
typedef struct HashTable
{
    char *word; // 单词首地址
    int count;  // 计数
} HashTable;

int InputWord(char *temp)
{
    char c;
    int length = 0;
    while ((c = getchar()) != EOF)
    {
        if (isalnum(c))
        {
            *(temp + length) = c;
            length++;
        }
        else
        {
            *(temp + length) = '\0';
            length++;
            break;
        }
    }

    return length;
}

size_t CalculateHashValue(char *temp)
{
    size_t asciiSum = 0;

    while (*temp)
    {
        asciiSum += *temp;
        temp++;
    }
    return asciiSum % MAX_BUF;
}

int Locate(char *temp, HashTable **table, int length, size_t *buf_times)
{
    int head, i;
    for (i = head = CalculateHashValue(temp); (*table + i)->word != NULL && strcmp(temp, (*table +i)->word) != 0; )
    {
        i++;
        if (i == MAX_BUF * *buf_times)
            i = 0;
        if (i == head)
        {
            (*buf_times)++;
            *table = (HashTable *)realloc(*table, sizeof(HashTable) * MAX_BUF * *buf_times);
            InitHashTable(*table, MAX_BUF * (*buf_times - 1), MAX_BUF * *buf_times);
        }
    }

    return i;
}

void InitHashTable(HashTable *table, size_t from, size_t to)
{
    size_t i;
    for (i = from; i < to; i++)
    {
        (table+i)->word = NULL;
        (table+i)->count = 0;
    }
}

int main(void)
{
    size_t temp_buf = 50;
    size_t buf_times = 1;
    size_t max_count = 0, max_position = 0;
    char *temp = (char *)malloc(temp_buf);
    HashTable *table = (HashTable *)malloc(sizeof(HashTable) * MAX_BUF * buf_times);
    int length, i;

    InitHashTable(table, 0, MAX_BUF * buf_times);

    while (length = InputWord(temp))
    {
        if (*temp == '\0')
        {
            continue;
        }
        i = Locate(temp, &table, length, &buf_times);
        if ((table + i)->word == NULL)
        {
            (table+i)->word = (char *)malloc(length);
            strcpy((table + i)->word, temp);
 //           printf("%s %s", temp, (table+i)->word);
        }
        (table+i)->count++;
    }

    for (i = 0; i < MAX_BUF * buf_times; i++)
    {
        if ((table+i)->count > max_count)
        {
            max_position = i;
            max_count = (table + i)->count;
        }
    }

    printf("Max Word: %s, Count: %d\n", (table + max_position)->word, max_count);

    return 0;
}
