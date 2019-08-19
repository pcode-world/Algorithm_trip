/*********************************************************************************
 *      Copyright:  (C) 2019 wujinlong<547124558@qq.com>
 *                  All rights reserved.
 *
 *       Filename:  heapsort.c
 *    Description:  This file 
 *                 
 *        Version:  1.0.0(2019年08月15日)
 *         Author:  wujinlong <547124558@qq.com>
 *      ChangeLog:  1, Release initial version on "2019年08月15日 18时08分37秒"
 *                 
 ********************************************************************************/
#include "sort.h"

/* small heap */

void heapinsert(int arr[],int index)
{
    while(arr[index] < arr[(index-1)>>1])
    {
        swap(arr,index,(index-1)>>1);
        index = (index-1)>>1;
    }

    //printf("0-1/2 = %d\n",0-1/2);

}

void heapfy(int arr[],int index,int heapsize)
{
    int min;
    int left = index*2+1;
    while(left < heapsize)
    {
        min = left+1 < heapsize && arr[left] < arr[left+1] ? left : left+1;//记录左右孩子最小的坐标
        min = arr[index] < arr[min] ? index : min;//判断index和孩子哪个小

        /* 如果孩子大,不调整 */
        if(min == index)
        {
            break;
        }

        /* 下沉 */
        swap(arr,min,index);
        index = min;
        left = index*2+1;
        printf("min = %d,left = %d\n",min,left);
    }
}

int heappop(int arr[],int *heapsize)
{
    int ret =  arr[0];
    arr[0] = arr[*heapsize-1];
    (*heapsize)--;
    heapfy(arr,0,*heapsize);
    return ret;
    
}

void heapsort(int arr[],int len)
{
    if(NULL == arr || len < 2)
    {
        return;
    }

    int heapsize = len;
    /* heap是一棵完全二叉树,可以用数组代替完全二叉树 */
    int curr;
    for(curr = 0;curr < len;curr++)
    {
        heapinsert(arr,curr);
    }
    /* 小根堆第一个元素一定最小 */

    heapsize--;
    swap(arr,0,heapsize);
    
    while(heapsize > 0)
    {
        printf("heapsize = %d\n",heapsize);
        heapfy(arr,0,heapsize);
        heapsize--;
        swap(arr,0,heapsize);

    }
}

