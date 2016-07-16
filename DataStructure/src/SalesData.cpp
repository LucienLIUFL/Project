#include "SalesData.h"

#include <iostream>
#include <algorithm>

SalesData::SalesData() = default;
SalesData::SalesData(const std::string & name, const std::vector<int> array, int index) :
pstr(new std::string("Hello~")), name(name), array(array), index(index) {}

void SalesData::get() const {
    std::cout << this->name << std::endl;
    std::for_each(std::begin(array), std::end(array), [](int x)->void{std::cout << x << std::endl;});
    std::cout << this->index << std::endl;
    std::cout << *this->pstr << std::endl;
}
