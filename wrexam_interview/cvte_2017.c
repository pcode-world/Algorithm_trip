/*********************************************************************************
 *      Copyright:  (C) 2019 wujinlong<547124558@qq.com>
 *                  All rights reserved.
 *
 *       Filename:  cvte_2017.c
 *    Description:  This file 
 *                 
 *        Version:  1.0.0(2019年08月19日)
 *         Author:  wujinlong <547124558@qq.com>
 *      ChangeLog:  1, Release initial version on "2019年08月19日 15时49分33秒"
 *                 
 ********************************************************************************/
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
char *sum(const char *num1,const char *num2)
{
    if(num1 == NULL && num2 == NULL)
    {
        return NULL;
    }
    else if(num1 == NULL && num2 != NULL)
    {
        return num2;
    }
    else if(num2 == NULL && num1 != NULL)
    {
        return num1;
    }

    int p1 = strlen(num1)-1;
    int p2 = strlen(num2)-1;
    int max = p1 > p2 ? p1 : p2;
    int temp = 0;
    int car = 0;
    char *ret =(char *)malloc(max+1);
    while(p1 >= 0 && p2 >= 0)
    {
        temp = (num1[p1] - '0')+(num2[p2] - '0');
        if(temp/10)
        {
            car = 1;
        }
        else 
            car = 0;

        ret[max+1] = (temp%10)+car+'0';
        printf("%c + %c = %c,cur = %d\n",num1[p1],num2[p2],temp-'0',car);
        p1--;
        p2--;
        max--;
    }

    if(p1 < 0)
    {
        ret[max+1] = num2[p2];
        p2--;
        max--;
    }
    if(p2 < 0)
    {
        ret[max+1] = num1[p1];
        p1--;
        max--;
    }

    if(car)
    {
        ret[0] = '1';
        return ret;
    }
    else 
    {
        ret[0] = '0';
        return ++ret;
    }
}

int jud_leapyear(int year)
{
    if((year%4== 0 && year%100 != 0) || year%400 == 0)
    {
        return 1;
    }
    else 
        return 0;
}

char *getUTCtimeString(unsigned long data_sec)
{
    unsigned long day = data_sec/(60*60*24);
    int year,month,hon,mi,sec;
    int montharr1[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int montharr2[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
    int nu = 0;
    int beainyear = 1970;
    int i = 0;
    
    while(day > 365)
    {
        if(jud_leapyear(beainyear))
        {
            day -= 366;
        }
        else 
        {
            day -= 365;
        }
        nu++;
        beainyear++;
    }

    year = 1970+nu;

    month = 1;
    while(day >= 28)
    {
        if(jud_leapyear(beainyear))
        {
            day -= montharr2[i];
        }
        else
        {
            day -= montharr1[i];
        }
        month++;
        i++;
    }

    day++;
    hon = (data_sec%(60*60*24))/(60*60);//UTC time,local time need add East eight area
    mi = (data_sec%(60*60*24)/60)-60*hon;
    sec = (data_sec%(60*60*24))-60*60*hon-60*mi;

    printf("year = %d\n",year);
    printf("month = %d\n",month);
    printf("day = %lu\n",day);
    printf("hon = %d\n",hon);
    printf("mi = %d\n",mi);
    printf("sec = %d\n",sec);
    return NULL;
}

int main()
{
    char *s1 = "14563";
    char *s2 = "95951";
    char *ret;
    ret = sum(s1,s2);
    printf("ret = %s\n",ret);
    free(ret);
    /*  2017-07-07 06:54:32 1499410472 */
    getUTCtimeString(1566216227);
    return 0;
}
