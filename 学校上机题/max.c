#include <stdio.h>

float max(float a, float b, float c);   /* 定义一个函数 */

int main(void)
{
    float a, b, c;  /* 声明浮点型数据 */

    printf("In the program you should input three numbers:\n");
    printf("Print the first number:");
    scanf("%f", &a);    /* 获取第一个数 */
    printf("Print the second number:");
    scanf("%f", &b);    /* 获取第二个数 */
    printf("Print the third number:");
    scanf("%f", &c);    /* 获取第三个数 */
    printf("The max number is %.2f.", max(a, b, c));
    return 0;

}
/* max函数比较大小 */
float max(float a, float b, float c)
{
    float max;
    max = a;
    if (b > max)
        max = b;
    if (c > max)
        max = c;
    return max;     /* 返回最大值 */
}
