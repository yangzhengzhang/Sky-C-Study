#include <stdio.h>

void praise(void);
void good(void);

main(void)
{
    praise();
    praise();
    praise();
    good();
    return 0;
}

void praise(void)
{
    printf("For he's a jolly good fellow!\n");
}

void good(void)
{
    printf("Which nobody can deny!\n");
}
