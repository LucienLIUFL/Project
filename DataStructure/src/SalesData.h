#ifndef SALESDATA_H_
#define SALESDATA_H_

#include <string>
#include <vector>
#include <memory>

class SalesData {
public:
    SalesData();
    SalesData(const std::string & name, const std::vector<int> array, int index);

    void get() const;
    std::unique_ptr<std::string> pstr;
private:
    std::string name;
    std::vector<int> array;
    int index;


};

#endif
