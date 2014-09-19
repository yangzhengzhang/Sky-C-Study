#include <stdio.h>

int main(void)
{
    int d = 5, *pd = &d, b = 3;

//    printf("%d", *pd * b);    // 15
//    printf("%d", ++*pd - b);  // 3
//    printf("%d", *pd++);    // 5
    printf("%d", ++(*pd));  //6

    return 0;
}
