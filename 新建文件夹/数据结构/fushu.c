#include <stdio.h>
/*
    关于如何判断i+x，可以选择i后读取符号，再scanf数字，再getchar判断是否正确格式。
*/
typedef struct
{
    float rpart;
    float ipart;
} complex;

void input(complex *num1)
{
    float a, b, c, d;
    while(1) {
        if (scanf("%f", &a) == 0) {
            if (getchar() == 'i') {
                num1->ipart = 1;
                num1->rpart = 0;
                fflush(stdin);
                break;
            } else {
                printf("未按正确复数格式输入，请重试\n");
                fflush(stdin);
                continue;
            }
        } else {
            if ((c = getchar()) == '+') {
                num1->rpart = a;
                if (scanf("%f", &a) == 0) {
                    if (getchar() == 'i') {
                        num1->ipart = 1;
                        fflush(stdin);
                        break;
                    } else {
                        printf("未按正确复数格式输入，请重试\n");
                        continue;
                    }
                } else {
                    if (getchar() == 'i') {
                        num1->ipart = a;
                        fflush(stdin);
                    } else {
                        printf("未按正确复数格式输入，请重试\n");
                        fflush(stdin);
                        continue;
                    }
                }
                fflush(stdin);
            } else if (c == '-') {
                num1->rpart = a;
                if (scanf("%f", &a) == 0) {
                    if (getchar() == 'i') {
                        num1->ipart = -1;
                        fflush(stdin);
                        break;
                    } else {
                        printf("未按正确复数格式输入，请重试\n");
                        continue;
                    }
                } else {
                    if (getchar() == 'i') {
                        num1->ipart = -a;
                        fflush(stdin);
                    } else {
                        printf("未按正确复数格式输入，请重试\n");
                        fflush(stdin);
                        continue;
                    }
                }
                fflush(stdin);
            } else if (c == 'i') {
                num1->ipart = a;
                num1->rpart = 0;
            } else if (c == '\n'){
                num1->rpart = a;
                num1->ipart = 0;
            } else {
                printf("未按正确复数格式输入，请重试\n");
                continue;
            }
        }
        break;
    }

    fflush(stdin);
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
        printf("%g+i\n", num3.rpart);
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

    printf("请输入你要进行的操作 w.输入 q.退出\n");
    while (c = getchar()) {
        fflush(stdin);
        if (c == 'w') {
            printf("请输入你要进行操作的两个复数（暂时只支持a+bi的形式，a b可省略）\n");
            input(&num1);
            input(&num2);

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

    //printf("%f %f\n %f %f", num1.rpart, num1.ipart, num2.rpart, num2.ipart);
/*
    int a, b;

    if (!scanf("%d", &a)) {
        printf("hhh");
    }
*/
    return 0;

}
