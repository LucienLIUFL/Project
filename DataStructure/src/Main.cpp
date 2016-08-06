#include <iostream>

#include "List.h"


void visit(int x) {
    std::cout << x << std::endl;
}

void testCase(int key, List & l, int value) {
    switch (key) {
        case 0 : {
            l.append(value);
            break;
        }
        case 1 : {
            l.insert(0, value);
            break;
        }
        case 2 : {
            l.remove(0);
            break;
        }
        case 3 : {
            std::cout << l[value] << std::endl;
            break;
        }
    }
}

int main(int argc, char const * argv[]) {

    List test;
    int key, value;
    while (true) {
        std::cin >> key;
        std::cin >> value;
        std::cout << "<test>" << std::endl;
        testCase(key, test, value);
        test.delegate(visit);
        std::cout << "</test>" << std::endl;
    }

    return 0;
}
