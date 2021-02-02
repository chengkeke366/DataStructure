//
// Created by ChengKeKe on 2021/2/1.
//

#include "sort.h"
void quickSortSwap(int &value1, int &value2)
{
    int temp = value1;
    value1 = value2;
    value2 = temp;
}

// 获取基准值最终位置
int getBorder(int array[], int left, int right)
{
    int pivotIndex = left;
    int size = right -left+1;

    int pivot = array[left];
    while(left < right)
    {
        while(left < right)
        {
            if(array[right] > pivot)
            {
                right--;
            } else{
                break;
            }
        }

        while(left < right)
        {
            if(array[left] <= pivot)
            {
                left++;
            }else
            {
                break;
            }
        }

        if(left < right)
        {
            quickSortSwap(array[left], array[right]);
            printArray(array, size);
        }
    }
    quickSortSwap(array[pivotIndex], array[right]);
    printArray(array, size);
    return  left;
}

/*双指针法*/
void quickSort(int array[], int left, int right)
{
    //left < right 时，表明大于两个元素，还可以进行处理。当左右指针指向同一个元素时，
    if (left >= right)//
    {
        return;
    }

    int partition = getBorder(array,left,right);
    quickSort(array, left, partition-1);
    quickSort(array, partition+1, right);
}


