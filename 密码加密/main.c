#include <stdio.h>
#include <ctype.h>
int main(void)
{
    char ch;
    int i, choice, low;
    printf("请选择 1.加密 2.解密: ");
/*
    while ((ch = getchar()) != '1' && ch != '2') {
        getchar();
        printf("请重新输入并重试: ");
    }
*/
    printf("接下来输入字符串，如www.baidu.com，请输入baidu: \n");

    while ((ch = getchar()) != 'q') {
        i = 0;
        do{

            i++;
            if (isalpha(ch)) {
                if (i % 2) {
                    ch = tolower(ch);
                    if (ch % 2) {
                        ch += 3;
                    } else {
                        ch -= 3;
                    }

                    if (ch < 'a') {
                        ch = 'a';
                    } else if (ch > 'z') {
                        ch = 'z';
                    }
                } else {
                    ch = toupper(ch);
                    low = 0;
                    if (ch % 2) {
                        ch += 3;
                    } else {
                        ch -= 3;
                    }

                    if (ch < 'A') {
                        ch = 'A';
                    } else if (ch > 'Z') {
                        ch = 'Z';
                    }
                }
            }

            putchar(ch);

        } while ((ch = getchar()) != '\n');
        putchar('\n');
    }
    return 0;
}
