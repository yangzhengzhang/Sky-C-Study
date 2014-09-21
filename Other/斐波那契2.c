#include <stdio.h>

int fibonacci(int num);

int main(void)
{
    int num;

    printf("Print the num: ");
    scanf("%d", &num);

    if (num > 50)
        printf("Sorry the number is too big");
    else
        printf("%d", fibonacci(num));
    return 0;
}

int fibonacci(int num)
{
    int list[50], former, later, temp, n;
    former = 0;
    later = 1;

    for (n = 0;n <= num; n++) {
        list[n] = former;

        temp = later;
        later = former + later;
        former = temp;
    }

    return list[num];
}
