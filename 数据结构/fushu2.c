#include <stdio.h>
#include <ctype.h>
/*
    实现思路：读取
*/
typedef struct
{
    float rpart;
    float ipart;
} complex;

int input(complex *num1) {
    char c;
    float num = 0, thatone;
    int digitmode = 0, counter = 0, minus = 0, rpart = 0, ipart = 0, point = 0, i, thisone, pcounter = 0;
    while (c = getchar()) {
        /* 结果储存部分 */
        if (!isdigit(c) && c != '-' && c != '.') {
            digitmode = 0;
            if (c == 'i' && ipart == 0 && counter == 0 && pcounter == 0) {   // 检测为虚数 虚部未输入
                if (minus) {
                    num1->ipart = -1;
                } else {
                    num1->ipart = 1;
                }
                ipart = 1;
                point = 0;
                minus = 0;
                counter = 0;
                pcounter = 0;
                num = 0;
            } else if (c == 'i' && ipart == 0 && (counter != 0 || pcounter != 0))  {    // 前面检测到数字 虚部未输入
                if (minus) {
                    num1->ipart = -num;
                } else {
                    num1->ipart = num;
                }
                ipart = 1;
                num = 0;
                point = 0;
                minus = 0;
                pcounter = 0;
                counter = 0;
            } else if (c != 'i' && rpart == 0 && (counter != 0 || pcounter != 0)) {    // 检测为实数 实部未输入 已经检测到前面的数据
                if (minus) {
                    num1->rpart = -num;
                } else {
                    num1->rpart = num;
                }
                rpart = 1;
                num = 0;
                counter = 0;
                minus = 0;
                point = 0;
                pcounter = 0;
            }
        /* 读入负号开启负号模式 */
        } else if (c == '-' && digitmode == 1) {
            if (minus) {
                num1->rpart = -num;
            } else {
                num1->rpart = num;
            }
            digitmode = 0;
            minus = 1;
            rpart = 1;
            num = 0;
            counter = 0;
            point = 0;
            pcounter = 0;
            continue;
        } else if (c == '-') {
            digitmode = 0;
            minus = 1;
            continue;
        /* 读入小数点开始小数点模式 */
        } else if (c == '.') {
            digitmode = 1;
            point = 1;
            pcounter = 0;
            continue;
        /* 小数点模式数据处理 */
        } else if (isdigit(c) && point) {
            digitmode = 1;
            pcounter++;
            thatone = c - '0';

            for (i = 0; i < pcounter; i++) {
                thatone /= 10;
            }

            num += thatone;
        } else if (isdigit(c)) {
            digitmode = 1;
            counter++;
            thisone = c - '0';
            num *= 10;
            num += thisone;
        }

        if (c == '\n') {
            break;
        }
    }
    fflush(stdin);

    if (ipart == 0 && rpart == 0) {
        printf("发生错误，无法识别的内容或者未输入正确格式， 请尝试重新输入\n");
        return 1;
    } else if (ipart == 0 && rpart == 1) {
        num1->ipart = 0;
        return 0;
    } else if (ipart == 1 && rpart == 0) {
        num1->rpart = 0;
        return 0;
    } else {
        return 0;
    }
}

void plus(complex num1, complex num2, complex *num3)
{
    num3->rpart = num1.rpart + num2.rpart;
    num3->ipart = num1.ipart + num2.ipart;
}

void minus(complex num1, complex num2, complex *num3)
{
    num3->rpart = num1.rpart - num2.rpart;
    num3->ipart = num1.ipart - num2.ipart;
}

void times(complex num1, complex num2, complex *num3)
{
    num3->rpart = num1.rpart * num2.rpart - num1.ipart * num2.ipart;
    num3->ipart = num1.ipart * num2.rpart + num1.rpart * num2.ipart;
}

int multi(complex num1, complex num2, complex *num3)
{
    if (num2.ipart == 0 && num2.rpart == 0) {
        return 1;
    } else {
        num3->rpart = (num1.rpart * num2.rpart + num1.ipart * num2.ipart) / (num2.rpart * num2.rpart + num2.ipart * num2.ipart);
        num3->ipart = (num1.ipart * num2.rpart - num1.rpart * num2.ipart) / (num2.rpart * num2.rpart + num2.ipart * num2.ipart);
        return 0;
    }
}

void output(complex num3)
{
    if (num3.ipart == 1 && num3.rpart != 0) {
        printf("%g+i\n", num3.rpart);
    } else if (num3.ipart == -1 && num3.rpart != 0) {
        printf("%g-i\n", num3.rpart);
    } else if (num3.ipart == 1 && num3.rpart == 0) {
        printf("i\n");
    } else if (num3.ipart == -1 && num3.rpart == 0) {
        printf("-i\n");
    } else if (num3.ipart == 0) {
        printf("%g\n", num3.rpart); // 虚部为0 不显示
    } else if (num3.rpart == 0) {
        printf("%gi\n", num3.ipart);    // 实部为0 不显示
    } else if (num3.ipart > 0) {
        printf("%g+%gi\n", num3.rpart, num3.ipart); // 虚部大于0 手动增加加号
    } else {
        printf("%g%gi\n", num3.rpart, num3.ipart);
    }
}

int main(void)
{


    complex num1, num2, num3;
    char c;
    printf("天家的复数计算器 V2.0\n");
    printf("请输入你要进行的操作 w.输入 q.退出\n");
    while (c = getchar()) {
        fflush(stdin);
        if (c == 'w') {
            printf("请输入你要进行操作的两个复数\n（a b可省略，可识别匹配，把虚数写在前面也可以哟~）\n");
            do {
                fflush(stdin);
                while (input(&num1));
                printf("根据智能识别系统，请确认结果：");
                output(num1);
                printf("按y或回车确认，其他重新输入：");
            } while ((c = getchar()) != 'y' && c != '\n');

            printf("成功录入第一个数，接下来开始录入第二个吧\n");

            fflush(stdin);
            do {
                fflush(stdin);
                while (input(&num2));
                printf("根据智能识别系统，请确认结果：");
                output(num2);
                printf("按y或回车确认，其他重新输入：");
            } while ((c = getchar()) != 'y' && c != '\n');
            printf("成功录入第二个数，接下来算吧\n");

        } else if (c == 'q') {
            break;
        } else {
            printf("指令无法识别，请重试\n");
            continue;
        }
        fflush(stdin);
        printf("请输入需要进行的操作（用小写字母表示）：\n\ta.加法, b.减法, c.乘法, d.除法, r.返回上一级（退出或重新输入）\n");
        while (c = getchar()) {
            fflush(stdin);
            if (c == 'a') {
                plus(num1,num2, &num3);
                printf("加法 ");
            } else if (c == 'b') {
                minus(num1,num2, &num3);
                printf("减法 ");
            } else if (c == 'c') {
                times(num1,num2, &num3);
                printf("乘法 ");
            } else if (c == 'd') {
                if (multi(num1,num2, &num3)) {
                    printf("出错了，被除数不能为0\n");
                    continue;
                }
                printf("除法 ");
            } else if (c == 'r') {
                printf("请输入你要进行的操作 w.输入 q.退出\n");
                break;
            } else {
                printf("输入错误，请重新输入\n");
                continue;
            }
            printf("结果： ");
            output(num3);
        }
    }

    printf("感谢使用，下次再见~\n");
/*
    input(&num1);
    input(&num2);
    printf("%f %f\n %f %f", num1.rpart, num1.ipart, num2.rpart, num2.ipart);
    */
/*
    int a, b;

    if (!scanf("%d", &a)) {
        printf("hhh");
    }
*/
    return 0;

}
