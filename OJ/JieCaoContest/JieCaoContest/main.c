//
//  main.c
//  JieCaoContest
//
//  Created by Sky Ao on 15/5/21.
//  Copyright (c) 2015年 Sky Ao. All rights reserved.
//

#include <stdio.h>

int main() {
    int stackNum = 0;
    int arr[100];
    int i;
    int count = 0;
    
    scanf("%d", &stackNum);
    
    for (i = 0; i < stackNum; i++)
        scanf("%d", arr + i);
    
    while (stackNum > 0 && arr[0] != 0)
    {
        if (arr[stackNum - 1] == 1)
        {
            count++;
            stackNum--;
        }
        else
        {
            arr[stackNum - 1] = 1;
            count++;
        }
    }
    
    if (count % 2)
    {
        printf("Me");
    }
    else
    {
        printf("Linkinpaoger");
    }
    
    return 0;
}
