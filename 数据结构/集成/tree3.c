<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char Elem;

/* 树结构 */
typedef struct Tree
{
    struct Node *root;
//    int size;
} Tree;

/* 结点 */
typedef struct Node
{
    Elem elem;
    struct Node *left;
    struct Node *right;
} Node;

void InitTree(Tree *ptree, Node *node)
{
    ptree->root = node;
}

bool TreeIsEmpty(Tree *ptree)
{
    if (ptree->root == NULL)
        return false;
    else
        return true;
}

/*
void AddElem(Tree *ptree, ElemType elem)
{
    Node *new_node;

    new_node = MakeNode(elem);

    if (TreeIsEmpty(ptree))
    {
        ptree->root = new_node;
        ptree->size = 0;
    }
    else
    {
    }
}
*/

Node *CreateTree(Node *node)
{
    Elem elem;
    scanf("%c", &elem);     // 修改类型需修改此处

    if (elem != ' ')
    {
        node = (Node *)malloc(sizeof(Node));
        node->elem = elem;
        node->left = CreateTree(node->left);
        node->right = CreateTree(node->right);
    }
    else
    {
        node = NULL;
    }

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

void InOrder(Node *node, void (*visit)(Node *node))
{
    if (node)
    {
        InOrder(node->left, visit);
        visit(node);
        InOrder(node->right, visit);
    }
}

void PostOrder(Node *node, void (*visit)(Node *node))
{
    if (node)
    {
        PostOrder(node->left, visit);
        PostOrder(node->right, visit);
        visit(node);
    }
}

int CountLeaf(Node *node, int count)
{
    if (node)
    {
        if ((!node->left) && (!node->right))
        {
            return 1;
        }
        count = CountLeaf(node->left, count) + CountLeaf(node->right, count);
    }

    return count;
}

int Depth(Node *node)
{
    if (!node)
        return 0;
    else
        return max(Depth(node->left), Depth(node->right)) + 1;
}

Node *CreateNode(Elem elem, Node *left, Node *right)
{
    Node *node;

    node= (Node *)malloc(sizeof(Node));
    node->elem = elem;
    node->left = left;
    node->right = right;

    return node;
}

Node *CopyTree(Node *node)
{
    Node *newlptr, *newrptr;

    if (!node)
        return NULL;

    if (node->left)
        newlptr = CopyTree(node->left);
    else
        newlptr = NULL;

    if (node->right)
        newrptr = CopyTree(node->right);
    else
        newrptr = NULL;

    return CreateNode(node->elem, newlptr, newrptr);
}

Node *GetRightChild(Node *node)
{
    if (node)
        return node->right;
    else
        return NULL;
}

Node *GetLeftChild(Node *node)
{
    if (node)
        return node->left;
    else
        return NULL;
}

void DestroyTree(Node *node)
{
    if (node)
    {
        DestroyTree(node->left);
        DestroyTree(node->right);
        free(node);
    }
}

int SearchNode(Node *node, int status, Elem elem)
{
    if (!status && node)
    {
        status = (node->elem == elem);
        status = SearchNode(node->left, status, elem) || SearchNode(node->right, status, elem);
    }

    return status;
}

void Show(Node *node)
{
    printf("%c", node->elem);
}

int max(int a, int b)
{
    if (a < b)
        return b;
    else
        return a;
}

int main(void)
{
    Node *tree, *p;
    Tree *ptree = (Tree *)malloc(sizeof(Tree));
    Elem elem;
    char c;
    int quit = 0, searchResult = 0;

    printf("首先，先序输入一棵二叉树：");

    tree = CreateTree(tree);
    InitTree(ptree, tree);
    fflush(stdin);
    while (1)
    {
        printf("a.先序 b.中序 c.后序 d. 深度 e. 叶子数 f. 进入左子树 g. 进入右子树 h. 返回根节点 i. 删除左子树 j. 删除右子树 k. 搜索指定字符 q. 退出");
        printf("\n目前所在位置：%c\n", tree->elem);
        printf("输入一个命令：");
        c = getchar();
        fflush(stdin);
        switch (c)
        {
        case 'a':
            printf("先序：");
            PreOrder(tree, Show);
            putchar('\n');
            break;
        case 'b':
            printf("中序：");
            InOrder(tree, Show);
            putchar('\n');
            break;
        case 'c':
            printf("后序：");
            PostOrder(tree, Show);
            putchar('\n');
            break;
        case 'd':
            printf("Depth: %d\n", Depth(tree));
            break;
        case 'e':
            printf("Leaves: %d\n", CountLeaf(tree, 0));
            break;
        case 'f':
            if (!GetLeftChild(tree))
                printf("左边没有啦");
            else
                tree = GetLeftChild(tree);
            break;
        case 'g':
            if (!GetRightChild(tree))
                printf("右边没有啦");
            else
                tree = GetRightChild(tree);
            break;
        case 'h':
            tree = ptree->root;
            break;
        case 'i':
            DestroyTree(tree->left);
            tree->left = NULL;
            break;
        case 'j':
            DestroyTree(tree->right);
            tree->right = NULL;
            break;
        case 'k':
            printf("输入一个想要搜索的值：");
            searchResult = SearchNode(tree, 0, getchar());
            if (searchResult)
            {
                printf("Get!\n");
            }
            else
            {
                printf("404 Not Found\n");
            }
            fflush(stdin);
            break;
        case 'q':
            quit = 1;
            break;
        default:
            printf("请重新输入\n");

        }

        if (quit)
            break;
    }

    return 0;
}
=======
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char Elem;

/* 树结构 */
typedef struct Tree
{
    struct Node *root;
//    int size;
} Tree;

/* 结点 */
typedef struct Node
{
    Elem elem;
    struct Node *left;
    struct Node *right;
} Node;

void InitTree(Tree *ptree, Node *node)
{
    ptree->root = node;
}

bool TreeIsEmpty(Tree *ptree)
{
    if (ptree->root == NULL)
        return false;
    else
        return true;
}

/*
void AddElem(Tree *ptree, ElemType elem)
{
    Node *new_node;

    new_node = MakeNode(elem);

    if (TreeIsEmpty(ptree))
    {
        ptree->root = new_node;
        ptree->size = 0;
    }
    else
    {
    }
}
*/

Node *CreateTree(Node *node)
{
    Elem elem;
    scanf("%c", &elem);     // 修改类型需修改此处

    if (elem != ' ')
    {
        node = (Node *)malloc(sizeof(Node));
        node->elem = elem;
        node->left = CreateTree(node->left);
        node->right = CreateTree(node->right);
    }
    else
    {
        node = NULL;
    }

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

void InOrder(Node *node, void (*visit)(Node *node))
{
    if (node)
    {
        InOrder(node->left, visit);
        visit(node);
        InOrder(node->right, visit);
    }
}

void PostOrder(Node *node, void (*visit)(Node *node))
{
    if (node)
    {
        PostOrder(node->left, visit);
        PostOrder(node->right, visit);
        visit(node);
    }
}

int CountLeaf(Node *node, int count)
{
    if (node)
    {
        if ((!node->left) && (!node->right))
        {
            return 1;
        }
        count = CountLeaf(node->left, count) + CountLeaf(node->right, count);
    }

    return count;
}

int Depth(Node *node)
{
    if (!node)
        return 0;
    else
        return max(Depth(node->left), Depth(node->right)) + 1;
}

Node *CreateNode(Elem elem, Node *left, Node *right)
{
    Node *node;

    node= (Node *)malloc(sizeof(Node));
    node->elem = elem;
    node->left = left;
    node->right = right;

    return node;
}

Node *CopyTree(Node *node)
{
    Node *newlptr, *newrptr;

    if (!node)
        return NULL;

    if (node->left)
        newlptr = CopyTree(node->left);
    else
        newlptr = NULL;

    if (node->right)
        newrptr = CopyTree(node->right);
    else
        newrptr = NULL;

    return CreateNode(node->elem, newlptr, newrptr);
}

Node *GetRightChild(Node *node)
{
    if (node)
        return node->right;
    else
        return NULL;
}

Node *GetLeftChild(Node *node)
{
    if (node)
        return node->left;
    else
        return NULL;
}

void DestroyTree(Node *node)
{
    if (node)
    {
        DestroyTree(node->left);
        DestroyTree(node->right);
        free(node);
    }
}

int SearchNode(Node *node, int status, Elem elem)
{
    if (!status && node)
    {
        status = (node->elem == elem);
        status = SearchNode(node->left, status, elem) || SearchNode(node->right, status, elem);
    }

    return status;
}

void Show(Node *node)
{
    printf("%c", node->elem);
}

int max(int a, int b)
{
    if (a < b)
        return b;
    else
        return a;
}

int main(void)
{
    Node *tree, *p;
    Tree *ptree = (Tree *)malloc(sizeof(Tree));
    Elem elem;
    char c;
    int quit = 0, searchResult = 0;

    printf("首先，先序输入一棵二叉树：");

    tree = CreateTree(tree);
    InitTree(ptree, tree);
    fflush(stdin);
    while (1)
    {
        printf("a.先序 b.中序 c.后序 d. 深度 e. 叶子数 f. 进入左子树 g. 进入右子树 h. 返回根节点 i. 删除左子树 j. 删除右子树 k. 搜索指定字符 q. 退出");
        printf("\n目前所在位置：%c\n", tree->elem);
        printf("输入一个命令：");
        c = getchar();
        fflush(stdin);
        switch (c)
        {
        case 'a':
            printf("先序：");
            PreOrder(tree, Show);
            putchar('\n');
            break;
        case 'b':
            printf("中序：");
            InOrder(tree, Show);
            putchar('\n');
            break;
        case 'c':
            printf("后序：");
            PostOrder(tree, Show);
            putchar('\n');
            break;
        case 'd':
            printf("Depth: %d\n", Depth(tree));
            break;
        case 'e':
            printf("Leaves: %d\n", CountLeaf(tree, 0));
            break;
        case 'f':
            if (!GetLeftChild(tree))
                printf("左边没有啦");
            else
                tree = GetLeftChild(tree);
            break;
        case 'g':
            if (!GetRightChild(tree))
                printf("右边没有啦");
            else
                tree = GetRightChild(tree);
            break;
        case 'h':
            tree = ptree->root;
            break;
        case 'i':
            DestroyTree(tree->left);
            tree->left = NULL;
            break;
        case 'j':
            DestroyTree(tree->right);
            tree->right = NULL;
            break;
        case 'k':
            printf("输入一个想要搜索的值：");
            searchResult = SearchNode(tree, 0, getchar());
            if (searchResult)
            {
                printf("Get!\n");
            }
            else
            {
                printf("404 Not Found\n");
            }
            fflush(stdin);
            break;
        case 'q':
            quit = 1;
            break;
        default:
            printf("请重新输入\n");

        }

        if (quit)
            break;
    }

    return 0;
}
>>>>>>> a0e8d74199742fbdb78356ff34cbaa1198f5fe58
