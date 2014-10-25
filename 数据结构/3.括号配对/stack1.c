#include <stdio.h>
#include <stdlib.h>

#define STACK_INIT_LENGTH 10

typedef char ElemType;

typedef struct Stack {
    ElemType *base;         // 栈底
    ElemType *top;          // 栈顶位置
    size_t stackSize;      // 开辟内存空间的大小
} Stack;

void InitStack(struct Stack *s)
{
    s->base = (ElemType *)malloc(STACK_INIT_LENGTH * sizeof(ElemType));
    s->top = s->base;
    s->stackSize = STACK_INIT_LENGTH;
}

void ClearStack(struct Stack *s)
{
    free(s->base);
}

size_t ElemCount(struct Stack *s)
{
    return (s->top - s->base);
}

void SetStackSize(struct Stack *s, size_t newSize)
{
    void *newBase = realloc(s->base, newSize);
    if (!newBase)
    {
        printf("Error: 内存重新分配失败。");
    }
    else
    {
        s->base = newBase;
        s->top = newBase + s->stackSize;
        s->stackSize = newSize;
    }
}

void CheckStackSize(struct Stack *s)
{
    if (s->stackSize == s->top - s->base)
    {
        SetStackSize(s, s->stackSize * 2);
    }
}

void Push(struct Stack *s, ElemType elem)
{
    CheckStackSize(s);
    *s->top++ = elem;
}

void Pop(struct Stack *s)
{
    if (s->base != s->top)
    {
        s->top--;
    }
}

ElemType GetElem(struct Stack *s, size_t num)
{
    if (num < s->top - s->base)
    {
        return s->base[num];
    }
    else
    {
        return -1;
    }
}

void ShowAll(struct Stack *s)
{
    size_t i;

    for (i = 0; i < s->top - s->base; i++)
    {
        printf("%c ",s->base[i]);
    }
}

int main(void)
{
    struct Stack s;
    InitStack(&s);
    Push(&s, 'c');
    Push(&s, 'd');
    ShowAll(&s);
    Pop(&s);
    printf("%c", GetElem(&s, 0));
    return 0;
}
