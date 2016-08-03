#include <iostream>

#include "List.h"

void visit(int x) {
    std::cout << x << std::endl;
}

int main(int argc, char const * argv[]) {
    List test;

    for (int i = 0; i < 10; ++i) {
        test.append(i);
    }
    std::cout << test.getSize() << std::endl;
    // std::cout << test.find(1) << std::endl;
    test.insert(9, 44);
    test.traverse(visit);
    test.remove(5);
    test.traverse(visit);
    return 0;
}
