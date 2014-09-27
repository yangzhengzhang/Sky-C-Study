#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    int N, i, j, input = 0;
    char name[200][50], (*p)[50], (*q)[50];

    scanf("%d", &N);
    getchar();

    for (i = 0; i < N; i++)
    {
        gets(name[i]);
        input++;
    }

    for (i = 0, j = 0; i < input; i++)
    {
        for (p = q = name + i; p < name + input; p++)
        {
            if ( !strcmp( tolower(*name + i + j), tolower(*p)) )
            {
                strcpy(*q + j, *p);
                j++;
            }
            else
                input--;
            printf("%s\n", *p);
            printf("%s\n", *q + j - 1);
        }
    }


    printf("%d\n", input);


    for ( ; q < name + input; q++)
    {
        printf("%s\n", *q);
    }

    return 0;
}
