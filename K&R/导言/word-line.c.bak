#include <stdio.h>

#define IN 1
#define OUT 0

main(void)
{
    int c, state;

    state = OUT;    // 默认在单词外，进入else if 循环

    while ((c = getchar()) != EOF) {
        if (c == '\t' || c == ' ' || c == '\n') {
            // 如果前面的字符非空格（前面是一个单词），输出换行符
            if (state == IN) {
                printf("\n");
                state = OUT;
            }
        } else if (state == OUT) {  // 如果输入不是if条件的三个 并且前面用三个断行 则新的单词开始记录
            state = IN;
            putchar(c);
        } else  // state == IN 的情况 输出单词内的字符
            putchar(c);

    }

    return 0;
}
