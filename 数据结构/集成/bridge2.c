<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define CARDTOTAL 52

typedef struct Node
{
    int num;
    struct Node *next;
} Node, *Linklist;

void InitList(LinkList *plist)
{
    *plist = NULL;
}

bool ListIsEmpty(const Linklist *plist)
{
    if (*plist = NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

unsigned int ListItemCount(const Linklist * plist)
{
    unsigned int count = 0;

    Node *pnode = *plist;
    while (pnode != NULL)
    {
        ++count;
        pnode = pnode->next;
    }

    return count;
}

bool AddNode(int num, Linklist *plist, int situation)
{
    Node *scan = *plist;
    Node *pnew;
    pnew = (Node *)malloc(sizeof(Node));
    int location = 0;

    if (pnew == NULL)
        return false;

    CopyToNode(num, pnew);
    pnew->next = NULL;
    if (scan == NULL)
        *plist = pnew;
    else
    {
        while (scan->next != NULL)
            scan = scan->next;
        scan->next = pnew;
    }
    return true;
}

void Traverse(const List * plist, void (*pfun)(Item item))
{
    Node * pnode = *plist;
    while (pnode != NULL)
    {
        (* pfun)(pnode -> item);
        pnode = pnode->next;
    }
}

void EmptyTheList(List *plist)
{
    Node *psave;
    while (*plist != NULL)
    {
        psave = (*plist)->next;
        free(*plist);
        *plist = psave;
    }
}

static void CopyToNode(int num, Node *pnode)
{
    pnode->num = num;
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
=======
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define CARDTOTAL 52

typedef struct Node
{
    int num;
    struct Node *next;
} Node, *Linklist;

void InitList(LinkList *plist)
{
    *plist = NULL;
}

bool ListIsEmpty(const Linklist *plist)
{
    if (*plist = NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

unsigned int ListItemCount(const Linklist * plist)
{
    unsigned int count = 0;

    Node *pnode = *plist;
    while (pnode != NULL)
    {
        ++count;
        pnode = pnode->next;
    }

    return count;
}

bool AddNode(int num, Linklist *plist, int situation)
{
    Node *scan = *plist;
    Node *pnew;
    pnew = (Node *)malloc(sizeof(Node));
    int location = 0;

    if (pnew == NULL)
        return false;

    CopyToNode(num, pnew);
    pnew->next = NULL;
    if (scan == NULL)
        *plist = pnew;
    else
    {
        while (scan->next != NULL)
            scan = scan->next;
        scan->next = pnew;
    }
    return true;
}

void Traverse(const List * plist, void (*pfun)(Item item))
{
    Node * pnode = *plist;
    while (pnode != NULL)
    {
        (* pfun)(pnode -> item);
        pnode = pnode->next;
    }
}

void EmptyTheList(List *plist)
{
    Node *psave;
    while (*plist != NULL)
    {
        psave = (*plist)->next;
        free(*plist);
        *plist = psave;
    }
}

static void CopyToNode(int num, Node *pnode)
{
    pnode->num = num;
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
>>>>>>> a0e8d74199742fbdb78356ff34cbaa1198f5fe58
