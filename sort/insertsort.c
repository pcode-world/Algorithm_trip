/*********************************************************************************
 *      Copyright:  (C) 2019 wujinlong<547124558@qq.com>
 *                  All rights reserved.
 *
 *       Filename:  insertsort.c
 *    Description:  This file 
 *                 
 *        Version:  1.0.0(2019年08月14日)
 *         Author:  wujinlong <547124558@qq.com>
 *      ChangeLog:  1, Release initial version on "2019年08月14日 15时32分05秒"
 *                 
 ********************************************************************************/
#include "sort.h"

void insertsort(int arr[],int len)
{
    if(NULL == arr || len < 2)
        return;

    int i,j;
    for(i = 1;i<len;i++)
    {
        /* 将当前位置的数插入到前面有序中去 */
        for(j = i-1;j >= 0 && arr[j+1]<arr[j];j--)
        {
            SWAP(arr,j,j+1);
        }
    }
}
