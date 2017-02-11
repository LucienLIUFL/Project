//
// Created by maples on 2/11/17.
//

#ifndef LEETCODE_TEST_H
#define LEETCODE_TEST_H

class Object {
public:
    virtual void print();
};

class Father : public Object {
public:
    virtual void print() override;
};

class Mother : public Object {
public:
    virtual void print() override;
};

class Child : public Father, public Mother {
public:
    virtual void print() override;
};

class Test {
public:
    static void test0();
    static void test1();
    static void test2();
    static void test3();
    static void test4();
};


#endif //LEETCODE_TEST_H
