#include <iostream>

#include "Vector.h"

void func(int a) {
    std::cout << a << std::endl;
}

int main(int argc, char const * argv[]) {
    Maples::Vector v;
    v.append(1);
    v.traverse(func);
    return 0;
}
