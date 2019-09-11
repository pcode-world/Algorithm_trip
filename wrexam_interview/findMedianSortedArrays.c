/*********************************************************************************
 *      Copyright:  (C) 2019 wujinlong<547124558@qq.com>
 *                  All rights reserved.
 *
 *       Filename:  findMedianSortedArrays.c
 *    Description:  This file 
 *                 
 *        Version:  1.0.0(2019年08月21日)
 *         Author:  wujinlong <547124558@qq.com>
 *      ChangeLog:  1, Release initial version on "2019年08月21日 11时22分45秒"
 *                 
 ********************************************************************************/

/*找两个有序数组的中位数*/
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int m = nums1Size;
    int n = nums2Size;
    int len = m + n;
    int left = -1, right = -1;
    int aStart = 0, bStart = 0;
    for (int i = 0; i <= len / 2; i++) 
    {
        left = right;
        if (aStart < m && (bStart >= n || nums1[aStart] < nums2[bStart])) 
        {
            right = nums1[aStart++];
        } 
        else 
        {
            right = nums2[bStart++];
        }
    }
    if ((len & 1) == 0)
        return (left + right) / 2.0;
    else
        return right;

}

/*二分法*/

