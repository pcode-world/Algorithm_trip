/*********************************************************************************
 *      Copyright:  (C) 2019 wujinlong<547124558@qq.com>
 *                  All rights reserved.
 *
 *       Filename:  getlonggestsubstring.c
 *    Description:  This file 
 *                 
 *        Version:  1.0.0(2019年09月11日)
 *         Author:  wujinlong <547124558@qq.com>
 *      ChangeLog:  1, Release initial version on "2019年09月11日 22时25分06秒"
 *                 
 ********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char *getlonggestsubstring(char *str1,char *str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int **dp = (int **)malloc(sizeof(int *) *len1);
    int i,j;
    int maxlen = 0,maxindex;
    for(i = 0;i < len1;i++)
    {
        dp[i] = (int *)malloc(sizeof(int *) *len2);
    }

    for(i = 0;i < len1;++i)
    {
        for(j = 0;j < len2;++j)
        {
            /* 遇到两个字符串的字符相等 */
            if(str1[i] == str2[j])
            {
                /* 在第一行或第一列 */
                if(i == 0 || j == 0)
                    dp[i][j] = 1;
                /* 为前一次+1 */
                else
                    dp[i][j] = dp[i-1][j-1]+1;
            }

            else
                dp[i][j] = 0;
            
            if(dp[i][j] > maxlen)
            {
                maxlen = dp[i][j];
                maxindex = i;
            }
        }

    }

    char *ret = (char *)malloc(maxindex - maxlen + 1);
    ret[maxindex - maxlen] = '\0';
    strncpy(ret,&str1[maxindex - maxlen+1],maxlen);
    free(dp);
    return ret;
}

int main()
{
    char *s1 = "acbcbcef";
    char *s2 = "abcbced";
    char *res = getlonggestsubstring(s1,s2);
    printf("res = %s\n",res);
    free(res);
    return 0;
}
