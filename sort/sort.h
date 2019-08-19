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
#ifndef SORT_H
#define SORT_H
#include <stdio.h>
#include <string.h>

#define ARRELE(arr) (sizeof(arr)/sizeof(arr[0]))

#define SWAP(arr,l,r)            \
do{                              \
    arr[l] = arr[l] ^ arr[r];    \
    arr[r] = arr[l] ^ arr[r];    \
    arr[l] = arr[l] ^ arr[r];    \
}while(0)

#define swap(arr,l,r)            \
do{                              \
    int temp;                    \
    temp = arr[l];               \
    arr[l] = arr[r];             \
    arr[r] = temp;               \
}while(0)
void Dutch_national_flag(int arr[],int left,int right,int x);

/********************************** 稳定排序 **********************************/

/* 1.冒泡排序 */

void bubblesort(int *arr,size_t arrsize);

/* 2.插入排序 */

void insertsort(int arr[],int len);

/* 3.归并排序 */

void mergesort(int arr[],int L,int R);

/* ********************************不稳定排序******************************* */

/* 选择排序 */

void selectsort(int arr[],int len);

/* 快排 */

int partition(int arr[],int left,int right);
void quicksort(int arr[],int left,int right);

/* 堆排序 */

void heapsort(int arr[],int len);

#endif
