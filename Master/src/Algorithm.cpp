#include "Algorithm.h"

void Algorithm::show(int * const array, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " " << std::ends;
    }
    std::cout << std::endl;
}


int Algorithm::binarySearch(int *const array, int size, int key) {
    int returnValue = -1;
    int low = 0, high = size - 1, mid;

    while (low <= high) {
        mid = (low + high) / 2;

        if (array[mid] == key) {
            returnValue = mid;
            break;
        } else if (array[mid] > key) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return returnValue;
}

void Algorithm::bubbleSort(int * const array, int size) {
    int temp;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < (size - i - 1); ++j) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void Algorithm::quickSort(int * const array, int low, int high) {
    if (low < high) {
        int pivot;
        int lowPos = low;
        int highPos = high;
        pivot = array[low];
        while (lowPos < highPos) {
            while ((lowPos < highPos) && (array[highPos] >= pivot)) {
                --highPos;
            }
            array[lowPos] = array[highPos];
            while ((lowPos < highPos) && (array[lowPos] <= pivot)) {
                ++lowPos;
            }
            array[highPos] = array[lowPos];
        }
        array[lowPos] = pivot;

        quickSort(array, low, lowPos - 1);
        quickSort(array, lowPos + 1, high);
    }
}
