/*********************************************************************************
 *      Copyright:  (C) 2019 wujinlong<547124558@qq.com>
 *                  All rights reserved.
 *
 *       Filename:  atoi_itoa.c
 *    Description:  This file 
 *                 
 *        Version:  1.0.0(2019年08月09日)
 *         Author:  wujinlong <547124558@qq.com>
 *      ChangeLog:  1, Release initial version on "2019年08月09日 16时04分50秒"
 *                 
 ********************************************************************************/
#include <stdio.h>
int atoi(const char *nptr)
{
    int sign;
    int nu = 0;
    const char *pfind = nptr;
    /* Skip white space and letter*/

    while(*pfind == ' ' || *pfind == '\t')
    {
        pfind++;
    }

    /* To transform */
    sign = (*pfind == '-')?-1:1;

    if(*pfind == '-' || *pfind == '+')
    {
        pfind++;
    }

    /* not number return error */
    else if(*pfind < '0' || *pfind > '9')
    {
        nu = 2147483647;//int max
        return nu;
    }

    while(*pfind != '\0' && *pfind > '/' && *pfind < ':')
    {
        nu = *pfind - '0'+10*nu;
        pfind++;
    }

    /* translate end */
    return sign*nu;
}

int itoa(int n, char s[])
{
    int i;
    int j;
    int sign;
    char arr[16];

    sign = n;    

    if(sign < 0)
    {
       n = -n;
    }

    i = 0;

    do
    {
        arr[i++] = n % 10 + '0'; 
    }
    while((n /= 10) > 0);

    if(sign < 0 )
    {
        arr[i++] = '-';
    }

    /* Reverse */
    while(!(i<0))
    {
        s[j] = arr[i];
        printf("arr[%d] = %c\n",i,arr[i]);
        printf("s[%d] = %c\n",j,s[j]);
        i--;
        j++;
    }
    s[j] = '\0';

    return 0;
}

int main()
{
    int b = -865122;
    char ch1[] = "  sjv-256";
    char ch2[] = "  -524";
    char ret[16]  = {0};
    int retint = atoi(ch1);
    printf("change to nu:%d\n",retint);
    retint = atoi(ch2);
    printf("change to nu:%d\n",retint);
    itoa(b,ret);
    return 0;
}
