#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct Node {
    ElemType data;
    struct Node *left, *right;
} Node, *Tree;

Node * CreateNode(ElemType data, Node *left, Node *right)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->left = NULL;
    node->right = NULL;
    node->data = data;
    return node;
}

int SearchBST(Tree T, ElemType key, Node **result, Node **parent)
{
    if (!T)
    {
        printf("找到尽头\n");
        *result = *parent;
        return 0;
    }
    else if (T->data == key)
    {
        *result = T;
        return 1;
    }
    else if (key < T->data)
    {
        printf("所在位置：%d 展开左子树查找\n", T->data);
        return SearchBST(T->left, key, result, &T);
    }
    else
    {
        printf("所在位置：%d 展开右子树查找\n", T->data);
        return SearchBST(T->right, key, result, &T);
    }
}

void InsertNode(Tree *T, int key)
{
    Node *result = NULL;
    Node *parent = NULL;
    printf("正在检索位置\n");
    if (!SearchBST(*T, key, &result, &parent))
    {
        if (!result)
        {
            printf("结果为空树，努力添加中\n");
            *T = CreateNode(key, NULL, NULL);
        }
        else if (key < result->data)
        {
            printf("比较小，正在添加到左子树\n");
            result->left = CreateNode(key, NULL, NULL);
        }
        else
        {
            printf("比较大，正在添加到右子树\n");
            result->right = CreateNode(key, NULL, NULL);
        }
    }
}

void DeleteNode(Tree *T, ElemType key)
{
    if (!*T)
    {
        return;
    }
    else if (key == (*T)->data)
    {
        printf("%d 搜索成功 开始删除\n", key);
        Delete(T);
    }
    else if (key < (*T)->data)
    {
        printf("%d 正在展开左子树 准备进一步删除\n", (*T)->data);
        DeleteNode(&((*T)->left), key);
    }
    else
    {
        printf("%d 正在展开右子树 准备进一步删除\n", (*T)->data);
        DeleteNode(&((*T)->right), key);
    }
}

void Delete(Tree *T)
{
    Node *p, *q;
    if (!(*T)->right)     // 没有右子树
    {
        printf("没有右子树，开始努力删除");
        p = *T;
        *T = (*T)->left;
        free(p);
    }
    else if (!(*T)->left) // 有右子树没有左子树
    {
        printf("有右子树，开始努力删除");
        p = *T;
        *T = (*T)->right;
        free(p);
    }
    else
    {
        printf("什么都有，努力删除中\n");
        p = *T;
        q = (*T)->left;
        while (q->right)
        {
            printf("目前所在位置：%d\n", q->data);
            p = q;
            q = q->right;
        }
        (*T)->data = q->data;
        printf("查找完毕\n");
        if (p != *T)
            p->right = q->left;
        else
            p->left = q->left;

        free(q);
    }
}

void AverageDepth(Tree T, size_t depth, size_t *totalDepth, size_t *counter)
{
    if (T)
    {
        printf("目前深度：%d\n", depth);
        (*counter)++;
        (*totalDepth) += depth;
        AverageDepth(T->left, depth + 1, totalDepth, counter);
        AverageDepth(T->right, depth + 1, totalDepth, counter);
    }
}

void PrintTree(Tree T)
{
    if (T)
    {
        printf("%d ", T->data);
        PrintTree(T->left);
        PrintTree(T->right);
    }
}

int main(void)
{
    Tree T = NULL;
    ElemType data;
    size_t totalDepth, counter;
    while(1)
    {
        if (scanf("%d", &data))
        {
            totalDepth = 0;
            counter = 0;
            if (data > 0)
            {
                printf("开始添加结点\n");
                InsertNode(&T, data);
            }
            else if (data < 0)
            {
                printf("开始删除结点\n");
                DeleteNode(&T, -data);
            }
            else
            {
                break;
            }
            printf("开始输出\n");
            // printf("根节点：%d\n", T);
            AverageDepth(T, 1, &totalDepth, &counter);
            printf("平均查找长度：%f\n", totalDepth/(double)counter);
            PrintTree(T);
            putchar('\n');
        }
    }
    printf("感谢使用 Press any key to continue...\n");
    getchar();
    getchar();
    return 0;
}
