/*********************************************************************************
 *      Copyright:  (C) 2019 wujinlong<547124558@qq.com>
 *                  All rights reserved.
 *
 *       Filename:  quicksort.c
 *    Description:  This file 
 *                 
 *        Version:  1.0.0(2019年08月14日)
 *         Author:  wujinlong <547124558@qq.com>
 *      ChangeLog:  1, Release initial version on "2019年08月14日 20时46分15秒"
 *                 
 ********************************************************************************/
#include "sort.h"

/* 将数组中大于某个数的放右边,等于的放中间,小于放左边 */
void Dutch_national_flag(int arr[],int left,int right,int x)
{
    if(NULL == arr || right < 2)
    {
        return;
    }
    int less = left-1;
    int more = right+1;
    int curr = left;
    while(curr < more)
    {
        /* 大于时curr不能++,需要考察换回来的数 */
        if(arr[curr] > x)
        {
            swap(arr,curr,more-1);
            more--;
        }
        else if(arr[curr] == x)
        {
            curr++;
        }
        else
        {
            swap(arr,curr,less+1);
            less++;
            curr++;
        }
    }
}

int partition(int arr[],int left,int right)
{
    int less = left-1;
    int more = right+1;
    int curr = left;
    /* 随机快排将standard换成一个随机数 */
    int standard = arr[right];
    while(curr < more)
    {
        /* 大于时curr不能++,需要考察换回来的数 */
        if(arr[curr] > standard)
        {
            swap(arr,curr,more-1);
            more--;
        }
        else if(arr[curr] == standard)
        {
            curr++;
        }
        else
        {
            swap(arr,curr,less+1);
            less++;
            curr++;
        }
    }

    /* 返回分区位置,继续递归 */
    /* less为小于的位置,下次递归-1会跳过一个数,所以返回+1 */
    return less+1;

}

void quicksort(int arr[],int left,int right)
{
    if(left < right)
    {
        int ret = partition(arr,left,right);
        if(ret > left)
            quicksort(arr,left,ret-1);
        if(ret < right)
            quicksort(arr,ret+1,right);

    }
}
