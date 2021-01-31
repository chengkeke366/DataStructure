//
// Created by ChengKeKe on 2021/1/31.
//

#include "sort.h"
#include <iostream>

void printArray(int array[], int size)
{
    std::cout<<"print array list :";
    for (int k = 0; k < size; ++k) {
        std::cout<< array[k]<<" ";
    }
    std::cout<<std::endl;
}
/*
 * 需要冒泡的轮数：n-1次，直接想最终的一次：剩下两个元素无需，只需要一次冒泡，即可让两个元素有序。
 * 因此3个元素两次，4个元素3次。那个n元素需n-1次冒泡。
 * */
void bubbleSort1(int array[], int size)
{
    //减去1的原因：因为每次要和后面的一个数比较交换，如果最大索引为最后一个数，则比较最后一位时就会越界。
    for(int i=0; i < size-1; i++)//size-1：冒泡轮数
    {
        //size-i-1 剩余需要冒泡的元素
        for(int j=0; j < size-i-1; j++)   //减去i的原因：冒泡i次，则认为i个数据有序。只需对之前的n-1-i个元素进行冒泡
        {//循环结束条件：当经过n-1此后，只剩下最后一个数，则完成排序。
            if(array[j] > array[j+1])
            {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

/*优化版 1 ： 有序后，不再进行后续冒泡判断
 *
 * 存在一种可能，可能经过几轮排序后，数据已经有序了。后续的冒泡都是多余的
 *  如序列：8,3,2,4,5,6,7,9
 *  第一轮冒泡结束： 3,2,4,5,6,7,8,9
 *  第二轮冒泡结束： 2,3,4,5,6,7,8,9
 *  第三轮冒泡比较后发现没有要交换的数据，但是后续还有进行无用的比较。
 *  因此，如果我们发现一轮冒泡中没有发生过一次冒泡，则表示数据已经有序。后续就不用在进行比较了。
 * */

void bubbleSort2(int array[], int size)
{
    for (int i = 0; i <size-1 ; ++i) {
        bool  hasSort  = true;
        for (int j = 0; j < size-i-1 ; ++j) {
            if (array[j] > array[j+1])
            {
                int temp = array[j+1];
                array[j+1] = array[j];
                array[j] = temp;
                hasSort = false;
            }
        }
        if(hasSort)
        {
            std::cout <<"break when time:"<< i+1 <<std::endl;
            return;
        }
    }
}


/*优化版2: 如果冒泡的过程中，发现数组后半部分已经有序了，记录这个有序的节点。下次冒泡到这个节点，冒泡就结束。
 * 这么做的依据：冒泡i次后，后面i个数肯定是序列中最大的i个(或最小的)数了。但是有可能真正的有序序列已经大于i了。
 * 如：2,3,1,4,5,6,7,8
 * 第一次冒泡：2,1,3,4,5,6,7,8。 其中从3开始后，4,5,6,7,8都没有进行过位置交换，也就是说已经有序。
 * 因此我们可以想办法获取有序序列最前面的一个数字下标。如何获取呢？
 * 我们可以发现，每次冒泡最后一个交换的元素下标就是我们想要的分解值。
 * */
void bubbleSort3(int array[], int size)
{
    int lastExchangeIndex = 0;//默认没交换过，则边界就是【0】元素
    int sortBorder = size -1;
    for (int i = 0; i < size-1; ++i) {
        bool isSort = true;
        for (int j = 0; j < sortBorder; ++j)
        {
            if (array[j] > array[j+1])
            {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1]= temp;

                lastExchangeIndex = j;
                isSort = false;
            }
        }
        std::cout<<"change bubble border index to:"<<lastExchangeIndex<<std::endl;
        sortBorder = lastExchangeIndex;//此处需要注意：边界变更必须在一轮冒泡结束后
        if (isSort)
            break;
    }
}

