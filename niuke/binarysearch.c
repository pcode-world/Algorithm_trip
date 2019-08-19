/*********************************************************************************
 *      Copyright:  (C) 2019 wujinlong<547124558@qq.com>
 *                  All rights reserved.
 *
 *       Filename:  binarysearch.c
 *    Description:  This file 
 *                 
 *        Version:  1.0.0(2019年08月13日)
 *         Author:  wujinlong <547124558@qq.com>
 *      ChangeLog:  1, Release initial version on "2019年08月13日 18时40分52秒"
 *                 
 ********************************************************************************/
#include <stdio.h>
int minnumberinrotatearray(int *arr,int len)
{

    int right,left,mid;
    
    if(NULL == arr)
    {
        return 0;
    }

    left = 0;
    right = len-1;
    mid = left;

    /*旋转过,两个递增数组*/
    while(arr[left] >= arr[right])
    {
        /* 只剩两个元素 */
        if((right - left) < 2)
        {
            return arr[right];
        }

        mid = left+(right-left)/2;

        /* 最小在mid->right */
        if(arr[mid] > arr[right])
        {
            left = mid;
        }

        /* 最小在left->mid */
        else if(arr[mid] < arr[right])
        {
            right = mid;
        }

        /* 相等下缩一格 */
        else
        {
            right--;
        }
    }

    /* 没有旋转过,直接返回最左边元素 */
    return arr[left];

}

int main()
{
    int res =0;
    int test[] = {1,1,1,1,1,0,1,1};
    int test2[] = {8,1,2,3,4,5};
    int test3[] = {1,2,3,4,5,6};
    int test4[] = {5,6,7,8,9,1};
    res = minnumberinrotatearray(test,sizeof(test)/sizeof(test[0]));
    printf("res = %d\n",res);
    res = minnumberinrotatearray(test2,sizeof(test2)/sizeof(test2[0]));
    printf("res = %d\n",res);
    res = minnumberinrotatearray(test3,sizeof(test3)/sizeof(test3[0]));
    printf("res = %d\n",res);
    res = minnumberinrotatearray(test4,sizeof(test4)/sizeof(test4[0]));
    printf("res = %d\n",res);

}
