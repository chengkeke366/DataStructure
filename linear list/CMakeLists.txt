cmake_minimum_required(VERSION 3.15)
project(linear_list)

set(CMAKE_CXX_STANDARD 11)

add_executable(linear_list
        "main.cpp"
        "non_cyclic_link_list.cpp" "non_cyclic_link_list.h"
        "stack.cpp" "stack.h"
        "queue.cpp" "queue.h"
        "sort.h"
        "bubbleSort.cpp"
        "quikSort.cpp"
        "insertSort.cpp"
        "selectSort.cpp"
        "heapSort.cpp"
        "mergeSort.cpp"
        "shellSort.cpp"
        "tree.h" "tree.cpp"
        SwordFingerOffer.cpp SwordFingerOffer.h)

