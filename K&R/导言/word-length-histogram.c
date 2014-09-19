/*
#include <stdio.h>

main(void)
{
    int c, i, word;
    int ndigit[999];    //  ndigit记录这是第几个单词

    for (i = 0; i < 999; i++)
        ndigit[i] = 0;

    word = 0;

    while ((c = getchar()) != EOF) {
        if (c != ' ' && c != '\n' && c != '\t') {
            putchar(c);
            ++ndigit[word];
        } else {
            for (i = 0; i < ndigit[word]; i++)
                printf("▅");
            printf("\twords:%d",ndigit[word]);
            printf("\n");
            word++;
        }

    }

    return 0;
}
*/
/*
 * 水平直方图
#include <stdio.h>

#define MAXHIST 15  // 直方图的最大长度
#define MAXWORD 11  // 单词最大长度
#define IN 1
#define OUT 0

main(void)
{
    int c, i, nc, state;
    int len;        // 每个直方长度
    int maxvalue;    // 单词的最大值
    int ovflow;     //  溢出单词的个数
    int wl[MAXWORD]; // 单词长度统计

    state = OUT;
    nc = 0;         // 单词中的字符数;
    ovflow= 0;     // 单词 >= 最大单词 的个数
    for (i = 0; i < MAXWORD; ++i)
        wl[i] = 0;  // 设定初值
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
            // 单词结束 开始统计字符数
            if (nc > 0)
                if (nc < MAXWORD)
                    ++wl[nc];
                else
                    ++ovflow;
            nc = 0;
        } else if (state == OUT) {
            state = IN;
            nc = 1;     // 新的一个单词开始计数
        } else
            ++nc;       // 单词计数
    }
    // 找出最大值
    maxvalue = 0;
    for (i = 1; i < MAXWORD; ++i)
        if (wl[i] > maxvalue)
            maxvalue = wl[i];

    for (i = 1; i < MAXWORD; ++i) {
        printf("%5d - %5d : ", i, wl[i]);   // 字符数 - 单词个数
        if (wl[i] > 0) {
            // 1 设定len的长度 2 如果len存在但过小会被舍去小数部分，故判断手动改为1
            if ((len = wl[i] * MAXHIST / maxvalue) <= 0)
                len = 1;
        } else
            len = 0;    // 如果遍历时为0
        while (len > 0) {
            putchar('*');   // 用 * 占位
            --len;
        }

        putchar('\n');
    }

    // 对超过限值的单词进行报告
    if (ovflow > 0)
        printf("There are %d words >= %d\n", ovflow, MAXWORD);
}
*/

#include <stdio.h>

#define MAXHIST 15
#define MAXWORD 11
#define IN 1
#define OUT 0

main(void)
{
    int c, i, j, nc, state;
    int maxvalue;       // 数组wl[]的最大值
    int ovflow;         // 超过最大长度的单词书
    int wl[MAXWORD];    // 单词长度计数

    state = OUT;
    nc = 0;             // 一个单词中的字符数量
    ovflow = 0;         // words >= MAXWORD 的数量
    for (i = 0; i < MAXWORD; ++i)
        wl[i] = 0;      // 给单词长度设定初值
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
            if (nc > 0)
                if (nc < MAXWORD)
                    ++wl[nc];
                else
                    ++ovflow;
            nc = 0;
        } else if (state == OUT) {
            state = IN;
            nc = 1;
        } else
            ++nc;
    }
    maxvalue = 0;
    for (i = 1; i < MAXWORD; ++i)
        if (wl[i] > maxvalue)
            maxvalue = wl[i];

    for (i = MAXHIST; i > 0; --i) {     // 列数（从最大依次递减）
        for (j = 1; j < MAXWORD; ++j)   // 行数
        // i从最大值开始 如果满足这一行条件（> i） 则输出 * MAXHIST / maxvalue相当于设定百分比
            if (wl[j] * MAXHIST / maxvalue >= i)
                printf("%4c", '*');
            else
                printf("%4c", ' ');
            putchar('\n');
    }
    for (i = 1; i < MAXWORD; ++i)
        printf("%4d", i);
    putchar('\n');
    for (i = 1; i < MAXWORD; ++i)
        printf("%4d", wl[i]);
    putchar('\n');
    if (ovflow > 0)
        printf("There are %d words >= %d\n", ovflow, MAXWORD);

    return 0;
}
