//
// Created by ChengKeKe on 2020/10/12.
//

#include "queue.h"
#include <stdlib.h>
#include <iostream>

arrayQueue::queue * arrayQueue::create_queue(int maxsize) {
    ElementType *array = (ElementType *)malloc(sizeof(ElementType)*maxsize);
    queue * q = (queue*)malloc(sizeof(queue));
    q->arrayAddr = array;
    q->head = 0;
    q->tail = 0;
    q->size = maxsize;
    return q;
}

void arrayQueue::en_queue(arrayQueue::queue *q, const ElementType &value) {
    int tailInsertIndex = q->tail++;
    if (q->tail >= q->size)
    {
        q->tail = q->tail % q->size;
    }

    if(q->tail == q->head)
    {
        throw "queue is full";
    }
    q->arrayAddr[tailInsertIndex] = value;
}

const ElementType arrayQueue::de_queue(arrayQueue::queue *q) {
    if (q->head == q->tail)
    {
        throw "queue is empty";
    }
    int value = q->arrayAddr[q->head++];
    if (q->head >= q->size)
    {
       q->head = q->head % q->size;
    }
    return value;
}

int arrayQueue::element_size(arrayQueue::queue *q) {
    if (q->tail > q->head)
    {
        return q->tail - q->head;
    }else if (q->tail == q->head)
    {
        return  0;
    }
    {
        return q->size - q->head + q->tail;
    }
}

void arrayQueue::clear_queue(arrayQueue::queue *q) {
    free(q->arrayAddr);
    q->arrayAddr = nullptr;
    q->size =0;
    q->head = q->tail = 0;
    free(q);
}

void arrayQueue::print_queue(arrayQueue::queue *q) {
    if (q->head < q->tail)
    {
        for(int i=q->head; i<q->tail; i++)
        {
            std::cout<<q->arrayAddr[i]<<"--";
        }
    }else if (q->head > q->tail)
    {
        for (int i = q->head; i < q->size; ++i) {
            std::cout<<q->arrayAddr[i]<<"--";
        }
        for (int j = 0; j < q->tail; ++j) {
            std::cout<<q->arrayAddr[j] << "--";
        }
    }else
    {
        std::cout<<"queue is empty";
    }
    std::cout<<std::endl;
}

linkedQueue::queue *linkedQueue::create_queue() {
    queue  *q = (queue*)malloc(sizeof(linkedQueue::queue));
    q->headNode = nullptr;
    q->tailNode = nullptr;
}

void linkedQueue::en_queue(linkedQueue::queue *q, ElementType value) {
    queueNode*newNode = (queueNode*)malloc(sizeof(queueNode));
    newNode->data = value;
    newNode->next = nullptr;

    queueNode * willAppendNode = q->tailNode;
    if (nullptr == willAppendNode)
    {
         q->headNode = newNode;
         q->tailNode = newNode;
    }else
    {
        willAppendNode->next = newNode;
        q->tailNode = newNode;
    }
}

ElementType linkedQueue::de_queue(linkedQueue::queue *q) {
    queueNode *willDequeueNode =  q->headNode;
    if (nullptr == willDequeueNode)
    {
        throw "queue is empty";
    }
    queueNode *willDequeueNodeNextNode = willDequeueNode->next;

    q->headNode = willDequeueNodeNextNode;
    ElementType  value = willDequeueNode->data;

    free(willDequeueNode);
    return value;
}

int linkedQueue::element_size(linkedQueue::queue *q) {
    int size = 0;
    queueNode *node = q->headNode;
    while(node != nullptr)
    {
        size++;
        node = node->next;
    }
    return size;
}

void linkedQueue::clear_queue(linkedQueue::queue *q) {

    queueNode *node = q->headNode;
    while(node != nullptr)
    {
        queueNode *willFreeNode = node->next;
        node = node->next;
        free(willFreeNode);
    }
}

void linkedQueue::printLinkedQueue(linkedQueue::queue *q) {
    queueNode *node = q->headNode;
    while(node != nullptr)
    {
        std::cout<<node->data<<"---";
        node = node->next;
    }
    std::cout<<std::endl;
}
