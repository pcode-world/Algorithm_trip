/*********************************************************************************
 *      Copyright:  (C) 2019 wujinlong<547124558@qq.com>
 *                  All rights reserved.
 *
 *       Filename:  stack.c
 *    Description:  This file implement stacks with arrays
 *                 
 *        Version:  1.0.0(2019年08月17日)
 *         Author:  wujinlong <547124558@qq.com>
 *      ChangeLog:  1, Release initial version on "2019年08月17日 08时50分14秒"
 *                 
 ********************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct{
    int *pstack;
    int start;
    int end;
    int stacksize;
}stu_stack_info;

int createstack(stu_stack_info *p,int len)
{
    int *p_stack;

    if(NULL == p || len < 2)
    {
        return -1;
    }

    if( NULL == (p_stack = (int *)malloc(len*sizeof(int))))
    {
        return -2;
    }

    p->stacksize = len;
    p->pstack = p_stack;
    p->start = 0;
    p->end = 0;
    return 0;

}

void destroystack(stu_stack_info *p)
{
    free(p->pstack);
    memset(p,0,sizeof(stu_stack_info));
}

void stack_push(stu_stack_info *p,int x)
{
    if(p->start == p->stacksize)
    {
        printf("stack is full\n");
        return;
    }
    p->pstack[p->start] = x;
    p->start++;

}

int stack_pop(stu_stack_info *p)
{
    int ret;
    if(p->start == 0)
    {
        printf("stack is empty\n");
        return -1;
    }
    p->start--;
    ret = p->pstack[p->start];
    return ret;
}

int stack_peek(stu_stack_info *p)
{
    if(p->start == p->end)
    {
        printf("stack is empty\n");
        return 0;
    }

    p->start--;
    return p->pstack[p->start];
}

int main()
{
    int ret;
    int i;
    stu_stack_info stacktest;
    createstack(&stacktest,10);
    for(i=0;i<11;i++)
    {
        stack_push(&stacktest,i+1);
    }

    for(i=0;i<stacktest.stacksize;i++)
    {
        ret = stack_pop(&stacktest);
        printf("ret = %d\n",ret);
    }

    stack_peek(&stacktest);

    stack_push(&stacktest,8);

    stack_push(&stacktest,2);

    ret = stack_peek(&stacktest);
    printf("ret = %d\n",ret);
    ret = stack_pop(&stacktest);
    printf("ret = %d\n",ret);

    destroystack(&stacktest);
    return 0;
}
