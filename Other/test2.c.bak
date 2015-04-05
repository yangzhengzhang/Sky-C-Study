#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char *tra(char str[]);
    char b[80], *p, c[80], d;
    gets(b);
    d = isarray(tra(b));
    strcpy(c, tra(b));
    p = tra(b);
    puts(c);
    printf("%c", tra(b)[2]);
    return 0;
}
char *tra(char str[])
{
    char stri[80];
    int i,j,k=0;
    i=strlen(str);
    for(j=0;j<=2*i-1;j=j+2)
    {
        stri[j]=str[k];
        stri[j+1]=' ';
        k++;
    }
    stri[j-1]='\0';
    return(stri);
}
