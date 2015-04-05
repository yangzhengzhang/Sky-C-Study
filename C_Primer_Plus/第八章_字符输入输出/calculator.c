#include <stdio.h>
#include <ctype.h>

float get_float(void);
char get_first(void);

int main(void)
{
    char select;
    float num1, num2;

    while (1) {
        printf("Enter the operation of your choice:\n");
        printf("a.add          s.subtract\n");
        printf("m. multiply    d.divide\n");
        printf("q.quit\n");
        select = get_first();
        if (select != 'a' && select != 's' && select != 'm' && select != 'd') {
            printf("Bye.\n");
            break;
        }
        printf("Enter first number:");
        num1 = get_float();
        printf("Enter second number:");
        num2 = get_float();
        switch (select)
        {
            case 'a': printf("%.2f + %.2f=%.2f\n", num1, num2, num1 + num2); break;
            case 's': printf("%.2f-%.2f=%.2f\n", num1, num2, num1 - num2);
            case 'm': printf("%.2f*%.2f=%.2f\n", num1, num2, num1 * num2);




        }
    }
}
