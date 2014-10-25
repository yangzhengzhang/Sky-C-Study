#include <stdio.h>
#include <stdlib.h>

#define STACK_INIT_LENGTH 10

typedef char ElemType;

/* 定义顺序栈 */
struct stack {
    ElemType *buf;
    size_t elem_size;       // 单个元素大小
    size_t elem_count;      // 有多少个元素
    size_t buf_count;       // 缓冲区大小
};

/* 初始化栈 */
void InitStack(struct stack * s, size_t elem_size)
{
    s->elem_count = 0;
    s->elem_size = elem_size;
    s->buf_count = STACK_INIT_LENGTH;
    s->buf = (ElemType *)malloc(s->buf_count * elem_size);
}

/* 清空栈 */
void ClearStack(struct stack *s)
{
    free(s->buf);
}

/* 获取栈元素个数 */
size_t ElemCount(struct stack *s)
{
    return s->elem_count;
}

/* 重新分配大小 */
void SetStackSize(struct stack *s, size_t new_size)
{
    ElemType *new_buf = realloc(s->buf, new_size);
    if (!new_buf)
    {
        printf("Error: 内存重新分配失败。");
    }
    else
    {
        s->buf = new_buf;
        s->buf_count = new_size;
    }
}

/* 检查栈的大小 */
void CheckStackSize(struct stack *s)
{
    if (s->elem_count == s->buf_count)
    {
        SetStackSize(s, s->buf_count * 2);
    }
}

/* 存入栈内 */
void Push(struct stack *s, ElemType elem)
{
    CheckStackSize(s);
    ElemType *p = s->buf;
    size_t elem_count = s->elem_count;
    s->elem_count++;

    p[elem_count] = elem;
}

/* 从栈内弹出 */
void Pop(struct stack *s, size_t count)
{
    s->elem_count--;     // 现在的元素个数
}

/* 获取第num个元素的值 */
ElemType GetElem(struct stack s, size_t num)
{
    if (s.elem_count < num)
    {
        return -1;
    }
    return s.buf[num - 1];
}

void ShowAll(struct stack *s)
{
    size_t i;

    for (i = 0; i < s->elem_count; i++)
    {
        printf("%c ",s->buf[i]);
    }
}

int main(void)
{
    struct stack s;
    InitStack(&s, sizeof(char));
    Push(&s, 'c');
    Push(&s, 'd');
    ShowAll(&s);
    Pop(&s, 1);
    printf("%c", GetElem(s, 1));
    return 0;
}
