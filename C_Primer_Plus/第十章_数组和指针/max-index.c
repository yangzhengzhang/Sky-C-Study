#include <stdio.h>

#define WIDTH 6

int max(float [], int);

int main(void)
{
    float array[] = {4.3, 5.3, 2.6, 9.2, 2.8, 3.6};
    printf("The max numnber's index is: %d\n", max(array, WIDTH));

    return 0;
}

int max(float array[], int num)
{
    int i, max, max_index;

    for (i = 0, max = *array, max_index = 0; i < num; i++) {
        if (*(array + i) > max) {
            max = *(array + i);
            max_index = i;
        }
    }

    return max_index;
}
