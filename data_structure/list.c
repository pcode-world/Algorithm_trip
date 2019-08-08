/*********************************************************************************
 *      Copyright:  (C) 2019 wujinlong<547124558@qq.com>
 *                  All rights reserved.
 *
 *       Filename:  list.c
 *    Description:  This file list operation function
 *                 
 *        Version:  1.0.0(2019年08月07日)
 *         Author:  wujinlong <547124558@qq.com>
 *      ChangeLog:  1, Release initial version on "2019年08月07日 09时47分55秒"
 *                 
 ********************************************************************************/
#include "list.h"

Node *listinit(elemtype *arr,size_t len)
{
    int index;
    Node *phead,*pcurr,*pnext;
    /* add a new Node */
    phead = pcurr = (Node *)malloc(sizeof(Node));

    if(NULL == pcurr)
    {
        printf("Memory allocation failed\n");
        exit(0);
    }

    memset(pcurr,0,sizeof(Node));
    pcurr->data = arr[0];
    pcurr->next = NULL;

    for(index = 1;index<len;index++)
    {
        pnext = (Node *)malloc(sizeof(Node));

        if(NULL == pcurr)
        {
            printf("Memory allocation failed\n");
            exit(0);
        }

        pnext->data = arr[index];
        pnext->next = NULL;
        pcurr->next = pnext;
        pcurr = pnext;
    }

    printf("creat list ok\n");
    return phead;
}

void printlist(Node *phead)
{
    if(NULL == phead)    
    {
        printf("list is empty\n");
        return;
    }

    printf("list content :");
    
    while(NULL != phead)
    {
        printf(PRINTFORMAT,phead->data);
        phead = phead->next;
    }

    printf("\n");
}

void listclear(Node *phead)
{
    Node *pnext;

    if(NULL == phead)    
    {
        printf("list is empty\n");
        return;
    }

    while(NULL != phead)
    {
        pnext = phead->next;
        free(phead);
        phead = pnext;
    }


    printf("clear ok\n");
}

int listsize(Node *phead)
{
    int size = 0;

    while(NULL != phead)
    {
        phead = phead->next;
        size++;
    }

    printf("list length of is %d\n",size);
    return size;
}

int isEmptyList(Node *pHead)
{
    if(pHead == NULL)
    {
        printf("list is empty\n");
        return 1;
    }
    printf("list id not empty\n");

    return 0;
}

elemtype getelement(Node *phead,int pos)
{
    int find = 0;

    if(pos < 0 || NULL == phead)
    {
        return 0;
    }

    while(phead != NULL)
    {
        if(pos == find)
        {
            break;
        }

        phead = phead->next;
        find++;
    }

    if(pos > find)
    {
        printf("Access out of range,returns the last term\n");
    }

    return phead->data;
}

int modifyelem(Node *phead,int pos,elemtype x)
{
	int i = 0;
	Node *pfind;
	pfind = phead;

	if(NULL == pfind || pos < 1)
	{
		return -1;    
	}

	while(pfind !=NULL)
	{
		if(i == pos)
		{
			break;
		}
	
        pfind = pfind->next;
        i++;
	}

	if(i < pos)
	{
		return -1;
	}

	phead = pfind;
	phead->data = x;

	return 0;
}

int insertLastList(Node *phead,elemtype insertElem)
{
    Node *pInsert;
    Node *pTmp;
    pTmp = phead;
    pInsert = (Node *)malloc(sizeof(Node));

    if(NULL == pInsert)
    {
        return -1;
    }

    memset(pInsert,0,sizeof(Node));
    pInsert->data = insertElem;
    pInsert->next =NULL;

    while(pTmp->next != NULL)
    {
        pTmp = pTmp->next;
    }

    pTmp->next = pInsert;
 
    return 0;
}
