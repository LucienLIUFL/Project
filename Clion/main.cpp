//#include <iostream>
//#include <memory>
//#include <stack>
//#include "BiTree.h"

//std::stack<int> treeStack;
//
//void preOrder(const std::shared_ptr<BiNode<int>> & root) {
//
//    if (root) {
//        treeStack.push(root->getValue());
//        std::cout << root->getValue() << " And Stack " << treeStack.size() << std::endl;
//        preOrder(root->getLchild());
//        preOrder(root->getRchild());
//        treeStack.pop();
//    }
//}

#include <panel.h>

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode * addTwoNumbers(ListNode * l1, ListNode * l2) {
        ListNode * returnList = new ListNode(-1);
        ListNode * pL1 = l1;
        ListNode * pL2 = l2;
        ListNode * pReturnNode = returnList;

        int carry = 0;
        while (pL1 && pL2) {
            pReturnNode->next = new ListNode(-1);

            pReturnNode->val = pL1->val + pL2->val + carry;
            carry = (pL1->val + pL2->val) > 9 ? 1 : 0;
            if (carry == 1) {
                pReturnNode -= 10;
            }

            pReturnNode = pReturnNode->next;
            pL1 = pL1->next;
            pL2 = pL2->next;
        }
    }
};

int main(int argc, const char * argv[]) {

//    std::shared_ptr<BiNode<int>> root;
//
//    preOrder(root);
    return 0;
}