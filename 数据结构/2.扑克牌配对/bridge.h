#ifndef BRIDGE_H_INCLUDED
#define BRIDGE_H_INCLUDED
#define OVERFLOW 0
#define OK 1

typedef int Status;

typedef struct Card {
    int num;
    struct card *next;
} Card, *CardList;

/* 初始化列表 */
Status initList(CardList *List);

void insertCard(CardList List);

void Traverse(const CardList * List);

void Show(int num);

#endif // BRIDGE_H_INCLUDED
