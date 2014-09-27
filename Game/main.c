#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <ctype.h>

/**
    格式化排版
*/

void lines(void)
{
    int i;

    for (i = 0; i < 55; i++)
        printf("=");
    printf("\n");
}

/**
    HP
*/
void hplines(hp)
{
    int i;

    for (i = 0; i < hp; i++)
        printf("|");
}

/**
    菜单
*/
int menu(void)
{
    int action;

    lines();
    printf("\t\t\t菜单（输入对应数字操作）\n");
    printf("1.开始游戏\t");
    printf("2.游戏说明\t");
    printf("3.退出游戏\n");
    lines();

    while (action = getchar(), action != '1' && action != '2' && action != '3')
    {
        getchar();
        printf("错误数字，请重试： ");
    }
    getchar();
    switch (action) {
        case '1':
            return 1;
        case '2':
            printf("暂时懒得写\n");
            printf("是否开始游戏（输入1开始）：");
            while (getchar() != '1')
            {
                getchar();
                printf("错误数字，请重试： ");
            }
            getchar();
            return 1;
        case '3':
            return 0;
    }
}

int main(void)
{
    int userNumber, comNumber;  /* 游戏选择号码 */
    int userHp, comHp;  /* HP情况 */
    const char const *name[] = {"卡奇", "罗斯", "特鲁", "米卢", "拉米", "杰克"};  /* 角色名 */
    const int skilled[] = {3, 5, 6, 6, 3 ,5};   /* 擅长拳法编号 */
    const char const *introduce[] = {"擅长直拳", "擅长勾拳", "擅长上击拳", "擅长上击拳", "擅长直拳", "擅长勾拳"};
    const char const *morra[] = {"石头", "剪刀", "布"};
    const char const *skillName[] = {"捣拳", "捣拳", "直拳", "必杀拳", "勾拳", "上击拳"};
    const int hurt[] = {1, 1, 2, 4, 2, 2};
    int i, count, turns;
    int userFinger, comFinger, dice;
    int beast;
    int finger = 1; /* 用于猜拳记录胜负 */

    srand((int) time(0));

    while (menu())
    {
        printf("Step 1: 选择选手\n");
        /* 选手介绍 */
        for (i = 0; i < 6; i++)
            printf("%d. %s： %s\n", i + 1, *(name + i), *(introduce + i));
        printf("请输入编号选择角色：");
        while ((userNumber = getchar() - '0') < 1 || userNumber > 6 )
        {
            getchar();
            printf("错误数字，请重试：");
        }
        getchar();
        while ((comNumber = (int) ( (rand() / RAND_MAX) * 6 ) + 1) == userNumber)
            ;
        userHp = comHp = 30;
        turns = 1;
        count = 0;

        printf("Step 2: 游戏开始\n");
        while (userHp > 0 && comHp > 0)
        {
            /* 首先猜拳 */
            while(finger)
            {
                printf("\n你想出： ");
                for(i = 0; i < 3; i++)
                    printf("%d . %s\t", i + 1, *(morra + i));
                printf("\n输入编号：");

                while ((userFinger = getchar() - '0') < 1 || userFinger > 3)
                {
                    putchar('\n');
                    getchar();
                    printf("错误数字，请重试：");
                }
                getchar();
                userFinger--;
                if ((comFinger = (int) ((rand() / (float)RAND_MAX) * 3) ) == userFinger)
                {
                    putchar('\n');
                    printf("平局，再来一次吧\n");
                    continue;
                }
                else if (comFinger == 0 && userFinger == 1 || comFinger == 1 && userFinger == 2 || comFinger == 2 && userFinger == 0)
                {
                    putchar('\n');
                    printf("系统：%s, 你：%s 你输了\n", *(morra + comFinger), *(morra + userFinger));
                    finger = -1;
                    dice = (int) ((rand() / (float)RAND_MAX) * 6) + 1;
                    break;

                } else {
                    putchar('\n');
                    printf("系统：%s, 你：%s 你赢了\n", *(morra + comFinger), *(morra + userFinger));
                    finger = 1;
                    dice = (int) ((rand() / (float)RAND_MAX) * 6) + 1;
                    break;
                }
            }

            if (finger < 0)
                printf("系统");
            else
                printf("你");
            printf("使用了 % s 造成了 %d 点伤害！\n", *(skillName + dice - 1), hurt[dice - 1]);
            if (finger < 0)
            {
                userHp -= hurt[dice - 1];
                if (dice == skilled[comNumber - 1])
                {
                    printf("擅长的拳术，攻击加成 + 3！\n");
                    userHp -= 3;
                }
            }
            else
            {
                comHp -= hurt[dice - 1];
                if (dice == skilled[userNumber - 1])
                {
                    printf("擅长的拳术，攻击加成 + 3！\n");
                    comHp -= 3;
                }
            }
            putchar('\n');
            printf("Your hp:");
            hplines(userHp);
            printf("%d", userHp);
            printf("\nCom hp: ");
            hplines(comHp);
            printf("%d", comHp);

            count++;

            if (!(count % 3)) {
                turns++;
                printf("\n一回合过去，双方HP + 3\n");
                userHp += 2;
                comHp += 2;
            }
            putchar('\n');
            if (comHp <= 0)
                printf("You win!\n");
            else if (userHp <= 0)
                printf("You Lose~\n");
        }
    }

    return 0;
}
