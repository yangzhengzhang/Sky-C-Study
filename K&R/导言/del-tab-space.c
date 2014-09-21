#include <stdio.h>

#define MAXLINE 1000

int getline(char line[], int maxline);
int removethis(char s[]);

main(void)
{
    char line[MAXLINE];

    while (getline(line, MAXLINE) > 0)
        if (removethis(line) > 0)
            printf("%s", line);
    return 0;
}

int getline(char s[], int lim)
{
    int c, i, j;

    j = 0;
    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
        if (i < lim -2) {
            s[j] = c;
            ++j;
        }

    if (c == '\n') {
        s[j] = c;
        ++i;
        ++j;
    }
    s[j] = '\0';
    return i;
}

int removethis(char s[])
{
    int i;

    // 如果不是换行符 则循环至遇到换行符
    while (s[i] != '\n')
        ++i;
    // 检查换行符前一个
    --i;
    while (i >= 0 && (s[i] == ' ' || s[i] == '\t'))
        --i;
    // 如果存在上面的情况 上面的情况覆盖为换行符，否则不变化（换行符覆盖为换行符），然后追加空字符
    if (i >= 0) {
        ++i;
        s[i] = '\n';
        ++i;
        s[i] = '\0';
    }
    return i;
}
