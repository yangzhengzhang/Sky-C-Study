#include <stdio.h>
#include <stdlib.h>

typedef int Elem;

typedef struct Node {
    struct Node * left;
    struct Node * right;
    struct Node * parent;

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
        visit(node);
        PreOrder(node->left, visit);
        PreOrder(node->right, visit);
    }
}

void Show(Node *node)
{
    printf("%d", node->value);
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
            printf("Now: i = %d\n", i);
            if (able[i])
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
        }
        printf("NodeCreateStart\n");
        if (!(nodeadr[minParent]->left))
        {
            nodeadr[minParent]->left = CreateNode(minNode, NULL, NULL, nodeadr[minParent], minCost);
            nodeadr[minNode] = nodeadr[minParent]->left;

        }
        else
        {
            nodeadr[minParent]->right = CreateNode(minNode, NULL, NULL, nodeadr[minParent], minCost);
            nodeadr[minNode] = nodeadr[minParent]->right;
        }
        printf("NodeCreateEnd\n");
        martix[minParent][minNode] = martix[minParent][minNode] = -1;
        able[minNode] = 1;
        printf("MinParent: %d to MinNode: %d\n", minParent, minNode);
    }
}

int able[100] = {0};
int martix[100][100];
Node *(nodeadr[100]);

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

    initPrimTree(martix, nodeNum, able, nodeadr);

    PreOrder(tree, Show);
    return 0;
}
