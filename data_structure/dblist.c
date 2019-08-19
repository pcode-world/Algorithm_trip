/*********************************************************************************
 *      Copyright:  (C) 2019 wujinlong<547124558@qq.com>
 *                  All rights reserved.
 *
 *       Filename:  dblist.c
 *    Description:  This file func of dblist 
 *                 
 *        Version:  1.0.0(2019年08月08日)
 *         Author:  wujinlong <547124558@qq.com>
 *      ChangeLog:  1, Release initial version on "2019年08月08日 16时03分36秒"
 *                 
 ********************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct _dbnode{
    struct _dbnode *prve;
    int data;
    struct _dbnode *next;
}dbnode;

dbnode *dblist_init(int *arr,size_t len)
{
    int i;
    dbnode *phead,*pcurr,*pnext;
    
    if(NULL == (phead = (dbnode *)malloc(sizeof(dbnode))))
    {
        return NULL;
    }

    phead->prve = phead;
    phead->data = arr[0];
    phead->next = NULL;
    pcurr = phead;

    for(i=1;i<len;i++)
    {
        /* alloc memory */
        pnext = (dbnode *)malloc(sizeof(dbnode));

        if(NULL == pnext)
        {
            printf("alloc node falilure\n");
            break;
        }
        pnext->prve = pcurr;
        pnext->data = arr[i];
        pnext->next = NULL;

        /* join up */
        pcurr->next = pnext;

        pcurr = pnext;

    }

    return phead;
}

void dblist_destroy(dbnode *phead)
{
    dbnode *temp;

    while(phead != NULL)
    {
        temp = phead->next;
        free(phead);
        phead = temp;

    }

}

int dblist_delet(dbnode *phead)
{
    dbnode *pcurr = phead;
    dbnode *pnext = phead->next;

    if(NULL == phead)
    {
        return -1;
    }

    /* delete data < 0 */
    while(pcurr != NULL)
    {
        if(pcurr->data < 0)
        {
            /*come  end */
            if(NULL == pnext)
            {
                pcurr->prve->next = NULL;
                free(pcurr);
                return;
            }

            pnext->prve = pcurr->prve;
            pcurr->prve->next = pnext;
            free(pcurr);
        }

        pcurr = pnext;
        pnext = pcurr->next;
    }

    return 0;

}

int dblist_add(dbnode *phead,int x)
{
    dbnode *insert;

    while(NULL != phead->next)
    {
        phead = phead->next;
    }

    if(NULL == (insert =(dbnode *)malloc(sizeof(dbnode))))
    {
        return -1;
    }

    phead->next = insert;
    insert->prve = phead;
    insert->data = x;
    insert->next = NULL;
    return 0;
}

void printlist(dbnode *phead)
{
    while(NULL != phead)
    {
        printf("%d ",phead->data);
        phead = phead->next;
    }
    printf("\n");
}

int main()
{
    int arr[] = {48,-5,86,1,0,95,5,-9};
    dbnode *head = dblist_init(arr,sizeof(arr)/sizeof(arr[0]));
    printlist(head);
    dblist_delet(head);
    printlist(head);
    dblist_add(head,2);
    printlist(head);
    dblist_destroy(head);
}

