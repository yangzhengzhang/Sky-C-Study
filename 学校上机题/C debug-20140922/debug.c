#include<stdio.h>
int main()  /* int */
{
     int   n,a,b,c,d,sum=0;
     for (a=0;a<=9;a++) //a ��ʾһ����λ���еİ�λ
     {
         for (b=0;b<=9;b++) //b ��ʾһ����λ���е�ʮλ
         {
             for (c=0;c<=9;c++) //c��ʾһ����λ���еĸ�λ  /* c = 0��ʼ */
             {
                 if (a == 0 && b == 0 && c == 0) {
                    c = 1;
                 }
                 sum = 0;
                 n=100*a+b*10+c; //n ��ʾһ��0~1000���ڵ���
                 for (d=1;d<n;d++)
                 {
                    if (n%d==0)  //d ��ʾ1~n-1֮����������n������d����d��n��һ������
                         sum=sum+d; //sum��ʾn������֮��
                 }
                 if (n==sum)  // ���n��n������֮����ȣ������n��һ������
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
