#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

#include "Algorithm.hpp"


void show(const std::vector<int> & array) {
	std::for_each(std::begin(array), std::end(array), [](int x){
		std::cout << x << "\t" << std::ends;
	});
	std::cout << std::endl;
}

int main(int argc, const char * argv[]) {
    // std::vector<int> array0 = {1, 3, 5, 6, 8, 9}; // Size = 6;
    // std::vector<int> array1 = {2, 9, 4, 2, 1, 3, 1, 5, 6, 8, 0}; // Size = 11;
    // std::cout << Algorithm::binarySearch(array,11, 8) << std::endl;
    // Algorithm::selectSort(&array0.at(0), array0.size());
    // Algorithm::selectSort(&array1.at(0), array1.size());
	// show(array0);
	// show(array1);
	// std::vector<int> array2(17);
	// Algorithm::mergeSort(&array0.at(0), &array1.at(0), array0.size(), array1.size(), &array2.at(0));
	// show(array2);
    std::vector<int> heap = {53, 17, 78, 9, 45, 65, 87, 32};
	Algorithm::heapSort(&heap[0], heap.size());
	Algorithm::bubbleSort(&heap[0], heap.size());
	show(heap);
}
