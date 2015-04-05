#include <stdio.h>

#define TABINC 8    // 每隔8个位置出现TAB

main(void)
{
    int c, nb, pos;

    nb = 0;     // 所需的空白数量
    pos = 1;    // 行中字符的位置
    while ((c = getchar()) != EOF) {
        if (c == '\t') {    // 制表符
            nb = TABINC - (pos - 1) % TABINC;
            while (nb > 0) {
                putchar(' ');
                ++pos;
                --nb;
            }
        } else if (c == '\n') {     // 换行符
            putchar(c);
            pos = 1;
        } else {        // 其他全部字符
            putchar(c);
            ++pos;
        }
    }
}
