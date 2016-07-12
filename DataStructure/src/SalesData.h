#ifndef SALESDATA_H_
#define SALESDATA_H_

#include <string>
#include <vector>

class SalesData {
public:
    SalesData() = default;
    SalesData(const std::string & name, const std::vector<int> array, int index):
              name(name), array(array), index(index) {}

    void get() const;
private:
    std::string name;
    std::vector<int> array;
    int index;
};

#endif
