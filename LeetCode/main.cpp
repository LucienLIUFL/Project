#include <iostream>
#include <future>
#include <algorithm>

#include "MaplesTool/Maples.h"

int add(int a, int b) {
    std::cout << "Hello, World!" << std::endl;
    return a + b;
}

int main() {
//    std::future<int> result1 = std::async(add, 1, 2);
//    std::future<int> result2 = std::async(add, 3, 4);
//    std::cout << result1.get() << std::endl;
//    std::cout << result2.get() << std::endl;
    return 0;
}