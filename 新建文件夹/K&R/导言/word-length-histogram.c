/*
#include <stdio.h>

main(void)
{
    int c, i, word;
    int ndigit[999];    //  ndigit��¼���ǵڼ�������

    for (i = 0; i < 999; i++)
        ndigit[i] = 0;

    word = 0;

    while ((c = getchar()) != EOF) {
        if (c != ' ' && c != '\n' && c != '\t') {
            putchar(c);
            ++ndigit[word];
        } else {
            for (i = 0; i < ndigit[word]; i++)
                printf("�|");
            printf("\twords:%d",ndigit[word]);
            printf("\n");
            word++;
        }

    }

    return 0;
}
*/
/*
 * ˮƽֱ��ͼ
#include <stdio.h>

#define MAXHIST 15  // ֱ��ͼ����󳤶�
#define MAXWORD 11  // ������󳤶�
#define IN 1
#define OUT 0

main(void)
{
    int c, i, nc, state;
    int len;        // ÿ��ֱ������
    int maxvalue;    // ���ʵ����ֵ
    int ovflow;     //  ������ʵĸ���
    int wl[MAXWORD]; // ���ʳ���ͳ��

    state = OUT;
    nc = 0;         // �����е��ַ���;
    ovflow= 0;     // ���� >= ��󵥴� �ĸ���
    for (i = 0; i < MAXWORD; ++i)
        wl[i] = 0;  // �趨��ֵ
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
            // ���ʽ��� ��ʼͳ���ַ���
            if (nc > 0)
                if (nc < MAXWORD)
                    ++wl[nc];
                else
                    ++ovflow;
            nc = 0;
        } else if (state == OUT) {
            state = IN;
            nc = 1;     // �µ�һ�����ʿ�ʼ����
        } else
            ++nc;       // ���ʼ���
    }
    // �ҳ����ֵ
    maxvalue = 0;
    for (i = 1; i < MAXWORD; ++i)
        if (wl[i] > maxvalue)
            maxvalue = wl[i];

    for (i = 1; i < MAXWORD; ++i) {
        printf("%5d - %5d : ", i, wl[i]);   // �ַ��� - ���ʸ���
        if (wl[i] > 0) {
            // 1 �趨len�ĳ��� 2 ���len���ڵ���С�ᱻ��ȥС�����֣����ж��ֶ���Ϊ1
            if ((len = wl[i] * MAXHIST / maxvalue) <= 0)
                len = 1;
        } else
            len = 0;    // �������ʱΪ0
        while (len > 0) {
            putchar('*');   // �� * ռλ
            --len;
        }

        putchar('\n');
    }

    // �Գ�����ֵ�ĵ��ʽ��б���
    if (ovflow > 0)
        printf("There are %d words >= %d\n", ovflow, MAXWORD);
}
*/

#include <stdio.h>

#define MAXHIST 15
#define MAXWORD 11
#define IN 1
#define OUT 0

main(void)
{
    int c, i, j, nc, state;
    int maxvalue;       // ����wl[]�����ֵ
    int ovflow;         // ������󳤶ȵĵ�����
    int wl[MAXWORD];    // ���ʳ��ȼ���

    state = OUT;
    nc = 0;             // һ�������е��ַ�����
    ovflow = 0;         // words >= MAXWORD ������
    for (i = 0; i < MAXWORD; ++i)
        wl[i] = 0;      // �����ʳ����趨��ֵ
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
            if (nc > 0)
                if (nc < MAXWORD)
                    ++wl[nc];
                else
                    ++ovflow;
            nc = 0;
        } else if (state == OUT) {
            state = IN;
            nc = 1;
        } else
            ++nc;
    }
    maxvalue = 0;
    for (i = 1; i < MAXWORD; ++i)
        if (wl[i] > maxvalue)
            maxvalue = wl[i];

    for (i = MAXHIST; i > 0; --i) {     // ��������������εݼ���
        for (j = 1; j < MAXWORD; ++j)   // ����
        // i�����ֵ��ʼ ���������һ��������> i�� ����� * MAXHIST / maxvalue�൱���趨�ٷֱ�
            if (wl[j] * MAXHIST / maxvalue >= i)
                printf("%4c", '*');
            else
                printf("%4c", ' ');
            putchar('\n');
    }
    for (i = 1; i < MAXWORD; ++i)
        printf("%4d", i);
    putchar('\n');
    for (i = 1; i < MAXWORD; ++i)
        printf("%4d", wl[i]);
    putchar('\n');
    if (ovflow > 0)
        printf("There are %d words >= %d\n", ovflow, MAXWORD);

    return 0;
}
