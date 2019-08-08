/*********************************************************************************
 *      Copyright:  (C) 2019 wujinlong<547124558@qq.com>
 *                  All rights reserved.
 *
 *       Filename:  sorttest.c
 *    Description:  This file test sort algorithm
 *                 
 *        Version:  1.0.0(2019年08月06日)
 *         Author:  wujinlong <547124558@qq.com>
 *      ChangeLog:  1, Release initial version on "2019年08月06日 20时53分47秒"
 *                 
 ********************************************************************************/

#include "sort.h"

#define typename int

void printarr(typename *arr,size_t arrsize)
{
    int i;
    
    printf("ordered arr = ");
    
    for(i=0;i<arrsize;i++)
    {
        printf("%d ",arr[i]);
    }

    printf("\n");
}

int main()
{
    int arr[] = {1,8,19,45,32,4,6,72,96,74,111,0};

    //mergesort(arr,0,ARRELE(arr)-1);
    bubblesort(arr,ARRELE(arr));

    printarr(arr,ARRELE(arr));

    return 0;


}
