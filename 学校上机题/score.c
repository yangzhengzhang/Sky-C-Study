#include <stdio.h>

int main(void)
{
    int score;

    printf("Please input a score: ");
    scanf("%d", &score);

    if (score >= 85 && score <= 100)
        printf("Your grade is A");
    else if (score >= 75 && score <= 84)
        printf("Your grade is B");
    else if (score >= 65 && score <= 74)
        printf("Your grade is C");
    else if (score >= 0 && score <= 64)
        printf("Your grade is D");
    else
        printf("Wrong score！");
    return 0;
}
