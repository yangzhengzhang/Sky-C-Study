#include <stdio.h>
#include <stdlib.h>
#include "bridge.h"

Status initList(CardList * List)
{
    *List = (CardList *)malloc(sizeof(CardList));
    if (!*List)
        exit(OVERFLOW);
    (*List) -> num = 0;
    (*List) -> next = NULL;
    return OK;
}

void insertCard(CardList List)
{
    int num;
    CardList p;
    scanf("%d", &num);
    p = (CardList *)malloc(sizeof(Card));
    p->num = num;
    p->next = List->next;
    List->next = p;
}

void Traverse(const CardList * List)
{
    Card *p = *List;
    while (p != NULL)
    {
        Show((p->num));
        p = p->next;
    }
}

void Show(int num)
{
    printf("%d ", num);
}
