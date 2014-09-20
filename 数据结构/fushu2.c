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
        } else if (c == '-') {
            digitmode = 0;
            minus = 1;
        /* 读入小数点开始小数点模式 */
        } else if (c == '.') {
            digitmode = 1;
            point = 1;
            pcounter = 0;
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
        printf("发生错误，识别不能，重新输入看看\n");
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
    int state;
    printf("天家的复数计算器 V2.0\n");
    printf("按下键盘上的按键来操作吧（菜单全都区分大小写呢~）! \n\tIt's the beginning. w.输入 h.帮助及关于 q.退出\n");
    while (c = getchar()) {
        fflush(stdin);
        if (c == 'w') {
            printf("输入两个复数咯~a+bi,b+ai都行，手滑打错也行！我会努力看懂的！\n");
            state = 0;
            do {
                if (state == 1) {
                    printf("对不起我会好好加油的！请再次努力的调教我吧\n");
                }
                fflush(stdin);
                while (input(&num1));
                printf("唔，我觉得吧，你是想要说这个吧？：");
                output(num1);
                printf("按y或回车确认，按其他键重新输入：");
                state = 1;
            } while ((c = getchar()) != 'y' && c != '\n');

            printf("机智的我，接下来开始录入第二个吧\n");

            state = 0;
            fflush(stdin);
            do {
                if (state == 1) {
                    printf("对不起我会好好加油的！请再次努力的调教我吧\n");
                }
                fflush(stdin);
                while (input(&num2));
                printf("所以这次你想输入的数字是这个咯？：");
                output(num2);
                printf("按y或回车确认，按其他键重新输入：");
            } while ((c = getchar()) != 'y' && c != '\n');
            printf("成功录入第二个数，接下来算吧\n");

        } else if (c == 'h') {
            printf("改啊改啊改，终于我还是重写了，这也真是醉了。。。讲完了\n\n");
            printf("按下键盘上的按键来操作吧（菜单全都区分大小写呢~）\n\t! It's the beginning. w.输入 h.帮助及关于 q.退出\n");
            continue;
        } else if (c == 'q') {
            break;
        } else {
            printf("你在说什么，我听不懂\n");
            continue;
        }
        fflush(stdin);
        printf("又到了按键的时候了！（区分大小写）：\n\ta.加法, b.减法, c.乘法, d.除法, r.返回上一级（退出或重新输入）\n");
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
                printf("按下键盘上的按键来操作吧（菜单全都区分大小写呢~）\n\t! It's the beginning. w.输入 h.帮助及关于 q.退出\n");
                break;
            } else {
                printf("输入错误，请重新输入\n");
                continue;
            }
            printf("我帮你算的结果： ");
            output(num3);
        }
    }

    printf("感谢使用，下次再见~再敲一下键盘我就走啦");
    getchar();
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
