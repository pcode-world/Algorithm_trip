/*********************************************************************************
 *      Copyright:  (C) 2019 wujinlong<547124558@qq.com>
 *                  All rights reserved.
 *
 *       Filename:  find_in_2arr.c
 *    Description:  This file 
 *                 
 *        Version:  1.0.0(2019年08月12日)
 *         Author:  wujinlong <547124558@qq.com>
 *      ChangeLog:  1, Release initial version on "2019年08月12日 18时30分00秒"
 *                 
 ********************************************************************************/
#include <stdio.h>
int find_in_2arr(int (*arr)[5],int M,int N,int m)
{
    int i = 0;
    int j = 0;

    if(arr[0][0] > m)
    {
        return 0;
    }

    while(i != M && j != N)
    {
        printf("find in diagonal\n");
        if(arr[i][j] == m)
        {
            printf("location row = %d,col = %d\n",i,j);
            return 1;
        }

        else if(arr[i][j] > m)
        {
            int temp_i = i;

            while(temp_i != 0)
            {

                temp_i--;
                if(arr[temp_i][j] == m)
                {
                    printf("location row = %d,col = %d\n",temp_i,j);
                    return 1;
                }
            }

            while(j != 0)
            {
                int temp_j = j;
                temp_j--;
                if(arr[i][temp_j] == m)
                {
                    printf("location row = %d,col = %d\n",i,temp_j);
                    return 1;
                }
            }
        }

        i++;
        j++;

    }

    if(i == M)
    {
        i--;
        while(j != N)
        {
            if(arr[i][j] == m)
            {
                printf("location row = %d,col = %d\n",i,j);
                return 1;
            }
            j++;

        }
    }

    else
    {
        j--;
        while(i != N)
        {
            if(arr[i][j] == m)
            {
                printf("location row = %d,col = %d\n",i,j);
                return 1;
            }
            i++;

        }
    }

    return 0;

}

int main()
{
    int test[3][5] = {{1,2,3,4,5},{2,3,4,5,6},{3,8,10,11,12}};
    int ret = find_in_2arr(test,3,5,11);

    printf("ret = %d\n",ret);

    return 0;
}
