//
// Created by maples on 11/10/16.
//

#ifndef MAPLESLIB_BITREE_H
#define MAPLESLIB_BITREE_H

#include <memory>

class Object {
public:
    Object() = default;
    Object(const Object &) = delete;
    Object & operator=(const Object &) = delete;
    virtual ~Object() {}
};

template <class T>
class BiNode : public Object {
public:
    BiNode(T value) :
            _value(value),
            _lchild(nullptr),
            _rchild(nullptr) {}

    T getValue() const {
        return this->_value;
    }

    std::shared_ptr<BiNode> getLchild() const {
        return this->_lchild;
    }

    std::shared_ptr<BiNode> getRchild() const {
        return this->_rchild;
    }

    void setLchild(const std::shared_ptr<BiNode> & node) {
        this->_lchild = node;
    }

    void setRchild(const std::shared_ptr<BiNode> & node) {
        this->_rchild = node;
    }

private:
    T _value;
    std::shared_ptr<BiNode> _lchild;
    std::shared_ptr<BiNode> _rchild;
};

template <class T>
class BiTree : public Object {
public:
    BiTree() : _root(nullptr) {}

    void initialize() {
        this->_root = std::make_shared<BiNode<int>>(0);
        this->_root->setLchild(std::make_shared<BiNode<int>>(1));
        this->_root->setRchild(std::make_shared<BiNode<int>>(2));
        this->_root->getLchild()->setLchild(std::make_shared<BiNode<int>>(3));
        this->_root->getLchild()->setRchild(std::make_shared<BiNode<int>>(4));
        this->_root->getRchild()->setRchild(std::make_shared<BiNode<int>>(5));

//        this->_root->getLchild()->getRchild()->setLchild(std::make_shared<BiNode<int>>(6));
    }

    std::shared_ptr<BiNode<T>> getRoot() const {
        return this->_root;
    }

private:
    std::shared_ptr<BiNode<T>> _root;
};

#endif //MAPLESLIB_BITREE_H
