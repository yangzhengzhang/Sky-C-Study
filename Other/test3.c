#include <stdio.h>
#include <string.h>


int main()
{
		char *tra(char str[]);
		char b[80];
		gets(b);
		//puts(tra(b));
		puts(tra(b));
		puts(stri);
		return 0;
}

char stri[80];

char *tra(char str[])
{

    int i, j, k = 0;
    i = strlen(str);
    //for(i=0;str[i]!='/0';i++);
    for (j = 0; j <= 2 * i - 1; j = j + 2)
    {
        stri[j] = str[k];
        stri[j + 1] = ' ';
        k++;
    }
    stri[j - 1] = '\0';
    return stri;
}
