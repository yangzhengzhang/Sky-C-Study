#include<stdio.h>
#include<string.h>
void delchar(char s[], char c);
int main(void)
{
	char c;
	char s[80];
	printf("Input a string: ");
	gets(s);
	printf("Input a char: ");
	scanf("%c", &c);
	delchar(s, c);
	printf("After deleted,the string is:%s", s);
	return 0;
}

void delchar(char s[], char c)
{
	int a, b, e, d = 0;
	e = strlen(s);
	for(a=0; a < e; a++) {

		if(s[a] == c) {
            d++;
			for(b = a; b < e; b++)
				s[b] = s[b + 1];


			a = a - 1;
		}
	}

}
