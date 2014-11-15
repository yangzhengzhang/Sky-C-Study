#include <stdio.h>
#include <stdlib.h>

typedef char TElemType;

typedef struct BiTNode
{
    TElemType data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
} BiTNode, *BiTree;

void Show(TElemType elem)
{
    printf("%c" , elem);
}

void Search(BiTree T, TElemType elem, int *tag)
{
    if (T && T->data != elem && !*tag)
    {
        Search(T->lchild, elem, tag);
        Search(T->rchild, elem, tag);
    }
    else if (T && T->data == elem)
    {
        return *tag = 1;
    }
}


/* 先序遍历 */
void Preorder(BiTree T, void(*visit)(TElemType elem))
{
    if (T)
    {
        visit(T->data);
        Preorder(T->lchild, visit);
        Preorder(T->rchild, visit);
    }
}

/* 中序遍历 */
void Inorder(BiTree T, void(*visit)(TElemType e))
{
    if (T)
    {
        Inorder(T->lchild, visit);
        visit(T->data);
        Inorder(T->rchild, visit);
    }
}


/* 后序遍历 */
void Postorder(BiTree T, void(*visit)(TElemType e))
{
    if (T)
    {
        Postorder(T->lchild, visit);
        Postorder(T->rchild, visit);
        visit(T->data);
    }
}

/* 统计二叉树中叶子节点的个数 */
void CountLeaf(BiTree T, int *count)
{
    if (T)
    {
        if((!T->lchild) && (!T->rchild))
        {
            ++(*count);
        }
        CountLeaf(T->lchild, count);
        CountLeaf(T->rchild, count);
    }
}

/* 计算深度 */
int Depth(BiTree T, int depthval)
{
    if (!T)
    {
        depthval = 0;
    }
    else
    {
        depthval = 1 + max(Depth(T->lchild, depthval), Depth(T->rchild, depthval));

    }
    return depthval;
}

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

/* 新建节点 */
BiTNode *GetTreeNode(TElemType item, BiTNode *lptr, BiTNode *rptr)
{
    BiTNode *T;
    T = (BiTNode *)malloc(sizeof(BiTNode));
    T->data = item;
    T->lchild = lptr;
    T->rchild = rptr;
    return T;
}

/* 复制树 */
BiTNode *CopyTree(BiTNode *T)
{
    BiTNode *newlptr;
    BiTNode *newrptr;
    BiTree newT;
    if (!T)
    {
        return NULL;
    }

    if (T->lchild)
    {
        newlptr = CopyTree(T->lchild);
    }
    else
    {
        newlptr = NULL;
    }

    if (T->rchild)
    {
        newrptr = CopyTree(T->rchild);
    }
    else
    {
        newrptr = NULL;
    }

    newT = GetTreeNode(T->data, newlptr, newrptr);
    return newT;
}

BiTree CreateBiTree(BiTree T)
{
    TElemType elem;
    scanf("%c", &elem);

    if (elem == ' ')
    {
        T = NULL;
    }
    else
    {
        T = (BiTNode *)malloc(sizeof(BiTNode));

        T->data = elem;
        T->lchild = CreateBiTree(T->lchild);
        T->rchild = CreateBiTree(T->rchild);
    }
    return T;
}


int main(void)
{
    BiTree T, Tcopy;
    int tag = 0;
    int count = 0;
    T = CreateBiTree(T);
    printf("先序：");
    Preorder(T, Show);
    printf("\n中序：");
    Inorder(T, Show);
    printf("\n后序：");
    Postorder(T, Show);
    printf("\n计算深度：");
    printf("%d ", Depth(T, count));
    printf("\n叶子数：");
    CountLeaf(T, &count);
    printf("%d\n", count);
    printf("复制树中...\n");
    Tcopy = CopyTree(T);
    printf("复制树先序：");
    Preorder(T, Show);
    getchar();
    printf("\n输入一个字符，我来搜索：");
    Search(T, getchar(), &tag);
    if (tag)
    {
        printf("Get!");
    }
    else
    {
        printf("404 Not Found");
    }

    return 0;
}
