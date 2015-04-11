#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_BUF 400

// 构建哈希表
typedef struct HashTable
{
    char *word; // 单词首地址
    int count;  // 计数
} HashTable;

/*
    对哈希表进行初始化
 
    @params *table 哈希表
    @params from 起始值
    @params to 终止值（不含）
 
    @return NULL
 */
void InitHashTable(HashTable *table, size_t from, size_t to)
{
    size_t i;
    
    HashTable *curr = NULL;
    
    for (i = from; i < to; i++)
    {
        curr = table + i;
        
        curr->word = NULL;
        curr->count = 0;
    }
}

/*
    录入单词
 
    @params *temp 存放单词的临时变量
    @params maxLength 可存放的最大长度
 
    @return length 单词长度
 */
int InputWord(char *temp, size_t maxLength)
{
    char c;
    int length = 0;
    while ((c = getchar()) != EOF)
    {
        if (length < maxLength && (isalnum(c) || c == '-'))     // 单词过长抛弃部分，如果是字母或数字或有-连接符，则判断为单词
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

/*
    计算哈希值确定在哈希表中的默认位置
 
    @params temp 存放单词的临时变量
 
    @return hashValue 哈希值
 */
int CalculateHashValue(char *temp)
{
    size_t asciiSum = 0;
    
    while (*temp)
    {
        asciiSum += *temp;
        temp++;
    }
    return asciiSum % MAX_BUF;
}

/*
    确定实际存放位置，如果不够则开辟空间
 
    @params *temp 存放单词的临时变量
    @params **table 哈希表的地址
    @params length 单词长度
    @params *buf_times 目前哈希表表倍数的地址
 
    @return i 实际存放位置
 */
int Locate(char *temp, HashTable **table, int length, size_t *buf_times)
{
    int head, i;    // head 默认存放位置
    
    for (i = head = CalculateHashValue(temp); (*table + i)->word != NULL && strcmp(temp, (*table +i)->word) != 0; )     // 如果单词存在并且与已存单词不同
    {
        i++;        // 线性探测查找位置
        if (i == MAX_BUF * *buf_times)  // 如果探测到尾部，从头开始
            i = 0;
        if (i == head)  // 如果完成一圈查找并没有找到，则表增加一倍
        {
            (*buf_times)++;
            *table = (HashTable *)realloc(*table, sizeof(HashTable) * MAX_BUF * *buf_times);
            InitHashTable(*table, MAX_BUF * (*buf_times - 1), MAX_BUF * *buf_times);
        }
    }
    
    return i;
}

int main(void)
{
    size_t temp_buf = 50;   // 临时单词变量长度
    size_t buf_times = 1;   // 哈希表表长倍数
    size_t max_count = 0, max_position = 0; // 用于最后顺序查找最大值
    char *temp = (char *)malloc(temp_buf);
    HashTable *table = (HashTable *)malloc(sizeof(HashTable) * MAX_BUF * buf_times);
    HashTable *curr;
    int strLength, i;   // 单词长度
    
    InitHashTable(table, 0, MAX_BUF * buf_times);
    
    for (i = 0; i < 50; i++)
        putchar('a');
    while ( (strLength = InputWord(temp, temp_buf)) != 0)
    {
        if (*temp == '\0')  // 如果单词为空，丢弃这个单词并继续
        {
            continue;
        }
        i = Locate(temp, &table, strLength, &buf_times);
        curr = table + i;
        if (curr->word == NULL)
        {
            curr->word = (char *)malloc(strLength);    // 根据单词长度开辟空间
            strcpy(curr->word, temp);    // 拷贝到目标位置
            //           printf("%s %s", temp, (table+i)->word);
        }
        curr->count++;
    }
    
    for (i = 0; i < MAX_BUF * buf_times; i++)
    {
        curr = table + i;
        if (curr->count > max_count)
        {
            max_position = i;
            max_count = curr->count;
        }
    }
    
    printf("Max Word: %s, Count: %ld\n", (table + max_position)->word, max_count);
    
    return 0;
}
