/********************************************************************************
 *      Copyright:  (C) 2019 wujinlong<547124558@qq.com>
 *                  All rights reserved.
 *
 *       Filename:  sort.h
 *    Description:  This head file headfile of sort algorithm
 *
 *        Version:  1.0.0(2019年08月06日)
 *         Author:  wujinlong <547124558@qq.com>
 *      ChangeLog:  1, Release initial version on "2019年08月06日 20时52分05秒"
 *                 
 ********************************************************************************/
#include <stdio.h>
#include <string.h>

#define ARRELE(arr) (sizeof(arr)/sizeof(arr[0]))

/* 稳定排序 */

/* 1.冒泡排序 */

void bubblesort(int *arr,size_t arrsize);


/* 2.归并排序 */

void mergesort(int arr[],int L,int R);
