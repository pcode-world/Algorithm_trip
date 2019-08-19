/*********************************************************************************
 *      Copyright:  (C) 2019 wujinlong<547124558@qq.com>
 *                  All rights reserved.
 *
 *       Filename:  StrReverse.c
 *    Description:  This file is reverse string
 *                 
 *        Version:  1.0.0(2019年08月08日)
 *         Author:  wujinlong <547124558@qq.com>
 *      ChangeLog:  1, Release initial version on "2019年08月08日 10时58分25秒"
 *                 
 ********************************************************************************/
#include <string.h>
#include <stdio.h>

void StrReverse(char *str,size_t len)
{
    char swap;
    int indexl = 0;
    int indexr = len-1;

    while(indexl < indexr)
    {
        swap = str[indexl];
        str[indexl] = str[indexr];
        str[indexr] = swap;
        indexl++;
        indexr--;
        printf("change once\n");
    }

}

int main()
{
    int i=0;
    char teststr[] = "hello worena*";
    
    StrReverse(teststr,sizeof(teststr)/sizeof(teststr[0]));
    printf("reverse to:\n");

    for(i;i<sizeof(teststr);i++)
    {
        printf("%c ",teststr[i]);
    }
    printf("\n");
    return 0;

}
