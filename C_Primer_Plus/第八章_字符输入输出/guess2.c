#include <stdio.h>

int main(void)
{
    int num, guess, yoo, size;
    int hlimit = 100, llimit = 1;

    while (1) {
        printf("1��100֮����������ĸ����֡��������Ҳ���͵����Ӵ��ֻ������markһ�£�: ");
        while (1) {
            if (scanf("%d", &num) == 1 && num >= 1 && num <= 100)
                break;
            else
                printf("�국��˵����1��100�������ˣ�����: ");
            while (getchar() != '\n');
        }

        guess = 50;
        printf("�Ҳ��� %d ���԰ɣ�������Y��N��: ", guess);

        while ((yoo = getchar()) != 'Y') {
            if (yoo == '\n')
                continue;
            if (guess == num) {
                printf("��ƭ�ˣ��������¶��ˣ�\n");
                break;
            }
            if (yoo != 'N') {
                printf("��������Ҳ���ʶ����������Y��N��: ");
                continue;
            }
            printf("���´����𡭡����Ǵ��˻���С�ˣ�������L��S��: ");
            size = getchar();
            size = getchar();
            if (size == 'S') {
                llimit = guess;
                guess = (llimit + hlimit) / 2;
            }
            else if (size == 'L') {
                hlimit = guess;
                guess = (hlimit + llimit) / 2;
            }
            else {
                printf("��������������L����S��: ");
                size = getchar();
            }

            printf("�Ҳ��� %d ���԰ɣ�������Y��N��: ", guess);
        }

        if (guess != num)
            printf("������ �øж��½����������Ҳ´���\n");
        else
            printf("���ǵ��ң�\n");
        printf("Ҫ����һ���𣿰���������� ����q�˳���Ϸ: ");
        getchar();
        if (getchar() == 'q')
            break;
}
    return 0;

}
