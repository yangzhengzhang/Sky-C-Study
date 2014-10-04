#include <stdio.h>
#define N 200
#define L 202

int main(void)
{
    char str[N][L], c, *p1, *p2;
    int count[2][N];
    int num, i,j, total, temp1, temp2;
    int tag1, tag2;

    scanf("%d", &num);
    getchar();
    for (i = 0; i < num; i++)
    {
        j = 0;
        total = 0;
        while ((c = getchar()) != '\n')
        {
            total += c;
            str[i][j] = c;
            j++;
        }
        str[i][j] = '\0';
        count[0][i] = total;
        count[1][i] = i;
    }

    for (i = 0; i < num - 1; i++) {
        for (j = 0; j < num - i - 1; j++) {
            if (count[0][j+1] > count[0][j]){
                temp1 = count[0][j];
                count[0][j] = count[0][j+1];
                count[0][j+1] = temp1;
                temp2 = count[1][j];
                count[1][j] = count[1][j+1];
                count[1][j+1] = temp2;
            }
            else if (count[0][j+1] == count[0][j])
            {
                tag1 = count[1][j+1];
                tag2 = count[1][j];
                p1 = str[tag1];
                p2 = str[tag2];
                while (((*p1) != '\0') && ((*p2) != '\0'))
                {
                    if (*p1 < *p2)
                    {
                        break;
                    }
                    else if (*p1 > *p2)
                    {
                        temp1 = count[0][j];
                        count[0][j] = count[0][j+1];
                        count[0][j+1] = temp1;
                        temp2 = count[1][j];
                        count[1][j] = count[1][j+1];
                        count[1][j+1] = temp2;
                        break;
                    }
                    p1++;
                    p2++;
                }
            }
        }
    }
    for (i = 0; i < num; i++)
    {
        tag1 = count[1][i];
        printf("%s %i\n", str[tag1], count[0][i]);
    }

    return 0;
}
