/*********************************************************************************
 *      Copyright:  (C) 2019 wujinlong<547124558@qq.com>
 *                  All rights reserved.
 *
 *       Filename:  queue.c
 *    Description:  This file implement queues with arrays
 *                 
 *        Version:  1.0.0(2019年08月17日)
 *         Author:  wujinlong <547124558@qq.com>
 *      ChangeLog:  1, Release initial version on "2019年08月17日 10时26分33秒"
 *                 
 ********************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct{
    int *pqueue;
    int queuesize;
    int head;
    int tail;
    int elenu;
}stu_queue_info;

void createqueue(stu_queue_info *p,int len)
{
    int *ptemp;
    if(NULL == p || len < 1)
    {
        return;
    }

    if( NULL == (ptemp = (int *)malloc(len*sizeof(int))))
    {
        printf("alloc mem faluire\n");
        return;
    }

    p->pqueue = ptemp;
    p->queuesize = len;
    p->head = 0;
    p->tail = 0;
    p->elenu = 0;

}

void destroyqueue(stu_queue_info *p)
{
    free(p->pqueue);
    memset(p,0,sizeof(stu_queue_info));
}

void queue_push(stu_queue_info *p,int x)
{
    if(p->elenu == p->queuesize)
    {
        printf("queue is full\n");
        return;
    }
    p->pqueue[p->tail] = x;
    p->tail++;
    p->elenu++;
    if(p->tail == p->queuesize)
    {
        p->tail = p->tail%p->queuesize;
    }
}

int queue_pop(stu_queue_info *p)
{
    int ret;
    if(p->elenu == 0)
    {
        printf("queue is empty\n");
        return 0;
    }
    ret = p->pqueue[p->head];
    p->head++;
    p->elenu--;
    if(p->head == p->queuesize)
    {
        p->tail = p->tail%p->queuesize;
    }
    return ret;
}

int main()
{
    int ret;
    stu_queue_info queue;
    int i;
    createqueue(&queue,5);
    for(i=0;i<6;i++)
    {
        queue_push(&queue,i+1);
    }

    for(i=0;i<6;i++)
    {
        ret = queue_pop(&queue);
        printf("ret = %d\n",ret);
    }
    destroyqueue(&queue);
    return 0;
}
