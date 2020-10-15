//
// Created by ChengKeKe on 2020/10/10.
//

#include "stack.h"
#include <stdlib.h>

Stack createStack() {
    Stack s= (Stack)malloc(sizeof(StackNode));
    s->next = nullptr;
    return s;
}

void push(Stack s, ElementType value) {
    StackNode *insertNodeNextNode = s->next;
    StackNode *newNode= (StackNode*)malloc(sizeof(StackNode));
    newNode->next = insertNodeNextNode;
    newNode->data = value;
    s->next = newNode;
}

bool isEmpty(Stack s) {
    return  s->next == nullptr;
}

ElementType pop(Stack s) {
   if (isEmpty(s))
   {
       throw -1;
   }
    StackNode *popNode = s->next;
    StackNode *needSaveNode = popNode->next;
    int value = popNode->data;
    free(popNode);
    s->next = needSaveNode;
    return value;
}

int stack_size(Stack s) {
    StackNode *node = s->next;
    int size = 0;
    while(node->next)
    {
        size++;
        node = node->next;
    }
    return size;
}

ElementType top(Stack s) {
    if (isEmpty(s))
    {
        throw -1;
    }else
    {
        ElementType  value = s->next->data;
        return value;
    }
}
