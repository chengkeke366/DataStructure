//
// Created by ChengKeKe on 2020/10/10.
//

#ifndef LINEAR_LIST_STACK_H
#define LINEAR_LIST_STACK_H

typedef int ElementType;
typedef struct StackNode{
    ElementType  data;
    StackNode *next;
}StackNode;

typedef StackNode* Stack;

Stack createStack();
bool isEmpty(Stack s);
void push(Stack s,ElementType value);

int stack_size(Stack s);
ElementType top(Stack s);
ElementType pop(Stack s);


#endif //LINEAR_LIST_STACK_H
