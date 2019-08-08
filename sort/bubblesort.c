/*********************************************************************************
 *      Copyright:  (C) 2019 wujinlong<547124558@qq.com>
 *                  All rights reserved.
 *
 *       Filename:  bubblesort.c
 *    Description:  This file bubble sort
 *                 
 *        Version:  1.0.0(2019年08月06日)
 *         Author:  wujinlong <547124558@qq.com>
 *      ChangeLog:  1, Release initial version on "2019年08月06日 20时44分14秒"
 *                 
 ********************************************************************************/
#include "sort.h"

void bubblesort(int *arr,size_t arrsize)
{
    int i,j,temp;

    for(i=0;i<arrsize;i++)
        for(j=0;j<arrsize-1;j++)
        {
            /* 每次比较两个，如果前一个大交换位置 */
            if(arr[j] > arr[j+1])
            {
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }

}

