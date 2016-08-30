#include "Vector.h"
#include <iostream>


Vector::Vector() : m_pElement(NULL), m_sizeElement(0) {}
Vector::Vector(int size) : m_sizeElement(size) {
    this->m_pElement = new int[size];
}

Vector::Vector(const Vector & v) {
    this->m_copyElement(v);
}

Vector & Vector::operator=(const Vector & v) {
    this->m_copyElement(v);
    return *this;
}

Vector::~Vector() {
    delete [] this->m_pElement;
}

void Vector::clear() {
    delete [] this->m_pElement;
    this->m_sizeElement = 0;
}

bool Vector::empty() const {
    return (this->m_sizeElement == 0);
}

int Vector::size() const {
    return this->m_sizeElement;
}

Type Vector::operator[](int index) const {
    if (index > (this->size() - 1)) {
        throw std::out_of_range("Access");
    }
    return this->m_pElement[index];
}

int Vector::find(Type e) const {
    int returnValue = -1;
    for (int i = 0; i < this->size(); ++i) {
        if (this->m_pElement[i] == e) {
            returnValue = i;
            break;
        }
    }
    return returnValue;
}

int Vector::prior(Type e) const {
    int returnValue = -1;
    for (int i = 0; i < this->size(); ++i) {
        if (this->m_pElement[i] == e) {
            returnValue = (i - 1);
            break;
        }
    }
    return returnValue;
}

int Vector::next(Type e) const {
    int returnValue = -1;
    for (int i = 0; i < this->size(); ++i) {
        if (this->m_pElement[i] == e) {
            returnValue = (i + 1);
            break;
        }
    }
    if (returnValue == this->size()) {
        returnValue = -1;
    }
    return returnValue;
}

void Vector::insert(int index, Type e) {
    if (index > (this->size() - 1)) {
        throw std::out_of_range("Insert");
    }
    this->m_moveElement(this->size() + 1);
    for (int i = (this->size() - 2); i >= index; --i) {
        this->m_pElement[i+1] =  this->m_pElement[i];
    }
    this->m_pElement[index] =  e;
}

void Vector::remove(int index) {
    if (index > (this->size() - 1)) {
        throw std::out_of_range("Remove");
    }
    for (int i = index; i < (this->size() - 1); ++i) {
        this->m_pElement[i] =  this->m_pElement[i+1];
    }
    this->m_moveElement(this->size() - 1);
}

void Vector::traverse(void (*visit)(Type)) {
    for (int i = 0; i < this->size(); ++i) {
        visit(this->m_pElement[i]);
    }
}

void Vector::append(Type e) {
    this->m_moveElement(this->size() + 1);
    this->m_pElement[this->size() - 1] = e;
}

void Vector::m_moveElement(int memSize) {
    Type * pTemp = new Type[memSize];
    int size = (this->m_sizeElement < memSize) ? this->m_sizeElement : memSize;
    for (int i = 0; i < size; ++i) {
        pTemp[i] = this->m_pElement[i];
    }
    this->m_sizeElement = memSize;
    delete [] this->m_pElement;
    this->m_pElement = pTemp;
}

void Vector::m_copyElement(const Vector & v) {
    this->m_sizeElement = v.m_sizeElement;
    this->m_pElement = new int[this->m_sizeElement];
    for (int i = 0; i < this->m_sizeElement; ++i) {
        this->m_pElement[i] = v.m_pElement[i];
    }
}
