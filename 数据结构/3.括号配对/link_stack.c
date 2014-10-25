#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;  // 修改类型

typedef struct Node {
    ElemType data;
    struct Node *next;
} Node, *LinkStack;

LinkStack NodeCreate(ElemType data, struct Node *next)
{
    struct Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = next;
    return node;
}

LinkStack InitStack()
{
    struct Node *heading = NodeCreate(0, NULL);
    return (LinkStack)heading;
}

/* 大于ElemCount表示不存在 */
int GetElem(LinkStack s, ElemType data)
{
    struct Node *node = s->next;
    int i = 1;

    while (node && node->data != data)
    {
        node = node->next;
        i++;
    }

    return i;
}

LinkStack NodeShow(LinkStack s, int position)
{
    struct Node *node = s;
    int i = 0;

    while (node && i < position)
    {
        node = node->next;
        i++;
    }

    return node;
}

void Push(LinkStack s, ElemType data)
{
    struct Node *node = s;
    int i = 0;
    int position = ElemCount(s);

    while (node && i < position)
    {
        node = node->next;
        i++;
    }
    node->next = NodeCreate(data, node->next);
}

void Pop(LinkStack s)
{
    struct Node *node = s, *p;
    int i = 0;
    int position = ElemCount(s);

    while (node->next && i < position - 1)
    {
        node = node->next;
        i++;
    }
    p = node->next;
    node->next = p->next;
    free(p);
}

int ElemCount(LinkStack s)
{
    struct Node *node = s->next;
    int counter = 0;
    while (node != NULL)
    {
        node = node->next;
        counter++;
    }

    return counter;
}

void ClearList(LinkStack List)
{
    struct Node *node;
    while (List->next != NULL)
    {
        node = List->next;
        List->next = node->next;
        free(node);
    }
}

/* 访问每个节点并执行函数 */
void Traverse(LinkStack List, void (*pfun)(Node *p))
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
    printf("%c ", p->data);      // 需要修改%d
}

int main(void)
{
    LinkStack s = InitStack();
    Push(s, 'c');
    Push(s, 'd');
    Pop(s);
    Push(s, 'e');
    Traverse(s, Show);
    ClearList(s);
    putchar('\n');
    Traverse(s, Show);
    Push(s, 'b');
    printf("%c", NodeShow(s, ElemCount(s))->data);
    return 0;
}
