
#include "non_cyclic_link_list.h"
#include "stack.h"
#include "queue.h"
#include "sort.h"

//带头单向链表测试
void listTest();
//栈测试
void stackTest();
//数组队列
void queueArrayTest();
//链表队列
void queueLinkedTest();
//冒泡排序
void bobbuleSortTest();

//快速排序
void quikSortTest();

//插入排序
void insertSortTest();

//选择
void selectSortTest();

//堆排序
void heapSortTest();

int main() {
    //listTest();
    //stackTest();
    //queueArrayTest();
    //queueLinkedTest();

    //冒泡
    //bobbuleSortTest();

    //快排
    //quikSortTest();

    //插入排序
    //insertSortTest();

    //选择排序
   // selectSortTest();

   //堆排序
    heapSortTest();
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

//排序
void bobbuleSortTest()
{
    int array[] = {21,32,11,33,4,21,54,123,12,23,121,22,32121,12112,3221,321};
    int size = sizeof(array)/sizeof(array[0]);
    printArray(array,size);
    bubbleSort1(array,size);
    printArray(array,size);

    int array2[] = {3,2,1,4,5,6};
    int size2 = sizeof(array2)/sizeof(array2[0]);
    printArray(array2,size2);
    bubbleSort2(array2,size2);
    printArray(array2,size2);

    int array3[] = {2,3,1,4,5,6,7,8,9};
    int size3 = sizeof(array3) / sizeof(array3[0]);
    bubbleSort3(array3, size3);
    printArray(array3, size3);
}

void quikSortTest() {
    int array[] = {21,12,1,3,4,6,5};
    int size = sizeof(array) / sizeof(array[0]);
    printArray(array, size);
    quickSort(array,0,size-1);
    printArray(array, size);
}

void insertSortTest()
{
    int array[] = {2,3,1,4,5,12,37,18,9};
    int size = sizeof(array) / sizeof(array[0]);
    insertSort(array,size);
    printArray(array,size);
}

void selectSortTest(){
    int array[] = {2,3,1,4,5,12,37,18,9};
    int size = sizeof(array) / sizeof(array[0]);
    selectSort(array,size);
    printArray(array,size);
}

void heapSortTest()
{
    int array[] = {1,33,132,16,5,7,8,9,10,0};
    int size = sizeof(array) / sizeof(array[0]);
    heapSort(array, size);
    printArray(array,size);
}
