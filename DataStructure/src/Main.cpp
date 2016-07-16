#include <iostream>
#include <memory>
#include "SalesData.h"


class Base {
public:
    void noVirtualFunc() {
        std::cout << "Base::noVirtualFunc" << std::endl;
    }

    virtual void virtualFunc() = 0;
};

// void Base::virtualFunc() {
//     std::cout << "Base::virtualFunc" << std::endl;
// }

class Derived : public Base {
    void noVirtualFunc();
    void virtualFunc() override;
};

void Derived::noVirtualFunc() {
    std::cout << "Derived::noVirtualFunc" << std::endl;
}

void Derived::virtualFunc() {
    std::cout << "Derived::noVirtualFunc" << std::endl;
}

int main(int argc, char const * argv[]) {
    std::shared_ptr<Base> p = std::make_shared<Derived>();
    p->noVirtualFunc();
    p->virtualFunc();

    Derived d;
    Base & b = d;
    b.noVirtualFunc();
    b.virtualFunc();

    Base && a = std::move(Derived());
    a.noVirtualFunc();
    a.virtualFunc();

    return 0;
}
