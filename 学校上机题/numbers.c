#include <stdio.h>

int main(void)
{
    char str[100], *p, *q;
    int a[80] = {0}, i, j, counter, *num, bits, temp;

    /* 初始化计数器与位数计数器 */
    counter = 0;
    bits = 0;

    gets(str);
    p = q = str;
    num = a;

    do
    {
        if (*p >= '0' && *p <= '9')
            bits++;
        else if (bits == 0)
            q++;    /* 跳过连续的字母 */
        else
        {
            while (1)
            {
                temp = *q - '0';

                for (i = 1; i < bits; i++)
                    temp *= 10;
                *num += temp;
                q++;
                if (bits == 1)
                {
                    num++;
                    bits--;     /* 位数归零 */
                    counter++;
                    q++;    /* 与下一次p指针同步 */
                    break;
                }
                bits--;
            }
        }

        if (*p == '\0')
            break;

    } while (*p++);

    for (i = 0; i < counter; i++)
        printf("%d ", a[i]);
    printf("\nTotal: %d", counter);

    return 0;
}
