#include "sort.h"
#include <iostream>
#include <vector>

void merge(int array[], int left, int mid, int right)
{
    int *arrayMerge = new int[right-left+1];
    int i=0;

    int AIndex = left; //AIndex表示数组前部分起始index
    int BIndex = mid+1;//BIndex表示数组后部分起始index
    while (AIndex<=mid && BIndex<=right)//其中一个不小于说明已经到尾部了
    {
        if(array[AIndex] <= array[BIndex])
        {
            arrayMerge[i++] = array[AIndex++];
        }else
        {
            arrayMerge[i++] = array[BIndex++];
        }
    }

    while (AIndex <= mid)
    {
        arrayMerge[i++] = array[AIndex++];
    }

    while (BIndex <= right)
    {
        arrayMerge[i++] = array[BIndex++];
    }

    //最后赋值时，需要注意从j+left开始。 因为分治需要把一个数据分成了N个区间。每次归并将区间内的元素进行赋值而已
    for (int j = 0; j <= right-left; ++j) {
        array[j+left] = arrayMerge[j];
        std::cout<<"arrayMerge["<<j<<"]:"<<arrayMerge[j]<<std::endl;
    }
    delete []arrayMerge;
}

void mergeSort(int array[], int left, int right)
{
    std::cout<<"left:"<<left<<"  right:"<<right<<std::endl;
    if(right - left<1)
    {
        return;
    }
    int mid = (left+right)/2;
    mergeSort(array, left, mid);
    mergeSort(array, mid+1, right);
    merge(array,left,mid,right);
}



void merge2(std::vector<int> &nums, int left, int mid, int right)
{

    std::vector<int> result;

    int indexVec1 = left;
    int indexVec2 = mid+1;
    while (indexVec1<=mid && indexVec2<=right)
    {
        if(nums[indexVec1]<=nums[indexVec2])
        {
            result.push_back(nums[indexVec1++]);
        }else
        {
            result.push_back(nums[indexVec2++]);
        }
    }

    while (indexVec1 <= mid)
    {
        result.push_back(nums[indexVec1++]);
    }

    while (indexVec2 <= right)
    {
        result.push_back(nums[indexVec2++]);
    }
    for (int i = 0; i <result.size() ; ++i) {
        nums[i+left] = result[i];
    }
}

void mergeSort2(std::vector<int>&nums, int left, int right)
{
    if(right-left<1)
    {
        return;
    }
    long mid = (right+left)/2;
    mergeSort2(nums, left, mid);
    mergeSort2(nums, mid+1, right);
    merge2(nums, left, mid,right);

    for (int i = 0; i < nums.size(); ++i) {
        std::cout<<nums[i]<<"  ";
    }
    std::cout<<std::endl;
}

void mergeSort2(std::vector<int> &nums)
{
    int left =0;
    int right = nums.size()-1;
    if(right - left <1)
    {
        return ;
    }
    mergeSort2(nums, left,right);
}