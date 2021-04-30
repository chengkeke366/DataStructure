//
// Created by ChengKeKe on 2021/1/31.
//

#ifndef LINEAR_LIST_SORT_H
#define LINEAR_LIST_SORT_H

#include <vector>

void printArray(int array[], int size);
void bubbleSort1(int array[], int size);
void bubbleSort2(int array[], int size);
void bubbleSort3(int array[], int size);

void quickSort(int array[], int left, int right);
void insertSort(int array[], int size);
void selectSort(int array[], int size);
void heapSort(int array[], int size);
void addValue2Heap(int **array, int size, int value);
int deleteValueFromHeap(int array[],int &size);
void buildHeap(int array[], int size);

void mergeSort(int array[], int left, int right);
void mergeSort2(std::vector<int>&nums);

void shellSort(int array[], int size);
void quickSortForCpp(std::vector<int> &nums, int left, int right);

void algorithmTest();


#endif //LINEAR_LIST_SORT_H
