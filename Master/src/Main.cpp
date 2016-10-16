#include "Algorithm.h"

int main(int argc, const char * argv[]) {
    int arrayOrder[] = {1, 3, 5, 6, 8, 9}; // Size = 6;
    int array[] = {2, 9, 4, 2, 1, 3, 1, 5, 6, 8, 0}; // Size = 11;

    // std::cout << Algorithm::binarySearch(array,11, 8) << std::endl;
    Algorithm::quickSort(arrayOrder, 0, 6);
    Algorithm::quickSort(array, 0, 11);
    Algorithm::show(arrayOrder, 6);
    Algorithm::show(array, 11);
    return 0;
}
