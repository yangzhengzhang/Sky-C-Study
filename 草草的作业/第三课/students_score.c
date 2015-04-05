#include <stdio.h>

#define SUBJECTS 5

double


int main(void)
{
    double usual[SUBJECTS], finalexam[SUBJECTS], scores[SUBJECTS];
    double sum, average, high, low;
    int i;

    sum = 0.0;

    for (i = 0; i < SUBJECTS; i++) {
        printf("Please input the regular grades of subject(%d): ", i);
        scanf("%lf", &usual[i]);
        printf("Please input the final grades of subject(%d): ", i);
        scanf("%lf", &finalexam[i]);
        scores[i] = 0.3 * usual[i] + 0.7 * finalexam[i];
        sum += scores[i];
    }

    average = sum / 5;

    high = scores[0];
    low = scores[0];

    for (i = 0; i < SUBJECTS; i++) {
        if (scores[i] > high)
            high = scores[i];
        if (scores[i] < low)
            low = scores[i];
    }

    printf("The students score list: \n");
    printf("1     2     3     4     5     sum     average     highest     lowest\n");
    for (i = 0; i < SUBJECTS; i++)
        printf("%.1f  ", scores[i]);
    printf("%.1f       %.1f     %.1f     %.1f", sum, average, high, low);
    return 0;
}
