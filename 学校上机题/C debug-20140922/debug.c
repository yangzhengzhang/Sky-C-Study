#include<stdio.h>
int main()  /* int */
{
     int   n,a,b,c,d,sum=0;
     for (a=0;a<=9;a++) //a 表示一个三位数中的百位
     {
         for (b=0;b<=9;b++) //b 表示一个三位数中的十位
         {
             for (c=0;c<=9;c++) //c表示一个三位数中的个位  /* c = 0开始 */
             {
                 if (a == 0 && b == 0 && c == 0) {
                    c = 1;
                 }
                 sum = 0;
                 n=100*a+b*10+c; //n 表示一个0~1000以内的数
                 for (d=1;d<n;d++)
                 {
                    if (n%d==0)  //d 表示1~n-1之间的数，如果n能整除d，则d是n的一个因子
                         sum=sum+d; //sum表示n的因子之和
                 }
                 if (n==sum)  // 如果n与n的因子之和相等，则表明n是一个完数
                 {
                     printf(" \n");
                     printf( "%d" ,n);
                     printf(" its factors are " );
                     for (d=1;d<n;d++)
                     {
                         if (n%d==0)
                             printf("%d" ,d);
                     }
                 }
              }
         }
     }
     printf(" \n");
     return  0;
}
