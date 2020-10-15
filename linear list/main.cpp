
#include "non_cyclic_link_list.h"
#include "stack.h"
#include "queue.h"
//带头单向链表测试
void listTest();
//栈测试
void stackTest();
//数组队列
void queueArrayTest();
//链表队列
void queueLinkedTest();



int main() {
    //listTest();
    //stackTest();
    //queueArrayTest();
    queueLinkedTest();
    return 0;
}

void listTest()
{
    //创建一个空的带头链表
    listNode *plistHead = createNewList();

    listNode *node1 =  (listNode*)malloc(sizeof(listNode));
    node1->data = 1;
    node1->next = nullptr;

    listNode *node2 =  (listNode*)malloc(sizeof(listNode));
    node2->data = 2;
    node2->next = nullptr;

    listNode *node3 =  (listNode*)malloc(sizeof(listNode));
    node3->data = 3;
    node3->next = nullptr;

    //头插法
    push_front(plistHead,node1);
    push_front(plistHead,node2);
    push_front(plistHead,node3);
    printList(plistHead);

    //删除头部
    delete_front(plistHead);
    printList(plistHead);

    //中间插入
    listNode *node4 =  (listNode*)malloc(sizeof(listNode));
    node4->data = 4;
    node4->next = nullptr;
    insert(plistHead, plistHead, node4);
    printList(plistHead);


    //尾插
    listNode *node5=  (listNode*)malloc(sizeof(listNode));
    node5->data = 5;
    node5->next = nullptr;
    push_back(plistHead,node5);
    printList(plistHead);

    listNode *node6=  (listNode*)malloc(sizeof(listNode));
    node6->data = 6;
    node6->next = nullptr;
    push_back(plistHead,node6);
    printList(plistHead);
    list_node_size(plistHead);

    //删除末尾元素
    delete_back(plistHead);
    printList(plistHead);

    //删除第一次值为value的元素
    delete_value(plistHead,1);
    printList(plistHead);
    delete_value(plistHead,5);
    printList(plistHead);

    list_node_size(plistHead);

    //尾插
    listNode *node7=  (listNode*)malloc(sizeof(listNode));
    node7->data = 7;
    node7->next = nullptr;
    push_back(plistHead,node7);
    //尾插
    listNode *node8=  (listNode*)malloc(sizeof(listNode));
    node8->data = 4;
    node8->next = nullptr;
    push_back(plistHead,node8);
    printList(plistHead);

    //删除所有值为value的元素
    delete_all_value(plistHead, 4);
    printList(plistHead);

    clearList(plistHead);
    printList(plistHead);
}

void stackTest()
{
    Stack s = createStack();
    bool isEmy = isEmpty(s);

    push(s,10);
    push(s,20);
    push(s,30);

    ElementType  value = pop(s);
    ElementType  value2 = pop(s);
    ElementType  value3 = pop(s);

}

void queueArrayTest() {
    using namespace arrayQueue;
    queue *q = arrayQueue::create_queue(5);
    arrayQueue::en_queue(q, 1);
    arrayQueue::en_queue(q, 2);
    arrayQueue::en_queue(q,3);
    arrayQueue::en_queue(q, 4);

    print_queue(q);
    int size1 = element_size(q);

    std::cout<<"queue size is:" << size1<<std::endl;

    int v1 = arrayQueue::de_queue(q);
    int v2 = arrayQueue::de_queue(q);
    print_queue(q);
    size1 = element_size(q);

    std::cout<<"queue size is:" << size1<<std::endl;

    arrayQueue::en_queue(q,5);
    print_queue(q);
    size1 = element_size(q);

    std::cout<<"queue size is:" << size1<<std::endl;
    int v3 = arrayQueue::de_queue(q);
    int v4 = arrayQueue::de_queue(q);
    int v5 = arrayQueue::de_queue(q);
    size1 = element_size(q);
    std::cout<<"queue size is:" << size1<<std::endl;
    print_queue(q);

    arrayQueue::en_queue(q,3);
    arrayQueue::en_queue(q, 4);
    size1 = element_size(q);
    std::cout<<"queue size is:" << size1<<std::endl;
    print_queue(q);
}


void queueLinkedTest() {
    linkedQueue::queue* q = linkedQueue::create_queue();
    linkedQueue::en_queue(q,10);
    linkedQueue::en_queue(q,20);
    linkedQueue::en_queue(q,30);
    linkedQueue::en_queue(q,40);
    linkedQueue::en_queue(q,50);
    linkedQueue::en_queue(q,60);

   int size = element_size(q);
   std::cout<<"queue size is:" << size<<std::endl;
   linkedQueue::printLinkedQueue(q);
   int v1 = linkedQueue::de_queue(q);
   int v2 = linkedQueue::de_queue(q);
   int v3 = linkedQueue::de_queue(q);
   int v4 = linkedQueue::de_queue(q);
   int v5 = linkedQueue::de_queue(q);
   int v6 = linkedQueue::de_queue(q);

   size = element_size(q);
   std::cout<<"queue size is:" << size<<std::endl;

}