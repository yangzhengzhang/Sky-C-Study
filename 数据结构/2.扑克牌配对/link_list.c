#include <stdio.h>
#include <stdlib.h>

#define CARDTOTAL 52

typedef int ElemType;   // 修改类型

/* 定义链表 */
typedef struct Node {
    ElemType data;
    struct Node *next;
} Node, *LinkList;

/* 创建节点 */
LinkList NodeCreate(ElemType data, struct Node *next)
{
    struct Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = next;

    return node;
}

/* 初始化链表 */
LinkList InitList()
{
    struct Node *heading = NodeCreate(0, NULL);
    return (LinkList)heading;
}

/* 查找指定位置 */
int GetElem(LinkList List, ElemType data)
{
    struct Node *p = List->next;
    int i = 1;

    while (p && data > p->data)
    {
        p = p->next;
        i++;
    }

    return i;
}
/* 输出第i个节点的情况 */
LinkList NodeShow(LinkList List, int i)
{
    struct Node *p = List;
    int j = 0;

    while (p && j < i)
    {
        p = p->next;
        j++;
    }

    return p;
}

/* 插入节点，在第i个之前 */
void NodeInsert(LinkList List, int i, ElemType data)
{
    struct Node *p = List;
    int j = 0;

    while (p && j < i - 1)
    {
        p = p->next;
        j++;
    }

    p->next = NodeCreate(data, p->next);
}

/* 删除节点，在第i之前 */
void NodeDelete(LinkList List, int i)
{
    struct Node *p = List, *q;
    int j = 0;

    while (p->next && j < i - 1)
    {
        p = p->next;
        j++;
    }

    q = p->next;
    p->next = q->next;
    free(q);
}

/* 访问每个节点并执行函数 */
void Traverse(LinkList List, void (*pfun)(Node *p))
{
    struct Node *p = List->next;
    while (p != NULL)
    {
        (*pfun)(p);
        p = p->next;
    }
}

/* 依次输出函数 */
void Show(Node *p)
{
    printf("%d ", p->data);      // 需要修改%d
}

int ElemCount(LinkList List)
{
    struct Node *p = List->next;
    int counter = 0;
    while (p != NULL)
    {
        counter++;
        p = p->next;
    }
    return counter;
}

/* 清空链表 */
void ClearList(LinkList List)
{
    struct Node *p;
    while (List->next != NULL)
    {
        p = List->next;
        List->next = p->next;
        free(p);
    }
}

int main(void)
{
    /* 不同花色分组 */
    // int card[4][13] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    /* 不分花色版 */
    int cards[13] = {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4};
    int total = CARDTOTAL;
    int num, position;
    Node *p;
    LinkList cardDeck = InitList();
    printf("扑克牌配对开始，输入1-13的数字抓牌吧。\n");

    while (total > 0)
    {
        while (!scanf("%d", &num))
        {
            printf("请输入正确的数字");
            fflush(stdin);
        }
        if (num <= 13 && num > 0 && cards[num - 1] > 0)
        {

            position = GetElem(cardDeck, num);
            p = NodeShow(cardDeck, position);
            if (p && p->data == num)
            {
                NodeDelete(cardDeck, position);
            }
            else
            {
                NodeInsert(cardDeck, position, num);
            }
            total--;
            cards[num - 1]--;
            printf("手中牌（NULL表示无）：");
            if (ElemCount(cardDeck))
            {
                Traverse(cardDeck, Show);
            }
            else
            {
                printf("NULL");
            }
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

    return 0;
}
