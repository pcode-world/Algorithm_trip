/*********************************************************************************
 *      Copyright:  (C) 2019 wujinlong<547124558@qq.com>
 *                  All rights reserved.
 *
 *       Filename:  selectsort.c
 *    Description:  This file 
 *                 
 *        Version:  1.0.0(2019年08月14日)
 *         Author:  wujinlong <547124558@qq.com>
 *      ChangeLog:  1, Release initial version on "2019年08月14日 15时04分12秒"
 *                 
 ********************************************************************************/
#include "sort.h"

void selectsort(int arr[],int len)
{
    if(NULL == arr || len < 2)
    {
        return;
    }

    int i,j,temp;
    for(i = 0;i<len;i++)
    {
        for(j = i+1;j<len;j++)
        {
            if(arr[j] < arr[i])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
 
    }
}

