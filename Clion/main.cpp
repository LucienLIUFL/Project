#include <iostream>
#include <memory>
#include <stack>
#include "BiTree.h"

std::stack<int> treeStack;

void preOrder(const std::shared_ptr<BiNode<int>> & root) {
    if (root) {
        treeStack.push(root->getValue());
        std::cout << root->getValue() << " And Stack " << treeStack.size() << std::endl;
        preOrder(root->getLchild());
        preOrder(root->getRchild());
        treeStack.pop();
    }
}

void midOrder(const std::shared_ptr<BiNode<int>> & root) {
    if (root) {
        treeStack.push(root->getValue());
        midOrder(root->getLchild());
        std::cout << root->getValue() << " And Stack " << treeStack.size() << std::endl;
        midOrder(root->getRchild());
        treeStack.pop();
    }
}

void change(const std::shared_ptr<BiNode<int>> & root) {
    if (root->getLchild() && (root->getRchild() == nullptr)) {
        root->setRchild(root->getLchild());
        root->setLchild(nullptr);
    } else if (root->getRchild() && (root->getLchild() == nullptr)) {
        root->setLchild(root->getRchild());
        root->setRchild(nullptr);
    }
}

void changeChild(const std::shared_ptr<BiNode<int>> & root) {
    if (root) {
        if (root->getLchild() || root->getRchild()) {
            std::shared_ptr<BiNode<int>> tempPtr = root->getRchild();
            root->setRchild(root->getLchild());
            root->setLchild(tempPtr);
        }
    }
}

void changeLeaves(const std::shared_ptr<BiNode<int>> & root) {
    if (root) {
        if (root->getLchild() && root->getRchild()) {
            // Identify
            bool value = (root->getLchild()->getLchild() == nullptr) &&
                         (root->getLchild()->getRchild() == nullptr) &&
                         (root->getRchild()->getLchild() == nullptr) &&
                         (root->getRchild()->getRchild() == nullptr);

            if (value) {
                std::shared_ptr<BiNode<int>> tempPtr = root->getRchild();
                root->setRchild(root->getLchild());
                root->setLchild(tempPtr);
            }
        }
    }
}

void pre(const std::shared_ptr<BiNode<int>> & root) {
    if (root) {
        changeLeaves(root);
        pre(root->getLchild());
        pre(root->getRchild());
    }
}

int main(int argc, const char * argv[]) {
    BiTree<int> tree;
    tree.initialize();

    pre(tree.getRoot());
    preOrder(tree.getRoot());
    std::cout << std::endl;
    midOrder(tree.getRoot());
    return 0;
}