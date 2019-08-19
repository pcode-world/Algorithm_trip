/*********************************************************************************
 *      Copyright:  (C) 2019 wujinlong<547124558@qq.com>
 *                  All rights reserved.
 *
 *       Filename:  jumpfloor.c
 *    Description:  This file 
 *                 
 *        Version:  1.0.0(2019年08月14日)
 *         Author:  wujinlong <547124558@qq.com>
 *      ChangeLog:  1, Release initial version on "2019年08月14日 09时12分56秒"
 *                 
 ********************************************************************************/

int jumpfloor(int number)
{
    if(number < 0)
    {
        return -1;
    }

    else if(!number)
    {
        return 0;
    }

    else if(number == 1)
    {
        return 1;
    }

    else if(number == 2)
    {
        return 2;
    }

    return jumpfloor(number-1)+jumpfloor(number-2);
}
