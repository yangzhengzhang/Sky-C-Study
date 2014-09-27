#include <stdio.h>

int main(void)
{
    int num, guess, yoo, size;
    int hlimit = 100, llimit = 1;

    while (1) {
        printf("1到100之间你想的是哪个数字。（放心我不会偷看的哟，只是让你mark一下）: ");
        while (1) {
            if (scanf("%d", &num) == 1 && num >= 1 && num <= 100)
                break;
            else
                printf("魂淡都说了是1到100的整数了，重来: ");
            while (getchar() != '\n');
        }

        guess = 50;
        printf("我猜是 %d ，对吧（请输入Y或N）: ", guess);

        while ((yoo = getchar()) != 'Y') {
            if (yoo == '\n')
                continue;
            if (guess == num) {
                printf("你骗人，我明明猜对了！\n");
                break;
            }
            if (yoo != 'N') {
                printf("你输入的我不认识啦（请输入Y或N）: ");
                continue;
            }
            printf("唔，猜错了吗……那是大了还是小了（请输入L或S）: ");
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
                printf("唉不是让你输入L或者S吗: ");
                size = getchar();
            }

            printf("我猜是 %d ，对吧（请输入Y或N）: ", guess);
        }

        if (guess != num)
            printf("呜呜呜 好感度下降了啦明明我猜错了\n");
        else
            printf("机智的我！\n");
        printf("要再来一发吗？按任意键继续 输入q退出游戏: ");
        getchar();
        if (getchar() == 'q')
            break;
}
    return 0;

}
