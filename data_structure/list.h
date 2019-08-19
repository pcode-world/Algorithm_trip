/********************************************************************************
 *      Copyright:  (C) 2019 wujinlong<547124558@qq.com>
 *                  All rights reserved.
 *
 *       Filename:  list.h
 *    Description:  This head file head file of list.c
 *
 *        Version:  1.0.0(2019年08月07日)
 *         Author:  wujinlong <547124558@qq.com>
 *      ChangeLog:  1, Release initial version on "2019年08月07日 09时56分24秒"
 *                 
 ********************************************************************************/

#ifndef LIST_H
#define LIST_H


#define elemtype int
#define PRINTFORMAT "%d "
#if !defined(Node)

typedef struct _Node{

    elemtype data;
    struct _Node *next;

}Node;

#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h>



/* 2.创建链表*/

Node *listinit(elemtype *arr,size_t len);

/* 3.打印链表，链表的遍历*/

void printlist(Node *phead);

/* 4.清除线性表L中的所有元素，即释放单链表L中所有的结点，使之成为一个空表 */

void listclear(Node *phead);

/* 5.返回单链表的长度 */

int listsize(Node *phead);

/* 6.检查单链表是否为空，若为空则返回１，否则返回０ */

int isEmptyList(Node *pHead);

/* 7.返回单链表中第pos个结点中的元素，若pos超出范围，则返回最后一项 */

elemtype getelement(Node *phead,int pos);

/* 8.从单链表中查找具有给定值x的第一个元素，若查找成功则返回该结点data域的存储地址，否则返回NULL */

/* 9.把单链表中第pos个结点的值修改为x的值，若修改成功返回１，否则返回０ */

int modifyelem(Node *phead,int pos,elemtype x);

/* 10.向单链表的表头插入一个元素 */
/* 11.向单链表的末尾添加一个元素 */

int insertLastList(Node *phead,elemtype insertElem);

/* 12.向单链表中第pos个结点位置插入元素为x的结点，若插入成功返回１，否则返回０ */
/* 14.从单链表中删除表头结点，并把该结点的值返回，若删除失败则停止程序运行 */
/* 15.从单链表中删除表尾结点并返回它的值，若删除失败则停止程序运行 */
/* 16.从单链表中删除第pos个结点并返回它的值，若删除失败则停止程序运行 */
/* 17.从单链表中删除值为x的第一个结点，若删除成功则返回1,否则返回0 */
/* 18.交换2个元素的位置 */
/* 链表反转 */

Node *reverselist(Node *phead);

#endif
