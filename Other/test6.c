#include "stdio.h"
max_value(m,n,array);
void main()
{int a[3][4]={{1,3,5,7},{2,4,6,8},{15,17,34,12}};
 printf("max value is %d\n",max_value(3, 4, a));
 }
 int m,n, array;
int max_value(m,n,array)
{int i,j,max;
max=array[0][0];
for(i=0;i<m;i++)
 for(j=0;j<n;j++)
  if(max<array[i][j]) max = array[i][j];
  return(max);
}
