#ifndef ALGORITHM_H_
#define ALGORITHM_H_
#include <iostream>

class Algorithm {
public:
    static int binarySearch(int * const array, int size, int key);
    static void insertSort(int * const array, int size);
    static void shellSort(int * const array, int size);
    static void bubbleSort(int * const array, int size);
    static void quickSort(int * const array, int low, int high);
    static void selectSort(int * const array, int size);
    static void heepSort(int * const array, int size);
    static void mergeSort(int * const array, int size);
    static void show(int * const array, int size);
};

#endif
