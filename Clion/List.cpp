#include "List.h"
#include <stdexcept>
#include <iostream>

List::List() : header(nullptr), size(0) {
    this->header = new Node();
}

List::~List() {
    Node * temp;
    while(this->header->next != nullptr) {
        temp = this->header;
        while(temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }
    delete this->header;
}

int List::getSize() const {
    return this->size;
}

bool List::empty() const {
    return this->size == 0;
}

void List::append(const Type & e) {
    Node * temp;
    temp = this->header;

    while(temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = new Node();
    temp->next->elem = e;
    ++this->size;
}

void List::insert(int pos, const Type & e) {
    Node * prior = this->header;
    if((pos <= this->size) && (pos >= 0)) {
        for(int i = 0; i < pos; ++i) {
            prior = prior->next;
        }

        Node * temp = new Node();
        temp->elem = e;

        temp->next = prior->next;
        prior->next = temp;
        ++this->size;
    }
}

// Error
void List::remove(int pos) {
    if((pos < this->size) && (pos >= 0)) {
        Node * prior = this->header;
        for(int i = 0; i < pos; ++i) {
            prior = prior->next;
        }

        Node * temp = prior->next;
        prior->next = temp->next;
        delete temp;
        --this->size;
    }
}

int List::find(const Type & e) const {
    int pos = -1;

    // Must Support Operator =
    Node * temp = this->header;
    for(int i = 0; i < this->size; ++i) {
        if(temp->next != nullptr) {
            temp = temp->next;
            if(temp->elem == e) {
                pos = i;
                break;
            }
        }
    }
    return pos;
}

void List::delegate(void (* visit)(Type)) {
    Node * temp = this->header;
    while(temp->next != nullptr) {
        visit(temp->next->elem);
        temp = temp->next;
    }
}

Type List::operator[](int pos) const {
    int value = 0;
    Node * temp = this->header->next;
    if((pos < this->size) && (pos >= 0)) {
        for(int i = 0; i < pos; ++i) {
            temp = temp->next;
        }
        value = temp->elem;

    } else {
        std::cerr << __LINE__ << std::endl;
        throw std::out_of_range("OUT OF RANGE");
    }
    return value;
}
