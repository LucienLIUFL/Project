#include <iostream>

#include "SalesData.h"

int main(int argc, char const * argv[]) {
    SalesData a;
    SalesData b("Maples", std::vector<int>(1, 10), 1);
    a.get();
    b.get();
    SalesData c(b);
    c.get();
    return 0;
}
