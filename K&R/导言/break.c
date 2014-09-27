#include <stdio.h>

#define MAXCOL 10   // 最大输入列
#define TABINC 8

char line[MAXCOL];  // 输入列

int exptab(int pos);
int findblnk(int pos);
int newpos(int pos);
void printl(int pos);

// 折叠长的输入行变为两行或更短的行
main(void)
{
    int c, pos;

    pos = 0;    // 行中字符的位置
    while ((c = getchar()) != EOF) {
        line[pos] = c;  // 储存现在的字符
        if (c == '\t')  //
            pos = exptab(pos);
        else if (c == '\n') {
            printl(pos);    // 输出目前输入行
            pos = 0;
        } else if (++pos >= MAXCOL) {
            pos = findblnk(pos);
            printl(pos);
            pos = newpos(pos);
        }
    }
}

// printl函数：输出行直到目前位置
void printl(int pos)
{
    int i;
    for (i = 0; i < pos; ++i)
        putchar(line[i]);
    if (pos > 0)    // 有字符输出吗？
        putchar('\n');
}

int exptab(int pos)
{
    line[pos] = " ";    // 制表符是至少一个空格
    for (++pos; pos < MAXCOL && pos % TABINC != 0; ++pos)
        line[pos] = ' ';
    if (pos < MAXCOL)
        return pos;     // 现在的行已满
    else {
        printl(pos);
        return 0;   // 重置现在的位置
    }
}

// findblnk函数：找到空格的位置
int findblnk(int pos)
{
    while (pos > 0 && line[pos] != ' ')
        --pos;
    if (pos == 0)   // 这行没有空格？
        return MAXCOL;
    else            // 至少一行
        return pos+1;   // 空格之后的位置
}

int newpos(int pos)
{
    int i, j;

    if (pos <= 0 || pos >= MAXCOL)
        return 0;   // 无需重新排列
    else {
        i = 0;
        for (j = pos; j < MAXCOL; ++j) {
            line[i] = line[j];
            ++i;
        }
        return i;   // 新的位置
    }
}
