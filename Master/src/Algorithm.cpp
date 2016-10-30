#include "Algorithm.hpp"

int Algorithm::binarySearch(int * const array, int size, int key) {
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
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < (size - i - 1); ++j) {
            if (array[j] > array[j + 1]) {
                array[j] += array[j + 1];
                array[j + 1] = array[j] - array[j + 1];
                array[j] -= array[j + 1];
            }
        }
    }
}

void Algorithm::_show(int * const array, int size) {
	for (int i = 0; i < size; ++i) {
		std::cout << array[i] << " " << std::ends;
	}
	std::cout << std::endl;
}

int Algorithm::_partition(int * const array, int low, int high) {
	int pivot = array[low];
	while (low < high) {
		while ((low < high) && (array[high] >= pivot)) {
			--high;
		}
		array[low] = array[high];
		while ((low < high) && (array[low] <= pivot)) {
			++low;
		}
		array[high] = array[low];
	}
	array[low] = pivot;
	return low;
}

void Algorithm::quickSort(int * const array, int low, int high) {
    if (low < high) {
        // int pivot;
        // int lowPos = low;
        // int highPos = high;
        // pivot = array[low];
        // while (lowPos < highPos) {
        //     while ((lowPos < highPos) && (array[highPos] >= pivot)) {
        //         --highPos;
        //     }
        //     array[lowPos] = array[highPos];
        //     while ((lowPos < highPos) && (array[lowPos] <= pivot)) {
        //         ++lowPos;
        //     }
        //     array[highPos] = array[lowPos];
        // }
        // array[lowPos] = pivot;
		int pivotPos = _partition(array, low, high);
        // quickSort(array, low, lowPos - 1);
        // quickSort(array, lowPos + 1, high);
		// std::cout << low << std::endl;
		quickSort(array, low, pivotPos - 1);
        quickSort(array, pivotPos + 1, high);
    }
}

void Algorithm::selectSort(int * const array, int size) {
	int min;
	for (int i = 0; i < size - 1; ++i) {
		min = i;
		for (int j = i + 1; j < size; ++j) {
			if (array[min] > array[j]) {
				min = j;
			}
		}

		if (min != i) {
			array[i] += array[min];
			array[min] = array[i] - array[min];
			array[i] -= array[min];
		}
	}
}

void Algorithm::mergeSort(int * const array1, int * const array2, int size1, int size2, int * result) {
	int i, j, k;
	for (i = 0, j = 0, k = 0; (i < size1) && (j < size2); ++k) {
		if (array1[i] < array2[j]) {
			result[k] = array1[i++];
		} else {
			result[k] = array2[j++];
		}
	}

	while (i < size1) {
		result[k++] = array1[i++];
	}

	while (j < size2) {
		result[k++] = array2[j++];
	}
}

void Algorithm::heapSort(int * const array, int size) {
	_buildMaxHeap(array, size);
	for (int i = size - 1; i > 0; --i) {
		array[i] += array[0];
		array[0] = array[i] - array[0];
		array[i] -= array[0];
		_adjustDown(array, 0, i);
	}
}

void Algorithm::_buildMaxHeap(int * const heap, int len) {
	for (int i = len/2; i > 0; --i) {
		_adjustDown(heap, i - 1, len);
	}
}

void Algorithm::_adjustDown(int * const heap, int root, int len) {
	int rootValue = heap[root];

	for (int i = 2 * root + 1; i < len; i = 2*i + 1) {
		i = ((i < len - 1) && (heap[i] < heap[i+1])) ? i + 1 : i;

		if (rootValue < heap[i]) {
			heap[root] = heap[i];
			root = i;
		}
	}
	heap[root] = rootValue;
}
