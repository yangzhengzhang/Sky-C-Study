#ifndef __TREE_H_
#define _TREE_H_
#include <stdbool.h>

typedef struct item
{
    char petname[20];
    char petkind[20];
} Item;

#define MAXITEMS 10

typedef struct node
{
    Item item;
    struct node *left;  /* 指向左分支的指针 */
    struct node *right; /* 指向右分支的指针 */
} Node;

typedef struct tree
{
    Node *root;  /* 指向树根的指针 */
    int size;   /* 树中项目的个数 */
} Tree;

/* 函数原型 */
/* 操作：把一个树初始化为空树 */
/* 操作前：ptree指向一个树 */
/* 操作后：该树已被初始化为空树 */
void InitializeTree(Tree * ptree);

/* 操作：确定树是否为空 */
/* 操作前：ptree指向一个树 */
/* 操作后：如果树为空则函数返回true, 否则返回false */
bool TreeIsEmpty(const Tree *ptree);

/* 操作：确认树是否已满 */
/* 操作前：ptree指向一个树 */
/* 操作后：如果树已满则函数返回true，否则返回false */
bool TreeIsFull(const Tree *ptree);

/* 操作：确认树中项目的个数 */
/* 操作前：ptree指向一个树 */
/* 操作后：函数返回树种项目的个数 */
int TreeItemCount(const Tree *ptree);

bool AddItem(const Item *pi, Tree *ptree);

bool InTree(const Item *pi, const Tree *ptree);

bool DeleteItem(const Item *pi, Tree *ptree);

void Traverse(const Tree *ptree, void (*pfun)(Item item));

void DeleteAll(Tree *ptree);


#endif // __TREE_H_
