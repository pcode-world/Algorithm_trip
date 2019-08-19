/*********************************************************************************
 *      Copyright:  (C) 2019 wujinlong<547124558@qq.com>
 *                  All rights reserved.
 *
 *       Filename:  replaceSpace.c
 *    Description:  This file replace space to %20
 *                 
 *        Version:  1.0.0(2019年08月13日)
 *         Author:  wujinlong <547124558@qq.com>
 *      ChangeLog:  1, Release initial version on "2019年08月13日 10时07分56秒"
 *                 
 ********************************************************************************/
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
char * replaceSpace(char *str,int length)
{
    char *newstr;
    int i = 0;
    int spacenu = 0;
    int newindex = 0;
    for(i;i<length;i++)
    {
        if(str[i] == ' ')
        {
            spacenu++;
        }
    }

    if(!spacenu)
    {
        return str;
    }
    newindex = length + 2*spacenu;
    newstr =(char *)malloc(newindex);
    memset(newstr,0,newindex);
    newindex--;
    i--;
    for(i;i>=0;i--,newindex--)
    {
        if(str[i] == ' ')
        {
            newstr[newindex--] = '0';
            newstr[newindex--] = '2';
            newstr[newindex] = '%';
            continue;

        }

        newstr[newindex] = str[i];
        printf("newstr[%d] = %c\n",newindex,newstr[newindex]);
    }

    return newstr;

}

int main()
{
    char test[] = "   a   ";
    char *p = replaceSpace(test,sizeof(test));
    printf("change to :%s\n",p);
    free(p);
    return 0;
}
