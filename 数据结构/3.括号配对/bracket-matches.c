#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;  // 修改类型

typedef struct Node {
    ElemType data;
    struct Node *next;
} Node, *LinkStack;

/**
 * 创建新的节点并返回节点
 * @param ElemType data
 * @param struct Node *next
 * @return LinkStack node
 */
LinkStack NodeCreate(ElemType data, struct Node *next)
{
    struct Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = next;
    return node;
}

/**
 * 初始化链栈并返回头结点
 * @return LinkStack heading
 */
LinkStack InitStack()
{
    struct Node *heading = NodeCreate(0, NULL);
    return (LinkStack)heading;
}

/**
 * 获取元素所在位置 如果i > ElemCount(s) 说明不存在
 * @param LinkStack s
 * @param ElemType data
 * @return int i
 */
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

/**
 * 返回某位置节点
 * @param LinkStack s
 * @param int position 第position个元素
 * @return LinkStack node
 */
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

/**
 * 元素压入栈内
 * @param LinkStack s
 * @param ElemType data
 */
void Push(LinkStack s, ElemType data)
{
    struct Node *node = s;
    int i = 0;
    int position = ElemCount(s);

    while (node->next && i < position)
    {
        node = node->next;
        i++;
    }
    node->next = NodeCreate(data, node->next);
}

/**
 * 元素出栈
 * @param LinkStack s
 * @return ElemType elem 返回出栈节点的data
 */
ElemType Pop(LinkStack s)
{
    struct Node *node = s, *p;
    ElemType elem;
    int i = 0;
    int position = ElemCount(s);

    if (!position)
    {
        return -1;  // 保护机制 如果栈为空
    }

    while (node->next && i < position - 1)
    {
        node = node->next;
        i++;
    }
    p = node->next;
    node->next = p->next;
    elem = p->data;
    free(p);
    return elem;
}

/**
 * 返回节点（元素）个数
 * @param LinkStack s
 * @return int counter
 */
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

/**
 * 清空栈内元素
 * @param LinkStack List
 */
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

/**
 * 遍历节点并调用指定函数
 * @param LinkStack List
 * @param void (*pfun)(Node *p)  要调用的函数，函数要求只传入节点
 */
void Traverse(LinkStack List, void (*pfun)(Node *p))
{
    struct Node *p = List->next;
    while (p != NULL)
    {
        (*pfun)(p);
        p = p->next;
    }
}

/**
 * 显示节点元素数据
 * @param Node *p
 */
void Show(Node *p)
{
    printf("%c ", p->data);      // 需要修改%c
}

int main(void)
{
    LinkStack s = InitStack();

    return 0;
}
