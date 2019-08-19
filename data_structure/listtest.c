/*********************************************************************************
 *      Copyright:  (C) 2019 wujinlong<547124558@qq.com>
 *                  All rights reserved.
 *
 *       Filename:  listtest.c
 *    Description:  This file test function of list.c
 *                 
 *        Version:  1.0.0(2019年08月07日)
 *         Author:  wujinlong <547124558@qq.com>
 *      ChangeLog:  1, Release initial version on "2019年08月07日 17时11分27秒"
 *                 
 ********************************************************************************/
#include "list.h"

#define ARRELEN(x) (sizeof(x)/sizeof(x[0]))
int main()
{


    elemtype getele;
    elemtype ele = 25;

    int dataarr[] = {1,2,3,4,5,6,7,8,9};

    Node *head = listinit(dataarr,ARRELEN(dataarr));

    printlist(head);

    listsize(head);

    isEmptyList(head);

    getele = getelement(head,3);

    printf("get: %d\n",getele);

    insertLastList(head,ele);
    
    printlist(head);

    Node *newhead = reverselist(head);

    printlist(newhead); 

    listclear(newhead);


    return 0;
}

