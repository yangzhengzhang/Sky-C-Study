<<<<<<< HEAD
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node{
    unsigned int weight;
    struct node * parent, *left, *right, *next;
} Node;

Node * CreateNode(int weight)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->parent = NULL;
    node->left = NULL;
    node->right = NULL;
    node->weight = weight;
    node->next = NULL;
    return node;
}

void SelectTwo(Node *head, Node **small1, Node **small2)
{
    int m1 = 32767, m2 = 32767;
    Node *p = head->next;
    Node *p1 = NULL, *p2 = NULL;

    while (p)
    {
        if (p->parent)
        {
            p = p->next;
            continue;
        }
        if (p->weight <= m1)
        {
            p2 = p1;
            m2 = m1;
            p1 = p;
            m1 = p->weight;
        }
        else if (p->weight < m2)
        {
            p2 = p;
            m2 = p->weight;
        }
        p = p->next;
    }

    *small1 = p1;
    *small2 = p2;
}

void DepthLoop(Node *current, char *add, int depth)
{
    if (current)
    {
        Output(current, add);
        *(add+depth) = '0';
        *(add+depth+1) = '\0';
        DepthLoop(current->left, add, depth + 1);
        *(add+depth) = '1';
        *(add+depth+1) = '\0';
        DepthLoop(current->right, add, depth + 1);
    }
}

void HafumanTree(Node *head, Node **tail)
{
    Node *p1, *p2, *p;
    while (1)
    {
        SelectTwo(head, &p1, &p2);
        if (!(p1 && p2))
            break;
        p = CreateNode(p1->weight + p2->weight);
        p1->parent = p;
        p2->parent = p;
        p->left = p1;
        p->right = p2;
        (*tail)->next = p;
        *tail = p;
    }
}

void Output(Node *current,char* add)
{
	if (current->left||current->right)
        return;
	printf("%d: %s\n",current->weight,add);
}

int main(void)
{
	Node *head = NULL, *p, *q, *tail;
    head = CreateNode(0);
    p = head;
    int n;
    printf("输入一串数字（权重） <=0 时结束\n");
    scanf("%d", &n);
    while (n > 0)
    {
        q = CreateNode(n);
        p->next = q;
        p = q;
        scanf("%d",&n);
    }
    tail=p;
    HafumanTree(head, &tail);
    char path[100];
    DepthLoop(tail, path, 0);
    return 0;
}
=======
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node{
    unsigned int weight;
    struct node * parent, *left, *right, *next;
} Node;

Node * CreateNode(int weight)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->parent = NULL;
    node->left = NULL;
    node->right = NULL;
    node->weight = weight;
    node->next = NULL;
    return node;
}

void SelectTwo(Node *head, Node **small1, Node **small2)
{
    int m1 = 32767, m2 = 32767;
    Node *p = head->next;
    Node *p1 = NULL, *p2 = NULL;

    while (p)
    {
        if (p->parent)
        {
            p = p->next;
            continue;
        }
        if (p->weight <= m1)
        {
            p2 = p1;
            m2 = m1;
            p1 = p;
            m1 = p->weight;
        }
        else if (p->weight < m2)
        {
            p2 = p;
            m2 = p->weight;
        }
        p = p->next;
    }

    *small1 = p1;
    *small2 = p2;
}

void DepthLoop(Node *current, char *add, int depth)
{
    if (current)
    {
        Output(current, add);
        *(add+depth) = '0';
        *(add+depth+1) = '\0';
        DepthLoop(current->left, add, depth + 1);
        *(add+depth) = '1';
        *(add+depth+1) = '\0';
        DepthLoop(current->right, add, depth + 1);
    }
}

void HafumanTree(Node *head, Node **tail)
{
    Node *p1, *p2, *p;
    while (1)
    {
        SelectTwo(head, &p1, &p2);
        if (!(p1 && p2))
            break;
        p = CreateNode(p1->weight + p2->weight);
        p1->parent = p;
        p2->parent = p;
        p->left = p1;
        p->right = p2;
        (*tail)->next = p;
        *tail = p;
    }
}

void Output(Node *current,char* add)
{
	if (current->left||current->right)
        return;
	printf("%d: %s\n",current->weight,add);
}

int main(void)
{
	Node *head = NULL, *p, *q, *tail;
    head = CreateNode(0);
    p = head;
    int n;
    printf("输入一串数字（权重） <=0 时结束\n");
    scanf("%d", &n);
    while (n > 0)
    {
        q = CreateNode(n);
        p->next = q;
        p = q;
        scanf("%d",&n);
    }
    tail=p;
    HafumanTree(head, &tail);
    char path[100];
    DepthLoop(tail, path, 0);
    return 0;
}
>>>>>>> a0e8d74199742fbdb78356ff34cbaa1198f5fe58
