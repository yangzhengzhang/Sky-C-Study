#include <stdio.h>
#include <ctype.h>
/*
    ʵ��˼·����ȡ
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
        /* ������沿�� */
        if (!isdigit(c) && c != '-' && c != '.') {
            digitmode = 0;
            if (c == 'i' && ipart == 0 && counter == 0 && pcounter == 0) {   // ���Ϊ���� �鲿δ����
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
            } else if (c == 'i' && ipart == 0 && (counter != 0 || pcounter != 0))  {    // ǰ���⵽���� �鲿δ����
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
            } else if (c != 'i' && rpart == 0 && (counter != 0 || pcounter != 0)) {    // ���Ϊʵ�� ʵ��δ���� �Ѿ���⵽ǰ�������
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
        /* ���븺�ſ�������ģʽ */
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
        /* ����С���㿪ʼС����ģʽ */
        } else if (c == '.') {
            digitmode = 1;
            point = 1;
            pcounter = 0;
        /* С����ģʽ���ݴ��� */
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
        printf("��������ʶ���ܣ��������뿴��\n");
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
    int state;
    printf("��ҵĸ��������� V2.0\n");
    printf("���¼����ϵİ����������ɣ��˵�ȫ�����ִ�Сд��~��! \n\tIt's the beginning. w.���� h.���������� q.�˳�\n");
    while (c = getchar()) {
        fflush(stdin);
        if (c == 'w') {
            printf("��������������~a+bi,b+ai���У��ֻ����Ҳ�У��һ�Ŭ�������ģ�\n");
            state = 0;
            do {
                if (state == 1) {
                    printf("�Բ����һ�úü��͵ģ����ٴ�Ŭ���ĵ����Ұ�\n");
                }
                fflush(stdin);
                while (input(&num1));
                printf("���Ҿ��ðɣ�������Ҫ˵����ɣ���");
                output(num1);
                printf("��y��س�ȷ�ϣ����������������룺");
                state = 1;
            } while ((c = getchar()) != 'y' && c != '\n');

            printf("���ǵ��ң���������ʼ¼��ڶ�����\n");

            state = 0;
            fflush(stdin);
            do {
                if (state == 1) {
                    printf("�Բ����һ�úü��͵ģ����ٴ�Ŭ���ĵ����Ұ�\n");
                }
                fflush(stdin);
                while (input(&num2));
                printf("�������������������������������");
                output(num2);
                printf("��y��س�ȷ�ϣ����������������룺");
            } while ((c = getchar()) != 'y' && c != '\n');
            printf("�ɹ�¼��ڶ����������������\n");

        } else if (c == 'h') {
            printf("�İ��İ��ģ������һ�����д�ˣ���Ҳ�������ˡ�����������\n\n");
            printf("���¼����ϵİ����������ɣ��˵�ȫ�����ִ�Сд��~��\n\t! It's the beginning. w.���� h.���������� q.�˳�\n");
            continue;
        } else if (c == 'q') {
            break;
        } else {
            printf("����˵ʲô����������\n");
            continue;
        }
        fflush(stdin);
        printf("�ֵ��˰�����ʱ���ˣ������ִ�Сд����\n\ta.�ӷ�, b.����, c.�˷�, d.����, r.������һ�����˳����������룩\n");
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
                printf("���¼����ϵİ����������ɣ��˵�ȫ�����ִ�Сд��~��\n\t! It's the beginning. w.���� h.���������� q.�˳�\n");
                break;
            } else {
                printf("�����������������\n");
                continue;
            }
            printf("�Ұ�����Ľ���� ");
            output(num3);
        }
    }

    printf("��лʹ�ã��´��ټ�~����һ�¼����Ҿ�����");
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
