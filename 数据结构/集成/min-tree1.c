<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>

typedef int Elem;

typedef struct Node {
    struct Node * left;     // addr1
    struct Node * right;    // addr2
    struct Node * parent;   // addr3

    int costToParent;
    Elem value;
} Node;

struct Node *CreateNode(Elem value, Node *left, Node *right, Node *parent, int costToParent)
{
    struct Node *node;

    node = (Node *)malloc(sizeof(Node));
    node->value = value;
    node->left = left;
    node->right = right;
    node->parent = parent;
    node->costToParent = costToParent;

    return node;
}

void PreOrder(Node *node, void (*visit)(Node *node))
{
    if (node)
    {
//        printf("Now: %d\n", node);
        visit(node);
        PreOrder(node->left, visit);
        PreOrder(node->right, visit);
    }
}

void Show(Node *node)
{
//    printf("%d:", node);
    if (node->parent)
    {
        printf("%d -> %d \n", node->parent->value, node->value);
    }
    else
    {
        printf("%d \n", node->value);
    }
}

void Show2(Node *node)
{
    printf("%d ", node->value);
}

void inputNodes(int martix[100][100], int n) {
    int i, j;
    int num;    // 权值

    for (i = 0; i < n; i++)
    {
        for (j = 0; j <= i; j++)
        {
            scanf("%d", &num);
            martix[i][j] = num;
            martix[j][i] = num;
        }
    }
}

void initPrimTree(int martix[100][100], int n, int *able, Node *(nodeadr[100]))
{
    int i, j, k;
    int minCost, minParent, minNode;
    int ableCount = n;
    while (--ableCount)
    {
        minCost = 65535;
        for (i = 0; i < n; i++)
        {
 //           printf("Now: i = %d\n", i);
            if (able[i])
            {
                for (j = 0; j < n; j++)
                {

                    if (martix[i][j] < minCost && martix[i][j] > 0 && !able[j])
                    {
                        minCost = martix[i][j];
                        minParent = i;
                        minNode = j;
                    }
                }
            }
        }
//        printf("NodeCreateStart\n");
        if (!(nodeadr[minParent]->left))
        {
            nodeadr[minParent]->left = CreateNode(minNode, NULL, NULL, nodeadr[minParent], minCost);
            nodeadr[minNode] = nodeadr[minParent]->left;
        }
        else
        {
            Node *p = nodeadr[minParent]->left;
            while (p->right)
            {
                p = p->right;
            }

            p->right = CreateNode(minNode, NULL, NULL, nodeadr[minParent], minCost);
            nodeadr[minNode] = p->right;
        }
//        printf("NodeCreateEnd\n");
        martix[minParent][minNode] = martix[minNode][minParent] = -1;
        able[minNode] = 1;
        printf("MinParent: %d to MinNode: %d, MinCost: %d\n", minParent, minNode, minCost);
    }
}

void initKruskalTree(int martix[100][100], int *able, int n, Node *(nodeadr[100]))
{
    int i, j, k;
    int minCost, minParent, minNode;
    int ableCount = n - 1;
    while (--ableCount)
    {
        minCost = 65535;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (martix[i][j] < minCost && martix[i][j] > 0)
                {
                    minCost = martix[i][j];
                    minParent = i;
                    minNode = j;
                }
            }
        }

        if (nodeadr[minParent])
            nodeadr[minParent] = CreateNode(minParent, NULL, NULL, NULL, -1);

        if (nodeadr[minNode])
            nodeadr[minNode] = CreateNode(minNode, NULL, NULL, NULL, -1);

        if (!nodeadr[minParent]->left)
            nodeadr[minParent]->left = nodeadr[minNode];
        else if (!nodeadr[minParent]->right)
            nodeadr[minParent]->right = nodeadr[minNode];
        else if (!nodeadr[minParent]->parent)
            nodeadr[minParent]->parent = nodeadr[minNode];
        else
            printf("Something wrong");

        if (!nodeadr[minNode]->left)
            nodeadr[minNode]->left = nodeadr[minParent];
        else if (!nodeadr[minNode]->right)
            nodeadr[minNode]->right = nodeadr[minParent];
        else if (!nodeadr[minNode]->parent)
            nodeadr[minNode]->parent = nodeadr[minParent];
        else
            printf("Something wrong");
    }
}

int checkRound(Node *addr, int found, Node *target, Node *pre)
{
    if (!addr && !found)
    {
        if (addr == target)
            found = 1;
        else
        {
            if (addr->left == pre)
            {
                pre = addr;
                found = checkRound(addr->parent, found, target, pre) + checkRound(addr->right, found, target, pre);
            }
            else if (addr->right == pre)
            {
                pre = addr;
                found = checkRound(addr->left, found, target, pre) + checkRound(addr->parent, found, target, pre);
            }
            else
            {
                pre = addr;
                found = checkRound(addr->left, found, target, pre) + checkRound(addr->right, found, target, pre);
            }

        }
    }

    return found;
}

int able[100] = {0};
int martix[100][100];
Node *(nodeadr[100]) = {NULL};

int main(void)
{
    int nodeNum;    // 点的个数

    printf("请输入节点的个数：");
    scanf("%d" , &nodeNum);
    printf("请输入无序图邻接矩阵[<0为不可达，对角线应该都为0]\n");
    inputNodes(martix, nodeNum);

    Node *tree = CreateNode(0, NULL, NULL, NULL, -1);
    Node *root = tree;
    able[0] = 1;
    nodeadr[0] = tree;

    printf("初始化创建过程：\n");
    initPrimTree(martix, nodeNum, able, nodeadr);
    printf("初始化完毕，先序输出中...\n");
    PreOrder(tree, Show);
    PreOrder(tree, Show2);

    return 0;
}
=======
#include <stdio.h>
#include <stdlib.h>

typedef int Elem;

typedef struct Node {
    struct Node * left;     // addr1
    struct Node * right;    // addr2
    struct Node * parent;   // addr3

    int costToParent;
    Elem value;
} Node;

struct Node *CreateNode(Elem value, Node *left, Node *right, Node *parent, int costToParent)
{
    struct Node *node;

    node = (Node *)malloc(sizeof(Node));
    node->value = value;
    node->left = left;
    node->right = right;
    node->parent = parent;
    node->costToParent = costToParent;

    return node;
}

void PreOrder(Node *node, void (*visit)(Node *node))
{
    if (node)
    {
//        printf("Now: %d\n", node);
        visit(node);
        PreOrder(node->left, visit);
        PreOrder(node->right, visit);
    }
}

void Show(Node *node)
{
//    printf("%d:", node);
    if (node->parent)
    {
        printf("%d -> %d \n", node->parent->value, node->value);
    }
    else
    {
        printf("%d \n", node->value);
    }
}

void Show2(Node *node)
{
    printf("%d ", node->value);
}

void inputNodes(int martix[100][100], int n) {
    int i, j;
    int num;    // 权值

    for (i = 0; i < n; i++)
    {
        for (j = 0; j <= i; j++)
        {
            scanf("%d", &num);
            martix[i][j] = num;
            martix[j][i] = num;
        }
    }
}

void initPrimTree(int martix[100][100], int n, int *able, Node *(nodeadr[100]))
{
    int i, j, k;
    int minCost, minParent, minNode;
    int ableCount = n;
    while (--ableCount)
    {
        minCost = 65535;
        for (i = 0; i < n; i++)
        {
 //           printf("Now: i = %d\n", i);
            if (able[i])
            {
                for (j = 0; j < n; j++)
                {

                    if (martix[i][j] < minCost && martix[i][j] > 0 && !able[j])
                    {
                        minCost = martix[i][j];
                        minParent = i;
                        minNode = j;
                    }
                }
            }
        }
//        printf("NodeCreateStart\n");
        if (!(nodeadr[minParent]->left))
        {
            nodeadr[minParent]->left = CreateNode(minNode, NULL, NULL, nodeadr[minParent], minCost);
            nodeadr[minNode] = nodeadr[minParent]->left;
        }
        else
        {
            Node *p = nodeadr[minParent]->left;
            while (p->right)
            {
                p = p->right;
            }

            p->right = CreateNode(minNode, NULL, NULL, nodeadr[minParent], minCost);
            nodeadr[minNode] = p->right;
        }
//        printf("NodeCreateEnd\n");
        martix[minParent][minNode] = martix[minNode][minParent] = -1;
        able[minNode] = 1;
        printf("MinParent: %d to MinNode: %d, MinCost: %d\n", minParent, minNode, minCost);
    }
}

void initKruskalTree(int martix[100][100], int *able, int n, Node *(nodeadr[100]))
{
    int i, j, k;
    int minCost, minParent, minNode;
    int ableCount = n - 1;
    while (--ableCount)
    {
        minCost = 65535;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (martix[i][j] < minCost && martix[i][j] > 0)
                {
                    minCost = martix[i][j];
                    minParent = i;
                    minNode = j;
                }
            }
        }

        if (nodeadr[minParent])
            nodeadr[minParent] = CreateNode(minParent, NULL, NULL, NULL, -1);

        if (nodeadr[minNode])
            nodeadr[minNode] = CreateNode(minNode, NULL, NULL, NULL, -1);

        if (!nodeadr[minParent]->left)
            nodeadr[minParent]->left = nodeadr[minNode];
        else if (!nodeadr[minParent]->right)
            nodeadr[minParent]->right = nodeadr[minNode];
        else if (!nodeadr[minParent]->parent)
            nodeadr[minParent]->parent = nodeadr[minNode];
        else
            printf("Something wrong");

        if (!nodeadr[minNode]->left)
            nodeadr[minNode]->left = nodeadr[minParent];
        else if (!nodeadr[minNode]->right)
            nodeadr[minNode]->right = nodeadr[minParent];
        else if (!nodeadr[minNode]->parent)
            nodeadr[minNode]->parent = nodeadr[minParent];
        else
            printf("Something wrong");
    }
}

int checkRound(Node *addr, int found, Node *target, Node *pre)
{
    if (!addr && !found)
    {
        if (addr == target)
            found = 1;
        else
        {
            if (addr->left == pre)
            {
                pre = addr;
                found = checkRound(addr->parent, found, target, pre) + checkRound(addr->right, found, target, pre);
            }
            else if (addr->right == pre)
            {
                pre = addr;
                found = checkRound(addr->left, found, target, pre) + checkRound(addr->parent, found, target, pre);
            }
            else
            {
                pre = addr;
                found = checkRound(addr->left, found, target, pre) + checkRound(addr->right, found, target, pre);
            }

        }
    }

    return found;
}

int able[100] = {0};
int martix[100][100];
Node *(nodeadr[100]) = {NULL};

int main(void)
{
    int nodeNum;    // 点的个数

    printf("请输入节点的个数：");
    scanf("%d" , &nodeNum);
    printf("请输入无序图邻接矩阵[<0为不可达，对角线应该都为0]\n");
    inputNodes(martix, nodeNum);

    Node *tree = CreateNode(0, NULL, NULL, NULL, -1);
    Node *root = tree;
    able[0] = 1;
    nodeadr[0] = tree;

    printf("初始化创建过程：\n");
    initPrimTree(martix, nodeNum, able, nodeadr);
    printf("初始化完毕，先序输出中...\n");
    PreOrder(tree, Show);
    PreOrder(tree, Show2);

    return 0;
}
>>>>>>> a0e8d74199742fbdb78356ff34cbaa1198f5fe58
