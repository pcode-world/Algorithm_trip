/*********************************************************************************
 *      Copyright:  (C) 2019 wujinlong<547124558@qq.com>
 *                  All rights reserved.
 *
 *       Filename:  macro.c
 *    Description:  This file 
 *                 
 *        Version:  1.0.0(2019年08月09日)
 *         Author:  wujinlong <547124558@qq.com>
 *      ChangeLog:  1, Release initial version on "2019年08月09日 18时28分58秒"
 *                 
 ********************************************************************************/
#include <stdio.h>
/* gcc -E ** -o *.i*/

#define PRINT(FORMAT, VALUE) printf("the value of " #VALUE " is "FORMAT"\n", VALUE)
#define ROUND_UP(v,s) (v%s==0?v:s*(v/s+1))
#define BITS_XOR(v,h,i) do   \
{                            \
    int a=0;int inc = i;     \
    while(inc <= h)          \
    {                        \
        a|=1<<inc;           \
        inc++;               \
    }                        \
    v=v^a;                   \
}while(0)

int main()
{
    int move = 1;
    int a1 = ROUND_UP(7,4);
    int a2 = ROUND_UP(16,8);
    PRINT("%d",a1);
    PRINT("%d",a2);

    BITS_XOR(move,3,2);
    printf("move=%d\n",move);

    return 0;
}
