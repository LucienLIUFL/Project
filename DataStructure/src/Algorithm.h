#ifndef ALGORITHM_H_
#define ALGORITHM_H_

class List {
public:
    int * array;
    int size;

    List(int size) : size(size) {
        this->array = new int[this->size];
    }

    ~List() {
        delete [] this->array;
    }
};

class Algorithm {
public:

private:

};

#endif
