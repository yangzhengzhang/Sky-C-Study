//
//  main.c
//  selfpower
//
//  Created by Sky Ao on 15/5/14.
//  Copyright (c) 2015年 Sky Ao. All rights reserved.
//

#include <stdio.h>

int CaclBits(long x)
{
    int i = 1;
    if (x / 10) {
        i++;
    }
    
    return i;
}

long PowerN(long num, int n)
{
    long x = 1;
    for (int i = 0; i < n; i++)
    {
        x = x * num;
    }
    
    return x;
}

int main(void) {
    int bit;
    long this, sum;
    long min = 1;
    long max;
    
    scanf("%d", &bit);

    for (int i = 1; i < bit; i++)
    {
        min *= 10;
    }
    max = min * 10 - 1;

    this = min;
    while (this <= max)
    {
        sum = 0;
        
        long temp = this;
        do
        {
            sum += PowerN(temp % 10, bit);
            temp /= 10;
        } while(temp);

        if (sum == this)
        {
            printf("%ld\n", this);
        }
        this++;
        
    }
    
    return 0;
}
