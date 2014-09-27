#include <stdio.h>

void rcomment(int c);
void in_comment(void);
void echo_quote(int c);

/* 移除所有注释 */
main(void)
{
    int c, d;

    while ((c = getchar()) != EOF)
        rcomment(c);
    return 0;
}

/* 阅读每个字节，移除注释 */
void rcomment(int c)
{
    int d;

    if (c == '/')
        if ((d = getchar()) == '*')
            in_comment();       /* 开始注释 */
        else if (d == '/') {
            putchar(c);             /* 另一个斜杠 */
            rcomment(d);
        } else {
            putchar(c);             /* 不是注释 */
            putchar(d);
        }
    else if (c == '\'' || c == '"')     /* 引号中的内容原样输出 */
        echo_quote(c);      /* 引用开始 */
    else
        putchar(c);     /* 不是注释 */
}

/* in_comment函数：在一个有效的注释内 */
void in_comment(void)
{
    int c, d;
    c = getchar();  /* 上一个字节 */
    d = getchar();  /* 所在的字节 */
    while (c != '*' || d != '/') {  /* 搜索结束标志 */
        c = d;
        d = getchar();
    }
}

/* echo_quote函数：每个函数内的字符 */
void echo_quote(int c)
{
    int d;

    putchar(c);
    while ((d = getchar()) != c) {  /* 搜索结束标志 */
        putchar(d);
        if (d == '\\')
            putchar(getchar());
    }
    putchar(d);
}
