#include <iostream>
#include "MaplesTool/Test.h"




void test() {
    for (int i = 0; i < 154; ++i) {
        for (int j = 0; j < 154; ++j) {
            for (int k = 0; k < 154; ++k) {
                if ((8 * i + 10 * j + 20 * k) == 154) {
                    std::cout << i << " " << j << " " << k << std::endl;
                }
            }
        }
    }

}


int main(int argc, const char * argv[]) {
    test();
    return 0;
}