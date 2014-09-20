#include <stdio.h>
/*
    ��������ж�i+x������ѡ��i���ȡ���ţ���scanf���֣���getchar�ж��Ƿ���ȷ��ʽ��
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
                printf("δ����ȷ������ʽ���룬������\n");
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
                        printf("δ����ȷ������ʽ���룬������\n");
                        continue;
                    }
                } else {
                    if (getchar() == 'i') {
                        num1->ipart = a;
                        fflush(stdin);
                    } else {
                        printf("δ����ȷ������ʽ���룬������\n");
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
                        printf("δ����ȷ������ʽ���룬������\n");
                        continue;
                    }
                } else {
                    if (getchar() == 'i') {
                        num1->ipart = -a;
                        fflush(stdin);
                    } else {
                        printf("δ����ȷ������ʽ���룬������\n");
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
                printf("δ����ȷ������ʽ���룬������\n");
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
        printf("%g\n", num3.rpart); // �鲿Ϊ0 ����ʾ
    } else if (num3.rpart == 0) {
        printf("%gi\n", num3.ipart);    // ʵ��Ϊ0 ����ʾ
    } else if (num3.ipart > 0) {
        printf("%g+%gi\n", num3.rpart, num3.ipart); // �鲿����0 �ֶ����ӼӺ�
    } else {
        printf("%g%gi\n", num3.rpart, num3.ipart);
    }
}

int main(void)
{


    complex num1, num2, num3;
    char c;

    printf("��������Ҫ���еĲ��� w.���� q.�˳�\n");
    while (c = getchar()) {
        fflush(stdin);
        if (c == 'w') {
            printf("��������Ҫ���в�����������������ʱֻ֧��a+bi����ʽ��a b��ʡ�ԣ�\n");
            input(&num1);
            input(&num2);

        } else if (c == 'q') {
            break;
        } else {
            printf("ָ���޷�ʶ��������\n");
            continue;
        }
        fflush(stdin);
        printf("��������Ҫ���еĲ�������Сд��ĸ��ʾ����\n\ta.�ӷ�, b.����, c.�˷�, d.����, r.������һ�����˳����������룩\n");
        while (c = getchar()) {
            fflush(stdin);
            if (c == 'a') {
                plus(num1,num2, &num3);
                printf("�ӷ� ");
            } else if (c == 'b') {
                minus(num1,num2, &num3);
                printf("���� ");
            } else if (c == 'c') {
                times(num1,num2, &num3);
                printf("�˷� ");
            } else if (c == 'd') {
                if (multi(num1,num2, &num3)) {
                    printf("�����ˣ�����������Ϊ0\n");
                    continue;
                }
                printf("���� ");
            } else if (c == 'r') {
                printf("��������Ҫ���еĲ��� w.���� q.�˳�\n");
                break;
            } else {
                printf("�����������������\n");
                continue;
            }
            printf("����� ");
            output(num3);
        }
    }

    printf("��лʹ�ã��´��ټ�~\n");

    //printf("%f %f\n %f %f", num1.rpart, num1.ipart, num2.rpart, num2.ipart);
/*
    int a, b;

    if (!scanf("%d", &a)) {
        printf("hhh");
    }
*/
    return 0;

}
