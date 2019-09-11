/*********************************************************************************
 *      Copyright:  (C) 2019 wujinlong<547124558@qq.com>
 *                  All rights reserved.
 *
 *       Filename:  cvte_2019.c
 *    Description:  This file 
 *                 
 *        Version:  1.0.0(2019年08月21日)
 *         Author:  wujinlong <547124558@qq.com>
 *      ChangeLog:  1, Release initial version on "2019年08月21日 09时29分03秒"
 *                 
********************************************************************************/
#include <string.h>
#include <stdio.h>
int chartodec(char ch)
{
    int index = 0;
    char hextodecarr[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    while(hextodecarr[index] != ch && index < 16)
    {
        index++;
    }
    return index;
}

int stringhex(const char *hexstring)
{
    int lowbit;
    int bitarr[4*4] = {0};
    int i;
    int dec;
    int count = 0;
    int ret = 0;
    for(i=0;i<strlen(hexstring);i++)
    {
        lowbit = (i+1)*4-1;
        dec = chartodec(hexstring[i]);
        while(dec > 0)
        {
            bitarr[lowbit--] = dec%2;
            dec /= 2;
        }
    }

    i = 0;
    while(i < sizeof(bitarr)/sizeof(bitarr[0]))
    {
        ret = count > ret ? count : ret;
        if(bitarr[i])
        {
            count++;
        }
        else
        {
            count = 0;
        }
        i++;
    }

    return ret;
}

int main()
{
    char *hex = "05F2";
    int ret = stringhex(hex);
    printf("ret = %d\n",ret);
    return 0;
}
