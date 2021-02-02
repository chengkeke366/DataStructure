#include "sort.h"

void insertSortswap(int &value1, int &value2)
{
    int temp = value1;
    value1 = value2;
    value2 = temp;
}

void insertSort(int array[], int size)
{
    for(int i=0; i < size-1; i++)
    {
        int insertIndex = i+1;
        for (int j = insertIndex; j >=0 ; --j) {
            if(array[j-1] > array[j])
            {
                insertSortswap(array[j], array[j-1]);
            }
        }
    }
}