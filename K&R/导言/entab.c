#include <stdio.h>

#define TABINC 8    // 设定每八个出现制表符

main(void)
{
    int c, nb, nt, pos;

    nb = 0;         // 需要的空白
    nt = 0;         // 需要的制表符
    for (pos = 1; (c = getchar()) != EOF; ++pos)
        if (c == ' ') {
            if (pos % TABINC != 0)
                ++nb;
            else {
                nb = 0;
                ++nt;
            }
        } else {
            for ( ; nt >0; --nt)
                putchar('\t');
            if (c == '\t')
                nb = 0;
            else
                for ( ; nb > 0; --nb)
                    putchar(' ');
            putchar(c);
            if (c == '\n')
                pos = 0;
            else if (c == '\t')
                pos = pos + (TABINC - (pos - 1) % TABINC) - 1;
        }
}
