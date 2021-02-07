#include "sort.h"

void shellSwapValue(int &a,int &b){
    int tem = a;
    a = b;
    b = tem;
}


void shellSort(int array[], int size)
{
    for (int gap = size/2; gap >0 ; gap/=2) {//分几次组
        int index = gap;//第一次的步长

        //第一个元素下标为gap，因此i起始位置等于gap
        for (int i = gap; i < size; ++i) {
            for (int j = i; j-gap >=0 ; j-=gap)
            {
                if(array[j-gap] > array[j])
                {
                    shellSwapValue(array[j],array[j-gap]);
                }else
                {
                    break;
                }
            }
        }
    }
}