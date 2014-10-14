#include <stdio.h>

typedef int ElemType;   // 修改类型

/* 定义链表 */
typedef struct LNode {
    ElemType data;
    struct Lnode *next;
} LNode, *LinkList;

/* 创建节点 */
LinkList NodeCreate(ElemType data, struct Lnode *next)
{
    LNode *node = (LNode *)malloc(sizeof(LNode));
    node->data = data;
    node->next = next;

    return node;
}

/* 初始化链表 */
LinkList InitList()
{
    Node *heading = NodeCreate(0, NULL);
    return LinkList(*heading);
}
/* 查找指定位置 */
int GetElem(LinkList List, ElemType data)
{
    Node *p = L->next;
    int i = 1;

    while (p && p->data >= data && p->next->data < data)
    {
        p = p->next;
        i++;
    }

    return i;
}
/* 插入节点，在第i个之前 */
void ListInsert(LinkList List, int i, ElemType data)
{
    Node *p = List;
    int j = 0;

    while (p && j < i - 1)
    {
        p = p->next;
        j++;
    }

    p->next = NodeCreate(e, p->next);
}

/* 删除节点，在第i之前 */
void ListDelete(LinkList List, int i)
{
    Node *p = List, *q;
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

int main(void)
{

    return 0;
}
