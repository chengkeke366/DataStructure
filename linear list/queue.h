//
// Created by ChengKeKe on 2020/10/12.
//

#ifndef LINEAR_LIST_QUEUE_H
#define LINEAR_LIST_QUEUE_H

#include "stack.h"

namespace arrayQueue
{
    typedef struct queueDefine
    {
        ElementType *arrayAddr;
        int head, tail;
        int size;
    }queue;

    typedef  int ElementType;

    queue* create_queue(int maxsize);
    void en_queue(queue *q, const ElementType &value);
    const ElementType de_queue(queue *q);
    int element_size(queue *q);
    void clear_queue(queue *q);
    void print_queue(queue *q);
};

namespace linkedQueue
{
    typedef  int ElementType;
    typedef struct queueNode
    {
        queueNode *next;
        ElementType data;
    }queueNode;

    typedef struct queue
    {
        queueNode *headNode;
        queueNode *tailNode;
    }queue;

    queue* create_queue();
    void en_queue(queue *q, ElementType value);
    ElementType de_queue(queue *q);
    int element_size(queue *q);
    void clear_queue(queue *q);
    void printLinkedQueue(queue *q);
};
#endif //LINEAR_LIST_QUEUE_H
