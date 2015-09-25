//
//  main.c
//  mathevil
//
//  Created by Sky Ao on 15/5/21.
//  Copyright (c) 2015年 Sky Ao. All rights reserved.
//

#include <stdio.h>

int main() {
    int buf[2][30000] = {0};
    int arr[3] = {0};
    
    int i, j;
    int firstNum;
    int secondNum;
    int totalnum;
    int count = 0;
    int counter = 0;
    int flag = 0;
    
    scanf("%d", &totalnum);
    for (i = 2; i <= totalnum; i++) {
        buf[1][i] = 1;
        for (j = 2; j * j <= i; j++) {
            if (i % j == 0)
                buf[1][i] = 0;
        }
        if (buf[1][i] == 1)
            buf[0][count++] = i;
    }
    /*
    for (i = 0; i < count; i++)
    {
        printf("%d\n", buf[0][i]);
    }
     */
    
    
    for (i = 0; i < count && flag == 0; i++)
    {
        firstNum = buf[0][i];
        arr[0] = firstNum;
        
        if (totalnum - firstNum < 0)
            break;
        
        for (j = 0; j < count && flag == 0; j++)
        {
            secondNum = buf[0][j];
            arr[1] = buf[0][j];
            
            if (totalnum - firstNum - secondNum < 0)
                break;

            
            if (buf[1][totalnum - firstNum - secondNum] == 1)
            {
                arr[2] = totalnum - firstNum - secondNum;
                counter++;
                if (counter >= 2000)
                    flag = 1;
                printf("%d %d %d\n", arr[0], arr[1], arr[2]);

//                if (arr[0] == arr[1] && arr[1] == arr[2])
//                    printf("%d %d %d\n", arr[0], arr[1], arr[2]);
//                else if (arr[0] == arr[1])
//                {
//                    printf("%d %d %d\n", arr[0], arr[1], arr[2]);
//                    printf("%d %d %d\n", arr[0], arr[2], arr[1]);
//                    printf("%d %d %d\n", arr[2], arr[0], arr[1]);
//                }
//                else if (arr[1] == arr[2])
//                {
//                    printf("%d %d %d\n", arr[0], arr[1], arr[2]);
//                    printf("%d %d %d\n", arr[1], arr[0], arr[2]);
//                    printf("%d %d %d\n", arr[1], arr[2], arr[0]);
//                }
//                else
//                {
//                    printf("%d %d %d\n", arr[0], arr[1], arr[2]);
//                    printf("%d %d %d\n", arr[0], arr[2], arr[1]);
//                    printf("%d %d %d\n", arr[1], arr[0], arr[2]);
//                    printf("%d %d %d\n", arr[1], arr[2], arr[0]);
//                    printf("%d %d %d\n", arr[2], arr[0], arr[1]);
//                    printf("%d %d %d\n", arr[2], arr[1], arr[0]);
//                }

                

            }
            
        }
        
    }
    
    return 0;
}
