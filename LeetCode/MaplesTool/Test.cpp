//
// Created by maples on 2/11/17.
//

#include <iostream>
#include "Test.h"

void Object::print() {
    std::cout << "Object Function" << std::endl;
}

void Father::print() {
    std::cout << "Father Function" << std::endl;
}

void Mother::print() {
    std::cout << "Mother Function" << std::endl;
}

void Child::print() {
    std::cout << "Child Function" << std::endl;
}

void Test::test0() {
    std::shared_ptr<Object> test = std::make_shared<Father>();
    std::shared_ptr<Father> temp = std::dynamic_pointer_cast<Father>(test);
    test->print();
    temp->print();
}

void Test::test1() {
    Mother * test = new Child();
    test->print();
}

void Test::test2() {

}

void Test::test3() {

}

void Test::test4() {

}
