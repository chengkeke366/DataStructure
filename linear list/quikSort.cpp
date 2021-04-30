//
// Created by ChengKeKe on 2021/2/1.
//

#include "sort.h"
#include <iostream>

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
        //从右向左查找 小于等于 pivot的值，找到后跳出循环
        while(left < right)
        {
            if(array[right] > pivot)
            {
                right--;
            } else{
                break;
            }
        }

        //从左往右查找大于pivot的值，找到后退出
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

        if(left < right)//交换元素
        {
            quickSortSwap(array[left], array[right]);
            printArray(array, size);
        }
    }

    //查找结束，left与right重合，交换pivot与重叠处的值
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

    int partition = getBorder(array, left, right);
    quickSort(array, left, partition-1);
    quickSort(array, partition+1, right);
}


int getPartation(std::vector<int> &nums, int left, int right)
{
    int pivot = nums[left];
    int rightIndex = right;
    int leftIndex = left;//要注意left 不能+1，因为当只有两个变量时，如果+1，则可能出现交换异常的问题
    while (leftIndex < rightIndex)
    {
        while (leftIndex < rightIndex && nums[rightIndex] > pivot)
        {
            rightIndex--;
        }

        while (leftIndex<rightIndex&& nums[leftIndex] <= pivot)
        {
            leftIndex++;
        }

        if(leftIndex < rightIndex)
        {
            std::swap(nums[leftIndex], nums[rightIndex]);
        }
    }

    std::swap(nums[left], nums[leftIndex]);

    return leftIndex;
}

void quickSortForCpp(std::vector<int> & nums, int left, int right)
{
    if(left >= right)
    {
        return;
    }
    long partition = getPartation(nums,left, right);
    quickSortForCpp(nums, left, partition-1);
    quickSortForCpp(nums, partition+1, right);
}
