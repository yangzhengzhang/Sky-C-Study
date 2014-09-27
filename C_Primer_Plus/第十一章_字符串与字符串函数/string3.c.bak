#include <stdio.h>
#include <ctype.h>

void word(char *p);

int main(void)
{
    char a[81];

    puts("input your string: ");
    gets(a);
    word(a);
    puts(a);

    return 0;
}

void word(char *p)
{
    int begin, end;

    for (begin = 0; isspace( *(p + begin) ); begin++)
        continue;
    for (end = begin; !isspace( *(p + end) ) ; end++)
        continue;
    *(p + end) = '\0';
    for (; *(p + begin) != '\0'; p++)
        *p = * (p + begin);
    *p = '\0';
}
