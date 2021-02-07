#include "sort.h"

void insertSortswap(int &value1, int &value2)
{
    int temp = value1;
    value1 = value2;
    value2 = temp;
}
/*插入排序思想：默认a[0]已经排好序，给a[0]后面依次插入新的元素，
 * 如果有新的元素加入，则需要将新元素插入到已有序列合适的位置中。
 *
 * 合适位置：因为第i轮排序后，前面i个元素都是有序的。因此只要新元素从后往前遍历，如果比末尾元素小，依次往后交换。 直到不必它小的元素停止来。这样一个数据就插入完成了。
 * */
void insertSort(int array[], int size)
{
    for(int i=0; i < size-1; i++)
    {
        int insertIndex = i+1;//第i+1个元素需要插入（第1次插入为准备插入a[1]个位置，第2次为准备插入第a[2]个位置）
        for (int j = insertIndex; j >0 ; --j) {//依次与前面元素比较
            if(array[j-1] > array[j])//与前面元素比较 插入
            {
                insertSortswap(array[j], array[j-1]);
            }
        }
    }
}