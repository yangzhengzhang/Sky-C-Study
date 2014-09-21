#include <stdio.h>

#define SECOND 3.156E7

int main(void)
{
    int age;

    printf("Please print your age: ");
    scanf("%d", &age);
    printf("The second you lived is %.Lf", age * SECOND);
    return 0;

}
