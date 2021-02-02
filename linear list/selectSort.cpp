#include "sort.h"

void selectSwap(int &value1, int &value2)
{
    int tmp = value1;
    value1 = value2;
    value2 = tmp;
}
/*思想：依次寻找最小的数，找到后与对应位上的数字进行交换。 默认最小数为a[0]开始，然后a[0]与其后面的数字依次比较，获取最小的数下标，然后进行交换。
 * 次小数a[1]，a[2]...  依次类推*/

void selectSort(int array[], int size)
{
    for (int i = 0; i < size-1; ++i) {
        int minIndex = i;
        for (int j = i+1; j <size ; ++j) {
            if(array[minIndex] > array[j])
            {
                minIndex = j;
            }
        }
        selectSwap(array[i],array[minIndex]);
    }
}