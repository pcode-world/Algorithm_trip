/*********************************************************************************
 *      Copyright:  (C) 2019 wujinlong<547124558@qq.com>
 *                  All rights reserved.
 *
 *       Filename:  checkendian.c
 *    Description:  This file 
 *                 
 *        Version:  1.0.0(2019年08月09日)
 *         Author:  wujinlong <547124558@qq.com>
 *      ChangeLog:  1, Release initial version on "2019年08月09日 15时39分56秒"
 *                 
 ********************************************************************************/
#include <stdio.h>
/* ******************linux kenel**************************************************************
 * static union { char c[4]; unsigned long mylong; } endian_test = {{ 'l', '?', '?', 'b' } };
 * #define ENDIANNESS ((char)endian_test.mylong)
 * *******************************************************************************************/


/* change */
//对于字数据16bit
#define BIG2LITTLE(A)   ((((A)&0xff00)>>8) | (((A)&0x00ff)<<8))  
// 
//对于双字数据32bit
#define BIG2LITTLE(A)  ((((A)&0xff000000)>>24) | (((A)&0x000000ff)<<24) | (((A)&0x0000ff00)<<8) | (((A)&0x00ff00)>>8))
int checkendian()
{
    union
    {
        int a;
        char b;
    }c;
    c.b = 1;

    return (c.b == 1);
}

int main()
{
    int endian = checkendian();

    printf("endian = %d\n",endian);

    return 0;
}

