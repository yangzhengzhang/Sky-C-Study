#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i, n, counter = 1, j;
    char str[100][10000], *p, *q, *t, num[1000], temp;

    scanf("%d", &n);
    getchar();

    for (i = 0; i < n; i++) {
        j = 0;
        while ((str[i][j++] = getchar()) != '\n')
        ;
        str[i][j - 1] = '\0';
        p = str[i];
        q = str[i];
        while (*p)
        {
            if (*p == *(p + 1)) {
                counter++;
            }
            else
            {
                temp = *p;

                if (counter > 1) {
                    sprintf(num, "%d", counter);
                    t = num;
                    while (*t) {
                        *(q++) = *(t++);
                    }
                }
                *(q++) = temp;
                counter = 1;
            }
            p++;
        }
        *(q++) = '\0';
    }

    for (i = 0; i < n; i++)
        puts(str[i]);

    return 0;
}
