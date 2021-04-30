//
// Created by ChengKeKe on 2020/10/9.
//

#ifndef LINEAR_LIST_NON_CYCLIC_LINK_LIST_H
#define LINEAR_LIST_NON_CYCLIC_LINK_LIST_H

#include <iostream>
#include <stdlib.h>
/**
 * 链表分类：
单向、双向
带头、不带头
循环、非循环
 **/

//链表节点
typedef  int DateType;

typedef struct listNode
{
    DateType data;
    listNode *next;
}listNode;


//链表操作
//创建一个带头链表
listNode * createNewList();

//插入
void push_back(listNode *list, listNode *node);
void push_front(listNode *list, listNode *node);

//插入链表list中节点node之后
void insert(listNode *list, listNode *node, listNode *newNode);

//删除
void delete_front(listNode *list);
void delete_back(listNode *list);

bool delete_value(listNode *list, const DateType &value);
void delete_all_value(listNode *list, const DateType &value);

void reverseList(listNode *list);

//节点个数
int list_node_size(listNode *list);

//打印链表
void printList(listNode *list);

//销毁链表
void clearList(listNode *list);

//访问节点
listNode *front(listNode *list);
listNode *back(listNode *list);
//查找
listNode* search_value(listNode *list, const DateType &value);
bool  isEmpty(listNode *list);

#endif //LINEAR_LIST_NON_CYCLIC_LINK_LIST_H
