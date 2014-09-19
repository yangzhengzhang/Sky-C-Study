#include <stdio.h>

int main(void)
{
    float inch;

    printf("Print your inch!\n");
    scanf("%f",&inch);
    printf("The cm is %.3f.\n", inch * 2.54);
    return 0;
}
