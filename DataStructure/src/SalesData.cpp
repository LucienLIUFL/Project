#include "SalesData.h"

#include <iostream>
#include <algorithm>


void SalesData::get() const {
    std::cout << this->name << std::endl;
    std::for_each(std::begin(array), std::end(array), [](int x)->void{std::cout << x << std::endl;});
    std::cout << this->index << std::endl;
}
