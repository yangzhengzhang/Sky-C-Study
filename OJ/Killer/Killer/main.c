//
//  main.c
//  Killer
//
//  Created by Sky Ao on 15/5/21.
//  Copyright (c) 2015年 Sky Ao. All rights reserved.
//

#include <stdio.h>

int main() {
    char c;
    int arr[20000] = {0};
    int count = 0;
    int i;
    int nums = 0;
    int max = 0;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        if (c == 'D')
        {
            arr[nums++] = count;
            count = 0;
        }
        else
        {
            count++;
        }
    }
    
    arr[nums] = count;
    max = arr[0];
    
    for (i = 0; i < nums - 1; i++)
    {
        if (arr[i] + arr[i + 1] > max) {
            max = arr[i] + arr[i+1];
        }
    }

    switch (max) {
        case 0:
        case 1:
        case 2:
            printf("You are a Foolish Man");
            break;
        case 3:
            printf("You are on a Killing Spree");
            break;
        case 4:
            printf("You are Dominating");
            break;
        case 5:
            printf("You have a Mega-Kill");
            break;
        case 6:
            printf("You are Unstoppable");
            break;
        case 7:
            printf("You are Wicked Sick");
            break;
        case 8:
            printf("You have a M-m-m-m....Monster Kill");
            break;
        case 9:
            printf("You are Godlike");
            break;
        default:
            printf("You are Beyond Godlike (Somebody kill him!)");
            break;
    }
    
    return 0;
}
