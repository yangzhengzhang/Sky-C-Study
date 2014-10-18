#include <stdio.h>
#include <stdlib.h>

#define STACK_INIT_LENGTH 10

/* 定义顺序栈 */
struct stack {
    void *buf;
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
    s->buf = (void *)malloc(s->buf_count * elem_size);
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
    void *new_buf = realloc(s, new_size);
    if (!new_buf)
    {
        printf("Error: 内存重新分配失败。");
    }
    else
    {
        s->buf = new_buf;
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



int main(void)
{
    return 0;
}
