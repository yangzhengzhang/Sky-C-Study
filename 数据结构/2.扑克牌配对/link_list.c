#include <stdio.h>
#include <stdlib.h>

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
    struct Node *q = p->next;
    int i = 1;

    while (p && p->data >= data && q->data < data)
    {
        p = p->next;
        q = q->next;
        i++;
    }

    return i;
}
/* 插入节点，在第i个之前 */
void ListInsert(LinkList List, int i, ElemType data)
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
void ListDelete(LinkList List, int i)
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
    printf("%d", p->data);      // 需要修改%d
}

int ElemCount(LinkList List)
{
    struct Node *p = List;
    int counter = 0;
    while (p != NULL)
    {
        counter++;
        p = p->next;
    }
    return counter;
}

/* 清空本地址 */
void ClearList(Node *p)
{
    free(p);
}

int main(void)
{

    return 0;
}
