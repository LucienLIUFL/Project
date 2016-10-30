#ifndef ALGORITHM_H_
#define ALGORITHM_H_
#include <iostream>

class Algorithm {
public:
    static int binarySearch(int * const array, int size, int key); // *
    static void bubbleSort(int * const array, int size); // *
    static void quickSort(int * const array, int low, int high); // *
    static void selectSort(int * const array, int size); // *
    static void heapSort(int * const array, int size);
    static void mergeSort(int * const array1, int * const array2, int size1, int size2, int * result);// *

private:
	static void _show(int * const array, int size);
	static int _partition(int * const array, int low, int high);
	static void _adjustDown(int * const heap, int root, int len);
	static void _buildMaxHeap(int * const heap, int len);
};

#endif
