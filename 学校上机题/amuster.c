#include <stdio.h>

// create a function cube
int cube(x)
{
    return x * x * x;
}

int main(void)
{
    int i, j, k, num;

    for (i = 0; i <= 9; i++)
        for (j = 0; j <= 9; j++)
            for(k = 0; k <=9; k++) {
                num = i * 100 + j * 10 + k;
                if (num == cube(i) + cube(j) + cube(k) && num != 0) // exclude 0
                    printf("%d\n", num);
            }

    return 0;
}
