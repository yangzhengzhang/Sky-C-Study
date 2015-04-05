#include <stdio.h>

int main(void)
{
    int i;
    char ascii;
    i = 1;
    ascii = 'A';

    printf("        结果为\n");
    printf("char dec    oct    hex      char dec    oct    hex      char dec    oct    hex\n");

    while (ascii <= 'Z') {
        if (i % 3 != 0)
            printf(" %c---%d-----%o-----%x      ", ascii, ascii, ascii, ascii);
        else
            printf(" %c---%d-----%o-----%x\n", ascii, ascii, ascii, ascii);
        ascii++;
        i++;
    }
    return 0;
}
