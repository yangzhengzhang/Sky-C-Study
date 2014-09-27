#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char letter;
    int diff, i, j, k;

    printf("Print a upper letter: ");
    scanf("%c", &letter);

    if ( !isupper(letter) ) {
        printf("Sorry please input a upper letter");
    } else {
        diff = letter - 'A';

        for (i = 0; i <= diff; i++) {
            for (j = diff; j > i; j--)
                printf(" ");
            for(k = 0; k <= i; k++)
                printf("%c", 'A' + k);
            for (k = i - 1; k >= 0; k--)
                printf("%c", 'A' + k);
            printf("\n");
        }
    }
    return 0;
}
