//
// Created by ChengKeKe on 2020/10/9.
//

#include "non_cyclic_link_list.h"


listNode * createNewList()
{
    listNode * head = (listNode*)malloc(sizeof(listNode));
    head->next = nullptr;
    return  head;
}

void push_front(listNode *list, listNode *node)
{
    listNode *nextNode = list->next;
    list->next = node;
    node->next = nextNode;
}
void push_back(listNode *list, listNode *node)
{
    listNode *pNode = list;
    while (pNode->next)
    {
        pNode = pNode->next;
    }
    pNode->next = node;
}
void printList(listNode *list)
{
    if (isEmpty(list))
    {
        std::cout<<"list empty, print exit"<<std::endl;
        return;
    }

    listNode *node = list->next;
    while (node)
    {
        std::cout<<node->data ;
        node = node->next;
        if (node)
        {
            std::cout<< "--->";
        }
    }
    std::cout<<std::endl;
}

void delete_front(listNode *list)
{
    listNode *needDeleteNode = list->next;
    listNode *deleteNodeNextNode = needDeleteNode->next;
    list->next = deleteNodeNextNode;
    free(needDeleteNode);
}

void delete_back(listNode *list)
{
    if(!isEmpty(list))
    {
        listNode *pNode = list->next;
        listNode *pNodePreNode = list;
        while (pNode->next)
        {
            pNodePreNode = pNode;
            pNode = pNode->next;
        }

        pNodePreNode->next = nullptr;
        free(pNode);
    }else
    {
        std::cout<<"list empty, delete fail!"<<std::endl;
    }
}
void insert(listNode *list, listNode *node, listNode *newNode)
{
    listNode *pNode =list;
    while (pNode && pNode!=node )
    {
        pNode = pNode->next;
    }
    listNode *saveNextNode = pNode->next;

    pNode->next = newNode;
    newNode->next = saveNextNode;
}

bool isEmpty(listNode *list) {
    if (!list->next)
    {
        return true;
    }else
    {
        return false;
    }
}

bool delete_value(listNode *list, const DateType &value) {

    listNode *pNode = list->next;
    listNode *pDeleteNodePreNode = list;
    listNode *pDeleteNode = nullptr;
    while (pNode)
    {
        if (pNode->data == value)
        {
            pDeleteNode = pNode;
            break;
        }else
        {
           pDeleteNodePreNode = pNode;
           pNode = pNode->next;
        }
    }

    if (!pDeleteNode)
    {
        std::cout<<"list is no value:"<<value<<std::endl;
    }else
    {
        pDeleteNodePreNode->next = pDeleteNode->next;
        free(pDeleteNode);
    }
}

void delete_all_value(listNode *list, const DateType &value) {
    listNode *pNode = list->next;
    listNode *pDeleteNodePreNode = list;
    listNode *pDeleteNode = nullptr;
    while (pNode)
    {
        if (pNode->data == value)
        {
            pDeleteNode = pNode;
            pDeleteNodePreNode->next = pDeleteNode->next;
            pNode = pNode->next;
            free(pDeleteNode);
        }else
        {
            pDeleteNodePreNode = pNode;
            pNode = pNode->next;
        }
    }

    if (!pDeleteNode)
    {
        std::cout<<"list is no value:"<<value<<std::endl;
    }
}

int list_node_size(listNode *list) {
    int i =0;
    while (list->next)
    {
        list = list->next;
        i++;
    }
    std::cout<<"list valide node size is:"<<i<<std::endl;
    return i;
}

void clearList(listNode *list) {
    listNode *pNode = list->next;
    while(pNode)
    {
        listNode *deleteNodeNextNode = pNode->next;
        free(pNode);
        pNode = deleteNodeNextNode;
    }
    list->next = nullptr;
}

listNode *front(listNode *list) {
    return list->next;
}

listNode *back(listNode *list)
{
    listNode *node = list->next;
    while (node->next)
    {
        node = node->next;
    }
    return node;
}

listNode *search_value(listNode *list, const DateType &value) {
    listNode *node = list->next;
    while(node)
    {
        if (node->data == value)
        {
            return node;
        }else
        {
            node = node->next;
        }
    }
    return nullptr;
}
