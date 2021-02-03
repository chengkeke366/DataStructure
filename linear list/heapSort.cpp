#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

void swapValue(int &value1, int &value2)
{
    int temp = value1;
    value1 = value2;
    value2 = temp;
}

/*上浮最后叶子节点
 * 常用给堆中插入新的元素*/
void upAdjust(int *array, int size)
{
    int childindex = size-1;
    int temp = array[childindex];
    int parentIndex = (childindex-1)/2;
    while (parentIndex >=0 )
    {
        if(array[parentIndex] > temp)
        {
            array[childindex] = array[parentIndex];
            childindex = parentIndex;
            parentIndex = (childindex-1)/2;
        }else
        {
            break;
        }
    }
    if (parentIndex>=0)
    {
        array[parentIndex] = temp;
    }
}

/*下沉非叶子节点
 * 常用于*/
void downAdjust(int array[], int parentIndex, int size)
{
    int lchildIndex = parentIndex*2+1;
    int temp = array[parentIndex];
    while (lchildIndex < size)
    {
        int rchildIndex = lchildIndex+1;
        int smallIndex = lchildIndex;
        if(rchildIndex < size)//表明右节点存在
        {
            if(array[lchildIndex] > array[rchildIndex])
            {
                smallIndex = rchildIndex;
            }
        }

        if(temp <= array[smallIndex])
            break;
        array[parentIndex] = array[smallIndex];
        parentIndex = smallIndex;      //要调整的节点下沉
        lchildIndex = parentIndex*2+1;
    }
    //将temp放置到合适的位置
    array[parentIndex] = temp;
}

void addValue2Heap(int **array, int size, int value)
{
    //静态数组不满足扩展，需要改为动态数组
    int *newarray = (int*)realloc(*array,(size+1)*sizeof(int));
    *array = newarray;
    newarray[size] = value;
    upAdjust(newarray, size);
}

int deleteValueFromHeap(int array[],int &size)
{
    swapValue(array[0], array[size-1]);
    --size;
    downAdjust(array,0,size);
}

void buildHeap(int array[], int size)
{
    for (int i = ((size-1)-1)/2; i>=0; i--) {
        downAdjust(array,i,size);
    }
}


void heapSort(int array[], int size)
{
    //最小堆构建：从最后一个非叶子节点开始，从左到右，从下到上依次 “下沉”，完成最小堆构建
    for (int i=((size-1)-1)/2;i>=0; i--)
    {
        downAdjust(array, i, size);
    }

    //依次删除堆顶元素：将堆顶元素和末尾元素交换，然后再调整堆顶元素。 因为删除时，总是交换末尾，因此最小堆可以得到逆序序列，最大堆可以得到顺序序列
    for (int j = size-1; j>=0; --j) {
        swapValue(array[0], array[j]);
        downAdjust(array,0,j);
    }
}