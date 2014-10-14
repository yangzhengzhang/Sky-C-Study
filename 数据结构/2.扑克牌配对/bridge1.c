#include <stdio.h>
#include <stdlib.h>

#define CARDTOTAL 52

typedef struct Node
{
    int num;
    struct Node *next;
} Node, *Linklist;

Node *node_create(int num, struct Node *next)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->num = num;
    node->next = next;
    return node;
}

Linklist list_create()
{
    Node *heading = node_create(0, NULL);
    return (Linklist)heading;
}
/*
    function: search & change
    return 1 找到相同，删除
    return 0 未找到，插入操作
*/
Linklist search_num(Node *heading, int num)
{
    Node *p = heading, *next;
    Node *newer;

    while (p != NULL)
    {
        next = p->next;
        if (p->next == NULL && num > p->num)   // 如果找到末尾仍然没有找到
        {
            p->next = node_create(num, NULL);
            break;
        }
        else if (p->next == NULL && num == heading->num)
        {
            heading->next = NULL;
            heading->num = 0;
            break;
        }
        if (num > p->num && num < next->num)    // 如果找到了排序到的位置
        {
            p->next = node_create(num, next);
            break;
        }
        else if (num < heading->num)
        {
            heading = node_create(num, p);
            break;
        }
        else if (num == heading->num) // 如果找到的位置是heading
        {
            heading = node_create(next->num, next->next);
            heading->next = next->next;
            heading->num = next->num;
            break;
        }
        else if (num == next->num)  // 如果找到两个相同的
        {
            p->next = next->next;
            break;
        }
        p = p->next;
    }
    return (Linklist)heading;
}

void show_node(int num, int *lock)
{
    if (num == 0)
    {
        *lock = 0;
        printf("NULL");
    }
    else
    {
    printf("%d ", num);
    }
}

/* 访问每个节点并执行统一函数 */
int Traverse(Node *heading, int *lock, void (* pfun)(int num, int *lock))
{
    Node *p = heading;
    int counter = 0;
    while (p != NULL)
    {
        (* pfun)(p->num, lock);
        p = p->next;
        counter++;
    }
    return counter;
}

int main(void)
{
    int lock = 0, num;
    int cards[13] = {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4};
    int total = CARDTOTAL;

    struct Node *heading = list_create();
    printf("扑克牌配对开始，输入1-13的数字抓牌吧。\n");
    while (total > 0)
    {
        scanf("%d", &num);
        if (num <= 13 && num > 0 && cards[num - 1] > 0)
        {
            if (lock == 0)
            {
                heading->num = num;
                lock = 1;
            }
            else
            {
                heading = search_num(heading, num);
            }
            total--;
            cards[num - 1]--;
            printf("手中牌（NULL表示无）：");
            Traverse(heading, &lock, show_node);
            putchar('\n');
        }
        else if (num > 13 || num <= 0)
        {
            printf("数字错误，请重试\n");
        }
        else if (cards[num - 1] <= 0)
        {
            printf("该数字卡片木有啦\n");
        }
    }
    printf("本轮结束，牌全部用完，谢谢拉\n");
    printf("%d", heading->num);

    return 0;
}
